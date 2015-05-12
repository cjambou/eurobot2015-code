#ifndef CONTROL_H
#define CONTROL_H

#include "Utils/Coord.h"
#include "Utils/Sonar.h"
#include "Utils/PID.h"
#include "pins.h"
#include "Const.h"



// type of BF
#define STOP 0
#define BFFW 1
#define BFCAP 2
#define BFXYCAP 3

// type of speed
#define SLOW 0
#define MEDIUM 1
#define FAST 2

// gain PID deplacement
#define GAIN_KP_DEP 1.5
#define GAIN_KI_DEP 0.00
#define GAIN_KD_DEP 0.00

// gain PID deplacement en FAST
#define GAIN_KP_DEP_FAST 15.6
#define GAIN_KI_DEP_FAST 44.0
#define GAIN_KD_DEP_FAST 1.36
#define GAIN_KP_CAP_FAST 2100.  //Ku = 3500
#define GAIN_KI_CAP_FAST 4200. //52.0 //70.0
#define GAIN_KD_CAP_FAST 300.0 //18.0 //40.0

// gain PID deplacement en medium
#define GAIN_KP_DEP_MEDIUM 15.6
#define GAIN_KI_DEP_MEDIUM 44.0
#define GAIN_KD_DEP_MEDIUM 1.36
#define GAIN_KP_CAP_MEDIUM 2100.  //Ku = 3500
#define GAIN_KI_CAP_MEDIUM 4200. //52.0 //70.0
#define GAIN_KD_CAP_MEDIUM 262.5 //18.0 //40.0

// gain PID deplacement en slow
#define GAIN_KP_DEP_SLOW 15.6
#define GAIN_KI_DEP_SLOW 44.0
#define GAIN_KD_DEP_SLOW 1.36
#define GAIN_KP_CAP_SLOW 2100.  //Ku = 3500
#define GAIN_KI_CAP_SLOW 4200. //52.0 //70.0
#define GAIN_KD_CAP_SLOW 262.5 //18.0 //40.0


// norme sur les etats de transistion proche  et fini
#define NEAR_ERROR_DEP 200//1//200
#define DONE_ERROR_DEP 100//0//150  //

// gain PID cap (rotation)
#define GAIN_KP_CAP 200  //Ku = 260
#define GAIN_KI_CAP 0 //52.0 //70.0
#define GAIN_KD_CAP 0 //18.0 //40.0

#define NEAR_ERROR_CAP 8.0 * 3.14 / 180.0
#define DONE_ERROR_CAP  4.0 * 3.14 / 180.0

// compteur blocage
#define BLOCAGE_MAX 20

//VITESSE
#define MIN_MAX_SLOW 200
#define MIN_MAX_MEDIUM 300 // A TESTER
#define MIN_MAX_FAST 400  // idem //don't use it too fast


class ControlLoop
/* This class gets the updated coordinate, and talk to the 2 PID
 * loops to tell the robot where to go.
 * This class also talk to the Raspberry Pi to say when the movement is finished*/
{
    private:
        Coord real_coord;           // coordonne actuelle
        Coord target_position;      // coordonne cible
        Vector dir;                 // vecteur de direction a suivre entre le point actuel et la cible (provisoire ou finale)
        bool detect_on;             // activation de la detection d'adversaire
        int bf_type;                // type de BF en cours
        int asserv_state;           // etat PID -> FAR, NEAR
        PID pidcap;                 // PID cap
        PID piddep;                 // PID deplacement
        int cmd_g;                  // commande sur roue gauche
        int cmd_d;                  // commande sur roue droite
        int cmd_dep;                // commande deplacement
        int cmd_cap;                // commance cap
        bool fw_g;                  // avance roue gauche
        bool fw_d;                  // avance roue droite
        int count_not_moving;       // Compteur de blocage
        Coord late_pos;             // to check how much we moved lately
        Sonar sonarg;               // Sonar cote droit
        Sonar sonard;               // Sonar cote gauche

    public:
        ControlLoop();
        void bf_avance(float d);
        void set_target(Coord coord);
        void update_error(Coord coord);
        int get_cmd_g();
        bool get_fw_g();
        int get_cmd_d();
        bool get_fw_d();
        void run(Coord real_coord_);
        void compute_pids();
        void compute_cmds();
        void set_BF(int bf_type_, Coord target_position_);
        void next_asserv_state();
        void check_blockage();
        void check_adversary();
        void setxycap(Coord new_coord);
        void write_real_coords();
        void write_debug();
        void set_speed(int speed);
        void recaler();
        void setTuningCap(float Kp, float Ki, float Kd );
        void setTuningDep(float Kp, float Ki, float Kd );
        void turn_on_evit();
        void turn_off_evit();
        Sonar* get_sonar_d();
        Sonar* get_sonar_g();

};



#endif
