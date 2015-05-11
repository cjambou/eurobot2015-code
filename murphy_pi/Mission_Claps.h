#ifndef MISSION_CLAPS_H
#define MISSION_CLAPS_H

#include "Coord.h"
#include "Mission.h"

class Mission_Claps: public Mission
{
    public:
        Mission_Claps(bool mission_a_faire_);
        void set_couleur(int couleur_);

        void stand_depart_done();
        bool is_stand_depart_done();

        void zone_coin_done();
        bool is_zone_coin_done();

        void claps_estrade_done();
        bool is_clap_estrade_done();

        void stand_estrade_done();
        bool is_stand_estrade_done();

    private:
        int couleur;
        bool stand_depart;
        bool zone_coin;    // la mission coin (2 stands + verre + claps)
        bool claps_estrade;
        bool stand_estrade; // reculer a la fin sinon les piles tombes


};

#endif // MISSION_CLAPS_H
