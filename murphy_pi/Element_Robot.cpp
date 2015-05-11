#include "Element_Robot.h"

Element_Robot::Element_Robot():
        pile_gauche(0),
        pile_droite(0),
        gobelet(false),
        pop_corn(false),
        balle(false)
{
    //ctor
    pile_gauche_reset();
    pile_droite_reset();
}



int Element_Robot::pile_gauche_nbr()
{
    return pile_gauche;
}

void Element_Robot::pile_gauche_incr()
{
    pile_gauche++;
}

void Element_Robot::pile_gauche_reset()
{
    pile_gauche = 0;
}

int Element_Robot::pile_droite_nbr()
{
    return pile_droite;
}
void Element_Robot::pile_droite_incr()
{
    pile_droite++;
}

void Element_Robot::pile_droite_reset()
{
    pile_droite = 0;
}

void Element_Robot::gobelet_saisie()
{
    gobelet = true;
}

void Element_Robot::gobelet_relache()
{
    gobelet = false;
}

bool Element_Robot::gobelet_present()
{
    return gobelet;
}

void Element_Robot::pop_corn_aspire()
{
    pop_corn = true;
}

void Element_Robot::pop_corn_decharge()
{
    pop_corn = false;
}

bool Element_Robot::pop_corn_present()
{
    return pop_corn;
}


void Element_Robot::balle_catch()
{
    balle = true;
}
bool Element_Robot::balle_presente()
{
    return balle;
}
