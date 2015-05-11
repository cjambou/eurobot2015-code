#include "Mission_Zone_centrale.h"

Mission_Zone_centrale::Mission_Zone_centrale(bool mission_a_faire_):
    Mission(mission_a_faire_, 4, Coord(0,0,0),"mission zone centrale"),
    couleur(0),
    stand_central(false),
    stand_estrade(false),
    stand_depart(false)
{
    set_couleur(couleur);
}



void Mission_Zone_centrale::set_couleur(int couleur_)
{
    couleur = couleur_;
    if(couleur == 0) // jaune
    {
        set_coord_debut_mission(Coord(-240,860,-95));
    }
    if(couleur == 1)  // vert
    {
        set_coord_debut_mission(Coord(240,860, -95));
    }
}

void Mission_Zone_centrale::catch_stand_central()
{
    stand_central = true;
}
bool Mission_Zone_centrale::is_stand_central_catched()
{
    return stand_central;
}

void Mission_Zone_centrale::catch_stand_estrade()
{
    stand_estrade = true;
}
bool Mission_Zone_centrale::is_stand_estrade_catched()
{
    return stand_estrade;
}

void Mission_Zone_centrale::catch_stand_depart()
{
    stand_depart = true;
}
bool Mission_Zone_centrale::is_stand_depart_catched()
{
    return stand_depart;
}
