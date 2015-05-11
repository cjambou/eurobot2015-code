#ifndef MISSION_ZONE_ENNEMIE_H
#define MISSION_ZONE_ENNEMIE_H

#include "Coord.h"
#include "Mission.h"

class Mission_Zone_Ennemie : public Mission
{
    public:
        Mission_Zone_Ennemie(bool mission_a_faire_);
        void set_couleur(int couleur_);

        void claps_done();
        void depot_gobelet_done();

        bool is_claps_done();
        bool is_depot_gobelet_done();

        int mode_chieur();
        void mode_chieur_plus();
        void mode_chieur_faible();
        void mode_chieur_stop();


    private:
        int couleur;
        bool claps;
        bool depot_gobelet;
        int chieur;

};

#endif // MISSION_ZONE_ENNEMIE_H
