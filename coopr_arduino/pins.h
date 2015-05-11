#ifndef PINS_H
#define PINS_H

/*
DEFINITION DES PINS SUR ARDUINO  (IO COOP'R)
COOP'R
*/


// bumpers recalage gauche
#define PIN_BUMPER_RECALAGE_AV_G A8
#define PIN_BUMPER_RECALAGE_G_AV A6
#define PIN_BUMPER_RECALAGE_G_AR A10

// bumpers recalage droite
#define PIN_BUMPER_RECALAGE_AV_D A9
#define PIN_BUMPER_RECALAGE_D_AV A7
#define PIN_BUMPER_RECALAGE_D_AR A11

// bumpers strat
#define PIN_BUMPER_STRAT_START A5
#define PIN_BUMPER_STRAT_COULEUR A4
#define PIN_BUMPER_STRAT_STRAT A3

// sonar gauche
#define PIN_PWM_SONAR_G_Echo 44
#define PIN_PWM_SONAR_G_TRIGGER 13

// sonar droit
#define PIN_PWM_SONAR_D_Echo 48
#define PIN_PWM_SONAR_D_TRIGGER 47

// sonar centre
#define PIN_PWM_SONAR_C_Echo 46
#define PIN_PWM_SONAR_C_TRIGGER 45

// Capteur IR Haut
#define PIN_IR_HAUT A12
#define PIN_IR_BAS A13

// Moteur
#define PIN_PWM_MOTEUR_CHENILLE_D 3
#define PIN_PWM_MOTEUR_CHENILLE_G 2
#define PIN_PWM_MOTEUR_CHENILLE_LATERALE 5
#define PIN_PWM_MOTEUR_CHENILLE_SECONDAIRE 6


#define MOT_B_EN 2
#define MOT_A_EN 3
#define MOT_B_I1 17
#define MOT_B_I2 16
#define MOT_A_I1 19
#define MOT_A_I2 18



// IMU
// declaration a mettre

//Servos
#define PIN_PWM_SERVO_BRAS_G 7
#define PIN_PWM_SERVO_BRAS_D 8
#define PIN_PWM_SERVO_GARDE_G 9
#define PIN_PWM_SERVO_GARDE_D 10
#define PIN_PWM_SERVO_TURBINE 11
#define PIN_PWM_SERVO_NOZZLE 12
#define PIN_PWM_SERVO_BASCULE 4



#endif
