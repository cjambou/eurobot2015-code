#ifndef MISSION_DEPOT_TOUR_DEPART_H
#define MISSION_DEPOT_TOUR_DEPART_H

#include "Coord.h"
#include "Mission.h"

class Mission_Depot_Tour_Depart : public Mission
{
    public:
        Mission_Depot_Tour_Depart(bool mission_a_faire_);
        Mission_Depot_Tour_Depart(bool mission_a_faire_, int nbr_pile_);
        void set_couleur(int couleur_);
        bool is_depot_double();
        void pile_depose();
        bool is_pile_depose();

    private:
        int couleur;
        int nbr_pile;
        bool depot_double;
        bool depot_pile;
        //bool depot_tour_2;

};

#endif // MISSION_DEPOT_TOUR_DEPART_H
