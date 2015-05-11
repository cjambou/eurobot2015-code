#ifndef PROTOCOLE_COM_H
#define PROTOCOLE_COM_H

#include <string>
#include <iostream>
#include <sstream>
#include "Period.h"
#include "Master.h"
#include <wiringSerial.h>

#define PERIODE_COM 50

class Protocole_COM
{
    public:
        Protocole_COM(Master* master_ );
        void run();
        void treatSerial();
        void executeinstr();

    private:
        Period period;
        int serial_count;
        std::string s;
        bool treated;
        std::istringstream stream;
        Master* master;
};

#endif // PROTOCOLE_COM_H
