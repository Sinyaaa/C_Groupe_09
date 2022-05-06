#ifndef MARQUES_H_INCLUDED
#define MARQUES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>
#include <mysql.h>
#include <locale.h>

#endif

typedef struct marque // Création d'un "struct" pour faciliter la récupération dans le .txt
{
    char *id;
    char *name;
    char *niceName;
} marque;

void initialiserConnexion(); // Connexion à la DB 
void executerSQL(char *instructionSQL); 
void recupFichier(char *ligne, marque marque); // Fonction récuperant les informations utiles à la création de table 
void recupMarque(marque marque, char *erreur); // Fait appel au jsonPrimitive pour n'utiliser que les informations demandées
void remplirSQL(marque marque); // Remplir les tableaux en DB
void cloturerConnexion(); // Déconnexion de la DB 