#include "panier.h"
#include "personnes.h"
#include "produits.h"

int     PANIER_PRODS_QTE[MAX_PRODUITS]  =   { 0 };
float   PRIX_TOTAL                      =     0.0;
bool    CLIENT_FIDELE                   =   false;
Personne p_recherchee;





bool panier_remise_client(void)
{
    printf("Est ce que c'est un client fidele?\n");
    printf("Ajouter le nom de client en tout en MAJUSCULE\n");
    scanf("%s %s %u", &p_recherchee.nom, &p_recherchee.pnom, &p_recherchee.tel);
    getchar(); // Consume the newline character
    for (int i = 0; p_recherchee.nom[i]; i++)
    {
        p_recherchee.nom[i] = toupper(p_recherchee.nom[i]);
    }
    for (int i = 0; p_recherchee.pnom[i]; i++)
    {
        p_recherchee.pnom[i] = toupper(p_recherchee.pnom[i]);
    }
    printf("test : %s %s %u\n", p_recherchee.nom, p_recherchee.pnom, p_recherchee.tel);



    printf("Recherche du client fidele : %s %s %u\n", p_recherchee.nom, p_recherchee.pnom, p_recherchee.tel);
    for (int i = 0; i < MAX_PERSONNES; i++)
    {
        if (strcmp(PERSONNES[i].nom, p_recherchee.nom) == 0 &&
                strcmp(PERSONNES[i].pnom, p_recherchee.pnom) == 0 &&
                PERSONNES[i].tel == p_recherchee.tel)
        {
            CLIENT_FIDELE = true;
            printf("Client cherchee est fidele .\n");
            return true;
        }
    }
    printf("client cherchee n'est pas fidele\n");
    return false;
}




void panier_initialiser(void)
{
    for (int i = 0; i < MAX_PRODUITS; ++i)
    {
        PANIER_PRODS_QTE[i] = 0;
        PRIX_TOTAL = 0.;
    }
    printf("----------------------------------------------------------------------\n");
    printf("##### Program et panier ont ete reinitialisee #####\n");

}

void panier_afficher(void)
{

    printf("----------------------------------------------------------------------\n");
     printf("Produit\t\tQuantite\tPrix Unitaire\tTotal\n");
    for (int i = 0; i < NB_PRODS; i++)
    {
        if (PANIER_PRODS_QTE[i] > 0)
        {
            printf("%s\t\t%d\t\t%.2f\t\t%.2f\n",
                   NOMS_PRODUITS[i], PANIER_PRODS_QTE[i], PRIX_PRODUITS[i],
                   PANIER_PRODS_QTE[i] * PRIX_PRODUITS[i]);
        }
    }
    printf("\nTotal du panier: %.2f\n", PRIX_TOTAL);
    printf("----------------------------------------------------------------------\n");
/*
j'ai fais ca
*/
}



void panier_payer(void)
{
    float prix = PRIX_TOTAL;
    panier_afficher();

    if (!CLIENT_FIDELE)
    {
        printf("Faites-vous partie du programme fidelite ? (o/n) ");
        char REPONSE = lire_char();
        if (REPONSE == 'o')
        {
            printf("Entrez votre nom, prenom et telephone : ");
            scanf("%s %s %u", p_recherchee.nom, p_recherchee.pnom, &p_recherchee.tel);
            for (int i = 0; p_recherchee.nom[i]; i++)
            {
                p_recherchee.nom[i] = toupper(p_recherchee.nom[i]);
            }
            for (int i = 0; p_recherchee.pnom[i]; i++)
            {
                p_recherchee.pnom[i] = toupper(p_recherchee.pnom[i]);
            }
            printf("Recherche du client : %s %s %u\n", p_recherchee.nom, p_recherchee.pnom, p_recherchee.tel);
            for (int i = 0; i < MAX_PERSONNES; i++)
            {
                if (strcmp(PERSONNES[i].nom, p_recherchee.nom) == 0 &&
                        strcmp(PERSONNES[i].pnom, p_recherchee.pnom) == 0 &&
                        PERSONNES[i].tel == p_recherchee.tel)
                {
                    CLIENT_FIDELE = true;
                    printf("Client cherchee est fidele.\n");
                    break;
                } else     printf("client cherchee n'est pas fidele\n");
                break;


            }
        }

    }
    if (CLIENT_FIDELE)
    {
        float remise = 0.0;
        if        (prix >= 80)
        {
            prix *= .90;
            remise = 10;
        } else if (prix >= 15)
            {
                prix *= .95;
                remise = 5;
            }
        printf("Total apres remise : %.2f (%.0f%% de remise)\n",prix,remise);
    }

    if (!CLIENT_FIDELE)
    {
        float remise = 0.0;
        printf("----------------------------------------------------------------------\n");
        printf("Total apres remise : %.2f (%.0f%% de remise)\n",prix,remise);
    }
        printf("Paiement effectue avec succes.\n");
        return main();

}



