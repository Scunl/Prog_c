#include <stdio.h>
#include <stdlib.h>
#define TAILLE_MAX 1000

int compteCaracteres(namefile) {
    return 0;
}

#define TAILLE_MAX 1000

int main(int argc, char *argv[]) {
    FILE *fichier = NULL;
    char chaine[TAILLE_MAX] = "";

    fichier = fopen("test.txt", "r");

    if (fichier != NULL) {
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL) {
            printf("%s", chaine);
        }

        fclose(fichier);
    }

    return 0;
}
