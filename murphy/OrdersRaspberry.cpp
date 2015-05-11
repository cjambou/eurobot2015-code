#include "OrdersRaspberry.h"

//Fichier de définition des fonction pour les ordre reçu depuis la Gumstix
//


OrdersRaspberry::OrdersRaspberry(Autom* slave_,IO* io_) :
    period(50),
    slave(slave_),
    io(io_),
    serial_count(0)
{
    treated=true;
}

void OrdersRaspberry::run()
{
    if(period.is_over())
    {
        period.reset();
        treatSerial();
        if ( !treated)
        {
            //Serial.println("coucou");
            executeinstr();
            treated = true;
            stream.str("");
            serial_count = 0;
            s="";
        }
    }

}

void OrdersRaspberry::treatSerial()
{
    char serial_char;

    // Ici on traite les différents messages reçus.
    while(Serial.available()>0 && serial_count < 28)
    {
        serial_char= Serial.read();
        if (serial_char =='\n')
        {
            //Serial.println("Fin de ligne");
            //on ne traite que les instructions de minimum 2 char
            if (serial_count<1)
            {
                treated = true;
            }
            else
            {
                treated = false;
            }
            //Serial.print("Enregistre : ");
            //Serial.print(s.c_str());
            //Serial.print("  serial_count  ");
            //Serial.println(serial_count);
            return;
        }
        s = s + serial_char;
        serial_count = serial_count + 1;
    }
}

void OrdersRaspberry::executeinstr()
{
    stream.str(s);
    std::string temp;
    stream>>temp;
    char ordre = temp[0];
    ///Serial.print("ordre ind = ");
    int ind = ((int)temp[1]) - 48;
    ///Serial.print(ordre);
    ///Serial.print("@");
    ///Serial.println(ind);
    std::string temp2;
    std::string cap;
    std::string x;
    std::string y;
    std::string z;
    std::string v;
    int r = 0;
    //int v = 0;
    int s = 0;
    bool precis;
    Coord target;
    switch (ordre)
    {


    /*****************************************************
        ordre de type camera control
    ******************************************************/
    case 'I' : // i pour image

		switch (ind)
        {
			case 0:
				Serial.print("inclinaison camera devant");
				io->get_Camera()->position_devant();
				break;

			case 1:
				Serial.print("inclinaison camera 45deg");
				io->get_Camera()->position_basse();
			break;
		}
        break;


    /*****************************************************
        ordre de type Claps
    ******************************************************/
    case 'C' : // c comme claps

		switch (ind)
        {
			case 0:
				Serial.print("ouverture clap droit");
				io->get_Aspiration_Bras()->tacle_droite();
				//io->get_Claps_droite()->ouverture();
				break;

			case 1:
				Serial.print("fermeture clap droit");
				//io->get_Claps_droite()->fermeture();
			break;

            case 2:
				Serial.print("ouverture clap gauche");
				io->get_Aspiration_Bras()->tacle_gauche();
				//io->get_Claps_gauche()->ouverture();
			break;

            case 3:
				Serial.print("fermeture clap gauche");
				//io->get_Claps_gauche()->fermeture();
			break;
		}
        break;


    /*****************************************************
        ordre de type Balle
    ******************************************************/
    case 'B' : // b comme balle

		switch (ind)
        {
			case 0:
				Serial.print("chargement balle gauche");
				io->get_Balle_gauche()->chargement();
				break;

			case 1:
				Serial.print("drop balle gauche");
				io->get_Balle_gauche()->ejection();
			break;

            case 2:
				Serial.print("attrape balle droite (par terre)");
				//io->balle_droite_trigger(TRANSISTION_BALLE_DROITE_PRISE);
				io->get_Balle_droite()->trigger(TRANSISTION_BALLE_DROITE_PRISE);
			break;

            case 3:
				Serial.print("drop balle droite");
				//io->balle_droite_trigger(TRANSISTION_BALLE_DROITE_EJECTION);
				io->get_Balle_droite()->trigger(TRANSISTION_BALLE_DROITE_EJECTION);
			break;

            case 4:
				Serial.print("debug :");
				io->get_Balle_droite()->debug();
			break;


		}
        break;


    /*****************************************************
        ordre de type Pop corn / gobelet saisie
    ******************************************************/
    case 'P' : // p comme poop corn

		switch (ind)
        {
			case 0:
				Serial.print("aspiration des balles : ON");
				io->get_Aspiration_Bras()->deboit_le_distrib();
				//io->get_Aspiration()->on();
				//io->get_Claps_droite()->ouverture();        // upgrade pour tube telescopique
				//io->get_Claps_gauche()->ouverture();
				// mettre un timer pour la pompe, histoire de securise si jamais on recoit pas d'ordre
				break;

			case 1:
				Serial.print("aspiration des balles : OFF");
				//io->get_Aspiration()->off();
				//io->get_Claps_droite()->fermeture();
				//io->get_Claps_gauche()->fermeture();
			break;

            case 2:
				Serial.print("ouverture du capot arriere");
				io->get_Capot()->ouverture_balle();
			break;

            case 3:
				Serial.print("fermeture du capot arriere");
				io->get_Capot()->fermeture();
			break;

            case 4:
				Serial.print("relache gobelet");
				io->get_Elevator_gobelet()->lache();
			break;

            case 5:
				Serial.print("souleve gobelet");
				io->get_Elevator_gobelet()->souleve();
			break;

            case 6:
				Serial.print("drop gobelet");
				io->get_Capot()->ouverture_gobelet();
				io->get_Elevator_gobelet()->lache();
			break;
		}
        break;


    /*****************************************************
        ordre de debug
    ******************************************************/
    case 'O':
            //Serial.println("debug");
            //slave->get_control()->write_debug();

        switch (ind)
        {
           case 0:
                Serial.println("Reinit");
                slave->debuggDistanceInit();
                slave->debuggTicInit();
            break;

            case 1:
                Serial.print("distance gain gauche : ");
                Serial.println(slave->debuggDistance_g());
                Serial.print("distance gain droit : ");
                Serial.println(slave->debuggDistance_d());
                Serial.print("Tic total droit : ");
                Serial.println(slave->debuggTic_d());
                Serial.print("Tic total gauche : ");
                Serial.println(slave->debuggTic_g());
            break;
        }
        break;


    /*****************************************************
        ordre de construction pile Gauche
    ******************************************************/
    case 'G':
        switch (ind)
        {
            Serial.print("pile gauche : "); // ouvre les pinces
           case 0:
                Serial.println("preparer prise"); // ouvre les pinces
                io->get_Constructeur_pile_gauche()->trigger(TRANS_PILE_PREP_SAISIE);

            break;

            case 1:
                Serial.println("attrappe le stand manuel"); // mode automatique de prise de decision
                io->get_Constructeur_pile_gauche()->trigger(TRANS_PILE_SAISIE_MANUELLE);
            break;
// voir automatique le monte directe
// ou referme simplement dessus

            case 2:
                Serial.println("range"); // mode automatique de prise de decision
                io->get_Constructeur_pile_gauche()->trigger(TRANS_PILE_FERMETURE);
            break;

            case 3:
                Serial.println("ASS FINI forcee"); // quiite le mode ouverture
                io->get_Constructeur_pile_gauche()->trigger(TRANS_PILE_ASSERV_FINI);
            break;

            case 4:
                Serial.println("prepare la pose de la pile"); // quiite le mode ouverture
                io->get_Constructeur_pile_gauche()->trigger(TRANS_PILE_PREP_DEPOT);
            break;

            case 5:
                Serial.println("depose la pile"); // 2 modes de pose, sur l'estrade ou non
                io->get_Constructeur_pile_gauche()->trigger(TRANS_PILE_POSE);
            break;

            case 6:
                Serial.println("replis"); // 2 modes de pose, sur l'estrade ou non
                io->get_Constructeur_pile_gauche()->trigger(TRANS_PILE_REPLIS);
            break;

            case 7:
                Serial.println("debug ascenseur one shot"); // 2 modes de pose, sur l'estrade ou non
                io->get_Constructeur_pile_gauche()->debug();
            break;

             case 8:
                Serial.println("set depot estrade"); // 2 modes de pose, sur l'estrade ou non
                io->get_Constructeur_pile_gauche()->set_depot_estrade(true);
            break;

            case 9:
                Serial.println("set depot sol"); // 2 modes de pose, sur l'estrade ou non
                io->get_Constructeur_pile_gauche()->set_depot_estrade(false);
            break;
            }
        break;

    /*****************************************************
        ordre de construction pile droit
    ******************************************************/
    case 'D':
        switch (ind)
        {
            Serial.print("pile droite : "); // ouvre les pinces
           case 0:
                Serial.println("preparer prise"); // ouvre les pinces
                io->get_Constructeur_pile_droite()->trigger(TRANS_PILE_PREP_SAISIE);

            break;

            case 1:
                Serial.println("attrappe le stand manuel"); // mode automatique de prise de decision
                io->get_Constructeur_pile_droite()->trigger(TRANS_PILE_SAISIE_MANUELLE);
            break;
// voir automatique le monte directe
// ou referme simplement dessus

            case 2:
                Serial.println("range"); // mode automatique de prise de decision
                io->get_Constructeur_pile_droite()->trigger(TRANS_PILE_FERMETURE);
            break;

            case 3:
                Serial.println("ASS FINI forcee"); // quiite le mode ouverture
                io->get_Constructeur_pile_droite()->trigger(TRANS_PILE_ASSERV_FINI);
            break;

            case 4:
                Serial.println("prepare la pose de la pile"); // quiite le mode ouverture
                io->get_Constructeur_pile_droite()->trigger(TRANS_PILE_PREP_DEPOT);
            break;

            case 5:
                Serial.println("depose la pile"); // 2 modes de pose, sur l'estrade ou non
                io->get_Constructeur_pile_droite()->trigger(TRANS_PILE_POSE);
            break;

            case 6:
                Serial.println("replis"); // 2 modes de pose, sur l'estrade ou non
                io->get_Constructeur_pile_droite()->trigger(TRANS_PILE_REPLIS);
            break;

            case 7:
                Serial.println("debug ascenseur, one shot"); // 2 modes de pose, sur l'estrade ou non
                io->get_Constructeur_pile_droite()->debug();
            break;

             case 8:
                Serial.println("set depot estrade"); // 2 modes de pose, sur l'estrade ou non
                io->get_Constructeur_pile_droite()->set_depot_estrade(true);
            break;

            case 9:
                Serial.println("set depot sol"); // 2 modes de pose, sur l'estrade ou non
                io->get_Constructeur_pile_droite()->set_depot_estrade(false);
            break;
        }
        break;



    /*****************************************************
        ordre de type Slave (base roulante)
    ******************************************************/
    case 'S' :
        //Vitesse vit;
        // ordre de type Slave
        switch (ind)
        {

        /** reinit les coords X,Y, CAP
        // attention ne deplace pas le robot **/
        case 0: // set x, y, cap
            Serial.print("SET X Y CAP :");
            stream >> x >> y >> cap;

            Serial.println(atoi(x.c_str()));
            if (atoi(x.c_str())== -1)
            {
                Serial.println("recal y -> x unknown");
                slave->setxycap_no_x(atoi(y.c_str()), 3.14 * atoi(cap.c_str())/ 180.0);
            }
            else
            {
                if (atoi(y.c_str())== -1)
                {
                    Serial.println("recal x -> y unknown");
                    slave->setxycap_no_y(atoi(x.c_str()), 3.14 * atoi(cap.c_str())/ 180.0);
                }
                else
                {
                    slave->setxycap(Coord(atoi(x.c_str()), atoi(y.c_str()), 3.14 * atoi(cap.c_str())/ 180.0));
                }

            }
            Serial.print(atoi(x.c_str()));
            Serial.print(" ");
            Serial.print(atoi(y.c_str()));
            Serial.print(" ");
            Serial.print(atoi(cap.c_str()));
            Serial.println(" ");
            break;


        /** donne les coordonnees du robots
        **/
        case 1:
            Serial.println("GET X Y CAP: ");
            slave->get_control()->write_real_coords();

            break;

        /** recalage arriere du robot
        **/
        case 2:
            Serial.println("Recalage");
            slave->get_control()->recaler();
            break;



        /** BFCap
        **/
        case 3:
            Serial.print("SET CAP :");
            stream >> cap;
            target = Coord(0, 0, 3.1416 * atoi(cap.c_str()) / 180.0);
            Serial.print ("BFCap ");
            Serial.println(atoi(cap.c_str()));
            slave->get_control()->set_BF(BFCAP, target);
            break;



        /** BF Avance
         x -> distance droit devant
         v -> vitesse de consigne (0 slow, 1 medium, 2 fast)
        **/
        case 4:
            stream >> x >> v;

            Serial.println("BFAvance");
            Serial.print(" ");
            Serial.print(atoi(x.c_str()));
            Serial.print(" ");
            Serial.print(atoi(v.c_str()));

            target = Coord(atoi(x.c_str()), 0, 0);

            //slave->get_control()->set_speed(atoi(v.c_str()));
            slave->get_control()->set_BF(BFFW, target);
            break;


        /** BF Droite
         x -> distance droit devant
         v -> vitesse de consigne (0 slow, 1 medium, 2 fast)
        **/
        case 5: //BFDroite

            stream >> x >> y >> cap >> v;

            Serial.print ("BFDroite ");
            Serial.print(atoi(x.c_str()));
            Serial.print(" ");
            Serial.print(atoi(y.c_str()));
            Serial.print(" ");
            Serial.println(atoi(cap.c_str()));
            //Serial.print(" ");
            //Serial.println(v);

            target = Coord(atoi(x.c_str()), atoi(y.c_str()), 3.14 * atoi(cap.c_str())/ 180.0);
            slave->get_control()->set_BF(BFXYCAP, target);
            //vit=determinerVitesse(v);
        //    slave->set<BFDroite>(x,y,cap ,vit,precis);
            break;


        /** BF cercle
         x -> distance droit devant
         v -> vitesse de consigne (0 slow, 1 medium, 2 fast)
        **/
        case 6: //BF Droite simple (sans cap)
            //stream >> x >> y >> r >> cap >> s >> v;
            stream >> x >> y >> cap >> v;
            Serial.println("BF Droite sans correction de cap");
            break;



        /** Set speed
         v -> vitesse de consigne (0 slow, 1 medium, 2 fast)
        **/
        case 7: //set speed
            Serial.println("Set speed");
            stream >> v;
            Serial.print("speed ");
            Serial.println(atoi(v.c_str()));
            slave->get_control()->set_speed(atoi(v.c_str()));
            //slave->get_control()->set_speed(1); //pour test uniquement

            break;


        /** Set gain PIDs
         x -> 0 gain dep, 1 gain cap
        **/
        case 8:
            Serial.println(" SET GAINS (DEBUG) ");

            stream>> x >> y >> z >> cap;

            if (atoi(x.c_str()) == 1 )
            {
                Serial.println("setting gains for dep");
                Serial.println(" Kp KI KV");

                slave->get_control()-> setTuningDep(atof(y.c_str()), atof(z.c_str()), atof(cap.c_str()));
                slave->get_control()->write_debug();

            }
            else
            {
                Serial.println(" setting gains for cap");
                Serial.println(" Kp KI KV");

                slave->get_control()-> setTuningCap(atof(y.c_str()), atof(z.c_str()), atof(cap.c_str()));
                slave->get_control()->write_debug();


            }
            break;

        /** Arret moteur
        **/
        case 9:
            Serial.println("SLAVE : stop");
            slave->stop();
            break;
        }
        break;




    /*****************************************************
        ordre de type evitement
    ******************************************************/
    case 'E' :

        switch (ind)
        {

        /** desactivation evitement
        **/
        case 0:
            Serial.println("EVITEMENT : OFF");
            slave->turn_off_evit();
            break;


        /** activation evitement
        **/
        case 1:
            Serial.println("EVITEMENT : ACTIF");
            slave->turn_on_evit();
            break;


        /** debugg sonar
        **/
        case 2:
            Serial.println("DEBUG SONAR: ");
            slave->get_control()->write_debug();
            break;


        /** debugg sonar
        **/
        case 3:
            Serial.println("DEBUG SONAR: flux active");
            slave->bavardeur_sonar_on();// get_control()->bavardeur_sonar_on();
            break;


        /** debugg sonar
        **/
        case 4:
            Serial.println("DEBUG SONAR: flux desactive");
            slave->bavardeur_sonar_off(); //get_control()->bavardeur_sonar_off();
            break;
        }
    break;

     /*****************************************************
        reglage offset moteur
    ******************************************************/
    case 'H' :

        switch (ind)
        {

        /** desactivation evitement
        **/
        case 0:
            Serial.println("reglage offset propu : Gauche");
            //slave->turn_off_evit();
            break;


        /** activation evitement
        **/
        case 1:
            Serial.println("reglage offset propu : Droite");
            //slave->turn_on_evit();
            break;

        }
    break;


    }


    return;


}

