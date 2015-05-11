#ifndef _ORDERSRASPBERRY_H
#define _ORDERSRASPBERRY_H


#include <Arduino.h>
#include "IO.h"
#include "Utils/Period.h"

#include <iterator> // ne pas mettre apres sinon ca compile pas
#include <string>
#include <iostream>
#include <sstream>

class OrdersRaspberry {

	public:
        OrdersRaspberry(IO* io_);
        void run();
        void treatSerial();
        void execute();
        void executeinstr();

	private:
        Period period;
        int serial_count;
        std::string s;
        bool treated;
        std::istringstream stream;
    IO* io;
};
#endif
