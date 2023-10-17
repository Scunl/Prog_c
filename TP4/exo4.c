#include <stdio.h>

void somme(int tab[], int tab2[], int s[], int taille) {
    for (int i = 0; i < taille; i++) {
        s[i] = tab[i] + tab2[i];
    }
}

int main(int argc, char const *argv[]) {
    int tab[] = {1, 2, 3, 4, 5};
    int tab2[] = {1, 2, 3, 4, 5};
    int s[];
    somme(tab, tab2, s, 5);
    return 0;
}
