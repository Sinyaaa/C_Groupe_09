#include <version.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

int tableauDeDecodage[128];

int erreurDeFichier(FILE *monFichier)
{
    if (monFichier == NULL)
    {
        int erreur = errno;
        printf("Erreur d'ouverture %d.\n", erreur);
        perror("Erreur d�taill�e: ");
        return true;
    }
    return false;
}

void initialiserTableauDeCodage()
{
    // Remplissage par des 0 pour d�faut pour initialiser
    for (int index = 0; index < 128; index++)
    {
        tableauDeDecodage[index] = 0;
    }
    // D�codage de A � Z pour les positions 0 � 25
    for (unsigned char majuscule = 'A'; majuscule <= 'Z'; majuscule++)
    {
        tableauDeDecodage[majuscule] = majuscule - 'A';
    }
    // D�codage de a � z pour les positions 26 � 51
    for (unsigned char minuscule = 'a'; minuscule <= 'z'; minuscule++)
    {
        tableauDeDecodage[minuscule] = minuscule - 'a' + 26;
    }
    // D�codage de 0 � 9 pour les positions 52 � 61
    for (unsigned char chiffre = '0'; chiffre <= '9'; chiffre++)
    {
        tableauDeDecodage[chiffre] = chiffre - '0' + 52;
    }
    // D�codage de + et / en 62 et 63
    tableauDeDecodage['+'] = 62;
    tableauDeDecodage['/'] = 63;
}

unsigned char DecodageCaractere(int caractereLu)
{
    if ((caractereLu >= 0) && (caractereLu < 128))
    {
        return (tableauDeDecodage[caractereLu]);
    }
    return 0;
}

void decodageBase64(char *nomDeFichierSource, char *nomDeFichierDestination)
{
    FILE *fichierB64 = fopen(nomDeFichierSource, "r");
    if (!erreurDeFichier(fichierB64))
    {
        FILE *fichierBinaire;   // Pour le fichier binaire
        unsigned char *buffer;  // Buffer de travail pour �crire le binaire d�cod�
        int positionBuffer = 0; // Position dans le buffer de travail

        // Si un nomDeFichierDestination est sp�cifi�,
        // on �crit en binaire dans ce fichier
        // Sinon, on �crira � l'�cran
        if (nomDeFichierDestination != NULL)
        {
            fichierBinaire = fopen(nomDeFichierDestination, "wb");
            buffer = (unsigned char *)malloc(65536);
        }
        // On boucle en lisant l'entr�e
        while (1)
        {
            // On lit 4 caract�res, un par 1
            // En effet, comme le BASE64 encode 6 bits sur un caract�re
            // il faut lire 4 caract�res en entr�e pour obtenir 24 bits en sortie
            // Si on arrive � la fin avant, c'est un probl�me (le standard
            // pr�voyant de remplir la fin avec des = jusqu'� un multiple de 4 caract�res)

            // Caract�re num�ro 1
            // Si le caract�re est un \n, on le passe
            int int1;
            while ((int1 = fgetc(fichierB64)) == '\n') {}
            // Si fin de fichier � ce moment, OK, on a juste fini la boucle
            if (int1 == EOF)
            {
                break;
            }

            // Caract�re num�ro 2
            // Si le caract�re est un \n, on le passe
            int int2;
            while ((int2 = fgetc(fichierB64)) == '\n') {}
            // Si fin de fichier, il y a un probl�me!
            if (int2 == EOF)
            {
                printf("\n\n****** Fichier incorrect ******");
                break;
            }

            // Caract�re num�ro 3
            // Si le caract�re est un \n, on le passe
            int int3;
            while ((int3 = fgetc(fichierB64)) == '\n') {}
            // Si fin de fichier, il y a un probl�me!
            if (int3 == EOF)
            {
                printf("\n\n****** Fichier incorrect ******");
                break;
            }

            // Caract�re num�ro 4
            // Si le caract�re est un \n, on le passe
            int int4;
            while ((int4 = fgetc(fichierB64)) == '\n') {}
            // Si fin de fichier, il y a un probl�me!
            if (int4 == EOF)
            {
                printf("\n\n****** Fichier incorrect ******");
                break;
            }

            // On remplace les 4 caract�res pour leur codage en 6 bits
            // Et on les assemble pour obtenir les 24 bits � d�coder
            unsigned long intTotal = ((((DecodageCaractere(int1) * 64) + DecodageCaractere(int2)) * 64) + DecodageCaractere(int3)) * 64 + DecodageCaractere(int4);

            // On d�coupe les 24 bits en 3 fois 8 bits
            // pour obtenir les 3 octets d�cod�s
            unsigned char char1 = (intTotal >> 16) & 255;
            unsigned char char2 = (intTotal >> 8) & 255;
            unsigned char char3 = intTotal & 255;

            // Si texte, on affiche � l'�cran
            if (nomDeFichierDestination == NULL)
            {
                // S'il y a == � la fin, on n'affiche qu'un caract�re
                if (int3 == '=')
                {
                    printf("%c", char1);
                }
                // S'il y a = � la fin, on n'affiche que deux caract�res
                else if (int4 == '=')
                {
                    printf("%c%c", char1, char2);
                }
                // Sinon, on affiche les 3 caract�res
                else
                {
                    printf("%c%c%c", char1, char2, char3);
                }
            }
            // Si binaire, �criture dans le buffer m�moire
            else
            {
                buffer[positionBuffer++] = char1;
                // S'il y a == � la fin, on n'�crit qu'un byte
                // S'il y a = � la fin, on n'�crit que deux bytes
                if (int3 != '=')
                {
                    buffer[positionBuffer++] = char2;
                }
                if (int4 != '=')
                {
                    buffer[positionBuffer++] = char3;
                }
            }
        }
        fclose(fichierB64);

        // Si binaire, �criture du buffer dans le fichier
        if (nomDeFichierDestination != NULL)
        {
            fwrite(buffer, positionBuffer, 1, fichierBinaire);
            fclose(fichierBinaire);
        }
    }
}

int main()
{
    // Forcer l'encodage ISO8859-1
    setlocale(LC_ALL, "");

    initialiserTableauDeCodage();

    decodageBase64(".\\labo7-encodedtext.base64", NULL);
    decodageBase64(".\\labo7-encodedtext.base64", "C:\\UE108\\labo7-text.txt");
    decodageBase64(".\\labo7-encodedimage.base64", "C:\\UE108\\labo7-image.jpg");

    return EXIT_SUCCESS;
}

