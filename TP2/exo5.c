#include <stdio.h>


void ajouteDix(int * entier) {
    *entier = *entier + 10;
}

int main(void)
{   
    int choix;
    int choix2;
    scanf("%d", &choix);
    scanf("%d", &choix2);
    printf("Valeur choix : %d\n", choix);
    printf("%p\n", (void *)&choix);
    ajouteDix(&choix);
    printf("=========================================\n");
    printf("%d\n", choix2);
    printf("%p", (void *)&choix2);
    return 0;
}