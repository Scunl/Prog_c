#include <stdio.h>

int main(void){
    int years,month,day,jour, i;
    jour = -1;
    while (jour<0){
        printf("Entrez un nombre de jours : ");
        scanf("%d", &jour);
    }
    years = jour/365;
    for (i=0; i<years; i++){
        jour = jour-365;
    }
    month = jour/30;
    day = jour - 30*month;
    printf("\n%d année(s), %d mois, %djour(s)\n", years, month, day);
}