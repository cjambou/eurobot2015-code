#ifndef GESTIONNAIRE_MISSION_H
#define GESTIONNAIRE_MISSION_H

#include "Element_Robot.h"
#include "MAE_MURPHY.h"

#include "Period.h"

#include <iomanip>
#include <locale>
#include <sstream>
#include <string>

#include "Mission_Claps.h"
#include "Mission_Depot_Tour_Depart.h"
#include "Mission_Depot_Tour_Estrade.h"
#include "Mission_Distrib.h"
#include "Mission_Zone_Ennemie.h"
#include "Mission_Zone_centrale.h"
#include "Mission_Chiage_Balle.h"

#define STRAT_0 0
#define STRAT_1 1
#define STRAT_2 2
#define STRAT_3 3

#include <vector>
#include <iterator>
#include <algorithm>

#define MISSION_CLAPS 1
#define MISSION_DISTRIB 2
#define MISSION_CHIAGE_BALLE 3
#define MISSION_ZONE_CENTRALE 4
#define MISSION_TOUR_DEPART 5
#define MISSION_TOUR_ESTRADE 6
#define MISSION_ZONE_ENNEMIE 7

#define DISTANCE_MINI_TO_MISSION 150
using namespace std;

class Gestionnaire_Mission
{
    private:

        Element_Robot element_robot;        // pour savoir ce qu'on a sous la dent

        // mission prioritaire
        Mission_Claps mission_claps;
        Mission_Distrib mission_distrib;
        Mission_Chiage_Balle mission_chiage_balle;
        Mission_Zone_centrale mission_zone_centrale;

        // mission a remplir avant le gong de fin
        Mission_Depot_Tour_Depart mission_depot_tour_depart;
        Mission_Depot_Tour_Estrade mission_depot_tour_estrade;

        // mission apres depot
        Mission_Zone_Ennemie mission_zone_ennemie;

        //Coordonne actuel
        Coord coord_reel;

        float cap_to_mission;
        float x_mission;
        float y_mission;
        float cap_mission;
        int distance_mission;
        bool alignement_to_mission;

        MAE_MURPHY mae_murphy;

        // couleur et temps restant
        int couleur;
        Period period_jeu;
        long temps_restant;

        // pour les trategies
        int strategie_1;
        int strategie_2;
        int mission_sortie_evitement;
        bool sortie_evitement;
        bool premiere_entree_decision;

    public:
        Gestionnaire_Mission();
        void start_compteur_periode();
        int strategie();
        void set_strategie_1(int strat_);
        void set_strategie_2(int strat_);

        void set_coord(Coord coord_reel_);
        Coord get_coord();

        void set_couleur(int couleur_);
        void decision_mission();            // appel de triger sur la mission a realiser
        void affiche_mission_active();

        bool commencement();
        void commencement_end();

        Mission_Claps*                  get_mission_claps();
        Mission_Distrib*                get_mission_distrib();
        Mission_Chiage_Balle*           get_mission_chiage_balle();
        Mission_Zone_centrale*          get_mission_zone_centrale();
        Mission_Depot_Tour_Depart*      get_mission_depot_tour_depart();
        Mission_Depot_Tour_Estrade*     get_mission_depot_tour_estrade();
        Mission_Zone_Ennemie*           get_mission_zone_ennemie();

        Element_Robot* get_element_robot();

        int get_distance_to_mission();
        float get_cap_to_mission();
        float get_x_mission();
        float get_y_mission();
        float get_cap_mission();
        bool is_mission_far();

        string get_cap_to_mission_str();
        string get_x_mission_str();
        string get_y_mission_str();
        string get_cap_mission_str();


        MAE_MURPHY* get_mae_murphy();

        void actualisation_Priorite();
        void actualisation_temps_restant();
        void appel_trigger(int mission_indice_);
        void evitement_mission();                   // pour baisser la priorite de la mission


};

#endif // GESTIONNAIRE_MISSION_H
