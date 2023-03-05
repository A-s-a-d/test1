#include "definitions.h"
#include "fichiers.h"
#include "chiffrement.h"

Personne PERSONNES[MAX_PERSONNES];
int      NB_PERS;
int Personne_existe = 0;
int vide = 1;


void personnes_remplir_liste()
{
 if (NB_PERS == 0 && !fichier_ouvert()) {
        printf("La base de donnee n'est pas ouverte !");
        return;
    }
    /*
    * to read the line and copy it to PERSONNES
    */
    char LIGNE[50];
    while (fgets(LIGNE, sizeof(LIGNE), CLIENTS))
    {
        if (strlen(LIGNE) == 1 || isspace(LIGNE[0]))
        {
            continue;
        }
        Personne p;
        //sscanf(LIGNE, "%49s %49s %u", p.nom, p.pnom, &p.tel); //
        sscanf(LIGNE, "%s %s %u", p.nom, p.pnom, &p.tel);

        // Convert nom and pnom to uppercase
        for (int i = 0; i < strlen(p.nom); i++)
        {
            p.nom[i] = toupper(p.nom[i]);
        }

        for (int i = 0; i < strlen(p.pnom); i++)
        {
            p.pnom[i] = toupper(p.pnom[i]);
        }

        printf("test : %s %s %u\n", p.nom, p.pnom, p.tel);

        for(int i = 0; i<NB_PERS; i++)
        {
            if(strcmp(PERSONNES[i].nom, p.nom) == 0 && strcmp(PERSONNES[i].pnom, p.pnom) == 0 && PERSONNES[i].tel == p.tel)
            {
                Personne_existe = 1;
                break;
            }
        }
        if(!Personne_existe)
        {
            PERSONNES[NB_PERS] = p;
            NB_PERS++;
        }
    }
    /*
    *print the number of lines read to verify
    */
    printf("TEST : ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~: TEST\n");
    printf("test : Nombre de personnes lues : %d\n", NB_PERS);
    /*
    *print all the persones read to verify
    */
    for (int i = 0; i < NB_PERS; i++)
    {
        printf("test : %s %s %u\n", PERSONNES[i].nom, PERSONNES[i].pnom, PERSONNES[i].tel);
    }
    /*
    * j'ai fais cette fonction
    */
}








