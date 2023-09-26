#include <stdio.h>

int main(void){
    float a;
    int b;
    printf("Entrez un nombre : ");
    scanf("%f", &a);
    b = a;
    if (a == b){
        printf("C'est un entier\n");
    } else {
        printf("C'est un nombre à décimal\n");
    }
    return 0;
}