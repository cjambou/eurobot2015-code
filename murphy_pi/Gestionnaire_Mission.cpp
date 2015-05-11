#include "Gestionnaire_Mission.h"

/********************************************************
    GESTIONNAIRE DE MISSION
*********************************************************/
#define PERIODE_JEU 90000
Gestionnaire_Mission::Gestionnaire_Mission():
        element_robot(),        // pour savoir ce qu'on a sous la dent
        mission_claps(true),
        mission_distrib(true),
        mission_chiage_balle(true),
        mission_zone_centrale(true),
        mission_depot_tour_depart(true),
        mission_depot_tour_estrade(true),
        mission_zone_ennemie(true),
        coord_reel(0,0,0),
        mae_murphy(),
        period_jeu(PERIODE_JEU),
        cap_to_mission(0),
        alignement_to_mission(false),
        premiere_entree_decision(true),
        strategie_1(0),
        strategie_2(0),
        distance_mission(0)
{
    mae_murphy.create();
    mission_zone_ennemie.mission_remplie();
    mission_depot_tour_estrade.mission_remplie();
    mission_depot_tour_depart.mission_remplie();

}

void Gestionnaire_Mission::start_compteur_periode()
{
    period_jeu.reset();
}


bool Gestionnaire_Mission::commencement()
{
    return premiere_entree_decision;
}
void Gestionnaire_Mission::commencement_end()
{
    premiere_entree_decision = false;
}

void Gestionnaire_Mission::set_coord(Coord coord_reel_)
{
    coord_reel = coord_reel_;
}

Coord Gestionnaire_Mission::get_coord()
{
    return coord_reel;
}


void Gestionnaire_Mission::decision_mission()
{
    actualisation_Priorite();
    /// recolte des données sur les missions, on prend seulement si la missions n'est pas remplie
    vector<float> vectorDistance;
    vector<string> vectorName;
    vector<int> vectorMission;
    vector<int> vectorPriorite;
    vector<float> vectorDecision;

    if(!mission_claps.is_accomplie())
    {
        vectorMission.push_back(MISSION_CLAPS);
        vectorName.push_back(mission_claps.get_title());
        vectorDistance.push_back(mission_claps.distance_to_mission(coord_reel));
        vectorPriorite.push_back(mission_claps.get_priorite());
    }
    if(!mission_distrib.is_accomplie())
    {
        vectorMission.push_back(MISSION_DISTRIB);
        vectorName.push_back(mission_distrib.get_title());
        vectorDistance.push_back(mission_distrib.distance_to_mission(coord_reel));
        vectorPriorite.push_back(mission_distrib.get_priorite());

    }
    if(!mission_chiage_balle.is_accomplie())
    {
        vectorMission.push_back(MISSION_CHIAGE_BALLE);
        vectorName.push_back(mission_chiage_balle.get_title());
        vectorDistance.push_back(mission_chiage_balle.distance_to_mission(coord_reel));
        vectorPriorite.push_back(mission_chiage_balle.get_priorite());
    }
    if(!mission_zone_centrale.is_accomplie())
    {
        vectorMission.push_back(MISSION_ZONE_CENTRALE);
        vectorName.push_back(mission_zone_centrale.get_title());
        vectorDistance.push_back(mission_zone_centrale.distance_to_mission(coord_reel));
        vectorPriorite.push_back(mission_zone_centrale.get_priorite());
    }
    if(!mission_depot_tour_depart.is_accomplie())
    {
        vectorMission.push_back(MISSION_TOUR_DEPART);
        vectorName.push_back(mission_depot_tour_depart.get_title());
        vectorDistance.push_back(mission_depot_tour_depart.distance_to_mission(coord_reel));
        vectorPriorite.push_back(mission_depot_tour_depart.get_priorite());
    }
    if(!mission_depot_tour_estrade.is_accomplie())
    {
        vectorMission.push_back(MISSION_TOUR_ESTRADE);
        vectorName.push_back(mission_depot_tour_estrade.get_title());
        vectorDistance.push_back(mission_depot_tour_estrade.distance_to_mission(coord_reel));
        vectorPriorite.push_back(mission_depot_tour_estrade.get_priorite());
    }
    if(!mission_zone_ennemie.is_accomplie())
    {
        vectorMission.push_back(MISSION_ZONE_ENNEMIE);
        vectorName.push_back(mission_zone_ennemie.get_title());
        vectorDistance.push_back(mission_zone_ennemie.distance_to_mission(coord_reel));
        vectorPriorite.push_back(mission_zone_ennemie.get_priorite());
    }




    /// affichage des missions à faire et les poids associées
    cout<<"mission dispo : "<<vectorDistance.size()<<endl;
    for (int index=0; index<(int)vectorDistance.size(); index++) {
        /** OPERATION POUR DECISION DE MISSION ICI : priorite - distance/1000*/
        vectorDecision.push_back((float)vectorPriorite[index] - vectorDistance[index]/900.0);
        cout.precision(2);
        cout<<"["<<vectorMission[index]<<"] Prio : ["<< vectorPriorite[index]<<"] DIS : "<<(int)vectorDistance[index]<<"\t Poids :"<<vectorDecision[index]<<"  \t"<<vectorName[index]<<endl;
    }


    /// decision de la mission a faire
    if(vectorDistance.size() == 0)
    {
        cout<<"aucune mission restante"<<endl;
    }
    else
    {
        if(vectorDistance.size() == 1)
        {
            cout<<"une seule mission restante"<<endl;
            int mission_to_do = vectorMission[0];
            cout<<"The mission to do : [" <<mission_to_do<<"] "<<vectorName[0]<<endl;

            /// appel de trigger()
            appel_trigger(mission_to_do);
            distance_mission = vectorDistance[0];
        }
        else
        {
            /// choix a faire dans les prioritées, en prennant en compte les distances restantes
            //cout<<"choix a faire ! "<<endl;
            //float biggest = *max_element(vectorDecision.begin(),vectorDecision.end());
            int index_max = distance(vectorDecision.begin(),max_element(vectorDecision.begin(),vectorDecision.end()));
            int mission_to_do = vectorMission[index_max];
            //cout << "The largest element is "  << biggest << endl;
            //cout << "The element is : "  << index_max << endl;
            cout << "The mission to do : ["  << mission_to_do << "] " << vectorName[index_max]<< endl;
            distance_mission = vectorDistance[index_max];
            /// appel de trigger()
            appel_trigger(mission_to_do);
        }
    }


}

void Gestionnaire_Mission::evitement_mission()
{
    sortie_evitement = true;
    cout<<"Evitement provoque sur mission ["<<mission_sortie_evitement<<"]"<<endl;
}

int Gestionnaire_Mission::get_distance_to_mission()
{
    return distance_mission;
}

bool Gestionnaire_Mission::is_mission_far()
{
    return (distance_mission > DISTANCE_MINI_TO_MISSION);
}

float Gestionnaire_Mission::get_cap_to_mission()
{
    return cap_to_mission*180 / PI;
}

float Gestionnaire_Mission::get_x_mission()
{
    return x_mission;
}

float Gestionnaire_Mission::get_y_mission()
{
    return y_mission;
}

float Gestionnaire_Mission::get_cap_mission()
{
    return cap_mission; //*180 / PI;
}


string Gestionnaire_Mission::get_cap_to_mission_str()
{
    string result;
    ostringstream convert;

    convert << (int)get_cap_to_mission();
    result = convert.str();
    return result;
}

string Gestionnaire_Mission::get_x_mission_str()
{
    string result;
    ostringstream convert;

    convert << get_x_mission();
    result = convert.str();
    return result;
}

string Gestionnaire_Mission::get_y_mission_str()
{
    string result;
    ostringstream convert;

    convert << get_y_mission();
    result = convert.str();
    return result;
}

string Gestionnaire_Mission::get_cap_mission_str()
{
    string result;
    ostringstream convert;

    convert << (int)get_cap_mission();
    result = convert.str();
    return result;
}

void Gestionnaire_Mission::appel_trigger(int mission_indice_)
{
    sortie_evitement = false;
    cout<<"appel de trigger sur mission : ";
    Vector *vector_to_mission;

    switch(mission_indice_)
    {
        case MISSION_CLAPS:
            cout<<mission_claps.get_title()<<endl;
            // trigger
            mission_sortie_evitement = MISSION_CLAPS;
            vector_to_mission = new Vector(coord_reel,mission_claps.get_coord_debut_mission());
            cap_to_mission = vector_to_mission->get_angle();
            x_mission = mission_claps.get_coord_debut_mission().get_x();
            y_mission = mission_claps.get_coord_debut_mission().get_y();
            cap_mission = mission_claps.get_coord_debut_mission().get_cap();
            cout << "cap vers objectif : " << int(cap_to_mission*180 / PI) << endl;

            get_mae_murphy()->mission_claps();
            break;

        case MISSION_DISTRIB:
            cout<<mission_distrib.get_title()<<endl;
            // trigger
            mission_sortie_evitement = MISSION_DISTRIB;
            vector_to_mission = new Vector(coord_reel,mission_distrib.get_coord_debut_mission());
            cap_to_mission = vector_to_mission->get_angle();
            x_mission = mission_distrib.get_coord_debut_mission().get_x();
            y_mission = mission_distrib.get_coord_debut_mission().get_y();
            cap_mission = mission_distrib.get_coord_debut_mission().get_cap();
            cout << "cap vers objectif : " << int(cap_to_mission*180 / PI) << endl;

            get_mae_murphy()->mission_distrib();
            break;

        case MISSION_CHIAGE_BALLE:
            cout<<mission_chiage_balle.get_title()<<endl;
            // trigger
            mission_sortie_evitement = MISSION_CHIAGE_BALLE;
            vector_to_mission = new Vector(coord_reel,mission_chiage_balle.get_coord_debut_mission());
            cap_to_mission = vector_to_mission->get_angle();
            x_mission = mission_chiage_balle.get_coord_debut_mission().get_x();
            y_mission = mission_chiage_balle.get_coord_debut_mission().get_y();
            cap_mission = mission_chiage_balle.get_coord_debut_mission().get_cap();
            cout << "cap vers objectif : " << int(cap_to_mission*180 / PI) << endl;

            get_mae_murphy()->mission_chiage_balle();
            break;

        case MISSION_ZONE_CENTRALE:
            cout<<mission_zone_centrale.get_title()<<endl;
            // trigger
            vector_to_mission = new Vector(coord_reel,mission_zone_centrale.get_coord_debut_mission());
            cap_to_mission = vector_to_mission->get_angle();
            x_mission = mission_zone_centrale.get_coord_debut_mission().get_x();
            y_mission = mission_zone_centrale.get_coord_debut_mission().get_y();
            cap_mission = mission_zone_centrale.get_coord_debut_mission().get_cap();
            cout << "cap vers objectif : " << int(cap_to_mission*180 / PI) << endl;
            mission_sortie_evitement = MISSION_ZONE_CENTRALE;

            get_mae_murphy()->mission_zone_centrale();
            break;

        case MISSION_TOUR_DEPART:
            cout<<mission_depot_tour_depart.get_title()<<endl;
            // trigger
            mission_sortie_evitement = MISSION_TOUR_DEPART;
            vector_to_mission = new Vector(coord_reel,mission_depot_tour_depart.get_coord_debut_mission());
            cap_to_mission = vector_to_mission->get_angle();
            x_mission = mission_depot_tour_depart.get_coord_debut_mission().get_x();
            y_mission = mission_depot_tour_depart.get_coord_debut_mission().get_y();
            cap_mission = mission_depot_tour_depart.get_coord_debut_mission().get_cap();
            cout << "cap vers objectif : " << int(cap_to_mission*180 / PI)<< endl;

            get_mae_murphy()->mission_depot_tour_depart();
            break;

        case MISSION_TOUR_ESTRADE:
            cout<<mission_depot_tour_estrade.get_title()<<endl;
            // trigger
            mission_sortie_evitement = MISSION_TOUR_ESTRADE;
            vector_to_mission = new Vector(coord_reel,mission_depot_tour_estrade.get_coord_debut_mission());
            cap_to_mission = vector_to_mission->get_angle();
            x_mission = mission_depot_tour_estrade.get_coord_debut_mission().get_x();
            y_mission = mission_depot_tour_estrade.get_coord_debut_mission().get_y();
            cap_mission = mission_depot_tour_estrade.get_coord_debut_mission().get_cap();
            cout << "cap vers objectif : " << int(cap_to_mission*180 / PI) << endl;

            get_mae_murphy()->mission_depot_tour_estrade();
            break;

        case MISSION_ZONE_ENNEMIE:
            cout<<mission_zone_ennemie.get_title()<<endl;
            // trigger
            mission_sortie_evitement = MISSION_ZONE_ENNEMIE;
            vector_to_mission = new Vector(coord_reel,mission_zone_ennemie.get_coord_debut_mission());
            cap_to_mission = vector_to_mission->get_angle();
            x_mission = mission_zone_ennemie.get_coord_debut_mission().get_x();
            y_mission = mission_zone_ennemie.get_coord_debut_mission().get_y();
            cap_mission = mission_zone_ennemie.get_coord_debut_mission().get_cap();
            cout << "cap vers objectif : " << int(cap_to_mission*180 / PI) << endl;

            get_mae_murphy()->mission_zone_ennemie();
            break;
    }
    cout<<endl;
}



void Gestionnaire_Mission::actualisation_Priorite()
{
    // temps restant pour decision des truc important
    temps_restant = (period_jeu.time_elapsed()- PERIODE_JEU)/1000; // en s
    cout<<"temps restant : "<<temps_restant<<" s"<<endl;
    cout<<"actualisation des prioritées"<<endl;
    if(sortie_evitement == true)
    {
        // peut etre mettre juste un malus
        switch(mission_sortie_evitement)
        {
            case MISSION_CLAPS:
                mission_claps.set_priorite(PRIORITE_MISSION_FAIBLE);
                break;

            case MISSION_DISTRIB:
                mission_distrib.set_priorite(PRIORITE_MISSION_FAIBLE);
                break;

            case MISSION_CHIAGE_BALLE:
                mission_chiage_balle.set_priorite(PRIORITE_MISSION_FAIBLE);
                break;

            case MISSION_ZONE_CENTRALE:
                mission_zone_centrale.set_priorite(PRIORITE_MISSION_FAIBLE);
                break;

            case MISSION_TOUR_DEPART:
                mission_depot_tour_depart.set_priorite(PRIORITE_MISSION_FAIBLE);
                break;

            case MISSION_TOUR_ESTRADE:
                mission_depot_tour_estrade.set_priorite(PRIORITE_MISSION_FAIBLE);
                break;

            case MISSION_ZONE_ENNEMIE:
                mission_zone_ennemie.set_priorite(PRIORITE_MISSION_FAIBLE);
                break;
        }

    }
    else
    {

        /***********************************************************************************************************
                    DISTRIB
        ***********************************************************************************************************/
        // si on a rien fait
        if(!mission_distrib.is_netoyage_zone_done() && !element_robot.pop_corn_present())
        {
            if(!mission_distrib.is_capture_gobelet_done())
            {
                if(strategie_1==0)
                {
                    mission_distrib.set_priorite(PRIORITE_MISSION_FIRST);
                }
                else
                {
                    mission_distrib.set_priorite(PRIORITE_MISSION_HAUTE);
                }
            }
            else
            {
                mission_distrib.set_priorite(PRIORITE_MISSION_HAUTE);
            }
        }
        else
        {
            if(!mission_distrib.is_capture_gobelet_done())
            {
                if(element_robot.gobelet_present())
                {
                    mission_distrib.set_priorite(PRIORITE_MISSION_FAIBLE);
                }
                else
                {
                    mission_distrib.set_priorite(PRIORITE_MISSION_MOYENNE);
                }

            }
            else
            {
                mission_distrib.set_priorite(PRIORITE_MISSION_FAIBLE);
            }
        }

        /***********************************************************************************************************
                    CLAPS
        ***********************************************************************************************************/
        if(element_robot.gobelet_present())
        {
            mission_claps.set_priorite(PRIORITE_MISSION_MOYENNE);
        }
        else
        {
            mission_claps.set_priorite(PRIORITE_MISSION_HAUTE);
        }



        /***********************************************************************************************************
                    ZONE CENTRALE
        ***********************************************************************************************************/
        if(strategie_1==1)
        {
            mission_zone_centrale.set_priorite(PRIORITE_MISSION_FIRST);
        }
        else
        {
            mission_zone_centrale.set_priorite(PRIORITE_MISSION_MOYENNE);
        }


        /***********************************************************************************************************
                    ZONE ENNEMIE
        ***********************************************************************************************************/
        //if()
        mission_zone_ennemie.set_priorite(PRIORITE_MISSION_FAIBLE);



        /***********************************************************************************************************
                    CHIAGE
        ***********************************************************************************************************/
        /// si la mission distrib est close, on a un gobelet, des balles, etc...
        /// donc faut aller ider ça vite fait
        if(mission_distrib.is_accomplie())
        {
                mission_chiage_balle.set_priorite(PRIORITE_MISSION_FIRST);
        }
        else
        {
            /// si on a du pop corn, c'est qu'on a potentiellement autre chose, donc important
            if( element_robot.pop_corn_present() )
            {
                mission_chiage_balle.set_priorite(PRIORITE_MISSION_FIRST);
            }
            else
            {
                /// si on a pas de pop corn mais un gobelet pas posé dans la zone, c'est peu etre le moment d'y aller
                if (element_robot.gobelet_present() && !mission_chiage_balle.is_drop_gobelet())
                {
                    mission_chiage_balle.set_priorite(PRIORITE_MISSION_MOYENNE);
                }
                else
                {
                    mission_chiage_balle.set_priorite(PRIORITE_MISSION_FAIBLE);
                }

            }
        }


        /***********************************************************************************************************
                    DEPOT DE PILE
        ***********************************************************************************************************/
        /// si on rempli les piles comme il faut
        /// donc faut aller ider ça vite fait
        if(element_robot.pile_droite_nbr()==4 || element_robot.pile_gauche_nbr()==4)
        {
            if(couleur == 0)
            {
                if(element_robot.pile_gauche_nbr()==4)
                {
                    mission_depot_tour_estrade.set_priorite(PRIORITE_MISSION_FIRST);
                }
                if(element_robot.pile_droite_nbr()==4)
                {
                    mission_depot_tour_depart.set_priorite(PRIORITE_MISSION_HAUTE);
                }
            }
            if(couleur == 1)
            {
                if(element_robot.pile_droite_nbr()==4)
                {
                    mission_depot_tour_estrade.set_priorite(PRIORITE_MISSION_FIRST);
                }
                if(element_robot.pile_gauche_nbr()==4)
                {
                    mission_depot_tour_depart.set_priorite(PRIORITE_MISSION_HAUTE);
                }
            }
        }
        else
        {
            /// si le temps presse on va vider quoi qu'il arrive
            if((temps_restant<20) && (element_robot.pile_droite_nbr()>=1 || element_robot.pile_gauche_nbr()>=1) )
            {
                mission_depot_tour_depart.set_priorite(PRIORITE_MISSION_FIRST);
                mission_depot_tour_estrade.set_priorite(PRIORITE_MISSION_FIRST);
            }
            else
            {
                mission_depot_tour_depart.set_priorite(PRIORITE_MISSION_FAIBLE);
                mission_depot_tour_estrade.set_priorite(PRIORITE_MISSION_FAIBLE);
            }
        }// fin depot pile


    }


}

void Gestionnaire_Mission::actualisation_temps_restant()
{

}


void Gestionnaire_Mission::set_couleur(int couleur_)
{
    couleur = couleur_;
    mission_claps.set_couleur(couleur_);
    mission_distrib.set_couleur(couleur_);
    mission_chiage_balle.set_couleur(couleur_);
    mission_zone_centrale.set_couleur(couleur_);
    mission_depot_tour_depart.set_couleur(couleur_);
    mission_depot_tour_estrade.set_couleur(couleur_);
    mission_zone_ennemie.set_couleur(couleur_);
}


void Gestionnaire_Mission::affiche_mission_active()
{
    cout<<"mission en cours : "<<endl;
    if(!mission_claps.is_accomplie())               { mission_claps.affiche(); }
    if(!mission_distrib.is_accomplie())             { mission_distrib.affiche(); }
    if(!mission_chiage_balle.is_accomplie())        { mission_chiage_balle.affiche(); }
    if(!mission_zone_centrale.is_accomplie())       { mission_zone_centrale.affiche(); }
    if(!mission_depot_tour_depart.is_accomplie())   { mission_depot_tour_depart.affiche(); }
    if(!mission_depot_tour_estrade.is_accomplie())  { mission_depot_tour_estrade.affiche(); }
    if(!mission_zone_ennemie.is_accomplie())        { mission_zone_ennemie.affiche(); }
}


Mission_Claps*                  Gestionnaire_Mission::get_mission_claps()
{
    return &mission_claps;
}
Mission_Distrib*                Gestionnaire_Mission::get_mission_distrib()
{
    return &mission_distrib;
}
Mission_Chiage_Balle*           Gestionnaire_Mission::get_mission_chiage_balle()
{
    return &mission_chiage_balle;
}
Mission_Zone_centrale*          Gestionnaire_Mission::get_mission_zone_centrale()
{
    return &mission_zone_centrale;
}
Mission_Depot_Tour_Depart*      Gestionnaire_Mission::get_mission_depot_tour_depart()
{
    return &mission_depot_tour_depart;
}
Mission_Depot_Tour_Estrade*     Gestionnaire_Mission::get_mission_depot_tour_estrade()
{
    return &mission_depot_tour_estrade;
}
Mission_Zone_Ennemie*           Gestionnaire_Mission::get_mission_zone_ennemie()
{
    return &mission_zone_ennemie;
}

Element_Robot* Gestionnaire_Mission::get_element_robot()
{
    return &element_robot;
}


// retourne la strategie en cours, pour gestionnaire
int Gestionnaire_Mission::strategie()
{
    if(strategie_1 == 0 && strategie_2 == 0)
    {
        return STRAT_0;
    }
    if(strategie_1 == 1 && strategie_2 == 0)
    {
        return STRAT_1;
    }
    if(strategie_1 == 0 && strategie_2 == 1)
    {
        return STRAT_2;
    }
    if(strategie_1 == 1 && strategie_2 == 1)
    {
        return STRAT_3;
    }
    return 0;
}

void Gestionnaire_Mission::set_strategie_1(int strat_)
{
    strategie_1 = strat_;
}

void Gestionnaire_Mission::set_strategie_2(int strat_)
{
    strategie_2 = strat_;
}


MAE_MURPHY* Gestionnaire_Mission::get_mae_murphy()
{
    return &mae_murphy;
}

