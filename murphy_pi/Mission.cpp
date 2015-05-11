#include "Mission.h"

Mission::Mission(bool mission_a_faire_, int nbr_pts_, Coord coord_debut_mission_, string title_):
        coord_debut_mission(coord_debut_mission_),
        status((int)mission_a_faire_),        // statu de la mission
        nbr_pts(nbr_pts_),
        mission_faite(!mission_a_faire_),
        title(title_),
        priorite(0)
{
    //ctor
}

void Mission::set_priorite(int priorite_)
{
    priorite = priorite_;
}
int Mission::get_priorite()
{
    return priorite;
}


Coord Mission::get_coord_debut_mission()
{
    return coord_debut_mission;
}


bool Mission::is_accomplie()
{
    return mission_faite;
}


void Mission::mission_remplie()
{
    cout<<title<<" -> remplie"<<endl;
    mission_faite = true;
}


int Mission::point_restant()
{
    if(nbr_pts<=0){return 0;}
    return nbr_pts;
}


float Mission::distance_to_mission(Coord coord_reel)
{
    return Vector(coord_debut_mission,coord_reel).norm();
}

void Mission::set_coord_debut_mission(Coord coord_debut_mission_)
{
    coord_debut_mission = coord_debut_mission_;
}

void Mission::affiche()
{
    cout<<"Mission : "<<title<<endl;
    cout<<"Status  : "<<mission_faite<<endl;
    cout<<"Pts     : "<<nbr_pts<<endl;
    cout<<"Coord   : "<<get_coord_debut_mission().get_x()<<" "<<get_coord_debut_mission().get_y()<<" "<<get_coord_debut_mission().get_cap()<<endl;
}

string Mission::get_title()
{
    return title;
}
