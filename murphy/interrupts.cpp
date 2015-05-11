#include "interrupts.h"
#include "pins.h"

//tics interrupt functions
//
//

//-> ok for PMI
long ticG = 0;
long ticD = 0;

long ticG_ASC = 0;
long ticD_ASC = 0;

long ticG2 = 0;
long ticD2 = 0;




// increment odo PROPU DROITE
void inc_ticG(){
    int chb;
    chb = digitalRead(PIN_ODO_PROPU_GAUCHE_B_DIR);

    if (chb != 1)
    {
        ticG = ticG + 1;
        ticG2 = ticG2 + 1;
    }
    else
    {
        ticG = ticG - 1;
        ticG2 = ticG2 - 1;
    }
    //Serial.print("tic G : ");
    //Serial.println(ticG);
}

// increment odo PROPU Gauche
void inc_ticD(){

    int chb = digitalRead(PIN_ODO_PROPU_DROITE_B_DIR) ;
    if (chb != 1)
    {
        ticD = ticD - 1;
        ticD2 = ticD2 - 1;
    }
    else
    {
        ticD = ticD + 1;
        ticD2 = ticD2 + 1;
    }
    //Serial.print("tic D : ");
    //Serial.println(ticD);
}

//#endif

// increment odo ASC Gauche
void inc_ticG_ASC(){
    int chb;
    chb = digitalRead(PIN_ODO_ASC_GAUCHE_B_DIR);
    if (chb != 1)
    {
        ticG_ASC = ticG_ASC + 1;
    }
    else
    {
        ticG_ASC = ticG_ASC - 1;
    }
}


// increment odo ASC Droite
void inc_ticD_ASC(){
    int chb;
    chb = digitalRead(PIN_ODO_ASC_DROITE_B_DIR);
    if (chb != 1)
    {
        ticD_ASC = ticD_ASC - 1;
    }
    else
    {
        ticD_ASC = ticD_ASC + 1;
    }
}


long pulse_color_D = 0;
long pulse_color_G = 0;

 /*
 interruption capteur couleur
 */
void inc_pulse_color_G() {
  // increase pulse count
    pulse_color_G = pulse_color_G + 1;
 }


void inc_pulse_color_D() {
  // increase pulse count
    pulse_color_G = pulse_color_G + 1;
 }
