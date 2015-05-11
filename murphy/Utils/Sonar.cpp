#include "Sonar.h"

Sonar::Sonar(int pin_, Coord dir_):
    pin(pin_),
    dir(dir_),
    on(true)
{
    // constructeur
}


float Sonar::get_dist(){
    int sensorValue = analogRead(pin);

    if (sensorValue == 0)
    {
        Serial.println("warning check sonar connection");
    }
    return 90.442 + (float)sensorValue /1.0 *0.82383 ; //divide by max sensor value, multiply by 900 mm
}

#define DISTANCE_DETECTION 300
bool Sonar::adv_detected(Coord pos_robot){
    if (!on)
    {
        return false;
    }
    float d = get_dist();
    if (d > 10.0 && d < DISTANCE_DETECTION)
    {
        /*
        adv = Coord(dir);
        adv.forward_translation(d) ;
        adv = Coord(
            pos_robot.get_x() + adv.get_x() * cos(pos_robot.get_cap()) + adv.get_y() * sin(pos_robot.get_cap()),
            pos_robot.get_y() + adv.get_y() * cos(pos_robot.get_cap()) + adv.get_x() * sin(pos_robot.get_cap()),
            pos_robot.get_cap());
            */
        adv = Coord(
            pos_robot.get_x() + (dir.get_x() + d)*cos(pos_robot.get_cap()) - (dir.get_y())*sin(pos_robot.get_cap()),
            pos_robot.get_y() + (dir.get_x() + d)*sin(pos_robot.get_cap()) + (dir.get_y())*cos(pos_robot.get_cap()),
            pos_robot.get_cap());

        Serial.print(" adversaire (COORD) : ");
        adv.write_serial();

        return adv.is_on_map();
    }
    return false;
}

void Sonar::turn_on(){
    on = true;
}

void Sonar::turn_off(){
    on = false;
}

void Sonar::write_debug(){
    Serial.print(" analog : ");
    Serial.print(analogRead(pin));
    Serial.print("\tdistance : ");
    Serial.println(get_dist());
    adv_detected(Coord(0,0,0));
}

void Sonar::write_adv_coord(){
    Serial.print("* ADVD ");
    adv.write_serial();
    Serial.println("# ADVD");
}

bool Sonar::mean_adv(Coord adv_){
   adv.barycentre(adv_, 0.5);
}

Coord Sonar::get_adv(){
    return adv;
}

