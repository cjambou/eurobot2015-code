#ifndef MISSION_H
#define MISSION_H


#define STATUS_MISSION_FAITE 0
#define STATUS_MISSION_A_FAIRE 1
#include <iostream>
#include "Coord.h"
using namespace std;


#define PRIORITE_MISSION_FAIBLE 0
#define PRIORITE_MISSION_MOYENNE 1
#define PRIORITE_MISSION_HAUTE 2
#define PRIORITE_MISSION_FIRST 3

class Mission
{
    public:
        Mission(bool mission_a_faire_, int nbr_pts_, Coord coord_debut_mission_, string title_);

        // pour savoir le statu de la mission
        bool is_accomplie();
        void mission_remplie();

        // gestion du point de depart de la mission
        Coord get_coord_debut_mission(); //attention a la couleur, inverser les X et les angles
        void set_coord_debut_mission(Coord coord_debut_mission_);
        float distance_to_mission(Coord coord_reel);

        // le nombre de pts de la mission pour savoir si ça aut le coup d'y aller
        int point_restant();
        void set_nbr_pts(int pts_);

        void affiche();
        string get_title();

        void set_priorite(int priorite_);
        int get_priorite();


    protected:
        Coord coord_debut_mission;
        int status;         // statu de la mission
        int nbr_pts;
        bool mission_faite;
        string title;

        int priorite;

};

#endif // MISSION_H
