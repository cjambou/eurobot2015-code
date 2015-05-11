# Eurobot-2015

code Iron menad de la coupe de france de robotique 2015 
contient :
- le code bas niveau (arduino)
- le code master (Raspberry PI)

## convention commune:

   COULEUR_JAUNE 0
   COULEUR_VERT  1
    
 bumper strat
 coop'r -> haut couleur (haut 1 vert , bas 0 jaune)
        -> bas strat 1  (haut 1      , bas 0      )

Murph'  ->


to do
dossier include a mettre dans les includes du compilateur arduino (ici codeblocks) 
procedure de travail pi <-> repository wifi


# ORDRE COOP'R

a taper dans le terminal serie

## Tapis (T)
-----------------------------

    T0 -> deployement tapis 1
    T1 -> replis intermediaire
    T2 -> deployement tapis 2
    T3 -> replis tapis 2

## Chaine secondaire
-----------------------------

    S0 -> desactivation de la chaine
    S1 -> activation de la chaine
    S2 -> position rangée
    S3 -> position mi-hauteur
    S4 -> position basse (attaque ou pompe)


## Chaine Principale (asserv base roulante)
-----------------------------

    A0 -> deplacement avant   (+ temps d'excecution en ms) s'arrette si bump ou evitement activé, need reprise
    A1 -> deplacement arriere (+ temps d'excecution en ms)
    A2 -> deplacement droite (+ temps d'excecution en ms)
    A3 -> deplacement gauche (+ temps d'excecution en ms)
    A4 -> pause asserv
    A5 -> reprise asserv (+ 1s pour compenser la perte de vitesse)
    A6 -> recalage avant 
    A7 -> recalage gauche
    A8 -> recalae droite

## DEBUG
-----------------------------

    D0 -> IMU bavard
    D1 -> IMU muet
    D2 -> SONAR bavard
    D3 -> SONAR muet
    D4 -> 


rotation? asserv sur IMU



# ORDRE MURPHY

ordre a taper dans le terminal serie



## Camera (I->image)
------------------------------
  
    I0 -> position devant
    I1 -> position basse


## Claps (C)
------------------------------

    C0 -> ouverture clap droit
    C1 -> fermeture clap droit
    C2 -> ouverture clap gauche
    C3 -> fermeture clap gauche


## Balle
------------------------------

    B0 -> chargement balle gauche
    B1 -> drop balle gauche
    B2 -> attrape balle droite (par terre)
    B3 -> drop balle droite
    B4 -> Debug (affiche etat courant de la MAE balle droite)


## POP-CORN
------------------------------

    P0 -> aspiration, allumage
    P1 -> aspiration, extinction
    P2 -> capot arriere, ouveture
    P3 -> capot arriere, fermeture


## DEBUG (principalement slave)
------------------------------

    O0 -> reinit compteur odo propu
    O1 -> affiche les tics, et distances parcourues


## CONSTRUCTEUR PILE 
------------------------------ 

    G -> pile gauche
    D -> pile droite
    G0 -> prepare la prise de stand (ouverture pinces)
    G1 -> saisie forcee
    G2 -> range les pinces si sorties
    G3 -> force l'etat de transition AssFini
    G4 -> prepare la pose de la pile
    G5 -> pose la pile
    G6 -> replis des modules de pose


## SLAVE (base roulante)
------------------------------

    S0 -> set X Y CAP
    S1 -> get X Y CAP
    S2 -> recalage
    S3 -> BF_cap >> angle en absolu degre
    S4 -> BF_avance 
    S5 -> BF_droite
    S6 -> BF_cercle
    S7 -> set speed (0:slow, 1:medium, 2:fast)
    S8 -> set gain PIDs (type Kp Kv Ki) type: 1 deplacement, 0 rotation  
    S9 -> stop asserv (moteur)


## EVITEMENT (base roulante)
------------------------------

    E0 -> Desactivation evitement
    E1 -> Activation evitement
    E2 -> Debug sonar


