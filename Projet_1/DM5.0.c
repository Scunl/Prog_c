#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>


#define TAILLE 100
#define TAILLE_P nbJoueurs

void Plateau(char plateau[]) {
    for (int i = 0; i < TAILLE; i++) {
        plateau[i] = '_';
        if (i % 9 == 0 && i < 92 && i != 0) {
            plateau[i] = 'O';
        }
        if (i == 53) {
            plateau[i] = 'T';
        }
        if (i == 8) {
            plateau[i] = 'R';
        }
        if (i == 74) {
            plateau[i] = 'P';
        }
        if (i == 31) {
            plateau[i] = 'H';
        }
        if (i == 65) {
            plateau[i] = 'L';
        }
        if (i == 94) {
            plateau[i] = 'X';
        }
    }
}

void collision(char plateau[], int positions[], int attente[], int nb_joueurs, int joueur_courant, int nouvelle_position) {
    bool collision = false;
    for (int i=0; i <= nb_joueurs; i++) {
        if (positions[joueur_courant] == positions[i] && i != joueur_courant) {
            printf("COLLISION\n");
            collision = true;
            if (collision) {
                if (plateau[positions[joueur_courant]] == 'R') {
                    positions[i] -= 8;
                } else if (plateau[positions[joueur_courant]] == 'T') {
                    attente[i] = 0;
                } else if (plateau[positions[joueur_courant]] == 'P') {
                    attente[i] = 0;
                    attente[joueur_courant] = 0;
                } else if (plateau[positions[joueur_courant]] == 'H') {
                    positions[i] = nouvelle_position;
                }
                else {
                    positions[i] = nouvelle_position;
                }
            }
        }
    }    
}

int avancerJoueur(char plateau[], int positions[], int attente[], int joueur_courant, int nb_joueurs, int des[2], int premier_tour) {
    int nouvelle_pos=0;
    if (attente[joueur_courant] == 0) {
        printf("\nTour du joueur %d\n", joueur_courant);
        positions[joueur_courant] += des[0] + des[1]; // Avancement du joueur si l'attente le permet

        if (positions[joueur_courant] == 99) {
            printf("Partie gagné!");
            return joueur_courant;
        }
        if (premier_tour == 0) {
            if ((des[0] == 3 && des[1] == 6) || (des[0] == 6 && des[1] == 3)) {
                positions[joueur_courant] = 40;
            }
            if ((des[0] == 4 && des[1] == 5) || (des[0] == 5 && des[1] == 4)){
                positions[joueur_courant] = 89;
            }
        }
        while ((positions[joueur_courant] % 9 == 0) && (premier_tour != 0)) {
            printf("OIE!\n");
            positions[joueur_courant] += des[0] + des[1];
        }
        if (positions[joueur_courant] == 53 || positions[joueur_courant] == 74) {
            attente[joueur_courant] = -1;
        }
        if (positions[joueur_courant] == 8) {
            printf("Raccourci!\n");
            positions[joueur_courant] = 16;
        }
        if (positions[joueur_courant] == 31) {
            printf("Hotel!\n");
            attente[joueur_courant] = 2;
            return -1;
        }
        if (positions[joueur_courant] == 65) {
            printf("Labyrinthe!\n");
            positions[joueur_courant] -= 13;
        }
        if (positions[joueur_courant] == 94) {
            printf("X Tête de mort! X\n");
            positions[joueur_courant] = 0;
        } 
    } else if (attente[joueur_courant] > 0 && positions[joueur_courant] == 31) {
            attente[joueur_courant]--;
            return -1; 
    }

    nouvelle_pos = positions[joueur_courant] - (des[0] + des[1]);
    printf("avant col:%d\n", positions[joueur_courant]);
    collision(plateau, positions, attente, nb_joueurs, joueur_courant, nouvelle_pos);
    printf("apres col:%d\n", positions[joueur_courant]);
    printf("PREMIER TOUR %d", premier_tour);
//    printf("joueur courant: %d\n", joueur_courant);
    return -1;
}

void conversion(int pos, int* x, int* y) {
    *x = pos % 10;          
    *y = pos / 10;      
}

int main() {

    int nbjoueurs;
    int joueur_courant = 1;
    int premier_tour = 0;
    int tours_joueurs = 0;
    int des[2];
    bool run = true;

    printf("Combien de joueurs ? (entre 2 et 4)\n");
    scanf("%d", &nbjoueurs);
    while (nbjoueurs < 2 || nbjoueurs > 4) {
        printf("Veuillez indiquer un nombre de joueurs compris entre 2 et 4!\n");
        scanf("%d", &nbjoueurs); // Saisie du nombre de joueurs
        return 0;
    }
    int positions[nbjoueurs];
    int attente[nbjoueurs];        
    char plateau[TAILLE];
    Plateau(plateau);
    for (int i=1; i<=nbjoueurs; i++) { // Initialisation des tableaux attente et positions
        attente[i] = 0;
        positions[i] = 0;
    }
    for (int i=1; i<=nbjoueurs; i++) { // Affichage du tableau attente
        printf("attente du joueur %d: %d\n", i, attente[i]);
    }
    printf("Pour chaque tour, indiquer les valeurs des deux dés ou taper 'q' pour quitter\n");
    while (run) {
        if (attente[joueur_courant] == 0) { 
            printf("\nJoueur %d:", joueur_courant);
            scanf("%d %d", &des[0], &des[1]);
        
            while ((des[0] > 6 || des[0] < 1) || (des[1] > 6 || des[1] < 1)) {
                printf("Valeurs de dés invalides. Veuillez réessayer!\n");
                scanf("%d %d", &des[0], &des[1]); 
            }
        }
        for (int i = 0; i < TAILLE; i++) { // Affichage du plateau
            if (i%10 == 0) {
                printf("\n");
            }
            printf("%c ", plateau[i]);
        }
        int res = avancerJoueur(plateau, positions, attente, joueur_courant, nbjoueurs, des, premier_tour);
        tours_joueurs++;
        if (tours_joueurs > 1) {
            premier_tour = 1;
        }
        if (res == 0) {
            return 1;  
        }
        for (int i=1; i <= nbjoueurs; i++) {
            printf("attente du joueur %d: %d\n", i, attente[i]);   // Affichage de positions des joueurs
            printf("position du joueur %d: %d\n", i, positions[i]);   // Affichage de positions des joueurs
        }
        if (joueur_courant < nbjoueurs) {   // Opération de changement du joueur courant
            joueur_courant++;
        } else {
            joueur_courant = 1;
        }
    
    }
    
    return 0;
}
