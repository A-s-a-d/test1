#include "definitions.h"
void mettre_en_majuscules(char ch[])
{
    for (int i = 0; ch[i] != '\0'; ++i)
        ch[i] = toupper(ch[i]);
}
int chifree = 0; // sert a savoir si le fichier a deja ete chifree? il faut q'au demarage le fichier ne soit pas chifree

void afficher_menu()
{
    printf("----------------------------------------------------------------------\n");
    printf("Entrez votre choix :\n"
        "[0] Quitter\n"
        "[1] Afficher la liste des produits\n"
        "[2] Ajouter un produit au panier\n"
        "[3] Retirer un produit du panier\n"
        "[4] Afficher le contenu du panier\n"
        "[5] Appliquer remise client\n"
        "[6] Payer\n"
    );
}


int main(void)
{
    int reponse = -1;
    /* lit le fichier de base de donnees des clients, et le charge en memoire */
    printf("\n\t\t###################    DEBUT      ########################\n\n");
/*
    if(chifree == 1)
    {
        chifree = ;
        crypto_chiffrer();
    }
*/
    printf("\n");
    crypto_dechiffrer();
    chifree = 0;
    printf("Chargement fichier clients...\n");
    ouvrir_fichier();
    personnes_remplir_liste();
    fermer_fichier();
    crypto_chiffrer();

//*
    // Menu client
    do {
        afficher_menu();
        reponse = 7;
        reponse = lire_int();

        switch(reponse) {
        case 0: puts("A bientot.");
                break;
        case 1: produit_afficher_liste();
                break;
        case 2: panier_ajouter();
                break;
        case 3: panier_supprimer();
                break;
        case 4: panier_afficher();
                break;
        case 5: CLIENT_FIDELE = panier_remise_client();
                break;
        case 6: panier_payer();
                CLIENT_FIDELE = false;
                panier_initialiser();
                break;
        case 7 : printf("entrer le choix");
                break;
        default: printf("Reponse incorrecte.\n");
        }
    } while (reponse != 0);
//*/
}
