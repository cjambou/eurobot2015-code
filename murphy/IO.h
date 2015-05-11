#ifndef IO_H
#define IO_H

#include "Utils/Period.h"
#include "Arduino.h"
#include <Servo.h>
#include "interrupts.h"
#include "pins.h"
#include "Const.h"
#include "Utils/Switch.h"
#include "Utils/SwitchAnalog.h"
//#include "ColorSensor.h"


#define TIC_HAUT 100
#define TIC_BAS 0

/****************************************************
   ELEVATOR GOBELET
*****************************************************/
class Elevator_Gobelet
{
    private:
        Servo servo_elevator_gauche;
        Servo servo_elevator_droite;

    public:
        Elevator_Gobelet();
        void lache();
        void souleve();
};



/****************************************************
   CLAPS
*****************************************************/
class Claps
{
    private:
        bool cote_droit;
        Servo servo_tacle;

    public:
        Claps(bool cote_droit_s);
        void ouverture();
        void fermeture();
};

/****************************************************
   Aspiration balle
*****************************************************/
class Aspiration
{
    private:
        Servo servo_turbine_gauche;
        Servo servo_turbine_droite;

    public:
        Aspiration();
        void on();
        void off();
};

/****************************************************
   CAPOT Arriere
*****************************************************/
class Capot
{
    private:
        Servo servo_capot;

    public:
        Capot();
        void fermeture();
        void ouverture_balle();
        void ouverture_gobelet();
};

/****************************************************
   CAMERA
*****************************************************/
class Camera
{
    private:
        Servo servo_camera;

    public:
        Camera();
        void position_devant();
        void position_basse();
};


/****************************************************
   Taclette INT
*****************************************************/
class Taclette_INT
{
    private:
        bool cote_droit;
        Servo servo_taclette_INT;

    public:
        Taclette_INT(bool cote_droit_s);
        void position_fermeture();
        void position_degagement();
        void position_prise_central();
};


/****************************************************
   Taclette EXT
*****************************************************/
class Taclette_EXT
{
    private:
        bool cote_droit;
        Servo servo_taclette_EXT;

    public:
        Taclette_EXT(bool cote_droit_s);
        void position_fermeture();
        void position_degagement();
        void position_moiss_bat();
};


/****************************************************
   Balle Gauche
*****************************************************/
class Balle_gauche
{
    private:
        Servo servo_balle_gauche;

    public:
        Balle_gauche();
        void chargement();
        void ejection();
};



/****************************************************
   ejcteur
*****************************************************/
class Ejecteur
{
    private:
        Servo servo_ejecteur;
    public:
        Ejecteur();
        void position_basse();
        void position_middle();
        void position_haute();
};


/****************************************************
   bras horizontal
*****************************************************/
class Bras_horizontal
{
    private:
        Servo servo_bras_horizontal;
    public:
        Bras_horizontal();
        void ouverture();
        void fermeture();
};

/****************************************************
   bras vertical
*****************************************************/
class Bras_vertical
{
    private:
        Servo servo_bras_vertical;
        int val_initiale;
    public:
        Bras_vertical();
        void monte();
        void descend();
        bool is_montee_atteinte();  // renvoi si le pwm cible est atteint
        void incremente(int val);   // incremente la valeur
        void send_commande();       // ecrit le pwm sur le servos
};





/****************************************************
   Balle Droite (MAE, sequencage de mouvement)
*****************************************************/
// STATES OF MAE
#define ETAT_BALLE_DROITE_RANGE_DEPART 0
#define ETAT_BALLE_DROITE_DEPLOYEMENT 1 //horizontal et gachette
#define ETAT_BALLE_DROITE_PRISE 2 //descente
#define ETAT_BALLE_DROITE_RELEVE 3 //remonte
#define ETAT_BALLE_DROITE_RANGE_1 4 //horintal
#define ETAT_BALLE_DROITE_RANGE_2 5 //gachette
#define ETAT_BALLE_DROITE_EXPULSION 6 //horizontal

//transition
#define TRANSISTION_BALLE_DROITE_TIME_OUT 0
#define TRANSISTION_BALLE_DROITE_PRISE 1
#define TRANSISTION_BALLE_DROITE_EJECTION 2
#define TRANSISTION_BALLE_DROITE_FIN_MONTEE 3


class Balle_droite
{
    private:
        Bras_vertical bras_vertical;
        Bras_horizontal bras_horizontal;
        Ejecteur ejecteur;
        long t_over;
        bool time_out_on;
        //int trigger_to_be;
        int state;
        Period period_run;
        bool balle_charge;

    public:
        Balle_droite();
        void run();
        bool est_chargee();
        void in_state_func();
        void trigger(int transition);
        void set_time_out(int dt_);
        void reset_time_out();
        bool is_time_out();
        int actualState();
        void debug();
};


/****************************************************
   Pince
*****************************************************/
class Pinceur
{
    private:
        Servo servo_pinceur;
        bool cote_droit;
    public:
        Pinceur(bool cote_droit_s);
        void deployement_total();   // depot des tours
        void saisie();              // pince la tour pour maintient
        void relachement();         // relachement pour prise en dessous
};

/****************************************************
   Ascenseur
*****************************************************/
class Ascenseur
{
    private:
        Servo servos_moteur_asc;
        Switch bumper_asc_bas;
        Switch bumper_asc_haut;
        bool in_asserv;
        int target;
        bool cote_droit;
        bool asserv_fini;

    public:
        Ascenseur(bool cote_droit_s,int pin_bas,int pin_haut);
        bool is_assFini();
        bool is_up();
        bool is_low();
        void start_asserv(int target_);
        void monte(); //A1
        void descend(); //A0
        void estrade();
        void run();
        void send_monte();
        void send_maintien_p();  // maintient asserv ou stop
        void send_zeros();
        void send_desc();
        void write_debug(); // renvoyer les coordonnees des odos pour debug
        void resest_odo(); // reinit les odos
        void stop();
        void debug();
        bool is_asserv_fini_ext();
        void reset_asserv_fini_ext();
};


/****************************************************
   Capteur couleur
*****************************************************/
class ColorSensor
{
    private:
        Period period_reset;
        float last_count;
        long last_time;
        bool cote_droit;
    public:
        ColorSensor(bool cote_droit_s);
        bool is_jaune();
        bool is_vert();
        void run();
        void write_debug();
};

// transistion d'etats
#define TRANS_ASPIRATION_TIME_OUT 0
#define TRANS_ASPIRATION_DEBOIT_DISTRIB 1
#define TRANS_ASPIRATION_CLAPS_DROITE 2
#define TRANS_ASPIRATION_CLAPS_GAUCHE 3

//etats
#define ETAT_ASPIRATION_INITIAL 0
#define ETAT_ASPIRATION_TAPE_GAUCHE 1
#define ETAT_ASPIRATION_TAPE_DROITE 2
#define ETAT_ASPIRATION_DEBUT_ASPI 3
#define ETAT_ASPIRATION_SORTIE_BRAS_DROITE 4
#define ETAT_ASPIRATION_RENTRE_BRAS_DROITE 5
#define ETAT_ASPIRATION_SORTIE_BRAS_GAUCHE 6
#define ETAT_ASPIRATION_RENTRE_BRAS_GAUCHE 7
#define ETAT_ASPIRATION_FIN_ASPI 8
/****************************************************
   ASPIRATION_BRAS
*****************************************************/
class Aspiration_Bras
{
    private:
        Period period_run;
        long t_over;
        bool time_out_on;
        int state;
        Claps clap_gauche;
        Claps clap_droite;
        Aspiration aspiration;

    public:
        Aspiration_Bras();
        void run();
        void in_state_func();
        void trigger(int transition);
        void set_time_out(int dt_);
        void reset_time_out();
        bool is_time_out();
        int actualState();

        void tacle_droite();
        void tacle_gauche();
        void deboit_le_distrib();

};





/****************************************************
   Constructeur de pile
*****************************************************/
//#define PERIODE_CONSTRUCTEUR_PILE 500


// transistion d'etats
#define TRANS_PILE_TIME_OUT 0
#define TRANS_PILE_PREP_SAISIE 1
#define TRANS_PILE_FERMETURE 2
#define TRANS_PILE_SAISIE_MANUELLE 3
#define TRANS_PILE_PREP_DEPOT 4
#define TRANS_PILE_POSE 5
#define TRANS_PILE_REPLIS 6
#define TRANS_PILE_ASSERV_FINI 7

//etats
#define ETAT_PILE_INITIAL 0
#define ETAT_PILE_PREP_SAISIE 1
#define ETAT_PILE_PRISE 2
#define ETAT_PILE_PRISE_SEC 222
#define ETAT_PILE_ANALYSE 3
#define ETAT_PILE_DECISION_MOVE 4
#define ETAT_PILE_RELACHEMENT 5
#define ETAT_PILE_RELAXATION 6
#define ETAT_PILE_DESCENTE 7
#define ETAT_PILE_SAISIE_PINCE 8
#define ETAT_PILE_SAISIE_MONTE 9
#define ETAT_PILE_SAISIE_FIN 10

#define ETAT_PILE_DEPOT_DECISION 11
#define ETAT_PILE_DEPOT_FULL_INIT 12
#define ETAT_PILE_DEPOT_FULL_H_PREP_1 13
#define ETAT_PILE_DEPOT_FULL_H_PREP_2 14
#define ETAT_PILE_DEPOT_FULL_H_PREP_3 15
#define ETAT_PILE_DEPOT_FULL_H_PREP_4 16
#define ETAT_PILE_DEPOT_FULL_H_PRET 17
#define ETAT_PILE_DEPOT_FULL_H_POSE 18
#define ETAT_PILE_DEPOT_FULL_REPLIS_1 19
#define ETAT_PILE_DEPOT_FULL_REPLIS_2 20
#define ETAT_PILE_DEPOT_INF_PREP_1 21
#define ETAT_PILE_DEPOT_INF_PREP_2 22

#define SEUIL_IR_BAS 400

class Constructeur_pile
{
    private:
        bool cote_droit;
        Pinceur pinceur;
        Ascenseur ascenseur;
        Taclette_EXT taclette_EXT;
        Taclette_INT taclette_INT;
        ColorSensor colorSensor;

        SwitchAnalog ir_bas_pince;

        Period period_run;

        //switchAnalog a mettre centre, bas et latBas

        int nombre_element;
        int couleur; // jaune 0, vert 1

        bool actif_couleur; //verification de la couleur lors de la chope auto/manuel
        bool actif_detection; //

        long t_over;
        bool time_out_on;
        int state;

        bool depot_estrade;

    public:
        Constructeur_pile(bool cote_droit_s,int pin_bas,int pin_haut, int pin_ir_bas);
        void definition_couleur(int couleur_s);
        void run();
        void in_state_func();
        void trigger(int transition);
        void set_time_out(int dt_);
        void reset_time_out();
        bool is_time_out();
        int actualState();
        void debug();
        void set_depot_estrade(bool etat);
        void set_actif_couleur(bool etat);
        void set_actif_detection(bool etat);
        int get_nombre_element();
};




/****************************************************
   IO
*****************************************************/
#define NOMBRE_MIN_STAND_AVANT_INJECTION 3
class IO
{
    private:
        Aspiration_Bras aspiration_bras;
        Elevator_Gobelet elevator_gobelet;
        Balle_droite balle_droite;
        Balle_gauche balle_gauche;
        //Claps clap_gauche;
        //Claps clap_droite;
        Constructeur_pile constructeur_pile_gauche;
        Constructeur_pile constructeur_pile_droite;
        Camera camera;
        Capot capot;
        //Aspiration aspiration;
        bool couleur_jaune; // couleur de jeux, jaune ou vert, pour detection
        int nombre_element_pile_gauche;
        int nombre_element_pile_droite;
        bool to_be_ejected_gauche;
        bool to_be_ejected_droite;


    public:
        IO();
        void write_debug();
        void run();
        void balle_droite_trigger(int transition);
        Elevator_Gobelet* get_Elevator_gobelet();
        //Claps* get_Claps_droite();
        //Claps* get_Claps_gauche();
        Constructeur_pile* get_Constructeur_pile_gauche();
        Constructeur_pile* get_Constructeur_pile_droite();
        Camera* get_Camera();
        Capot* get_Capot();
        Aspiration_Bras* get_Aspiration_Bras();
        Balle_droite* get_Balle_droite();
        Balle_gauche* get_Balle_gauche();
};

#endif
