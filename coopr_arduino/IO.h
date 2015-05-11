#ifndef IO_H
#define IO_H

#include "Const.h"
#include "pins.h"
#include <Arduino.h>
#include <Utils/Period.h>
#include <Utils/SwitchAnalog.h>
#include "./Utils/SwitchAnalog.h"
#include <Servo.h>
#include "NewPing.h"
#include "I2Cdev.h"
#include "MPU6050.h"

// IMU
// http://www.seeedstudio.com/wiki/Xadow_-_IMU_6DOF
#define SEUIL_IR_ALIGNEMENT 490 //au dessus c que c'est bon
/****************************************************
   IR compteur de roue
*****************************************************/
class IR_compteur
{
    private:
        Period period_run;
        SwitchAnalog IR;
        bool alignement;
        bool vu;
        int compteur;
        bool bavardeur;
        void incremente_compteur();

    public:
        IR_compteur();
        void bavard();
        void muet();
        void run();
        void affiche();
        void reset_compteur();
        int nbr_compteur();
        bool est_aligne();
};




#define PERIODE_CENTRALE 50         // temps d'echantillonage (dt)
#define RAD_TO_DEG_CONV 57.3        // radians to degree conversion
#define FILTER_GAIN 1//0.95            // gain angle = angle_gyro*Filter_gain + angle_accel*(1-Filter_gain)
#define CONSTANTE_G 9.81
/****************************************************
   Centrale inertielle
*****************************************************/
class Centrale_Inertielle
{
    private:
        Period period_centrale;
        MPU6050 accelgyro;
        float angle_x_gyro, angle_y_gyro, angle_z_gyro;
        float angle_x_accel, angle_y_accel, angle_z_accel;
        float angle_x, angle_y, angle_z;
        float force_x_accel, force_y_accel, force_z_accel;
        float vitesse_x_accel, vitesse_y_accel, vitesse_z_accel;
        int16_t ax, ay, az;     // acceleration
        int16_t gx, gy, gz;     // gyration
        int16_t ax_OC, ay_OC, az_OC;     // acceleration
        int16_t gx_OC, gy_OC, gz_OC;     // gyration
        float dt;
        bool bavardeur_gyro;
        bool bavardeur_accelero;

    public:
        Centrale_Inertielle();
        void recalibrage();
        void run();
        float angle_x_out();
        float angle_y_out();
        float angle_z_out();
        float accel_x_out();
        float accel_y_out();
        float accel_z_out();
        void affiche();
        void bavard_gyro();
        void bavard_accelero();
        void muet_gyro();
        void muet_accelero();
        void reset_angle();    // juste avant la monteee, tolerance a 5deg, on va s'incliner de pres de 20deg
        void reset_vitesse();    // juste avant la monteee, tolerance a 5deg, on va s'incliner de pres de 20deg
};


/****************************************************
   SONAR
*****************************************************/
class Sonar
{
    private:
        Period period_sonar;
        NewPing sonar_gauche;//(PIN_PWM_SONAR_G_TRIGGER,PIN_PWM_SONAR_G_Echo,SONAR_DISTANCE_MAX);
        NewPing sonar_droite;//(PIN_PWM_SONAR_D_TRIGGER,PIN_PWM_SONAR_D_Echo,SONAR_DISTANCE_MAX);
        NewPing sonar_face;//(PIN_PWM_SONAR_C_TRIGGER,PIN_PWM_SONAR_C_Echo,SONAR_DISTANCE_MAX);
        unsigned int sonar_distance_droite;
        unsigned int sonar_distance_gauche;
        unsigned int sonar_distance_face;
        bool bavardeur;

    public:
        Sonar();
        void run();
        bool adv_gauche();
        bool adv_droite();
        bool adv_face();
        void affiche();
        void afficheADV();
        void bavard();
        void muet();
};


#define PERIODE_CHENILLE_SECONDAIRE 50

#define STATE_CHENILLE_SECONDAIRE_RANGEE 0
#define STATE_CHENILLE_SECONDAIRE_DEPLOYEMENT 1
#define STATE_CHENILLE_SECONDAIRE_GRIMPE 2
#define STATE_CHENILLE_SECONDAIRE_GRIMPE_TEMPO 3
#define STATE_CHENILLE_SECONDAIRE_FIN_MONTEE 4 // attente
#define STATE_CHENILLE_SECONDAIRE_DEBUT_RANGEMENT 5 // attente


#define TRIGGER_CHENILLE_SECONDAIRE_TIME_OUT 0
#define TRIGGER_CHENILLE_SECONDAIRE_DEPLOYEMENT 1
#define TRIGGER_CHENILLE_SECONDAIRE_GRIMPE 2
#define TRIGGER_CHENILLE_SECONDAIRE_STABILISATION 3 // vers fin de montee quand centrale se stabilise a moins de 5 deg


/****************************************************
   CHENILLE SECONDAIRE
*****************************************************/
class ChenilleSecondaire
{
    private:
        Servo bascule;
        Servo chenille_secondaire;
        //Centrale_Inertielle centrale_Inertielle;   // a integrer proprement
        Period period_run;
        int state;
        bool time_out_on;
        long t_over;
        float angle_tangage;

    public:
        ChenilleSecondaire();
        void run();
        void set_time_out(int dt_);
        void reset_time_out();
        bool is_time_out();
        void in_state_func();
        void trigger(int transition);
        void ON();
        void OFF();
        void position_rangee();
        void position_miHauteur(); // pour preparer le rangement
        void position_auSol();
        //Centrale_Inertielle* get_Centrale_Inertielle();

        // commande haut niveau MAE
        void deployement();
        void grimpe();


};


/****************************************************
   CHENILLE PRINCIPALE
*****************************************************/
// base roulante, slave bis
#define LONGI_GAUCHE_STOP 1485
#define LONGI_GAUCHE_AVANCE 1250
#define LONGI_GAUCHE_RECULE 1700
#define LONGI_DROITE_STOP 1500
#define LONGI_DROITE_AVANCE 1700
#define LONGI_DROITE_RECULE 1300
#define LATERAL_STOP 1500
#define LATERAL_GAUCHE 1000
#define LATERAL_DROITE 2000

// les etats de
#define SLAVE_STATE_REPOS 0
#define SLAVE_STATE_DEPLACEMENT_GAUCHE_ACTION 1
#define SLAVE_STATE_DEPLACEMENT_GAUCHE_ACTION_FINISHING 11
#define SLAVE_STATE_DEPLACEMENT_GAUCHE_PAUSE 2
#define SLAVE_STATE_DEPLACEMENT_DROITE_ACTION 3
#define SLAVE_STATE_DEPLACEMENT_DROITE_ACTION_FINISHING 33
#define SLAVE_STATE_DEPLACEMENT_DROITE_PAUSE 4
#define SLAVE_STATE_DEPLACEMENT_AVANT_ACTION 5
#define SLAVE_STATE_DEPLACEMENT_AVANT_PAUSE 6
#define SLAVE_STATE_DEPLACEMENT_ARRIERE_ACTION 7
#define SLAVE_STATE_DEPLACEMENT_ARRIIERE_PAUSE 8

// les declencheurs
#define SLAVE_TRIGGER_TIME_OUT 0
#define SLAVE_TRIGGER_LATERAL_GAUCHE 1
#define SLAVE_TRIGGER_LATERAL_DROITE 3
#define SLAVE_TRIGGER_LONGITUDINAL_AVANT 4
#define SLAVE_TRIGGER_LONGITUDINAL_ARRIERE 5
#define SLAVE_TRIGGER_PAUSE 6
#define SLAVE_TRIGGER_REPRISE 7

#define SLAVE_TRIGGER_BUMP_GAUCHE 8
#define SLAVE_TRIGGER_BUMP_DROITE 9
#define SLAVE_TRIGGER_BUMP_FACE 10
#define SLAVE_TRIGGER_STOP 11
#define SLAVE_TRIGGER_TOUR_ROUE_FINISH 12
#define SLAVE_TRIGGER_TOUR_ROUE_ATTEINT 13

class ChenillePrincipale
{
    private:
        //pour commande des moteurs
        Servo chenille_laterale;
        Servo chenille_gauche;
        Servo chenille_droite;
        //rampe IR avant
		//SwitchAnalog val_ir_bas;
        //SwitchAnalog val_ir_haut;
        //rampe avant
        SwitchAnalog bumper_av_g;
        SwitchAnalog bumper_av_d;
        //rampe gauche
        SwitchAnalog bumper_g_av;
        SwitchAnalog bumper_g_ar;
        //rampe droite
        SwitchAnalog bumper_d_av;
        SwitchAnalog bumper_d_ar;
        // sonar (pour l'evitement)

        bool bavardeur_bumper;

        Sonar sonar;

        IR_compteur ir_compteur_lat;

        // penser a mettre un timer
        bool assFini;
        bool pause;

        // gestion des temps
        Period period_run;
        long time_asserv_started;
        long time_asserv_to_do;         // temps d'asserv pour l'asser en cours
        long time_asserv_remaining;     // temps restant si interruption par l'evitement, rajouter un dela temps
        long time_delta_time_after_interrupt;

        //gestion des tours de roue, en lateral
        int tour_a_faire;
        int tour_effectuee;

        // pour MAE
        int state;
        bool time_out_on;
        long t_over;
        bool evitement_actif;       // pour savoir si on consulte les sonar ou pas
        bool interruption_par_evitement;

    public:
        ChenillePrincipale();

        void stop();

        void alignementLaterale();

        // activation ou pas de l'evitement, intervient dans le run
        void set_evitement_ON();
        void set_evitement_OFF();

        // briques de base : mouvement basique
        void longi_gauche_stop();
        void longi_gauche_avance();
        void longi_gauche_recule();
        void longi_droite_stop();
        void longi_droite_avance();
        void longi_droite_recule();
        void lateral_gauche();
        void lateral_droite();
        void lateral_stop();
        void arret();            // arret des chaines


        // trigger MAE, ordre haut niveau
        void recalage_gauche();
        void recalage_droite();
        void recalage_face(); //tak droite et gauche, mettre un timer de sortie

        // evitement a integrer (sur base de sonar)
        void decalage_droite(int tour_de_roue);
        void decalage_gauche(int tour_de_roue); // mettre un timer
        void decalage_avant(long tempsTotAction);
        void decalage_arriere(long tempsTotAction);

        // a faire si temps.... j'en doute :\
        void rotation(double tempsTotAction); //couplage avec IMU???

        // mise en place escalier
        void stop_asserv();  //sort de l'asserv en cours, si pausee
        void pause_asserv(); //pause de l'asserv en cours (timer)
        void reprise(); //reprise de l'asserv en cours, si existe
        void run();
        void set_time_out(int dt_);
        void reset_time_out();
        bool is_time_out();
        void in_state_func();
        void trigger(int transition);

        // chaine secondaire
        void chenilleSecondaire_ON();
        void chenilleSecondaire_OFF();

        Sonar* get_Sonar();
        IR_compteur* get_IR_compteur();
        void debug_bumper_muet();
        void debug_bumper_bavard();
        void affiche_bumper();
};




/****************************************************
   TURBINE
*****************************************************/
class Turbine
{
    private:
        Servo turbine;

    public:
        Turbine();
        void ON();
        void OFF();
};

/****************************************************
   NOZZLE
*****************************************************/
class Nozzle
{
    private:
        Servo nozzle;

    public:
        Nozzle();
        void haut();
        void middle();
        void bas();
};

/****************************************************
   PINCE
*****************************************************/
// pince porte tapis rouge
class Pince
{
    private:
        bool cote_droit; // constante differente true droit, false gauche
        Servo garde;
		Servo bras;

        int val_target;
        int val_temporaire;
		int val_initiale;

    public:
        Pince(bool cote_droit);
        void haut();
        void middle();
        void bas();
        void pince_ON();
        void pince_OFF();

        void set_target(int target);    // haut, milieu, bas
        void incrementation();
        bool is_cmd_finie();
        void send_command();

};


/****************************************************
   DEPOSEUR DE TAPIS
*****************************************************/
// deposeur de tapis, ici c'est une MAE
// ne pas oublier de mettre les differents etats
#define ETAT_TAPIS_INIT 0
#define ETAT_TAPIS_AT 1
#define ETAT_TAPIS_DF_1 2
#define ETAT_TAPIS_DF_2 3
#define ETAT_TAPIS_DF_3 4
#define ETAT_TAPIS_DFP_1 5
#define ETAT_TAPIS_DFP_2 6
#define ETAT_TAPIS_RF_1 7
#define ETAT_TAPIS_RF_2 8
#define ETAT_TAPIS_DS_1 9
#define ETAT_TAPIS_DS_2 10
#define ETAT_TAPIS_DS_3 11
#define ETAT_TAPIS_DSP_1 12
#define ETAT_TAPIS_DSP_2 13
#define ETAT_TAPIS_RS_1 14
#define ETAT_TAPIS_RS_2 15
#define ETAT_TAPIS_RS_3 16

#define TRANS_TAPIS_TIME_OUT 0
#define TRANS_TAPIS_POSE_FIRST 1
#define TRANS_TAPIS_REPLI_FIRST 2
#define TRANS_TAPIS_POSE_SECOND 3
#define TRANS_TAPIS_REPLI_SECOND 4
#define TRANS_TAPIS_FIN_ASSERV 5

class DeposeurTapis
{
    private:
        Turbine turbine;
		Nozzle nozzle;
		Pince pince_droite;
		Pince pince_gauche;
		bool time_out_on;
		int state;
        long t_over;
        Period period_run;

    public:
        // MAE depose tapis
        DeposeurTapis();
        void run();
        void stop();
        void trigger(int transition);
        //void set_time_out(int dt_, int trigger);
        void reset_time_out();
        bool is_time_out();

        void depose_first(); //depose une fois en position
        void replis_first();
        void depose_second();
        void replis_second();
        void in_state_func();
        void set_time_out(int dt_);


};



/****************************************************
   IO
*****************************************************/
class IO
{
    private:
        DeposeurTapis deposeurTapis;
        ChenilleSecondaire chenilleSecondaire;
        ChenillePrincipale chenillePrincipale;
        //Centrale_Inertielle centrale;

    public:
        IO();
        void run();
        void stop();
        DeposeurTapis* get_DeposeurTapis();
        ChenilleSecondaire* get_ChenilleSecondaire();
        ChenillePrincipale* get_ChenillePrincipale();
        //Centrale_Inertielle* get_Centrale_Inertielle();
        void monte_escalier();

};





#endif
