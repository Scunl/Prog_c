#include <stdio.h>

int valAbsolueV1(int a) {
    if (a < 0) {
        return (-a);
    } 
    return a;
    
}

void valAbsolueV2(int a) {
    int *pointeur = &a;

    if (*pointeur < 0) {
        a = valAbsolueV1(*pointeur);
        return a;
    }
}

int main(void) {
    int nvar;  
    int pvar;
    printf("Veuillez saisir un nombre relatif : ");
    scanf("%d", &nvar);
    printf("\nVous avez saisi le nombre %d\n dont l'adresse est : %p\n", nvar, &nvar);
    pvar = valAbsolueV1(nvar);
    printf("Vous obtenez le nombre : %d\n L'adresse est : %p\n", pvar, &pvar);
    
    valAbsolueV2(31);
    return 0;
}
