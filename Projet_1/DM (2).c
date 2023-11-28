#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAILLE 100
#define TAILLE_P nbJoueurs

void Plateau(char plateau[]) {
    for (int i = 0; i < TAILLE; i++) {
        plateau[i] = '_';
        if (i % 9 == 0 && i <= 90 && i != 0) {
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

int collision(char plateau[], int positions[], int attente[], int nb_joueurs,
              int joueur_courant, int nouvelle_position) {
    bool collision = false;
    for (int i = 0; i <= nb_joueurs; i++) {
        if (positions[joueur_courant] == positions[i] && i != joueur_courant) {
            printf("COLLISION\n");
            collision = true;
            if (collision) {
                if (plateau[positions[joueur_courant]] == 'R') {        //
                    positions[i] -= 8;                                  //
                } else if (plateau[positions[joueur_courant]] == 'T') { //
                    attente[i] = 0;                                     //
                } else if (plateau[positions[joueur_courant]] == 'P') { //
                    attente[i] = 0; //  Gestion des différents cas de collision
                                    //  sur les cases spéciales.
                    attente[joueur_courant] = 0;                        //
                } else if (plateau[positions[joueur_courant]] == 'H') { //
                    positions[i] = nouvelle_position;                   //
                } else {                                                //
                    positions[i] = nouvelle_position;                   //
                }
            }
        }
    }
    return collision;
}

int avancerJoueur(char plateau[], int positions[], int attente[],
                  int joueur_courant, int nb_joueurs, int des[2],
                  int premier_tour) {
    int nouvelle_pos = 0;
    if (attente[joueur_courant] == 0) {
        printf("\nTour du joueur %d\n", joueur_courant);
        positions[joueur_courant] += des[0] + des[1]; // Avancement du joueur
        if (positions[joueur_courant] + des[0] + des[1] > 99) { //
            int diff = positions[joueur_courant] -
                       99; // Gestion du cas où le joueur dépasse 99
            positions[joueur_courant] = 99 - diff; //
        }
        if (positions[joueur_courant] == 99) {
            printf("Partie gagné!\n");
            return joueur_courant;
        }
        if (premier_tour == 0) {
            if ((des[0] == 3 && des[1] == 6) || (des[0] == 6 && des[1] == 3)) {
                positions[joueur_courant] = 40;
            }
            if ((des[0] == 4 && des[1] == 5) || (des[0] == 5 && des[1] == 4)) {
                positions[joueur_courant] = 89;
            }
        }

        if ((positions[joueur_courant] % 9 == 0) && (premier_tour != 0)) {
            printf("Oie!\n");
            positions[joueur_courant] += des[0] + des[1];
        }

        if (positions[joueur_courant] == 53 ||
            positions[joueur_courant] == 74) {
            if (positions[joueur_courant] == 53) {
                printf("Joueur %d est tombé dans le trou!\n", joueur_courant);
            }
            attente[joueur_courant] = -1;
        }
        if (nb_joueurs == 2) {
            if ((positions[1] == 53 && positions[2] == 74) ||
                (positions[1] == 74 &&
                 positions[2] ==
                     53)) { // Gestion du cas où les joueurs sont bloqués
                printf("Jeu bloqué!\n");
                return joueur_courant;
            }
        }
        if (positions[joueur_courant] == 8) {
            printf("Raccourci!\n");
            positions[joueur_courant] = 16;
        }
        if (positions[joueur_courant] == 31) {
            nouvelle_pos = positions[joueur_courant] - (des[0] + des[1]);
            printf("Hotel! Joueur %d passe 2 tours\n", joueur_courant);
            attente[joueur_courant] = 2;
            if (collision(plateau, positions, attente, nb_joueurs,
                          joueur_courant,
                          nouvelle_pos)) { // Gestion du cas de collision sur la
                                           // case hôtel
                attente[joueur_courant] = 0;
            }
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
    } else if (attente[joueur_courant] > 0 && positions[joueur_courant] <= 31) {
        attente[joueur_courant]--; // Gestion du cas lorsqu'un joueur est sur la
                                   // case hôtel
        return -1;
    }

    nouvelle_pos = positions[joueur_courant] - (des[0] + des[1]);
    collision(plateau, positions, attente, nb_joueurs, joueur_courant,
              nouvelle_pos);
    return -1;
}

void conversion(int pos, int *x, int *y) {
    int n = 0;
    int span = 10;
    while (pos > span) { // Conversion de la position d'un joueur pour les
                         // représenter sur un plateau en spirale
        pos -= span;
        n += 1;
        span -= n % 2;
    }
    int d = n / 4;
    int cote = n % 4;
    int c = 10 - 1 - d;
    int x_tab[4] = {d, d + pos + 1, c, c - pos - 1};
    int y_tab[4] = {d + pos, c, c - pos - 1, d};

    *x = x_tab[cote];
    *y = y_tab[cote];
}

void afficherPlateau(char plateau[], int positions[], int nb_joueurs) {
    int size = TAILLE / 10;
    int tab[size][size];
    int N = size - 1;
    int num = 0;
    int i = 0;
    int j = 0;

    for (i = 0; i < size / 2; i++, N--) { // Construction du plateau

        // gauche à droite
        for (j = i; j <= N; j++, num++) {
            tab[i][j] = num;
        }
        // de haut en bas
        for (j = i + 1; j <= N; j++, num++) {
            tab[j][N] = num;
        }
        // droite à gauche
        for (j = N - 1; j >= i; j--, num++) {
            tab[N][j] = num;
        }
        // de bas en haut
        for (j = N - 1; j > i; j--, num++) {
            tab[j][i] = num;
        }
    }
    for (i = 0; i < size; ++i) {
        for (j = 0; j < size; ++j) {
            tab[i][j] = '_';
        }
    }

    // Ajout des lettres pour les cases spéciales
    tab[8][5] = 'T';
    tab[0][8] = 'R';
    tab[7][7] = 'P';
    tab[5][0] = 'H';
    tab[2][3] = 'L';
    tab[5][3] = 'X';

    for (i = 1; i <= nb_joueurs; ++i) { // Placement des joueurs sur le plateau
        int position = positions[i];
        int x = position % size;
        int y = position / size;
        conversion(position, &x, &y); // Utilisation de la fonction conversion
        tab[x][y] = i + '0';
    }

    // Affichage du plateau
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("| %c ", tab[i][j]);
        }
        printf("|\n");
    }
}

typedef struct {
    int nombre_joueurs;
    int nombre_simulations;
    int seed;
} JeuDeLoieParams;

void simulation(JeuDeLoieParams params) {

    int min = TAILLE;
    int max = 0;
    int bloque = 0;
    double somme = 0.0;

    printf("Simulations: %d à %d joueurs, graine = %d\n",
           params.nombre_simulations, params.nombre_joueurs, params.seed);
    srand(params.seed);

    for (int i = 0; i < params.nombre_simulations;
         i++) { // Itération sur le nombre de simulations
        int tours = 0;
        int joueur_courant = 1;
        int positions[params.nombre_joueurs];
        int attente[params.nombre_joueurs];
        char plateau[TAILLE];

        Plateau(plateau);
        for (int j = 1; j <= params.nombre_joueurs; j++) {
            attente[j] = 0;
            positions[j] = 0;
        }

        while (true) {
            int des[2] = {rand() % 6 + 1,
                          rand() % 6 + 1}; // dés aléatoires pour la simulation
            int res =
                avancerJoueur(plateau, positions, attente, joueur_courant,
                              params.nombre_joueurs, des, tours == 0 ? 0 : 1);
            if (res == joueur_courant || res == 0 ||
                positions[joueur_courant] >= TAILLE - 1) {
                break;
            }
            if (params.nombre_joueurs == 2) { //
                if (attente[1] == -1 &&
                    attente[2] == -1) { //  Tour où les joueurs sont bloqués
                    bloque++;           //
                }
            }
            tours++;
            joueur_courant = (joueur_courant % params.nombre_joueurs) + 1;
        }
        if (tours < min) {
            min = tours;
        }
        if (tours > max) {
            max = tours;
        }
        somme += tours;
    }
    double moyenne = somme / params.nombre_simulations;
    printf("Nombre de tours minimum = %d\n", min);
    printf("Nombre de tours maximum = %d\n", max);
    printf("Nombre de tours moyen = %.3lf\n", moyenne);
    printf("Nombre de tours ou le jeu est bloqué = %d\n", bloque);
}

int main(int argc, char *argv[]) {

    int nbjoueurs;
    int joueur_courant = 1;
    int premier_tour = 0;
    int tours_joueurs = 0;
    int des[2];
    FILE *fichier;
    bool run = true;
    JeuDeLoieParams jeuParams;
    jeuParams.seed = time(NULL);
    if (argc > 1 &&) {                                 //
        if (strcmp(argv[1], "-W") == 0 && argc >= 4) { //
            sscanf(argv[2], "%d",
                   &jeuParams.nombre_joueurs); // Lecture des arguments si l'on
                                               // veut simuler
            sscanf(argv[3], "%d", &jeuParams.nombre_simulations); //
            sscanf(argv[5], "%d", &jeuParams.seed);               //
        }
        simulation(jeuParams);
    } else {
        fichier = fopen("sauvegarde.jo", "w");

        printf("Combien de joueurs ? (entre 2 et 4)\n");
        scanf("%d", &nbjoueurs);
        while (nbjoueurs < 2 || nbjoueurs > 4) {
            printf("Veuillez indiquer un nombre de joueurs compris entre 2 et "
                   "4!\n");
            scanf("%d", &nbjoueurs); // Saisie du nombre de joueurs
        }
        fprintf(
            fichier, "JO\n%d\n",
            nbjoueurs); // Ecriture du nombre nombre de joueurs dans le fichier

        int positions[nbjoueurs];
        int attente[nbjoueurs];
        char plateau[TAILLE];
        Plateau(plateau);
        for (int i = 1; i <= nbjoueurs;
             i++) { // Initialisation des tableaux attente et positions
            attente[i] = 0;
            positions[i] = 0;
        }
        for (int i = 1; i <= nbjoueurs; i++) { // Affichage du tableau attente
            printf("attente du joueur %d: %d\n", i, attente[i]);
        }
        afficherPlateau(plateau, positions, nbjoueurs);
        printf("Pour chaque tour, indiquer les valeurs des deux dés ou taper "
               "'q' pour quitter\n");
        while (run) {
            if (attente[joueur_courant] == 0) {
                printf("\nJoueur %d:", joueur_courant);
                if (scanf("%d", &des[0]) == 0) {
                    char input;
                    scanf(" %c", &input); // Lire le caractère suivant
                    if (input == 'q') {
                        fclose(fichier);
                        printf("Arrêt\n");
                        run = false; // Arrêt du jeu
                        break;
                    } else {
                        printf("Saisie invalide, veuillez réessayer!\n");
                        continue;
                    }
                }
                if (scanf("%d", &des[1]) == 0) {
                    char input;
                    scanf(" %c", &input); // Lire le caractère suivant
                    if (input == 'q') {
                        fclose(fichier);
                        printf("Arrêt\n");
                        run = false; // Arrêt du jeu
                        break;
                    } else {
                        printf("Saisie invalide, veuillez réessayer!\n");
                        continue;
                    }
                }
                while ((des[0] > 6 || des[0] < 1) ||
                       (des[1] > 6 || des[1] < 1)) {
                    printf("Valeurs de dés invalides. Veuillez réessayer!\n");
                    scanf("%d %d", &des[0], &des[1]);
                }
            }
            fprintf(fichier, "%d %d\n", des[0],
                    des[1]); // Ecriture des dés dans le fichier
            tours_joueurs++;
            if (tours_joueurs > nbjoueurs) {
                premier_tour = 1;
            }
            int res = avancerJoueur(plateau, positions, attente, joueur_courant,
                                    nbjoueurs, des, premier_tour);
            if (res == 0) {
                return 1;
            } else if (res == joueur_courant) { // Arrêt du jeu si victoire
                run = false;
            }
            int x = 0;
            int y = 0;
            for (int i = 1; i <= nbjoueurs; i++) {
                printf("attente du joueur %d: %d\n", i,
                       attente[i]); // Affichage de positions des joueurs
                printf("Joueur %d: %d\n", i,
                       positions[i]); // Affichage de positions des joueurs
                printf("premier tour: %d", premier_tour);
                conversion(positions[i], &x, &y);
                printf("Coordonnées du joueur %d: x = %d, y = %d\n", i, x, y);
            }
            afficherPlateau(plateau, positions, nbjoueurs);
            if (joueur_courant <
                nbjoueurs) { // Opération de changement du joueur courant
                joueur_courant++;
            } else {
                joueur_courant = 1;
            }
        }
    }

    return 0;
}