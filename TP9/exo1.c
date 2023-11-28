#include <stdio.h>
#include <stdlib.h>
/*On utilise des tableaux avec une structure*/
typedef struct {
    int plus_haut_deg;
    float *coef;
} Polynome;

void affichePolynome(Polynome p) {
    for (int i = 0; i < p.plus_haut_deg; i++) {
        if (i != p.plus_haut_deg - 1)
            printf("%.2f^%d + ", p.coef[i], i + 1);
        else
            printf("%.2f^%d ", p.coef[i], i + 1);
    }
    printf("\n");
}

int lirePolynome(Polynome *p) {
    int degre;
    printf("Entrez le degre du polynome : ");
    scanf("%d", &(p->plus_haut_deg));
    degre = p->plus_haut_deg;
    printf("Plus haut degré : %d\n", degre);
    p->coef = malloc(degre * sizeof(double));

    if (p->coef == NULL) {
        printf("Allocation de memoire echouée.");
        return -1;
    }
    printf("\n");
    for (int i = 0; i < degre; i++) {
        printf("Entrez le coefficient du degré %d : ", i + 1);
        scanf("%f", &(p->coef[i]));
    }

    return 0;
}

int somme(Polynome p, Polynome q, Polynome *res) {
    int degre_p = p.plus_haut_deg;
    int degre_q = q.plus_haut_deg;
    int deg_somme;

    if (degre_p < degre_q) {
        res->coef = malloc(degre_q * sizeof(double));
        deg_somme = q.plus_haut_deg;
    } else {
        res->coef = malloc(degre_p * sizeof(double));
        deg_somme = q.plus_haut_deg;
    }
    if (res->coef == NULL) {
        printf("Allocation de memoire echouée.");
        return -1;
    }

    for (int i = 0; i < deg_somme; i++) {
        res->coef[i] = p.coef[i] + q.coef[i];
    }

    return 0;
}

int main() {
    Polynome P1;
    Polynome P2;
    Polynome PS;
    lirePolynome(&P1);
    lirePolynome(&P1);
    somme(P1, P2, *PS);
    affichePolynome(PS);
    return 0;
}
