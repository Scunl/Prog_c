#include <stdio.h>

typedef struct cellule {
    int valeur;
    struct cellule *suivant;
} Cellule;

typedef Cellule *Liste;

int compte(Liste l) {
    int cmp = 0;
    while (l != NULL) {
        cmp += 1;
        l = l->suivant;
    }
    return cmp;
}

Liste recherche(Liste l, int val) {
    for (int i = 0; i < compte(l); i++) {
        if (val == l->valeur)
            return l;
        else
            l = l->suivant;
    }
    return NULL;
}
Cellule *recherche_min(Liste l) {
    if (l == NULL)
        return NULL;
    Cellule *min = l;
    while (l != NULL) {
        if (l->valeur < min->valeur)
            min = l;
        l = l->suivant;
    }
    return min;
}

int nb_different(Liste l) {
    int nb = 0;
    while (l != NULL) {
        if (recherche(l->suivant, l->valeur) == NULL)
            nb += 1;
        l = l->suivant;
    }
    return nb;
}

int esTrie(Liste l) {
    while (l != NULL && l->suivant->valeur) {
        if (l->valeur > l->suivant->valeur)
            return 0;
        l = l->suivant;
    }
    return 1;
}

int main(void) {
    return 0;
}
