/** PROGRAMME PI COOP R
mise a jour du dossier git
~/.git/Eurobot_2015/
git pull
git commit -a si changement local
git push
execution du script
~/.git/Eurobot_2015/COOP_R__MASTER_PI/bin/Debug/COOP_R__MASTER_PI

*/

#include <iostream>

#include <wiringPi.h>
#include <wiringSerial.h>

#include <unistd.h>

#include "Master.h"
#include "Protocole_COM.h"

// pour la com série
#define SERIAL_DEV "/dev/ttyACM0"
#define SPEED 9600


#include "Period.h"
#include "util.h"

#define VERBOSE_STATE_MACHINE 1

using namespace std;

Master* master;
Protocole_COM* protocole_com;


/** EXECUTION DU PROGRAMME PRINCIPALE (IA)
*/
int main()
{
    cout << "[MASTER_COOP'R] lancement du programme" << endl;

    /** CONNEXION SERIAL ARDUINO
    */
    int portSerie;
    portSerie = serialOpen(SERIAL_DEV, SPEED) ;
    if(portSerie >-1)
    {
        cout << "[SERIAL] Connection success -> "<<portSerie << endl;
        serialFlush(portSerie);
        cout << "[SERIAL] flush(netoyage) -> "<<portSerie << endl;
    }
    else{
        cout << "[SERIAL] Connection failed -> "<<portSerie << endl;
    }

    // boucle de jeu
    cout << "[MASTER_COOP'R] boucle de jeu" << endl;

    // initialisation du Master
    cout << "[MASTER_COOP'R] INITIALISATION DU MASTER" << endl;
    //Master* master;
    master = new Master(portSerie);

    // initialisation du protocole de COM
    cout << "[MASTER_COOP'R] INITIALISATION DU MASTER" << endl;
    protocole_com = new Protocole_COM(master);



    cout<<"________________________________________"<<endl;
    cout << "[MASTER_COOP'R] boucle de jeu" << endl;
    cout<<"________________________________________"<<endl;

    while(1)
    {
         master->run();
        protocole_com->run();
        delay(1);
    }

    return 0;
}



