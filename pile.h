#ifndef PILE_H
#define PILE_H
#include <stddef.h>
#include <stdbool.h>
typedef struct NoeudPile { int val; struct NoeudPile* suivant; } NoeudPile;
typedef struct { NoeudPile* sommet; size_t taille; } Pile;
void pile_init(Pile* p);
bool pile_vide(Pile* p);
void pile_push(Pile* p, int v);
int pile_pop(Pile* p);
int pile_sommet(Pile* p);
void pile_detruire(Pile* p);
#endif
