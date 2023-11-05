#include <math.h>
#include <stdio.h>

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  * * * * */
/* BUT : resoudre une equation du second degre                            */
/* PARAM : 3 valeurs float, qui sont les coefficients de l'equation       */
/*         2 adresses de float, qui stockeront les solutions possibles    */
/* RETOUR : un entier, qui sera le nombre de solutions                    */
/*          Plus precisemment :                                           */
/*                  -1, s'il y a une infinite de solutions                */
/*                  0, s'il n'y a pas de solution                         */
/*                  1, s'il y a une racine                                */
/*                  2, s'il y a deux racines distinctes                   */
/* EFFETS DE BORDS : S'il y a 1 solution, elle sera place a l'adresse de x*/
/*                   S'il y a 2 solutions, elles seront placees           */
/*                   aux adresses de x et y                               */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  * * * * */

int resoudre(float a, float b, float c, float *x, float *y) {
    float delta = (b * b) - (4 * a * c);
    if (delta > 0) {
        *x = (-b - sqrt(delta)) / (2 * a);
        *y = (-b + sqrt(delta)) / (2 * a);
        return 2;
    }
    if (delta == 0) {
        *x = (-b) / (2 * a);
        return 1;
    }
    return -1;
}

int main(void) {
    float r_un, r_deux;
    return 0;
}
