#ifndef _MAE_COOP_R_H
#define _MAE_COOP_R_H

#include <iostream>
using namespace std;


// implement the state machine MAE_COOP_R
class MAE_COOP_R {
  protected:
    // Mother class of all the classes representing states
    class AnyState {
      public:
        virtual ~AnyState();

        // return the upper state
        virtual AnyState * _upper(MAE_COOP_R &) = 0;

        // perform the 'do activity'
        virtual void _do(MAE_COOP_R &);

        virtual void create(MAE_COOP_R &);

        // the current state doesn't manage the event stratEnleve, give it to the upper state
        virtual void stratEnleve(MAE_COOP_R & stm);

        // the current state doesn't manage the event time_out, give it to the upper state
        virtual void time_out(MAE_COOP_R & stm);

        // the current state doesn't manage the event adversaire, give it to the upper state
        virtual void adversaire(MAE_COOP_R & stm);

        // the current state doesn't manage the event assFini, give it to the upper state
        virtual void assFini(MAE_COOP_R & stm);

        // the current state doesn't manage the event ioFini, give it to the upper state
        virtual void ioFini(MAE_COOP_R & stm);

        // the current state doesn't manage the event game_over, give it to the upper state
        virtual void game_over(MAE_COOP_R & stm);

    };
    
    // implement the state MAE_COOP_R
    class MAE_COOP_R_State : public AnyState {
      public:
        // implement the state Attente
        class Attente_State : public AnyState {
          public:
            virtual ~Attente_State();

            // to manage the event stratEnleve
            virtual void stratEnleve(MAE_COOP_R & stm);

            // to manage the event create
            virtual void create(MAE_COOP_R & stm);

            // perform the 'entry behavior'
            void _doentry(MAE_COOP_R & stm);

            // returns the state containing the current
            virtual AnyState * _upper(MAE_COOP_R & stm);

        };
        
        // implement the state Fin de Jeu
        class Fin_de_Jeu_State : public AnyState {
          public:
            virtual ~Fin_de_Jeu_State();

            // to manage the event create
            virtual void create(MAE_COOP_R & stm);

            // perform the 'entry behavior'
            void _doentry(MAE_COOP_R & stm);

            // returns the state containing the current
            virtual AnyState * _upper(MAE_COOP_R & stm);

        };
        
        // implement the state Jeu
        class Jeu_State : public AnyState {
          public:
            // implement the state attente
            class attente_State : public AnyState {
              public:
                virtual ~attente_State();

                // to manage the event time_out
                virtual void time_out(MAE_COOP_R & stm);

                // to manage the event create
                virtual void create(MAE_COOP_R & stm);

                // perform the 'entry behavior'
                void _doentry(MAE_COOP_R & stm);

                // returns the state containing the current
                virtual AnyState * _upper(MAE_COOP_R & stm);

            };
            
            // implement the state attente tempo
            class attente_tempo_State : public AnyState {
              public:
                virtual ~attente_tempo_State();

                // to manage the event time_out
                virtual void time_out(MAE_COOP_R & stm);

                // to manage the event create
                virtual void create(MAE_COOP_R & stm);

                // perform the 'entry behavior'
                void _doentry(MAE_COOP_R & stm);

                // returns the state containing the current
                virtual AnyState * _upper(MAE_COOP_R & stm);

            };
            
            // implement the state deployement
            class deployement_State : public AnyState {
              public:
                virtual ~deployement_State();

                // to manage the event time_out
                virtual void time_out(MAE_COOP_R & stm);

                // to manage the event create
                virtual void create(MAE_COOP_R & stm);

                // perform the 'entry behavior'
                void _doentry(MAE_COOP_R & stm);

                // returns the state containing the current
                virtual AnyState * _upper(MAE_COOP_R & stm);

            };
            
            // implement the state reprise
            class reprise_State : public AnyState {
              public:
                virtual ~reprise_State();

                // to manage the event adversaire
                virtual void adversaire(MAE_COOP_R & stm);

                // to manage the event assFini
                virtual void assFini(MAE_COOP_R & stm);

                // to manage the event create
                virtual void create(MAE_COOP_R & stm);

                // perform the 'entry behavior'
                void _doentry(MAE_COOP_R & stm);

                // returns the state containing the current
                virtual AnyState * _upper(MAE_COOP_R & stm);

            };
            
            // implement the state fin deplacement lateral
            class fin_deplacement_lateral_State : public AnyState {
              public:
                virtual ~fin_deplacement_lateral_State();

                // to manage the event time_out
                virtual void time_out(MAE_COOP_R & stm);

                // to manage the event create
                virtual void create(MAE_COOP_R & stm);

                // perform the 'entry behavior'
                void _doentry(MAE_COOP_R & stm);

                // returns the state containing the current
                virtual AnyState * _upper(MAE_COOP_R & stm);

            };
            
            // implement the state bumper en bas des marches
            class bumper_en_bas_des_marches_State : public AnyState {
              public:
                virtual ~bumper_en_bas_des_marches_State();

                // to manage the event assFini
                virtual void assFini(MAE_COOP_R & stm);

                // to manage the event create
                virtual void create(MAE_COOP_R & stm);

                // perform the 'entry behavior'
                void _doentry(MAE_COOP_R & stm);

                // returns the state containing the current
                virtual AnyState * _upper(MAE_COOP_R & stm);

            };
            
            // implement the state Evitement
            class Evitement_State : public AnyState {
              public:
                virtual ~Evitement_State();

                // to manage the event time_out
                virtual void time_out(MAE_COOP_R & stm);

                // to manage the event create
                virtual void create(MAE_COOP_R & stm);

                // perform the 'entry behavior'
                void _doentry(MAE_COOP_R & stm);

                // returns the state containing the current
                virtual AnyState * _upper(MAE_COOP_R & stm);

            };
            
            // implement the state remonte 2
            class remonte_2_State : public AnyState {
              public:
                virtual ~remonte_2_State();

                // to manage the event ioFini
                virtual void ioFini(MAE_COOP_R & stm);

                // to manage the event create
                virtual void create(MAE_COOP_R & stm);

                // perform the 'entry behavior'
                void _doentry(MAE_COOP_R & stm);

                // returns the state containing the current
                virtual AnyState * _upper(MAE_COOP_R & stm);

            };
            
            // implement the state preparation pose second tapis
            class preparation_pose_second_tapis_State : public AnyState {
              public:
                virtual ~preparation_pose_second_tapis_State();

                // to manage the event ioFini
                virtual void ioFini(MAE_COOP_R & stm);

                // to manage the event create
                virtual void create(MAE_COOP_R & stm);

                // perform the 'entry behavior'
                void _doentry(MAE_COOP_R & stm);

                // returns the state containing the current
                virtual AnyState * _upper(MAE_COOP_R & stm);

            };
            
            // implement the state decalage droite
            class decalage_droite_State : public AnyState {
              public:
                virtual ~decalage_droite_State();

                // to manage the event assFini
                virtual void assFini(MAE_COOP_R & stm);

                // to manage the event create
                virtual void create(MAE_COOP_R & stm);

                // perform the 'entry behavior'
                void _doentry(MAE_COOP_R & stm);

                // returns the state containing the current
                virtual AnyState * _upper(MAE_COOP_R & stm);

            };
            
            // implement the state remonte
            class remonte_State : public AnyState {
              public:
                virtual ~remonte_State();

                // to manage the event ioFini
                virtual void ioFini(MAE_COOP_R & stm);

                // to manage the event create
                virtual void create(MAE_COOP_R & stm);

                // perform the 'entry behavior'
                void _doentry(MAE_COOP_R & stm);

                // returns the state containing the current
                virtual AnyState * _upper(MAE_COOP_R & stm);

            };
            
            // implement the state preparation pose premier tapis
            class preparation_pose_premier_tapis_State : public AnyState {
              public:
                virtual ~preparation_pose_premier_tapis_State();

                // to manage the event ioFini
                virtual void ioFini(MAE_COOP_R & stm);

                // to manage the event create
                virtual void create(MAE_COOP_R & stm);

                // perform the 'entry behavior'
                void _doentry(MAE_COOP_R & stm);

                // returns the state containing the current
                virtual AnyState * _upper(MAE_COOP_R & stm);

            };
            
            // implement the state decalage gauche
            class decalage_gauche_State : public AnyState {
              public:
                virtual ~decalage_gauche_State();

                // to manage the event assFini
                virtual void assFini(MAE_COOP_R & stm);

                // to manage the event create
                virtual void create(MAE_COOP_R & stm);

                // perform the 'entry behavior'
                void _doentry(MAE_COOP_R & stm);

                // returns the state containing the current
                virtual AnyState * _upper(MAE_COOP_R & stm);

            };
            
            // implement the state ascension
            class ascension_State : public AnyState {
              public:
                virtual ~ascension_State();

                // to manage the event assFini
                virtual void assFini(MAE_COOP_R & stm);

                // to manage the event create
                virtual void create(MAE_COOP_R & stm);

                // perform the 'entry behavior'
                void _doentry(MAE_COOP_R & stm);

                // returns the state containing the current
                virtual AnyState * _upper(MAE_COOP_R & stm);

            };
            
            // implement the state attente recalibration
            class attente_recalibration_State : public AnyState {
              public:
                virtual ~attente_recalibration_State();

                // to manage the event time_out
                virtual void time_out(MAE_COOP_R & stm);

                // to manage the event create
                virtual void create(MAE_COOP_R & stm);

                // perform the 'entry behavior'
                void _doentry(MAE_COOP_R & stm);

                // perform the 'exit behavior'
                void _doexit(MAE_COOP_R & stm);

                // returns the state containing the current
                virtual AnyState * _upper(MAE_COOP_R & stm);

            };
            
            // implement the state deplacement lateral
            class deplacement_lateral_State : public AnyState {
              public:
                virtual ~deplacement_lateral_State();

                // to manage the event adversaire
                virtual void adversaire(MAE_COOP_R & stm);

                // to manage the event assFini
                virtual void assFini(MAE_COOP_R & stm);

                // to manage the event create
                virtual void create(MAE_COOP_R & stm);

                // perform the 'entry behavior'
                void _doentry(MAE_COOP_R & stm);

                // returns the state containing the current
                virtual AnyState * _upper(MAE_COOP_R & stm);

            };
            
            virtual ~Jeu_State();

            // memorize the instance of the state attente, internal
            attente_State _attente_state;

            // memorize the instance of the state deplacement lateral, internal
            deplacement_lateral_State _deplacement_lateral_state;

            // memorize the instance of the state attente recalibration, internal
            attente_recalibration_State _attente_recalibration_state;

            // memorize the instance of the state ascension, internal
            ascension_State _ascension_state;

            // memorize the instance of the state decalage gauche, internal
            decalage_gauche_State _decalage_gauche_state;

            // memorize the instance of the state preparation pose premier tapis, internal
            preparation_pose_premier_tapis_State _preparation_pose_premier_tapis_state;

            // memorize the instance of the state remonte, internal
            remonte_State _remonte_state;

            // memorize the instance of the state decalage droite, internal
            decalage_droite_State _decalage_droite_state;

            // memorize the instance of the state preparation pose second tapis, internal
            preparation_pose_second_tapis_State _preparation_pose_second_tapis_state;

            // memorize the instance of the state remonte 2, internal
            remonte_2_State _remonte_2_state;

            // memorize the instance of the state Evitement, internal
            Evitement_State _evitement_state;

            // memorize the instance of the state bumper en bas des marches, internal
            bumper_en_bas_des_marches_State _bumper_en_bas_des_marches_state;

            // memorize the instance of the state fin deplacement lateral, internal
            fin_deplacement_lateral_State _fin_deplacement_lateral_state;

            // memorize the instance of the state reprise, internal
            reprise_State _reprise_state;

            // memorize the instance of the state deployement, internal
            deployement_State _deployement_state;

            // to manage the event create
            virtual void create(MAE_COOP_R & stm);

            virtual bool _completion(MAE_COOP_R & stm);

            // perform the 'entry behavior'
            void _doentry(MAE_COOP_R & stm);

            // returns the state containing the current
            virtual AnyState * _upper(MAE_COOP_R & stm);

            // memorize the instance of the state attente tempo, internal
            attente_tempo_State _attente_tempo_state;

            // to manage the event game_over
            virtual void game_over(MAE_COOP_R & stm);

            // to manage the exit point 'fin', defined because probably shared
            void _exit1(MAE_COOP_R & stm);

        };
        
        virtual ~MAE_COOP_R_State();

        // memorize the instance of the state Attente, internal
        Attente_State _attente_state;

        // memorize the instance of the state Jeu, internal
        Jeu_State _jeu_state;

        // to manage the event create
        virtual void create(MAE_COOP_R & stm);

        // returns the state containing the current
        virtual AnyState * _upper(MAE_COOP_R &);

        // memorize the instance of the state Fin de Jeu, internal
        Fin_de_Jeu_State _fin_de_jeu_state;

    };
    
    // memorize the instance of the state MAE_COOP_R, internal
    MAE_COOP_R_State _mae_coop_r_state;


  public:
    MAE_COOP_R();

    virtual ~MAE_COOP_R();

    // the operation you call to signal the event create
    bool create();

    // the operation you call to signal the event stratEnleve
    bool stratEnleve();

  friend class MAE_COOP_R_State::Attente_State;
    // the operation you call to signal the event time_out
    bool time_out();

  friend class MAE_COOP_R_State::Jeu_State::attente_State;
    // the operation you call to signal the event adversaire
    bool adversaire();

    // the operation you call to signal the event assFini
    bool assFini();

  friend class MAE_COOP_R_State::Jeu_State::deplacement_lateral_State;
  friend class MAE_COOP_R_State::Jeu_State::attente_recalibration_State;
  friend class MAE_COOP_R_State::Jeu_State::ascension_State;
  friend class MAE_COOP_R_State::Jeu_State::decalage_gauche_State;
    // the operation you call to signal the event ioFini
    bool ioFini();

  friend class MAE_COOP_R_State::Jeu_State::preparation_pose_premier_tapis_State;
  friend class MAE_COOP_R_State::Jeu_State::remonte_State;
  friend class MAE_COOP_R_State::Jeu_State::decalage_droite_State;
  friend class MAE_COOP_R_State::Jeu_State::preparation_pose_second_tapis_State;
  friend class MAE_COOP_R_State::Jeu_State::remonte_2_State;
  friend class MAE_COOP_R_State::Jeu_State::Evitement_State;
  friend class MAE_COOP_R_State::Jeu_State::bumper_en_bas_des_marches_State;
  friend class MAE_COOP_R_State::Jeu_State::fin_deplacement_lateral_State;
  friend class MAE_COOP_R_State::Jeu_State::reprise_State;
  friend class MAE_COOP_R_State::Jeu_State::deployement_State;
  friend class MAE_COOP_R_State::Jeu_State;
  friend class MAE_COOP_R_State;
    // to execute the current state 'do activity'
    void doActivity();


  protected:
    // change the current state, internal
    inline void _set_currentState(AnyState & st);

    // execution done, internal
    void _final();

    // contains the current state, internal
    AnyState * _current_state;


  public:
    // the operation you call to signal the event game_over
    bool game_over();

  friend class MAE_COOP_R_State::Jeu_State::attente_tempo_State;
  friend class MAE_COOP_R_State::Fin_de_Jeu_State;
};
// change the current state, internal
inline void MAE_COOP_R::_set_currentState(MAE_COOP_R::AnyState & st) {
    _current_state = &st;
}

#endif
