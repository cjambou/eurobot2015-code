#include "Mission_Chiage_Balle.h"

Mission_Chiage_Balle::Mission_Chiage_Balle(bool mission_a_faire_):
    Mission(mission_a_faire_, 12, Coord(0,0,0),"mission chiage"),
    couleur(0),
    drop_pop_corn(false),
    drop_gobelet(false),
    catch_ball(false)
{
    //ctor
    set_couleur(couleur);
    //set_priorite(PRIORITE_MISSION_MOYENNE);
}


void Mission_Chiage_Balle::drop_pop_corn_done()
{
    drop_pop_corn = true;
}

void Mission_Chiage_Balle::drop_gobelet_done()
{
    drop_gobelet = true;
}

void Mission_Chiage_Balle::catch_ball_done()
{
    catch_ball = true;
}

bool Mission_Chiage_Balle::is_drop_pop_corn()
{
    return drop_pop_corn;
}

bool Mission_Chiage_Balle::is_drop_gobelet()
{
    return drop_gobelet;
}
bool Mission_Chiage_Balle::is_catch_ball()
{
    return catch_ball;
}



void Mission_Chiage_Balle::set_couleur(int couleur_)
{
    couleur = couleur_;
    if(couleur == 0)
    {
        set_coord_debut_mission(Coord(-900,999,0));
    }
    if(couleur == 1)
    {
        set_coord_debut_mission(Coord(900,999, 180));
    }
}


