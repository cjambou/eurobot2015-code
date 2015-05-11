#include "Mission_Distrib.h"

Mission_Distrib::Mission_Distrib(bool mission_a_faire_):
    Mission(mission_a_faire_, 14, Coord(0,0,0),"mission distrib"),
    couleur(0),
    vidange_zone(false),
    gobelet_escalier(false)
{
    //ctor
    set_couleur(couleur);
}

void Mission_Distrib::set_couleur(int couleur_)
{
    couleur = couleur_;
    if(couleur == 0)
    {
        set_coord_debut_mission(Coord(-960,999,0));
    }
    if(couleur == 1)
    {
        set_coord_debut_mission(Coord(960,999, 180));
    }
}


void Mission_Distrib::netoyage_zone_done()
{
    vidange_zone = true;
}

void Mission_Distrib::capture_gobelet_done()
{
    gobelet_escalier = true;
}

bool Mission_Distrib::is_netoyage_zone_done()
{
    return vidange_zone;
}

bool Mission_Distrib::is_capture_gobelet_done()
{
    return gobelet_escalier;
}
