#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initAlea(int tab[], int taille, int max) {
    srand(time(NULL));
    for (int i = 0; i < taille; i++) {
        tab[i] = rand() % max;
    }
}

int main(int argc, char const *argv[]) {
    srand(time(NULL));
    for (int i = 0; i < 20; i++) {
        printf("%d\n", rand());
    }
    return 0;
}
