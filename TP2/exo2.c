#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int a;
    int i;
    int incr = 0;
    printf("J’ai choisi un nombre entre 1 et 1000.\n A vous de le deviner: ");
    i = rand() % 1000;
    
    do {
        scanf("%d", &a);
        if (a > i) {
            printf("C'est trop grand\n Devine encore: ");
        }
        if (a < i) {
            printf("C'est trop petit\n Devine encore: ");
        } 
        incr+=1;
             
    } while (i != a);
    
    printf("En %d essais\n", incr);

    return 0;
}