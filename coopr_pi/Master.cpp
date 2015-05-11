#include "Master.h"

Master::Master(int portSerie_):
    periode_run(PERIODE_MASTER),
    time_out_on(false),
    t_over(0),
    couleur(0),
    tour_de_roue(0),
    cycle_attente(0),
    portSerie(portSerie_),
    rush(false)
{
    mae_coop_r.create();
    cout << "[MASTER_COOP'R] initialisation" << endl;
}

int Master::getPortSerie()
{
    return portSerie;
}

// retourne la couleur de la strat
int Master::get_Couleur()
{
    return couleur;
}

// la strat est elle verte?
bool Master::is_Vert()
{
    return (couleur==COULEUR_VERT);
}

// jaune?
bool Master::is_Jaune()
{
    return (couleur==COULEUR_JAUNE);
}

// retourne la MAE
MAE_COOP_R* Master::get_MAE_COOP_R()
{
    return &mae_coop_r;
}


// modifie la couleur de la strat
void Master::set_couleur(int couleur_)
{
    couleur = couleur_;
    if (couleur == COULEUR_JAUNE)
    {
        cout << "[COULEUR] Jaune" << endl;
    }

    if (couleur == COULEUR_VERT)
    {
        cout << "[COULEUR] Vert" << endl;
    }
}


// boucle de controle du master
void Master::run()
{
    if(periode_run.is_over())
        {
            periode_run.reset();

            // execution des instructions
            mae_coop_r.doActivity();

            // les transistions autre que time_out provienne du protocole de COM par ordre retour

            // check les time out
            if(is_time_out())
            {
                mae_coop_r.time_out();
            }

            /** appel du protocol de COM
                - adversaire
                - assFini
                - ioFini
            */

        }
}


// tempo
void Master::set_time_out(int dt_)
{
    t_over = millis() + dt_;
    time_out_on = true;
    cout<<"time_out set "<< dt_<<endl;
    cout<<"time in "<< millis()<<endl;
    cout<<"time out "<< t_over<<endl;
}

// reset time out
void Master::reset_time_out()
{
    time_out_on = false;
}

// es ce que c'est fini
bool Master::is_time_out()
{
   if (time_out_on && t_over < millis())
   {
     time_out_on = false;
     cout<<"time in "<< millis()<<endl;
     return true;
   }
   return false;
}

/** gere les cycle d'attente de l'evitement
*/
int Master::get_cycle_attente()
{
    return cycle_attente;
}
void Master::cycle_attente_incremente()
{
    cycle_attente++;
}
void Master::cycle_attente_reset()
{
    cycle_attente = 0;
}


/** gere les tour de roue
*/
int Master::get_tour_roue()
{
    return tour_de_roue;
}
void Master::tour_roue_incremente()
{
    tour_de_roue++;
}
void Master::tour_roue_reset()
{
    tour_de_roue = 0;;
}
void Master::tour_roue_set(int tour)
{
    tour_de_roue = tour;
}


void Master::activation_rush()
{
    rush = true;
}

void Master::desactivation_rush()
{
    rush = false;
}


bool Master::is_rush()
{
    return rush;
}
