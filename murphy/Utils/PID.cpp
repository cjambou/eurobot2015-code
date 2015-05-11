#include "PID.h"

/** Constructeur PID par default
**/
PID::PID():last_error(0.),
    I_sum(0.),
    target(0.),
    Kp(3.45),  //Ku = 5.75
    Kd(4.6),
    Ki(0.6468),
    minV(-255),
    maxV(255),
    inAuto(true)
{
}

/** Constructeur plus complexe
**/
PID::PID(bool type_cap_, float Kp_, float Ki_, float Kd_, float near_error_value_, float done_error_value_):
    last_error(0.),
    I_sum(0.),
    target(0.),
    Kp(Kp_),  //Ku = 5.75
    Kd(Kd_),
    Ki(Ki_),
    near_error_value(near_error_value_),
    done_error_value(done_error_value_),
    minV(-500),
    maxV(500),
    inAuto(true),
    type_cap(type_cap_)
{
    // autre merde a init si on veut
}

/** modification des bornes inf et sup
// attention pour sabertooth : PWM (1000 -> 2000)
//                             Serie (-128,128)
**/
void PID::setMinMax(int v)
{
    minV = -v;
    maxV = v;
}


/** definition de la cible
**/
void PID::setTarget(float target_){
    target = target_;
}


/** add to target? erreur?
**/
void PID::addToTarget(float dep){
    target = target + dep;
}


/** Modification des gains
**/
void PID::setTuning(float Kp_, float Ki_, float Kd_){
    Kp = Kp_;
    Ki = Ki_;
    Kd = Kd_;
}



/** Calcul des PIDs
**/
float PID::compute(float input){
    // si on est pas en mode auto, commande a zero
    if (!inAuto)
    {
        return 0.;
    }

    float error;

    if (type_cap)
    {
        error = diff_cap(target, input);
    }
    else
    {
        error = target - input;
    }

    //Serial.print("error");
    //Serial.print(error);
   // Serial.print(" target ");
    //Serial.print(target);
    //Serial.print(" input ");
    //Serial.print(input);

    I_sum = I_sum + Ki * error;     // integrale?
    //saturation of I term
    //if (I_sum > maxV){
    //    I_sum = maxV;}
    //else if (I_sum < minV){
    //    I_sum = minV;}
    // reset integrator in case of not agree with prop
    //
    //if (I_sum * error < 0)
    //{
    //    I_sum = 0.;
    //}
    float derror = error - last_error;  // derivee
    last_error = error;
    float out = Kp * error + I_sum + Kd * derror / 0.02;  //0.04 = period du slave

    // check des bornes
    if (out > maxV)
    {                               // saturation haute
        out = maxV;
        I_sum = I_sum - Ki * error;
    }
    else if (out < minV)             // saturation basse
    {
        out = minV;
        I_sum = I_sum - Ki * error;
    }

    // retourne la commande a appliquer
    return out;
}

/** modif etats des PIDs
**/
void PID::set_pid_state(int state)
{
    pid_state = state;
}

/** Reinit PIDs
**/
void PID::reinit()
{
    pid_state = FAR;
    arrival_count = 0;
}


/** Actualisation des etats PIDS
**/
void PID::update_pid_state()
{
    float error = abs(last_error);
    switch(pid_state){

        // si on est loin, on passe en proche si l'erreur est ... near
        case FAR:
            if (error < near_error_value)
            {
                Serial.println("LAST ERROR");
                Serial.println(last_error);
                pid_state = NEAR;
            }
            break;

        // idem si proche
        case NEAR:
            if (error < done_error_value)
            {
                arrival_count += 1;
            }
            else
            {
                if (error > near_error_value)
                {
                    arrival_count = 0;
                }
            }
            if (arrival_count> 8)
            {
                pid_state = DONE;
            }
            break;
    }

}

/** Constructeur par default
**/
bool PID::check_if_over(int asserv_state)
{
    /* check if the pid is over or near ( for waypoints )
     *-> return true if pid_state is better than asserv_state
     * */
    update_pid_state();
    return pid_state != asserv_state;

}
/** limites? deja fait
**/
void PID::setOutputLimit(int max, int min){
    minV = min;
    maxV = max;
}


/** activation du mode auto
**/
void PID::turn_on(bool on_off, float input)
{
  inAuto = on_off;
  init(input);

}

/** reinit les PIDs
**/
void PID::init(float input)
{
    last_error = 0.;
    I_sum = 0.;
    reinit();
}

/** retourne l'objectif visee
**/
float PID::get_target()
    {
        return target;
    }


/** affiche les gains
**/
void PID::write_debug()
{
    Serial.println("KP, KI ,KV");
    Serial.print(Kp);
    Serial.print ( "  ");
    Serial.print(Ki);
    Serial.print ( "  ");
    Serial.println(Kd);

}
