#include <stdio.h>

typedef struct cellule {
    int valeur;
    struct cellule *suivant;
} Cellule;

typedef Cellule *Liste;

Liste alloueCellule(int x) {
    Cellule *cell = (Cellule *)malloc(sizeof(Cellule));
    if (cell != NULL) {
        cell->valeur = x;
        cell->suivant = NULL;
    }
    return cell;
}

Cellule *extraitTete(Liste *al) {
    if (*al == NULL)
        return NULL;
    Cellule *tmp = *al;
    *al = tmp->suivant;
    tmp->suivant = NULL;
    return tmp;
}

int insererTete(Liste *al, int x) {
    Cellule *cell = alloueCellule(x);
    if (cell == NULL)
        return 0;
    cell->suivant = *al;
    *al = cell*;
    return 1;
}

int insereApres(Liste *al, int x, int y)

