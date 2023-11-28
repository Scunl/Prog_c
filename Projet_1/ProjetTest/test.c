#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAILLE_MAX 100
#define MAX 50

void chargement() {
    int nbjoueurs;
    int joueur_courant = 1;
    int premier_tour = 0;
    int tours_joueurs = 0;
    int des0;
    int des1;
    FILE *fichier;
    bool run = true;
    fichier = fopen("sauvegarde.jo", "r");
    char str[MAX];
    int a;
    int des[10];
    int reponse[80][2];
    des[0] = 0;
    des[1] = 0;
    if (strcmp(fgets(str, TAILLE_MAX, fichier), "JO")) {
        printf("C'est bien un fichier de type 'JO'\n");
        a = fgetc(fichier);
        nbjoueurs = a;
        while ((a = fgetc(fichier)) != EOF) {
            des[0] = 0;
            des[1] = 0;
            for (int i = 0; i <= 2; i++) {
                while ((a = fgetc(fichier)) != EOF) {
                    if (a != '\n' && a != ' ') {
                        a = a - '0';
                        des[i] = a;
                        printf("%d et %d\n", des[0], des[1]);
                    }
                }
            }
        }
        des[0] = 0;
        des[1] = 0;
    }
}

int main(int argc, char const *argv[]) {
    chargement();
}