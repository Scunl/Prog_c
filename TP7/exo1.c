#include <MLV/MLV_all.h>
#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point x;
    Point y;
} Droite;

void saisiePoint(Point *p) {
    *p = MLV_wait_mouse();
    printf("%d", p);
}

int constructionDroite(Point a, Point b, Droite *d) {
    for (int i = 0; i < 2; i++) {
        /*saisie des points MLV*/
    }
    /*stock equation de la droite ax + b et retourne si tout se passe bien (PAS
     * DE VERTICALE)*/
}

void dessinDroit(Droite d) {
    /*DRAW LINE d = ax + b OU DRAW LINE entre les deux points en fonction de ce
     * que draw line fait*/
}

int main(int argc, char const *argv[]) {
    saisiePoint();
    return 0;
}
