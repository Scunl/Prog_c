#include <MLV/MLV_all.h>
#include <stdio.h>
#include <stdlib.h>

#define TAILLE_X 512
#define TAILLE_Y 512

typedef struct {
    int x;
    int y;
} Point;

typedef struct cellulePoint {
    Point p;
    struct cellulePoint *suivant;
} CellulePoint, *ListePoint;

ListePoint creer_liste_vide() {
    return NULL;
}

void detruire_liste(ListePoint liste) {
    ListePoint temp;
    while (liste != NULL) {
        temp = liste;
        liste = liste->suivant;
        free(temp);
    }
}

CellulePoint *allouerCellule(Point pval) {
    CellulePoint *nouvelle_cellule =
        (CellulePoint *)malloc(sizeof(CellulePoint));

    if (nouvelle_cellule != NULL) {
        nouvelle_cellule->p = pval;
        nouvelle_cellule->suivant = NULL;
    }

    return nouvelle_cellule;
}

int insererEnTete(ListePoint *liste, Point val) {
    CellulePoint *nouvelleCellule =
        (CellulePoint *)malloc(sizeof(CellulePoint));
    if (nouvelleCellule == NULL)
        return 0;
    nouvelleCellule->p = val;
    nouvelleCellule->suivant = *liste;
    *liste = nouvelleCellule;

    return 1;
}

int entrerPolygone(ListePoint *lst) {
    MLV_create_window("Polygone", "Polygone", 800, 600);
    Point p;
    int continuer = 1;

    while (continuer) {
        if (MLV_wait_mouse(&(p.x), &(p.y)) == MLV_BUTTON_LEFT) {
            insererEnTete(lst, p);

            if (*lst != NULL && (*lst)->suivant != NULL) {
                MLV_draw_line(p.x, p.y, (*lst)->suivant->p.x,
                              (*lst)->suivant->p.y, MLV_COLOR_BLACK);
                MLV_actualise_window();
            }
        } else {
            continuer = 0;
        }
    }

    MLV_wait_keyboard(NULL, NULL, NULL);
    MLV_free_window();
    return 1;
}

int main(int argc, char *argv[]) {
    ListePoint liste_points = creer_liste_vide();

    MLV_create_window("Fenêtre MLV", "MLV", TAILLE_X, TAILLE_Y);

    MLV_actualise_window();

    int attente = 5;
    MLV_wait_mouse_or_seconds(NULL, NULL, attente);

    MLV_free_window();

    detruire_liste(liste_points);

    return 0;
}
