#ifndef ELEMENT_ROBOT_H
#define ELEMENT_ROBOT_H


class Element_Robot
{
    private:
        // pour les trategies
        int pile_gauche;
        int pile_droite;
        bool gobelet;
        bool pop_corn;
        bool balle;

    public:
        Element_Robot();

        int pile_gauche_nbr();
        void pile_gauche_incr();
        void pile_gauche_reset();

        int pile_droite_nbr();
        void pile_droite_incr();
        void pile_droite_reset();

        void gobelet_saisie();
        void gobelet_relache();
        bool gobelet_present();

        void pop_corn_aspire();
        void pop_corn_decharge();
        bool pop_corn_present();

        void balle_catch();
        bool balle_presente();
};

#endif // ELEMENT_ROBOT_H
