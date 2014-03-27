#ifndef PROJET_H_INCLUDED
#define PROJET_H_INCLUDED

#include <allegro.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#define NBPARA 3

int jeu(int niveau);
void lancerAllegro(int largeur, int hauteur);
void chargement(int niveau,int **paraBM ,BITMAP *fond, BITMAP *coll, BITMAP *calque);

#endif // PROJET_H_INCLUDED
