#include "chiffrement.h"
#include "definitions.h"

int CLE = CLE_DEFAUT;

void crypto_initialiser_cle(int cle)
{
    CLE = cle;
}

void crypto_chiffrer()
{
    ouvrir_fichier();
    CLE = 5;
    FILE *encrypted_file = fopen("encrypted.txt", "w");
    char LIGNE[50];
    while (fgets(LIGNE, sizeof(LIGNE), CLIENTS))
    {
        // Check if line is already encrypted
        if (strstr(LIGNE, "ENCRYPTED: ")) {
            fputs(LIGNE, encrypted_file);
            continue;
        }
        int length = strlen(LIGNE); // store length before encryption
        for(int i=0;i<length;i++)
        {
            // encryption code here
            if (isspace(LIGNE[i])) { // skip whitespace characters
                continue;
            }
            if (!isalpha(LIGNE[i]))
                LIGNE[i] = ((LIGNE[i] - '0' )+ CLE) % 10 + '0';
            if(isupper(LIGNE[i]))
                LIGNE[i]=((LIGNE[i]-'A') + CLE) % 26 + 'A';
            else if(islower(LIGNE[i]))
                LIGNE[i]=((LIGNE[i]-'a') + CLE) % 26 + 'a';
        }
        fprintf(encrypted_file, "ENCRYPTED: %s", LIGNE);
    }
    fclose(CLIENTS);
    fclose(encrypted_file);
    remove(NOM_BDD); // delete original file
    rename("encrypted.txt", NOM_BDD); // rename encrypted file to original file name
    fermer_fichier();
}

void crypto_dechiffrer()
{
    ouvrir_fichier();
    CLE = 5;
    FILE *decrypted_file = fopen("decrypted.txt", "w");
    char LIGNE[50];
    while (fgets(LIGNE, sizeof(LIGNE), CLIENTS))
    {
        // Check if line is already decrypted
        if (strstr(LIGNE, "ENCRYPTED: ")) {
            fprintf(decrypted_file, "%s", LIGNE + strlen("ENCRYPTED: "));
            continue;
        }
        int length = strlen(LIGNE);
        for(int i=0;i<length;i++)
        {
            // decryption code here
            if (isspace(LIGNE[i]))
            { // skip whitespace characters
                continue;
            }
            if (!isalpha(LIGNE[i]))
                LIGNE[i] = ((LIGNE[i] - '0' )- CLE) % 10 + '0';

            if(isupper(LIGNE[i]))
                LIGNE[i]=((LIGNE[i]-'A') - CLE + 26) % 26 + 'A';
            else if(islower(LIGNE[i]))
                LIGNE[i]=((LIGNE[i]-'a') - CLE + 26) % 26 + 'a';
        }
        fprintf(decrypted_file, "%s", LIGNE);
    }
    fclose(CLIENTS);
    fclose(decrypted_file);
    remove(NOM_BDD); // delete original file
    rename("decrypted.txt", NOM_BDD); // replace input file with decrypted data
    fermer_fichier();
}
