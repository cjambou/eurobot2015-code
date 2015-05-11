#ifndef MISSION_DISTRIB_H
#define MISSION_DISTRIB_H

#include "Coord.h"
#include "Mission.h"

class Mission_Distrib : public Mission
{
    public:
        Mission_Distrib(bool mission_a_faire_);
        void set_couleur(int couleur_);

        void netoyage_zone_done();
        bool is_netoyage_zone_done();

        void capture_gobelet_done();
        bool is_capture_gobelet_done();

    private:
        int couleur;
        bool vidange_zone;
        bool gobelet_escalier;




};

#endif // MISSION_DISTRIB_H
