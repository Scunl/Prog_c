#include <stdio.h>

int position(int tab[], int taille, int elt) {
    for (int i = 0; i < taille; i++) {
        if (elt == tab[i]) {
            return i;
        }
    }
    return -1;
}

int main(int argc, char const *argv[]) {
    int tab[] = {2, 7, 8, 9, 0};
    printf("%d", position(tab, 5, 9));
    return 0;
}
