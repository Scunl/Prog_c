#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    int cmptiret = 0;
    int cmpfile = 0;
    FILE *fichier = NULL;
    printf("Il y'a %d argument(s)\n", argc - 1);

    for (int i = 0; i <= argc - 1; i++) {
        if (argv[i][0] == '-') {
            cmptiret++;
        } else {
            fichier = fopen(argv[i], "r+");
            if (fichier != NULL) {
                cmpfile++;
            }
        }
    }
    printf("nb of file : %d\n", cmpfile);
    printf("nb of - : %d\n", cmptiret);

    return 0;
}
