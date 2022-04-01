#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>
#include <time.h>

#define LONG_MIN_ID_PL 5
#define LONG_MIN_FIRSTNAME_PL 2
#define LONG_MIN_LASTNAME_PL 2
#define LONG_MIN_PWD_PL 8

#define LONG_MAX_ID_PL 10
#define LONG_MAX_FIRSTNAME_PL 25
#define LONG_MAX_LASTNAME_PL 35
#define LONG_MAX_PWD_PL 12

#define LONG_PASS 12 +1
#define MAX_YEAR 9999
#define MIN_YEAR 1800

#endif

struct User
{
    char id_pl[10];
    char firstName_pl[25];
    char lastName_pl[35];
    unsigned type_pl;
    unsigned enabled_pl;
    unsigned char pwd_pl[12];
};

int addUser(struct User registerPlayer);
int deleteUser(char idUser[]);
void *encrypt(const unsigned char *password, unsigned char *encrypted, size_t size);
void *decrypt(const unsigned char *encrypted, unsigned char *decrypted, size_t size);