#include <stdio.h>

int affichage(char choix) {
    
    if (choix == 'a') {
        printf("Rouge\n");
        return 0;
    }
    if (choix == 'b') {
        printf("Vert\n");
        return 0;
    }
    if (choix == 'c') {
        printf("Bleue\n");
        return 0;
    }
    return 1;
}
char choix_user() {
    char choix;
    printf("Choisis entre ces 3 couleurs: Rouge (a), Vert (b), Bleue (c) ou n'importe quelle autre lettre pour sortir du programme\n"); 
    scanf(" %c", &choix);

    int resultat = affichage(choix);

    return choix;
}


int main(int argc, char const *argv[]) {   
    char result = ' ';
    while (1) {
        result = choix_user();
        printf("%c a été choisi\n", result);
        if (result != 'a') {
            if (result != 'b') {
                if (result != 'c') {
                    break;
                }
            }
        }

    }
    return 0;

}
