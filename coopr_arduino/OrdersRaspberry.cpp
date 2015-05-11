#include "OrdersRaspberry.h"

//Fichier de définition des fonction pour les ordre reçu depuis la Gumstix
//Order for the big robot


/*
 CONSTRUCTEUR OrdersRaspberry
*/
OrdersRaspberry::OrdersRaspberry(IO* io_) : period(100), io(io_), serial_count(0)
{
    treated=true;
    //s.resize(28);
}


/*
 RUN OrdersRaspberry
*/
void OrdersRaspberry::run()
{
    if(period.is_over())
    {
        period.reset();
        treatSerial();

        if ( !treated)
        {
            //Serial.println("message traite");
            executeinstr();
            treated = true;
            stream.str("");
            serial_count = 0;
            s="";
            //s.resize(28);
        }
    }

}


/*
 Traitement du signal OrdersRaspberry
*/
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
        //Serial.println(serial_count);
        s = s + serial_char;
        serial_count = serial_count + 1;
    }
}




/*
 Execution des instructions OrdersRaspberry
*/
void OrdersRaspberry::executeinstr()
{
    //char ordre = cmdBuffer[bufindr][strchr_pointer];
    stream.str(s);
    std::string temp;
    stream>>temp;
    char ordre = temp[0];
    Serial.print("ordre ind = ");
    int ind = ((int)temp[1]) - 48;
    Serial.print(ordre);
    Serial.print("@");
    Serial.println(ind);

    std::string temp2;

    std::string cap;
    std::string x;
    std::string y;
    std::string z;
    std::string temps;

    bool precis;
    switch (ordre)
    {


    // chenille secondaire
	case 'S' :
        // ordre de type Tacle Laterale
        switch (ind)
        {
        case 0:
            Serial.print("chenille secondaire : OFF");
            io->get_ChenilleSecondaire()->OFF();
            break;
        case 1:
            Serial.print("chenille secondaire : ON");
            io->get_ChenilleSecondaire()->ON();
            break;
        case 2:
            Serial.print("chenille secondaire : rangee");
            io->get_ChenilleSecondaire()->position_rangee();
            break;
        case 3:
            Serial.print("chenille secondaire : mi hauteur");
            io->get_ChenilleSecondaire()->position_miHauteur();
            break;
        case 4:
            Serial.print("chenille secondaire : sol");
            io->get_ChenilleSecondaire()->position_auSol();
            break;

         case 5:
            Serial.print("chenille secondaire : MAE deployement");
            io->get_ChenilleSecondaire()->deployement();
            break;

        case 6:
            Serial.print("chenille secondaire : MAE grimpe");
            io->get_ChenillePrincipale()->set_evitement_OFF();      // pour pas avoir de merde, si une mascotte s'approche, et puis on desactive en haut des marche
            io->get_ChenillePrincipale()->recalage_face();          // en fin de montee ca va bumper
            io->get_ChenilleSecondaire()->grimpe();                 // grimpe enn meme temps que la chaine principale
            break;
       }
    break;


    // Depose tapis
	case 'T' :
        // ordre de type depose tapis
        switch (ind)
        {
        case 0:
            Serial.print("depose le premier tapis");
            io->get_DeposeurTapis()->depose_first();
            break;
        case 1:
            Serial.print("replis le premier tapis");
            io->get_DeposeurTapis()->replis_first();
            break;
        case 2:
            Serial.print("depose le second tapis");
            io->get_DeposeurTapis()->depose_second();
            break;
        case 3:
            Serial.print("replis le second tapis");
            io->get_DeposeurTapis()->replis_second();
            break;
       }
       break;



    // avance
	case 'A' :
        // AVANCE LA BASE ROULANTE
        switch (ind)
        {
        case 0:
            Serial.print("BASE ROULANTE, decalage avant :");
            // faire en sorte que l'on s'arrrete en rotation lateral sur des demi tour de roue
            stream >> temps;
            Serial.println(atoi(temps.c_str()));
            io->get_ChenillePrincipale()->decalage_avant(atoi(temps.c_str()));
            // renvoye ennemi detectee
            break;
        case 1:
            Serial.print("BASE ROULANTE, decalage arriere :");
            stream >> temps;
            Serial.println(atoi(temps.c_str()));
            io->get_ChenillePrincipale()->decalage_arriere(atoi(temps.c_str()));
            break;
        case 2:
            Serial.print("BASE ROULANTE, decalage droite :");
            stream >> temps;
            Serial.println(atoi(temps.c_str()));
            io->get_ChenillePrincipale()->decalage_droite(atoi(temps.c_str()));
            break;
        case 3:
            Serial.print("BASE ROULANTE, decalage gauche :");
            stream >> temps;
            Serial.println(atoi(temps.c_str()));
            io->get_ChenillePrincipale()->decalage_gauche(atoi(temps.c_str()));
            break;

        case 4:
            Serial.print("BASE ROULANTE, pause :");
            io->get_ChenillePrincipale()->pause_asserv();
            break;

        case 5:
            Serial.print("BASE ROULANTE, reprise :");
            io->get_ChenillePrincipale()->reprise();
            break;

        case 6:
            Serial.print("BASE ROULANTE, recalage face");
            io->get_ChenillePrincipale()->recalage_face();
            break;

        case 7:
            Serial.print("BASE ROULANTE, recalage gauche");
            // renvoyer (# AssFINI) par le port serie
            io->get_ChenillePrincipale()->recalage_gauche();
            break;

        case 8:
            Serial.print("BASE ROULANTE, recalage droite");
            // renvoyer (# AssFINI) par le port serie
            io->get_ChenillePrincipale()->recalage_droite();
            break;

        case 9:
            Serial.print("BASE ROULANTE, stop asserv");
            // renvoyer (# AssFINI) par le port serie
            io->get_ChenillePrincipale()->stop_asserv();
            break;
       }

       break;



    // DEBUG
	case 'D' :
        // ordre de type Tacle Laterale
        switch (ind)
        {
        case 0:
            Serial.print("Debug IMU, gyro on");
            //io->get_ChenilleSecondaire()->get_Centrale_Inertielle()->bavard_gyro();
            break;
        case 1:
            Serial.print("Debug IMU, gyro off");
            //io->get_ChenilleSecondaire()->get_Centrale_Inertielle()->muet_gyro();
           break;

        case 2:
            Serial.print("Debug Bumper,  on");
            //io->get_ChenilleSecondaire()->get_Centrale_Inertielle()->bavard_accelero();
            io->get_ChenillePrincipale()->debug_bumper_bavard();
            break;
        case 3:
            Serial.print("Debug bumper,  off");
            //io->get_ChenilleSecondaire()->get_Centrale_Inertielle()->muet_accelero();
            io->get_ChenillePrincipale()->debug_bumper_muet();
           break;

        case 4:
            Serial.print("Debug IMU, reset angle");
//            io->get_ChenilleSecondaire()->get_Centrale_Inertielle()->reset_angle();
            break;
        case 5:
            Serial.print("Debug IMU, reset calibration");
  //          io->get_ChenilleSecondaire()->get_Centrale_Inertielle()->recalibrage();
            break;

        case 6:
            Serial.print("Debug SONAR, on");
            io->get_ChenillePrincipale()->get_Sonar()->bavard();
            break;
        case 7:
            Serial.print("Debug SONAR, off");
            io->get_ChenillePrincipale()->get_Sonar()->muet();
            break;

        case 8:
            Serial.print("Debug IR, on");
            io->get_ChenillePrincipale()->get_IR_compteur()->bavard();
            break;

        case 9:
            Serial.print("Debug IR, off");
            io->get_ChenillePrincipale()->get_IR_compteur()->muet();
            break;
       }
    break;




    // test des chenilles principales en mode debug
	case 'Q' :
        // ordre de type Tacle Laterale
        switch (ind)
        {
        case 0:
            Serial.print("laterale gauche");
            io->get_ChenillePrincipale()->lateral_gauche();
            //io->get_ChenillePrincipale()->decalage_avant();
            break;
        case 1:
            Serial.print("laterale droite");
            // renvoyer (# AssFINI) par le port serie
            io->get_ChenillePrincipale()->lateral_droite();
            //io->get_ChenillePrincipale()->decalage_gauche();
            break;
        case 2:
            Serial.print("laterale stop");
            // renvoyer (# AssFINI) par le port serie
            io->get_ChenillePrincipale()->lateral_stop();
            //io->get_ChenillePrincipale()->decalage_droite();
            break;


        case 3:
            Serial.print("avance droite");
            io->get_ChenillePrincipale()->longi_droite_avance();
            break;
        case 4:
            Serial.print("recule droite");
            io->get_ChenillePrincipale()->longi_droite_recule();
            break;
        case 5:
            Serial.print("stop droite");
            io->get_ChenillePrincipale()->longi_droite_stop();
            break;


        case 6:
            Serial.print("avance gauche");
            io->get_ChenillePrincipale()->longi_gauche_avance();
            break;
        case 7:
            Serial.print("recule gauche");
            io->get_ChenillePrincipale()->longi_gauche_recule();
            break;
        case 8:
            Serial.print("stop gauche");
            io->get_ChenillePrincipale()->longi_gauche_stop();
            break;
       }
       break;



        // EVITEMENT
	case 'E' :
        switch (ind)
        {
        case 0:
            Serial.print("Desactivation de l'evitement");
            io->get_ChenillePrincipale()->set_evitement_OFF();
            break;
        case 1:
            Serial.print("Activation de l'evitement");
            io->get_ChenillePrincipale()->set_evitement_ON();
           break;
       }
    break;

return;
    }

}

