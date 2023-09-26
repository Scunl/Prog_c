#include <stdio.h>

int main(void) {
    int a, i;
    printf("Entrez un nombre strictement positif : ");
    scanf("%d", &a);
    for (i=0; i<a; i++){
        
        if (i%2 == 0){
            printf("Fizz");
        }
        if (i%3 == 0){
            printf("Buzz\n");
        }else{
            printf("\n");
        }
        printf("%d\n", i);
        }
        
    
    return 0;
}
