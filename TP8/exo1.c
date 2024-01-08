#include <stdio.h>

typedef struct cellule {
    int valeur;              /* donnee stockee : un entier . */
    struct cellule *suivant; /* adresse de la cellule suivante . */
} Cellule;                   /* definition d ’ un nouveau type . */
typedef Cellule *Liste;      /* definition d ’ un nouveau type . */

int nbelem(Cellule *lst) {
    int i = 0;
    while (lst != NULL) {
        i++;
        lst = lst->suivant;
    }
    return i;
}

void *recherche_adresse(Cellule *lst, int element) {
    int len = nbelem(lst);
    for (int i = 0; i < len; i++) {
        if (element == lst->valeur) {
            printf("L'adresse de l'element %d est : %p", element,
                   (void *)&lst->valeur);
            return &lst->valeur;
        } else
            lst = lst->suivant;
    }
    return NULL;
}

int inf(lst, x)
Cellule *lst;
{ // stylé
    int cmp = 0;
    int len = nbelem(lst);
    for (int i = 0; i < len; i++) {
        if (lst->valeur <= x)
            cmp++;
        lst = lst->suivant;
    }
    return cmp;
}

int estTriePainAuChocolat(Cellule *lst) {
    int prec = lst->valeur;
    while (lst != NULL) {
        if (lst->valeur > prec)
            return 0;
        prec = lst->valeur;
        lst = lst->suivant;
    }
    return 1;
}
int smegma(Cellule *lst) {
    
    int longueur = nbelem(lst) - 1;
    if (longueur < 2) {
        return 1;
    }
    int prec = lst->valeur;
    lst = lst->suivant;
    if (prec <= lst->valeur) {
        for (int i = 0; i < longueur; i++) {
        }
    }
}

int main() {
    // Création de la liste avec différentes valeurs
    Cellule c1 = {10, NULL};
    Cellule c2 = {212, NULL};
    Cellule c3 = {'w', NULL};
    Cellule c4 = {14, NULL};
    Cellule c5 = {31, NULL};

    c1.suivant = &c2;
    c2.suivant = &c3;
    c3.suivant = &c4;
    c4.suivant = &c5;

    Liste maListe = &c1;

    printf("Nombre d'éléments dans la liste : %d\n", nbelem(maListe));

    int elementRecherche = 15;
    void *adresse = recherche_adresse(maListe, elementRecherche);
    if (adresse != NULL) {
        printf("L'adresse de l'élément %d est : %p\n", elementRecherche,
               adresse);
    } else {
        printf("Element non trouvé dans la liste.\n");
    }

    int valeurX = 400;
    int resultInf = inf(maListe, valeurX);
    printf("Nombre d'éléments inférieurs ou égaux à %d : %d\n", valeurX,
           resultInf);

    return 0;
}