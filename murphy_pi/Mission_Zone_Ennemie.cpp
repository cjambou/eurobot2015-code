#include "Mission_Zone_Ennemie.h"


Mission_Zone_Ennemie::Mission_Zone_Ennemie(bool mission_a_faire_):
    Mission(mission_a_faire_, 9, Coord(0,0,0),"mission zone ennemie"),
    couleur(0),
    claps(false),
    depot_gobelet(false),
    chieur(0)
{
    //ctor
    set_couleur(couleur);
    //affiche();
}


void Mission_Zone_Ennemie::set_couleur(int couleur_)
{
    couleur = couleur_;
    if(couleur == 0)    // jaune
    {
        set_coord_debut_mission(Coord(512,550,-25));
    }
    if(couleur == 1)    // vert
    {
        set_coord_debut_mission(Coord(-512,550, 205));
    }
}


void Mission_Zone_Ennemie::claps_done()
{
    claps = true;
}
void Mission_Zone_Ennemie::depot_gobelet_done()
{
    depot_gobelet = true;
}
bool Mission_Zone_Ennemie::is_claps_done()
{
    return claps;
}
bool Mission_Zone_Ennemie::is_depot_gobelet_done()
{
    return depot_gobelet;
}
int Mission_Zone_Ennemie::mode_chieur()
{
    return chieur;
}
void Mission_Zone_Ennemie::mode_chieur_plus()
{
    chieur = 2;
}
void Mission_Zone_Ennemie::mode_chieur_faible()
{
    chieur = 1;
}
void Mission_Zone_Ennemie::mode_chieur_stop()
{
    chieur = 0;
}
