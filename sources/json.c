#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>

unsigned jsonPrimitive(char *chaineJson, char *nomAttribut, char *resultat, unsigned dim,char *messageErreur)
{

    //Ouverture du fichier "marques modeles"
    FILE* p_mm = fopen("marques_modeles.json", "r");

    //Message d'erreur si le fichier ne s'ouvre pas
    if (p_mm == NULL)
    {
        printf("Erreur de l'ouverture\n");
        return -1
    }

    resultat = 0;

    while (resultat != EOF)
    {
        resultat = fgetc(p_mm);
        printf("%c", (char)resultat);
    }
    
    //fermeture du fichier "marques modeles"
    fclose(p_mm);


    return 0;
}



unsigned jsonArray(char *chaineJson, char *nomAttribut, char resultats[][DIM], unsigned *nbElements, char *messageErreur)
{


}



