#ifndef PROJET_H_INCLUDED
#define PROJET_H_INCLUDED

#include <allegro.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#define NBPARA 3

#ifndef H_PROTO
#define H_PROTO

//perso.c
void ajoutPerso(t_perso **ancre, float perso_px, float perso_py, float perso_vx, float perso_vy, float perso_ax, float perso_ay, int perso_deg);
void supprimerPerso(t_perso **ancre, t_perso *perso_mort);
void mouvPerso(t_perso *ancre, float para[NBPARA]);

//jeu.c
void jeu(int niveau);

//initialisation.c
void lancerAllegro(int largeur, int hauteur);
void chargement(int niveau,int **paraBM ,BITMAP *fond, BITMAP *coll, BITMAP *calque);

//affichage.c
void affichage(float vitesseScroll, BITMAP *fond, BITMAP *coll, BITMAP *calque);

#endif // H_PROTO

#endif // PROJET_H_INCLUDED
