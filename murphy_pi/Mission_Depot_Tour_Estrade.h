#ifndef MISSION_DEPOT_TOUR_ESTRADE_H
#define MISSION_DEPOT_TOUR_ESTRADE_H

#include "Coord.h"
#include "Mission.h"

class Mission_Depot_Tour_Estrade : public Mission
{
    public:
        Mission_Depot_Tour_Estrade(bool mission_a_faire_, int nbr_pile_);
        Mission_Depot_Tour_Estrade(bool mission_a_faire_);
        void set_couleur(int couleur_);
        bool is_depot_double();         // normalement on suit les memes operations ensuite
        bool is_pile_depose();
        void depot_done();

        void activation_depot_double();

    private:
        int couleur;
        int nbr_pile;   // entre 1 et 2 pour savoir si on fait un depot double ou simple
        bool depot_double;
        bool pile_depot;

        //bool depot_simple;
        //bool depot_double;

};

#endif // MISSION_DEPOT_TOUR_ESTRADE_H
