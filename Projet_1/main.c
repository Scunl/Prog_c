#include <stdio.h>
#include <stdlib.h>

int lancer_des() {
    /*retourne un entier compris entre [2, 12]*/
    int nombre;
    nombre = rand() % 6;
    nombre += rand() % 6;
    return nombre;
}

int avanceJoueur(char plateau[], int positions[], int attente[],
                 int joueur_courant, int nb_joueurs, int des[2],
                 int premier_tour) {
    int resultat_des;
    if (positions[99] == joueur_courant) {
        return joueur_courant
    } else {
        return -1
    }
    for (int i = 0, i < nb_joueur) {
        if (attente[i] == 0) {
            resultat_des = lancer_des()
        }
    }
}