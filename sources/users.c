#include <users.h>

int erreurDeFichier(FILE *monFichier)
{
    if (monFichier == NULL)
    {
        int erreur = errno;
        printf("Erreur d'ouverture %d.\n", erreur);
        perror("Erreur détaillée");

        return true;
    }
    return false;
}

int addUser(struct User registerUser)
{
    FILE *fUser=NULL;
    fUser=fopen("../textfiles/users.txt", "a");
    int done = 0;

    if (fUser != NULL)
    {
        if(checkExistUser(registerUser.id_pl) == 0)
        {
            if(checkDataUser(&registerUser) == 1)
            {
                fprintf(fUser, "%s %s %s %s %d %d\n", registerUser.id_pl, registerUser.firstName_pl, registerUser.lastName_pl, registerUser.pwd_pl, 2, 1);

                done = 0;
            }
            else
            {
                done = 1;
            }
        }
        else
        {
            done = 1;
        }
        fclose(fUser);
    }
    return done;
}

int deleteUser(char idUser[])
{
    FILE* fUser = NULL;
    FILE* ftemp = NULL;

    fUser = fopen("../textfiles/users.txt", "r");
    ftemp = fopen("../textfiles/temp.txt", "w");

    struct User joueur[100];
    int count = 0;

    if (fUser != NULL && ftemp != NULL)
    {
        while (fscanf(fUser, "%s %s %s %s %d %d\n", joueur[count].id_pl, joueur[count].firstName_pl, joueur[count].lastName_pl, joueur[count].pwd_pl, &joueur[count].type_pl, &joueur[count].enabled_pl) != EOF)
        {
            if (strcmp(joueur[count].id_pl, idUser) == 0)
            {
                fprintf(ftemp,"%s %s %s %s %d %d\n", joueur[count].id_pl, joueur[count].firstName_pl, joueur[count].lastName_pl, joueur[count].pwd_pl, joueur[count].type_pl, 0);

            }
            else
                fprintf(ftemp,"%s %s %s %s %d %d\n", joueur[count].id_pl, joueur[count].firstName_pl, joueur[count].lastName_pl, joueur[count].pwd_pl, joueur[count].type_pl, joueur[count].enabled_pl);

            count++;
        }
        fclose(fUser);
        fclose(ftemp);
    }

    fUser = fopen("../textfiles/users.txt", "w");
    ftemp = fopen("../textfiles/temp.txt", "r");

    if (fUser != NULL && ftemp != NULL)
    {
        while (fscanf(ftemp, "%s %s %s %s %d %d\n", joueur[count].id_pl, joueur[count].firstName_pl, joueur[count].lastName_pl, joueur[count].pwd_pl, &joueur[count].type_pl, &joueur[count].enabled_pl) != EOF)
        {
            fprintf(fUser,"%s %s %s %s %d %d\n", joueur[count].id_pl, joueur[count].firstName_pl, joueur[count].lastName_pl, joueur[count].pwd_pl, joueur[count].type_pl, joueur[count].enabled_pl);
        }

        fclose(ftemp);
        remove("../textfiles/temp.txt");
        fclose(fUser);

    }

    return 0;
}

// int modifUser(){}

unsigned checkExistUser(char * pId_pl)
{
    FILE* fUser = NULL;

    struct User joueur[100]; // Tableau

    int count = 0;
    int exist = 0;

    fUser = fopen("../textfiles/users.txt", "r");

    if(fUser != NULL)
    {

        while(fscanf(fUser,"%s %s %s %s %d %d\n", joueur[count].id_pl,joueur[count].firstName_pl, joueur[count].lastName_pl, joueur[count].pwd_pl, &joueur[count].type_pl, &joueur[count].enabled_pl) != EOF)
        {
            if (strcmp(pId_pl, joueur[count].id_pl) == 0)
            {
                exist = 1;
            }
            count++;
        }

        fclose(fUser);
    }

    return exist;
}

unsigned checkDataUser(struct User * pUser)
{

    //Verifie la longueur MIN des informations joueurs
    if ( strlen(pUser->id_pl) < LONG_MIN_ID_PL) return 0;
    if ( strlen(pUser->firstName_pl) < LONG_MIN_FIRSTNAME_PL) return 0;
    if ( strlen(pUser->lastName_pl) < LONG_MIN_LASTNAME_PL) return 0;
    if ( strlen(pUser->pwd_pl) < LONG_MIN_PWD_PL) return 0;

    //Verifie la longueur MAX  des informations joueurs
    if ( strlen(pUser->id_pl) > LONG_MAX_ID_PL) return 0;
    if ( strlen(pUser->firstName_pl) > LONG_MAX_FIRSTNAME_PL) return 0;
    if ( strlen(pUser->lastName_pl) > LONG_MAX_LASTNAME_PL) return 0;
    if ( strlen(pUser->pwd_pl) > LONG_MAX_PWD_PL) return 0;

    return 1;
}


void *encrypt(const unsigned char *password, unsigned char *encrypted, size_t size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        encrypted[i] = (password[i] << 1) + ((password[i] >> 7) & 1);
    }
    encrypted[i] = '\0';

    return 0;
}

void *decrypt(const unsigned char *encryptedPass, unsigned char *decrypted, size_t size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        decrypted[i] = (encryptedPass[i] >> 1) + ((encryptedPass[i] & 1) << 7);
    }
    decrypted[i] = '\0';

    return 0;
}

