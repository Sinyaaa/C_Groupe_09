#include "json.h"

// === === Fonction 0 === ===
//sert a enlever les espaces blanc dans la chaine de caractère

char *supp_esp_blanc(char *str)
{
    int i = 0, j = 0;

    while (str[i])
    {
        if (str[i] != ' ')
        {
            str[j++] = str[i];
        }
        i++;
    }
    
    str[j] = '\0';

    return str; 
}
// === === ----- === ===

// === === Fonction 1 === ===
unsigned jsonPrimitive(char *chaineJson, char *nomAttribut, char *resultat, unsigned dim,char *messageErreur)
{

    char cles[100][dim];
    char valeurs[100][dim];

    int indiceCle = 0;
    int indiceValeur = 0;

    int len = strlen(chaineJson);
    int valeurOuCle = 0;
    int i = 0;

    while (chaineJson[i] =! '}')
    {
        if (chaineJson[i] == '"' && chaineJson[i+1] != ':')
        {
            char mot[dim];
            int j = i + 1;
            int k = 0;

            while (chaineJson[j] != '"')
            {
                mot[k] = chaineJson[j];
                j++;
                i++;
                k++;
            }

            if (valeurOuCle % 2 == 0)
            {
                strcpy(cles[indiceCle], mot);
                indiceCle++;
            }
            else
            {
                strcpy(valeurs[indiceValeur], mot);
                indiceValeur++;
            }
            valeurOuCle++;
        }
        i++;
    }

    for (int i = 0; i < indiceCle; i++;)
    {
        if (strcmp( cles[i], nomAttribut ) == 0)
        {
            if (strlen( cles[i], nomAttribut ) == 0)
            {
                strcpy(resultat, valeurs[i]); 
                return 1;
            }
            else
            {
                char message[30] = "La taille dépasse la limite";
                strcpy(messageErreur, message);
                return 0;
            }
        }
    }
    
    strcpy(messageErreur, "Non trouvé");
    return 0;
}
// === === ----- === ===

// === === Fonction 2 === ===
unsigned jsonArray(char *chaineJson, char *nomAttribut, char resultats[][DIM], unsigned *nbElements, char *messageErreur)
{


}
// === === ----- === ===


