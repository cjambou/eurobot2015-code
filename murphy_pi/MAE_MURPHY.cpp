
#include "MAE_MURPHY.h"

#include "Master.h"
#include <wiringPi.h>
#include <wiringSerial.h>
#include <iostream>
#include <string>

using namespace std;

MAE_MURPHY::AnyState::~AnyState() {
}

// perform the 'do activity'
void MAE_MURPHY::AnyState::_do(MAE_MURPHY &) {
}

void MAE_MURPHY::AnyState::create(MAE_MURPHY &) {
}

// the current state doesn't manage the event start_mis, give it to the upper state
void MAE_MURPHY::AnyState::start_mis(MAE_MURPHY & stm) {
    AnyState * st = _upper(stm);
  
    if (st != 0)
      st->start_mis(stm);
#ifdef VERBOSE_STATE_MACHINE
    else
      puts("DEBUG : transition start_mis not expected");
#endif
}

// the current state doesn't manage the event assFini, give it to the upper state
void MAE_MURPHY::AnyState::assFini(MAE_MURPHY & stm) {
    AnyState * st = _upper(stm);
  
    if (st != 0)
      st->assFini(stm);
#ifdef VERBOSE_STATE_MACHINE
    else
      puts("DEBUG : transition assFini not expected");
#endif
}

// the current state doesn't manage the event pince_lache, give it to the upper state
void MAE_MURPHY::AnyState::pince_lache(MAE_MURPHY & stm) {
    AnyState * st = _upper(stm);
  
    if (st != 0)
      st->pince_lache(stm);
#ifdef VERBOSE_STATE_MACHINE
    else
      puts("DEBUG : transition pince_lache not expected");
#endif
}

// the current state doesn't manage the event pince_ready_to_drop, give it to the upper state
void MAE_MURPHY::AnyState::pince_ready_to_drop(MAE_MURPHY & stm) {
    AnyState * st = _upper(stm);
  
    if (st != 0)
      st->pince_ready_to_drop(stm);
#ifdef VERBOSE_STATE_MACHINE
    else
      puts("DEBUG : transition pince_ready_to_drop not expected");
#endif
}

// the current state doesn't manage the event blocage, give it to the upper state
void MAE_MURPHY::AnyState::blocage(MAE_MURPHY & stm) {
    AnyState * st = _upper(stm);
  
    if (st != 0)
      st->blocage(stm);
#ifdef VERBOSE_STATE_MACHINE
    else
      puts("DEBUG : transition blocage not expected");
#endif
}

// the current state doesn't manage the event pince_range, give it to the upper state
void MAE_MURPHY::AnyState::pince_range(MAE_MURPHY & stm) {
    AnyState * st = _upper(stm);
  
    if (st != 0)
      st->pince_range(stm);
#ifdef VERBOSE_STATE_MACHINE
    else
      puts("DEBUG : transition pince_range not expected");
#endif
}

// the current state doesn't manage the event evitement, give it to the upper state
void MAE_MURPHY::AnyState::evitement(MAE_MURPHY & stm) {
    AnyState * st = _upper(stm);
  
    if (st != 0)
      st->evitement(stm);
#ifdef VERBOSE_STATE_MACHINE
    else
      puts("DEBUG : transition evitement not expected");
#endif
}

// the current state doesn't manage the event time_out, give it to the upper state
void MAE_MURPHY::AnyState::time_out(MAE_MURPHY & stm) {
    AnyState * st = _upper(stm);
  
    if (st != 0)
      st->time_out(stm);
#ifdef VERBOSE_STATE_MACHINE
    else
      puts("DEBUG : transition time_out not expected");
#endif
}

// the current state doesn't manage the event pince_ouverte, give it to the upper state
void MAE_MURPHY::AnyState::pince_ouverte(MAE_MURPHY & stm) {
    AnyState * st = _upper(stm);
  
    if (st != 0)
      st->pince_ouverte(stm);
#ifdef VERBOSE_STATE_MACHINE
    else
      puts("DEBUG : transition pince_ouverte not expected");
#endif
}

// the current state doesn't manage the event pince_stand_by, give it to the upper state
void MAE_MURPHY::AnyState::pince_stand_by(MAE_MURPHY & stm) {
    AnyState * st = _upper(stm);
  
    if (st != 0)
      st->pince_stand_by(stm);
#ifdef VERBOSE_STATE_MACHINE
    else
      puts("DEBUG : transition pince_stand_by not expected");
#endif
}

// the current state doesn't manage the event distrib_deboite, give it to the upper state
void MAE_MURPHY::AnyState::distrib_deboite(MAE_MURPHY & stm) {
    AnyState * st = _upper(stm);
  
    if (st != 0)
      st->distrib_deboite(stm);
#ifdef VERBOSE_STATE_MACHINE
    else
      puts("DEBUG : transition distrib_deboite not expected");
#endif
}

// the current state doesn't manage the event fin_montee_bras, give it to the upper state
void MAE_MURPHY::AnyState::fin_montee_bras(MAE_MURPHY & stm) {
    AnyState * st = _upper(stm);
  
    if (st != 0)
      st->fin_montee_bras(stm);
#ifdef VERBOSE_STATE_MACHINE
    else
      puts("DEBUG : transition fin_montee_bras not expected");
#endif
}

// the current state doesn't manage the event claps_replie, give it to the upper state
void MAE_MURPHY::AnyState::claps_replie(MAE_MURPHY & stm) {
    AnyState * st = _upper(stm);
  
    if (st != 0)
      st->claps_replie(stm);
#ifdef VERBOSE_STATE_MACHINE
    else
      puts("DEBUG : transition claps_replie not expected");
#endif
}

// the current state doesn't manage the event mission_distrib, give it to the upper state
void MAE_MURPHY::AnyState::mission_distrib(MAE_MURPHY & stm) {
    AnyState * st = _upper(stm);
  
    if (st != 0)
      st->mission_distrib(stm);
#ifdef VERBOSE_STATE_MACHINE
    else
      puts("DEBUG : transition mission_distrib not expected");
#endif
}

// the current state doesn't manage the event mission_claps, give it to the upper state
void MAE_MURPHY::AnyState::mission_claps(MAE_MURPHY & stm) {
    AnyState * st = _upper(stm);
  
    if (st != 0)
      st->mission_claps(stm);
#ifdef VERBOSE_STATE_MACHINE
    else
      puts("DEBUG : transition mission_claps not expected");
#endif
}

// the current state doesn't manage the event mission_depot_tour_depart, give it to the upper state
void MAE_MURPHY::AnyState::mission_depot_tour_depart(MAE_MURPHY & stm) {
    AnyState * st = _upper(stm);
  
    if (st != 0)
      st->mission_depot_tour_depart(stm);
#ifdef VERBOSE_STATE_MACHINE
    else
      puts("DEBUG : transition mission_depot_tour_depart not expected");
#endif
}

// the current state doesn't manage the event mission_zone_ennemie, give it to the upper state
void MAE_MURPHY::AnyState::mission_zone_ennemie(MAE_MURPHY & stm) {
    AnyState * st = _upper(stm);
  
    if (st != 0)
      st->mission_zone_ennemie(stm);
#ifdef VERBOSE_STATE_MACHINE
    else
      puts("DEBUG : transition mission_zone_ennemie not expected");
#endif
}

// the current state doesn't manage the event mission_chiage_balle, give it to the upper state
void MAE_MURPHY::AnyState::mission_chiage_balle(MAE_MURPHY & stm) {
    AnyState * st = _upper(stm);
  
    if (st != 0)
      st->mission_chiage_balle(stm);
#ifdef VERBOSE_STATE_MACHINE
    else
      puts("DEBUG : transition mission_chiage_balle not expected");
#endif
}

// the current state doesn't manage the event mission_zone_centrale, give it to the upper state
void MAE_MURPHY::AnyState::mission_zone_centrale(MAE_MURPHY & stm) {
    AnyState * st = _upper(stm);
  
    if (st != 0)
      st->mission_zone_centrale(stm);
#ifdef VERBOSE_STATE_MACHINE
    else
      puts("DEBUG : transition mission_zone_centrale not expected");
#endif
}

// the current state doesn't manage the event mission_depot_tour_estrade, give it to the upper state
void MAE_MURPHY::AnyState::mission_depot_tour_estrade(MAE_MURPHY & stm) {
    AnyState * st = _upper(stm);
  
    if (st != 0)
      st->mission_depot_tour_estrade(stm);
#ifdef VERBOSE_STATE_MACHINE
    else
      puts("DEBUG : transition mission_depot_tour_estrade not expected");
#endif
}

// the current state doesn't manage the event end_game, give it to the upper state
void MAE_MURPHY::AnyState::end_game(MAE_MURPHY & stm) {
    AnyState * st = _upper(stm);
  
    if (st != 0)
      st->end_game(stm);
#ifdef VERBOSE_STATE_MACHINE
    else
      puts("DEBUG : transition end_game not expected");
#endif
}

// the current state doesn't manage the event start_enleve, give it to the upper state
void MAE_MURPHY::AnyState::start_enleve(MAE_MURPHY & stm) {
    AnyState * st = _upper(stm);
  
    if (st != 0)
      st->start_enleve(stm);
#ifdef VERBOSE_STATE_MACHINE
    else
      puts("DEBUG : transition start_enleve not expected");
#endif
}

MAE_MURPHY::MAE_MURPHY_State::Initialisation_State::~Initialisation_State() {
}

// to manage the event start_mis
void MAE_MURPHY::MAE_MURPHY_State::Initialisation_State::start_mis(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._recalage_initial_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Recalage Initial");
#endif
      stm._mae_murphy_state._recalage_initial_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Initialisation_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Initialisation_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Initialisation");
#endif
  cout<<"ETAT INITIALISATION"<<endl;
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Initialisation_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state;
}

MAE_MURPHY::MAE_MURPHY_State::Game_Over_State::~Game_Over_State() {
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Game_Over_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Game_Over_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Game Over");
#endif
  cout<<"ETAT END OF GAME"<<endl;
  // arret de la base roulante et tout...
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Game_Over_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state;
}

MAE_MURPHY::MAE_MURPHY_State::startin_block_State::~startin_block_State() {
}

// to manage the event start_enleve
void MAE_MURPHY::MAE_MURPHY_State::startin_block_State::start_enleve(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu");
#endif
      stm._mae_murphy_state._jeu_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::startin_block_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::startin_block_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.startin' block");
#endif
  cout<<"MURPHY IS READY, PULL THE TRIGGER !"<<endl;
  serialPrintf(master->getPortSerie(),"E1 \n"); // activation de l'evitement
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::startin_block_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state;
}

MAE_MURPHY::MAE_MURPHY_State::Recalage_Initial_State::Recule_State::~Recule_State() {
}

// to manage the event blocage
void MAE_MURPHY::MAE_MURPHY_State::Recalage_Initial_State::Recule_State::blocage(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._recalage_initial_state._set_x_y_cap_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Recalage Initial.set X Y CAP");
#endif
      stm._mae_murphy_state._recalage_initial_state._set_x_y_cap_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Recalage_Initial_State::Recule_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Recalage_Initial_State::Recule_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Recalage Initial.Recule");
#endif
  cout<<"RECULE"<<endl;
  // recule (recalage au cul)
  serialPrintf(master->getPortSerie(),"E0 \n"); // desactivation de l'evitement
  serialPrintf(master->getPortSerie(),"S0 0 0 0 \n");
  serialPrintf(master->getPortSerie(),"S2 \n");
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Recalage_Initial_State::Recule_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._recalage_initial_state;
}

MAE_MURPHY::MAE_MURPHY_State::Recalage_Initial_State::avance_State::~avance_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Recalage_Initial_State::avance_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._recalage_initial_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Recalage Initial");
#endif
      stm._mae_murphy_state._recalage_initial_state._exit27(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Recalage_Initial_State::avance_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Recalage_Initial_State::avance_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Recalage Initial.avance");
#endif
  // pour laisser de la place à coop'r
  cout<<"avance de 200 mm "<<endl;
  serialPrintf(master->getPortSerie(),"S4 250 \n");
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Recalage_Initial_State::avance_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._recalage_initial_state;
}

MAE_MURPHY::MAE_MURPHY_State::Recalage_Initial_State::coup_de_patte_cote_escalier_pour_confirmer_le_sens_State::~coup_de_patte_cote_escalier_pour_confirmer_le_sens_State() {
}

bool MAE_MURPHY::MAE_MURPHY_State::Recalage_Initial_State::coup_de_patte_cote_escalier_pour_confirmer_le_sens_State::_completion(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._recalage_initial_state._avance_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Recalage Initial.avance");
#endif
      stm._mae_murphy_state._recalage_initial_state._avance_state.create(stm);
      return (bool) 1;
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Recalage_Initial_State::coup_de_patte_cote_escalier_pour_confirmer_le_sens_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
  	_completion(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Recalage_Initial_State::coup_de_patte_cote_escalier_pour_confirmer_le_sens_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Recalage Initial.coup de patte cote escalier pour confirmer le sens");
#endif
  if(master->is_Jaune()){
  // coup de patte cote gauche
  serialPrintf(master->getPortSerie(),"C2 \n");
  }
  if(master->is_Vert()){
  // coup de patte cote droit
  serialPrintf(master->getPortSerie(),"C0 \n");
  }
  //master->set_time_out(2000);
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Recalage_Initial_State::coup_de_patte_cote_escalier_pour_confirmer_le_sens_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._recalage_initial_state;
}

MAE_MURPHY::MAE_MURPHY_State::Recalage_Initial_State::set_X_Y_CAP_State::~set_X_Y_CAP_State() {
}

// to manage the event time_out
void MAE_MURPHY::MAE_MURPHY_State::Recalage_Initial_State::set_X_Y_CAP_State::time_out(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._recalage_initial_state._coup_de_patte_cote_escalier_pour_confirmer_le_sens_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Recalage Initial.coup de patte cote escalier pour confirmer le sens");
#endif
      stm._mae_murphy_state._recalage_initial_state._coup_de_patte_cote_escalier_pour_confirmer_le_sens_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Recalage_Initial_State::set_X_Y_CAP_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Recalage_Initial_State::set_X_Y_CAP_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Recalage Initial.set X Y CAP");
#endif
  if(master->is_Jaune()){
  	cout<<"SET X Y CAP ORIGIN, COULEUR JAUNE"<<endl;
  	// X = -1500 + 70 +96 = -1334
  	// terrain, bordure, robot (axe de rotation)
  	serialPrintf(master->getPortSerie(),"S0 -1334 996 0 \n");
  }
  if(master->is_Vert()){
  	cout<<"SET X Y CAP ORIGIN, COULEUR VERT"<<endl;
  	serialPrintf(master->getPortSerie(),"S0 1334 996 180 \n");
  }
  master->set_time_out(300);
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Recalage_Initial_State::set_X_Y_CAP_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._recalage_initial_state;
}

MAE_MURPHY::MAE_MURPHY_State::Recalage_Initial_State::~Recalage_Initial_State() {
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Recalage_Initial_State::create(MAE_MURPHY & stm) {
    _doentry(stm);
    {
      stm._set_currentState(stm._mae_murphy_state._recalage_initial_state._recule_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Recalage Initial.Recule");
#endif
      stm._mae_murphy_state._recalage_initial_state._recule_state.create(stm);
    }
}

// to manage the exit point 'sortie recalage', defined because probably shared
void MAE_MURPHY::MAE_MURPHY_State::Recalage_Initial_State::_exit27(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._startin_block_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.startin' block");
#endif
      stm._mae_murphy_state._startin_block_state.create(stm);
    }
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Recalage_Initial_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Recalage Initial");
#endif
  cout<<"ETAT RECALAGE INITIAL"<<endl;
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Recalage_Initial_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state;
}

MAE_MURPHY::MAE_MURPHY_State::Evitement_State::faire_des_maneuvre_State::~faire_des_maneuvre_State() {
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Evitement_State::faire_des_maneuvre_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Evitement_State::faire_des_maneuvre_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Evitement.faire des maneuvre");
#endif
  // BF cap 90 ou -90 ou 180
  // etat pipo d'evitement, le tout ce passe dans la decision dans le super etat Game
  // sinon un petit timer...
  // fermeture des pinces 
  // et capot
  serialPrintf(master->getPortSerie(),"P3 \n");
  serialPrintf(master->getPortSerie(),"D2 \n");
  serialPrintf(master->getPortSerie(),"G2 \n");
  master->set_time_out(50);
  cout<<"on evite"<<endl;
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Evitement_State::faire_des_maneuvre_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._evitement_state;
}

// to manage the event time_out
void MAE_MURPHY::MAE_MURPHY_State::Evitement_State::faire_des_maneuvre_State::time_out(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._evitement_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Evitement");
#endif
      stm._mae_murphy_state._evitement_state._exit26(stm);
    }
}

MAE_MURPHY::MAE_MURPHY_State::Evitement_State::~Evitement_State() {
}

// to manage the exit point 'sortie evitement', defined because probably shared
void MAE_MURPHY::MAE_MURPHY_State::Evitement_State::_exit26(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu");
#endif
      stm._mae_murphy_state._jeu_state.create(stm);
    }
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Evitement_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Evitement");
#endif
  cout<<"ETAT EVITEMENT"<<endl;
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Evitement_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state;
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Evitement_State::create(MAE_MURPHY & stm) {
    _doentry(stm);
    {
      stm._set_currentState(stm._mae_murphy_state._evitement_state._faire_des_maneuvre_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Evitement.faire des maneuvre");
#endif
      stm._mae_murphy_state._evitement_state._faire_des_maneuvre_state.create(stm);
    }
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::waypoint_init_State::BF_cap_to_mission_State::~BF_cap_to_mission_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::waypoint_init_State::BF_cap_to_mission_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state._waypoint_init_state._bf_droite_to_mission_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission depot tour estrade.waypoint init.BF droite to mission");
#endif
      stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state._waypoint_init_state._bf_droite_to_mission_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::waypoint_init_State::BF_cap_to_mission_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::waypoint_init_State::BF_cap_to_mission_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission depot tour estrade.waypoint init.BF cap to mission");
#endif
  // BCAP
  string ordre;
  ordre = "S3 " + master->get_gestionnaire()->get_cap_to_mission_str() + " \n";
  const char* ordre_c = ordre.c_str();
  serialPrintf(master->getPortSerie(),"S7 1 \n"); 	// vitesse moyenn
  serialPrintf(master->getPortSerie(),ordre_c);
  cout<<"ORIENTATION VERS MISSION : "<<ordre<<endl;
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::waypoint_init_State::BF_cap_to_mission_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state._waypoint_init_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::waypoint_init_State::BF_cap_mission_State::~BF_cap_mission_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::waypoint_init_State::BF_cap_mission_State::assFini(MAE_MURPHY & stm) {
    {
      stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state._waypoint_init_state._bf_cap_mission_state._doexit(stm);
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state._waypoint_init_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission depot tour estrade.waypoint init");
#endif
      stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state._waypoint_init_state._exit1(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::waypoint_init_State::BF_cap_mission_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::waypoint_init_State::BF_cap_mission_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission depot tour estrade.waypoint init.BF cap mission");
#endif
  // BF Droite vers objectif
  string ordre;
  ordre = "S3 " 
  	+ master->get_gestionnaire()->get_cap_mission_str() 
  	+ " \n";
  const char* ordre_c = ordre.c_str();
  serialPrintf(master->getPortSerie(),ordre_c); 
  cout<<"ORIENTATION VERS MISSION : "<<ordre<<endl;
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::waypoint_init_State::BF_cap_mission_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state._waypoint_init_state;
}

// perform the 'exit behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::waypoint_init_State::BF_cap_mission_State::_doexit(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute exit behavior of .MAE_MURPHY.Jeu.mission depot tour estrade.waypoint init.BF cap mission");
#endif
  serialPrintf(master->getPortSerie(),"S7 0 \n"); 	// vitesse moyenne
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::waypoint_init_State::BF_droite_to_mission_State::~BF_droite_to_mission_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::waypoint_init_State::BF_droite_to_mission_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state._waypoint_init_state._bf_cap_mission_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission depot tour estrade.waypoint init.BF cap mission");
#endif
      stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state._waypoint_init_state._bf_cap_mission_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::waypoint_init_State::BF_droite_to_mission_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::waypoint_init_State::BF_droite_to_mission_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission depot tour estrade.waypoint init.BF droite to mission");
#endif
  // BF Droite vers objectif
  string ordre;
  ordre = "S5 "
  	+ master->get_gestionnaire()->get_x_mission_str() 
  	+ " "
  	+ master->get_gestionnaire()->get_y_mission_str() 
  	+ " "
  	+ master->get_gestionnaire()->get_cap_to_mission_str() 
  	+ " \n";
  const char* ordre_c = ordre.c_str();
  serialPrintf(master->getPortSerie(),ordre_c); 
  cout<<"BF droite vers MISSION : "<<ordre<<endl;
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::waypoint_init_State::BF_droite_to_mission_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state._waypoint_init_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::waypoint_init_State::~waypoint_init_State() {
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::waypoint_init_State::create(MAE_MURPHY & stm) {
    _doentry(stm);
    {
      if (master->get_gestionnaire_mission()->is_mission_far()) {
        stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state._waypoint_init_state._bf_cap_to_mission_state);
#ifdef VERBOSE_STATE_MACHINE
        puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission depot tour estrade.waypoint init.BF cap to mission");
#endif
        stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state._waypoint_init_state._bf_cap_to_mission_state.create(stm);
      }
      else if (!master->get_gestionnaire_mission()->is_mission_far()) {
        stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state._waypoint_init_state._bf_cap_mission_state);
#ifdef VERBOSE_STATE_MACHINE
        puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission depot tour estrade.waypoint init.BF cap mission");
#endif
        stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state._waypoint_init_state._bf_cap_mission_state.create(stm);
      }
    }
}

// to manage the exit point 'sortie', defined because probably shared
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::waypoint_init_State::_exit1(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state._preparation_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission depot tour estrade.preparation");
#endif
      stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state._preparation_state.create(stm);
    }
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::waypoint_init_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission depot tour estrade.waypoint init");
#endif
  // rejoindre un point initial
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::waypoint_init_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::BF_Cap_State::~BF_Cap_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::BF_Cap_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission depot tour estrade");
#endif
      stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state._exit2(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::BF_Cap_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::BF_Cap_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission depot tour estrade.BF Cap");
#endif
  cout<<"depot estrade : demi tour"<<endl;
  serialPrintf(master->getPortSerie(),"S3 90 \n");
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::BF_Cap_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::replis_des_pinces_State::~replis_des_pinces_State() {
}

// to manage the event pince_range
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::replis_des_pinces_State::pince_range(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state._bf_cap_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission depot tour estrade.BF Cap");
#endif
      stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state._bf_cap_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::replis_des_pinces_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::replis_des_pinces_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission depot tour estrade.replis des pinces");
#endif
  cout<<"depot estrade : replis des pinces"<<endl;
  // replis des pinces
  serialPrintf(master->getPortSerie(),"G6 \n");
  serialPrintf(master->getPortSerie(),"D6 \n");
  master->get_gestionnaire_mission()->get_mission_depot_tour_estrade()->mission_remplie();
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::replis_des_pinces_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::set_Y_CAP_State::~set_Y_CAP_State() {
}

bool MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::set_Y_CAP_State::_completion(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state._depot_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission depot tour estrade.depot");
#endif
      stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state._depot_state.create(stm);
      return (bool) 1;
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::set_Y_CAP_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
  	_completion(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::set_Y_CAP_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission depot tour estrade.set Y CAP");
#endif
  cout<<"depot estrade : set Y CAP"<<endl;
  // recup les coords du master avec le S1 (pour le x)
  serialPrintf(master->getPortSerie(),"S0 -1 200 -90 \n");
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::set_Y_CAP_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::avance_State::~avance_State() {
}

// to manage the event blocage
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::avance_State::blocage(MAE_MURPHY & stm) {
    {
      stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state._avance_state._doexit(stm);
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state._set_y_cap_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission depot tour estrade.set Y CAP");
#endif
      stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state._set_y_cap_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::avance_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::avance_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission depot tour estrade.avance");
#endif
  cout<<"depot estrade : avance jusq'au blocage"<<endl;
  // jusqu'au blocage
  serialPrintf(master->getPortSerie(),"S4 350 \n");
}

// perform the 'exit behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::avance_State::_doexit(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute exit behavior of .MAE_MURPHY.Jeu.mission depot tour estrade.avance");
#endif
  serialPrintf(master->getPortSerie(),"S1 \n");
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::avance_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::preparation_State::~preparation_State() {
}

// to manage the event pince_ready_to_drop
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::preparation_State::pince_ready_to_drop(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state._avance_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission depot tour estrade.avance");
#endif
      stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state._avance_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::preparation_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::preparation_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission depot tour estrade.preparation");
#endif
  cout<<"depot estrade : prepare la pile"<<endl;
  // preparation des piles a poser
  if(master->is_Jaune()){
  	serialPrintf(master->getPortSerie(),"G8 \n"); // objectif de pose sur estrade
  	serialPrintf(master->getPortSerie(),"G4 \n"); // preparation de la pose
  	if(master->get_gestionnaire_mission()->get_mission_depot_tour_estrade()->is_depot_double())
  	{
  		serialPrintf(master->getPortSerie(),"D8 \n");
  		serialPrintf(master->getPortSerie(),"D4 \n");
  	}
  }
  if(master->is_Vert()){
  	serialPrintf(master->getPortSerie(),"D8 \n");
  	serialPrintf(master->getPortSerie(),"D4 \n");
  	if(master->get_gestionnaire_mission()->get_mission_depot_tour_estrade()->is_depot_double())
  	{
  		serialPrintf(master->getPortSerie(),"G8 \n");
  		serialPrintf(master->getPortSerie(),"G4 \n");
  	}
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::preparation_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::recule_doucement_State::~recule_doucement_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::recule_doucement_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state._replis_des_pinces_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission depot tour estrade.replis des pinces");
#endif
      stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state._replis_des_pinces_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::recule_doucement_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::recule_doucement_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission depot tour estrade.recule doucement");
#endif
  cout<<"depot estrade : recule doucement"<<endl;
  serialPrintf(master->getPortSerie(),"S4 -250 \n");
  
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::recule_doucement_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state;
}

// to manage the event blocage
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::recule_doucement_State::blocage(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state._replis_des_pinces_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission depot tour estrade.replis des pinces");
#endif
      stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state._replis_des_pinces_state.create(stm);
    }
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::depot_State::~depot_State() {
}

// to manage the event pince_lache
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::depot_State::pince_lache(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state._recule_doucement_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission depot tour estrade.recule doucement");
#endif
      stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state._recule_doucement_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::depot_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::depot_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission depot tour estrade.depot");
#endif
  cout<<"depot estrade : pose de pile"<<endl;
  // preparation des piles a poser
  if(master->is_Jaune()){
  	serialPrintf(master->getPortSerie(),"G5 \n"); // lache
  	if(master->get_gestionnaire_mission()->get_mission_depot_tour_estrade()->is_depot_double())
  	{
  		serialPrintf(master->getPortSerie(),"D5 \n");
  	}
  }
  if(master->is_Vert()){
  	serialPrintf(master->getPortSerie(),"D5 \n");
  	if(master->get_gestionnaire_mission()->get_mission_depot_tour_estrade()->is_depot_double())
  	{
  		serialPrintf(master->getPortSerie(),"G5 \n");
  	}
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::depot_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::~mission_depot_tour_estrade_State() {
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::create(MAE_MURPHY & stm) {
    _doentry(stm);
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state._waypoint_init_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission depot tour estrade.waypoint init");
#endif
      stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state._waypoint_init_state.create(stm);
    }
}

// to manage the exit point 'sortie', defined because probably shared
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::_exit2(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._decision_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.decision");
#endif
      stm._mae_murphy_state._jeu_state._decision_state.create(stm);
    }
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission depot tour estrade");
#endif
  // depose une ou plusieurs pile sur l'estrade
  // normalement une seule sinon risque de faire tomber celle adverse
  cout<<"MISSION DEPOT TOUR ESTRADE"<<endl;
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::decision_State::~decision_State() {
}

// to manage the event mission_distrib
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::decision_State::mission_distrib(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state.create(stm);
    }
}

// to manage the event mission_claps
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::decision_State::mission_claps(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps");
#endif
      stm._mae_murphy_state._jeu_state._mission_claps_state.create(stm);
    }
}

// to manage the event mission_depot_tour_depart
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::decision_State::mission_depot_tour_depart(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission depot de tour zone depart");
#endif
      stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state.create(stm);
    }
}

// to manage the event mission_zone_ennemie
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::decision_State::mission_zone_ennemie(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission zone ennemie");
#endif
      stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state.create(stm);
    }
}

// to manage the event mission_chiage_balle
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::decision_State::mission_chiage_balle(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission attrap balle et chiage");
#endif
      stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state.create(stm);
    }
}

// to manage the event mission_zone_centrale
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::decision_State::mission_zone_centrale(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission rush zone centrale");
#endif
      stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state.create(stm);
    }
}

// to manage the event mission_depot_tour_estrade
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::decision_State::mission_depot_tour_estrade(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission depot tour estrade");
#endif
      stm._mae_murphy_state._jeu_state._mission_depot_tour_estrade_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::decision_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::decision_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.decision");
#endif
  cout<<"DECISION DE MISSION"<<endl;
  master->get_gestionnaire_mission()->decision_mission();
  
  // decision du gestionnaire de mission
  // consulte les mission restante à faire et dans quel ordre
  // etat de depart apres sortie d'evitement ...
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::decision_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::waypoint_initial_State::cap_to_mission_State::~cap_to_mission_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::waypoint_initial_State::cap_to_mission_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._waypoint_initial_state._bf_droite_to_mission_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission zone ennemie.waypoint initial.BF droite to mission");
#endif
      stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._waypoint_initial_state._bf_droite_to_mission_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::waypoint_initial_State::cap_to_mission_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::waypoint_initial_State::cap_to_mission_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission zone ennemie.waypoint initial.cap to mission");
#endif
  serialPrintf(master->getPortSerie(),"S7 1 \n"); 	// vitesse moyenne
  // BCAP
  string ordre;
  ordre = "S3 " + master->get_gestionnaire()->get_cap_to_mission_str() + " \n";
  const char* ordre_c = ordre.c_str();
  serialPrintf(master->getPortSerie(),ordre_c);
  cout<<"ORIENTATION VERS MISSION : "<<ordre<<endl;
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::waypoint_initial_State::cap_to_mission_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._waypoint_initial_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::waypoint_initial_State::cap_mission_State::~cap_mission_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::waypoint_initial_State::cap_mission_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._waypoint_initial_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission zone ennemie.waypoint initial");
#endif
      stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._waypoint_initial_state._exit21(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::waypoint_initial_State::cap_mission_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::waypoint_initial_State::cap_mission_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission zone ennemie.waypoint initial.cap mission");
#endif
  // BF Droite vers objectif
  string ordre;
  ordre = "S3 " 
  	+ master->get_gestionnaire()->get_cap_mission_str() 
  	+ " \n";
  const char* ordre_c = ordre.c_str();
  serialPrintf(master->getPortSerie(),ordre_c); 
  cout<<"ORIENTATION VERS MISSION : "<<ordre<<endl;
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::waypoint_initial_State::cap_mission_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._waypoint_initial_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::waypoint_initial_State::BF_droite_to_mission_State::~BF_droite_to_mission_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::waypoint_initial_State::BF_droite_to_mission_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._waypoint_initial_state._cap_mission_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission zone ennemie.waypoint initial.cap mission");
#endif
      stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._waypoint_initial_state._cap_mission_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::waypoint_initial_State::BF_droite_to_mission_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::waypoint_initial_State::BF_droite_to_mission_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission zone ennemie.waypoint initial.BF droite to mission");
#endif
  // BF Droite vers objectif
  string ordre;
  ordre = "S5 "
  	+ master->get_gestionnaire()->get_x_mission_str() 
  	+ " "
  	+ master->get_gestionnaire()->get_y_mission_str() 
  	+ " "
  	+ master->get_gestionnaire()->get_cap_to_mission_str() 
  	+ " \n";
  const char* ordre_c = ordre.c_str();
  serialPrintf(master->getPortSerie(),ordre_c); 
  cout<<"BF droite vers MISSION : "<<ordre<<endl;
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::waypoint_initial_State::BF_droite_to_mission_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._waypoint_initial_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::waypoint_initial_State::~waypoint_initial_State() {
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::waypoint_initial_State::create(MAE_MURPHY & stm) {
    _doentry(stm);
    {
      if (master->get_gestionnaire_mission()->is_mission_far()) {
        stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._waypoint_initial_state._cap_to_mission_state);
#ifdef VERBOSE_STATE_MACHINE
        puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission zone ennemie.waypoint initial.cap to mission");
#endif
        stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._waypoint_initial_state._cap_to_mission_state.create(stm);
      }
      else if (!master->get_gestionnaire_mission()->is_mission_far()) {
        stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._waypoint_initial_state._cap_mission_state);
#ifdef VERBOSE_STATE_MACHINE
        puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission zone ennemie.waypoint initial.cap mission");
#endif
        stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._waypoint_initial_state._cap_mission_state.create(stm);
      }
    }
}

// to manage the exit point 'sortie', defined because probably shared
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::waypoint_initial_State::_exit21(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission zone ennemie");
#endif
      if (!master->get_gestionnaire()->get_mission_zone_ennemie()->is_claps_done()) {
        stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._claps_central_state);
#ifdef VERBOSE_STATE_MACHINE
        puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission zone ennemie.claps central");
#endif
        stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._claps_central_state.create(stm);
      }
      else if (master->get_gestionnaire()->get_mission_zone_ennemie()->is_claps_done()) {
        if (master->get_gestionnaire()->get_mission_zone_ennemie()->is_depot_gobelet_done()) {
          stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._faire_chier_en_zizagant_state);
#ifdef VERBOSE_STATE_MACHINE
          puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission zone ennemie.faire chier en zizagant");
#endif
          stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._faire_chier_en_zizagant_state.create(stm);
        }
        else if (!master->get_gestionnaire()->get_mission_zone_ennemie()->is_depot_gobelet_done()) {
          if (!master->get_gestionnaire()->get_element_robot()->gobelet_present()) {
            stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._faire_chier_en_zizagant_state);
#ifdef VERBOSE_STATE_MACHINE
            puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission zone ennemie.faire chier en zizagant");
#endif
            stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._faire_chier_en_zizagant_state.create(stm);
          }
          else if (master->get_gestionnaire()->get_element_robot()->gobelet_present()) {
            stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._depot_gobelet_state);
#ifdef VERBOSE_STATE_MACHINE
            puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission zone ennemie.depot gobelet");
#endif
            stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._depot_gobelet_state.create(stm);
          }
        }
      }
    }
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::waypoint_initial_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission zone ennemie.waypoint initial");
#endif
  // en BF droite
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::waypoint_initial_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::to_escalier_State::~to_escalier_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::to_escalier_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._faire_chier_en_zizagant_state._to_estrade_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission zone ennemie.faire chier en zizagant.to estrade");
#endif
      stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._faire_chier_en_zizagant_state._to_estrade_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::to_escalier_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::to_escalier_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission zone ennemie.faire chier en zizagant.to escalier");
#endif
  cout<<"chieur : to escalier"<<endl;
  if(master->is_Jaune()){
  // BF droite sur le cine
  serialPrintf(master->getPortSerie(),"S5 170 919 180 \n");
  }
  if(master->is_Vert()){
  serialPrintf(master->getPortSerie(),"S5 -170 919 0 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::to_escalier_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._faire_chier_en_zizagant_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::chieur_plus_State::~chieur_plus_State() {
}

bool MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::chieur_plus_State::_completion(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._faire_chier_en_zizagant_state._to_escalier_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission zone ennemie.faire chier en zizagant.to escalier");
#endif
      stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._faire_chier_en_zizagant_state._to_escalier_state.create(stm);
      return (bool) 1;
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::chieur_plus_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
  	_completion(stm);
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::chieur_plus_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._faire_chier_en_zizagant_state;
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::chieur_plus_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission zone ennemie.faire chier en zizagant.chieur plus");
#endif
  cout<<"mode chieur : normal :)"<<endl;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::chieur_faible_State::~chieur_faible_State() {
}

bool MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::chieur_faible_State::_completion(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._faire_chier_en_zizagant_state._to_escalier_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission zone ennemie.faire chier en zizagant.to escalier");
#endif
      stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._faire_chier_en_zizagant_state._to_escalier_state.create(stm);
      return (bool) 1;
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::chieur_faible_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
  	_completion(stm);
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::chieur_faible_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._faire_chier_en_zizagant_state;
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::chieur_faible_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission zone ennemie.faire chier en zizagant.chieur faible");
#endif
  cout<<"mode chieur : faible"<<endl;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::chieur_stop_State::~chieur_stop_State() {
}

bool MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::chieur_stop_State::_completion(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._faire_chier_en_zizagant_state._to_escalier_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission zone ennemie.faire chier en zizagant.to escalier");
#endif
      stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._faire_chier_en_zizagant_state._to_escalier_state.create(stm);
      return (bool) 1;
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::chieur_stop_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
  	_completion(stm);
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::chieur_stop_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._faire_chier_en_zizagant_state;
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::chieur_stop_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission zone ennemie.faire chier en zizagant.chieur stop");
#endif
  cout<<"mode chieur : stop"<<endl;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::deboit_les_cines_adverses_State::~deboit_les_cines_adverses_State() {
}

bool MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::deboit_les_cines_adverses_State::_completion(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._faire_chier_en_zizagant_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission zone ennemie.faire chier en zizagant");
#endif
      stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._faire_chier_en_zizagant_state._exit24(stm);
      return (bool) 1;
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::deboit_les_cines_adverses_State::create(MAE_MURPHY & stm) {
  	_completion(stm);
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::deboit_les_cines_adverses_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._faire_chier_en_zizagant_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::to_estrade_State::~to_estrade_State() {
}

bool MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::to_estrade_State::_completion(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._faire_chier_en_zizagant_state._deboit_les_cines_adverses_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission zone ennemie.faire chier en zizagant.deboit les cines adverses");
#endif
      stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._faire_chier_en_zizagant_state._deboit_les_cines_adverses_state.create(stm);
      return (bool) 1;
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::to_estrade_State::create(MAE_MURPHY & stm) {
  	_completion(stm);
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::to_estrade_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._faire_chier_en_zizagant_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::~faire_chier_en_zizagant_State() {
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::create(MAE_MURPHY & stm) {
    _doentry(stm);
    {
      if (master->get_gestionnaire()->get_mission_zone_ennemie()->mode_chieur()==0) {
        stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._faire_chier_en_zizagant_state._chieur_stop_state);
#ifdef VERBOSE_STATE_MACHINE
        puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission zone ennemie.faire chier en zizagant.chieur stop");
#endif
        stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._faire_chier_en_zizagant_state._chieur_stop_state.create(stm);
      }
      else if (master->get_gestionnaire()->get_mission_zone_ennemie()->mode_chieur()==1) {
        stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._faire_chier_en_zizagant_state._chieur_faible_state);
#ifdef VERBOSE_STATE_MACHINE
        puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission zone ennemie.faire chier en zizagant.chieur faible");
#endif
        stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._faire_chier_en_zizagant_state._chieur_faible_state.create(stm);
      }
      else if (master->get_gestionnaire()->get_mission_zone_ennemie()->mode_chieur()==2) {
        stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._faire_chier_en_zizagant_state._chieur_plus_state);
#ifdef VERBOSE_STATE_MACHINE
        puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission zone ennemie.faire chier en zizagant.chieur plus");
#endif
        stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._faire_chier_en_zizagant_state._chieur_plus_state.create(stm);
      }
    }
}

// to manage the exit point 'sortie', defined because probably shared
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::_exit24(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission zone ennemie");
#endif
      stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._exit25(stm);
    }
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission zone ennemie.faire chier en zizagant");
#endif
  // mission qui n'a pas de prix
  // simplement rejoindre la sortie
  
  // mettre un choix de point chieur à atteindre
  master->get_gestionnaire()->get_mission_zone_ennemie()->mission_remplie();
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::depot_gobelet_State::BF_droite_sur_le_cine_State::~BF_droite_sur_le_cine_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::depot_gobelet_State::BF_droite_sur_le_cine_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._depot_gobelet_state._bf_cap_vers_centre_de_la_table_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission zone ennemie.depot gobelet.BF CAP vers centre de la table");
#endif
      stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._depot_gobelet_state._bf_cap_vers_centre_de_la_table_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::depot_gobelet_State::BF_droite_sur_le_cine_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::depot_gobelet_State::BF_droite_sur_le_cine_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission zone ennemie.depot gobelet.BF droite sur le cine");
#endif
  cout<<"gobelet : BF droite sur le cine"<<endl;
  if(master->is_Jaune()){
  // BF droite sur le cine
  serialPrintf(master->getPortSerie(),"S5 1255 531 0 \n");
  }
  if(master->is_Vert()){
  serialPrintf(master->getPortSerie(),"S5 -1255 531 180 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::depot_gobelet_State::BF_droite_sur_le_cine_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._depot_gobelet_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::depot_gobelet_State::fermeture_capot_State::~fermeture_capot_State() {
}

bool MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::depot_gobelet_State::fermeture_capot_State::_completion(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._depot_gobelet_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission zone ennemie.depot gobelet");
#endif
      stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._depot_gobelet_state._exit23(stm);
      return (bool) 1;
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::depot_gobelet_State::fermeture_capot_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
  	_completion(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::depot_gobelet_State::fermeture_capot_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission zone ennemie.depot gobelet.fermeture capot");
#endif
  cout<<"claps central : fermeture du capot"<<endl;
  serialPrintf(master->getPortSerie(),"P3 \n");
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::depot_gobelet_State::fermeture_capot_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._depot_gobelet_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::depot_gobelet_State::avance_State::~avance_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::depot_gobelet_State::avance_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._depot_gobelet_state._fermeture_capot_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission zone ennemie.depot gobelet.fermeture capot");
#endif
      stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._depot_gobelet_state._fermeture_capot_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::depot_gobelet_State::avance_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::depot_gobelet_State::avance_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission zone ennemie.depot gobelet.avance");
#endif
  cout<<"claps central : degagement"<<endl;
  serialPrintf(master->getPortSerie(),"S4 250 \n");
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::depot_gobelet_State::avance_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._depot_gobelet_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::depot_gobelet_State::ouverture_capot_State::~ouverture_capot_State() {
}

// to manage the event time_out
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::depot_gobelet_State::ouverture_capot_State::time_out(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._depot_gobelet_state._avance_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission zone ennemie.depot gobelet.avance");
#endif
      stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._depot_gobelet_state._avance_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::depot_gobelet_State::ouverture_capot_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::depot_gobelet_State::ouverture_capot_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission zone ennemie.depot gobelet.ouverture capot");
#endif
  cout<<"claps central : drop du gobelet"<<endl;
  serialPrintf(master->getPortSerie(),"P6 \n");
  master->set_time_out(300);
  master->get_gestionnaire()->get_mission_zone_ennemie()->depot_gobelet_done();
  master->get_gestionnaire()->get_element_robot()->gobelet_relache();
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::depot_gobelet_State::ouverture_capot_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._depot_gobelet_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::depot_gobelet_State::BF_CAP_vers_centre_de_la_table_State::~BF_CAP_vers_centre_de_la_table_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::depot_gobelet_State::BF_CAP_vers_centre_de_la_table_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._depot_gobelet_state._ouverture_capot_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission zone ennemie.depot gobelet.ouverture capot");
#endif
      stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._depot_gobelet_state._ouverture_capot_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::depot_gobelet_State::BF_CAP_vers_centre_de_la_table_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::depot_gobelet_State::BF_CAP_vers_centre_de_la_table_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission zone ennemie.depot gobelet.BF CAP vers centre de la table");
#endif
  cout<<"claps central : demi tour pour sortie"<<endl;
  if(master->is_Jaune()){
  // BF cap centre
  serialPrintf(master->getPortSerie(),"S3 180 \n");
  }
  if(master->is_Vert()){
  serialPrintf(master->getPortSerie(),"S3 0 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::depot_gobelet_State::BF_CAP_vers_centre_de_la_table_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._depot_gobelet_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::depot_gobelet_State::~depot_gobelet_State() {
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::depot_gobelet_State::create(MAE_MURPHY & stm) {
    _doentry(stm);
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._depot_gobelet_state._bf_droite_sur_le_cine_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission zone ennemie.depot gobelet.BF droite sur le cine");
#endif
      stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._depot_gobelet_state._bf_droite_sur_le_cine_state.create(stm);
    }
}

// to manage the exit point 'sortie', defined because probably shared
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::depot_gobelet_State::_exit23(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._faire_chier_en_zizagant_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission zone ennemie.faire chier en zizagant");
#endif
      stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._faire_chier_en_zizagant_state.create(stm);
    }
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::depot_gobelet_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission zone ennemie.depot gobelet");
#endif
  // mission à 4 pts
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::depot_gobelet_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::claps_central_State::BF_droite_State::~BF_droite_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::claps_central_State::BF_droite_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._claps_central_state._bf_cap_vers_estrade_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission zone ennemie.claps central.BF cap vers estrade");
#endif
      stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._claps_central_state._bf_cap_vers_estrade_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::claps_central_State::BF_droite_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::claps_central_State::BF_droite_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission zone ennemie.claps central.BF droite");
#endif
  cout<<"claps central : BF droite dessus"<<endl;
  if(master->is_Jaune()){
  // BF droite sur le claps
  serialPrintf(master->getPortSerie(),"S5 977 260 -60 \n");
  }
  if(master->is_Vert()){
  serialPrintf(master->getPortSerie(),"S5 -977 260 -120 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::claps_central_State::BF_droite_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._claps_central_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::claps_central_State::BF_cap_vers_estrade_State::~BF_cap_vers_estrade_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::claps_central_State::BF_cap_vers_estrade_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._claps_central_state._ouverture_claps_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission zone ennemie.claps central.ouverture claps");
#endif
      stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._claps_central_state._ouverture_claps_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::claps_central_State::BF_cap_vers_estrade_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::claps_central_State::BF_cap_vers_estrade_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission zone ennemie.claps central.BF cap vers estrade");
#endif
  cout<<"claps central : BF cap/rotation sur claps"<<endl;
  if(master->is_Jaune()){
  // BF droite sur le claps
  serialPrintf(master->getPortSerie(),"S3 180 \n");
  }
  if(master->is_Vert()){
  serialPrintf(master->getPortSerie(),"S3 0 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::claps_central_State::BF_cap_vers_estrade_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._claps_central_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::claps_central_State::BF_cap_to_cine_State::~BF_cap_to_cine_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::claps_central_State::BF_cap_to_cine_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._claps_central_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission zone ennemie.claps central");
#endif
      stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._claps_central_state._exit22(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::claps_central_State::BF_cap_to_cine_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::claps_central_State::BF_cap_to_cine_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission zone ennemie.claps central.BF cap to cine");
#endif
  cout<<"claps central : BF cap pour avoir le claps au dos"<<endl;
  if(master->is_Jaune()){
  // BF cap sur le cine adverse
  serialPrintf(master->getPortSerie(),"S3 80 \n");
  }
  if(master->is_Vert()){
  serialPrintf(master->getPortSerie(),"S3 110 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::claps_central_State::BF_cap_to_cine_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._claps_central_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::claps_central_State::ouverture_claps_State::~ouverture_claps_State() {
}

// to manage the event claps_replie
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::claps_central_State::ouverture_claps_State::claps_replie(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._claps_central_state._bf_cap_to_cine_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission zone ennemie.claps central.BF cap to cine");
#endif
      stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._claps_central_state._bf_cap_to_cine_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::claps_central_State::ouverture_claps_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::claps_central_State::ouverture_claps_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission zone ennemie.claps central.ouverture claps");
#endif
  cout<<"claps central : deboit le claps"<<endl;
  if(master->is_Jaune()){
  // ouverture claps cote bordure (jaune gauche)
  serialPrintf(master->getPortSerie(),"C2 \n");
  }
  if(master->is_Vert()){
  serialPrintf(master->getPortSerie(),"C0 \n");
  }
  master->get_gestionnaire()->get_mission_zone_ennemie()->claps_done();
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::claps_central_State::ouverture_claps_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._claps_central_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::claps_central_State::~claps_central_State() {
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::claps_central_State::create(MAE_MURPHY & stm) {
    _doentry(stm);
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._claps_central_state._bf_droite_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission zone ennemie.claps central.BF droite");
#endif
      stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._claps_central_state._bf_droite_state.create(stm);
    }
}

// to manage the exit point 'sortie', defined because probably shared
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::claps_central_State::_exit22(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission zone ennemie");
#endif
      if (master->get_gestionnaire()->get_mission_zone_ennemie()->is_depot_gobelet_done()) {
        stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._faire_chier_en_zizagant_state);
#ifdef VERBOSE_STATE_MACHINE
        puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission zone ennemie.faire chier en zizagant");
#endif
        stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._faire_chier_en_zizagant_state.create(stm);
      }
      else if (!master->get_gestionnaire()->get_mission_zone_ennemie()->is_depot_gobelet_done()) {
        if (!master->get_gestionnaire()->get_element_robot()->gobelet_present()) {
          stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._faire_chier_en_zizagant_state);
#ifdef VERBOSE_STATE_MACHINE
          puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission zone ennemie.faire chier en zizagant");
#endif
          stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._faire_chier_en_zizagant_state.create(stm);
        }
        else if (master->get_gestionnaire()->get_element_robot()->gobelet_present()) {
          stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._depot_gobelet_state);
#ifdef VERBOSE_STATE_MACHINE
          puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission zone ennemie.depot gobelet");
#endif
          stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._depot_gobelet_state.create(stm);
        }
      }
    }
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::claps_central_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission zone ennemie.claps central");
#endif
  // mission à 5pts
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::claps_central_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::~mission_zone_ennemie_State() {
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::create(MAE_MURPHY & stm) {
    _doentry(stm);
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._waypoint_initial_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission zone ennemie.waypoint initial");
#endif
      stm._mae_murphy_state._jeu_state._mission_zone_ennemie_state._waypoint_initial_state.create(stm);
    }
}

// to manage the exit point 'sortie', defined because probably shared
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::_exit25(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._decision_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.decision");
#endif
      stm._mae_murphy_state._jeu_state._decision_state.create(stm);
    }
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission zone ennemie");
#endif
  // claps ennemi
  // depot de goblets cinéma adverse
  cout<<"MISSION ZONE ENNEMIE"<<endl;
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::sortie_de_zone_de_depart_State::~sortie_de_zone_de_depart_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::sortie_de_zone_de_depart_State::assFini(MAE_MURPHY & stm) {
    {
      stm._mae_murphy_state._jeu_state._sortie_de_zone_de_depart_state._doexit(stm);
      stm._set_currentState(stm._mae_murphy_state._jeu_state._decision_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.decision");
#endif
      stm._mae_murphy_state._jeu_state._decision_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::sortie_de_zone_de_depart_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::sortie_de_zone_de_depart_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.sortie de zone de depart");
#endif
  serialPrintf(master->getPortSerie(),"S7 1 \n"); 	// vitesse moyenne
  cout<<"sortie de la zone de depart"<<endl;
  // avance de 200mm (400mm avec le recalage)
  // attention si on laisse coop'r derrière ou devant
  serialPrintf(master->getPortSerie(),"S4 200 \n");
  master->get_gestionnaire_mission()->commencement_end();
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::sortie_de_zone_de_depart_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state;
}

// perform the 'exit behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::sortie_de_zone_de_depart_State::_doexit(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute exit behavior of .MAE_MURPHY.Jeu.sortie de zone de depart");
#endif
  serialPrintf(master->getPortSerie(),"S7 0 \n"); 	// vitesse moyenne
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::way_point_initial_State::cap_to_mission_State::~cap_to_mission_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::way_point_initial_State::cap_to_mission_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state._way_point_initial_state._bf_droite_to_mission_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission depot de tour zone depart.way point initial.BF droite to mission");
#endif
      stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state._way_point_initial_state._bf_droite_to_mission_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::way_point_initial_State::cap_to_mission_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::way_point_initial_State::cap_to_mission_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission depot de tour zone depart.way point initial.cap to mission");
#endif
  // BCAP
  string ordre;
  ordre = "S3 " + master->get_gestionnaire()->get_cap_to_mission_str() + " \n";
  const char* ordre_c = ordre.c_str();
  serialPrintf(master->getPortSerie(),"S7 1 \n"); 	// vitesse moyenne
  serialPrintf(master->getPortSerie(),ordre_c);
  cout<<"ORIENTATION VERS MISSION : "<<ordre<<endl;
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::way_point_initial_State::cap_to_mission_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state._way_point_initial_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::way_point_initial_State::cap_mission_State::~cap_mission_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::way_point_initial_State::cap_mission_State::assFini(MAE_MURPHY & stm) {
    {
      stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state._way_point_initial_state._cap_mission_state._doexit(stm);
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state._way_point_initial_state._bf_droite_to_mission_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission depot de tour zone depart.way point initial.BF droite to mission");
#endif
      stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state._way_point_initial_state._bf_droite_to_mission_state._exit19(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::way_point_initial_State::cap_mission_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::way_point_initial_State::cap_mission_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission depot de tour zone depart.way point initial.cap mission");
#endif
  // BF Droite vers objectif
  string ordre;
  ordre = "S3 " 
  	+ master->get_gestionnaire()->get_cap_mission_str() 
  	+ " \n";
  const char* ordre_c = ordre.c_str();
  serialPrintf(master->getPortSerie(),"S7 1 \n"); 	// vitesse moyenne
  serialPrintf(master->getPortSerie(),ordre_c); 
  cout<<"ORIENTATION VERS MISSION : "<<ordre<<endl;
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::way_point_initial_State::cap_mission_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state._way_point_initial_state;
}

// perform the 'exit behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::way_point_initial_State::cap_mission_State::_doexit(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute exit behavior of .MAE_MURPHY.Jeu.mission depot de tour zone depart.way point initial.cap mission");
#endif
  serialPrintf(master->getPortSerie(),"S7 0 \n"); 	// vitesse moyennee
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::way_point_initial_State::BF_droite_to_mission_State::~BF_droite_to_mission_State() {
}

// to manage the exit point 'sortie', defined because probably shared
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::way_point_initial_State::BF_droite_to_mission_State::_exit19(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state._prepare_la_pose_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission depot de tour zone depart.prepare la pose");
#endif
      stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state._prepare_la_pose_state.create(stm);
    }
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::way_point_initial_State::BF_droite_to_mission_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state._way_point_initial_state._cap_mission_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission depot de tour zone depart.way point initial.cap mission");
#endif
      stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state._way_point_initial_state._cap_mission_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::way_point_initial_State::BF_droite_to_mission_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::way_point_initial_State::BF_droite_to_mission_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission depot de tour zone depart.way point initial.BF droite to mission");
#endif
  // BF Droite vers objectif
  string ordre;
  ordre = "S5 "
  	+ master->get_gestionnaire()->get_x_mission_str() 
  	+ " "
  	+ master->get_gestionnaire()->get_y_mission_str() 
  	+ " "
  	+ master->get_gestionnaire()->get_cap_to_mission_str() 
  	+ " \n";
  const char* ordre_c = ordre.c_str();
  serialPrintf(master->getPortSerie(),ordre_c); 
  cout<<"BF droite vers MISSION : "<<ordre<<endl;
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::way_point_initial_State::BF_droite_to_mission_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state._way_point_initial_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::way_point_initial_State::~way_point_initial_State() {
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::way_point_initial_State::create(MAE_MURPHY & stm) {
    _doentry(stm);
    {
      if (master->get_gestionnaire_mission()->is_mission_far()) {
        stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state._way_point_initial_state._cap_to_mission_state);
#ifdef VERBOSE_STATE_MACHINE
        puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission depot de tour zone depart.way point initial.cap to mission");
#endif
        stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state._way_point_initial_state._cap_to_mission_state.create(stm);
      }
      else if (!master->get_gestionnaire_mission()->is_mission_far()) {
        stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state._way_point_initial_state._cap_mission_state);
#ifdef VERBOSE_STATE_MACHINE
        puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission depot de tour zone depart.way point initial.cap mission");
#endif
        stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state._way_point_initial_state._cap_mission_state.create(stm);
      }
    }
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::way_point_initial_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission depot de tour zone depart.way point initial");
#endif
  // rejoindre le point initial de mission
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::way_point_initial_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::BF_cap_vers_la_zone_adverse_State::~BF_cap_vers_la_zone_adverse_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::BF_cap_vers_la_zone_adverse_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission depot de tour zone depart");
#endif
      stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state._exit20(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::BF_cap_vers_la_zone_adverse_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::BF_cap_vers_la_zone_adverse_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission depot de tour zone depart.BF cap vers la zone adverse");
#endif
  cout<<"depot depart : demi-tour"<<endl;
  // demi-tour
  if(master->is_Jaune()){
  	serialPrintf(master->getPortSerie(),"S3 0 \n"); 
  }
  if(master->is_Vert()){
  	serialPrintf(master->getPortSerie(),"S3 180 \n"); 
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::BF_cap_vers_la_zone_adverse_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::rembale_les_pinces_State::~rembale_les_pinces_State() {
}

// to manage the event pince_range
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::rembale_les_pinces_State::pince_range(MAE_MURPHY & stm) {
    {
      stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state._rembale_les_pinces_state._doexit(stm);
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state._bf_cap_vers_la_zone_adverse_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission depot de tour zone depart.BF cap vers la zone adverse");
#endif
      stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state._bf_cap_vers_la_zone_adverse_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::rembale_les_pinces_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::rembale_les_pinces_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission depot de tour zone depart.rembale les pinces");
#endif
  cout<<"depot depart : replis des pinces"<<endl;
  serialPrintf(master->getPortSerie(),"G6 \n");
  serialPrintf(master->getPortSerie(),"D6 \n");
}

// perform the 'exit behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::rembale_les_pinces_State::_doexit(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute exit behavior of .MAE_MURPHY.Jeu.mission depot de tour zone depart.rembale les pinces");
#endif
  master->get_gestionnaire_mission()->get_mission_depot_tour_depart()->mission_remplie();
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::rembale_les_pinces_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::prepare_la_pose_State::~prepare_la_pose_State() {
}

// to manage the event pince_ready_to_drop
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::prepare_la_pose_State::pince_ready_to_drop(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state._avance_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission depot de tour zone depart.avance");
#endif
      stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state._avance_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::prepare_la_pose_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::prepare_la_pose_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission depot de tour zone depart.prepare la pose");
#endif
  cout<<"depot depart : prepare la pile"<<endl;
  // preparation des piles a poser
  if(master->is_Jaune()){
  	serialPrintf(master->getPortSerie(),"D9 \n"); // objectif de pose sur estrade
  	serialPrintf(master->getPortSerie(),"D4 \n"); // preparation de la pose
  	if(master->get_gestionnaire_mission()->get_mission_depot_tour_depart()->is_depot_double())
  	{
  		serialPrintf(master->getPortSerie(),"G9 \n");
  		serialPrintf(master->getPortSerie(),"G4 \n");
  	}
  }
  if(master->is_Vert()){
  	serialPrintf(master->getPortSerie(),"G9 \n");
  	serialPrintf(master->getPortSerie(),"G4 \n");
  	if(master->get_gestionnaire_mission()->get_mission_depot_tour_depart()->is_depot_double())
  	{
  		serialPrintf(master->getPortSerie(),"D9 \n");
  		serialPrintf(master->getPortSerie(),"D4 \n");
  	}
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::prepare_la_pose_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::recule_State::~recule_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::recule_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state._rembale_les_pinces_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission depot de tour zone depart.rembale les pinces");
#endif
      stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state._rembale_les_pinces_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::recule_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::recule_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission depot de tour zone depart.recule");
#endif
  cout<<"depot depart : recule avant replie"<<endl;
  serialPrintf(master->getPortSerie(),"S4 -250 \n"); 
  	
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::recule_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::avance_State::~avance_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::avance_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state._depot_une_tour_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission depot de tour zone depart.depot une tour");
#endif
      stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state._depot_une_tour_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::avance_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::avance_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission depot de tour zone depart.avance");
#endif
  cout<<"depot depart : avance pour depot"<<endl;
  serialPrintf(master->getPortSerie(),"S4 120 \n"); 
  	
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::avance_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state;
}

// to manage the event blocage
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::avance_State::blocage(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state._depot_une_tour_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission depot de tour zone depart.depot une tour");
#endif
      stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state._depot_une_tour_state.create(stm);
    }
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::depot_une_tour_State::~depot_une_tour_State() {
}

// to manage the event pince_lache
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::depot_une_tour_State::pince_lache(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state._recule_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission depot de tour zone depart.recule");
#endif
      stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state._recule_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::depot_une_tour_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::depot_une_tour_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission depot de tour zone depart.depot une tour");
#endif
  cout<<"depot depart : depose la pile"<<endl;
  // preparation des piles a poser
  if(master->is_Jaune()){
  	serialPrintf(master->getPortSerie(),"D5 \n"); // lache
  	if(master->get_gestionnaire_mission()->get_mission_depot_tour_depart()->is_depot_double())
  	{
  		serialPrintf(master->getPortSerie(),"G5 \n");
  	}
  }
  if(master->is_Vert()){
  	serialPrintf(master->getPortSerie(),"G5 \n");
  	if(master->get_gestionnaire_mission()->get_mission_depot_tour_depart()->is_depot_double())
  	{
  		serialPrintf(master->getPortSerie(),"D5 \n");
  	}
  }
  
  // depot de gobelet ?
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::depot_une_tour_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::~mission_depot_de_tour_zone_depart_State() {
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::create(MAE_MURPHY & stm) {
    _doentry(stm);
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state._way_point_initial_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission depot de tour zone depart.way point initial");
#endif
      stm._mae_murphy_state._jeu_state._mission_depot_de_tour_zone_depart_state._way_point_initial_state.create(stm);
    }
}

// to manage the exit point 'sortie ', defined because probably shared
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::_exit20(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._decision_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.decision");
#endif
      stm._mae_murphy_state._jeu_state._decision_state.create(stm);
    }
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission depot de tour zone depart");
#endif
  // depot de tour sur la zone de depart
  cout<<"MISSION DEPOT TOUR DEPART"<<endl;
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::waypoint_init_State::cap_to_mission_State::~cap_to_mission_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::waypoint_init_State::cap_to_mission_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._waypoint_init_state._bf_droite_to_mission_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission rush zone centrale.waypoint init.BF droite to mission");
#endif
      stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._waypoint_init_state._bf_droite_to_mission_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::waypoint_init_State::cap_to_mission_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::waypoint_init_State::cap_to_mission_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission rush zone centrale.waypoint init.cap to mission");
#endif
  // BCAP
  string ordre;
  ordre = "S3 " + master->get_gestionnaire()->get_cap_to_mission_str() + " \n";
  const char* ordre_c = ordre.c_str();
  serialPrintf(master->getPortSerie(),"S7 1 \n"); 	// vitesse moyenne
  serialPrintf(master->getPortSerie(),ordre_c);
  cout<<"ORIENTATION VERS MISSION : "<<ordre<<endl;
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::waypoint_init_State::cap_to_mission_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._waypoint_init_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::waypoint_init_State::cap_mission_State::~cap_mission_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::waypoint_init_State::cap_mission_State::assFini(MAE_MURPHY & stm) {
    {
      stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._waypoint_init_state._cap_mission_state._doexit(stm);
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._waypoint_init_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission rush zone centrale.waypoint init");
#endif
      stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._waypoint_init_state._exit18(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::waypoint_init_State::cap_mission_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::waypoint_init_State::cap_mission_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission rush zone centrale.waypoint init.cap mission");
#endif
  // BF Droite vers objectif
  string ordre;
  ordre = "S3 " 
  	+ master->get_gestionnaire()->get_cap_mission_str() 
  	+ " \n";
  const char* ordre_c = ordre.c_str();
  serialPrintf(master->getPortSerie(),ordre_c); 
  cout<<"ORIENTATION VERS MISSION : "<<ordre<<endl;
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::waypoint_init_State::cap_mission_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._waypoint_init_state;
}

// perform the 'exit behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::waypoint_init_State::cap_mission_State::_doexit(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute exit behavior of .MAE_MURPHY.Jeu.mission rush zone centrale.waypoint init.cap mission");
#endif
  serialPrintf(master->getPortSerie(),"S7 0 \n"); 	// vitesse lente
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::waypoint_init_State::BF_droite_to_mission_State::~BF_droite_to_mission_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::waypoint_init_State::BF_droite_to_mission_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._waypoint_init_state._cap_mission_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission rush zone centrale.waypoint init.cap mission");
#endif
      stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._waypoint_init_state._cap_mission_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::waypoint_init_State::BF_droite_to_mission_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::waypoint_init_State::BF_droite_to_mission_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission rush zone centrale.waypoint init.BF droite to mission");
#endif
  // BF Droite vers objectif
  string ordre;
  ordre = "S5 "
  	+ master->get_gestionnaire()->get_x_mission_str() 
  	+ " "
  	+ master->get_gestionnaire()->get_y_mission_str() 
  	+ " "
  	+ master->get_gestionnaire()->get_cap_to_mission_str() 
  	+ " \n";
  const char* ordre_c = ordre.c_str();
  serialPrintf(master->getPortSerie(),ordre_c); 
  cout<<"BF droite vers MISSION : "<<ordre<<endl;
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::waypoint_init_State::BF_droite_to_mission_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._waypoint_init_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::waypoint_init_State::~waypoint_init_State() {
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::waypoint_init_State::create(MAE_MURPHY & stm) {
    {
      if (master->get_gestionnaire_mission()->is_mission_far()) {
        stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._waypoint_init_state._cap_to_mission_state);
#ifdef VERBOSE_STATE_MACHINE
        puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission rush zone centrale.waypoint init.cap to mission");
#endif
        stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._waypoint_init_state._cap_to_mission_state.create(stm);
      }
      else if (!master->get_gestionnaire_mission()->is_mission_far()) {
        stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._waypoint_init_state._cap_mission_state);
#ifdef VERBOSE_STATE_MACHINE
        puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission rush zone centrale.waypoint init.cap mission");
#endif
        stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._waypoint_init_state._cap_mission_state.create(stm);
      }
    }
}

// to manage the exit point 'sortie', defined because probably shared
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::waypoint_init_State::_exit18(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission rush zone centrale");
#endif
      if (!master->get_gestionnaire_mission()->get_mission_zone_centrale()->is_stand_central_catched()) {
        stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._ouverture_pince_state);
#ifdef VERBOSE_STATE_MACHINE
        puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission rush zone centrale.ouverture pince");
#endif
        stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._ouverture_pince_state.create(stm);
      }
      else if (master->get_gestionnaire_mission()->get_mission_zone_centrale()->is_stand_central_catched()) {
        if (!master->get_gestionnaire_mission()->get_mission_zone_centrale()->is_stand_estrade_catched()) {
          stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._re_ouverture_pince_state);
#ifdef VERBOSE_STATE_MACHINE
          puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission rush zone centrale.re ouverture pince");
#endif
          stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._re_ouverture_pince_state.create(stm);
        }
        else if (master->get_gestionnaire_mission()->get_mission_zone_centrale()->is_stand_estrade_catched()) {
          if (master->get_gestionnaire_mission()->get_mission_zone_centrale()->is_stand_depart_catched()) {
            stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._tempo_pour_coopr_state);
#ifdef VERBOSE_STATE_MACHINE
            puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission rush zone centrale.tempo pour coop'r?");
#endif
            stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._tempo_pour_coopr_state.create(stm);
          }
          else if (!master->get_gestionnaire_mission()->get_mission_zone_centrale()->is_stand_depart_catched()) {
            stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._bf_cap_sur_stand_3_state);
#ifdef VERBOSE_STATE_MACHINE
            puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission rush zone centrale.BF cap sur stand 3");
#endif
            stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._bf_cap_sur_stand_3_state.create(stm);
          }
        }
      }
    }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::waypoint_init_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::tempo_pour_coopr_State::~tempo_pour_coopr_State() {
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::tempo_pour_coopr_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
  	_completion(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::tempo_pour_coopr_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission rush zone centrale.tempo pour coop'r?");
#endif
  cout<<"sortie de zone"<<endl;
  //master->set_time_out(300);
}

// perform the 'exit behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::tempo_pour_coopr_State::_doexit(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute exit behavior of .MAE_MURPHY.Jeu.mission rush zone centrale.tempo pour coop'r?");
#endif
  if(	master->get_gestionnaire_mission()->get_mission_zone_centrale()->is_stand_central_catched()
  	&& master->get_gestionnaire_mission()->get_mission_zone_centrale()->is_stand_estrade_catched()
  	&& master->get_gestionnaire_mission()->get_mission_zone_centrale()->is_stand_depart_catched() )
  
  {
  	master->get_gestionnaire_mission()->get_mission_zone_centrale()->mission_remplie();
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::tempo_pour_coopr_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state;
}

bool MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::tempo_pour_coopr_State::_completion(MAE_MURPHY & stm) {
    {
      stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._tempo_pour_coopr_state._doexit(stm);
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission rush zone centrale");
#endif
      stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._exit17(stm);
      return (bool) 1;
    }
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::chope_stand_3_State::~chope_stand_3_State() {
}

// to manage the event pince_stand_by
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::chope_stand_3_State::pince_stand_by(MAE_MURPHY & stm) {
    {
      stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._chope_stand_3_state._doexit(stm);
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._tempo_pour_coopr_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission rush zone centrale.tempo pour coop'r?");
#endif
      stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._tempo_pour_coopr_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::chope_stand_3_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::chope_stand_3_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission rush zone centrale.chope stand 3");
#endif
  cout<<"stand depart : chope stand"<<endl;
  if(master->is_Jaune()){
  serialPrintf(master->getPortSerie(),"G1 \n");
  }
  if(master->is_Vert()){
  serialPrintf(master->getPortSerie(),"D1 \n");
  }
}

// perform the 'exit behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::chope_stand_3_State::_doexit(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute exit behavior of .MAE_MURPHY.Jeu.mission rush zone centrale.chope stand 3");
#endif
  master->get_gestionnaire_mission()->get_mission_zone_centrale()->catch_stand_depart();
  master->get_gestionnaire_mission()->get_mission_claps()->stand_depart_done();
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::chope_stand_3_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::BF_droite_stand_3_State::~BF_droite_stand_3_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::BF_droite_stand_3_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._chope_stand_3_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission rush zone centrale.chope stand 3");
#endif
      stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._chope_stand_3_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::BF_droite_stand_3_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::BF_droite_stand_3_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission rush zone centrale.BF droite stand 3");
#endif
  cout<<"stand depart : BF droite sur cible"<<endl;
  if(master->is_Jaune()){
  serialPrintf(master->getPortSerie(),"S5 -528 623 110 \n");
  }
  if(master->is_Vert()){
  serialPrintf(master->getPortSerie(),"S5 528 623 70 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::BF_droite_stand_3_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::re_re_ouverture_pince_State::~re_re_ouverture_pince_State() {
}

// to manage the event pince_ouverte
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::re_re_ouverture_pince_State::pince_ouverte(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._bf_droite_stand_3_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission rush zone centrale.BF droite stand 3");
#endif
      stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._bf_droite_stand_3_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::re_re_ouverture_pince_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::re_re_ouverture_pince_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission rush zone centrale.re re ouverture pince");
#endif
  cout<<"stand depart : ouverture de pince"<<endl;
  if(master->is_Jaune()){
  serialPrintf(master->getPortSerie(),"G0 \n");
  }
  if(master->is_Vert()){
  serialPrintf(master->getPortSerie(),"D0 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::re_re_ouverture_pince_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::BF_cap_sur_stand_3_State::~BF_cap_sur_stand_3_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::BF_cap_sur_stand_3_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._re_re_ouverture_pince_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission rush zone centrale.re re ouverture pince");
#endif
      stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._re_re_ouverture_pince_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::BF_cap_sur_stand_3_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::BF_cap_sur_stand_3_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission rush zone centrale.BF cap sur stand 3");
#endif
  cout<<"stand depart : orientation sur cible"<<endl;
  if(master->is_Jaune()){
  serialPrintf(master->getPortSerie(),"S3 110 \n");
  }
  if(master->is_Vert()){
  serialPrintf(master->getPortSerie(),"S3 70 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::BF_cap_sur_stand_3_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::chope_stand_2_State::~chope_stand_2_State() {
}

// to manage the event pince_stand_by
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::chope_stand_2_State::pince_stand_by(MAE_MURPHY & stm) {
    {
      stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._chope_stand_2_state._doexit(stm);
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission rush zone centrale");
#endif
      if (master->get_gestionnaire_mission()->get_mission_zone_centrale()->is_stand_depart_catched()) {
        stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._tempo_pour_coopr_state);
#ifdef VERBOSE_STATE_MACHINE
        puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission rush zone centrale.tempo pour coop'r?");
#endif
        stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._tempo_pour_coopr_state.create(stm);
      }
      else if (!master->get_gestionnaire_mission()->get_mission_zone_centrale()->is_stand_depart_catched()) {
        stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._bf_cap_sur_stand_3_state);
#ifdef VERBOSE_STATE_MACHINE
        puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission rush zone centrale.BF cap sur stand 3");
#endif
        stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._bf_cap_sur_stand_3_state.create(stm);
      }
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::chope_stand_2_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::chope_stand_2_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission rush zone centrale.chope stand 2");
#endif
  cout<<"stand estrade : chope stand"<<endl;
  if(master->is_Jaune()){
  serialPrintf(master->getPortSerie(),"G1 \n");
  }
  if(master->is_Vert()){
  serialPrintf(master->getPortSerie(),"D1 \n");
  }
}

// perform the 'exit behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::chope_stand_2_State::_doexit(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute exit behavior of .MAE_MURPHY.Jeu.mission rush zone centrale.chope stand 2");
#endif
  master->get_gestionnaire_mission()->get_mission_zone_centrale()->catch_stand_estrade();
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::chope_stand_2_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::BF_droite_stand_2_State::~BF_droite_stand_2_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::BF_droite_stand_2_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._chope_stand_2_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission rush zone centrale.chope stand 2");
#endif
      stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._chope_stand_2_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::BF_droite_stand_2_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::BF_droite_stand_2_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission rush zone centrale.BF droite stand 2");
#endif
  cout<<"stand estrade : BF droite sur cible"<<endl;
  if(master->is_Jaune()){
  serialPrintf(master->getPortSerie(),"S5 -434 347 -122 \n");
  }
  if(master->is_Vert()){
  serialPrintf(master->getPortSerie(),"S5 434 347 302 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::BF_droite_stand_2_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::re_ouverture_pince_State::~re_ouverture_pince_State() {
}

// to manage the event pince_ouverte
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::re_ouverture_pince_State::pince_ouverte(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._bf_droite_stand_2_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission rush zone centrale.BF droite stand 2");
#endif
      stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._bf_droite_stand_2_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::re_ouverture_pince_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::re_ouverture_pince_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission rush zone centrale.re ouverture pince");
#endif
  cout<<"stand estrade : ouverture de pince"<<endl;
  if(master->is_Jaune()){
  serialPrintf(master->getPortSerie(),"G0 \n");
  }
  if(master->is_Vert()){
  serialPrintf(master->getPortSerie(),"D0 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::re_ouverture_pince_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::chope_stand_1_State::~chope_stand_1_State() {
}

// to manage the event pince_stand_by
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::chope_stand_1_State::pince_stand_by(MAE_MURPHY & stm) {
    {
      stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._chope_stand_1_state._doexit(stm);
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission rush zone centrale");
#endif
      if (!master->get_gestionnaire_mission()->get_mission_zone_centrale()->is_stand_estrade_catched()) {
        stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._re_ouverture_pince_state);
#ifdef VERBOSE_STATE_MACHINE
        puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission rush zone centrale.re ouverture pince");
#endif
        stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._re_ouverture_pince_state.create(stm);
      }
      else if (master->get_gestionnaire_mission()->get_mission_zone_centrale()->is_stand_estrade_catched()) {
        if (master->get_gestionnaire_mission()->get_mission_zone_centrale()->is_stand_depart_catched()) {
          stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._tempo_pour_coopr_state);
#ifdef VERBOSE_STATE_MACHINE
          puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission rush zone centrale.tempo pour coop'r?");
#endif
          stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._tempo_pour_coopr_state.create(stm);
        }
        else if (!master->get_gestionnaire_mission()->get_mission_zone_centrale()->is_stand_depart_catched()) {
          stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._bf_cap_sur_stand_3_state);
#ifdef VERBOSE_STATE_MACHINE
          puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission rush zone centrale.BF cap sur stand 3");
#endif
          stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._bf_cap_sur_stand_3_state.create(stm);
        }
      }
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::chope_stand_1_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::chope_stand_1_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission rush zone centrale.chope stand 1");
#endif
  cout<<"stand central : chope de stand"<<endl;
  if(master->is_Jaune()){
  serialPrintf(master->getPortSerie(),"G1 \n");
  }
  if(master->is_Vert()){
  serialPrintf(master->getPortSerie(),"D1 \n");
  }
}

// perform the 'exit behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::chope_stand_1_State::_doexit(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute exit behavior of .MAE_MURPHY.Jeu.mission rush zone centrale.chope stand 1");
#endif
  master->get_gestionnaire_mission()->get_mission_zone_centrale()->catch_stand_central();
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::chope_stand_1_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::BF_droite_stand_1_State::~BF_droite_stand_1_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::BF_droite_stand_1_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._chope_stand_1_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission rush zone centrale.chope stand 1");
#endif
      stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._chope_stand_1_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::BF_droite_stand_1_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::BF_droite_stand_1_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission rush zone centrale.BF droite stand 1");
#endif
  cout<<"stand central : BF droite sur cible"<<endl;
  if(master->is_Jaune()){
  serialPrintf(master->getPortSerie(),"S5 -270 687 -100 \n");
  }
  if(master->is_Vert()){
  serialPrintf(master->getPortSerie(),"S5 270 687 280 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::BF_droite_stand_1_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::ouverture_pince_State::~ouverture_pince_State() {
}

// to manage the event pince_ouverte
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::ouverture_pince_State::pince_ouverte(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._bf_droite_stand_1_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission rush zone centrale.BF droite stand 1");
#endif
      stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._bf_droite_stand_1_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::ouverture_pince_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::ouverture_pince_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission rush zone centrale.ouverture pince");
#endif
  cout<<"stand central : ouverture de pince"<<endl;
  // pince cote escalier
  if(master->is_Jaune()){
  serialPrintf(master->getPortSerie(),"G0 \n");
  }
  if(master->is_Vert()){
  serialPrintf(master->getPortSerie(),"D0 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::ouverture_pince_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::~mission_rush_zone_centrale_State() {
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::create(MAE_MURPHY & stm) {
    _doentry(stm);
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._waypoint_init_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission rush zone centrale.waypoint init");
#endif
      stm._mae_murphy_state._jeu_state._mission_rush_zone_centrale_state._waypoint_init_state.create(stm);
    }
}

// to manage the exit point 'sortie zone centrale', defined because probably shared
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::_exit17(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._decision_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.decision");
#endif
      stm._mae_murphy_state._jeu_state._decision_state.create(stm);
    }
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission rush zone centrale");
#endif
  // on va rusher les trois stands centraux
  cout<<"MISSION RUSH ZONE CENTRALE"<<endl;
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_stand_sur_la_route_State::BF_droite_State::~BF_droite_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_stand_sur_la_route_State::BF_droite_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_stand_sur_la_route_state._chope_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.chope du stand sur la route.chope");
#endif
      stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_stand_sur_la_route_state._chope_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_stand_sur_la_route_State::BF_droite_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_stand_sur_la_route_State::BF_droite_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission claps.chope du stand sur la route.BF droite");
#endif
  serialPrintf(master->getPortSerie(),"S7 0 \n"); 	// vitesse moyenne
  cout<<"stand depart : BF droite sur cible"<<endl;
  if(master->is_Jaune()){
  // BF droite sur le gobelet 
  serialPrintf(master->getPortSerie(),"S5 -835 744 -90 \n");
  }
  if(master->is_Vert()){
  // BF droite sur le gobelet 
  serialPrintf(master->getPortSerie(),"S5 835 744 -90 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_stand_sur_la_route_State::BF_droite_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_stand_sur_la_route_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_stand_sur_la_route_State::chope_State::~chope_State() {
}

// to manage the event pince_stand_by
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_stand_sur_la_route_State::chope_State::pince_stand_by(MAE_MURPHY & stm) {
    {
      stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_stand_sur_la_route_state._chope_state._doexit(stm);
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_stand_sur_la_route_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.chope du stand sur la route");
#endif
      stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_stand_sur_la_route_state._exit11(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_stand_sur_la_route_State::chope_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_stand_sur_la_route_State::chope_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission claps.chope du stand sur la route.chope");
#endif
  cout<<"stand depart : chope stand"<<endl;
  if(master->is_Jaune()){
  // ouvre pince gauche
  serialPrintf(master->getPortSerie(),"G1 \n");
  }
  if(master->is_Vert()){
  serialPrintf(master->getPortSerie(),"D1 \n");
  }
}

// perform the 'exit behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_stand_sur_la_route_State::chope_State::_doexit(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute exit behavior of .MAE_MURPHY.Jeu.mission claps.chope du stand sur la route.chope");
#endif
  master->get_gestionnaire_mission()->get_mission_zone_centrale()->catch_stand_depart();
  master->get_gestionnaire_mission()->get_mission_claps()->stand_depart_done();
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_stand_sur_la_route_State::chope_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_stand_sur_la_route_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_stand_sur_la_route_State::ouverture_de_pince_State::~ouverture_de_pince_State() {
}

// to manage the event pince_ouverte
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_stand_sur_la_route_State::ouverture_de_pince_State::pince_ouverte(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_stand_sur_la_route_state._bf_droite_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.chope du stand sur la route.BF droite");
#endif
      stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_stand_sur_la_route_state._bf_droite_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_stand_sur_la_route_State::ouverture_de_pince_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_stand_sur_la_route_State::ouverture_de_pince_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission claps.chope du stand sur la route.ouverture de pince");
#endif
  cout<<"stand depart : ouverture pince"<<endl;
  if(master->is_Jaune()){
  // ouvre pince gauche
  serialPrintf(master->getPortSerie(),"G0 \n");
  }
  if(master->is_Vert()){
  serialPrintf(master->getPortSerie(),"D0 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_stand_sur_la_route_State::ouverture_de_pince_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_stand_sur_la_route_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_stand_sur_la_route_State::~chope_du_stand_sur_la_route_State() {
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_stand_sur_la_route_State::create(MAE_MURPHY & stm) {
    _doentry(stm);
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_stand_sur_la_route_state._ouverture_de_pince_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.chope du stand sur la route.ouverture de pince");
#endif
      stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_stand_sur_la_route_state._ouverture_de_pince_state.create(stm);
    }
}

// to manage the exit point 'sortie stand', defined because probably shared
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_stand_sur_la_route_State::_exit11(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps");
#endif
      if (master->get_gestionnaire_mission()->get_mission_claps()->is_zone_coin_done()) {
        if (master->get_gestionnaire_mission()->get_mission_claps()->is_clap_estrade_done()) {
          stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._sortie_de_zone_state);
#ifdef VERBOSE_STATE_MACHINE
          puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.sortie de zone");
#endif
          stm._mae_murphy_state._jeu_state._mission_claps_state._sortie_de_zone_state.create(stm);
        }
        else if (!master->get_gestionnaire_mission()->get_mission_claps()->is_clap_estrade_done()) {
          stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._claps_estrade_state);
#ifdef VERBOSE_STATE_MACHINE
          puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.claps estrade");
#endif
          stm._mae_murphy_state._jeu_state._mission_claps_state._claps_estrade_state.create(stm);
        }
      }
      else if (!master->get_gestionnaire_mission()->get_mission_claps()->is_zone_coin_done()) {
        stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state);
#ifdef VERBOSE_STATE_MACHINE
        puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.chope du coin");
#endif
        stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state.create(stm);
      }
    }
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_stand_sur_la_route_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission claps.chope du stand sur la route");
#endif
  // chope le stand devant la zone de depart
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_stand_sur_la_route_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_claps_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::sortie_de_zone_State::BF_cap_State::~BF_cap_State() {
}

bool MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::sortie_de_zone_State::BF_cap_State::_completion(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._sortie_de_zone_state._avance_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.sortie de zone.avance");
#endif
      stm._mae_murphy_state._jeu_state._mission_claps_state._sortie_de_zone_state._avance_state.create(stm);
      return (bool) 1;
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::sortie_de_zone_State::BF_cap_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
  	_completion(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::sortie_de_zone_State::BF_cap_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission claps.sortie de zone.BF cap");
#endif
  cout<<"sortie de zone"<<endl;
  if(	master->get_gestionnaire_mission()->get_mission_claps()->is_stand_depart_done()
  	&& master->get_gestionnaire_mission()->get_mission_claps()->is_zone_coin_done()
  	&& master->get_gestionnaire_mission()->get_mission_claps()->is_clap_estrade_done())
  {
  	master->get_gestionnaire_mission()->get_mission_claps()->mission_remplie();
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::sortie_de_zone_State::BF_cap_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_claps_state._sortie_de_zone_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::sortie_de_zone_State::avance_State::~avance_State() {
}

bool MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::sortie_de_zone_State::avance_State::_completion(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._sortie_de_zone_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.sortie de zone");
#endif
      stm._mae_murphy_state._jeu_state._mission_claps_state._sortie_de_zone_state._exit15(stm);
      return (bool) 1;
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::sortie_de_zone_State::avance_State::create(MAE_MURPHY & stm) {
  	_completion(stm);
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::sortie_de_zone_State::avance_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_claps_state._sortie_de_zone_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::sortie_de_zone_State::~sortie_de_zone_State() {
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::sortie_de_zone_State::create(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._sortie_de_zone_state._bf_cap_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.sortie de zone.BF cap");
#endif
      stm._mae_murphy_state._jeu_state._mission_claps_state._sortie_de_zone_state._bf_cap_state.create(stm);
    }
}

// to manage the exit point 'sortie', defined because probably shared
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::sortie_de_zone_State::_exit15(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps");
#endif
      stm._mae_murphy_state._jeu_state._mission_claps_state._exit16(stm);
    }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::sortie_de_zone_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_claps_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::waypoint_initial_State::cap_to_mission_State::~cap_to_mission_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::waypoint_initial_State::cap_to_mission_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._waypoint_initial_state._bf_droite_to_mission_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.waypoint initial.BF droite to mission");
#endif
      stm._mae_murphy_state._jeu_state._mission_claps_state._waypoint_initial_state._bf_droite_to_mission_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::waypoint_initial_State::cap_to_mission_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::waypoint_initial_State::cap_to_mission_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission claps.waypoint initial.cap to mission");
#endif
  // BCAP
  string ordre;
  ordre = "S3 " + master->get_gestionnaire()->get_cap_to_mission_str() + " \n";
  const char* ordre_c = ordre.c_str();
  serialPrintf(master->getPortSerie(),"S7 1 \n"); 	// vitesse moyenne
  serialPrintf(master->getPortSerie(),ordre_c);
  cout<<"ORIENTATION VERS MISSION : "<<ordre<<endl;
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::waypoint_initial_State::cap_to_mission_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_claps_state._waypoint_initial_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::waypoint_initial_State::cap_mission_State::~cap_mission_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::waypoint_initial_State::cap_mission_State::assFini(MAE_MURPHY & stm) {
    {
      stm._mae_murphy_state._jeu_state._mission_claps_state._waypoint_initial_state._cap_mission_state._doexit(stm);
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._waypoint_initial_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.waypoint initial");
#endif
      stm._mae_murphy_state._jeu_state._mission_claps_state._waypoint_initial_state._exit14(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::waypoint_initial_State::cap_mission_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::waypoint_initial_State::cap_mission_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission claps.waypoint initial.cap mission");
#endif
  // BF Droite vers objectif
  string ordre;
  ordre = "S3 " 
  	+ master->get_gestionnaire()->get_cap_mission_str() 
  	+ " \n";
  const char* ordre_c = ordre.c_str();
  serialPrintf(master->getPortSerie(),ordre_c); 
  cout<<"ORIENTATION VERS MISSION : "<<ordre<<endl;
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::waypoint_initial_State::cap_mission_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_claps_state._waypoint_initial_state;
}

// perform the 'exit behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::waypoint_initial_State::cap_mission_State::_doexit(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute exit behavior of .MAE_MURPHY.Jeu.mission claps.waypoint initial.cap mission");
#endif
  serialPrintf(master->getPortSerie(),"S7 0 \n"); 	// vitesse moyenne
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::waypoint_initial_State::BF_droite_to_mission_State::~BF_droite_to_mission_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::waypoint_initial_State::BF_droite_to_mission_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._waypoint_initial_state._cap_mission_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.waypoint initial.cap mission");
#endif
      stm._mae_murphy_state._jeu_state._mission_claps_state._waypoint_initial_state._cap_mission_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::waypoint_initial_State::BF_droite_to_mission_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::waypoint_initial_State::BF_droite_to_mission_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission claps.waypoint initial.BF droite to mission");
#endif
  // BF Droite vers objectif
  string ordre;
  ordre = "S5 "
  	+ master->get_gestionnaire()->get_x_mission_str() 
  	+ " "
  	+ master->get_gestionnaire()->get_y_mission_str() 
  	+ " "
  	+ master->get_gestionnaire()->get_cap_to_mission_str() 
  	+ " \n";
  const char* ordre_c = ordre.c_str();
  serialPrintf(master->getPortSerie(),ordre_c); 
  cout<<"BF droite vers MISSION : "<<ordre<<endl;
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::waypoint_initial_State::BF_droite_to_mission_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_claps_state._waypoint_initial_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::waypoint_initial_State::~waypoint_initial_State() {
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::waypoint_initial_State::create(MAE_MURPHY & stm) {
    _doentry(stm);
    {
      if (master->get_gestionnaire_mission()->is_mission_far()) {
        stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._waypoint_initial_state._cap_to_mission_state);
#ifdef VERBOSE_STATE_MACHINE
        puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.waypoint initial.cap to mission");
#endif
        stm._mae_murphy_state._jeu_state._mission_claps_state._waypoint_initial_state._cap_to_mission_state.create(stm);
      }
      else if (!master->get_gestionnaire_mission()->is_mission_far()) {
        stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._waypoint_initial_state._cap_mission_state);
#ifdef VERBOSE_STATE_MACHINE
        puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.waypoint initial.cap mission");
#endif
        stm._mae_murphy_state._jeu_state._mission_claps_state._waypoint_initial_state._cap_mission_state.create(stm);
      }
    }
}

// to manage the exit point 'sortie w', defined because probably shared
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::waypoint_initial_State::_exit14(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps");
#endif
      if (!master->get_gestionnaire_mission()->get_mission_claps()->is_stand_depart_done()) {
        stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_stand_sur_la_route_state);
#ifdef VERBOSE_STATE_MACHINE
        puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.chope du stand sur la route");
#endif
        stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_stand_sur_la_route_state.create(stm);
      }
      else if (master->get_gestionnaire_mission()->get_mission_claps()->is_stand_depart_done()) {
        if (master->get_gestionnaire_mission()->get_mission_claps()->is_zone_coin_done()) {
          if (master->get_gestionnaire_mission()->get_mission_claps()->is_clap_estrade_done()) {
            stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._sortie_de_zone_state);
#ifdef VERBOSE_STATE_MACHINE
            puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.sortie de zone");
#endif
            stm._mae_murphy_state._jeu_state._mission_claps_state._sortie_de_zone_state.create(stm);
          }
          else if (!master->get_gestionnaire_mission()->get_mission_claps()->is_clap_estrade_done()) {
            stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._claps_estrade_state);
#ifdef VERBOSE_STATE_MACHINE
            puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.claps estrade");
#endif
            stm._mae_murphy_state._jeu_state._mission_claps_state._claps_estrade_state.create(stm);
          }
        }
        else if (!master->get_gestionnaire_mission()->get_mission_claps()->is_zone_coin_done()) {
          stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state);
#ifdef VERBOSE_STATE_MACHINE
          puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.chope du coin");
#endif
          stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state.create(stm);
        }
      }
    }
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::waypoint_initial_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission claps.waypoint initial");
#endif
  // rejoint le debut de la mission
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::waypoint_initial_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_claps_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::claps_estrade_State::BF_droite_sur_claps_estrade_State::~BF_droite_sur_claps_estrade_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::claps_estrade_State::BF_droite_sur_claps_estrade_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._claps_estrade_state._claps_3_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.claps estrade.Claps 3");
#endif
      stm._mae_murphy_state._jeu_state._mission_claps_state._claps_estrade_state._claps_3_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::claps_estrade_State::BF_droite_sur_claps_estrade_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::claps_estrade_State::BF_droite_sur_claps_estrade_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission claps.claps estrade.BF droite sur claps estrade");
#endif
  serialPrintf(master->getPortSerie(),"S7 1 \n"); 	// vitesse moyenne
  cout<<"claps estrade : BF droite sur cible"<<endl;
  if(master->is_Jaune()){
  // BF droite sur le gobelet 
  serialPrintf(master->getPortSerie(),"S5 -730 270 0 \n");
  }
  if(master->is_Vert()){
  // BF droite sur le gobelet 
  serialPrintf(master->getPortSerie(),"S5 730 270 180 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::claps_estrade_State::BF_droite_sur_claps_estrade_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_claps_state._claps_estrade_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::claps_estrade_State::Claps_3_State::~Claps_3_State() {
}

// to manage the event claps_replie
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::claps_estrade_State::Claps_3_State::claps_replie(MAE_MURPHY & stm) {
    {
      stm._mae_murphy_state._jeu_state._mission_claps_state._claps_estrade_state._claps_3_state._doexit(stm);
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._claps_estrade_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.claps estrade");
#endif
      stm._mae_murphy_state._jeu_state._mission_claps_state._claps_estrade_state._exit13(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::claps_estrade_State::Claps_3_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::claps_estrade_State::Claps_3_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission claps.claps estrade.Claps 3");
#endif
  cout<<"claps estrade : deboit le claps"<<endl;
  // claps cote droit pour jaune
  if(master->is_Jaune()){
  // ouverture du claps
  serialPrintf(master->getPortSerie(),"C0 \n");
  }
  if(master->is_Vert()){
  // BF droite sur le gobelet 
  serialPrintf(master->getPortSerie(),"C2 \n");
  }
}

// perform the 'exit behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::claps_estrade_State::Claps_3_State::_doexit(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute exit behavior of .MAE_MURPHY.Jeu.mission claps.claps estrade.Claps 3");
#endif
  master->get_gestionnaire_mission()->get_mission_claps()->claps_estrade_done();
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::claps_estrade_State::Claps_3_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_claps_state._claps_estrade_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::claps_estrade_State::~claps_estrade_State() {
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::claps_estrade_State::create(MAE_MURPHY & stm) {
    _doentry(stm);
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._claps_estrade_state._bf_droite_sur_claps_estrade_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.claps estrade.BF droite sur claps estrade");
#endif
      stm._mae_murphy_state._jeu_state._mission_claps_state._claps_estrade_state._bf_droite_sur_claps_estrade_state.create(stm);
    }
}

// to manage the exit point 'sortie claps', defined because probably shared
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::claps_estrade_State::_exit13(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._sortie_de_zone_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.sortie de zone");
#endif
      stm._mae_murphy_state._jeu_state._mission_claps_state._sortie_de_zone_state.create(stm);
    }
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::claps_estrade_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission claps.claps estrade");
#endif
  // deboit le claps vers l'estrade
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::claps_estrade_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_claps_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::BF_droite_sur_le_verre_State::~BF_droite_sur_le_verre_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::BF_droite_sur_le_verre_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state._chope_gobelet_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.chope du coin.chope gobelet");
#endif
      stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state._chope_gobelet_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::BF_droite_sur_le_verre_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::BF_droite_sur_le_verre_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission claps.chope du coin.BF droite sur le verre");
#endif
  cout<<"coin : BF droite sur verre"<<endl;
  if(master->is_Jaune()){
  // BF droite sur le gobelet 
  serialPrintf(master->getPortSerie(),"S5 -1250 247 180 \n");
  }
  if(master->is_Vert()){
  // BF droite sur le gobelet 
  serialPrintf(master->getPortSerie(),"S5 1250 247 0 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::BF_droite_sur_le_verre_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::avance_claps_State::~avance_claps_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::avance_claps_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state._deboit_claps_coin_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.chope du coin.deboit claps coin");
#endif
      stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state._deboit_claps_coin_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::avance_claps_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::avance_claps_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission claps.chope du coin.avance claps");
#endif
  cout<<"coin : avance claps coin"<<endl;
  // de 100mm
  serialPrintf(master->getPortSerie(),"S4 100 \n");
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::avance_claps_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::set_X_CAP_State::~set_X_CAP_State() {
}

// to manage the event time_out
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::set_X_CAP_State::time_out(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state._avance_claps_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.chope du coin.avance claps");
#endif
      stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state._avance_claps_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::set_X_CAP_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::set_X_CAP_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission claps.chope du coin.set X CAP");
#endif
  cout<<"coin : set X CAP"<<endl;
  if(master->is_Jaune()){
  // BF droite sur le gobelet 
  serialPrintf(master->getPortSerie(),"S0 -1404 -1 0\n"); // mettre le Y du S
  }
  if(master->is_Vert()){
  // BF droite sur le gobelet 
  serialPrintf(master->getPortSerie(),"S0 1404 -1 180 \n");
  }
  master->set_time_out(50);
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::set_X_CAP_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::deboit_claps_coin_State::~deboit_claps_coin_State() {
}

// to manage the event claps_replie
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::deboit_claps_coin_State::claps_replie(MAE_MURPHY & stm) {
    {
      stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state._deboit_claps_coin_state._doexit(stm);
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.chope du coin");
#endif
      stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state._exit12(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::deboit_claps_coin_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::deboit_claps_coin_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission claps.chope du coin.deboit claps coin");
#endif
  cout<<"coin : deboit le claps du coin"<<endl;
  if(master->is_Jaune()){
  // BF droite sur le gobelet 
  serialPrintf(master->getPortSerie(),"C0 \n");
  }
  if(master->is_Vert()){
  // BF droite sur le gobelet 
  serialPrintf(master->getPortSerie(),"C2 \n");
  }
}

// perform the 'exit behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::deboit_claps_coin_State::_doexit(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute exit behavior of .MAE_MURPHY.Jeu.mission claps.chope du coin.deboit claps coin");
#endif
  master->get_gestionnaire_mission()->get_mission_claps()->zone_coin_done();
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::deboit_claps_coin_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::BF_CAP_pour_claps_State::~BF_CAP_pour_claps_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::BF_CAP_pour_claps_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state._recalage_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.chope du coin.recalage");
#endif
      stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state._recalage_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::BF_CAP_pour_claps_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::BF_CAP_pour_claps_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission claps.chope du coin.BF CAP pour claps");
#endif
  cout<<"coin : BF Cap pour claps"<<endl;
  if(master->is_Jaune()){
  // BF droite sur le gobelet 
  serialPrintf(master->getPortSerie(),"S3 0 \n");
  }
  if(master->is_Vert()){
  // BF droite sur le gobelet 
  serialPrintf(master->getPortSerie(),"S3 180 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::BF_CAP_pour_claps_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::recalage_State::~recalage_State() {
}

// to manage the event blocage
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::recalage_State::blocage(MAE_MURPHY & stm) {
    {
      stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state._recalage_state._doexit(stm);
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state._set_x_cap_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.chope du coin.set X CAP");
#endif
      stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state._set_x_cap_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::recalage_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::recalage_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission claps.chope du coin.recalage");
#endif
  cout<<"coin : recalage coin"<<endl;
  serialPrintf(master->getPortSerie(),"S2 \n");
}

// perform the 'exit behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::recalage_State::_doexit(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute exit behavior of .MAE_MURPHY.Jeu.mission claps.chope du coin.recalage");
#endif
  serialPrintf(master->getPortSerie(),"S1 \n");
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::recalage_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::chope_stand_2_State::~chope_stand_2_State() {
}

// to manage the event pince_stand_by
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::chope_stand_2_State::pince_stand_by(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state._bf_cap_pour_claps_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.chope du coin.BF CAP pour claps");
#endif
      stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state._bf_cap_pour_claps_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::chope_stand_2_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::chope_stand_2_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission claps.chope du coin.chope stand 2");
#endif
  cout<<"coin : chope 2nd stand"<<endl;
  if(master->is_Jaune()){
  // ouverture de pince
  serialPrintf(master->getPortSerie(),"D1 \n");
  }
  if(master->is_Vert()){
  serialPrintf(master->getPortSerie(),"G1 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::chope_stand_2_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::re_avance_State::~re_avance_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::re_avance_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state._chope_stand_2_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.chope du coin.chope stand 2");
#endif
      stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state._chope_stand_2_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::re_avance_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::re_avance_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission claps.chope du coin.re avance");
#endif
  cout<<"coin : avance sur 2nd stand"<<endl;
  serialPrintf(master->getPortSerie(),"S4 110 \n");
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::re_avance_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::re_ouvre_pince_State::~re_ouvre_pince_State() {
}

// to manage the event pince_ouverte
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::re_ouvre_pince_State::pince_ouverte(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state._re_avance_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.chope du coin.re avance");
#endif
      stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state._re_avance_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::re_ouvre_pince_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::re_ouvre_pince_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission claps.chope du coin.re ouvre pince");
#endif
  cout<<"coin : ouverture pince 2nd stand"<<endl;
  if(master->is_Jaune()){
  // ouverture de pince
  serialPrintf(master->getPortSerie(),"D0 \n");
  }
  if(master->is_Vert()){
  serialPrintf(master->getPortSerie(),"G0 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::re_ouvre_pince_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::chope_stand_1_State::~chope_stand_1_State() {
}

// to manage the event pince_stand_by
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::chope_stand_1_State::pince_stand_by(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state._re_ouvre_pince_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.chope du coin.re ouvre pince");
#endif
      stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state._re_ouvre_pince_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::chope_stand_1_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::chope_stand_1_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission claps.chope du coin.chope stand 1");
#endif
  cout<<"coin : chope 1er stand"<<endl;
  if(master->is_Jaune()){
  // ouverture de pince
  serialPrintf(master->getPortSerie(),"D1 \n");
  }
  if(master->is_Vert()){
  serialPrintf(master->getPortSerie(),"G1 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::chope_stand_1_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::avance_State::~avance_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::avance_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state._chope_stand_1_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.chope du coin.chope stand 1");
#endif
      stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state._chope_stand_1_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::avance_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::avance_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission claps.chope du coin.avance");
#endif
  cout<<"coin : avance sur 1er stand"<<endl;
  serialPrintf(master->getPortSerie(),"S4 120 \n");
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::avance_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::ouvre_pince_State::~ouvre_pince_State() {
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::ouvre_pince_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::ouvre_pince_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission claps.chope du coin.ouvre pince");
#endif
  cout<<"coin : ouverture pince 1er stand"<<endl;
  if(master->is_Jaune()){
  // ouverture de pince
  serialPrintf(master->getPortSerie(),"D0 \n");
  }
  if(master->is_Vert()){
  serialPrintf(master->getPortSerie(),"G0 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::ouvre_pince_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state;
}

// to manage the event pince_ouverte
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::ouvre_pince_State::pince_ouverte(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state._avance_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.chope du coin.avance");
#endif
      stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state._avance_state.create(stm);
    }
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::BF_droite_vers_les_stands_State::~BF_droite_vers_les_stands_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::BF_droite_vers_les_stands_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state._ouvre_pince_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.chope du coin.ouvre pince");
#endif
      stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state._ouvre_pince_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::BF_droite_vers_les_stands_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::BF_droite_vers_les_stands_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission claps.chope du coin.BF droite vers les stands");
#endif
  cout<<"coin : BF droite sur stands"<<endl;
  if(master->is_Jaune()){
  // BF droite sur le gobelet 
  serialPrintf(master->getPortSerie(),"S5 -1180 468 -90 \n");
  }
  if(master->is_Vert()){
  // BF droite sur le gobelet 
  serialPrintf(master->getPortSerie(),"S5 1180 468 -90 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::BF_droite_vers_les_stands_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::recule_vers_la_zone_de_depart_State::~recule_vers_la_zone_de_depart_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::recule_vers_la_zone_de_depart_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state._bf_droite_vers_les_stands_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.chope du coin.BF droite vers les stands");
#endif
      stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state._bf_droite_vers_les_stands_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::recule_vers_la_zone_de_depart_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::recule_vers_la_zone_de_depart_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission claps.chope du coin.recule vers la zone de depart");
#endif
  cout<<"coin : recule vers la zone de depart"<<endl;
  //serialPrintf(master->getPortSerie(),"S4 -350 \n");
  if(master->is_Jaune()){
  // BF droite sur le gobelet 
  serialPrintf(master->getPortSerie(),"S5 -1013 610 -90 \n");
  }
  if(master->is_Vert()){
  // BF droite sur le gobelet 
  serialPrintf(master->getPortSerie(),"S5 1013 610 -90 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::recule_vers_la_zone_de_depart_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::recule_des_stands_State::~recule_des_stands_State() {
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::recule_des_stands_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::recule_des_stands_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission claps.chope du coin.recule des stands");
#endif
  cout<<"coin : recule pour degagement"<<endl;
  serialPrintf(master->getPortSerie(),"S4 -120 \n");
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::recule_des_stands_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::chope_gobelet_State::~chope_gobelet_State() {
}

// to manage the event time_out
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::chope_gobelet_State::time_out(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state._recule_vers_la_zone_de_depart_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.chope du coin.recule vers la zone de depart");
#endif
      stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state._recule_vers_la_zone_de_depart_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::chope_gobelet_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::chope_gobelet_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission claps.chope du coin.chope gobelet");
#endif
  cout<<"coin : chope gobelet"<<endl;
  serialPrintf(master->getPortSerie(),"P5 \n");
  master->set_time_out(200);
  master->get_gestionnaire_mission()->get_element_robot()->gobelet_saisie();
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::chope_gobelet_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::~chope_du_coin_State() {
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::create(MAE_MURPHY & stm) {
    _doentry(stm);
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state._bf_droite_sur_le_verre_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.chope du coin.BF droite sur le verre");
#endif
      stm._mae_murphy_state._jeu_state._mission_claps_state._chope_du_coin_state._bf_droite_sur_le_verre_state.create(stm);
    }
}

// to manage the exit point 'sortie coin', defined because probably shared
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::_exit12(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps");
#endif
      if (master->get_gestionnaire_mission()->get_mission_claps()->is_clap_estrade_done()) {
        stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._sortie_de_zone_state);
#ifdef VERBOSE_STATE_MACHINE
        puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.sortie de zone");
#endif
        stm._mae_murphy_state._jeu_state._mission_claps_state._sortie_de_zone_state.create(stm);
      }
      else if (!master->get_gestionnaire_mission()->get_mission_claps()->is_clap_estrade_done()) {
        stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._claps_estrade_state);
#ifdef VERBOSE_STATE_MACHINE
        puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.claps estrade");
#endif
        stm._mae_murphy_state._jeu_state._mission_claps_state._claps_estrade_state.create(stm);
      }
    }
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission claps.chope du coin");
#endif
  // chope les 2 stands
  // le gobelet
  // et fait le claps du coin
  // attention faut pas avoir un gobelet dans le cul
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_claps_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::~mission_claps_State() {
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::create(MAE_MURPHY & stm) {
    _doentry(stm);
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_claps_state._waypoint_initial_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission claps.waypoint initial");
#endif
      stm._mae_murphy_state._jeu_state._mission_claps_state._waypoint_initial_state.create(stm);
    }
}

// to manage the exit point 'fin claps', defined because probably shared
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::_exit16(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._decision_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.decision");
#endif
      stm._mae_murphy_state._jeu_state._decision_state.create(stm);
    }
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission claps");
#endif
  // part vers le bas en direction des claps
  cout<<"MISSION CLAPS"<<endl;
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_claps_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::point_de_depart_State::orientation_vers_objectif_State::~orientation_vers_objectif_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::point_de_depart_State::orientation_vers_objectif_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state._point_de_depart_state._bf_droite_to_objectif_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission attrap balle et chiage.point de depart.BF droite to objectif");
#endif
      stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state._point_de_depart_state._bf_droite_to_objectif_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::point_de_depart_State::orientation_vers_objectif_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::point_de_depart_State::orientation_vers_objectif_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission attrap balle et chiage.point de depart.orientation vers objectif");
#endif
  // BCAP
  string ordre;
  ordre = "S3 " + master->get_gestionnaire()->get_cap_to_mission_str() + " \n";
  const char* ordre_c = ordre.c_str();
  serialPrintf(master->getPortSerie(),ordre_c);
  serialPrintf(master->getPortSerie(),"S7 1 \n"); 	// vitesse moyenne
  cout<<"ORIENTATION VERS MISSION : "<<ordre<<endl;
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::point_de_depart_State::orientation_vers_objectif_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state._point_de_depart_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::point_de_depart_State::BF_cap_mission_State::~BF_cap_mission_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::point_de_depart_State::BF_cap_mission_State::assFini(MAE_MURPHY & stm) {
    {
      stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state._point_de_depart_state._bf_cap_mission_state._doexit(stm);
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state._point_de_depart_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission attrap balle et chiage.point de depart");
#endif
      stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state._point_de_depart_state._exit9(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::point_de_depart_State::BF_cap_mission_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::point_de_depart_State::BF_cap_mission_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission attrap balle et chiage.point de depart.BF cap mission");
#endif
  // BF Droite vers objectif
  string ordre;
  ordre = "S3 " 
  	+ master->get_gestionnaire()->get_cap_mission_str() 
  	+ " \n";
  const char* ordre_c = ordre.c_str();
  serialPrintf(master->getPortSerie(),ordre_c); 
  cout<<"ORIENTATION VERS MISSION : "<<ordre<<endl;
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::point_de_depart_State::BF_cap_mission_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state._point_de_depart_state;
}

// perform the 'exit behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::point_de_depart_State::BF_cap_mission_State::_doexit(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute exit behavior of .MAE_MURPHY.Jeu.mission attrap balle et chiage.point de depart.BF cap mission");
#endif
  serialPrintf(master->getPortSerie(),"S7 0 \n"); 	// vitesse moyenne
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::point_de_depart_State::BF_droite_to_objectif_State::~BF_droite_to_objectif_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::point_de_depart_State::BF_droite_to_objectif_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state._point_de_depart_state._bf_cap_mission_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission attrap balle et chiage.point de depart.BF cap mission");
#endif
      stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state._point_de_depart_state._bf_cap_mission_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::point_de_depart_State::BF_droite_to_objectif_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::point_de_depart_State::BF_droite_to_objectif_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission attrap balle et chiage.point de depart.BF droite to objectif");
#endif
  // BF Droite vers objectif
  string ordre;
  ordre = "S5 "
  	+ master->get_gestionnaire()->get_x_mission_str() 
  	+ " "
  	+ master->get_gestionnaire()->get_y_mission_str() 
  	+ " "
  	+ master->get_gestionnaire()->get_cap_to_mission_str() 
  	+ " \n";
  const char* ordre_c = ordre.c_str();
  serialPrintf(master->getPortSerie(),ordre_c); 
  cout<<"BF droite vers MISSION : "<<ordre<<endl;
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::point_de_depart_State::BF_droite_to_objectif_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state._point_de_depart_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::point_de_depart_State::~point_de_depart_State() {
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::point_de_depart_State::create(MAE_MURPHY & stm) {
    _doentry(stm);
    {
      if (master->get_gestionnaire_mission()->is_mission_far()) {
        stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state._point_de_depart_state._orientation_vers_objectif_state);
#ifdef VERBOSE_STATE_MACHINE
        puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission attrap balle et chiage.point de depart.orientation vers objectif");
#endif
        stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state._point_de_depart_state._orientation_vers_objectif_state.create(stm);
      }
      else if (!master->get_gestionnaire_mission()->is_mission_far()) {
        stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state._point_de_depart_state._bf_cap_mission_state);
#ifdef VERBOSE_STATE_MACHINE
        puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission attrap balle et chiage.point de depart.BF cap mission");
#endif
        stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state._point_de_depart_state._bf_cap_mission_state.create(stm);
      }
    }
}

// to manage the exit point 'sortie waypoint', defined because probably shared
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::point_de_depart_State::_exit9(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state._orientation_avant_reculage_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission attrap balle et chiage.orientation avant reculage");
#endif
      stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state._orientation_avant_reculage_state.create(stm);
    }
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::point_de_depart_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission attrap balle et chiage.point de depart");
#endif
  // rejoindre devant la zone de depart
  // en BF droite sans cap final
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::point_de_depart_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::transition_avant_reculage_State::~transition_avant_reculage_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::transition_avant_reculage_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state._recalage_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission attrap balle et chiage.Recalage");
#endif
      stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state._recalage_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::transition_avant_reculage_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::transition_avant_reculage_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission attrap balle et chiage.transition avant reculage");
#endif
  if(master->is_Jaune()){
  // BF droite sur le gobelet 
  serialPrintf(master->getPortSerie(),"S5 -1234 996 0 \n");
  }
  if(master->is_Vert()){
  // BF droite sur le gobelet 
  serialPrintf(master->getPortSerie(),"S5 1234 996 180 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::transition_avant_reculage_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::sortie_State::~sortie_State() {
}

bool MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::sortie_State::_completion(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission attrap balle et chiage");
#endif
      stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state._exit10(stm);
      return (bool) 1;
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::sortie_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
  	_completion(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::sortie_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission attrap balle et chiage.sortie");
#endif
  cout<<"chiage : sortie de zone"<<endl;
  // fermeture capot arriere
  serialPrintf(master->getPortSerie(),"P3 \n");
  master->get_gestionnaire_mission()->get_mission_chiage_balle()->mission_remplie();
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::sortie_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::avance_State::~avance_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::avance_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state._sortie_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission attrap balle et chiage.sortie");
#endif
      stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state._sortie_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::avance_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::avance_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission attrap balle et chiage.avance");
#endif
  cout<<"chiage : avance/degagement"<<endl;
  // aller devant la zone de depart
  //BF avance de 400mm
  
  serialPrintf(master->getPortSerie(),"S7 1 \n"); 	// vitesse moyenne
  
  //serialPrintf(master->getPortSerie(),"S4 400 \n");
  
  if(master->is_Jaune()){
  // BF droite sur le gobelet 
  serialPrintf(master->getPortSerie(),"S5 -934 996 0 \n");
  }
  if(master->is_Vert()){
  // BF droite sur le gobelet 
  serialPrintf(master->getPortSerie(),"S5 934 996 180 \n");
  }
  
  //master->get_gestionnaire_mission()->get_mission_chiage_balle()->mission_remplie();
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::avance_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::drop_gobelet_State::~drop_gobelet_State() {
}

// to manage the event time_out
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::drop_gobelet_State::time_out(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state._avance_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission attrap balle et chiage.avance");
#endif
      stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state._avance_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::drop_gobelet_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::drop_gobelet_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission attrap balle et chiage.drop gobelet");
#endif
  cout<<"chiage : drop gobelet"<<endl;
  // drop si present
  master->set_time_out(200);
  if(master->get_gestionnaire_mission()->get_element_robot()->gobelet_present())
  {
  	master->get_gestionnaire_mission()->get_element_robot()->gobelet_relache();
  	master->get_gestionnaire_mission()->get_mission_chiage_balle()->drop_gobelet_done();
  	// drop gobelet
  	serialPrintf(master->getPortSerie(),"P6 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::drop_gobelet_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::drop_pop_corn_State::~drop_pop_corn_State() {
}

// to manage the event time_out
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::drop_pop_corn_State::time_out(MAE_MURPHY & stm) {
    {
      stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state._drop_pop_corn_state._doexit(stm);
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state._drop_gobelet_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission attrap balle et chiage.drop gobelet");
#endif
      stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state._drop_gobelet_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::drop_pop_corn_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::drop_pop_corn_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission attrap balle et chiage.drop pop corn");
#endif
  cout<<"chiage : drop pop-corn"<<endl;
  // drop si present
  if(master->get_gestionnaire_mission()->get_element_robot()->pop_corn_present())
  {
  	master->get_gestionnaire_mission()->get_element_robot()->pop_corn_decharge();
  	master->get_gestionnaire_mission()->get_mission_chiage_balle()->drop_pop_corn_done();
  	// ouverture du capot
  	serialPrintf(master->getPortSerie(),"P2 \n");
  	master->set_time_out(1200);
  }
  else
  {
  	master->set_time_out(200);
  }
}

// perform the 'exit behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::drop_pop_corn_State::_doexit(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute exit behavior of .MAE_MURPHY.Jeu.mission attrap balle et chiage.drop pop corn");
#endif
  // fermeture du capot
  serialPrintf(master->getPortSerie(),"P3 \n");
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::drop_pop_corn_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::capture_de_balle_State::~capture_de_balle_State() {
}

// to manage the event fin_montee_bras
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::capture_de_balle_State::fin_montee_bras(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state._drop_pop_corn_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission attrap balle et chiage.drop pop corn");
#endif
      stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state._drop_pop_corn_state.create(stm);
    }
}

// to manage the event time_out
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::capture_de_balle_State::time_out(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state._drop_pop_corn_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission attrap balle et chiage.drop pop corn");
#endif
      stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state._drop_pop_corn_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::capture_de_balle_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::capture_de_balle_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission attrap balle et chiage.capture de balle");
#endif
  cout<<"chiage : capture de balle"<<endl;
  if(!master->get_gestionnaire_mission()->get_mission_chiage_balle()->is_catch_ball())
  {
  	serialPrintf(master->getPortSerie(),"B2 \n");
  	master->get_gestionnaire_mission()->get_mission_chiage_balle()->catch_ball_done();
  	master->get_gestionnaire_mission()->get_element_robot()->balle_catch();
  }
  else
  {
  	master->set_time_out(200);
  }
  
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::capture_de_balle_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::Recalage_State::~Recalage_State() {
}

// to manage the event blocage
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::Recalage_State::blocage(MAE_MURPHY & stm) {
    {
      stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state._recalage_state._doexit(stm);
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state._capture_de_balle_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission attrap balle et chiage.capture de balle");
#endif
      stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state._capture_de_balle_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::Recalage_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::Recalage_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission attrap balle et chiage.Recalage");
#endif
  cout<<"chiage : recalage"<<endl;
  // vers le centre de la table
  serialPrintf(master->getPortSerie(),"S2 \n");
  
  // set X, Y CAP??
}

// perform the 'exit behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::Recalage_State::_doexit(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute exit behavior of .MAE_MURPHY.Jeu.mission attrap balle et chiage.Recalage");
#endif
  if(master->is_Jaune()){
  	cout<<"SET X Y CAP ORIGIN, COULEUR JAUNE"<<endl;
  	// X = -1500 + 70 +96 = -1334
  	// terrain, bordure, robot (axe de rotation)
  	serialPrintf(master->getPortSerie(),"S0 -1334 -1 0 \n");
  }
  if(master->is_Vert()){
  	cout<<"SET X Y CAP ORIGIN, COULEUR VERT"<<endl;
  	serialPrintf(master->getPortSerie(),"S0 1334 -1 180 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::Recalage_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::orientation_avant_reculage_State::~orientation_avant_reculage_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::orientation_avant_reculage_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state._transition_avant_reculage_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission attrap balle et chiage.transition avant reculage");
#endif
      stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state._transition_avant_reculage_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::orientation_avant_reculage_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::orientation_avant_reculage_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission attrap balle et chiage.orientation avant reculage");
#endif
  cout<<"chiage : orientation sur zone de depart"<<endl;
  if(master->is_Jaune()){
  // vers le centre de la table
  serialPrintf(master->getPortSerie(),"S3 0 \n");
  }
  if(master->is_Vert()){
  serialPrintf(master->getPortSerie(),"S3 180 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::orientation_avant_reculage_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::~mission_attrap_balle_et_chiage_State() {
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::create(MAE_MURPHY & stm) {
    _doentry(stm);
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state._point_de_depart_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission attrap balle et chiage.point de depart");
#endif
      stm._mae_murphy_state._jeu_state._mission_attrap_balle_et_chiage_state._point_de_depart_state.create(stm);
    }
}

// to manage the exit point 'sortie mission drop', defined because probably shared
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::_exit10(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._decision_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.decision");
#endif
      stm._mae_murphy_state._jeu_state._decision_state.create(stm);
    }
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission attrap balle et chiage");
#endif
  // de but : pres de zone de depart
  cout<<"MISSION CHIAGE & BALL"<<endl;
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::sortie_de_la_zone_de_depart_State::~sortie_de_la_zone_de_depart_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::sortie_de_la_zone_de_depart_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_de_gobelet_escalier_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.capture de gobelet escalier");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_de_gobelet_escalier_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::sortie_de_la_zone_de_depart_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::sortie_de_la_zone_de_depart_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission pillage distrib.sortie de la zone de depart");
#endif
  // avance de 400mm
  serialPrintf(master->getPortSerie(),"S4 400 \n");
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::sortie_de_la_zone_de_depart_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::sortie_zone_State::~sortie_zone_State() {
}

bool MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::sortie_zone_State::_completion(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._exit8(stm);
      return (bool) 1;
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::sortie_zone_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
  	_completion(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::sortie_zone_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission pillage distrib.sortie zone");
#endif
  // on se remet devant la zone de depart
  // BF droite vers la zone enemie
  
  if(master->get_gestionnaire_mission()->get_mission_distrib()->is_netoyage_zone_done() 
  	&& master->get_gestionnaire_mission()->get_mission_distrib()->is_capture_gobelet_done())
  {
  	master->get_gestionnaire_mission()->get_mission_distrib()->mission_remplie();
  }
  cout<<"sortie de zone"<<endl;
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::sortie_zone_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::rejoindre_le_point_de_depart_mission_State::orientation_vers_objectif_State::~orientation_vers_objectif_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::rejoindre_le_point_de_depart_mission_State::orientation_vers_objectif_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._rejoindre_le_point_de_depart_mission_state._bf_droite_vers_lobjectif_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.rejoindre le point de depart mission.BF droite vers l'objectif");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._rejoindre_le_point_de_depart_mission_state._bf_droite_vers_lobjectif_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::rejoindre_le_point_de_depart_mission_State::orientation_vers_objectif_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::rejoindre_le_point_de_depart_mission_State::orientation_vers_objectif_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission pillage distrib.rejoindre le point de depart mission.orientation vers objectif");
#endif
  // BCAP
  string ordre;
  ordre = "S3 " + master->get_gestionnaire()->get_cap_to_mission_str() + " \n";
  const char* ordre_c = ordre.c_str();
  serialPrintf(master->getPortSerie(),"S7 1 \n"); 	// vitesse moyenne
  serialPrintf(master->getPortSerie(),ordre_c);
  cout<<"ORIENTATION VERS MISSION : "<<ordre<<endl;
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::rejoindre_le_point_de_depart_mission_State::orientation_vers_objectif_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._rejoindre_le_point_de_depart_mission_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::rejoindre_le_point_de_depart_mission_State::orientation_cap_mission_State::~orientation_cap_mission_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::rejoindre_le_point_de_depart_mission_State::orientation_cap_mission_State::assFini(MAE_MURPHY & stm) {
    {
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._rejoindre_le_point_de_depart_mission_state._orientation_cap_mission_state._doexit(stm);
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._rejoindre_le_point_de_depart_mission_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.rejoindre le point de depart mission");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._rejoindre_le_point_de_depart_mission_state._exit7(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::rejoindre_le_point_de_depart_mission_State::orientation_cap_mission_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::rejoindre_le_point_de_depart_mission_State::orientation_cap_mission_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission pillage distrib.rejoindre le point de depart mission.orientation cap mission");
#endif
  // BF Droite vers objectif
  string ordre;
  ordre = "S3 " 
  	+ master->get_gestionnaire()->get_cap_mission_str() 
  	+ " \n";
  const char* ordre_c = ordre.c_str();
  serialPrintf(master->getPortSerie(),ordre_c); 
  cout<<"ORIENTATION VERS MISSION : "<<ordre<<endl;
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::rejoindre_le_point_de_depart_mission_State::orientation_cap_mission_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._rejoindre_le_point_de_depart_mission_state;
}

// perform the 'exit behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::rejoindre_le_point_de_depart_mission_State::orientation_cap_mission_State::_doexit(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute exit behavior of .MAE_MURPHY.Jeu.mission pillage distrib.rejoindre le point de depart mission.orientation cap mission");
#endif
  serialPrintf(master->getPortSerie(),"S7 0 \n"); 	// vitesse moyenne
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::rejoindre_le_point_de_depart_mission_State::BF_droite_vers_lobjectif_State::~BF_droite_vers_lobjectif_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::rejoindre_le_point_de_depart_mission_State::BF_droite_vers_lobjectif_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._rejoindre_le_point_de_depart_mission_state._orientation_cap_mission_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.rejoindre le point de depart mission.orientation cap mission");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._rejoindre_le_point_de_depart_mission_state._orientation_cap_mission_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::rejoindre_le_point_de_depart_mission_State::BF_droite_vers_lobjectif_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::rejoindre_le_point_de_depart_mission_State::BF_droite_vers_lobjectif_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission pillage distrib.rejoindre le point de depart mission.BF droite vers l'objectif");
#endif
  // BF Droite vers objectif
  string ordre;
  ordre = "S5 "
  	+ master->get_gestionnaire()->get_x_mission_str() 
  	+ " "
  	+ master->get_gestionnaire()->get_y_mission_str() 
  	+ " "
  	+ master->get_gestionnaire()->get_cap_to_mission_str() 
  	+ " \n";
  const char* ordre_c = ordre.c_str();
  serialPrintf(master->getPortSerie(),ordre_c); 
  cout<<"BF droite vers MISSION : "<<ordre<<endl;
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::rejoindre_le_point_de_depart_mission_State::BF_droite_vers_lobjectif_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._rejoindre_le_point_de_depart_mission_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::rejoindre_le_point_de_depart_mission_State::~rejoindre_le_point_de_depart_mission_State() {
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::rejoindre_le_point_de_depart_mission_State::create(MAE_MURPHY & stm) {
    _doentry(stm);
    {
      if (master->get_gestionnaire_mission()->is_mission_far()) {
        stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._rejoindre_le_point_de_depart_mission_state._orientation_vers_objectif_state);
#ifdef VERBOSE_STATE_MACHINE
        puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.rejoindre le point de depart mission.orientation vers objectif");
#endif
        stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._rejoindre_le_point_de_depart_mission_state._orientation_vers_objectif_state.create(stm);
      }
      else if (!master->get_gestionnaire_mission()->is_mission_far()) {
        stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._rejoindre_le_point_de_depart_mission_state._orientation_cap_mission_state);
#ifdef VERBOSE_STATE_MACHINE
        puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.rejoindre le point de depart mission.orientation cap mission");
#endif
        stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._rejoindre_le_point_de_depart_mission_state._orientation_cap_mission_state.create(stm);
      }
    }
}

// to manage the exit point 'sortie', defined because probably shared
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::rejoindre_le_point_de_depart_mission_State::_exit7(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib");
#endif
      if (master->get_gestionnaire_mission()->get_mission_distrib()->is_capture_gobelet_done()) {
        stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stands_cote_escalier_state);
#ifdef VERBOSE_STATE_MACHINE
        puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.capture stands cote escalier");
#endif
        stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stands_cote_escalier_state.create(stm);
      }
      else if (!master->get_gestionnaire_mission()->get_mission_distrib()->is_capture_gobelet_done() ) {
        if (!master->get_gestionnaire_mission()->get_element_robot()->gobelet_present()) {
          stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_de_gobelet_escalier_state);
#ifdef VERBOSE_STATE_MACHINE
          puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.capture de gobelet escalier");
#endif
          stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_de_gobelet_escalier_state.create(stm);
        }
        else if (master->get_gestionnaire_mission()->get_element_robot()->gobelet_present()) {
          if (!master->get_gestionnaire_mission()->get_mission_distrib()->is_netoyage_zone_done() ) {
            stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stands_cote_escalier_state);
#ifdef VERBOSE_STATE_MACHINE
            puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.capture stands cote escalier");
#endif
            stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stands_cote_escalier_state.create(stm);
          }
          else if (master->get_gestionnaire_mission()->get_mission_distrib()->is_netoyage_zone_done() ) {
            stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._sortie_zone_state);
#ifdef VERBOSE_STATE_MACHINE
            puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.sortie zone");
#endif
            stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._sortie_zone_state.create(stm);
          }
        }
      }
    }
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::rejoindre_le_point_de_depart_mission_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission pillage distrib.rejoindre le point de depart mission");
#endif
  // devant la zone de depart
  // on check ou on est puis BF cap vers le point, puis BF droite
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::rejoindre_le_point_de_depart_mission_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::avance_State::~avance_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::avance_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._vidage_distributeur_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.vidage distributeur");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._vidage_distributeur_state._exit6(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::avance_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::avance_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission pillage distrib.vidage distributeur.avance");
#endif
  cout<<"distrib : BF avance sortie"<<endl;
  serialPrintf(master->getPortSerie(),"E1 \n"); // activation de l'evitement
  if(master->is_Jaune()){
  // BF droite sur le gobelet 
  serialPrintf(master->getPortSerie(),"S5 -848 996 -90 \n");
  }
  if(master->is_Vert()){
  // BF droite sur le gobelet 
  serialPrintf(master->getPortSerie(),"S5 848 996 -90 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::avance_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._vidage_distributeur_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::orientation_vers_sortie_de_zone_State::~orientation_vers_sortie_de_zone_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::orientation_vers_sortie_de_zone_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._vidage_distributeur_state._avance_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.vidage distributeur.avance");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._vidage_distributeur_state._avance_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::orientation_vers_sortie_de_zone_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::orientation_vers_sortie_de_zone_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission pillage distrib.vidage distributeur.orientation vers sortie de zone");
#endif
  cout<<"distrib : orientation vers sortie"<<endl;
  if(master->is_Jaune()){
  serialPrintf(master->getPortSerie(),"S3 -90 \n");
  }
  if(master->is_Vert()){
  serialPrintf(master->getPortSerie(),"S3 -90 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::orientation_vers_sortie_de_zone_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._vidage_distributeur_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::recule_State::~recule_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::recule_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._vidage_distributeur_state._orientation_vers_sortie_de_zone_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.vidage distributeur.orientation vers sortie de zone");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._vidage_distributeur_state._orientation_vers_sortie_de_zone_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::recule_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::recule_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission pillage distrib.vidage distributeur.recule");
#endif
  cout<<"distrib : recule/degage/decrochage"<<endl;
  //serialPrintf(master->getPortSerie(),"S4 -300 \n");
  if(master->is_Jaune()){
  serialPrintf(master->getPortSerie(),"S5 -848 1436 135 \n");
  }
  if(master->is_Vert()){
  serialPrintf(master->getPortSerie(),"S5 848 1436 45 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::recule_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._vidage_distributeur_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::pompage_State::~pompage_State() {
}

// to manage the event distrib_deboite
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::pompage_State::distrib_deboite(MAE_MURPHY & stm) {
    {
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._vidage_distributeur_state._pompage_state._doexit(stm);
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._vidage_distributeur_state._recule_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.vidage distributeur.recule");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._vidage_distributeur_state._recule_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::pompage_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::pompage_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission pillage distrib.vidage distributeur.pompage");
#endif
  cout<<"distrib : pompage pilote"<<endl;
  serialPrintf(master->getPortSerie(),"P0 \n");
}

// perform the 'exit behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::pompage_State::_doexit(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute exit behavior of .MAE_MURPHY.Jeu.mission pillage distrib.vidage distributeur.pompage");
#endif
  master->get_gestionnaire_mission()->get_mission_distrib()->netoyage_zone_done();
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::pompage_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._vidage_distributeur_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::SET_Y_CAP_State::~SET_Y_CAP_State() {
}

bool MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::SET_Y_CAP_State::_completion(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._vidage_distributeur_state._pompage_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.vidage distributeur.pompage");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._vidage_distributeur_state._pompage_state.create(stm);
      return (bool) 1;
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::SET_Y_CAP_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
  	_completion(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::SET_Y_CAP_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission pillage distrib.vidage distributeur.SET Y CAP");
#endif
  cout<<"distrib : set Y CAP"<<endl;
  if(master->is_Jaune()){
  // BF droite sur le gobelet 
  serialPrintf(master->getPortSerie(),"S0 -1 1794 90 \n");
  }
  if(master->is_Vert()){
  // BF droite sur le gobelet 
  serialPrintf(master->getPortSerie(),"S0 -1 1794 90 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::SET_Y_CAP_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._vidage_distributeur_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::BF_avance_jusquau_blocage_State::~BF_avance_jusquau_blocage_State() {
}

// to manage the event blocage
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::BF_avance_jusquau_blocage_State::blocage(MAE_MURPHY & stm) {
    _do(stm);
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._vidage_distributeur_state._set_y_cap_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.vidage distributeur.SET Y CAP");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._vidage_distributeur_state._set_y_cap_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::BF_avance_jusquau_blocage_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::BF_avance_jusquau_blocage_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission pillage distrib.vidage distributeur.BF avance jusquau blocage");
#endif
  cout<<"distrib : avance jusqu'au blocage"<<endl;
  serialPrintf(master->getPortSerie(),"S4 200 \n");
}

// perform the 'do activity'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::BF_avance_jusquau_blocage_State::_do(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute do behavior of .MAE_MURPHY.Jeu.mission pillage distrib.vidage distributeur.BF avance jusquau blocage");
#endif
  serialPrintf(master->getPortSerie(),"S1 \n");
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::BF_avance_jusquau_blocage_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._vidage_distributeur_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::BF_droite_sur_distrib_State::~BF_droite_sur_distrib_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::BF_droite_sur_distrib_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._vidage_distributeur_state._bf_avance_jusquau_blocage_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.vidage distributeur.BF avance jusquau blocage");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._vidage_distributeur_state._bf_avance_jusquau_blocage_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::BF_droite_sur_distrib_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::BF_droite_sur_distrib_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission pillage distrib.vidage distributeur.BF droite sur distrib");
#endif
  cout<<"distrib : BF droite sur cible"<<endl;
  if(master->is_Jaune()){
  // BF droite sur le gobelet 
  serialPrintf(master->getPortSerie(),"S5 -1050 1700 90 \n");
  }
  if(master->is_Vert()){
  // BF droite sur le gobelet 
  serialPrintf(master->getPortSerie(),"S5 1050 1700 90 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::BF_droite_sur_distrib_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._vidage_distributeur_state;
}

// to manage the event blocage
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::BF_droite_sur_distrib_State::blocage(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._vidage_distributeur_state._bf_avance_jusquau_blocage_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.vidage distributeur.BF avance jusquau blocage");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._vidage_distributeur_state._bf_avance_jusquau_blocage_state.create(stm);
    }
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::~vidage_distributeur_State() {
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::create(MAE_MURPHY & stm) {
    _doentry(stm);
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._vidage_distributeur_state._bf_droite_sur_distrib_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.vidage distributeur.BF droite sur distrib");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._vidage_distributeur_state._bf_droite_sur_distrib_state.create(stm);
    }
}

// to manage the exit point 'sortie pompage', defined because probably shared
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::_exit6(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._sortie_zone_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.sortie zone");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._sortie_zone_state.create(stm);
    }
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission pillage distrib.vidage distributeur");
#endif
  // element_robot.aspire();
  // mission_distrib.netoyage_zone_done(); 
  cout<<"vidage distributeur"<<endl;
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stand_bordure_State::BF_cap_vers_objectif_State::~BF_cap_vers_objectif_State() {
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stand_bordure_State::BF_cap_vers_objectif_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stand_bordure_State::BF_cap_vers_objectif_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission pillage distrib.capture stand bordure.BF cap vers objectif");
#endif
  cout<<"stands bodure : orientation sur cible"<<endl;
  if(master->is_Jaune()){
  serialPrintf(master->getPortSerie(),"S3 90 \n");
  }
  if(master->is_Vert()){
  serialPrintf(master->getPortSerie(),"S3 90 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stand_bordure_State::BF_cap_vers_objectif_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stand_bordure_state;
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stand_bordure_State::BF_cap_vers_objectif_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stand_bordure_state._ouverture_pince_cote_bordure_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.capture stand bordure.ouverture pince cote bordure");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stand_bordure_state._ouverture_pince_cote_bordure_state.create(stm);
    }
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stand_bordure_State::recule_State::~recule_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stand_bordure_State::recule_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stand_bordure_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.capture stand bordure");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stand_bordure_state._exit5(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stand_bordure_State::recule_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stand_bordure_State::recule_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission pillage distrib.capture stand bordure.recule");
#endif
  cout<<"stands bordure : recule/degage de la zone"<<endl;
  serialPrintf(master->getPortSerie(),"S4 -300 \n");
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stand_bordure_State::recule_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stand_bordure_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stand_bordure_State::chope_State::~chope_State() {
}

// to manage the event pince_stand_by
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stand_bordure_State::chope_State::pince_stand_by(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stand_bordure_state._recule_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.capture stand bordure.recule");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stand_bordure_state._recule_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stand_bordure_State::chope_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stand_bordure_State::chope_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission pillage distrib.capture stand bordure.chope");
#endif
  cout<<"stands bordure : chope de stand"<<endl;
  if(master->is_Jaune()){
  serialPrintf(master->getPortSerie(),"G1 \n");
  }
  if(master->is_Vert()){
  serialPrintf(master->getPortSerie(),"D1 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stand_bordure_State::chope_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stand_bordure_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stand_bordure_State::BF_avance_State::~BF_avance_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stand_bordure_State::BF_avance_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stand_bordure_state._chope_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.capture stand bordure.chope");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stand_bordure_state._chope_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stand_bordure_State::BF_avance_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stand_bordure_State::BF_avance_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission pillage distrib.capture stand bordure.BF avance");
#endif
  cout<<"stands bordure : avance pour capture"<<endl;
  serialPrintf(master->getPortSerie(),"S4 245 \n");
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stand_bordure_State::BF_avance_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stand_bordure_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stand_bordure_State::ouverture_pince_cote_bordure_State::~ouverture_pince_cote_bordure_State() {
}

// to manage the event pince_ouverte
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stand_bordure_State::ouverture_pince_cote_bordure_State::pince_ouverte(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stand_bordure_state._bf_avance_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.capture stand bordure.BF avance");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stand_bordure_state._bf_avance_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stand_bordure_State::ouverture_pince_cote_bordure_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stand_bordure_State::ouverture_pince_cote_bordure_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission pillage distrib.capture stand bordure.ouverture pince cote bordure");
#endif
  cout<<"stands bordure : ouverture de pince"<<endl;
  if(master->is_Jaune()){
  serialPrintf(master->getPortSerie(),"G0 \n");
  }
  if(master->is_Vert()){
  serialPrintf(master->getPortSerie(),"D0 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stand_bordure_State::ouverture_pince_cote_bordure_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stand_bordure_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stand_bordure_State::~capture_stand_bordure_State() {
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stand_bordure_State::create(MAE_MURPHY & stm) {
    _doentry(stm);
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stand_bordure_state._bf_cap_vers_objectif_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.capture stand bordure.BF cap vers objectif");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stand_bordure_state._bf_cap_vers_objectif_state.create(stm);
    }
}

// to manage the exit point 'sortie stand bordure', defined because probably shared
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stand_bordure_State::_exit5(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._vidage_distributeur_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.vidage distributeur");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._vidage_distributeur_state.create(stm);
    }
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stand_bordure_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission pillage distrib.capture stand bordure");
#endif
  // Jaune : pile gauche +1
  // element_robot.pile_gauche_incr();
  
  
  // Vert : pile droite +1
  // element_robot.pile_droite_incr();
  cout<<"capture de stand bordure"<<endl;
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stand_bordure_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::BF_cap_initial_35deg_State::~BF_cap_initial_35deg_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::BF_cap_initial_35deg_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stands_cote_escalier_state._bf_droite_vers_le_stand_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.capture stands cote escalier.BF droite vers le stand");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stands_cote_escalier_state._bf_droite_vers_le_stand_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::BF_cap_initial_35deg_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::BF_cap_initial_35deg_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission pillage distrib.capture stands cote escalier.BF cap initial 35deg");
#endif
  serialPrintf(master->getPortSerie(),"S7 0 \n"); 	// vitesse moyenne
  cout<<"stands escalier : orientation sur cible"<<endl;
  serialPrintf(master->getPortSerie(),"E0 \n"); // desactivation de l'evitement
  if(master->is_Jaune()){
  serialPrintf(master->getPortSerie(),"S3 90 \n");
  }
  if(master->is_Vert()){
  serialPrintf(master->getPortSerie(),"S3 90 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::BF_cap_initial_35deg_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stands_cote_escalier_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::recule_State::~recule_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::recule_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stands_cote_escalier_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.capture stands cote escalier");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stands_cote_escalier_state._exit4(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::recule_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::recule_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission pillage distrib.capture stands cote escalier.recule");
#endif
  cout<<"stands escalier : recule/degage de la zone"<<endl;
  
  if(master->is_Jaune()){
  serialPrintf(master->getPortSerie(),"S5 -1185 1470 0 \n");
  }
  if(master->is_Vert()){
  serialPrintf(master->getPortSerie(),"S5 1185 1470 180 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::recule_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stands_cote_escalier_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::chope_2_State::~chope_2_State() {
}

// to manage the event pince_stand_by
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::chope_2_State::pince_stand_by(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stands_cote_escalier_state._recule_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.capture stands cote escalier.recule");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stands_cote_escalier_state._recule_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::chope_2_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::chope_2_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission pillage distrib.capture stands cote escalier.chope 2");
#endif
  cout<<"stands escalier : chope second stand"<<endl;
  if(master->is_Jaune()){
  serialPrintf(master->getPortSerie(),"D1 \n");
  }
  if(master->is_Vert()){
  serialPrintf(master->getPortSerie(),"G1 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::chope_2_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stands_cote_escalier_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::BF_avance_seconde_State::~BF_avance_seconde_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::BF_avance_seconde_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stands_cote_escalier_state._chope_2_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.capture stands cote escalier.chope 2");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stands_cote_escalier_state._chope_2_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::BF_avance_seconde_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::BF_avance_seconde_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission pillage distrib.capture stands cote escalier.BF avance seconde");
#endif
  cout<<"stands escalier : BF avance sur 2nd stand"<<endl;
  serialPrintf(master->getPortSerie(),"S4 106 \n");
  
  // check si blocage, sortie
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::BF_avance_seconde_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stands_cote_escalier_state;
}

// to manage the event blocage
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::BF_avance_seconde_State::blocage(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stands_cote_escalier_state._chope_2_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.capture stands cote escalier.chope 2");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stands_cote_escalier_state._chope_2_state.create(stm);
    }
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::ouverture_pince_cote_escalier_seconde_State::~ouverture_pince_cote_escalier_seconde_State() {
}

// to manage the event pince_ouverte
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::ouverture_pince_cote_escalier_seconde_State::pince_ouverte(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stands_cote_escalier_state._bf_avance_seconde_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.capture stands cote escalier.BF avance seconde");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stands_cote_escalier_state._bf_avance_seconde_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::ouverture_pince_cote_escalier_seconde_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::ouverture_pince_cote_escalier_seconde_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission pillage distrib.capture stands cote escalier.ouverture pince cote escalier seconde");
#endif
  cout<<"stands escalier : re-ouverture de pince"<<endl;
  if(master->is_Jaune()){
  serialPrintf(master->getPortSerie(),"D0 \n");
  }
  if(master->is_Vert()){
  serialPrintf(master->getPortSerie(),"G0 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::ouverture_pince_cote_escalier_seconde_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stands_cote_escalier_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::chope_1_State::~chope_1_State() {
}

// to manage the event pince_stand_by
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::chope_1_State::pince_stand_by(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stands_cote_escalier_state._ouverture_pince_cote_escalier_seconde_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.capture stands cote escalier.ouverture pince cote escalier seconde");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stands_cote_escalier_state._ouverture_pince_cote_escalier_seconde_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::chope_1_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::chope_1_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission pillage distrib.capture stands cote escalier.chope 1");
#endif
  cout<<"stands escalier : chope stand 1"<<endl;
  if(master->is_Jaune()){
  serialPrintf(master->getPortSerie(),"D1 \n");
  }
  if(master->is_Vert()){
  serialPrintf(master->getPortSerie(),"G1 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::chope_1_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stands_cote_escalier_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::BF_avance_State::~BF_avance_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::BF_avance_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stands_cote_escalier_state._chope_1_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.capture stands cote escalier.chope 1");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stands_cote_escalier_state._chope_1_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::BF_avance_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::BF_avance_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission pillage distrib.capture stands cote escalier.BF avance");
#endif
  serialPrintf(master->getPortSerie(),"S7 0 \n"); 	// vitesse lente
  cout<<"stands escalier : avance sur 1er stand"<<endl;
  serialPrintf(master->getPortSerie(),"S4 250 \n");
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::BF_avance_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stands_cote_escalier_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::ouverture_pince_cote_escalier_State::~ouverture_pince_cote_escalier_State() {
}

// to manage the event pince_ouverte
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::ouverture_pince_cote_escalier_State::pince_ouverte(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stands_cote_escalier_state._bf_avance_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.capture stands cote escalier.BF avance");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stands_cote_escalier_state._bf_avance_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::ouverture_pince_cote_escalier_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::ouverture_pince_cote_escalier_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission pillage distrib.capture stands cote escalier.ouverture pince cote escalier");
#endif
  cout<<"stands escalier : ouverture de pince"<<endl;
  if(master->is_Jaune()){
  serialPrintf(master->getPortSerie(),"D0 \n");
  }
  if(master->is_Vert()){
  serialPrintf(master->getPortSerie(),"G0 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::ouverture_pince_cote_escalier_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stands_cote_escalier_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::BF_droite_vers_le_stand_State::~BF_droite_vers_le_stand_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::BF_droite_vers_le_stand_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stands_cote_escalier_state._ouverture_pince_cote_escalier_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.capture stands cote escalier.ouverture pince cote escalier");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stands_cote_escalier_state._ouverture_pince_cote_escalier_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::BF_droite_vers_le_stand_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::BF_droite_vers_le_stand_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission pillage distrib.capture stands cote escalier.BF droite vers le stand");
#endif
  cout<<"stands escalier : BF droite sur cible"<<endl;
  if(master->is_Jaune()){
  // BF droite sur le gobelet 
  // y = 1664 -120
  serialPrintf(master->getPortSerie(),"S5 -886 1436 90 \n");
  }
  if(master->is_Vert()){
  // BF droite sur le gobelet 
  serialPrintf(master->getPortSerie(),"S5 886 1436 90 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::BF_droite_vers_le_stand_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stands_cote_escalier_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::~capture_stands_cote_escalier_State() {
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::create(MAE_MURPHY & stm) {
    _doentry(stm);
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stands_cote_escalier_state._bf_cap_initial_35deg_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.capture stands cote escalier.BF cap initial 35deg");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stands_cote_escalier_state._bf_cap_initial_35deg_state.create(stm);
    }
}

// to manage the exit point 'sortie chope stands escalier', defined because probably shared
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::_exit4(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stand_bordure_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.capture stand bordure");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stand_bordure_state.create(stm);
    }
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission pillage distrib.capture stands cote escalier");
#endif
  /// Jaune : pile droite +2
  // element_robot.pile_droite_incr();
  // element_robot.pile_droite_incr();
  
  /// Vert : pile gauche +2
  // element_robot.pile_gauche_incr();
  // element_robot.pile_gauche_incr();
  cout<<"capture de stand escalier"<<endl;
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_de_gobelet_escalier_State::deplacement_cible_State::~deplacement_cible_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_de_gobelet_escalier_State::deplacement_cible_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_de_gobelet_escalier_state._capture_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.capture de gobelet escalier.capture");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_de_gobelet_escalier_state._capture_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_de_gobelet_escalier_State::deplacement_cible_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_de_gobelet_escalier_State::deplacement_cible_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission pillage distrib.capture de gobelet escalier.deplacement cible");
#endif
  serialPrintf(master->getPortSerie(),"S7 0 \n"); 	// vitesse lente
  cout<<"gobelet : deplacement sur cible"<<endl;
  if(master->is_Jaune()){
  // BF droite sur le gobelet 
  serialPrintf(master->getPortSerie(),"S5 -550 1238 35 \n");
  }
  if(master->is_Vert()){
  // BF droite sur le gobelet 
  serialPrintf(master->getPortSerie(),"S5 550 1238 145 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_de_gobelet_escalier_State::deplacement_cible_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_de_gobelet_escalier_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_de_gobelet_escalier_State::recule_State::~recule_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_de_gobelet_escalier_State::recule_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_de_gobelet_escalier_state._bf_cap_vers_la_zone_de_distrib_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.capture de gobelet escalier.BF cap vers la zone de distrib");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_de_gobelet_escalier_state._bf_cap_vers_la_zone_de_distrib_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_de_gobelet_escalier_State::recule_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_de_gobelet_escalier_State::recule_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission pillage distrib.capture de gobelet escalier.recule");
#endif
  serialPrintf(master->getPortSerie(),"S7 1 \n"); 	// vitesse moyenne
  cout<<"gobelet : recule"<<endl;
  serialPrintf(master->getPortSerie(),"S4 -200 \n");
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_de_gobelet_escalier_State::recule_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_de_gobelet_escalier_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_de_gobelet_escalier_State::BF_cap_vers_la_zone_de_distrib_State::~BF_cap_vers_la_zone_de_distrib_State() {
}

// to manage the event assFini
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_de_gobelet_escalier_State::BF_cap_vers_la_zone_de_distrib_State::assFini(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_de_gobelet_escalier_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.capture de gobelet escalier");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_de_gobelet_escalier_state._exit3(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_de_gobelet_escalier_State::BF_cap_vers_la_zone_de_distrib_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_de_gobelet_escalier_State::BF_cap_vers_la_zone_de_distrib_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission pillage distrib.capture de gobelet escalier.BF cap vers la zone de distrib");
#endif
  cout<<"gobelet : cap sur zone suivante"<<endl;
  if(master->is_Jaune()){
  // BF cap
  serialPrintf(master->getPortSerie(),"S3 132 \n");
  }
  if(master->is_Vert()){
  serialPrintf(master->getPortSerie(),"S3 48 \n");
  }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_de_gobelet_escalier_State::BF_cap_vers_la_zone_de_distrib_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_de_gobelet_escalier_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_de_gobelet_escalier_State::capture_State::~capture_State() {
}

// to manage the event time_out
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_de_gobelet_escalier_State::capture_State::time_out(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_de_gobelet_escalier_state._recule_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.capture de gobelet escalier.recule");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_de_gobelet_escalier_state._recule_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_de_gobelet_escalier_State::capture_State::create(MAE_MURPHY & stm) {
  	_doentry(stm);
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_de_gobelet_escalier_State::capture_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission pillage distrib.capture de gobelet escalier.capture");
#endif
  cout<<"gobelet : capture"<<endl;
  // ferme le pince interne souleve
  serialPrintf(master->getPortSerie(),"P5 \n");
  master->set_time_out(300);
  
  master->get_gestionnaire_mission()->get_mission_distrib()->capture_gobelet_done();
  master->get_gestionnaire_mission()->get_element_robot()->gobelet_saisie();
  cout<<"gobelet attrape!"<<endl;
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_de_gobelet_escalier_State::capture_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_de_gobelet_escalier_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_de_gobelet_escalier_State::~capture_de_gobelet_escalier_State() {
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_de_gobelet_escalier_State::create(MAE_MURPHY & stm) {
    _doentry(stm);
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_de_gobelet_escalier_state._deplacement_cible_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.capture de gobelet escalier.deplacement cible");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_de_gobelet_escalier_state._deplacement_cible_state.create(stm);
    }
}

// to manage the exit point 'sortie capture gobelet', defined because probably shared
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_de_gobelet_escalier_State::_exit3(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib");
#endif
      if (!master->get_gestionnaire_mission()->get_mission_distrib()->is_netoyage_zone_done() ) {
        stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stands_cote_escalier_state);
#ifdef VERBOSE_STATE_MACHINE
        puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.capture stands cote escalier");
#endif
        stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._capture_stands_cote_escalier_state.create(stm);
      }
      else if (master->get_gestionnaire_mission()->get_mission_distrib()->is_netoyage_zone_done() ) {
        stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._sortie_zone_state);
#ifdef VERBOSE_STATE_MACHINE
        puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.sortie zone");
#endif
        stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._sortie_zone_state.create(stm);
      }
    }
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_de_gobelet_escalier_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission pillage distrib.capture de gobelet escalier");
#endif
  // capture d gobelet pres de l'escalier
  cout<<"capture de gobelet"<<endl;
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_de_gobelet_escalier_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::~mission_pillage_distrib_State() {
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::create(MAE_MURPHY & stm) {
    _doentry(stm);
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._rejoindre_le_point_de_depart_mission_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.mission pillage distrib.rejoindre le point de depart mission");
#endif
      stm._mae_murphy_state._jeu_state._mission_pillage_distrib_state._rejoindre_le_point_de_depart_mission_state.create(stm);
    }
}

// to manage the exit point 'sortie pillage distrib', defined because probably shared
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::_exit8(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._jeu_state._decision_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Jeu.decision");
#endif
      stm._mae_murphy_state._jeu_state._decision_state.create(stm);
    }
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu.mission pillage distrib");
#endif
  // pille le distrib et les pillier autour
  // mission quart haut, capture du gobelet pres de l'escalier
  cout<<"MISSION PILLAGE DISTRIB"<<endl;
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state._jeu_state;
}

MAE_MURPHY::MAE_MURPHY_State::Jeu_State::~Jeu_State() {
}

// to manage the event evitement
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::evitement(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._evitement_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Evitement");
#endif
      stm._mae_murphy_state._evitement_state.create(stm);
    }
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::create(MAE_MURPHY & stm) {
    _doentry(stm);
    {
      if (master->get_gestionnaire_mission()->commencement() == true) {
        stm._set_currentState(stm._mae_murphy_state._jeu_state._sortie_de_zone_de_depart_state);
#ifdef VERBOSE_STATE_MACHINE
        puts("DEBUG : current state is now .MAE_MURPHY.Jeu.sortie de zone de depart");
#endif
        stm._mae_murphy_state._jeu_state._sortie_de_zone_de_depart_state.create(stm);
      }
      else if (master->get_gestionnaire_mission()->commencement() == false) {
        stm._set_currentState(stm._mae_murphy_state._jeu_state._decision_state);
#ifdef VERBOSE_STATE_MACHINE
        puts("DEBUG : current state is now .MAE_MURPHY.Jeu.decision");
#endif
        stm._mae_murphy_state._jeu_state._decision_state.create(stm);
      }
    }
}

// to manage the event end_game
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::end_game(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._game_over_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Game Over");
#endif
      stm._mae_murphy_state._game_over_state.create(stm);
    }
}

// perform the 'entry behavior'
void MAE_MURPHY::MAE_MURPHY_State::Jeu_State::_doentry(MAE_MURPHY & stm) {
#ifdef VERBOSE_STATE_MACHINE
  	puts("DEBUG : execute entry behavior of .MAE_MURPHY.Jeu");
#endif
  cout<<"ETAT JEU"<<endl;
  // toute la strat est la
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::Jeu_State::_upper(MAE_MURPHY & stm) {
    return &stm._mae_murphy_state;
}

MAE_MURPHY::MAE_MURPHY_State::~MAE_MURPHY_State() {
}

// to manage the event create
void MAE_MURPHY::MAE_MURPHY_State::create(MAE_MURPHY & stm) {
    {
      stm._set_currentState(stm._mae_murphy_state._initialisation_state);
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : current state is now .MAE_MURPHY.Initialisation");
#endif
      stm._mae_murphy_state._initialisation_state.create(stm);
    }
}

// returns the state containing the current
MAE_MURPHY::AnyState * MAE_MURPHY::MAE_MURPHY_State::_upper(MAE_MURPHY &) {
    return 0;
}

MAE_MURPHY::MAE_MURPHY() {
    _current_state = 0;
}

MAE_MURPHY::~MAE_MURPHY() {
}

// the operation you call to signal the event create
bool MAE_MURPHY::create() {
  if (_current_state == 0)
  (_current_state = &(*this)._mae_murphy_state)->create(*this);
  return (_current_state != 0);
}

// the operation you call to signal the event start_mis
bool MAE_MURPHY::start_mis() {
    if (_current_state != 0) {
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : fire trigger start_mis");
#endif
      _current_state->start_mis(*this);
    }
    return (_current_state != 0);
}

// the operation you call to signal the event assFini
bool MAE_MURPHY::assFini() {
    if (_current_state != 0) {
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : fire trigger assFini");
#endif
      _current_state->assFini(*this);
    }
    return (_current_state != 0);
}

// the operation you call to signal the event pince_lache
bool MAE_MURPHY::pince_lache() {
    if (_current_state != 0) {
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : fire trigger pince_lache");
#endif
      _current_state->pince_lache(*this);
    }
    return (_current_state != 0);
}

// the operation you call to signal the event pince_ready_to_drop
bool MAE_MURPHY::pince_ready_to_drop() {
    if (_current_state != 0) {
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : fire trigger pince_ready_to_drop");
#endif
      _current_state->pince_ready_to_drop(*this);
    }
    return (_current_state != 0);
}

// the operation you call to signal the event blocage
bool MAE_MURPHY::blocage() {
    if (_current_state != 0) {
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : fire trigger blocage");
#endif
      _current_state->blocage(*this);
    }
    return (_current_state != 0);
}

// the operation you call to signal the event pince_range
bool MAE_MURPHY::pince_range() {
    if (_current_state != 0) {
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : fire trigger pince_range");
#endif
      _current_state->pince_range(*this);
    }
    return (_current_state != 0);
}

// the operation you call to signal the event evitement
bool MAE_MURPHY::evitement() {
    if (_current_state != 0) {
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : fire trigger evitement");
#endif
      _current_state->evitement(*this);
    }
    return (_current_state != 0);
}

// the operation you call to signal the event time_out
bool MAE_MURPHY::time_out() {
    if (_current_state != 0) {
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : fire trigger time_out");
#endif
      _current_state->time_out(*this);
    }
    return (_current_state != 0);
}

// the operation you call to signal the event pince_ouverte
bool MAE_MURPHY::pince_ouverte() {
    if (_current_state != 0) {
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : fire trigger pince_ouverte");
#endif
      _current_state->pince_ouverte(*this);
    }
    return (_current_state != 0);
}

// the operation you call to signal the event pince_stand_by
bool MAE_MURPHY::pince_stand_by() {
    if (_current_state != 0) {
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : fire trigger pince_stand_by");
#endif
      _current_state->pince_stand_by(*this);
    }
    return (_current_state != 0);
}

// the operation you call to signal the event distrib_deboite
bool MAE_MURPHY::distrib_deboite() {
    if (_current_state != 0) {
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : fire trigger distrib_deboite");
#endif
      _current_state->distrib_deboite(*this);
    }
    return (_current_state != 0);
}

// the operation you call to signal the event fin_montee_bras
bool MAE_MURPHY::fin_montee_bras() {
    if (_current_state != 0) {
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : fire trigger fin_montee_bras");
#endif
      _current_state->fin_montee_bras(*this);
    }
    return (_current_state != 0);
}

// the operation you call to signal the event claps_replie
bool MAE_MURPHY::claps_replie() {
    if (_current_state != 0) {
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : fire trigger claps_replie");
#endif
      _current_state->claps_replie(*this);
    }
    return (_current_state != 0);
}

// the operation you call to signal the event mission_distrib
bool MAE_MURPHY::mission_distrib() {
    if (_current_state != 0) {
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : fire trigger mission_distrib");
#endif
      _current_state->mission_distrib(*this);
    }
    return (_current_state != 0);
}

// the operation you call to signal the event mission_claps
bool MAE_MURPHY::mission_claps() {
    if (_current_state != 0) {
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : fire trigger mission_claps");
#endif
      _current_state->mission_claps(*this);
    }
    return (_current_state != 0);
}

// the operation you call to signal the event mission_depot_tour_depart
bool MAE_MURPHY::mission_depot_tour_depart() {
    if (_current_state != 0) {
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : fire trigger mission_depot_tour_depart");
#endif
      _current_state->mission_depot_tour_depart(*this);
    }
    return (_current_state != 0);
}

// the operation you call to signal the event mission_zone_ennemie
bool MAE_MURPHY::mission_zone_ennemie() {
    if (_current_state != 0) {
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : fire trigger mission_zone_ennemie");
#endif
      _current_state->mission_zone_ennemie(*this);
    }
    return (_current_state != 0);
}

// the operation you call to signal the event mission_chiage_balle
bool MAE_MURPHY::mission_chiage_balle() {
    if (_current_state != 0) {
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : fire trigger mission_chiage_balle");
#endif
      _current_state->mission_chiage_balle(*this);
    }
    return (_current_state != 0);
}

// the operation you call to signal the event mission_zone_centrale
bool MAE_MURPHY::mission_zone_centrale() {
    if (_current_state != 0) {
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : fire trigger mission_zone_centrale");
#endif
      _current_state->mission_zone_centrale(*this);
    }
    return (_current_state != 0);
}

// the operation you call to signal the event mission_depot_tour_estrade
bool MAE_MURPHY::mission_depot_tour_estrade() {
    if (_current_state != 0) {
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : fire trigger mission_depot_tour_estrade");
#endif
      _current_state->mission_depot_tour_estrade(*this);
    }
    return (_current_state != 0);
}

// the operation you call to signal the event end_game
bool MAE_MURPHY::end_game() {
    if (_current_state != 0) {
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : fire trigger end_game");
#endif
      _current_state->end_game(*this);
    }
    return (_current_state != 0);
}

// the operation you call to signal the event start_enleve
bool MAE_MURPHY::start_enleve() {
    if (_current_state != 0) {
#ifdef VERBOSE_STATE_MACHINE
      puts("DEBUG : fire trigger start_enleve");
#endif
      _current_state->start_enleve(*this);
    }
    return (_current_state != 0);
}

// to execute the current state 'do activity'
void MAE_MURPHY::doActivity() {
    _current_state->_do(*this);
}

// execution done, internal
void MAE_MURPHY::_final() {
    _current_state = 0;
#ifdef VERBOSE_STATE_MACHINE
    puts("DEBUG : final state reached");
#endif
}

