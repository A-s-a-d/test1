#ifndef PANIER_H_GUARD
#define PANIER_H_GUARD

#include "definitions.h"
#include "produits.h"
#include "utils.h"

/*
 * TODO 
 * XXX /!\ DOCUMENTEZ-MOI /!\ XXX
 */ 

/*
 * PANIER_PRODS_QTE contient la quantite de chaque produit du meme indice que
 * dans le tableau PRODUITS.
 * Par exemple, si PANIER_PRODS_QTE[3] == 2, alors c'est que le client a demande
 * d'acheter 2 lots de "LEGUMES" (voir produits.c).
 */
extern int     PANIER_PRODS_QTE[MAX_PRODUITS];

/*
 * TODO 
 * XXX /!\ DOCUMENTEZ-MOI /!\ XXX
 */
extern float   PRIX_TOTAL                    ;

/*
 * TODO 
 * XXX /!\ DOCUMENTEZ-MOI /!\ XXX
 */
extern bool    CLIENT_FIDELE                 ;

/* 
 * panier_remise_client
 * fonction : 
 * entrees : 
 * sortie :
 * variables globales modifiées :
 */
bool panier_remise_client(void);

/* 
 * panier_initialiser
 * fonction : 
 * entrees : 
 * sortie :
 * variables globales modifiées :
 */
void panier_initialiser(void);

/* 
 * panier_afficher
 * fonction : 
 * entrees : 
 * sortie :
 * variables globales modifiées :
 */
void panier_afficher(void);

/* 
 * panier_payer
 * fonction : 
 * entrees : 
 * sortie :
 * variables globales modifiées :
 */
void panier_payer(void);

/* 
 * panier_ajouter
 * fonction : 
 * entrees : 
 * sortie :
 * variables globales modifiées :
 */
void panier_ajouter(void);

/* 
 * panier_supprimer
 * fonction : 
 * entrees : 
 * sortie :
 * variables globales modifiées :
 */
void panier_supprimer(void);

/* 
 * panier_afficher
 * fonction : 
 * entrees : 
 * sortie :
 * variables globales modifiées :
 */
void panier_afficher(void);
#endif // PANIER_H_GUARD
