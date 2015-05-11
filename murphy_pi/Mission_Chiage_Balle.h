#ifndef MISSION_CHIAGE_BALLE_H
#define MISSION_CHIAGE_BALLE_H

#include "Coord.h"
#include "Mission.h"

class Mission_Chiage_Balle : public Mission
{
    public:
        Mission_Chiage_Balle(bool mission_a_faire_);
        void set_couleur(int couleur_);

        void drop_pop_corn_done();
        void drop_gobelet_done();
        void catch_ball_done();
        bool is_drop_pop_corn();
        bool is_drop_gobelet();
        bool is_catch_ball();

    private:
        int couleur;
        bool drop_pop_corn;
        bool drop_gobelet;
        bool catch_ball;
        //void change_pts();

};

#endif // MISSION_CHIAGE_BALLE_H
