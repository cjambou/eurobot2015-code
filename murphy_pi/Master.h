#ifndef MASTER_H
#define MASTER_H
#include "Period.h"
#include "MAE_MURPHY.h"
#include "Gestionnaire_Mission.h"
#include <wiringPi.h>

#define PERIODE_MASTER 50

#define STRAT_NOMINALE 0
#define STRAT_CHIANTE 1

#define COULEUR_JAUNE 0
#define COULEUR_VERT 1






class Master
{
    private:
        //static Master masterInstance;
        // attribut
        long t_over;
        bool time_out_on;
        Period periode_run;

        int couleur;
        int cycle_attente;
        int portSerie;


        Gestionnaire_Mission gestionnaire_mission;



    public:

        // méthodes
        Master(int portSerie_);
        //static Master* getInstance{ return &masterInstance;}

        // gestion du temps de la MAE
        int getPortSerie();
        void run();
        void set_time_out(int dt_);     // besoin d'avoir acces de l'exterieur, pour mettre les tempos
        void reset_time_out();
        bool is_time_out();

        // couleur
        void set_couleur(int couleur_);     // fixe la couleur, appel depuis la COM

        MAE_MURPHY* get_MAE_MURPHY();       // retourne la MAE, util? je sais pas, si pour la com
        Gestionnaire_Mission* get_gestionnaire_mission();
        Gestionnaire_Mission* get_gestionnaire();

        int get_Couleur();                  // couleur pour la strat
        bool is_Vert();                     // couleur pour la strat
        bool is_Jaune();                    // couleur pour la strat

};

extern Master * master;

#endif // MASTER_H
