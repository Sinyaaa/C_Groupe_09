#ifndef __JSON_H__
#define __JSON_H__

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>

#define DIM 20

unsigned jsonPrimitive(char *chaineJson, char *nomAttribut, char *resultat, unsigned dim,char *messageErreur);
unsigned jsonArray(char *chaineJson, char *nomAttribut, char resultats[][DIM], unsigned *nbElements, char *messageErreur);

#endif
