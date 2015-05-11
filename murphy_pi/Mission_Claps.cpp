#include "Mission_Claps.h"

Mission_Claps::Mission_Claps(bool mission_a_faire_):
    Mission(mission_a_faire_, 18, Coord(0,0,0),"mission claps"),
    couleur(0),
    stand_depart(false),
    zone_coin(false),
    claps_estrade(false),
    stand_estrade(false)

{
    //ctor
    set_couleur(couleur);
}

void Mission_Claps::set_couleur(int couleur_)
{
    couleur = couleur_;
    if(couleur == 0)
    {
        set_coord_debut_mission(Coord(-890,996,-90));
    }
    if(couleur == 1)
    {
        set_coord_debut_mission(Coord(890,996, 90));
    }
}


void Mission_Claps::stand_depart_done()
{
    stand_depart = true;
}
bool Mission_Claps::is_stand_depart_done()
{
    return stand_depart;
}

void Mission_Claps::zone_coin_done()
{
    zone_coin = true;
}
bool Mission_Claps::is_zone_coin_done()
{
    return zone_coin;
}

void Mission_Claps::claps_estrade_done()
{
    claps_estrade = true;
}
bool Mission_Claps::is_clap_estrade_done()
{
    return claps_estrade;
}

void Mission_Claps::stand_estrade_done()
{
    stand_estrade = true;
}
bool Mission_Claps::is_stand_estrade_done()
{
    return stand_estrade;
}
