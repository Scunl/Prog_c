
#include <stdio.h>

int puissance(int n, int p) {
    int temp = n;
    for (int i = 0; i < p - 1; i++) {
        n *= temp;
    }
    return n;
}

int diviseur(int entier) {
    if (entier <= 0) {
        return -1;
    }

    return 0;
}

/*
/\_
|_|
*/

int max_tab(int tab[], int size) {
    if (size <= 0) {
        return -1;
    }
    int tmp = 0;
    for (int i = 0; i < size; i++) {
        if (tmp < tab[i]) {
            tmp = tab[i];
        }
    }
    return tmp;
}

int est_partie_triee(int *tab) {
    for (int i = 1; i < 18; i++) {
        if (tab[i] < tab[i - 1]) {
            return 0;
        }
    }
    return 1;
}

int position(int tab[], int taille, int elt) {
    for (int i = 0; i < taille; i++) {
        if (tab[i] == elt) {
            return i;
        }
    }
    return -1;
}

int are_equal_tab(int *tab, int *tab2, int size) {
    for (int i = 0; i < size; i++) {
        if (tab[i] != tab2[i]) {
            return 0;
        }
    }
    return 1;
}

float mean_positive(int *array, int size) {
    float somme = 0;
    int cpt = 1;
    for (int i = 0; i < size; i++) {
        if (array[i] >= 0) {
            cpt += 1;
            somme += array[i];
        }
    }
    if (somme == 0) {
        return 0;
    }
    return somme / cpt;
}

void miroir(int *tab, int size) {
    int tmp;
    for (int i = 0; i < size; i++) {
        tab[i] = tab[size - i];
    }
}

int main(int argc, char *argv[]) {
    int array[4] = {1, -1, 0, 0};
    printf("%f", mean_positive(array, 4));
    return 0;
}
