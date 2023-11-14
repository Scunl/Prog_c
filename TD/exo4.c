#define MAXNOTES 10
#include <stdio.h>

typedef struct {
    int jour;
    char mois[10];
    int annee;
} Date;

typedef struct {
    char prenom[25];
    char nom;
    Date naissance;
    char formation[2];
    int redoublant;
    int groupe;
    int notes[MAXNOTES];
    int nbnotes;
} Fiche;

Date LireDate(void) {
    printf("Jour, mois, annee\n");
    scanf("%d", &Date.jour);
    scanf("%s", &Date.mois);
    scanf("%d", &Date.annee);
}

/*
int LireFiche(Fiche *fiche) {
}
*/

void ecrireFiche(Fiche f) {
    printf("Nom/Prenom : %s %s", f.nom, f.prenom);
    printf("Date de naissance: ");
    afficherDate(f.naissance);
    for (int i = 0; i < f.nbnotes; i++) {
        printf("%g ", f.notes[i]);
    }
}
void ajouteNote(Fiche *f, float note) {
    if (f->nbnotes < MAXNOTES) {
        f->notes[f->nbnotes] = note;
        f->nbnotes++;
    }
}

float moyenne(Fiche *f) {
    if (f->nbnotes == 0) {
        return -1;
    }
    float total = 0;
    for (int i = 0; i < f->nbnotes; i++) {
        total += f->notes[i];
    }
    return total / f->nbnotes;
}
