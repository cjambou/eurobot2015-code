#include "IO.h"
#include <string.h>
int couleur;

/****************************************************
   IR compteur de roue
*****************************************************/

IR_compteur::IR_compteur():
    period_run(20),
    IR(PIN_IR_BAS,SEUIL_IR_ALIGNEMENT),
    alignement(false),
    vu(false),
    compteur(0),
    bavardeur(false)
{
      // init
      muet();               // on met pas de merde
      reset_compteur();     // on met les compteurs a zero
      IR.reverse();
}

void IR_compteur::run()
{
    if (period_run.is_over())
    {
        period_run.reset();
        // si le temps est fini
        if(bavardeur)
        {
            affiche();
        }

        if(IR.is_on())
        {
            alignement = true;
            if(vu == false)
            {
                incremente_compteur();
                vu = true;
            }
        }
        else
        {
            alignement = false;
            vu = false;
        }
    }

}

void IR_compteur::affiche()
{
    Serial.print("valeur ir : ");
    Serial.print(analogRead(PIN_IR_BAS));
    Serial.print("\t alignement: ");
    Serial.print((int)est_aligne());
    Serial.print("\t compteur: ");
    Serial.println(nbr_compteur());
}

void IR_compteur::reset_compteur()
{
    compteur = 0;
}

void IR_compteur::incremente_compteur()
{
    compteur++;
    Serial.print("# TOUR ");
    Serial.println(compteur);
    Serial.print("compteur: ");
    Serial.println(compteur);
}
int IR_compteur::nbr_compteur()
{
    return compteur;
}
bool IR_compteur::est_aligne()
{
    return IR.is_on();
}

void IR_compteur::bavard()
{
    bavardeur = true;
}


void IR_compteur::muet()
{
    bavardeur = false;
}

/*********************************************************************
    CHAINE SECONDAIRE
*********************************************************************/
ChenilleSecondaire::ChenilleSecondaire():
        period_run(PERIODE_CHENILLE_SECONDAIRE),
        state(STATE_CHENILLE_SECONDAIRE_RANGEE),
        time_out_on(false),
        t_over(0),
        angle_tangage(0)//,
        //centrale_Inertielle()
{
    chenille_secondaire.attach(PIN_PWM_MOTEUR_CHENILLE_SECONDAIRE);
    bascule.attach(PIN_PWM_SERVO_BASCULE);
    OFF();
    position_rangee();
    in_state_func();
}


void ChenilleSecondaire::OFF(){
    chenille_secondaire.writeMicroseconds(CHAINE_SECONDAIRE_STOP);
    //Serial.println("ChenilleSecondaire::OFF()");
}

void ChenilleSecondaire::ON(){
    chenille_secondaire.writeMicroseconds(CHAINE_SECONDAIRE_MARCHE);
    //Serial.println("ChenilleSecondaire::ON()");
}

void ChenilleSecondaire::position_rangee(){
    bascule.writeMicroseconds(CHAINE_SECONDAIRE_POSITION_RANGEE);
}

void ChenilleSecondaire::position_miHauteur(){
    bascule.writeMicroseconds(CHAINE_SECONDAIRE_POSITION_MI);
}

void ChenilleSecondaire::position_auSol(){
    bascule.writeMicroseconds(CHAINE_SECONDAIRE_POSITION_SOL);
}

void ChenilleSecondaire::deployement()
{
    // centrale.resestangle();
    trigger(TRIGGER_CHENILLE_SECONDAIRE_DEPLOYEMENT);
}
void ChenilleSecondaire::grimpe()
{
    trigger(TRIGGER_CHENILLE_SECONDAIRE_GRIMPE);
}

// tempo
void ChenilleSecondaire::set_time_out(int dt_)
{
    t_over = millis() + dt_;
    time_out_on = true;
    //trigger_to_be = trigger;
    Serial.print("time_out set ");
    //Serial.println(trigger);
}

// reset time out
void ChenilleSecondaire::reset_time_out()
{
    time_out_on = false;
}

// es ce que c'est fini
bool ChenilleSecondaire::is_time_out()
{
   if (time_out_on && t_over < millis())
   {
     time_out_on = false;
     return true;
   }
   return false;
}

/*
Centrale_Inertielle* ChenilleSecondaire::get_Centrale_Inertielle()
{
    return &centrale_Inertielle;
}
*/


/** boucle de control
*/
#define SEUIL_TANGAGE 4 // deg
void ChenilleSecondaire::run(){

    // actualisation des donnees pour deplacement
    //centrale_Inertielle.run();
    //angle_tangage = centrale_Inertielle.angle_x_out();

    if (period_run.is_over())
    {
        period_run.reset();

        // si le temps est fini
        if (is_time_out())
        {
            trigger(TRIGGER_CHENILLE_SECONDAIRE_TIME_OUT);
        }

        // si on est stabiliser en fin de montee, on remonte la chenille
        /*
        if (state == STATE_CHENILLE_SECONDAIRE_GRIMPE_TEMPO)
        {
            Serial.print("angle_tangage : ");
            Serial.println(angle_tangage);
            if (abs(angle_tangage) < SEUIL_TANGAGE)
            {
                trigger(TRIGGER_CHENILLE_SECONDAIRE_STABILISATION);
            }

        }
        */
    }
}



// appel de transistion MAE
void ChenilleSecondaire::trigger(int transition)
{
    Serial.println("");
    Serial.print("appel trigger slave : ");
    Serial.println(transition);

    if (transition == TRIGGER_CHENILLE_SECONDAIRE_STABILISATION  )
    {
         Serial.println(" ");
         Serial.print("[SCIE] TRANSISTION AUTOMATIQUE: STABILISATION GYRO");
         Serial.println(transition);
    }

    if (transition == TRIGGER_CHENILLE_SECONDAIRE_GRIMPE || transition == TRIGGER_CHENILLE_SECONDAIRE_DEPLOYEMENT )
    {
         Serial.println(" ");
         Serial.print("[SCIE] TRANSISTION FORCEE");
         Serial.println(transition);
    }

    if (transition == TRIGGER_CHENILLE_SECONDAIRE_TIME_OUT )
    {
         Serial.println(" ");
         Serial.print("[SCIE] TRANSISTION AUTOMATIQUE: TIME OUT");
         Serial.println(transition);
    }

   Serial.print("[SCIE] ACTUAL STATE ->  ");
   Serial.println(state);
   int old_state;
   old_state = state;
   switch(state)
    {
        case STATE_CHENILLE_SECONDAIRE_RANGEE  :
           if (transition == TRIGGER_CHENILLE_SECONDAIRE_DEPLOYEMENT )
           {
                state = STATE_CHENILLE_SECONDAIRE_DEPLOYEMENT;
                Serial.println("[SCIE] Deployement");
           }
           break;

        case STATE_CHENILLE_SECONDAIRE_DEPLOYEMENT  :
           if (transition == TRIGGER_CHENILLE_SECONDAIRE_GRIMPE )
           {
                state = STATE_CHENILLE_SECONDAIRE_GRIMPE;
                Serial.println("[SCIE] Grimpe");
           }
           break;

        case STATE_CHENILLE_SECONDAIRE_GRIMPE  :
           if (transition == TRIGGER_CHENILLE_SECONDAIRE_TIME_OUT)
           {
                state = STATE_CHENILLE_SECONDAIRE_GRIMPE_TEMPO;
                Serial.println("[SCIE] grimpe tempo");
           }
           break;

        case STATE_CHENILLE_SECONDAIRE_GRIMPE_TEMPO  :
           if (transition == TRIGGER_CHENILLE_SECONDAIRE_STABILISATION )
           {
                state = STATE_CHENILLE_SECONDAIRE_FIN_MONTEE;
                Serial.println("[SCIE] Fin de montee, stabilisation");
           }
           if (transition == TRIGGER_CHENILLE_SECONDAIRE_TIME_OUT)
           {
                state = STATE_CHENILLE_SECONDAIRE_FIN_MONTEE;
                Serial.println("[SCIE] Fin de montee, time out");
           }
           break;

        case STATE_CHENILLE_SECONDAIRE_FIN_MONTEE  :
           if (transition == TRIGGER_CHENILLE_SECONDAIRE_TIME_OUT )
           {
                state = STATE_CHENILLE_SECONDAIRE_DEBUT_RANGEMENT;
                Serial.println("[SCIE] Debut du Rangement");
           }
           break;

         case STATE_CHENILLE_SECONDAIRE_DEBUT_RANGEMENT  :
           if (transition == TRIGGER_CHENILLE_SECONDAIRE_TIME_OUT )
           {
                state = STATE_CHENILLE_SECONDAIRE_RANGEE;
                Serial.println("[SCIE] fin du Rangement");
           }
           break;

    }
   if (old_state != state)
    {
        Serial.print("[SLAVE] NEW STATE ->  ");
        Serial.println(state);
        reset_time_out();
        in_state_func();
    }
}



void ChenilleSecondaire::in_state_func()
{
    switch (state)
    {
        case STATE_CHENILLE_SECONDAIRE_RANGEE  :
           Serial.println("[SCIE][ETAT] RANGEE]");
           position_rangee();
           OFF();
           break;


        case STATE_CHENILLE_SECONDAIRE_DEPLOYEMENT  :
           Serial.println("[SCIE][ETAT] DEPLOYEMENT");
           Serial.println("reset angle");
           //centrale_Inertielle.reset_angle();
           position_auSol();
           break;


         case STATE_CHENILLE_SECONDAIRE_GRIMPE  :
           Serial.println("[SCIE][ETAT] GRIMPE");
           set_time_out(5000); // au cas ou ca chie a la montee ou que l'imu est morte
           ON();
           break;

         case STATE_CHENILLE_SECONDAIRE_GRIMPE_TEMPO  :
           Serial.println("[SCIE][ETAT] GRIMPE TEMPO");
           set_time_out(10000); // au cas ou ca chie a la montee ou que l'imu est morte
           break;

         case STATE_CHENILLE_SECONDAIRE_FIN_MONTEE  :
           Serial.println("[SCIE][ETAT] FIN MONTEE");
           set_time_out(3000);
           break;

         case STATE_CHENILLE_SECONDAIRE_DEBUT_RANGEMENT  :
           Serial.println("[SCIE][ETAT] DEBUT RANGEMENT");
           set_time_out(2000);
           Serial.println("# FIN MONTEE");
           position_miHauteur();
           OFF();
           break;
    }
}




#define PERIODE_SLAVE 50
#define SLAVE_TIME_SUP_APRES_STOP 1000 // 1s a checke en vrai
#define SLAVE_TIME_OUT_RECALAGE 15000 //15s
/*********************************************************************
    CHAINE PRINCIPALE
*********************************************************************/
/*
CONSTRUCTEUR
*/
ChenillePrincipale::ChenillePrincipale():
    bumper_av_g(PIN_BUMPER_RECALAGE_AV_G,SEUIL_BUMPER),
    bumper_av_d(PIN_BUMPER_RECALAGE_AV_D,SEUIL_BUMPER),
    bumper_g_av(PIN_BUMPER_RECALAGE_G_AV,SEUIL_BUMPER),
    bumper_g_ar(PIN_BUMPER_RECALAGE_G_AR,SEUIL_BUMPER),
    bumper_d_av(PIN_BUMPER_RECALAGE_D_AV,SEUIL_BUMPER),
    bumper_d_ar(PIN_BUMPER_RECALAGE_D_AR,SEUIL_BUMPER),
    ir_compteur_lat(),
    period_run(10),
    sonar(),
    state(SLAVE_STATE_REPOS),
    time_asserv_started(0),
    time_asserv_to_do(0),         // temps d'asserv pour l'asser en cours
    time_asserv_remaining(0),     // temps restant si interruption par l'evitement, rajouter un dela temps
    time_delta_time_after_interrupt(SLAVE_TIME_SUP_APRES_STOP),
    time_out_on(false),
    t_over(false),
    evitement_actif(false),       // pour savoir si on consulte les sonar ou pas
    interruption_par_evitement(false),
    bavardeur_bumper(false),
    tour_a_faire(0),
    tour_effectuee(0)
{
    chenille_laterale.attach(PIN_PWM_MOTEUR_CHENILLE_LATERALE);
    //chenille_gauche.attach(PIN_PWM_MOTEUR_CHENILLE_G);
    //chenille_droite.attach(PIN_PWM_MOTEUR_CHENILLE_D);

    alignementLaterale();

    debug_bumper_muet();
    arret();
    set_evitement_OFF();
    in_state_func();
    Serial.println("[INIT] CHENILLE PRINCIPAL");
}

void ChenillePrincipale::stop()
{
    arret();
}

Sonar* ChenillePrincipale::get_Sonar()
{
    return &sonar;
}

void ChenillePrincipale::set_evitement_OFF()
{
    evitement_actif = false;
}

void ChenillePrincipale::set_evitement_ON()
{
    evitement_actif = true;
}


/** deplacement longitudinale, chenille gauche arret moteur
*/
void ChenillePrincipale::longi_gauche_stop()
{
    //chenille_gauche.writeMicroseconds(LONGI_GAUCHE_STOP);
    analogWrite(MOT_A_EN, 0);
    digitalWrite(MOT_A_I1,LOW);
    digitalWrite(MOT_A_I2,LOW);
}

/** deplacement longitudinale, chenille gauche avance
*/
void ChenillePrincipale::longi_gauche_avance()
{
    //chenille_gauche.writeMicroseconds(LONGI_GAUCHE_AVANCE);
    analogWrite(MOT_A_EN, 100);
    digitalWrite(MOT_A_I1,LOW);
    digitalWrite(MOT_A_I2,HIGH);
}

/** deplacement longitudinale, chenille gauche recule
*/
void ChenillePrincipale::longi_gauche_recule()
{
    //chenille_gauche.writeMicroseconds(LONGI_GAUCHE_RECULE);
    analogWrite(MOT_A_EN, 100);
    digitalWrite(MOT_A_I1,HIGH);
    digitalWrite(MOT_A_I2,LOW);
}


/** deplacement longitudinale, chenille droite arret moteur
*/
void ChenillePrincipale::longi_droite_stop()
{
    chenille_droite.writeMicroseconds(LONGI_DROITE_STOP);
    analogWrite(MOT_B_EN, 0);
    digitalWrite(MOT_B_I1,LOW);
    digitalWrite(MOT_B_I2,LOW);
}

/** deplacement longitudinale, chenille droite avance
*/
void ChenillePrincipale::longi_droite_avance()
{
    //chenille_droite.writeMicroseconds(LONGI_DROITE_AVANCE);
    analogWrite(MOT_B_EN, 100);
    digitalWrite(MOT_B_I1,HIGH);
    digitalWrite(MOT_B_I2,LOW);
}

/** deplacement longitudinale, chenille droite recule
*/
void ChenillePrincipale::longi_droite_recule()
{
    //chenille_droite.writeMicroseconds(LONGI_DROITE_RECULE);
    analogWrite(MOT_B_EN, 100);
    digitalWrite(MOT_B_I1,LOW);
    digitalWrite(MOT_B_I2,HIGH);
}


/** deplacement laterale gauche
*/
void ChenillePrincipale::lateral_gauche()
{
    chenille_laterale.writeMicroseconds(CHENILLE_LATERALE_DEPLACEMENT_GAUCHE);
}

/** deplacement laterale droite
*/
void ChenillePrincipale::lateral_droite()
{
    chenille_laterale.writeMicroseconds(CHENILLE_LATERALE_DEPLACEMENT_DROITE);
}

/** deplacement laterale arrret moteur
*/
void ChenillePrincipale::lateral_stop()
{
    chenille_laterale.writeMicroseconds(CHENILLE_LATERALE_ARRET);
}

// arrete toutes les chaines sans scrupules
void ChenillePrincipale::arret(){
    lateral_stop();
    longi_droite_stop();
    longi_gauche_stop();
}



// tempo
void ChenillePrincipale::set_time_out(int dt_)
{
    t_over = millis() + dt_;
    time_out_on = true;
    //trigger_to_be = trigger;
    Serial.print("time_out set ");
    //Serial.println(trigger);
}

// reset time out
void ChenillePrincipale::reset_time_out()
{
    time_out_on = false;
}

// es ce que c'est fini
bool ChenillePrincipale::is_time_out()
{
   if (time_out_on && t_over < millis())
   {
     time_out_on = false;
     return true;
   }
   return false;
}

/** boucle de control
*/
void ChenillePrincipale::run(){

    // actualisation des sonars pour deplacement
    sonar.run();
    ir_compteur_lat.run();

    if (period_run.is_over())
    {
        period_run.reset();

        // affiche bumper
        if(bavardeur_bumper)
        {
            affiche_bumper();
        }

        // si le temps est fini
        if (is_time_out())
        {
            trigger(SLAVE_TRIGGER_TIME_OUT);
        }
    }


        /** DEPLACEMENT AVANT */
        if (state == SLAVE_STATE_DEPLACEMENT_AVANT_ACTION)
        {
            // detection adversaire prioitaire
            if(evitement_actif && sonar.adv_face())
            {
                    trigger(SLAVE_TRIGGER_PAUSE);
                    Serial.println("# ADV DETECTED FACE");
            }
            else
            {
                // detection aux bumpers ensuite
                if(bumper_av_d.is_on() && bumper_av_g.is_on())
                {
                    trigger(SLAVE_TRIGGER_BUMP_FACE);
                }
            }
        }

        /** DEPLACEMENT GAUCHE */
        if (state == SLAVE_STATE_DEPLACEMENT_GAUCHE_ACTION)
        {
            // detection adversaire prioitaire
            if(evitement_actif && sonar.adv_gauche())
            {
                    trigger(SLAVE_TRIGGER_PAUSE);
                    Serial.println("# ADV DETECTED GAUCHE");
            }
            else
            {
                // detection aux bumpers ensuite
                if(bumper_g_ar.is_on() && bumper_g_av.is_on())
                {
                    trigger(SLAVE_TRIGGER_BUMP_GAUCHE);
                }
                else
                {
                    // on check les tours de roues
                    if(ir_compteur_lat.nbr_compteur()>=tour_a_faire && ir_compteur_lat.est_aligne())
                    {
                        trigger(SLAVE_TRIGGER_TOUR_ROUE_ATTEINT);
                    }
                }
            }
        }


        if(state == SLAVE_STATE_DEPLACEMENT_GAUCHE_ACTION_FINISHING)
        {
            if(ir_compteur_lat.est_aligne())
            {
                trigger(SLAVE_TRIGGER_TOUR_ROUE_FINISH);
            }
        }

        if(state == SLAVE_STATE_DEPLACEMENT_DROITE_ACTION_FINISHING)
        {
            if(ir_compteur_lat.est_aligne())
            {
                trigger(SLAVE_TRIGGER_TOUR_ROUE_FINISH);
            }
        }




        /** DEPLACEMENT DROITE */
        if (state == SLAVE_STATE_DEPLACEMENT_DROITE_ACTION)
        {
            // detection adversaire prioitaire
            if(evitement_actif && sonar.adv_droite())
            {
                    trigger(SLAVE_TRIGGER_PAUSE);
                    Serial.println("# ADV DETECTED DROITE");
            }
            else
            {
                // detection aux bumpers ensuite
                if(bumper_d_ar.is_on() && bumper_d_av.is_on())
                {
                    trigger(SLAVE_TRIGGER_BUMP_DROITE);
                }
                else
                {
                    // on check les tours de roues
                    if(ir_compteur_lat.nbr_compteur()>=tour_a_faire && ir_compteur_lat.est_aligne())
                    {
                        trigger(SLAVE_TRIGGER_TOUR_ROUE_ATTEINT);
                    }
                }
            }
        }



}

// pour le debug
void ChenillePrincipale::affiche_bumper()
{
    Serial.print("[BUMPER] ");
    Serial.print((int)bumper_g_ar.is_on());
    Serial.print(" ");
    Serial.print((int)bumper_g_av.is_on());
    Serial.print("\t");

    Serial.print((int)bumper_av_g.is_on());
    Serial.print(" ");
    Serial.print((int)bumper_av_d.is_on());
    Serial.print("\t");

    Serial.print((int)bumper_d_av.is_on());
    Serial.print(" ");
    Serial.print((int)bumper_d_ar.is_on());
    Serial.println();

}

// a utiliser que pour le debut (init), car bloquante
void ChenillePrincipale::alignementLaterale()
{
    Serial.println("[Chaine principale] alignement en cours");
    Serial.print("rotation : ");

    if(couleur == COULEUR_JAUNE)
        {
            Serial.println("droite");
        }
        if(couleur == COULEUR_VERT)
        {
            Serial.println("gauche");
        }
    Serial.print("couleur : ");
    Serial.println(couleur);
    int cpt(0);
    while(!ir_compteur_lat.est_aligne())
    {
        cpt++;
        //Serial.print(cpt);
        //Serial.print(" ");
        if(couleur == COULEUR_JAUNE)
        {
            lateral_droite();
        }
        if(couleur == COULEUR_VERT)
        {
            lateral_gauche();
        }
        delay(5);

        if(cpt>500)
        {
            Serial.println("\n[ALIGNEMENT] ECHEC");
            lateral_stop();
            return;
        }
    }
    lateral_stop();
    Serial.println("\n[ALIGNEMENT] SUCCESS");
}

// va bumper a droite et s'arrete
void ChenillePrincipale::recalage_gauche(){
    ir_compteur_lat.reset_compteur();
    tour_a_faire = 6; // just in case
    time_asserv_to_do = SLAVE_TIME_OUT_RECALAGE; //par default 15s si ca fini pas on passe ailleurs
    //set_evitement_OFF();
    trigger(SLAVE_TRIGGER_LATERAL_GAUCHE);
}

//va bumper a gauche et s'arrete
void ChenillePrincipale::recalage_droite(){
    ir_compteur_lat.reset_compteur();
    tour_a_faire = 6; // just in case
    time_asserv_to_do = SLAVE_TIME_OUT_RECALAGE; //par default 15s si ca fini pas on passe ailleurs
    //set_evitement_OFF();
    trigger(SLAVE_TRIGGER_LATERAL_DROITE);
}

// va bumper en face et s'arrete
void ChenillePrincipale::recalage_face(){
    time_asserv_to_do = SLAVE_TIME_OUT_RECALAGE; //par default 15s si ca fini pas on passe ailleurs
    //set_evitement_OFF();
    trigger(SLAVE_TRIGGER_LONGITUDINAL_AVANT);
}

// decalage lateral avec compteur de tour de roue
void ChenillePrincipale::decalage_droite(int tour_de_roue){
    time_asserv_to_do = 20000;       // au cas ou
    tour_a_faire = tour_de_roue;
    ir_compteur_lat.reset_compteur();
    //set_evitement_ON();
    // il faut activer l'evitement de l'exterieur
    trigger(SLAVE_TRIGGER_LATERAL_DROITE);
}


void ChenillePrincipale::decalage_gauche(int tour_de_roue){
    time_asserv_to_do = 20000;      // au cas ou
    tour_a_faire = tour_de_roue;
    ir_compteur_lat.reset_compteur();
    //set_evitement_ON();
    // il faut activer l'evitement de l'exterieur
    trigger(SLAVE_TRIGGER_LATERAL_GAUCHE);
}

void ChenillePrincipale::decalage_avant(long tempsTotAction){

    time_asserv_to_do = tempsTotAction;
    //set_evitement_ON();
    // il faut activer l'evitement de l'exterieur
    trigger(SLAVE_TRIGGER_LONGITUDINAL_AVANT);
}


void ChenillePrincipale::decalage_arriere(long tempsTotAction){
    time_asserv_to_do = tempsTotAction;
    //set_evitement_OFF();        // pas besoin ici et puis ya pas de sonar derrriere :P
    // il faut activer l'evitement de l'exterieur
    trigger(SLAVE_TRIGGER_LATERAL_DROITE);
}

void ChenillePrincipale::stop_asserv()
{
    trigger(SLAVE_TRIGGER_STOP);
}

// pause l'asserv manuellement pour test, sinon c'est automatique avec l'evitement
void ChenillePrincipale::pause_asserv()
{
    trigger(SLAVE_TRIGGER_PAUSE);
}

// reprise de l'asser en cours
void ChenillePrincipale::reprise()
{
    trigger(SLAVE_TRIGGER_REPRISE);
}


// appel de transistion MAE
void ChenillePrincipale::trigger(int transition)
{
    Serial.println("");
    Serial.print("appel trigger slave : ");
    Serial.println(transition);

    if (transition == SLAVE_TRIGGER_BUMP_DROITE || transition == SLAVE_TRIGGER_BUMP_GAUCHE || transition == SLAVE_TRIGGER_BUMP_FACE )
    {
         Serial.println(" ");
         Serial.print("[SLAVE] TRANSISTION AUTOMATIQUE: BUMPER ACTIF");
         Serial.println(transition);
    }

    if (transition == SLAVE_TRIGGER_LATERAL_DROITE || transition == SLAVE_TRIGGER_LATERAL_GAUCHE || transition == SLAVE_TRIGGER_LONGITUDINAL_ARRIERE || transition == SLAVE_TRIGGER_LONGITUDINAL_AVANT )
    {
         Serial.println(" ");
         Serial.print("[SLAVE] TRANSISTION FORCEE: DEPLACEMENT");
         Serial.println(transition);
    }

    if (transition == SLAVE_TRIGGER_PAUSE || transition == SLAVE_TRIGGER_REPRISE || transition== SLAVE_TRIGGER_STOP)
    {
         Serial.println(" ");
         Serial.print("[SLAVE] TRANSISTION FORCEE: PAUSE/STOP/REPRISE");
         Serial.println(transition);
    }

    if (transition == SLAVE_TRIGGER_REPRISE )
    {
         Serial.println(" ");
         Serial.print("[SLAVE] TRANSISTION FORCEE: REPRISE");
         Serial.println(transition);
    }
    if (transition == SLAVE_TRIGGER_TOUR_ROUE_FINISH )
    {
         Serial.println(" ");
         Serial.print("[SLAVE] TRANSISTION FORCEE: FIN DU TOUR DE ROUE ACTUEL");
         Serial.println(transition);
    }

    if (transition == SLAVE_TRIGGER_TOUR_ROUE_ATTEINT)
    {
         Serial.println(" ");
         Serial.print("[SLAVE] TRANSISTION FORCEE: FIN DU TOUR DE ROUE ATTEINT");
         Serial.println(transition);
    }

    if (transition == TRANS_TAPIS_TIME_OUT  )
    {
         Serial.println(" ");
         Serial.print("[SLAVE] TRANSITION AUTOMATIQUE: TIME OUT");
         Serial.println(transition);

    }
   Serial.print("[SLAVE] ACTUAL STATE ->  ");
   Serial.println(state);
   int old_state;
   old_state = state;
   switch(state)
    {
        case SLAVE_STATE_REPOS  :
           if (transition == SLAVE_TRIGGER_LATERAL_GAUCHE )
           {
                state = SLAVE_STATE_DEPLACEMENT_GAUCHE_ACTION;
                time_asserv_started = millis();
                Serial.println("[SLAVE] Deplacement gauche");
           }
           if (transition == SLAVE_TRIGGER_LATERAL_DROITE )
           {
                state = SLAVE_STATE_DEPLACEMENT_DROITE_ACTION;
                time_asserv_started = millis();
                Serial.println("[SLAVE] Deplacement droite");
           }
           if (transition == SLAVE_TRIGGER_LONGITUDINAL_AVANT )
           {
                state = SLAVE_STATE_DEPLACEMENT_AVANT_ACTION;
                time_asserv_started = millis();
                Serial.println("[SLAVE] Deplacement avant");
           }
           if (transition == SLAVE_TRIGGER_LONGITUDINAL_ARRIERE )
           {
                state = SLAVE_STATE_DEPLACEMENT_ARRIERE_ACTION;
                Serial.println("[SLAVE] Deplacement arriere");
           }
           break;


        case SLAVE_STATE_DEPLACEMENT_GAUCHE_ACTION  :
           if(transition == SLAVE_TRIGGER_TOUR_ROUE_ATTEINT)
           {
                state = SLAVE_STATE_REPOS;
                Serial.println("[SLAVE] Deplacement gauche fin, tour de roue atteint");
                Serial.println("# ASSFINI");
           }
           if (transition == SLAVE_TRIGGER_TIME_OUT )
           {
                state = SLAVE_STATE_REPOS;
                Serial.println("[SLAVE] Deplacement gauche fin, time out");
                Serial.println("# ASSFINI");
           }
           if (transition == SLAVE_TRIGGER_BUMP_GAUCHE )
           {
                state = SLAVE_STATE_REPOS;
                Serial.println("[SLAVE] Deplacement gauche fin, bumpers actifs");
                Serial.println("# ASSFINI");
           }
           if (transition == SLAVE_TRIGGER_PAUSE )
           {
                state = SLAVE_STATE_DEPLACEMENT_GAUCHE_ACTION_FINISHING;
                Serial.println("[SLAVE] Deplacement gauche interruption, vers fin du tour de roue");
                Serial.println("# PAUSE");
           }
           break;


       case SLAVE_STATE_DEPLACEMENT_GAUCHE_ACTION_FINISHING  :
           if (transition == SLAVE_TRIGGER_TOUR_ROUE_FINISH)
           {
                state = SLAVE_STATE_DEPLACEMENT_GAUCHE_PAUSE;
                Serial.println("[SLAVE] Deplacement gauche tour de roue alignement");
           }
           if(transition == SLAVE_TRIGGER_TIME_OUT)
           {
                state = SLAVE_STATE_DEPLACEMENT_GAUCHE_PAUSE;
                Serial.println("[SLAVE] Deplacement gauche tour de roue alignement.... time out, fail alignement");
           }
           break;



        case SLAVE_STATE_DEPLACEMENT_GAUCHE_PAUSE  :
           if (transition == SLAVE_TRIGGER_REPRISE )
           {
                state = SLAVE_STATE_DEPLACEMENT_GAUCHE_ACTION;
                tour_effectuee = ir_compteur_lat.nbr_compteur();
                ir_compteur_lat.reset_compteur();
                tour_a_faire -= tour_effectuee;
                if(tour_a_faire<0){tour_a_faire=0;}
                Serial.println("[SLAVE] Deplacement gauche reprise");
           }
           if (transition == SLAVE_TRIGGER_STOP )
           {
                state = SLAVE_STATE_REPOS;
                Serial.println("[SLAVE] STOP");
           }
           break;


        case SLAVE_STATE_DEPLACEMENT_DROITE_ACTION  :
           if(transition == SLAVE_TRIGGER_TOUR_ROUE_ATTEINT)
           {
                state = SLAVE_STATE_REPOS;
                Serial.println("[SLAVE] Deplacement gauche fin, tour de roue atteint");
                Serial.println("# ASSFINI");
           }
           if (transition == SLAVE_TRIGGER_TIME_OUT )
           {
                state = SLAVE_STATE_REPOS;
                Serial.println("[SLAVE] Deplacement droite fin, time out");
                Serial.println("# ASSFINI");
           }
           if (transition == SLAVE_TRIGGER_BUMP_DROITE)
           {
                state = SLAVE_STATE_REPOS;
                Serial.println("[SLAVE] Deplacement droite fin, bumpers actifs");
                Serial.println("# ASSFINI");
           }
           if (transition == SLAVE_TRIGGER_PAUSE )
           {
                state = SLAVE_STATE_DEPLACEMENT_DROITE_ACTION_FINISHING;
                Serial.println("[SLAVE] Deplacement droite interruption, vers fin de tour roue");
                Serial.println("# PAUSE");
           }
           break;

       case SLAVE_STATE_DEPLACEMENT_DROITE_ACTION_FINISHING  :
           if (transition == SLAVE_TRIGGER_TOUR_ROUE_FINISH)
           {
                state = SLAVE_STATE_DEPLACEMENT_DROITE_PAUSE;
                Serial.println("[SLAVE] Deplacement droite tour de roue alignement");
           }
           if(transition == SLAVE_TRIGGER_TIME_OUT)
           {
                state = SLAVE_STATE_DEPLACEMENT_DROITE_PAUSE;
                Serial.println("[SLAVE] Deplacement droite tour de roue alignement.... time out, fail alignement");
           }
           break;

        case SLAVE_STATE_DEPLACEMENT_DROITE_PAUSE  :
           if (transition == SLAVE_TRIGGER_REPRISE )
           {
                state = SLAVE_STATE_DEPLACEMENT_DROITE_ACTION;
                tour_effectuee = ir_compteur_lat.nbr_compteur();
                ir_compteur_lat.reset_compteur();
                tour_a_faire -= tour_effectuee;
                if(tour_a_faire<0){tour_a_faire=0;}
                Serial.println("[SLAVE] Deplacement droite reprise");
           }
           if (transition == SLAVE_TRIGGER_STOP )
           {
                state = SLAVE_STATE_REPOS;
                Serial.println("[SLAVE] STOP");
           }
           break;

        case SLAVE_STATE_DEPLACEMENT_AVANT_ACTION  :
           if (transition == SLAVE_TRIGGER_TIME_OUT )
           {
                state = SLAVE_STATE_REPOS;
                Serial.println("[SLAVE] Deplacement avant fin, time out");
                Serial.println("# ASSFINI");
           }
           if (transition == SLAVE_TRIGGER_BUMP_FACE)
           {
                state = SLAVE_STATE_REPOS;
                Serial.println("[SLAVE] Deplacement avant fin, bumpers actifs");
                Serial.println("# ASSFINI");
           }
           if (transition == SLAVE_TRIGGER_PAUSE )
           {
                state = SLAVE_STATE_DEPLACEMENT_AVANT_PAUSE;
                // temps restant a faire pour l'asserv
                time_asserv_remaining = time_asserv_to_do - (millis() - time_asserv_started);
                if(time_asserv_remaining <=0 ){time_asserv_remaining=0;}
                // to do after reprise
                time_asserv_to_do = time_asserv_remaining + time_delta_time_after_interrupt;
                Serial.println("[SLAVE] Deplacement avant interruption");
                Serial.println("# PAUSE");
           }
           break;


        case SLAVE_STATE_DEPLACEMENT_AVANT_PAUSE  :
           if (transition == SLAVE_TRIGGER_REPRISE )
           {
                state = SLAVE_STATE_DEPLACEMENT_AVANT_ACTION;
                time_asserv_started = millis();
                Serial.println("[SLAVE] Deplacement avant reprise");
           }
           if (transition == SLAVE_TRIGGER_STOP )
           {
                state = SLAVE_STATE_REPOS;
                Serial.println("[SLAVE] STOP");
           }
           break;

        case SLAVE_STATE_DEPLACEMENT_ARRIERE_ACTION  :
           if (transition == SLAVE_TRIGGER_TIME_OUT )
           {
                state = SLAVE_STATE_REPOS;
                Serial.println("[SLAVE] Deplacement arriere fin, time out");
                Serial.println("# ASSFINI");
           }
           break;
    }
   if (old_state != state)
    {
        Serial.print("[SLAVE] NEW STATE ->  ");
        Serial.println(state);
        reset_time_out();
        in_state_func();
    }
}



void ChenillePrincipale::in_state_func()
{
    switch (state)
    {
        case SLAVE_STATE_REPOS  :
           Serial.println("[SLAVE][ETAT] REPOS]");
           arret();
           break;


        case SLAVE_STATE_DEPLACEMENT_GAUCHE_ACTION  :
           Serial.println("[SLAVE][ETAT] DEPLACEMENT LATERAL GAUCHE ACTION");
           Serial.print("time asserv to do : ");
           Serial.println("10s before time out");
           Serial.print("tour de roue a faire : ");
           Serial.println(tour_a_faire);
           set_time_out(10000);
           lateral_gauche();
           break;

        case SLAVE_STATE_DEPLACEMENT_GAUCHE_ACTION_FINISHING  :
           Serial.println("[SLAVE][ETAT] DEPLACEMENT LATERAL GAUCHE ACTION FINISHING");
           set_time_out(5000);   // si jamais on a un blocage IR
           Serial.print("tour de roue fait : ");
           Serial.println(ir_compteur_lat.nbr_compteur());
           break;

        case SLAVE_STATE_DEPLACEMENT_GAUCHE_PAUSE  :
           Serial.println("[SLAVE][ETAT] DEPLACEMENT LATERAL GAUCHE PAUSE");
           Serial.print("tour de roue fait : ");
           Serial.println(ir_compteur_lat.nbr_compteur());
           lateral_stop();
           break;

        case SLAVE_STATE_DEPLACEMENT_DROITE_ACTION  :
           Serial.println("[SLAVE][ETAT] DEPLACEMENT LATERAL DROITE ACTION");
           Serial.print("time asserv to do : ");
           Serial.println("10s before time out");
           Serial.print("tour de roue a faire : ");
           Serial.println(tour_a_faire);
           set_time_out(10000);
           lateral_droite();
           break;

        case SLAVE_STATE_DEPLACEMENT_DROITE_ACTION_FINISHING  :
           Serial.println("[SLAVE][ETAT] DEPLACEMENT LATERAL DROITE ACTION FINISHING");
           set_time_out(5000);   // si jamais on a un blocage IR
           Serial.print("tour de roue fait : ");
           Serial.println(ir_compteur_lat.nbr_compteur());
           break;

        case SLAVE_STATE_DEPLACEMENT_DROITE_PAUSE  :
           Serial.println("[SLAVE][ETAT] DEPLACEMENT LATERAL DROITE PAUSE");
           lateral_stop();
           break;

        case SLAVE_STATE_DEPLACEMENT_AVANT_ACTION  :
           Serial.println("[SLAVE][ETAT] DEPLACEMENT AVANT ACTION");
           Serial.print("time asserv to do : ");
           Serial.println(time_asserv_to_do);
           set_time_out(time_asserv_to_do);
           longi_droite_avance();
           longi_gauche_avance();
           break;


        case SLAVE_STATE_DEPLACEMENT_AVANT_PAUSE  :
           Serial.println("[SLAVE][ETAT] DEPLACEMENT AVANT PAUSE");
           longi_droite_stop();
           longi_gauche_stop();
           break;

        case SLAVE_STATE_DEPLACEMENT_ARRIERE_ACTION  :
           Serial.println("[SLAVE][ETAT] DEPLACEMENT ARRIERE ACTION");
           set_time_out(time_asserv_to_do);
           Serial.print("time asserv to do : ");
           Serial.println(time_asserv_to_do);
           longi_droite_recule();
           longi_gauche_recule();
           break;
    }
}

IR_compteur* ChenillePrincipale::get_IR_compteur()
{
    return &ir_compteur_lat;
}


void ChenillePrincipale::debug_bumper_muet()
{
    bavardeur_bumper = false;
}
void ChenillePrincipale::debug_bumper_bavard()
{
    bavardeur_bumper = true;
}

/*********************************************************************
    TURBINE
*********************************************************************/
Turbine::Turbine()
{
    turbine.attach(PIN_PWM_SERVO_TURBINE);
    OFF();
}

void Turbine::OFF(){
    turbine.writeMicroseconds(TURBINE_OFF);
}

void Turbine::ON(){
    turbine.writeMicroseconds(1400); // a laisser fixe
}



/*********************************************************************
    NOZZLE
*********************************************************************/
Nozzle::Nozzle()
{
    nozzle.attach(PIN_PWM_SERVO_NOZZLE);
    middle();
}

void Nozzle::haut(){
    nozzle.writeMicroseconds(NOZZLE_HAUT);
}
void Nozzle::middle(){
    nozzle.writeMicroseconds(NOZZLE_MIDDLE);
}
void Nozzle::bas(){
    nozzle.writeMicroseconds(NOZZLE_BAS);
}



/*********************************************************************
    PINCE
*********************************************************************/
Pince::Pince(bool cote_droit_v)
{
    cote_droit = cote_droit_v;
    if(cote_droit){
        garde.attach(PIN_PWM_SERVO_GARDE_D);
        bras.attach(PIN_PWM_SERVO_BRAS_D);
        val_initiale = BRAS_DROITE_RANGE;
        val_temporaire = val_initiale;
        val_target = val_initiale;
    }
    else{
        garde.attach(PIN_PWM_SERVO_GARDE_G);
        bras.attach(PIN_PWM_SERVO_BRAS_G);
        val_initiale = BRAS_GAUCHE_RANGE;
        val_temporaire = val_initiale;
        val_target = val_initiale;
    }
    haut();
    pince_ON();

}

void Pince::haut(){
    if(cote_droit){
        bras.writeMicroseconds(BRAS_DROITE_RANGE);
        val_initiale = BRAS_DROITE_RANGE;
    }
    else{
        bras.writeMicroseconds(BRAS_GAUCHE_RANGE);
        val_initiale = BRAS_GAUCHE_RANGE;
    }
}
void Pince::middle(){
    if(cote_droit){
        bras.writeMicroseconds(BRAS_DROITE_MIDDLE);
        val_initiale = BRAS_DROITE_MIDDLE;
    }
    else{
        bras.writeMicroseconds(BRAS_DROITE_MIDDLE);
        val_initiale = BRAS_GAUCHE_MIDDLE;
    }
}

void Pince::bas(){
    if(cote_droit){
        bras.writeMicroseconds(BRAS_DROITE_BAS);
        val_initiale = BRAS_DROITE_BAS;
    }
    else{
        bras.writeMicroseconds(BRAS_GAUCHE_BAS);
        val_initiale = BRAS_GAUCHE_BAS;
    }
}

void Pince::pince_ON(){
    if(cote_droit){
        garde.writeMicroseconds(GARDE_DROITE_ON);
    }
    else{
        garde.writeMicroseconds(GARDE_GAUCHE_ON);
    }
}

void Pince::set_target(int objectif)    // haut, milieu, bas
{
    if(cote_droit)
    {
        if(objectif == HAUT){   val_target = BRAS_DROITE_RANGE;}
        if(objectif == MILIEU){ val_target = BRAS_DROITE_MIDDLE;}
        if(objectif == BAS){    val_target = BRAS_DROITE_BAS;}
    }
    else
    {
        if(objectif == HAUT){   val_target = BRAS_GAUCHE_RANGE;}
        if(objectif == MILIEU){ val_target = BRAS_GAUCHE_MIDDLE;}
        if(objectif == BAS){    val_target = BRAS_GAUCHE_BAS;}
    }
    val_temporaire = val_initiale;
}

void Pince::incrementation()
{
    Serial.print("target : ");
    Serial.print(val_target);
    Serial.print("\t actual : ");
    Serial.println(val_temporaire);


    val_temporaire += (val_target-val_initiale)/abs(val_target-val_initiale)*PAS_INCREMENTATION;
    if(abs(val_temporaire-val_target)<2*PAS_INCREMENTATION)
    {
        val_temporaire = val_target;
        val_initiale = val_target;
    }
}

bool Pince::is_cmd_finie()
{
    return (val_temporaire == val_target);
}

void Pince::send_command()
{
    bras.writeMicroseconds(val_temporaire);

}



void Pince::pince_OFF(){
    if(cote_droit){
        garde.writeMicroseconds(GARDE_DROITE_OFF);
    }
    else{
        garde.writeMicroseconds(GARDE_GAUCHE_OFF);
    }
}


/*********************************************************************
    DeposeurTapis
*********************************************************************/
DeposeurTapis::DeposeurTapis():
    turbine(),
    nozzle(),
    pince_droite(true),
    pince_gauche(false),
    time_out_on(false),
    state(0),
    period_run(30)
    {

    }

// attention l'appel des transistions est sequentiel 1, puis 2,3 et 4

// depose le premier tapis
void DeposeurTapis::depose_first()
{
    trigger(TRANS_TAPIS_POSE_FIRST);
}

//remballe le premier tapis
void DeposeurTapis::replis_first()
{
    trigger(TRANS_TAPIS_REPLI_FIRST);
}

// depose le second tapis
void DeposeurTapis::depose_second()
{
    trigger(TRANS_TAPIS_POSE_SECOND);
}

// replis le second
void DeposeurTapis::replis_second()
{
    trigger(TRANS_TAPIS_REPLI_SECOND);
}

// appel de transistion
void DeposeurTapis::trigger(int transition)
{
    Serial.println("");
    Serial.print("appel trigger depose tapis : ");
    Serial.println(transition);

    if (transition == TRANS_TAPIS_POSE_FIRST  || transition == TRANS_TAPIS_REPLI_FIRST  || transition == TRANS_TAPIS_POSE_SECOND  || transition == TRANS_TAPIS_REPLI_SECOND  )
    {
         Serial.println(" ");
         Serial.print("TRANSISTION FORCEE -> depose tapis: ");
         Serial.println(transition);
    }

    if (transition == TRANS_TAPIS_TIME_OUT  )
    {
         Serial.println(" ");
         Serial.print("TRANSITION AUTO -> depose tapis: ");
         Serial.println(transition);

    }
   Serial.print("ACTUAL STATE -> depose tapis : ");
   Serial.println(state);
   int old_state;
   old_state = state;
   switch(state)
    {
        case ETAT_TAPIS_INIT  :
           if (transition == TRANS_TAPIS_POSE_FIRST )
           {
                state = ETAT_TAPIS_AT ;
           }
           break;

         case ETAT_TAPIS_AT  :
           if (transition == TRANS_TAPIS_TIME_OUT  )
           {
                state = ETAT_TAPIS_DF_1 ;
           }
           break;

        case ETAT_TAPIS_DF_1  :
           //if (transition == TRANS_TAPIS_TIME_OUT  )
           if (transition == TRANS_TAPIS_FIN_ASSERV  )
           {
                state = ETAT_TAPIS_DF_2   ;
           }
           break;

        case ETAT_TAPIS_DF_2   :
           if (transition == TRANS_TAPIS_TIME_OUT )
           {
                state = ETAT_TAPIS_DF_3  ;
           }
           break;

        case ETAT_TAPIS_DF_3   :
           if (transition == TRANS_TAPIS_FIN_ASSERV )
           {
                state = ETAT_TAPIS_DFP_1  ;
           }
           break;

         case ETAT_TAPIS_DFP_1   :
           if (transition == TRANS_TAPIS_TIME_OUT )
           {
                state = ETAT_TAPIS_DFP_2  ;
           }
           break;

        case ETAT_TAPIS_DFP_2   :
           if (transition == TRANS_TAPIS_REPLI_FIRST  )
           {
                state = ETAT_TAPIS_RF_1  ;
           }
           break;

        case ETAT_TAPIS_RF_1   :
           if (transition == TRANS_TAPIS_FIN_ASSERV )
           {
                state = ETAT_TAPIS_RF_2  ;
           }
           break;

        case ETAT_TAPIS_RF_2    :
           if (transition == TRANS_TAPIS_POSE_SECOND  )
           {
                state = ETAT_TAPIS_DS_1   ;
           }
           break;

        case ETAT_TAPIS_DS_1    :
           if (transition == TRANS_TAPIS_FIN_ASSERV )
           {
                state = ETAT_TAPIS_DS_2   ;
           }
           break;

          case ETAT_TAPIS_DS_2     :
           if (transition == TRANS_TAPIS_FIN_ASSERV )
           {
                state = ETAT_TAPIS_DS_3    ;
           }
           break;

        case ETAT_TAPIS_DS_3     :
           if (transition == TRANS_TAPIS_FIN_ASSERV )
           {
                state = ETAT_TAPIS_DSP_1    ;
           }
           break;

          case ETAT_TAPIS_DSP_1      :
           if (transition == TRANS_TAPIS_TIME_OUT )
           {
                state = ETAT_TAPIS_DSP_2     ;
           }
           break;

        case ETAT_TAPIS_DSP_2      :
           if (transition == TRANS_TAPIS_REPLI_SECOND  )
           {
                state = ETAT_TAPIS_RS_1     ;
           }
           break;

          case ETAT_TAPIS_RS_1       :
           if (transition == TRANS_TAPIS_FIN_ASSERV )
           {
                state = ETAT_TAPIS_RS_2      ;
           }
           break;

          case ETAT_TAPIS_RS_2        :
           if (transition == TRANS_TAPIS_FIN_ASSERV )
           {
                state = ETAT_TAPIS_RS_3       ;
           }
           break;

           case ETAT_TAPIS_RS_3        :
           if (transition == TRANS_TAPIS_FIN_ASSERV )
           {
                state = ETAT_TAPIS_INIT        ;
           }
           break;
    }
   if (old_state != state)
    {
        Serial.print("NEW STATE -> Depose Tapis: ");
        Serial.println(state);

        reset_time_out();
        in_state_func();
    }
}

//le run....
void DeposeurTapis::run(){
    if (period_run.is_over())
    {
        period_run.reset();
        if (is_time_out())
        {
            trigger(TRANS_TAPIS_TIME_OUT);
        }

        if(!pince_droite.is_cmd_finie() || !pince_gauche.is_cmd_finie())
        {
            if(!pince_droite.is_cmd_finie())
            {
                pince_droite.incrementation();
                pince_droite.send_command();
            }
            if(!pince_gauche.is_cmd_finie())
            {
                pince_gauche.incrementation();
                pince_gauche.send_command();
            }
            if(pince_droite.is_cmd_finie() && pince_gauche.is_cmd_finie())
            {
                trigger(TRANS_TAPIS_FIN_ASSERV);
            }
        }
    }
}

// tempo
void DeposeurTapis::set_time_out(int dt_)
{
    t_over = millis() + dt_;
    time_out_on = true;
    //trigger_to_be = trigger;
    Serial.print("time_out set ");
    //Serial.println(trigger);
}

// reset time out
void DeposeurTapis::reset_time_out()
{
    time_out_on = false;
}

// es ce que c'est fini
bool DeposeurTapis::is_time_out()
{
   if (time_out_on && t_over < millis())
   {
     time_out_on = false;
     return true;
   }
   return false;
}


void DeposeurTapis::in_state_func()
{
    switch (state)
    {
        case ETAT_TAPIS_INIT :
            pince_droite.haut();
            pince_droite.pince_ON();
            pince_gauche.haut();
            pince_gauche.pince_ON();
            turbine.OFF();
            nozzle.middle();
            Serial.println("ETAT_TAPIS_INIT: repos/rangee");
            break;

        case ETAT_TAPIS_AT :
            set_time_out(200);
            turbine.ON();
            nozzle.haut();
            Serial.println("ETAT_TAPIS_AT: allumage turbine");
            break;

        case ETAT_TAPIS_DF_1  :
            // descente du bras au milieu
            // mettre une transition et faire un truc dans le run
            pince_gauche.set_target(MILIEU);
            //set_time_out(1000);
            //pince_gauche.middle();
            //nozzle.haut();
            nozzle.middle();
            Serial.println("ETAT_TAPIS_DF_1: descente nozzle/descente bras gauche milieu ");
            break;

        case ETAT_TAPIS_DF_2  :
            set_time_out(2000);
            //pince_gauche.middle();
            //nozzle.middle();
            nozzle.bas();
            Serial.println("ETAT_TAPIS_DF_2: descente nozzle ");
            break;

         case ETAT_TAPIS_DF_3 :
             // idem ici
            //set_time_out(1000);
            pince_gauche.set_target(BAS);
            //pince_gauche.bas();
            nozzle.bas();
            Serial.println("ETAT_TAPIS_DF_3: descente bras gauche");
            break;

        case ETAT_TAPIS_DFP_1  :
            set_time_out(100);
            turbine.OFF();
            Serial.println("ETAT_TAPIS_DFP_1: arret turbine ");
            break;

         case ETAT_TAPIS_DFP_2  :
            pince_gauche.pince_OFF();
            Serial.println("ETAT_TAPIS_DFP_2: relache tapis gauche");
            Serial.println("# POSE TAPIS 1 POSEE");
            break;

        case ETAT_TAPIS_RF_1  :
            //set_time_out(1000);
            pince_gauche.set_target(MILIEU);
            //pince_gauche.middle();
            Serial.println("ETAT_TAPIS_RF_1: remonte bras gauche au milieu");
            break;

         case ETAT_TAPIS_RF_2  :
            pince_gauche.pince_ON();
            Serial.println("ETAT_TAPIS_RF_2: fermeture pince gauche");
            Serial.println("# POSE TAPIS 1 REMONTEE");
            break;

        case ETAT_TAPIS_DS_1  :
            //set_time_out(1000);
            //pince_gauche.bas();
            pince_gauche.set_target(BAS);
            turbine.ON();
            nozzle.haut();
            Serial.println("ETAT_TAPIS_DS_1: re-descente bras gauche/ nozzle haut/ turbine on");
            break;

         case ETAT_TAPIS_DS_2  :
            //set_time_out(1000);
            //pince_droite.middle();
            pince_droite.set_target(MILIEU);
            nozzle.middle();
            Serial.println("ETAT_TAPIS_DS_2: descente bras droite milieu/nozzle centre");
            break;

        case ETAT_TAPIS_DS_3  :
            //set_time_out(1000);
            //pince_droite.bas();
            pince_droite.set_target(BAS);
            nozzle.bas();
            Serial.println("ETAT_TAPIS_DS_3: nozzle bas / bras bas");
            break;

        case ETAT_TAPIS_DSP_1   :
            set_time_out(100);
            turbine.OFF();
            Serial.println("ETAT_TAPIS_DSP_1: coupure turbine");
            break;

        case ETAT_TAPIS_DSP_2   :
            pince_droite.pince_OFF();
            Serial.println("ETAT_TAPIS_DSP_2 : relache tapis droite");
            Serial.println("# POSE TAPIS 2 POSEE");
            break;

        case ETAT_TAPIS_RS_1   :
            //set_time_out(1000);
            //pince_droite.middle();
            pince_droite.set_target(MILIEU);
            Serial.println("ETAT_TAPIS_RS_1 : remonte pince droite");
            break;

        case ETAT_TAPIS_RS_2   :
            //set_time_out(1000);
            pince_droite.pince_ON();
            //pince_droite.haut();
            //pince_gauche.middle();
            pince_droite.set_target(HAUT);
            pince_gauche.set_target(MILIEU);
            Serial.println("ETAT_TAPIS_RS_2 : ferme pince droite et remonte pince gauche");
            break;

        case ETAT_TAPIS_RS_3   :
            //set_time_out(1000);
            pince_gauche.set_target(HAUT);
            //pince_gauche.haut();
            nozzle.middle();
            Serial.println("ETAT_TAPIS_RS_3 : remonte pince gauche");
            Serial.println("# POSE TAPIS 2 REMONTEE");
            break;
    }
}


#define SONAR_DISTANCE_MAX 100 //en cm default=500
#define SONAR_PING_INTERVAL 33
#define SONAR_SEUIL_DETECTION_ADV_LAT 30 //cm
#define SONAR_SEUIL_DETECTION_ADV_FACE 40 //cm
/****************************************************
   SONAR
*****************************************************/
Sonar::Sonar():
    period_sonar(SONAR_PING_INTERVAL),
    sonar_gauche(PIN_PWM_SONAR_G_TRIGGER,PIN_PWM_SONAR_G_Echo,SONAR_DISTANCE_MAX),
    sonar_droite(PIN_PWM_SONAR_D_TRIGGER,PIN_PWM_SONAR_D_Echo,SONAR_DISTANCE_MAX),
    sonar_face(PIN_PWM_SONAR_C_TRIGGER,PIN_PWM_SONAR_C_Echo,SONAR_DISTANCE_MAX),
    sonar_distance_droite(SONAR_DISTANCE_MAX),
    sonar_distance_gauche(SONAR_DISTANCE_MAX),
    sonar_distance_face(SONAR_DISTANCE_MAX),
    bavardeur(false)
    {

    }

void Sonar::bavard()
{
    bavardeur = true;
}

void Sonar::muet()
{
    bavardeur = false;
}

void Sonar::run()
{
     if (period_sonar.is_over())
    {
        period_sonar.reset();
        // to do telemesure
        sonar_distance_droite = sonar_droite.ping_cm();
        sonar_distance_gauche = sonar_gauche.ping_cm();
        sonar_distance_face = sonar_face.ping_cm();
        if(bavardeur)
        {
            afficheADV();
        }

    }
}
void Sonar::affiche()
{
    Serial.print("Sonar gauche : ");
    Serial.print(sonar_distance_gauche);
    Serial.println(" cm");
    Serial.print("Sonar droite : ");
    Serial.print(sonar_distance_droite);
    Serial.println(" cm");
    Serial.print("Sonar face   : ");
    Serial.print(sonar_distance_face);
    Serial.println(" cm");
}

void Sonar::afficheADV()
{
    adv_droite();
    adv_gauche();
    adv_face();
}

bool Sonar::adv_gauche()
{
    if(sonar_distance_gauche>SONAR_SEUIL_DETECTION_ADV_LAT || sonar_distance_gauche==0)
    {
        return false;
    }
    else
    {
        Serial.println("# ADV GAUCHE");  // a mettre plutot dans la sorte de slave roue
        return true;
    }
}

bool Sonar::adv_droite()
{
    if(sonar_distance_droite>SONAR_SEUIL_DETECTION_ADV_LAT || sonar_distance_droite==0)
    {
        return false;
    }
    else
    {
        Serial.println("# ADV DROITE");
        return true;
    }
}
bool Sonar::adv_face()
{
    if(sonar_distance_face>SONAR_SEUIL_DETECTION_ADV_FACE || sonar_distance_face==0)
    {
        return false;
    }
    else
    {
        Serial.println("# ADV FACE");
        return true;
    }
}

/****************************************************
   Centrale inertielle
*****************************************************/
Centrale_Inertielle::Centrale_Inertielle():
    period_centrale(PERIODE_CENTRALE),
    angle_x_gyro(0), angle_y_gyro(0), angle_z_gyro(0),
    angle_x_accel(0), angle_y_accel(0), angle_z_accel(0),
    angle_x(0), angle_y(0), angle_z(0),
    ax(0), ay(0), az(0),
    gx(0), gy(0), gz(0),
    dt(PERIODE_CENTRALE),
    force_x_accel(0), force_y_accel(0),force_z_accel(0),
    vitesse_x_accel(0),vitesse_y_accel(0),vitesse_z_accel(0)
{

    // initialisation gyro
    accelgyro.initialize();
    // verify connection
    Serial.println("Testing connection gyro...");
    //Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");

    delay(100);

    // offset, et calibration
    accelgyro.getMotion6(&ax_OC, &ay_OC, &az_OC, &gx_OC, &gy_OC, &gz_OC);
    accelgyro.setXGyroOffset(0);
    accelgyro.setYGyroOffset(0);
    accelgyro.setZGyroOffset(0);
    accelgyro.setXAccelOffset(0);
    accelgyro.setYAccelOffset(0);
    accelgyro.setZAccelOffset(0);
    delay(100);
    // mettre un 1g qq part
    muet_gyro();
    muet_accelero();
    recalibrage();
}

#define MESURE_RECALIBRATION 300
#define MESURE_TIME_PAUSE 5
void Centrale_Inertielle::recalibrage()
{
    Serial.println("[CENTRALE] debut recalibration");
    gx_OC = -221;
    gy_OC = 194;
    gz_OC = 127;

    float moy_gx, moy_gy, moy_gz;
    moy_gx = 0;
    moy_gy = 0;
    moy_gz = 0;


    for(int i = 0; i<MESURE_RECALIBRATION;i++)
    {
        /** Lecture des mesures */
        accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
        moy_gx += gx/((float)MESURE_RECALIBRATION);
        moy_gy += gy/((float)MESURE_RECALIBRATION);
        moy_gz += gz/((float)MESURE_RECALIBRATION);
        delay(MESURE_TIME_PAUSE);
    }

    gx_OC = moy_gx;
    gy_OC = moy_gy;
    gz_OC = moy_gz;
    Serial.println("[CENTRALE] fin recalibration");

}


void Centrale_Inertielle::run()
{
     if (period_centrale.is_over())
    {
        period_centrale.reset();

        /** Lecture des mesures */
        accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

        /** Calcul des angles */
        // derive du gyro



            float vx, vy,vz;
            vx = gx-gx_OC;
            vy = gy-gy_OC;
            vz = gz-gz_OC;


            if(abs(vx)<30){vx = 0;}
            if(abs(vy)<30){vy = 0;}
            if(abs(vz)<30){vz = 0;}

            angle_x_gyro = vx*dt/100000 + angle_x_gyro;
            angle_y_gyro = vy*dt/100000 + angle_y_gyro;
            angle_z_gyro = vz*dt/100000 + angle_z_gyro;

        // affiche
        if(bavardeur_gyro)
        {
            Serial.print("g:\t");
            Serial.print(gx); Serial.print("\t");
            Serial.print(gy); Serial.print("\t");
            Serial.print(gz); Serial.print("\t");

            Serial.print("v:\t");
            Serial.print(vx); Serial.print("\t");
            Serial.print(vy); Serial.print("\t");
            Serial.print(vz); Serial.print("\t");


            Serial.print("static:\t");
            Serial.print(angle_x_gyro); Serial.print("\t");
            Serial.print(angle_y_gyro); Serial.print("\t");
            Serial.print(angle_z_gyro); Serial.print("\t");
            Serial.println();
            Serial.println();
        }


        float acc_x, acc_y, acc_z;
        ax_OC = -2708;
        ay_OC = -19298;
        az_OC = -13373;
        acc_x = ax-ax_OC;
        acc_y = ay-ay_OC;
        acc_z = az-az_OC;

            if(abs(acc_x)<100){acc_x = 0;}
            if(abs(acc_y)<100){acc_y = 0;}
            if(abs(acc_z)<100){acc_z = 0;}

        force_x_accel = acc_x/100;
        force_y_accel = acc_y/100;
        force_z_accel = acc_z/100;

            vitesse_x_accel = acc_x*dt/100000 + vitesse_x_accel;
            vitesse_y_accel = acc_y*dt/100000 + vitesse_y_accel;
            vitesse_z_accel = acc_z*dt/100000 + vitesse_z_accel;

        if(bavardeur_accelero)
        {
            Serial.print("g:\t");
            Serial.print(ax); Serial.print("\t");
            Serial.print(ay); Serial.print("\t");
            Serial.print(az); Serial.print("\t");

            Serial.print("g0:\t");
            Serial.print(acc_x); Serial.print("\t");
            Serial.print(acc_y); Serial.print("\t");
            Serial.print(acc_z); Serial.print("\t");


            Serial.print("vitesse:\t");
            Serial.print(vitesse_x_accel); Serial.print("\t");
            Serial.print(vitesse_y_accel); Serial.print("\t");
            Serial.print(vitesse_z_accel); Serial.print("\t");
            Serial.println();
            Serial.println();


        }
        //affiche();
    }
}

float Centrale_Inertielle::angle_x_out()
{
    return angle_x_gyro;
}

float Centrale_Inertielle::angle_y_out()
{
    return angle_y_gyro;
}

float Centrale_Inertielle::angle_z_out()
{
    return angle_z_gyro;
}

void Centrale_Inertielle::affiche()
{
    Serial.print("angle X : ");
    Serial.print(angle_x);
    Serial.println(" deg");
    Serial.print("angle Y : ");
    Serial.print(angle_y);
    Serial.println(" deg");
    Serial.print("angle Z : ");
    Serial.print(angle_z);
    Serial.println(" deg");
    Serial.println("");

}

void Centrale_Inertielle::bavard_gyro()
{
    bavardeur_gyro = true;
}
void Centrale_Inertielle::muet_gyro()
{
    bavardeur_gyro = false;
}

void Centrale_Inertielle::bavard_accelero()
{
    bavardeur_accelero = true;
}
void Centrale_Inertielle::muet_accelero()
{
    bavardeur_accelero = false;
}

void Centrale_Inertielle::reset_angle()
{
    angle_x_gyro = 0;
    angle_y_gyro = 0;
    angle_z_gyro = 0;
}

void Centrale_Inertielle::reset_vitesse()
{
    vitesse_x_accel = 0;
    vitesse_y_accel = 0;
    vitesse_z_accel = 0;
}


/*********************************************************************
    IO
*********************************************************************/

/** CONSTRUCTEUR IO **/
IO::IO():
    deposeurTapis(),
    chenilleSecondaire(),
    chenillePrincipale()//,
    //centrale()
     // a mettre dans chenille pricipale car uniquement pour elle
{


}

void IO::stop()
{
    //deposeurTapis.stop();
    chenillePrincipale.stop();
    //chenilleSecondaire.stop();
}

void IO::run()
{
    //Serial.println("IO run");
    deposeurTapis.run();
    chenillePrincipale.run();
    chenilleSecondaire.run();
    //centrale.run();
}

DeposeurTapis* IO::get_DeposeurTapis()
{
    return &deposeurTapis;
}

ChenilleSecondaire* IO::get_ChenilleSecondaire()
{
    return &chenilleSecondaire;
}

ChenillePrincipale* IO::get_ChenillePrincipale()
{
    return &chenillePrincipale;
}
