#include "projet.h"

void lancerAllegro(int largeur, int hauteur)
{
    // BUFFER d'affichage
    BITMAP *page;

    allegro_init();
    install_keyboard();

    /// OUVERTURE DU MODE GRAPHIQUE
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,largeur,hauteur,0,0)!=0)
    {
        allegro_message("Erreur graphique : %s", allegro_error);
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    /// CREATION DU BUFFER D'AFFICHAGE à la taille de l'écran
    page=create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(page);
}

void chargement(int niveauTube,int **paraBM ,BITMAP *fond, BITMAP *coll, BITMAP *calque)
{
    ///Déclaration des variables
    FILE *fp=NULL;
    fond=NULL;
    coll=NULL;
    calque=NULL;
    int niveau=48+niveauTube; //conversion du int en char*
    char *niv=(char*)&niveau;
    int nbBM=0; //nombre de bonus/malus
    int tmp=0; //inutile
    int i=0;

    ///Creation des chemins + chargement des images
    //fond
    char cheminFond[25] = "images/fond/";
    strcat(cheminFond, niv);
    strcat(cheminFond, ".bmp");
    fond=load_bitmap(cheminFond, NULL);

    //fond intermediaire : calque
    char cheminCalque[25]="images/calque/";
    strcat(cheminCalque, niv);
    strcat(cheminCalque, ".bmp");
    calque=load_bitmap(cheminCalque, NULL);

    //Colli
    char cheminColl[25]="images/collision/";
    strcat(cheminColl, niv);
    strcat(cheminColl, ".bmp");
    coll=load_bitmap(cheminColl, NULL);

    //test ouverture images
    if ((coll==NULL)||(fond==NULL))
    {
        printf("\nErreur chargement fond et/ou collision");
    }
    else
    {
        ///Ouverture fichier position bonus/malus
        //Chemin d'acces au fichier position
        char cheminPosition[20]="positionsBM/";
        strcat(cheminPosition, niv);
        strcat(cheminPosition, ".txt");

        fp=fopen(cheminPosition, "r");

        //test du chargement du fichier
        if(fp==NULL)
        {
            printf("\nErreur ouverture fichier position bonus/malus");
        }
        else
        {
            ///Comptage nombre de bonus/malus
            while(!(feof(fp)))
            {
                fscanf(fp,"%d", &tmp);
                nbBM++;
            }
            nbBM=nbBM/3;

            ///Allocation dynamique du tableau qui contiendra les bonus/malus
            paraBM=(int**)malloc(nbBM*sizeof(int*));
            for(i=0; i<nbBM; i++)
            {
                paraBM[i]=(int*)malloc(3*sizeof(int));
            }

            //test allocation
            if(paraBM==NULL) printf("\nErreur allocation dynamique BM");
            else
            {
                //retour au debut du fichier
                fseek(fp, 0, SEEK_SET);

                ///Acquisition des types et position des BM
                for(i=0; i<nbBM; i++)
                {
                    fscanf(fp, "%d %d %d", &paraBM[i][0], &paraBM[i][1],&paraBM[i][2]); //type du bonus//position x du bonus//position y
                }

                fclose(fp);
                printf("\nImages de fond, de collision et fichier de positions B/M chargees.");
            }
        }
    }
}



