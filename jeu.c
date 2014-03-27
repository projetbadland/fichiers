#include "projet.h"

int jeu(int niveau)
{
    ///Déclaration des variables de jeu
    //variable communes
    BITMAP *persoS;
    BITMAP *persoM;
    BITMAP *persoL;

    float para[NBPARA]={0,0,1};
    int **paraBM=NULL;

    //variable par niveau
    BITMAP *fond;
    BITMAP *collision;
    BITMAP *calque;

    ///Chargement des images
    //chargement images communes
    persoS=load_bitmap("images/persoS.bmp",NULL);
    persoM=load_bitmap("images/persoM.bmp",NULL);
    persoL=load_bitmap("images/persoL.bmp",NULL);
    //chargement images niveau
    chargement(niveau, paraBM, fond, collision, calque);

    free(paraBM);

    return 0;
}
