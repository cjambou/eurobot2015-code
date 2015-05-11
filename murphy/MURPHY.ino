/*
 PROGRAMME PRINCIPAL BAS NIVEAU
 Carte : Arduino Mega 2560
 Robot : PRINCIPAL
 Nom   : MURPHY
 Annee : 2015
 Auteur: Veg (Loic MAXEL)
*/


/** INCLUDES **/
#include <Arduino.h>
#include <Servo.h>
#include "IO.h"
#include "Const.h"
#include "OrdersRaspberry.h"
#include <pnew.cpp>
#include "Utils/Switch.h"



/** DECLARATIONS **/
#define ALLUMAGE 0
#define STARTMIS 1
#define GAME 2
#define END 3

IO* io;
OrdersRaspberry* com;
Autom* slave;

int state;
int led_on;
long timer;
long TEMPS_PARTIE = 90000; //en ms mettre 90




//test capteur US

    // bumper de strategie
    Switch bumper_START(PIN_BUMPER_STRAT_START);
    Switch bumper_Couleur(PIN_BUMPER_STRAT_COULEUR);
    Switch bumper_Strat_1(PIN_BUMPER_STRAT_STRAT_1);
    Switch bumper_Strat_2(PIN_BUMPER_STRAT_STRAT_2);



/** INITIALISATION **/
void setup()
{




    bumper_Couleur.reverse();
    bumper_Strat_1.reverse();
    bumper_Strat_2.reverse();

    // pin ODO
    pinMode(19, INPUT);
    pinMode(18, INPUT);
    digitalWrite(19,HIGH);
    digitalWrite(18,HIGH);

    pinMode(PIN_ODO_PROPU_GAUCHE_B_DIR, INPUT);
    pinMode(PIN_ODO_PROPU_DROITE_B_DIR, INPUT);
    digitalWrite(PIN_ODO_PROPU_GAUCHE_B_DIR,HIGH);
    digitalWrite(PIN_ODO_PROPU_GAUCHE_B_DIR,HIGH);

    // attachement des odos de propu
    attachInterrupt(PIN_ODO_PROPU_GAUCHE_A_INC, inc_ticG, RISING);
    attachInterrupt(PIN_ODO_PROPU_DROITE_A_INC, inc_ticD, RISING);


    pinMode(2, INPUT);
    pinMode(3, INPUT);
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    pinMode(PIN_ODO_ASC_GAUCHE_B_DIR, INPUT);
    pinMode(PIN_ODO_ASC_DROITE_B_DIR, INPUT);
    digitalWrite(PIN_ODO_ASC_GAUCHE_B_DIR,HIGH);
    digitalWrite(PIN_ODO_ASC_GAUCHE_B_DIR,HIGH);



    // attachement des odos Ascenseur
    attachInterrupt(PIN_ODO_ASC_GAUCHE_A_INC, inc_ticG_ASC, RISING);
    attachInterrupt(PIN_ODO_ASC_DROITE_A_INC, inc_ticD_ASC, RISING);

    // attachement des capteurs couleur
    //attachInterrupt(PIN_COULEUR_DROITE, inc_pulse_color_D, RISING);
    //attachInterrupt(PIN_COULEUR_GAUCHE, inc_pulse_color_G, RISING);

    // initialisation du port serie
    Serial.begin(9600) ;
    Serial.println("#SERIAL READY");
    Serial.println("#BAS NIVEAU COOP'R");

    // initialisation des PINS IN et OUT
    io = new IO();
    Serial.println("INIT IO");

    // initialisation du slave
    slave = new Autom();
    Serial.println("INIT SLAVE");

    // initialisation du protocol de communication via le port serie
    com = new OrdersRaspberry(slave,io);
    Serial.println("INIT OrdersRaspberry");

    //write_serial_strat();
    Serial.println("");
    Serial.println("________________________");

    // initialisation du timer et de l'etat de depart
    state = ALLUMAGE;
    //state = GAME;
    timer = 0;
    Serial.println("etat init");

    Serial.print("* START : ");
    Serial.println((int)bumper_START.is_on());

    Serial.print("* COULEUR : ");
    Serial.println((int)bumper_Couleur.is_on());

    Serial.print("* STRAT 1 : ");
    Serial.println((int)bumper_Strat_1.is_on());

    Serial.print("* STRAT 2 : ");
    Serial.println((int)bumper_Strat_2.is_on());

    //testMoteurD.attach(PIN_PWM_MOTEUR_PROPU_DROITE);
    //testMoteurG.attach(PIN_PWM_MOTEUR_PROPU_GAUCHE);
    //testMoteurG.writeMicroseconds(1500);
    //testMoteurD.writeMicroseconds(1700);
    //gauche AV -> up 1500
    // idem pour droite

    slave->turn_off_evit();
}


/**
BOUCLE DE CONTROL
*/
void loop(){



    // enclenchement du start
   if (state == ALLUMAGE && bumper_START.is_on())
    {
        state = STARTMIS;
        Serial.println("# START_IN");
    }
    else
    {
            // debut de jeu quand le start est releve
        if (state == STARTMIS && bumper_START.is_off())
        {
            state = GAME ;
            Serial.println("# START_OUT");
            //slave->turn_on_evit();
            timer = millis();
            //Serial.println(timer);

        }
        else
        {
            // fin de partie si t>90s
            if ( (state == END) || (state == GAME && ((millis()-timer) > TEMPS_PARTIE ) ) )
            {

                Serial.println("# END_GAME");
                state = END;
                slave->stop();
                //io->stop();

            }
            else
            {
                    //Serial.println(millis()-timer);
                    com->run();
                    slave->run();
                    io->run();
            }
        }
    }


/**
            com->run();
            slave->run();
            io->run();
            delay(1);
*/

/*

    // test US
    Serial.print("SONAR GAUCHE : ");
    Serial.println(analogRead(PIN_SONAR_GAUCHE));

    Serial.print("SONAR DROITE : ");
    Serial.println(analogRead(PIN_SONAR_DROITE));

   // test des IR des ASCENSEUR
    Serial.print("IR CENTRAL : ");
    Serial.println(analogRead(PIN_IR_CENTRAL));

    Serial.print("IR BAS GAUCHE : ");
    Serial.println(analogRead(PIN_IR_BAS_GAUCHE));

    Serial.print("IR BAS DROITE : ");
    Serial.println(analogRead(PIN_IR_BAS_DROITE));

    Serial.print("IR HAUT GAUCHE : ");
    Serial.println(analogRead(PIN_IR_HAUT_GAUCHE));

    Serial.print("IR HAUT DROITE : ");
    Serial.println(analogRead(PIN_IR_HAUT_DROITE));

    Serial.print("IR MID GAUCHE : ");
    Serial.println(analogRead(PIN_IR_MID_GAUCHE));

    Serial.print("IR MID DROITE : ");
    Serial.println(analogRead(PIN_IR_MID_DROITE));

    Serial.println();


   delay(500);
*/




//   delay(200);

}

