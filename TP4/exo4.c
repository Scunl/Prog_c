#include <stdio.h>
#define TAILLE 5

void somme(int tab[][TAILLE], int result[]) {
    for (int l = 0; l < TAILLE; l++) {
        result[l] = 0;
    }

    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            result[i] += tab[i][j];
        }
    }
}

int main(int argc, char const *argv[]) {
    return 0;
}