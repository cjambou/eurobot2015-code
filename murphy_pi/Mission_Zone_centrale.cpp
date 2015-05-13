#include "Mission_Zone_centrale.h"

Mission_Zone_centrale::Mission_Zone_centrale(bool mission_a_faire_):
    Mission(mission_a_faire_, 4, Coord(0,0,0),"mission zone centrale"),
    couleur(0),
    stand_central(false),
    stand_estrade(false),
    stand_depart(false),
    rush_salace(false)
{
    set_couleur(couleur);
}



void Mission_Zone_centrale::set_couleur(int couleur_)
{
    couleur = couleur_;
    if(couleur == 0) // jaune
    {
        if(is_rush_salace_on())
        {
            set_coord_debut_mission(Coord(-880,750,-45));
        }
        else{
            set_coord_debut_mission(Coord(-240,840,-95));
        }

    }
    if(couleur == 1)  // vert
    {
        if(is_rush_salace_on())
        {
            set_coord_debut_mission(Coord(880,750, -135));
        }
        else{
            set_coord_debut_mission(Coord(240,840, -85));
        }

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


void Mission_Zone_centrale::activation_rush_salace()
{
    rush_salace = true;
}
bool Mission_Zone_centrale::is_rush_salace_on()
{
    return rush_salace;
}
void Mission_Zone_centrale::desactivation_rush_salace()
{
    rush_salace = false;
}
