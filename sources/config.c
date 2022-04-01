#include "config.h"


struct User * pUser1=NULL;
struct User * pUser2=NULL;
struct User * pUser3=NULL;
struct User * pUser4=NULL;
struct User * pUser5=NULL;
struct User * pUser6=NULL;
struct User * pUser7=NULL;
struct User * pUser8=NULL;


// Joueur Sans Erreur

struct User * getUser1()
{

    if (pUser1 == NULL)
    {
        pUser1 = (struct User *) malloc(sizeof(struct User));
        pUser1->enabled_pl=1;
        pUser1->type_pl=1;
        strcpy(pUser1->firstName_pl, "Yassin");
        strcpy(pUser1->lastName_pl, "Assabban");
        strcpy(pUser1->id_pl, "1");
        strcpy(pUser1->pwd_pl, "Giraafee32$$");
    }
    return pUser1;
}

struct User * getUser2() 
{
    if (pUser2 == NULL)
    {
        pUser2 = (struct User *) malloc(sizeof(struct User));
        pUser2->enabled_pl=1;
        pUser2->type_pl=1;
        strcpy(pUser2->firstName_pl, "Ugur");
        strcpy(pUser2->lastName_pl, "Firat");
        strcpy(pUser2->id_pl, "2");
        strcpy(pUser2->pwd_pl, "Firatugur23$");
    }
    return pUser2;
}

//Joueur sans lastName

struct User * getUser3() 
{
    if (pUser3 == NULL)
    {
        pUser2 = (struct User *) malloc(sizeof(struct User ));
        pUser2->enabled_pl=1;
        pUser2->type_pl=1;
        strcpy(pUser3->firstName_pl, "Yassin3");
        strcpy(pUser3->lastName_pl, "");
        strcpy(pUser3->id_pl, "3");
        strcpy(pUser3->pwd_pl, "NetflixPrime54");
    }
    return pUser3;
}

//Joueur sans id_pl

struct User * getUser4() 
{
    if (pUser4==NULL )
    {
        pUser4 = (struct User *) malloc(sizeof(struct User ));
        pUser4->enabled_pl=1;
        pUser4->type_pl=1;
        strcpy(pUser4->firstName_pl, "Yassin4");
        strcpy(pUser4->lastName_pl, "Assabban4");
        strcpy(pUser4->id_pl, "");
        strcpy(pUser4->pwd_pl, "NetflixPrime54");
    }
    return pUser4;
}

//Joueur sans pwd_pl

struct User * getUser5() 
{
    if (pUser5==NULL )
    {
        pUser5 = (struct User *) malloc(sizeof(struct User ));
        pUser5->enabled_pl=1;
        pUser5->type_pl=1;
        strcpy(pUser5->firstName_pl, "Yassin5");
        strcpy(pUser5->lastName_pl, "Assabban5");
        strcpy(pUser5->id_pl, "5");
        strcpy(pUser5->pwd_pl, "");
    }
    return pUser5;
}

//Joueur avec rien

struct User * getUser6() 
{
    if (pUser6==NULL )
    {
        pUser6 = (struct User *) malloc(sizeof(struct User ));
        pUser6->enabled_pl=1;
        pUser6->type_pl=1;
        strcpy(pUser6->firstName_pl, "");
        strcpy(pUser6->lastName_pl, "");
        strcpy(pUser6->id_pl, "");
        strcpy(pUser6->pwd_pl, "");
    }
    return pUser6;
}

//Joueur prenom trop long

struct User * getUser7() 
{
    if (pUser7==NULL )
    {
        pUser7 = (struct User *) malloc(sizeof(struct User ));
        pUser7->enabled_pl=1;
        pUser7->type_pl=1;
        strcpy(pUser7->firstName_pl, "YassinAssabbanUgurFiratHarunSerdar9");
        strcpy(pUser7->lastName_pl, "Assabban9");
        strcpy(pUser7->id_pl, "7");
        strcpy(pUser7->pwd_pl, "NetflixPrime54");
    }
    return pUser7;
}

//Joueur nom trop long

struct User * getUser8() 
{
    if (pUser8==NULL )
    {
        pUser8 = (struct User *) malloc(sizeof(struct User ));
        pUser8->enabled_pl=1;
        pUser8->type_pl=1;
        strcpy(pUser8->firstName_pl, "Yassin8");
        strcpy(pUser8->lastName_pl, "YassinAssabbanUgurFiratHarunSerdar9");
        strcpy(pUser8->id_pl, "8");
        strcpy(pUser8->pwd_pl, "NetflixPrime54");
    }
    return pUser8;
}
