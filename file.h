#ifndef FILE_H
#define FILE_H
#include <stddef.h>
#include <stdbool.h>
typedef struct NoeudFile { int val; struct NoeudFile* suivant; } NoeudFile;
typedef struct { NoeudFile* tete; NoeudFile* queue; size_t taille; } File;
void file_init(File* f);
bool file_vide(File* f);
void file_enfiler(File* f, int v);
int file_defiler(File* f);
int file_tete(File* f);
void file_detruire(File* f);
#endif
