#ifndef INTERRUPTS_H
#define INTERRUPTS_H
// coucou on change rien
#include "Arduino.h"
#include "pins.h"

//variables globales

extern long ticG;
extern long ticD;
extern long ticG2;
extern long ticD2;

extern void inc_ticG();
extern void inc_ticD();

extern long ticG_ASC;
extern long ticD_ASC;
extern void inc_ticG_ASC();
extern void inc_ticD_ASC();

extern long pulse_color_G;
extern long pulse_color_D;
extern void inc_pulse_color_G();
extern void inc_pulse_color_D();

#endif
