#ifndef _MAE_MURPHY_H
#define _MAE_MURPHY_H

#include <iostream>
using namespace std;


// implement the state machine MAE_MURPHY
class MAE_MURPHY {
  protected:
    // Mother class of all the classes representing states
    class AnyState {
      public:
        virtual ~AnyState();

        // return the upper state
        virtual AnyState * _upper(MAE_MURPHY &) = 0;

        // perform the 'do activity'
        virtual void _do(MAE_MURPHY &);

        virtual void create(MAE_MURPHY &);

        // the current state doesn't manage the event start_mis, give it to the upper state
        virtual void start_mis(MAE_MURPHY & stm);

        // the current state doesn't manage the event assFini, give it to the upper state
        virtual void assFini(MAE_MURPHY & stm);

        // the current state doesn't manage the event pince_lache, give it to the upper state
        virtual void pince_lache(MAE_MURPHY & stm);

        // the current state doesn't manage the event pince_ready_to_drop, give it to the upper state
        virtual void pince_ready_to_drop(MAE_MURPHY & stm);

        // the current state doesn't manage the event blocage, give it to the upper state
        virtual void blocage(MAE_MURPHY & stm);

        // the current state doesn't manage the event pince_range, give it to the upper state
        virtual void pince_range(MAE_MURPHY & stm);

        // the current state doesn't manage the event evitement, give it to the upper state
        virtual void evitement(MAE_MURPHY & stm);

        // the current state doesn't manage the event time_out, give it to the upper state
        virtual void time_out(MAE_MURPHY & stm);

        // the current state doesn't manage the event pince_ouverte, give it to the upper state
        virtual void pince_ouverte(MAE_MURPHY & stm);

        // the current state doesn't manage the event pince_stand_by, give it to the upper state
        virtual void pince_stand_by(MAE_MURPHY & stm);

        // the current state doesn't manage the event distrib_deboite, give it to the upper state
        virtual void distrib_deboite(MAE_MURPHY & stm);

        // the current state doesn't manage the event fin_montee_bras, give it to the upper state
        virtual void fin_montee_bras(MAE_MURPHY & stm);

        // the current state doesn't manage the event claps_replie, give it to the upper state
        virtual void claps_replie(MAE_MURPHY & stm);

        // the current state doesn't manage the event mission_distrib, give it to the upper state
        virtual void mission_distrib(MAE_MURPHY & stm);

        // the current state doesn't manage the event mission_claps, give it to the upper state
        virtual void mission_claps(MAE_MURPHY & stm);

        // the current state doesn't manage the event mission_depot_tour_depart, give it to the upper state
        virtual void mission_depot_tour_depart(MAE_MURPHY & stm);

        // the current state doesn't manage the event mission_zone_ennemie, give it to the upper state
        virtual void mission_zone_ennemie(MAE_MURPHY & stm);

        // the current state doesn't manage the event mission_chiage_balle, give it to the upper state
        virtual void mission_chiage_balle(MAE_MURPHY & stm);

        // the current state doesn't manage the event mission_zone_centrale, give it to the upper state
        virtual void mission_zone_centrale(MAE_MURPHY & stm);

        // the current state doesn't manage the event mission_depot_tour_estrade, give it to the upper state
        virtual void mission_depot_tour_estrade(MAE_MURPHY & stm);

        // the current state doesn't manage the event end_game, give it to the upper state
        virtual void end_game(MAE_MURPHY & stm);

        // the current state doesn't manage the event start_enleve, give it to the upper state
        virtual void start_enleve(MAE_MURPHY & stm);

    };
    
    // implement the state MAE_MURPHY
    class MAE_MURPHY_State : public AnyState {
      public:
        // implement the state Initialisation
        class Initialisation_State : public AnyState {
          public:
            virtual ~Initialisation_State();

            // to manage the event start_mis
            virtual void start_mis(MAE_MURPHY & stm);

            // to manage the event create
            virtual void create(MAE_MURPHY & stm);

            // perform the 'entry behavior'
            void _doentry(MAE_MURPHY & stm);

            // returns the state containing the current
            virtual AnyState * _upper(MAE_MURPHY & stm);

        };
        
        // implement the state Game Over
        class Game_Over_State : public AnyState {
          public:
            virtual ~Game_Over_State();

            // to manage the event create
            virtual void create(MAE_MURPHY & stm);

            // perform the 'entry behavior'
            void _doentry(MAE_MURPHY & stm);

            // returns the state containing the current
            virtual AnyState * _upper(MAE_MURPHY & stm);

        };
        
        // implement the state startin' block
        class startin_block_State : public AnyState {
          public:
            virtual ~startin_block_State();

            // to manage the event start_enleve
            virtual void start_enleve(MAE_MURPHY & stm);

            // to manage the event create
            virtual void create(MAE_MURPHY & stm);

            // perform the 'entry behavior'
            void _doentry(MAE_MURPHY & stm);

            // returns the state containing the current
            virtual AnyState * _upper(MAE_MURPHY & stm);

        };
        
        // implement the state Recalage Initial
        class Recalage_Initial_State : public AnyState {
          public:
            // implement the state Recule
            class Recule_State : public AnyState {
              public:
                virtual ~Recule_State();

                // to manage the event blocage
                virtual void blocage(MAE_MURPHY & stm);

                // to manage the event create
                virtual void create(MAE_MURPHY & stm);

                // perform the 'entry behavior'
                void _doentry(MAE_MURPHY & stm);

                // returns the state containing the current
                virtual AnyState * _upper(MAE_MURPHY & stm);

            };
            
            // implement the state avance
            class avance_State : public AnyState {
              public:
                virtual ~avance_State();

                // to manage the event assFini
                virtual void assFini(MAE_MURPHY & stm);

                // to manage the event create
                virtual void create(MAE_MURPHY & stm);

                // perform the 'entry behavior'
                void _doentry(MAE_MURPHY & stm);

                // returns the state containing the current
                virtual AnyState * _upper(MAE_MURPHY & stm);

            };
            
            // implement the state coup de patte cote escalier pour confirmer le sens
            class coup_de_patte_cote_escalier_pour_confirmer_le_sens_State : public AnyState {
              public:
                virtual ~coup_de_patte_cote_escalier_pour_confirmer_le_sens_State();

                virtual bool _completion(MAE_MURPHY & stm);

                // to manage the event create
                virtual void create(MAE_MURPHY & stm);

                // perform the 'entry behavior'
                void _doentry(MAE_MURPHY & stm);

                // returns the state containing the current
                virtual AnyState * _upper(MAE_MURPHY & stm);

            };
            
            // implement the state set X Y CAP
            class set_X_Y_CAP_State : public AnyState {
              public:
                virtual ~set_X_Y_CAP_State();

                // to manage the event time_out
                virtual void time_out(MAE_MURPHY & stm);

                // to manage the event create
                virtual void create(MAE_MURPHY & stm);

                // perform the 'entry behavior'
                void _doentry(MAE_MURPHY & stm);

                // returns the state containing the current
                virtual AnyState * _upper(MAE_MURPHY & stm);

            };
            
            virtual ~Recalage_Initial_State();

            // memorize the instance of the state Recule, internal
            Recule_State _recule_state;

            // memorize the instance of the state set X Y CAP, internal
            set_X_Y_CAP_State _set_x_y_cap_state;

            // memorize the instance of the state coup de patte cote escalier pour confirmer le sens, internal
            coup_de_patte_cote_escalier_pour_confirmer_le_sens_State _coup_de_patte_cote_escalier_pour_confirmer_le_sens_state;

            // memorize the instance of the state avance, internal
            avance_State _avance_state;

            // to manage the event create
            virtual void create(MAE_MURPHY & stm);

            // to manage the exit point 'sortie recalage', defined because probably shared
            void _exit27(MAE_MURPHY & stm);

            // perform the 'entry behavior'
            void _doentry(MAE_MURPHY & stm);

            // returns the state containing the current
            virtual AnyState * _upper(MAE_MURPHY & stm);

        };
        
        // implement the state Evitement
        class Evitement_State : public AnyState {
          public:
            // implement the state faire des maneuvre
            class faire_des_maneuvre_State : public AnyState {
              public:
                virtual ~faire_des_maneuvre_State();

                // to manage the event create
                virtual void create(MAE_MURPHY & stm);

                // perform the 'entry behavior'
                void _doentry(MAE_MURPHY & stm);

                // returns the state containing the current
                virtual AnyState * _upper(MAE_MURPHY & stm);

                // to manage the event time_out
                virtual void time_out(MAE_MURPHY & stm);

            };
            
            virtual ~Evitement_State();

            // memorize the instance of the state faire des maneuvre, internal
            faire_des_maneuvre_State _faire_des_maneuvre_state;

            // to manage the exit point 'sortie evitement', defined because probably shared
            void _exit26(MAE_MURPHY & stm);

            // perform the 'entry behavior'
            void _doentry(MAE_MURPHY & stm);

            // returns the state containing the current
            virtual AnyState * _upper(MAE_MURPHY & stm);

            // to manage the event create
            virtual void create(MAE_MURPHY & stm);

        };
        
        // implement the state Jeu
        class Jeu_State : public AnyState {
          public:
            // implement the state mission depot tour estrade
            class mission_depot_tour_estrade_State : public AnyState {
              public:
                // implement the state waypoint init
                class waypoint_init_State : public AnyState {
                  public:
                    // implement the state BF cap to mission
                    class BF_cap_to_mission_State : public AnyState {
                      public:
                        virtual ~BF_cap_to_mission_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state BF cap mission
                    class BF_cap_mission_State : public AnyState {
                      public:
                        virtual ~BF_cap_mission_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                        // perform the 'exit behavior'
                        void _doexit(MAE_MURPHY & stm);

                    };
                    
                    // implement the state BF droite to mission
                    class BF_droite_to_mission_State : public AnyState {
                      public:
                        virtual ~BF_droite_to_mission_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    virtual ~waypoint_init_State();

                    // memorize the instance of the state BF cap to mission, internal
                    BF_cap_to_mission_State _bf_cap_to_mission_state;

                    // memorize the instance of the state BF droite to mission, internal
                    BF_droite_to_mission_State _bf_droite_to_mission_state;

                    // memorize the instance of the state BF cap mission, internal
                    BF_cap_mission_State _bf_cap_mission_state;

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // to manage the exit point 'sortie', defined because probably shared
                    void _exit1(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state BF Cap
                class BF_Cap_State : public AnyState {
                  public:
                    virtual ~BF_Cap_State();

                    // to manage the event assFini
                    virtual void assFini(MAE_MURPHY & stm);

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state replis des pinces
                class replis_des_pinces_State : public AnyState {
                  public:
                    virtual ~replis_des_pinces_State();

                    // to manage the event pince_range
                    virtual void pince_range(MAE_MURPHY & stm);

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state set Y CAP
                class set_Y_CAP_State : public AnyState {
                  public:
                    virtual ~set_Y_CAP_State();

                    virtual bool _completion(MAE_MURPHY & stm);

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state avance
                class avance_State : public AnyState {
                  public:
                    virtual ~avance_State();

                    // to manage the event blocage
                    virtual void blocage(MAE_MURPHY & stm);

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // perform the 'exit behavior'
                    void _doexit(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state preparation
                class preparation_State : public AnyState {
                  public:
                    virtual ~preparation_State();

                    // to manage the event pince_ready_to_drop
                    virtual void pince_ready_to_drop(MAE_MURPHY & stm);

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state recule doucement
                class recule_doucement_State : public AnyState {
                  public:
                    virtual ~recule_doucement_State();

                    // to manage the event assFini
                    virtual void assFini(MAE_MURPHY & stm);

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                    // to manage the event blocage
                    virtual void blocage(MAE_MURPHY & stm);

                };
                
                // implement the state depot
                class depot_State : public AnyState {
                  public:
                    virtual ~depot_State();

                    // to manage the event pince_lache
                    virtual void pince_lache(MAE_MURPHY & stm);

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                virtual ~mission_depot_tour_estrade_State();

                // memorize the instance of the state waypoint init, internal
                waypoint_init_State _waypoint_init_state;

                // memorize the instance of the state depot, internal
                depot_State _depot_state;

                // memorize the instance of the state recule doucement, internal
                recule_doucement_State _recule_doucement_state;

                // memorize the instance of the state preparation, internal
                preparation_State _preparation_state;

                // memorize the instance of the state avance, internal
                avance_State _avance_state;

                // memorize the instance of the state set Y CAP, internal
                set_Y_CAP_State _set_y_cap_state;

                // memorize the instance of the state replis des pinces, internal
                replis_des_pinces_State _replis_des_pinces_state;

                // memorize the instance of the state BF Cap, internal
                BF_Cap_State _bf_cap_state;

                // to manage the event create
                virtual void create(MAE_MURPHY & stm);

                // to manage the exit point 'sortie', defined because probably shared
                void _exit2(MAE_MURPHY & stm);

                // perform the 'entry behavior'
                void _doentry(MAE_MURPHY & stm);

                // returns the state containing the current
                virtual AnyState * _upper(MAE_MURPHY & stm);

            };
            
            // implement the state decision
            class decision_State : public AnyState {
              public:
                virtual ~decision_State();

                // to manage the event mission_distrib
                virtual void mission_distrib(MAE_MURPHY & stm);

                // to manage the event mission_claps
                virtual void mission_claps(MAE_MURPHY & stm);

                // to manage the event mission_depot_tour_depart
                virtual void mission_depot_tour_depart(MAE_MURPHY & stm);

                // to manage the event mission_zone_ennemie
                virtual void mission_zone_ennemie(MAE_MURPHY & stm);

                // to manage the event mission_chiage_balle
                virtual void mission_chiage_balle(MAE_MURPHY & stm);

                // to manage the event mission_zone_centrale
                virtual void mission_zone_centrale(MAE_MURPHY & stm);

                // to manage the event mission_depot_tour_estrade
                virtual void mission_depot_tour_estrade(MAE_MURPHY & stm);

                // to manage the event create
                virtual void create(MAE_MURPHY & stm);

                // perform the 'entry behavior'
                void _doentry(MAE_MURPHY & stm);

                // returns the state containing the current
                virtual AnyState * _upper(MAE_MURPHY & stm);

            };
            
            // implement the state mission zone ennemie
            class mission_zone_ennemie_State : public AnyState {
              public:
                // implement the state waypoint initial
                class waypoint_initial_State : public AnyState {
                  public:
                    // implement the state cap to mission
                    class cap_to_mission_State : public AnyState {
                      public:
                        virtual ~cap_to_mission_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state cap mission
                    class cap_mission_State : public AnyState {
                      public:
                        virtual ~cap_mission_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state BF droite to mission
                    class BF_droite_to_mission_State : public AnyState {
                      public:
                        virtual ~BF_droite_to_mission_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    virtual ~waypoint_initial_State();

                    // memorize the instance of the state cap to mission, internal
                    cap_to_mission_State _cap_to_mission_state;

                    // memorize the instance of the state BF droite to mission, internal
                    BF_droite_to_mission_State _bf_droite_to_mission_state;

                    // memorize the instance of the state cap mission, internal
                    cap_mission_State _cap_mission_state;

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // to manage the exit point 'sortie', defined because probably shared
                    void _exit21(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state faire chier en zizagant
                class faire_chier_en_zizagant_State : public AnyState {
                  public:
                    // implement the state to escalier
                    class to_escalier_State : public AnyState {
                      public:
                        virtual ~to_escalier_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state chieur plus
                    class chieur_plus_State : public AnyState {
                      public:
                        virtual ~chieur_plus_State();

                        virtual bool _completion(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                    };
                    
                    // implement the state chieur faible
                    class chieur_faible_State : public AnyState {
                      public:
                        virtual ~chieur_faible_State();

                        virtual bool _completion(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                    };
                    
                    // implement the state chieur stop
                    class chieur_stop_State : public AnyState {
                      public:
                        virtual ~chieur_stop_State();

                        virtual bool _completion(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                    };
                    
                    // implement the state deboit les cines adverses
                    class deboit_les_cines_adverses_State : public AnyState {
                      public:
                        virtual ~deboit_les_cines_adverses_State();

                        virtual bool _completion(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state to estrade
                    class to_estrade_State : public AnyState {
                      public:
                        virtual ~to_estrade_State();

                        virtual bool _completion(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    virtual ~faire_chier_en_zizagant_State();

                    // memorize the instance of the state to escalier, internal
                    to_escalier_State _to_escalier_state;

                    // memorize the instance of the state to estrade, internal
                    to_estrade_State _to_estrade_state;

                    // memorize the instance of the state deboit les cines adverses, internal
                    deboit_les_cines_adverses_State _deboit_les_cines_adverses_state;

                    // memorize the instance of the state chieur stop, internal
                    chieur_stop_State _chieur_stop_state;

                    // memorize the instance of the state chieur faible, internal
                    chieur_faible_State _chieur_faible_state;

                    // memorize the instance of the state chieur plus, internal
                    chieur_plus_State _chieur_plus_state;

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // to manage the exit point 'sortie', defined because probably shared
                    void _exit24(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state depot gobelet
                class depot_gobelet_State : public AnyState {
                  public:
                    // implement the state BF droite sur le cine
                    class BF_droite_sur_le_cine_State : public AnyState {
                      public:
                        virtual ~BF_droite_sur_le_cine_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state fermeture capot
                    class fermeture_capot_State : public AnyState {
                      public:
                        virtual ~fermeture_capot_State();

                        virtual bool _completion(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state avance
                    class avance_State : public AnyState {
                      public:
                        virtual ~avance_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state ouverture capot
                    class ouverture_capot_State : public AnyState {
                      public:
                        virtual ~ouverture_capot_State();

                        // to manage the event time_out
                        virtual void time_out(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state BF CAP vers centre de la table
                    class BF_CAP_vers_centre_de_la_table_State : public AnyState {
                      public:
                        virtual ~BF_CAP_vers_centre_de_la_table_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    virtual ~depot_gobelet_State();

                    // memorize the instance of the state BF droite sur le cine, internal
                    BF_droite_sur_le_cine_State _bf_droite_sur_le_cine_state;

                    // memorize the instance of the state BF CAP vers centre de la table, internal
                    BF_CAP_vers_centre_de_la_table_State _bf_cap_vers_centre_de_la_table_state;

                    // memorize the instance of the state ouverture capot, internal
                    ouverture_capot_State _ouverture_capot_state;

                    // memorize the instance of the state avance, internal
                    avance_State _avance_state;

                    // memorize the instance of the state fermeture capot, internal
                    fermeture_capot_State _fermeture_capot_state;

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // to manage the exit point 'sortie', defined because probably shared
                    void _exit23(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state claps central
                class claps_central_State : public AnyState {
                  public:
                    // implement the state BF droite
                    class BF_droite_State : public AnyState {
                      public:
                        virtual ~BF_droite_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state BF cap vers estrade
                    class BF_cap_vers_estrade_State : public AnyState {
                      public:
                        virtual ~BF_cap_vers_estrade_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state BF cap to cine
                    class BF_cap_to_cine_State : public AnyState {
                      public:
                        virtual ~BF_cap_to_cine_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state ouverture claps
                    class ouverture_claps_State : public AnyState {
                      public:
                        virtual ~ouverture_claps_State();

                        // to manage the event claps_replie
                        virtual void claps_replie(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    virtual ~claps_central_State();

                    // memorize the instance of the state BF droite, internal
                    BF_droite_State _bf_droite_state;

                    // memorize the instance of the state ouverture claps, internal
                    ouverture_claps_State _ouverture_claps_state;

                    // memorize the instance of the state BF cap to cine, internal
                    BF_cap_to_cine_State _bf_cap_to_cine_state;

                    // memorize the instance of the state BF cap vers estrade, internal
                    BF_cap_vers_estrade_State _bf_cap_vers_estrade_state;

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // to manage the exit point 'sortie', defined because probably shared
                    void _exit22(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                virtual ~mission_zone_ennemie_State();

                // memorize the instance of the state waypoint initial, internal
                waypoint_initial_State _waypoint_initial_state;

                // memorize the instance of the state claps central, internal
                claps_central_State _claps_central_state;

                // memorize the instance of the state depot gobelet, internal
                depot_gobelet_State _depot_gobelet_state;

                // memorize the instance of the state faire chier en zizagant, internal
                faire_chier_en_zizagant_State _faire_chier_en_zizagant_state;

                // to manage the event create
                virtual void create(MAE_MURPHY & stm);

                // to manage the exit point 'sortie', defined because probably shared
                void _exit25(MAE_MURPHY & stm);

                // perform the 'entry behavior'
                void _doentry(MAE_MURPHY & stm);

                // returns the state containing the current
                virtual AnyState * _upper(MAE_MURPHY & stm);

            };
            
            // implement the state sortie de zone de depart
            class sortie_de_zone_de_depart_State : public AnyState {
              public:
                virtual ~sortie_de_zone_de_depart_State();

                // to manage the event assFini
                virtual void assFini(MAE_MURPHY & stm);

                // to manage the event create
                virtual void create(MAE_MURPHY & stm);

                // perform the 'entry behavior'
                void _doentry(MAE_MURPHY & stm);

                // returns the state containing the current
                virtual AnyState * _upper(MAE_MURPHY & stm);

                // perform the 'exit behavior'
                void _doexit(MAE_MURPHY & stm);

            };
            
            // implement the state mission depot de tour zone depart
            class mission_depot_de_tour_zone_depart_State : public AnyState {
              public:
                // implement the state way point initial
                class way_point_initial_State : public AnyState {
                  public:
                    // implement the state cap to mission
                    class cap_to_mission_State : public AnyState {
                      public:
                        virtual ~cap_to_mission_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state cap mission
                    class cap_mission_State : public AnyState {
                      public:
                        virtual ~cap_mission_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                        // perform the 'exit behavior'
                        void _doexit(MAE_MURPHY & stm);

                    };
                    
                    // implement the state BF droite to mission
                    class BF_droite_to_mission_State : public AnyState {
                      public:
                        virtual ~BF_droite_to_mission_State();

                        // to manage the exit point 'sortie', defined because probably shared
                        void _exit19(MAE_MURPHY & stm);

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    virtual ~way_point_initial_State();

                    // memorize the instance of the state cap to mission, internal
                    cap_to_mission_State _cap_to_mission_state;

                    // memorize the instance of the state BF droite to mission, internal
                    BF_droite_to_mission_State _bf_droite_to_mission_state;

                    // memorize the instance of the state cap mission, internal
                    cap_mission_State _cap_mission_state;

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state BF cap vers la zone adverse
                class BF_cap_vers_la_zone_adverse_State : public AnyState {
                  public:
                    virtual ~BF_cap_vers_la_zone_adverse_State();

                    // to manage the event assFini
                    virtual void assFini(MAE_MURPHY & stm);

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state rembale les pinces
                class rembale_les_pinces_State : public AnyState {
                  public:
                    virtual ~rembale_les_pinces_State();

                    // to manage the event pince_range
                    virtual void pince_range(MAE_MURPHY & stm);

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // perform the 'exit behavior'
                    void _doexit(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state prepare la pose
                class prepare_la_pose_State : public AnyState {
                  public:
                    virtual ~prepare_la_pose_State();

                    // to manage the event pince_ready_to_drop
                    virtual void pince_ready_to_drop(MAE_MURPHY & stm);

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state recule
                class recule_State : public AnyState {
                  public:
                    virtual ~recule_State();

                    // to manage the event assFini
                    virtual void assFini(MAE_MURPHY & stm);

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state avance
                class avance_State : public AnyState {
                  public:
                    virtual ~avance_State();

                    // to manage the event assFini
                    virtual void assFini(MAE_MURPHY & stm);

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                    // to manage the event blocage
                    virtual void blocage(MAE_MURPHY & stm);

                };
                
                // implement the state depot une tour
                class depot_une_tour_State : public AnyState {
                  public:
                    virtual ~depot_une_tour_State();

                    // to manage the event pince_lache
                    virtual void pince_lache(MAE_MURPHY & stm);

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                virtual ~mission_depot_de_tour_zone_depart_State();

                // memorize the instance of the state way point initial, internal
                way_point_initial_State _way_point_initial_state;

                // memorize the instance of the state depot une tour, internal
                depot_une_tour_State _depot_une_tour_state;

                // memorize the instance of the state avance, internal
                avance_State _avance_state;

                // memorize the instance of the state recule, internal
                recule_State _recule_state;

                // memorize the instance of the state prepare la pose, internal
                prepare_la_pose_State _prepare_la_pose_state;

                // memorize the instance of the state rembale les pinces, internal
                rembale_les_pinces_State _rembale_les_pinces_state;

                // memorize the instance of the state BF cap vers la zone adverse, internal
                BF_cap_vers_la_zone_adverse_State _bf_cap_vers_la_zone_adverse_state;

                // to manage the event create
                virtual void create(MAE_MURPHY & stm);

                // to manage the exit point 'sortie ', defined because probably shared
                void _exit20(MAE_MURPHY & stm);

                // perform the 'entry behavior'
                void _doentry(MAE_MURPHY & stm);

                // returns the state containing the current
                virtual AnyState * _upper(MAE_MURPHY & stm);

            };
            
            // implement the state mission rush zone centrale
            class mission_rush_zone_centrale_State : public AnyState {
              public:
                // implement the state waypoint init
                class waypoint_init_State : public AnyState {
                  public:
                    // implement the state cap to mission
                    class cap_to_mission_State : public AnyState {
                      public:
                        virtual ~cap_to_mission_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state cap mission
                    class cap_mission_State : public AnyState {
                      public:
                        virtual ~cap_mission_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                        // perform the 'exit behavior'
                        void _doexit(MAE_MURPHY & stm);

                    };
                    
                    // implement the state BF droite to mission
                    class BF_droite_to_mission_State : public AnyState {
                      public:
                        virtual ~BF_droite_to_mission_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    virtual ~waypoint_init_State();

                    // memorize the instance of the state cap to mission, internal
                    cap_to_mission_State _cap_to_mission_state;

                    // memorize the instance of the state BF droite to mission, internal
                    BF_droite_to_mission_State _bf_droite_to_mission_state;

                    // memorize the instance of the state cap mission, internal
                    cap_mission_State _cap_mission_state;

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // to manage the exit point 'sortie', defined because probably shared
                    void _exit18(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state tempo pour coop'r?
                class tempo_pour_coopr_State : public AnyState {
                  public:
                    virtual ~tempo_pour_coopr_State();

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // perform the 'exit behavior'
                    void _doexit(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                    virtual bool _completion(MAE_MURPHY & stm);

                };
                
                // implement the state chope stand 3
                class chope_stand_3_State : public AnyState {
                  public:
                    virtual ~chope_stand_3_State();

                    // to manage the event pince_stand_by
                    virtual void pince_stand_by(MAE_MURPHY & stm);

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // perform the 'exit behavior'
                    void _doexit(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state BF droite stand 3
                class BF_droite_stand_3_State : public AnyState {
                  public:
                    virtual ~BF_droite_stand_3_State();

                    // to manage the event assFini
                    virtual void assFini(MAE_MURPHY & stm);

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state re re ouverture pince
                class re_re_ouverture_pince_State : public AnyState {
                  public:
                    virtual ~re_re_ouverture_pince_State();

                    // to manage the event pince_ouverte
                    virtual void pince_ouverte(MAE_MURPHY & stm);

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state BF cap sur stand 3
                class BF_cap_sur_stand_3_State : public AnyState {
                  public:
                    virtual ~BF_cap_sur_stand_3_State();

                    // to manage the event assFini
                    virtual void assFini(MAE_MURPHY & stm);

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state chope stand 2
                class chope_stand_2_State : public AnyState {
                  public:
                    virtual ~chope_stand_2_State();

                    // to manage the event pince_stand_by
                    virtual void pince_stand_by(MAE_MURPHY & stm);

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // perform the 'exit behavior'
                    void _doexit(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state BF droite stand 2
                class BF_droite_stand_2_State : public AnyState {
                  public:
                    virtual ~BF_droite_stand_2_State();

                    // to manage the event assFini
                    virtual void assFini(MAE_MURPHY & stm);

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state re ouverture pince
                class re_ouverture_pince_State : public AnyState {
                  public:
                    virtual ~re_ouverture_pince_State();

                    // to manage the event pince_ouverte
                    virtual void pince_ouverte(MAE_MURPHY & stm);

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state chope stand 1
                class chope_stand_1_State : public AnyState {
                  public:
                    virtual ~chope_stand_1_State();

                    // to manage the event pince_stand_by
                    virtual void pince_stand_by(MAE_MURPHY & stm);

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // perform the 'exit behavior'
                    void _doexit(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state BF droite stand 1
                class BF_droite_stand_1_State : public AnyState {
                  public:
                    virtual ~BF_droite_stand_1_State();

                    // to manage the event assFini
                    virtual void assFini(MAE_MURPHY & stm);

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state ouverture pince
                class ouverture_pince_State : public AnyState {
                  public:
                    virtual ~ouverture_pince_State();

                    // to manage the event pince_ouverte
                    virtual void pince_ouverte(MAE_MURPHY & stm);

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                virtual ~mission_rush_zone_centrale_State();

                // memorize the instance of the state waypoint init, internal
                waypoint_init_State _waypoint_init_state;

                // memorize the instance of the state ouverture pince, internal
                ouverture_pince_State _ouverture_pince_state;

                // memorize the instance of the state BF droite stand 1, internal
                BF_droite_stand_1_State _bf_droite_stand_1_state;

                // memorize the instance of the state chope stand 1, internal
                chope_stand_1_State _chope_stand_1_state;

                // memorize the instance of the state re ouverture pince, internal
                re_ouverture_pince_State _re_ouverture_pince_state;

                // memorize the instance of the state BF droite stand 2, internal
                BF_droite_stand_2_State _bf_droite_stand_2_state;

                // memorize the instance of the state chope stand 2, internal
                chope_stand_2_State _chope_stand_2_state;

                // memorize the instance of the state BF cap sur stand 3, internal
                BF_cap_sur_stand_3_State _bf_cap_sur_stand_3_state;

                // memorize the instance of the state re re ouverture pince, internal
                re_re_ouverture_pince_State _re_re_ouverture_pince_state;

                // memorize the instance of the state BF droite stand 3, internal
                BF_droite_stand_3_State _bf_droite_stand_3_state;

                // memorize the instance of the state chope stand 3, internal
                chope_stand_3_State _chope_stand_3_state;

                // memorize the instance of the state tempo pour coop'r?, internal
                tempo_pour_coopr_State _tempo_pour_coopr_state;

                // to manage the event create
                virtual void create(MAE_MURPHY & stm);

                // to manage the exit point 'sortie zone centrale', defined because probably shared
                void _exit17(MAE_MURPHY & stm);

                // perform the 'entry behavior'
                void _doentry(MAE_MURPHY & stm);

                // returns the state containing the current
                virtual AnyState * _upper(MAE_MURPHY & stm);

            };
            
            // implement the state mission claps
            class mission_claps_State : public AnyState {
              public:
                // implement the state chope du stand sur la route
                class chope_du_stand_sur_la_route_State : public AnyState {
                  public:
                    // implement the state BF droite
                    class BF_droite_State : public AnyState {
                      public:
                        virtual ~BF_droite_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state chope
                    class chope_State : public AnyState {
                      public:
                        virtual ~chope_State();

                        // to manage the event pince_stand_by
                        virtual void pince_stand_by(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // perform the 'exit behavior'
                        void _doexit(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state ouverture de pince
                    class ouverture_de_pince_State : public AnyState {
                      public:
                        virtual ~ouverture_de_pince_State();

                        // to manage the event pince_ouverte
                        virtual void pince_ouverte(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    virtual ~chope_du_stand_sur_la_route_State();

                    // memorize the instance of the state BF droite, internal
                    BF_droite_State _bf_droite_state;

                    // memorize the instance of the state ouverture de pince, internal
                    ouverture_de_pince_State _ouverture_de_pince_state;

                    // memorize the instance of the state chope, internal
                    chope_State _chope_state;

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // to manage the exit point 'sortie stand', defined because probably shared
                    void _exit11(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state sortie de zone
                class sortie_de_zone_State : public AnyState {
                  public:
                    // implement the state BF cap
                    class BF_cap_State : public AnyState {
                      public:
                        virtual ~BF_cap_State();

                        virtual bool _completion(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state avance
                    class avance_State : public AnyState {
                      public:
                        virtual ~avance_State();

                        virtual bool _completion(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    virtual ~sortie_de_zone_State();

                    // memorize the instance of the state BF cap, internal
                    BF_cap_State _bf_cap_state;

                    // memorize the instance of the state avance, internal
                    avance_State _avance_state;

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // to manage the exit point 'sortie', defined because probably shared
                    void _exit15(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state waypoint initial
                class waypoint_initial_State : public AnyState {
                  public:
                    // implement the state cap to mission
                    class cap_to_mission_State : public AnyState {
                      public:
                        virtual ~cap_to_mission_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state cap mission
                    class cap_mission_State : public AnyState {
                      public:
                        virtual ~cap_mission_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                        // perform the 'exit behavior'
                        void _doexit(MAE_MURPHY & stm);

                    };
                    
                    // implement the state BF droite to mission
                    class BF_droite_to_mission_State : public AnyState {
                      public:
                        virtual ~BF_droite_to_mission_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    virtual ~waypoint_initial_State();

                    // memorize the instance of the state cap to mission, internal
                    cap_to_mission_State _cap_to_mission_state;

                    // memorize the instance of the state BF droite to mission, internal
                    BF_droite_to_mission_State _bf_droite_to_mission_state;

                    // memorize the instance of the state cap mission, internal
                    cap_mission_State _cap_mission_state;

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // to manage the exit point 'sortie w', defined because probably shared
                    void _exit14(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state claps estrade
                class claps_estrade_State : public AnyState {
                  public:
                    // implement the state BF droite sur claps estrade
                    class BF_droite_sur_claps_estrade_State : public AnyState {
                      public:
                        virtual ~BF_droite_sur_claps_estrade_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state Claps 3
                    class Claps_3_State : public AnyState {
                      public:
                        virtual ~Claps_3_State();

                        // to manage the event claps_replie
                        virtual void claps_replie(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // perform the 'exit behavior'
                        void _doexit(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    virtual ~claps_estrade_State();

                    // memorize the instance of the state BF droite sur claps estrade, internal
                    BF_droite_sur_claps_estrade_State _bf_droite_sur_claps_estrade_state;

                    // memorize the instance of the state Claps 3, internal
                    Claps_3_State _claps_3_state;

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // to manage the exit point 'sortie claps', defined because probably shared
                    void _exit13(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state chope du coin
                class chope_du_coin_State : public AnyState {
                  public:
                    // implement the state BF droite sur le verre
                    class BF_droite_sur_le_verre_State : public AnyState {
                      public:
                        virtual ~BF_droite_sur_le_verre_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state avance claps
                    class avance_claps_State : public AnyState {
                      public:
                        virtual ~avance_claps_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state set X CAP
                    class set_X_CAP_State : public AnyState {
                      public:
                        virtual ~set_X_CAP_State();

                        // to manage the event time_out
                        virtual void time_out(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state deboit claps coin
                    class deboit_claps_coin_State : public AnyState {
                      public:
                        virtual ~deboit_claps_coin_State();

                        // to manage the event claps_replie
                        virtual void claps_replie(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // perform the 'exit behavior'
                        void _doexit(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state BF CAP pour claps
                    class BF_CAP_pour_claps_State : public AnyState {
                      public:
                        virtual ~BF_CAP_pour_claps_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state recalage
                    class recalage_State : public AnyState {
                      public:
                        virtual ~recalage_State();

                        // to manage the event blocage
                        virtual void blocage(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // perform the 'exit behavior'
                        void _doexit(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state chope stand 2
                    class chope_stand_2_State : public AnyState {
                      public:
                        virtual ~chope_stand_2_State();

                        // to manage the event pince_stand_by
                        virtual void pince_stand_by(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state re avance
                    class re_avance_State : public AnyState {
                      public:
                        virtual ~re_avance_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state re ouvre pince
                    class re_ouvre_pince_State : public AnyState {
                      public:
                        virtual ~re_ouvre_pince_State();

                        // to manage the event pince_ouverte
                        virtual void pince_ouverte(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state chope stand 1
                    class chope_stand_1_State : public AnyState {
                      public:
                        virtual ~chope_stand_1_State();

                        // to manage the event pince_stand_by
                        virtual void pince_stand_by(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state avance
                    class avance_State : public AnyState {
                      public:
                        virtual ~avance_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state ouvre pince
                    class ouvre_pince_State : public AnyState {
                      public:
                        virtual ~ouvre_pince_State();

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                        // to manage the event pince_ouverte
                        virtual void pince_ouverte(MAE_MURPHY & stm);

                    };
                    
                    // implement the state BF droite vers les stands
                    class BF_droite_vers_les_stands_State : public AnyState {
                      public:
                        virtual ~BF_droite_vers_les_stands_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state recule vers la zone de depart
                    class recule_vers_la_zone_de_depart_State : public AnyState {
                      public:
                        virtual ~recule_vers_la_zone_de_depart_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state recule des stands
                    class recule_des_stands_State : public AnyState {
                      public:
                        virtual ~recule_des_stands_State();

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state chope gobelet
                    class chope_gobelet_State : public AnyState {
                      public:
                        virtual ~chope_gobelet_State();

                        // to manage the event time_out
                        virtual void time_out(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    virtual ~chope_du_coin_State();

                    // memorize the instance of the state BF droite sur le verre, internal
                    BF_droite_sur_le_verre_State _bf_droite_sur_le_verre_state;

                    // memorize the instance of the state chope gobelet, internal
                    chope_gobelet_State _chope_gobelet_state;

                    // memorize the instance of the state recule des stands, internal
                    recule_des_stands_State _recule_des_stands_state;

                    // memorize the instance of the state recule vers la zone de depart, internal
                    recule_vers_la_zone_de_depart_State _recule_vers_la_zone_de_depart_state;

                    // memorize the instance of the state BF droite vers les stands, internal
                    BF_droite_vers_les_stands_State _bf_droite_vers_les_stands_state;

                    // memorize the instance of the state ouvre pince, internal
                    ouvre_pince_State _ouvre_pince_state;

                    // memorize the instance of the state avance, internal
                    avance_State _avance_state;

                    // memorize the instance of the state chope stand 1, internal
                    chope_stand_1_State _chope_stand_1_state;

                    // memorize the instance of the state re ouvre pince, internal
                    re_ouvre_pince_State _re_ouvre_pince_state;

                    // memorize the instance of the state re avance, internal
                    re_avance_State _re_avance_state;

                    // memorize the instance of the state chope stand 2, internal
                    chope_stand_2_State _chope_stand_2_state;

                    // memorize the instance of the state recalage, internal
                    recalage_State _recalage_state;

                    // memorize the instance of the state BF CAP pour claps, internal
                    BF_CAP_pour_claps_State _bf_cap_pour_claps_state;

                    // memorize the instance of the state deboit claps coin, internal
                    deboit_claps_coin_State _deboit_claps_coin_state;

                    // memorize the instance of the state set X CAP, internal
                    set_X_CAP_State _set_x_cap_state;

                    // memorize the instance of the state avance claps, internal
                    avance_claps_State _avance_claps_state;

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // to manage the exit point 'sortie coin', defined because probably shared
                    void _exit12(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                virtual ~mission_claps_State();

                // memorize the instance of the state chope du stand sur la route, internal
                chope_du_stand_sur_la_route_State _chope_du_stand_sur_la_route_state;

                // memorize the instance of the state chope du coin, internal
                chope_du_coin_State _chope_du_coin_state;

                // memorize the instance of the state claps estrade, internal
                claps_estrade_State _claps_estrade_state;

                // memorize the instance of the state waypoint initial, internal
                waypoint_initial_State _waypoint_initial_state;

                // memorize the instance of the state sortie de zone, internal
                sortie_de_zone_State _sortie_de_zone_state;

                // to manage the event create
                virtual void create(MAE_MURPHY & stm);

                // to manage the exit point 'fin claps', defined because probably shared
                void _exit16(MAE_MURPHY & stm);

                // perform the 'entry behavior'
                void _doentry(MAE_MURPHY & stm);

                // returns the state containing the current
                virtual AnyState * _upper(MAE_MURPHY & stm);

            };
            
            // implement the state mission attrap balle et chiage
            class mission_attrap_balle_et_chiage_State : public AnyState {
              public:
                // implement the state point de depart
                class point_de_depart_State : public AnyState {
                  public:
                    // implement the state orientation vers objectif
                    class orientation_vers_objectif_State : public AnyState {
                      public:
                        virtual ~orientation_vers_objectif_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state BF cap mission
                    class BF_cap_mission_State : public AnyState {
                      public:
                        virtual ~BF_cap_mission_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                        // perform the 'exit behavior'
                        void _doexit(MAE_MURPHY & stm);

                    };
                    
                    // implement the state BF droite to objectif
                    class BF_droite_to_objectif_State : public AnyState {
                      public:
                        virtual ~BF_droite_to_objectif_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    virtual ~point_de_depart_State();

                    // memorize the instance of the state orientation vers objectif, internal
                    orientation_vers_objectif_State _orientation_vers_objectif_state;

                    // memorize the instance of the state BF droite to objectif, internal
                    BF_droite_to_objectif_State _bf_droite_to_objectif_state;

                    // memorize the instance of the state BF cap mission, internal
                    BF_cap_mission_State _bf_cap_mission_state;

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // to manage the exit point 'sortie waypoint', defined because probably shared
                    void _exit9(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state transition avant reculage
                class transition_avant_reculage_State : public AnyState {
                  public:
                    virtual ~transition_avant_reculage_State();

                    // to manage the event assFini
                    virtual void assFini(MAE_MURPHY & stm);

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state sortie
                class sortie_State : public AnyState {
                  public:
                    virtual ~sortie_State();

                    virtual bool _completion(MAE_MURPHY & stm);

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state avance
                class avance_State : public AnyState {
                  public:
                    virtual ~avance_State();

                    // to manage the event assFini
                    virtual void assFini(MAE_MURPHY & stm);

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state drop gobelet
                class drop_gobelet_State : public AnyState {
                  public:
                    virtual ~drop_gobelet_State();

                    // to manage the event time_out
                    virtual void time_out(MAE_MURPHY & stm);

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state drop pop corn
                class drop_pop_corn_State : public AnyState {
                  public:
                    virtual ~drop_pop_corn_State();

                    // to manage the event time_out
                    virtual void time_out(MAE_MURPHY & stm);

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // perform the 'exit behavior'
                    void _doexit(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state capture de balle
                class capture_de_balle_State : public AnyState {
                  public:
                    virtual ~capture_de_balle_State();

                    // to manage the event fin_montee_bras
                    virtual void fin_montee_bras(MAE_MURPHY & stm);

                    // to manage the event time_out
                    virtual void time_out(MAE_MURPHY & stm);

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state Recalage
                class Recalage_State : public AnyState {
                  public:
                    virtual ~Recalage_State();

                    // to manage the event blocage
                    virtual void blocage(MAE_MURPHY & stm);

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // perform the 'exit behavior'
                    void _doexit(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state orientation avant reculage
                class orientation_avant_reculage_State : public AnyState {
                  public:
                    virtual ~orientation_avant_reculage_State();

                    // to manage the event assFini
                    virtual void assFini(MAE_MURPHY & stm);

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                virtual ~mission_attrap_balle_et_chiage_State();

                // memorize the instance of the state point de depart, internal
                point_de_depart_State _point_de_depart_state;

                // memorize the instance of the state orientation avant reculage, internal
                orientation_avant_reculage_State _orientation_avant_reculage_state;

                // memorize the instance of the state Recalage, internal
                Recalage_State _recalage_state;

                // memorize the instance of the state capture de balle, internal
                capture_de_balle_State _capture_de_balle_state;

                // memorize the instance of the state drop pop corn, internal
                drop_pop_corn_State _drop_pop_corn_state;

                // memorize the instance of the state drop gobelet, internal
                drop_gobelet_State _drop_gobelet_state;

                // memorize the instance of the state avance, internal
                avance_State _avance_state;

                // memorize the instance of the state sortie, internal
                sortie_State _sortie_state;

                // to manage the event create
                virtual void create(MAE_MURPHY & stm);

                // to manage the exit point 'sortie mission drop', defined because probably shared
                void _exit10(MAE_MURPHY & stm);

                // perform the 'entry behavior'
                void _doentry(MAE_MURPHY & stm);

                // returns the state containing the current
                virtual AnyState * _upper(MAE_MURPHY & stm);

                // memorize the instance of the state transition avant reculage, internal
                transition_avant_reculage_State _transition_avant_reculage_state;

            };
            
            // implement the state mission pillage distrib
            class mission_pillage_distrib_State : public AnyState {
              public:
                // implement the state sortie de la zone de depart
                class sortie_de_la_zone_de_depart_State : public AnyState {
                  public:
                    virtual ~sortie_de_la_zone_de_depart_State();

                    // to manage the event assFini
                    virtual void assFini(MAE_MURPHY & stm);

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state sortie zone
                class sortie_zone_State : public AnyState {
                  public:
                    virtual ~sortie_zone_State();

                    virtual bool _completion(MAE_MURPHY & stm);

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state rejoindre le point de depart mission
                class rejoindre_le_point_de_depart_mission_State : public AnyState {
                  public:
                    // implement the state orientation vers objectif
                    class orientation_vers_objectif_State : public AnyState {
                      public:
                        virtual ~orientation_vers_objectif_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state orientation cap mission
                    class orientation_cap_mission_State : public AnyState {
                      public:
                        virtual ~orientation_cap_mission_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                        // perform the 'exit behavior'
                        void _doexit(MAE_MURPHY & stm);

                    };
                    
                    // implement the state BF droite vers l'objectif
                    class BF_droite_vers_lobjectif_State : public AnyState {
                      public:
                        virtual ~BF_droite_vers_lobjectif_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    virtual ~rejoindre_le_point_de_depart_mission_State();

                    // memorize the instance of the state orientation vers objectif, internal
                    orientation_vers_objectif_State _orientation_vers_objectif_state;

                    // memorize the instance of the state BF droite vers l'objectif, internal
                    BF_droite_vers_lobjectif_State _bf_droite_vers_lobjectif_state;

                    // memorize the instance of the state orientation cap mission, internal
                    orientation_cap_mission_State _orientation_cap_mission_state;

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // to manage the exit point 'sortie', defined because probably shared
                    void _exit7(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state vidage distributeur
                class vidage_distributeur_State : public AnyState {
                  public:
                    // implement the state avance
                    class avance_State : public AnyState {
                      public:
                        virtual ~avance_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state orientation vers sortie de zone
                    class orientation_vers_sortie_de_zone_State : public AnyState {
                      public:
                        virtual ~orientation_vers_sortie_de_zone_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state recule
                    class recule_State : public AnyState {
                      public:
                        virtual ~recule_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state pompage
                    class pompage_State : public AnyState {
                      public:
                        virtual ~pompage_State();

                        // to manage the event distrib_deboite
                        virtual void distrib_deboite(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // perform the 'exit behavior'
                        void _doexit(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state SET Y CAP
                    class SET_Y_CAP_State : public AnyState {
                      public:
                        virtual ~SET_Y_CAP_State();

                        virtual bool _completion(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state BF avance jusquau blocage
                    class BF_avance_jusquau_blocage_State : public AnyState {
                      public:
                        virtual ~BF_avance_jusquau_blocage_State();

                        // to manage the event blocage
                        virtual void blocage(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // perform the 'do activity'
                        virtual void _do(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state BF droite sur distrib
                    class BF_droite_sur_distrib_State : public AnyState {
                      public:
                        virtual ~BF_droite_sur_distrib_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                        // to manage the event blocage
                        virtual void blocage(MAE_MURPHY & stm);

                    };
                    
                    virtual ~vidage_distributeur_State();

                    // memorize the instance of the state BF droite sur distrib, internal
                    BF_droite_sur_distrib_State _bf_droite_sur_distrib_state;

                    // memorize the instance of the state BF avance jusquau blocage, internal
                    BF_avance_jusquau_blocage_State _bf_avance_jusquau_blocage_state;

                    // memorize the instance of the state SET Y CAP, internal
                    SET_Y_CAP_State _set_y_cap_state;

                    // memorize the instance of the state pompage, internal
                    pompage_State _pompage_state;

                    // memorize the instance of the state recule, internal
                    recule_State _recule_state;

                    // memorize the instance of the state orientation vers sortie de zone, internal
                    orientation_vers_sortie_de_zone_State _orientation_vers_sortie_de_zone_state;

                    // memorize the instance of the state avance, internal
                    avance_State _avance_state;

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // to manage the exit point 'sortie pompage', defined because probably shared
                    void _exit6(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state capture stand bordure
                class capture_stand_bordure_State : public AnyState {
                  public:
                    // implement the state BF cap vers objectif
                    class BF_cap_vers_objectif_State : public AnyState {
                      public:
                        virtual ~BF_cap_vers_objectif_State();

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                    };
                    
                    // implement the state recule
                    class recule_State : public AnyState {
                      public:
                        virtual ~recule_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state chope
                    class chope_State : public AnyState {
                      public:
                        virtual ~chope_State();

                        // to manage the event pince_stand_by
                        virtual void pince_stand_by(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state BF avance
                    class BF_avance_State : public AnyState {
                      public:
                        virtual ~BF_avance_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state ouverture pince cote bordure
                    class ouverture_pince_cote_bordure_State : public AnyState {
                      public:
                        virtual ~ouverture_pince_cote_bordure_State();

                        // to manage the event pince_ouverte
                        virtual void pince_ouverte(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    virtual ~capture_stand_bordure_State();

                    // memorize the instance of the state BF cap vers objectif, internal
                    BF_cap_vers_objectif_State _bf_cap_vers_objectif_state;

                    // memorize the instance of the state ouverture pince cote bordure, internal
                    ouverture_pince_cote_bordure_State _ouverture_pince_cote_bordure_state;

                    // memorize the instance of the state BF avance, internal
                    BF_avance_State _bf_avance_state;

                    // memorize the instance of the state chope, internal
                    chope_State _chope_state;

                    // memorize the instance of the state recule, internal
                    recule_State _recule_state;

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // to manage the exit point 'sortie stand bordure', defined because probably shared
                    void _exit5(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                // implement the state capture stands cote escalier
                class capture_stands_cote_escalier_State : public AnyState {
                  public:
                    // implement the state BF cap initial 35deg
                    class BF_cap_initial_35deg_State : public AnyState {
                      public:
                        virtual ~BF_cap_initial_35deg_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state recule
                    class recule_State : public AnyState {
                      public:
                        virtual ~recule_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state chope 2
                    class chope_2_State : public AnyState {
                      public:
                        virtual ~chope_2_State();

                        // to manage the event pince_stand_by
                        virtual void pince_stand_by(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state BF avance seconde
                    class BF_avance_seconde_State : public AnyState {
                      public:
                        virtual ~BF_avance_seconde_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                        // to manage the event blocage
                        virtual void blocage(MAE_MURPHY & stm);

                    };
                    
                    // implement the state ouverture pince cote escalier seconde
                    class ouverture_pince_cote_escalier_seconde_State : public AnyState {
                      public:
                        virtual ~ouverture_pince_cote_escalier_seconde_State();

                        // to manage the event pince_ouverte
                        virtual void pince_ouverte(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state chope 1
                    class chope_1_State : public AnyState {
                      public:
                        virtual ~chope_1_State();

                        // to manage the event pince_stand_by
                        virtual void pince_stand_by(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state BF avance
                    class BF_avance_State : public AnyState {
                      public:
                        virtual ~BF_avance_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state ouverture pince cote escalier
                    class ouverture_pince_cote_escalier_State : public AnyState {
                      public:
                        virtual ~ouverture_pince_cote_escalier_State();

                        // to manage the event pince_ouverte
                        virtual void pince_ouverte(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state BF droite vers le stand
                    class BF_droite_vers_le_stand_State : public AnyState {
                      public:
                        virtual ~BF_droite_vers_le_stand_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    virtual ~capture_stands_cote_escalier_State();

                    // memorize the instance of the state BF cap initial 35deg, internal
                    BF_cap_initial_35deg_State _bf_cap_initial_35deg_state;

                    // memorize the instance of the state ouverture pince cote escalier, internal
                    ouverture_pince_cote_escalier_State _ouverture_pince_cote_escalier_state;

                    // memorize the instance of the state BF avance, internal
                    BF_avance_State _bf_avance_state;

                    // memorize the instance of the state chope 1, internal
                    chope_1_State _chope_1_state;

                    // memorize the instance of the state ouverture pince cote escalier seconde, internal
                    ouverture_pince_cote_escalier_seconde_State _ouverture_pince_cote_escalier_seconde_state;

                    // memorize the instance of the state BF avance seconde, internal
                    BF_avance_seconde_State _bf_avance_seconde_state;

                    // memorize the instance of the state chope 2, internal
                    chope_2_State _chope_2_state;

                    // memorize the instance of the state recule, internal
                    recule_State _recule_state;

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // to manage the exit point 'sortie chope stands escalier', defined because probably shared
                    void _exit4(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                    // memorize the instance of the state BF droite vers le stand, internal
                    BF_droite_vers_le_stand_State _bf_droite_vers_le_stand_state;

                };
                
                // implement the state capture de gobelet escalier
                class capture_de_gobelet_escalier_State : public AnyState {
                  public:
                    // implement the state deplacement cible
                    class deplacement_cible_State : public AnyState {
                      public:
                        virtual ~deplacement_cible_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state recule
                    class recule_State : public AnyState {
                      public:
                        virtual ~recule_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state BF cap vers la zone de distrib
                    class BF_cap_vers_la_zone_de_distrib_State : public AnyState {
                      public:
                        virtual ~BF_cap_vers_la_zone_de_distrib_State();

                        // to manage the event assFini
                        virtual void assFini(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    // implement the state capture
                    class capture_State : public AnyState {
                      public:
                        virtual ~capture_State();

                        // to manage the event time_out
                        virtual void time_out(MAE_MURPHY & stm);

                        // to manage the event create
                        virtual void create(MAE_MURPHY & stm);

                        // perform the 'entry behavior'
                        void _doentry(MAE_MURPHY & stm);

                        // returns the state containing the current
                        virtual AnyState * _upper(MAE_MURPHY & stm);

                    };
                    
                    virtual ~capture_de_gobelet_escalier_State();

                    // memorize the instance of the state deplacement cible, internal
                    deplacement_cible_State _deplacement_cible_state;

                    // memorize the instance of the state capture, internal
                    capture_State _capture_state;

                    // memorize the instance of the state BF cap vers la zone de distrib, internal
                    BF_cap_vers_la_zone_de_distrib_State _bf_cap_vers_la_zone_de_distrib_state;

                    // memorize the instance of the state recule, internal
                    recule_State _recule_state;

                    // to manage the event create
                    virtual void create(MAE_MURPHY & stm);

                    // to manage the exit point 'sortie capture gobelet', defined because probably shared
                    void _exit3(MAE_MURPHY & stm);

                    // perform the 'entry behavior'
                    void _doentry(MAE_MURPHY & stm);

                    // returns the state containing the current
                    virtual AnyState * _upper(MAE_MURPHY & stm);

                };
                
                virtual ~mission_pillage_distrib_State();

                // memorize the instance of the state sortie de la zone de depart, internal
                sortie_de_la_zone_de_depart_State _sortie_de_la_zone_de_depart_state;

                // memorize the instance of the state capture de gobelet escalier, internal
                capture_de_gobelet_escalier_State _capture_de_gobelet_escalier_state;

                // memorize the instance of the state capture stands cote escalier, internal
                capture_stands_cote_escalier_State _capture_stands_cote_escalier_state;

                // memorize the instance of the state capture stand bordure, internal
                capture_stand_bordure_State _capture_stand_bordure_state;

                // memorize the instance of the state vidage distributeur, internal
                vidage_distributeur_State _vidage_distributeur_state;

                // memorize the instance of the state rejoindre le point de depart mission, internal
                rejoindre_le_point_de_depart_mission_State _rejoindre_le_point_de_depart_mission_state;

                // memorize the instance of the state sortie zone, internal
                sortie_zone_State _sortie_zone_state;

                // to manage the event create
                virtual void create(MAE_MURPHY & stm);

                // to manage the exit point 'sortie pillage distrib', defined because probably shared
                void _exit8(MAE_MURPHY & stm);

                // perform the 'entry behavior'
                void _doentry(MAE_MURPHY & stm);

                // returns the state containing the current
                virtual AnyState * _upper(MAE_MURPHY & stm);

            };
            
            virtual ~Jeu_State();

            // memorize the instance of the state mission depot tour estrade, internal
            mission_depot_tour_estrade_State _mission_depot_tour_estrade_state;

            // memorize the instance of the state mission pillage distrib, internal
            mission_pillage_distrib_State _mission_pillage_distrib_state;

            // memorize the instance of the state mission attrap balle et chiage, internal
            mission_attrap_balle_et_chiage_State _mission_attrap_balle_et_chiage_state;

            // memorize the instance of the state mission claps, internal
            mission_claps_State _mission_claps_state;

            // memorize the instance of the state mission rush zone centrale, internal
            mission_rush_zone_centrale_State _mission_rush_zone_centrale_state;

            // memorize the instance of the state mission depot de tour zone depart, internal
            mission_depot_de_tour_zone_depart_State _mission_depot_de_tour_zone_depart_state;

            // memorize the instance of the state sortie de zone de depart, internal
            sortie_de_zone_de_depart_State _sortie_de_zone_de_depart_state;

            // memorize the instance of the state mission zone ennemie, internal
            mission_zone_ennemie_State _mission_zone_ennemie_state;

            // memorize the instance of the state decision, internal
            decision_State _decision_state;

            // to manage the event evitement
            virtual void evitement(MAE_MURPHY & stm);

            // to manage the event create
            virtual void create(MAE_MURPHY & stm);

            // to manage the event end_game
            virtual void end_game(MAE_MURPHY & stm);

            // perform the 'entry behavior'
            void _doentry(MAE_MURPHY & stm);

            // returns the state containing the current
            virtual AnyState * _upper(MAE_MURPHY & stm);

        };
        
        virtual ~MAE_MURPHY_State();

        // memorize the instance of the state Initialisation, internal
        Initialisation_State _initialisation_state;

        // memorize the instance of the state Jeu, internal
        Jeu_State _jeu_state;

        // memorize the instance of the state Evitement, internal
        Evitement_State _evitement_state;

        // memorize the instance of the state Recalage Initial, internal
        Recalage_Initial_State _recalage_initial_state;

        // memorize the instance of the state startin' block, internal
        startin_block_State _startin_block_state;

        // memorize the instance of the state Game Over, internal
        Game_Over_State _game_over_state;

        // to manage the event create
        virtual void create(MAE_MURPHY & stm);

        // returns the state containing the current
        virtual AnyState * _upper(MAE_MURPHY &);

    };
    
    // memorize the instance of the state MAE_MURPHY, internal
    MAE_MURPHY_State _mae_murphy_state;


  public:
    MAE_MURPHY();

    virtual ~MAE_MURPHY();

    // the operation you call to signal the event create
    bool create();

    // the operation you call to signal the event start_mis
    bool start_mis();

  friend class MAE_MURPHY_State::Initialisation_State;
    // the operation you call to signal the event assFini
    bool assFini();

  friend class MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::waypoint_init_State::BF_cap_to_mission_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::waypoint_init_State::BF_droite_to_mission_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::waypoint_init_State::BF_cap_mission_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::waypoint_init_State;
    // the operation you call to signal the event pince_lache
    bool pince_lache();

  friend class MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::depot_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::recule_doucement_State;
    // the operation you call to signal the event pince_ready_to_drop
    bool pince_ready_to_drop();

  friend class MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::preparation_State;
    // the operation you call to signal the event blocage
    bool blocage();

  friend class MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::avance_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::set_Y_CAP_State;
    // the operation you call to signal the event pince_range
    bool pince_range();

  friend class MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::replis_des_pinces_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State::BF_Cap_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_depot_tour_estrade_State;
    // the operation you call to signal the event evitement
    bool evitement();

  friend class MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::sortie_de_la_zone_de_depart_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_de_gobelet_escalier_State::deplacement_cible_State;
    // the operation you call to signal the event time_out
    bool time_out();

  friend class MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_de_gobelet_escalier_State::capture_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_de_gobelet_escalier_State::BF_cap_vers_la_zone_de_distrib_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_de_gobelet_escalier_State::recule_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_de_gobelet_escalier_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::BF_cap_initial_35deg_State;
    // the operation you call to signal the event pince_ouverte
    bool pince_ouverte();

  friend class MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::ouverture_pince_cote_escalier_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::BF_avance_State;
    // the operation you call to signal the event pince_stand_by
    bool pince_stand_by();

  friend class MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::chope_1_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::ouverture_pince_cote_escalier_seconde_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::BF_avance_seconde_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::chope_2_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::recule_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stand_bordure_State::BF_cap_vers_objectif_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stand_bordure_State::ouverture_pince_cote_bordure_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stand_bordure_State::BF_avance_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stand_bordure_State::chope_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stand_bordure_State::recule_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stand_bordure_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::BF_droite_sur_distrib_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::BF_avance_jusquau_blocage_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::SET_Y_CAP_State;
    // the operation you call to signal the event distrib_deboite
    bool distrib_deboite();

  friend class MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::pompage_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::recule_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::orientation_vers_sortie_de_zone_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State::avance_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::vidage_distributeur_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::rejoindre_le_point_de_depart_mission_State::orientation_vers_objectif_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::rejoindre_le_point_de_depart_mission_State::BF_droite_vers_lobjectif_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::rejoindre_le_point_de_depart_mission_State::orientation_cap_mission_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::rejoindre_le_point_de_depart_mission_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::sortie_zone_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::point_de_depart_State::orientation_vers_objectif_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::point_de_depart_State::BF_droite_to_objectif_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::point_de_depart_State::BF_cap_mission_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::point_de_depart_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::orientation_avant_reculage_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::Recalage_State;
    // the operation you call to signal the event fin_montee_bras
    bool fin_montee_bras();

  friend class MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::capture_de_balle_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::drop_pop_corn_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::drop_gobelet_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::avance_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::sortie_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_stand_sur_la_route_State::BF_droite_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_stand_sur_la_route_State::ouverture_de_pince_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_stand_sur_la_route_State::chope_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_stand_sur_la_route_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::BF_droite_sur_le_verre_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::chope_gobelet_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::recule_des_stands_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::recule_vers_la_zone_de_depart_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::BF_droite_vers_les_stands_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::ouvre_pince_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::avance_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::chope_stand_1_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::re_ouvre_pince_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::re_avance_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::chope_stand_2_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::recalage_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::BF_CAP_pour_claps_State;
    // the operation you call to signal the event claps_replie
    bool claps_replie();

  friend class MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::deboit_claps_coin_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::set_X_CAP_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State::avance_claps_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_claps_State::chope_du_coin_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_claps_State::claps_estrade_State::BF_droite_sur_claps_estrade_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_claps_State::claps_estrade_State::Claps_3_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_claps_State::claps_estrade_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_claps_State::waypoint_initial_State::cap_to_mission_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_claps_State::waypoint_initial_State::BF_droite_to_mission_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_claps_State::waypoint_initial_State::cap_mission_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_claps_State::waypoint_initial_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_claps_State::sortie_de_zone_State::BF_cap_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_claps_State::sortie_de_zone_State::avance_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_claps_State::sortie_de_zone_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_claps_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::waypoint_init_State::cap_to_mission_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::waypoint_init_State::BF_droite_to_mission_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::waypoint_init_State::cap_mission_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::waypoint_init_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::ouverture_pince_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::BF_droite_stand_1_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::chope_stand_1_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::re_ouverture_pince_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::BF_droite_stand_2_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::chope_stand_2_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::BF_cap_sur_stand_3_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::re_re_ouverture_pince_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::BF_droite_stand_3_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::chope_stand_3_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State::tempo_pour_coopr_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_rush_zone_centrale_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::way_point_initial_State::cap_to_mission_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::way_point_initial_State::BF_droite_to_mission_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::way_point_initial_State::cap_mission_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::way_point_initial_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::depot_une_tour_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::avance_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::recule_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::prepare_la_pose_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::rembale_les_pinces_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State::BF_cap_vers_la_zone_adverse_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_depot_de_tour_zone_depart_State;
  friend class MAE_MURPHY_State::Jeu_State::sortie_de_zone_de_depart_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::waypoint_initial_State::cap_to_mission_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::waypoint_initial_State::BF_droite_to_mission_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::waypoint_initial_State::cap_mission_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::waypoint_initial_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::claps_central_State::BF_droite_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::claps_central_State::ouverture_claps_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::claps_central_State::BF_cap_to_cine_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::claps_central_State::BF_cap_vers_estrade_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::claps_central_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::depot_gobelet_State::BF_droite_sur_le_cine_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::depot_gobelet_State::BF_CAP_vers_centre_de_la_table_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::depot_gobelet_State::ouverture_capot_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::depot_gobelet_State::avance_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::depot_gobelet_State::fermeture_capot_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::depot_gobelet_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::to_escalier_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::to_estrade_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::deboit_les_cines_adverses_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::chieur_stop_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::chieur_faible_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State::chieur_plus_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State::faire_chier_en_zizagant_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_zone_ennemie_State;
    // the operation you call to signal the event mission_distrib
    bool mission_distrib();

    // the operation you call to signal the event mission_claps
    bool mission_claps();

    // the operation you call to signal the event mission_depot_tour_depart
    bool mission_depot_tour_depart();

    // the operation you call to signal the event mission_zone_ennemie
    bool mission_zone_ennemie();

    // the operation you call to signal the event mission_chiage_balle
    bool mission_chiage_balle();

    // the operation you call to signal the event mission_zone_centrale
    bool mission_zone_centrale();

    // the operation you call to signal the event mission_depot_tour_estrade
    bool mission_depot_tour_estrade();

  friend class MAE_MURPHY_State::Jeu_State::decision_State;
    // the operation you call to signal the event end_game
    bool end_game();

  friend class MAE_MURPHY_State::Jeu_State;
  friend class MAE_MURPHY_State::Evitement_State::faire_des_maneuvre_State;
  friend class MAE_MURPHY_State::Evitement_State;
  friend class MAE_MURPHY_State::Recalage_Initial_State::Recule_State;
  friend class MAE_MURPHY_State::Recalage_Initial_State::set_X_Y_CAP_State;
  friend class MAE_MURPHY_State::Recalage_Initial_State::coup_de_patte_cote_escalier_pour_confirmer_le_sens_State;
  friend class MAE_MURPHY_State::Recalage_Initial_State::avance_State;
  friend class MAE_MURPHY_State::Recalage_Initial_State;
    // the operation you call to signal the event start_enleve
    bool start_enleve();

  friend class MAE_MURPHY_State::startin_block_State;
  friend class MAE_MURPHY_State::Game_Over_State;
  friend class MAE_MURPHY_State;
    // to execute the current state 'do activity'
    void doActivity();


  protected:
    // change the current state, internal
    inline void _set_currentState(AnyState & st);

    // execution done, internal
    void _final();

    // contains the current state, internal
    AnyState * _current_state;

  friend class MAE_MURPHY_State::Jeu_State::mission_attrap_balle_et_chiage_State::transition_avant_reculage_State;
  friend class MAE_MURPHY_State::Jeu_State::mission_pillage_distrib_State::capture_stands_cote_escalier_State::BF_droite_vers_le_stand_State;
};
// change the current state, internal
inline void MAE_MURPHY::_set_currentState(MAE_MURPHY::AnyState & st) {
    _current_state = &st;
}

#endif
