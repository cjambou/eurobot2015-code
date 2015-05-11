#include "ControlLoop.h"
//#include "const.h"

/**
 CONSTRUCTEUR de la boucle de controle (base roulante)
*/
ControlLoop::ControlLoop():
    pidcap(CAP, GAIN_KP_CAP, GAIN_KI_CAP, GAIN_KD_CAP, NEAR_ERROR_CAP, DONE_ERROR_CAP),
    piddep(DEP, GAIN_KP_DEP, GAIN_KI_DEP, GAIN_KD_DEP, NEAR_ERROR_DEP, DONE_ERROR_DEP),
    bf_type(STOP),
    asserv_state(DONE),
    cmd_d(0),
    cmd_g(0),
    fw_g(true),
    fw_d(true),
    real_coord(),
    target_position(),
    count_not_moving(0),
    late_pos(),
    detect_on(false),
    sonarg(PIN_SONAR_GAUCHE, Coord(100., 159., 0.)),
    sonard(PIN_SONAR_DROITE, Coord(100., -159., 0.))
    {
        set_speed(SLOW);        // on defini la vitesse initiale comme slow
        //sonarg.turn_off();      // evitement off
        //
};

/**
*/
void ControlLoop::set_target(Coord coord)
{

}

/**
*/
void ControlLoop::update_error(Coord coord)
{
    // erreur accumulee ?
}

/** BF avance?
*/
void ControlLoop::bf_avance(float d){
    piddep.addToTarget(d);
}


/** definition des vitesses
// a check sur PID
**/
#define MIN_MAX_SLOW 80
#define MIN_MAX_MEDIUM 110
#define MIN_MAX_FAST 160  // don't use it too fast
void ControlLoop::set_speed(int speed)
{
    switch(speed){
        case SLOW:
            Serial.println("SPEED -> SLOW");
			piddep.setMinMax(MIN_MAX_SLOW);
            pidcap.setMinMax(MIN_MAX_SLOW);
            setTuningCap(GAIN_KP_CAP_SLOW,GAIN_KI_CAP_SLOW,GAIN_KD_CAP_SLOW);
            setTuningDep(GAIN_KP_DEP_SLOW,GAIN_KI_DEP_SLOW,GAIN_KD_DEP_SLOW);
            break;

        case MEDIUM:
            Serial.println("SPEED -> MEDIUM");
            piddep.setMinMax(MIN_MAX_MEDIUM);
            pidcap.setMinMax(MIN_MAX_MEDIUM);
            setTuningCap(GAIN_KP_CAP_MEDIUM,GAIN_KI_CAP_MEDIUM,GAIN_KD_CAP_MEDIUM);
            setTuningDep(GAIN_KP_DEP_MEDIUM,GAIN_KI_DEP_MEDIUM,GAIN_KD_DEP_MEDIUM);
            break;

        case FAST:
            Serial.println("SPEED -> FAST");
			piddep.setMinMax(MIN_MAX_FAST);
            pidcap.setMinMax(MIN_MAX_FAST);
            setTuningCap(GAIN_KP_CAP_FAST,GAIN_KI_CAP_FAST,GAIN_KD_CAP_FAST);
            setTuningDep(GAIN_KP_DEP_FAST,GAIN_KI_DEP_FAST,GAIN_KD_DEP_FAST);
            break;
    }
}


/** recalage :
on recule et on attend le blocage
**/
void ControlLoop::recaler(){
    set_speed(SLOW);                        // on fait ca en vitesse lente, quand meme
    set_BF(BFFW, Coord(-1000, 0, 0));       // recule de 1m ?? wtf
}


/** set la BF a faire avec le point objectif
    BF : BFCAP, BFavance, BF droite, BF cercle....
**/
void ControlLoop::set_BF(int bf_type_, Coord target_position_){

    count_not_moving = 0;       // compteur de blocage a zero
    bf_type = bf_type_;         // la BF a faire
    asserv_state = FAR;         // on commence loin de l'objectif
    pidcap.reinit();            // PID cap, met les I_sum a zero
    piddep.reinit();            // PID deplacement
    float d;                    // d?? distance a parcourir ?

    switch(bf_type){

        /** STOP **/
        case STOP:
            Serial.println("STOP");
            break;


        /** BF avance **/
        case BFFW:
            //target_position = real_coord;
            target_position.forward_translation(target_position_.get_x());
            Serial.print("BF avance, point a rejoindre : ");
            target_position.write_serial();
            dir = Vector(real_coord, target_position);
            if (target_position_.get_x() < 0){
                dir.neg();
            }
            //d = dir.norm();
            dir.normalize();
            piddep.setTarget(0.0);  // pk???
            //pidcap.setTarget(target_position.get_cap());
            pidcap.setTarget(real_coord.get_cap());

            break;

        /** BF Cap (rotation angulaire) **/
        case BFCAP:
            //target_position = real_coord;
            target_position.set_cap(target_position_.get_cap());
            pidcap.setTarget(target_position.get_cap());
            //piddep.setTarget(0.0);
            //Serial.println(target_position.get_cap());
            break;

        /** BF droite **/
        case BFXYCAP:
            target_position = target_position_;
            Serial.print("BF droite, point a rejoindre : ");
            target_position.write_serial();
            piddep.setTarget(0.0);                          // l'ecart a minimiser
            pidcap.setTarget(target_position.get_cap());    // cap a rejoindre
            break;
    }

}

/** modification de l'etats suivant dans l'asserv
**/
void ControlLoop::next_asserv_state(){
    switch (asserv_state){

        // de lointain a proche
        case FAR:
            asserv_state = NEAR ;
            write_real_coords();
            Serial.println("# SLAVE_NEAR");       // pour le master
            break;

        // de proche a fini
        case NEAR:
            asserv_state = DONE ;
            write_real_coords();
            Serial.println("# SLAVE_AFINI");      // pour le master
            bf_type = STOP;
            break;
    }
}


/** calcul des PID pour le deplacement
**/
void ControlLoop::compute_pids(){
    // vecteur position
    // depart: coord reel
    // arrivee: target/cible
    Vector to_target;
    to_target = Vector(real_coord, target_position);

    // les PIDs dependent des BF a faire....
    switch (bf_type){

        /** arret, on renvoi rien **/
        case STOP:
            cmd_cap = 0;
            cmd_dep = 0;
            break;



        /** BF AVANCE ***********************************************************************/
        case BFFW:
            //Serial.println("coucou BFFW");
            //cmd_cap = 0;
            //Serial.println(to_target.scalar(dir));
            /*
            double Xt, Yt, Xr, Yr, erreur_deplacement;
            Xt = target_position.get_x();
            Yt = target_position.get_y();
            Xr = real_coord.get_x();
            Yr = real_coord.get_y();

            erreur_deplacement = sqrt( (Xt-Xr)*(Xt-Xr) + (Yt-Yr)*(Yt-Yr) );
            */
            // commande de PID sur le deplacement
            //cmd_dep = piddep.compute(erreur_deplacement);

            // truc a jambou, j'ai pas confiance...
            cmd_dep = piddep.compute( to_target.scalar(Vector(real_coord)));
            // the error is a scalar product >> UN PEU MOISI, c'est juste pour la partie angulaire
            // vaudrait mieux la norme du vecteur distance entre les deux nan?


            /** si on est loin de la cible, on asservi le cap sur le vecteur directeur
             modification de la consigne de cap en temps reel */

            if (asserv_state != NEAR)
            {

                // si on recule, evite de faire demi tour....

                if (abs(diff_cap(to_target.get_angle(), target_position.get_cap())) > PI / 2)
                {

                    // le cap est celui vers la cible (en marche arriere), normal :)
                    pidcap.setTarget(to_target.get_angle() + PI);

                    // commande de PID sur la rotation
                    //  cmd_cap = pidcap.compute(real_coord.get_cap());
                    // double factor_NEAR(0.5);
                    // cmd_cap = factor_NEAR*pidcap.compute(real_coord.get_cap());
                }

                // si on avance
                else
                {
                    // le cap est celui vers la cible (en marche avant), normal
                    pidcap.setTarget(to_target.get_angle());

                    // commande de PID sur la rotation
                    cmd_cap = pidcap.compute(real_coord.get_cap());
                    //double factor_NEAR(0.5);
                    //cmd_cap = factor_NEAR*pidcap.compute(real_coord.get_cap());
                }
            }

            /** si on est proche, on s'asservi sur la posistion finale
            */

            else
            {
                pidcap.setTarget(target_position.get_cap());
                // il faut faire une modif ici, les gains sont trop fort une fois arrive en NEAR
                // commande de PID sur la rotation
                float factor_NEAR(1);
                cmd_cap = factor_NEAR*pidcap.compute(real_coord.get_cap());

            }


            // check si on a fini l'asserv
            if (piddep.check_if_over(asserv_state)  && pidcap.check_if_over(asserv_state))
            {
               next_asserv_state();
            }
            break;



//******************************************* MODIF A FAIRE....NORMALEMENT CA MARCHE
        /** BF CAP ******************************************************************/
        case BFCAP:
            //Serial.println("coucou BFCAP");
            //cmd_dep = 0;
            //Serial.println(real_coord.get_cap());
            //Serial.print ("  CAP  ");

            // commande de PID sur la rotation
            cmd_cap = pidcap.compute(real_coord.get_cap());     // on s'oriente vers le cap cible
            cmd_dep = 0;                                        // on reste sur place, logique, on veut tourner en rond

            // check si on a fini l'asserv
            if (pidcap.check_if_over(asserv_state))
            {
               next_asserv_state();
            }
            break;




/******************************************* MODIF A FAIRE....
        /** BF droite **/
        case BFXYCAP:
            /* later !, no, now or never :) */
            // see supaero report 2012

            /** first, on s'occupe de la translation */
            // on reprend la meme formule que la BF avance,
            // ici le vecteur n'est pas normaliser du coup on a bien le produit scalaire (cap reel et (reel>>cible)
            // en gros si on est aligne, pleine balle, si perpendiculaire on stope pour laisser faire le cap
            cmd_dep = piddep.compute( to_target.scalar(Vector(real_coord)));


            /**  secondly, on s'occupe de la rotation */
            float alpha;       // difference angulaire entre (le cap du point objectif) et (le cap de la droite reliant le robot au point objectif)
            float beta;        // difference angulaire entre (le cap du robot) et (le cap du point objectif)
            float A(1.0);      // poids angle alpha
            float B(2.0);      // poids angle beta
            float erreur_cap;


            if (asserv_state == NEAR)
            {
                //Serial.print("BF DROITE NEAR: ");


                A = 1;
                B = 1.5;
                alpha = -diff_cap( target_position.get_cap() ,  real_coord.get_cap() );
                beta =  0;//-diff_cap( to_target.get_angle()     ,  target_position.get_cap() );
                erreur_cap = diff_cap(A*alpha + B*beta,0);//(A+B);
                //Serial.print(erreur_cap);
                cmd_cap = pidcap.compute(erreur_cap + pidcap.get_target());  // car la formule du pidcap : target - input

                //pidcap.setTarget(target_position.get_cap());
                //cmd_cap = pidcap.compute(real_coord.get_cap());

            }

            /// si on est loin
            else
            {
                A = 1;
                B = 1.8;
                alpha = -diff_cap( target_position.get_cap() ,  real_coord.get_cap() );
                beta =  -diff_cap( to_target.get_angle()     ,  target_position.get_cap() );
                erreur_cap = diff_cap(A*alpha + B*beta,0);//(A+B);
                cmd_cap = pidcap.compute(erreur_cap + pidcap.get_target());  // car la formule du pidcap : target - input




                if (abs(diff_cap(to_target.get_angle(), target_position.get_cap())) > PI / 2)
                {
                    // le cap est celui vers la cible (en marche arriere), normal :)
                    //pidcap.setTarget(to_target.get_angle() + PI);
                    alpha = -diff_cap( target_position.get_cap() ,  real_coord.get_cap() );
                    beta =  -diff_cap( to_target.get_angle() + PI    ,  target_position.get_cap() );
                    erreur_cap = diff_cap(A*alpha + B*beta,0);//(A+B);
                    cmd_cap = pidcap.compute(erreur_cap + pidcap.get_target());  // car la formule du pidcap : target - input

                }


            }



            // affichage pour verification

            //erreur_cap =  diff_cap(B*beta,0);




            /** Check si on fini */
            if (piddep.check_if_over(asserv_state)  && pidcap.check_if_over(asserv_state))
            {
               next_asserv_state();
            }
            break;
    }
}


/** Calcul les commandes a appliquer au moteur droite et gauche
**/
void ControlLoop::compute_cmds(){
    /* compute the command G and D of the motors */
    /*
    Serial.print("cmd_dep : ");
    Serial.println(cmd_dep);
    Serial.print("cmd_cap : ");
    Serial.println(cmd_cap);
    Serial.println(" ");
    */
    cmd_g = 0.5 * ((cmd_dep) + (cmd_cap));
    cmd_d = 0.5 * ((cmd_dep) - (cmd_cap));

    fw_g = cmd_g <= 0;
    fw_d = cmd_d <= 0;

    if (cmd_g <0){ cmd_g = - cmd_g;}
    if (cmd_d <0){ cmd_d = - cmd_d;}

}


/** boucle d'asserv
**/
void ControlLoop::run(Coord real_coord_){
    real_coord = real_coord_;               // coordonnee actuelles
    compute_pids();                         // calcul les PIDs
    compute_cmds();                         // calcul les commandes

    // mettre aussi la BF droite si elle fonctionne
    if ((bf_type == BFFW || bf_type == BFXYCAP)&& detect_on)
    {
        check_adversary();
    }
    if (bf_type != STOP)
    {
        // pour tester a remettre apres
        check_blockage();                       // check blocage, ....
    }
  }

/** commande gauche
**/
int ControlLoop::get_cmd_g(){
    return cmd_g;
}

/** sens gauche
**/
bool ControlLoop::get_fw_g(){
    return fw_g;
}

/** commande droite
**/
int ControlLoop::get_cmd_d(){
    return cmd_d;
}

/** sens droite
**/
bool ControlLoop::get_fw_d(){
    return fw_d;
}



/** detection de blocage
**/
void ControlLoop::check_blockage()
{
    /*code to test if moving when commands are sent*/
   late_pos.barycentre(real_coord, 0.3);
   Vector dep = Vector(real_coord, late_pos);

    // si la commande est grande pas de blocage?    bizarre
   //if (abs(cmd_dep) + abs(cmd_cap) < 100)
   if (abs(cmd_dep) + abs(cmd_cap) < 50)
    {
        return;
    }

   if (dep.norm() < 10.0 && abs(real_coord.get_cap() - late_pos.get_cap()) < 0.05)
   {
        count_not_moving += 1;
        Serial.print("INC BLOC COUNT ");
        Serial.println(100. * abs(real_coord.get_cap() - late_pos.get_cap()));

   }
   else
    {
        count_not_moving = 0;
   }

   if (count_not_moving > BLOCAGE_MAX)
   {
        write_real_coords();
        Serial.println("# SLAVE_BLOCAGE");

        set_BF(STOP, Coord());
        count_not_moving = 0;
   }


}


/**
detection de l'adversaire
*/
void ControlLoop::check_adversary()
{
    Vector to_target;
    to_target = Vector(real_coord, target_position);

    if (to_target.scalar(Vector(real_coord)) <0.)
    {
        // Serial.println("going backward...");
        return;
    }

    // on check a gauche
    if (sonarg.adv_detected(real_coord)){
        if (sonard.adv_detected(real_coord))
        {
            sonarg.mean_adv(sonard.get_adv());
        }
        write_real_coords();
        sonarg.write_adv_coord();
        set_BF(STOP, Coord());
        Serial.println("# SLAVE_ENNEMI_GAUCHE");
    }
    else if (sonard.adv_detected(real_coord))
    {
        write_real_coords();
        sonard.write_adv_coord();
        set_BF(STOP, Coord());
        Serial.println("# SLAVE_ENNEMI_DROITE");
    }

}

/**
modification des gains PIDs Cap en cours d'execution pour test
*/
void ControlLoop::setTuningCap(float Kp, float Ki, float Kd )
{
    pidcap.setTuning(Kp, Ki, Kd);
}

/**
modification des gains PIDs deplacement en cours d'execution pour test
*/
void ControlLoop::setTuningDep(float Kp, float Ki, float Kd )
{
    piddep.setTuning(Kp, Ki, Kd);
}

/**
modification de la position actuelle
*/
void ControlLoop::setxycap(Coord new_coord)
{
    real_coord = Coord(new_coord);
    target_position = Coord(real_coord);
    write_real_coords();
}

/**
coordonne affiche
*/
void ControlLoop::write_real_coords()
{
    Serial.print("* COORD ");
    real_coord.write_serial();

    Serial.print("theorique");
    target_position.write_serial();

}


/** activation de l'evitement
**/
void ControlLoop::turn_on_evit()
{
   detect_on = true;

}

void ControlLoop::turn_off_evit()
{
    detect_on = false;
}

/**
ecriture du debug
*/
void ControlLoop::write_debug()
{
    Serial.println("GAIN CAP");
    pidcap.write_debug();

    Serial.println("GAIN DEP");
    piddep.write_debug();


    Serial.print("SonarG");
    sonarg.write_debug();

    Serial.print("SonarD");
    sonard.write_debug();

}

Sonar* ControlLoop::get_sonar_d()
{
    return &sonard;
}

Sonar* ControlLoop::get_sonar_g()
{
    return &sonarg;
}
