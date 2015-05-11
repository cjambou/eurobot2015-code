#ifndef AUTOM_H
#define AUTOM_H


#include "Utils/Period.h"
#include "Arduino.h"
#include "interrupts.h"
#include "pins.h"
#include "Utils/Coord.h"
#include "ControlLoop.h"
#include <Servo.h>

// GAIN du slave
#define GAIN_ODO_G 0.340045058//0.377287304 //0.325998//0.338409475
#define GAIN_ODO_D 0.339614681//0.379146919 //0.338925//0.337609723
#define GAIN_ODO_inter 0.005537522 //0.004987


// moteur
#define MOTEUR_PROPU_DROIT_ARRET 1516
#define MOTEUR_PROPU_DROIT_MAX_AVANT 2000
#define MOTEUR_PROPU_DROIT_MAX_ARRIERE 1000

#define MOTEUR_PROPU_GAUCHE_ARRET 1516
#define MOTEUR_PROPU_GAUCHE_MAX_AVANT 2000
#define MOTEUR_PROPU_GAUCHE_MAX_ARRIERE 1000

class Autom
{
    private:
        Coord real_coord;               // coordonnee reelles
        ControlLoop control;            // boucle de controle (PID et tout...)
        Period period_update_coords;    // periode de refreh position du robot
        Period period_pid_loop;         // periode de refreh autom
        Period period_sonar;
        float gain_odo_g;               // gain odo gauche
        float gain_odo_d;               // gain odo droit
        float gain_inter_odos;          // gain inter odo
        int last_ticG;                  // dernier tic odo gauche
        int last_ticD;                  // dernier tic odo droite
        Servo moteur_gauche;            // commande PWM moteur gauche
        Servo moteur_droit;             // commande PWM moteur droit

        // pour debugg
        int tic_total_g;                // tic total gauche
        int tic_total_d;                // tic total droit
        float distance_g;               // distance prcourue a gauche
        float distance_d;               // distance prcourue a droite
        bool bavardeur_sonar;

    public:
        Autom();
        Coord get_real_coord();
        void send_cmd();
        void write_cmd(int cmd_g, int cmd_d, bool fw_g, bool fw_d);
        void update_cap();
        void update_coords();
        void reset_tics_odos();

        void run();
        void stop();

        void setxycap(Coord real_coord);
        void setxycap_no_x(int y, float cap);
        void setxycap_no_y(int x, float cap);
        void setTuningCap(float Kp, float Ki, float Kd );
        void setTuningDep(float Kp, float Ki, float Kd );
        void turn_on_evit();
        void turn_off_evit();

        ControlLoop* get_control();

        float debuggDistance_g();
		float debuggDistance_d();
		int debuggTic_g();
		int debuggTic_d();
		void debuggDistanceInit();
		void debuggTicInit();
		void bavardeur_sonar_on();
		void bavardeur_sonar_off();

};

void write_serial_strat();
#endif
