#include <stdlib.h>
#include "pile.h"
void pile_init(Pile* p){ p->sommet=NULL; p->taille=0; }
bool pile_vide(Pile* p){ return p->sommet==NULL; }
void pile_push(Pile* p, int v){ NoeudPile* n=malloc(sizeof(NoeudPile)); n->val=n->suivant=p->sommet; p->sommet=n; p->taille++; }
int pile_pop(Pile* p){ if(pile_vide(p)) return 0; NoeudPile* tmp=p->sommet; int v=tmp->val; p->sommet=tmp->suivant; free(tmp); p->taille--; return v; }
int pile_sommet(Pile* p){ if(pile_vide(p)) return 0; return p->sommet->val; }
void pile_detruire(Pile* p){ while(!pile_vide(p)) pile_pop(p); }
