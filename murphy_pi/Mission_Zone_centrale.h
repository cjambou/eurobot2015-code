#ifndef MISSION_ZONE_CENTRALE_H
#define MISSION_ZONE_CENTRALE_H

#include "Coord.h"
#include "Mission.h"

class Mission_Zone_centrale : public Mission
{
    public:
        Mission_Zone_centrale(bool mission_a_faire_);
        void set_couleur(int couleur_);

        void catch_stand_central();
        bool is_stand_central_catched();

        void catch_stand_estrade();
        bool is_stand_estrade_catched();

        void catch_stand_depart();
        bool is_stand_depart_catched();

        void activation_rush_salace();
        bool is_rush_salace_on();
        void desactivation_rush_salace();

    private:
        int couleur;
        bool stand_central;
        bool stand_estrade;
        bool stand_depart;

        bool rush_salace;

};

#endif // MISSION_ZONE_CENTRALE_H
