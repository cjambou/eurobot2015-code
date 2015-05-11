#include "Period.h"

Period::Period(int period_):period(period_)
{
    reset();
}


void Period::reset()
{
    time_last_reset = millis();
}

long Period::time_remaining()
{
    if(is_over())
    {
        return 0;
    }
    else
    {
        long t = millis();
        return (period - t - time_last_reset);
    }
}

bool Period::is_over(){
    long t = millis();
    if (t - time_last_reset > period){
    return true;
    }
    else
    {
    return false;
    }

}


void Period::set_periode(int period_){
    period = period_;
}
