/*
 PROGRAMME PRINCIPAL BAS NIVEAU
 Carte : Arduino Mega 2560
 Robot : PMI
 Nom   : COOP'R
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
#include "./Utils/SwitchAnalog.h"
//#include "./Utils/Switch.h"
#include <Utils/Period.h>

#include "I2Cdev.h"
#include "MPU6050.h"


#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif



/** DECLARATIONS **/
#define ALLUMAGE 0
#define STARTMIS 1
#define GAME 2
#define END 3


// IN/OUT et COM
IO* io;
OrdersRaspberry* com;

// pour test uniquement
//MPU6050 accelgyro;




// bumper de strat
SwitchAnalog bumper_start(PIN_BUMPER_STRAT_START,SEUIL_BUMPER);
SwitchAnalog bumper_couleur(PIN_BUMPER_STRAT_COULEUR,SEUIL_BUMPER);
SwitchAnalog bumper_strategie(PIN_BUMPER_STRAT_STRAT,SEUIL_BUMPER);


int state;
int led_on;
long timer;
long TEMPS_PARTIE = 90000; //en ms mettre 90





/** INITIALISATION **/
void setup()
{
    pinMode(MOT_A_EN,OUTPUT);
    pinMode(MOT_B_EN,OUTPUT);
    pinMode(MOT_A_I1,OUTPUT);
    pinMode(MOT_A_I2,OUTPUT);
    pinMode(MOT_B_I1,OUTPUT);
    pinMode(MOT_B_I2,OUTPUT);

    bumper_couleur.reverse(); //bumper du haut
    bumper_strategie.reverse(); // bumper du bas

	// initialisation port I2C (wire)
	// join I2C bus (I2Cdev library doesn't do this automatically)
    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif


    // initialisation du port serie
    Serial.begin(9600) ;
    Serial.println("SERIAL READY");
    Serial.println("BAS NIVEAU COOP'R");


    delay(500);

    state = ALLUMAGE;
    //state = GAME;
    timer = 0;

    Serial.println("");
    Serial.println("________________________");


    // initialisation du timer et de l'etat de depart
    timer = 0;
    Serial.println("etat init");

    Serial.print("* START : ");
    Serial.println((int)bumper_start.is_on());

    Serial.print("* COULEUR : ");
    extern int couleur;
    couleur = (int)bumper_couleur.is_on();
    Serial.println(couleur);

    Serial.print("* STRAT 1 : ");
    Serial.println((int)bumper_strategie.is_on());

    Serial.println("");
    Serial.println("________________________");

    // initialisation des PINS IN et OUT
    io = new IO();
    Serial.println("INIT IO");

    // initialisation du protocol de communication via le port serie
    com = new OrdersRaspberry(io);
    Serial.println("INIT OrdersRaspberry");

    Serial.println("");
    Serial.println("________________________");
}


/**
BOUCLE DE CONTROL
*/
void loop(){

/** BOUCLE de jeux */
    // enclenchement du start
   if (state == ALLUMAGE && bumper_start.is_on())
    {
        state = STARTMIS;
        Serial.println("# START IN");
    }

    // debut de jeu quand le start est releve
    if (state == STARTMIS && bumper_start.is_off())
    {
        state = GAME ;
        Serial.println("# START OUT");
        timer = millis();
    }

    // fin de partie si t>90s
    if ( (state == END) || (state == GAME && ((millis()-timer) > TEMPS_PARTIE ) ) )
    {

        Serial.println("# ENDGAME");
        state = END;
        io->stop();

        }
    else
        {
        com->run();
        io->run();
        }



   //delay(1);
//*/
/*
    com->run();
    io->run();
    delay(1);
*/
}

