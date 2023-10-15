#include <stdio.h>

/*Écrire un programme C qui lit son premier argument et compte les caractères de différents types dans le premier argument donné au programme. Il y aura trois types de caractères à compter : les lettres minuscules, les lettres majuscules et le reste du monde. Une fois le comptage terminé, votre programme devra faire un résumé de ce qu'il a compté sur la sortie standard via l'affichage suivant :

Nombre de majuscules : X   
Nombre de minuscules : Y   
Nombre d'autres caractères : Z
Où X, Y et Z seront remplacés par les entiers qui vont bien. Pas besoin d'adapter les pluriels selon les comptes trouvés. Il y a des espaces avant et après les deux points sur chaque lignes. Toutefois, ne rajouter aucun autre espace superflu.*/

int main(int argc, char const *argv[]) {
    int X = 0;
    int Y = 0;
    int Z = 0;
    const char *text = argv[1];
    int i = 0;
    while (text[i] != '\0') {
        if (65 <= text[i] && text[i] <= 90) {
            X += 1;
        } else if (97 <= text[i] && text[i] <= 122) {
            Y += 1;
        } else {
            Z += 1;
        }
        i += 1;
    }

    printf("Nombre de majuscules : %d\n", X);
    printf("Nombre de minuscules : %d\n", Y);
    printf("Nombre d'autres caractères : %d\n", Z);
    return 0;
}