#include "Mission_Depot_Tour_Depart.h"

Mission_Depot_Tour_Depart::Mission_Depot_Tour_Depart(bool mission_a_faire_):
    Mission(mission_a_faire_, 20, Coord(0,0,0),"mission depot tour depart"),
    couleur(0),
    depot_double(false),
    depot_pile(false),
    nbr_pile(1)
{
    //ctor
    set_couleur(couleur);
}

Mission_Depot_Tour_Depart::Mission_Depot_Tour_Depart(bool mission_a_faire_, int nbr_pile_):
    Mission(mission_a_faire_, 20, Coord(0,0,0),"mission depot tour depart"),
    couleur(0),
    depot_double(false),
    depot_pile(false),
    nbr_pile(nbr_pile_)
{
    //ctor
    set_couleur(couleur);
    if(nbr_pile==2){depot_double=true;}
}

void Mission_Depot_Tour_Depart::set_couleur(int couleur_)
{
    couleur = couleur_;
    if(couleur == 0)    // jaune
    {
        set_coord_debut_mission(Coord(-900,996,180));
    }
    if(couleur == 1)    // vert
    {
        set_coord_debut_mission(Coord(900,996, 0));
    }
}

bool Mission_Depot_Tour_Depart::is_depot_double()
{
    return depot_double;
}
void Mission_Depot_Tour_Depart::pile_depose()
{
    depot_pile = true;
}
bool Mission_Depot_Tour_Depart::is_pile_depose()
{
    return depot_pile;
}
