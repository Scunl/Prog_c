#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point x;
    Point y;
} Droite;

void saisiePoit(Point *p) {
    /*MLV INPUT => MLV_WAIT_MOUSE(X)*/
}

int constructionDroite(Point a, Point b, Droite *d) {
    /*stock equation de la droite ax + b et retourne si tout se passe bien*/
}

void dessinDroit(Droite d) {
    /*DRAW LINE d = ax + b*/
}