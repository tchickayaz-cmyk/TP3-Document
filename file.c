#include <stdlib.h>
#include "file.h"
void file_init(File* f){ f->tete=f->queue=NULL; f->taille=0; }
bool file_vide(File* f){ return f->tete==NULL; }
void file_enfiler(File* f, int v){ NoeudFile* n=malloc(sizeof(NoeudFile)); n->val=v; n->suivant=NULL; if(file_vide(f)) f->tete=f->queue=n; else { f->queue->suivant=n; f->queue=n; } f->taille++; }
int file_defiler(File* f){ if(file_vide(f)) return 0; NoeudFile* tmp=f->tete; int v=tmp->val; f->tete=tmp->suivant; if(f->tete==NULL) f->queue=NULL; free(tmp); f->taille--; return v; }
int file_tete(File* f){ if(file_vide(f)) return 0; return f->tete->val; }
void file_detruire(File* f){ while(!file_vide(f)) file_defiler(f); }
