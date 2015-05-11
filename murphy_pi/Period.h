#ifndef PERIOD_H
#define PERIOD_H

#include <ctime>
#include <wiringPi.h>

class Period
{
    public:
        Period(int period_);
        bool is_over();
        void reset();
        void set_periode(int period_);
        long time_elapsed();
    private:
        long period;
        long time_last_reset;
        long t;

};


#endif
