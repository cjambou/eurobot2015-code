#include "Protocole_COM.h"

//int portSerie;

/** Constructeur COM
*/
Protocole_COM::Protocole_COM(Master* master_ ):
    period(PERIODE_COM),
    master(master_),
    serial_count(0)
{
    treated = true;
    cout << "[COM] initialisation" << endl;
    //master->set_couleur(COULEUR_VERT);

}


/**
 RUN COM
*/
void Protocole_COM::run()
{
    if(period.is_over())
    {
        period.reset();
        treatSerial();

        if ( !treated)
        {
            //Serial.println("message traite");
            //cout << "[COM] message traitée" << endl;
            executeinstr();
            treated = true;
            stream.str("");
            serial_count = 0;
            s="";
        }
    }

}


/**
 Traitement du signal COM
*/
void Protocole_COM::treatSerial()
{
    char serial_char;

    // Ici on traite les différents messages reçus.
    while(serialDataAvail(master->getPortSerie())>0 && serial_count < 228)
    {
        serial_char= serialGetchar(master->getPortSerie());

        if (serial_char =='\n')
        {
            //cout<<"Fin de ligne"<<endl;
            //on ne traite que les instructions de minimum 2 char
            if (serial_count<1)
            {
                treated = true;
            }
            else
            {
                treated = false;
            }
             //cout<<"Enregistre : "<<s.c_str()<<endl;
             //cout<<"serial_count :"<<serial_count<<endl;
            return;
        }
        //Serial.println(serial_count);
        s = s + serial_char;
        serial_count = serial_count + 1;
    }

}




/*
 Execution des instructions OrdersRaspberry
*/
void Protocole_COM::executeinstr()
{
    //char ordre = cmdBuffer[bufindr][strchr_pointer];
    stream.str(s);
    std::string temp;
    stream>>temp;
    char ordre = s[0];
    cout<<"[arduino] "<<s<<endl;

    if(ordre == '#' || ordre == '*')
    {
        cout<<"appel arduino found : ";
        if(ordre == '#')
        {
            cout<<"ordre asserv/action"<<endl;
        }
        if (ordre == '*')
        {
            cout<<"ordre strat"<<endl;
        }
    }
    else
    {
        // on sort, et on affiche la ligne
        return;
    }

    //cout << "[COM] ordre ind = " << endl;
    //int ind = ((int)temp[1]) - 48;      // pour avoir le numero de l'ordre
    //cout <<ordre<< "@" <<ind<< endl;

    switch (ordre)
    {

    /** ordre de type adversaire et truc fini
    */
	case '#' :

        // start mis
        if(s.find("START IN") != string::npos)
        {
            cout<<"[Master] start mis"<<endl;
        }

        //start retiré
        if(s.find("START OUT") != string::npos)
        {
            cout<<"[Master] start enleve"<<endl;
            master->get_MAE_COOP_R()->stratEnleve();
        }

        //fin des 90s
        if(s.find("ENDDAME") != string::npos)
        {
            cout<<"[Master] end of game"<<endl;
            //master->get_MAE_COOP_R()->stratEnleve();
        }



        // check si adversaire detecté
        if(s.find("PAUSE") != string::npos)
        {
            cout<<"[Master] adversaire detectee, pause"<<endl;
            master->get_MAE_COOP_R()->adversaire();
        }

        // check si l'asserv est fini
        if(s.find("ASSFINI") != string::npos)
        {
            cout<<"[Master] assfini"<<endl;
            master->get_MAE_COOP_R()->assFini();
        }


        // pour les tours de roues?
        if(s.find("TOUR") != string::npos)
        {
            int tour = ((int)s[7]) - 48;
            cout<<"[Master] tour de roue laterale"<<endl;
            cout<<"tour de roue casted : "<<tour<<endl;
            master->tour_roue_set(tour);
            cout<<"tour de roue master : "<<master->get_tour_roue()<<endl;
        }

        // pour les pose de tapis?
        if(s.find("POSE TAPIS 1 POSEE") != string::npos)
        {
            cout<<"[Master] tapis 1 posé"<<endl;
            master->get_MAE_COOP_R()->ioFini();     // faire plus mieu, étayé
        }

        // pour les pose de tapis?
        if(s.find("POSE TAPIS 1 REMONTEE") != string::npos)
        {
            cout<<"[Master] tapis 1 remonté"<<endl;
            master->get_MAE_COOP_R()->ioFini();     // faire plus mieu, étayé
        }

        // pour les pose de tapis?
        if(s.find("POSE TAPIS 2 POSEE") != string::npos)
        {
            cout<<"[Master] tapis 2 posé"<<endl;
            master->get_MAE_COOP_R()->ioFini();     // faire plus mieu, étayé
        }

        // pour les pose de tapis?
        if(s.find("POSE TAPIS 2 REMONTEE") != string::npos)
        {
            cout<<"[Master] tapis 2 remonté"<<endl;
            master->get_MAE_COOP_R()->ioFini();     // faire plus mieu, étayé
        }
        break;


    /** ordre de strat
    */
	case '*' :

        // si jaune
        if(s.find("COULEUR : 0") != string::npos)
        {
            cout<<"[Master] couleur 0"<<endl;
            master->set_couleur(COULEUR_JAUNE);
        }

        //si vert
        if(s.find("COULEUR : 1") != string::npos)
        {
            cout<<"[Master] couleur 1"<<endl;
            master->set_couleur(COULEUR_VERT);
        }

        // si attente
        if(s.find("STRAT 1 : 0") != string::npos)
        {
            cout<<"[Master] attente"<<endl;
            master->desactivation_rush();
        }

        //si vert
        if(s.find("STRAT 1 : 1") != string::npos)
        {
            cout<<"[Master] rush"<<endl;
            master->activation_rush();
        }

        break;


    }

}




