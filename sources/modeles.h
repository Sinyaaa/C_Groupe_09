#ifndef MODELES_H_INCLUDED
#define MODELES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>

#include <windows.h>
#include <stdbool.h>
#include <mysql.h>
#include "../sources/json.h"

void initialiserConnexion();
void cloturerConnexion();
void remplirTables();

void executerSQL(char *instructionSQL);
void fecthDonnee(char *insctructionSQL);

void ajouterModele(char* id, char* name, char* niceName);
void trier(char *words[], int count);
char **trieeModeles(char *niceName);

#endif




