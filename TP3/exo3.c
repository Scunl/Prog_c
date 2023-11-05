#include <stdio.h>

void afficheTab(int tab[], int taille) {
    for (int i = 0; i < taille; i++) {
        printf("- %d\n", tab[i]);
    }
}

void changeTab(int tab[], int taille, int indice) {
    tab[indice] += 2;
}

int main(int argc, char const *argv[]) {
    int tab[] = {1, 2, 3, 4, 5, 0};
    afficheTab(tab, 5);
    changeTab(tab, 5, 2);
    return 0;
}
