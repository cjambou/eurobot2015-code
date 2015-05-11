#include "Mission_Depot_Tour_Estrade.h"

Mission_Depot_Tour_Estrade::Mission_Depot_Tour_Estrade(bool mission_a_faire_):
    Mission(mission_a_faire_, 20, Coord(0,0,0),"mission depot tour estrade"),
    couleur(0),
    nbr_pile(1),
    depot_double(false),
    pile_depot(false)
{
    //ctor
    set_couleur(couleur);
}

Mission_Depot_Tour_Estrade::Mission_Depot_Tour_Estrade(bool mission_a_faire_, int nbr_pile_):
    Mission(mission_a_faire_, 20, Coord(0,0,0),"mission depot tour estrade"),
    couleur(0),
    nbr_pile(nbr_pile_),
    depot_double(false),
    pile_depot(false)
{
    //ctor
    set_couleur(couleur);
}

void Mission_Depot_Tour_Estrade::set_couleur(int couleur_)
{
    couleur = couleur_;
    /// jaune
    if(couleur == 0)
    {
        if(nbr_pile == 2)
        {
            set_coord_debut_mission(Coord(-155,460,-90));
            depot_double = true;
        }
        else
        {
            set_coord_debut_mission(Coord(-215,460,-90));
            depot_double = false;
        }

    }
    /// vert
    if(couleur == 1)
    {
        if(nbr_pile == 2)
        {
            set_coord_debut_mission(Coord(155,460,-90));
            depot_double = true;
        }
        else
        {
            set_coord_debut_mission(Coord(215,460,-90));
            depot_double = false;
        }
    }
}

bool Mission_Depot_Tour_Estrade::is_depot_double()
{
    return depot_double;
}

bool Mission_Depot_Tour_Estrade::is_pile_depose()
{
    return pile_depot;
}

void Mission_Depot_Tour_Estrade::depot_done()
{
    pile_depot = true;
}

void Mission_Depot_Tour_Estrade::activation_depot_double()
{
    depot_double = true;
    nbr_pile = 2;
    set_couleur(couleur);


}
