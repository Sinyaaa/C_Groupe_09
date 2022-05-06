#include "modeles.h"

MYSQL *sqlConnection = NULL;

int main()
{
    setlocale(LC_ALL, "");

    initialiserConnexion();

    // === creation de la table modeles ===

    executerSQL("CREATE TABLE modeles (\
                id_modeles int(11) NOT NULL,\
                name_modeles varchar(50) DEFAULT NULL,\
                niceName_modeles varchar(50) DEFAULT NULL,\
                id_marques int(11) NOT NULL\
            ) ENGINE=InnoDB DEFAULT CHARSET=utf8;");

    ajouterModele("Acura_ILX", "Acura_ILX", "ilx");
    ajouterModele("Acura_ILX_Hybrid", "ILX Hybrid", "ilx-hybrid");
    ajouterModele("Acura_MDX", "MDX", "mdx");
    ajouterModele("Acura_RDX", "RDX", "rdx");
    ajouterModele("Acura_RLX", "RLX", "ilx");
    ajouterModele("Acura_ILX", "Acura_ILX", "rlx");
    ajouterModele("Acura_TL", "TL", "tl");
    ajouterModele("Acura_TSX", "TSX", "tsx");
    ajouterModele("Acura_TSX_Sport_Wagon", "TSX Sport Wagon", "tsx-sport-wagon");

    return EXIT_SUCCESS;
}

// === Analyse de la connexion avec la base de données ===
void initialiserConnexion()
{

    sqlConnection = mysql_init(NULL);
    if (sqlConnection == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(sqlConnection));
        exit(EXIT_FAILURE);
    }

    if (!mysql_real_connect(sqlConnection, "localhost", "root", NULL, NULL, 3306, NULL, 0))
    {
        fprintf(stderr, "%s\n", mysql_error(sqlConnection));
        exit(EXIT_FAILURE);
    }
}

// === Fermeture de la connexion avec la base de données ===
void cloturerConnexion()
{
    if (sqlConnection != NULL)
    {
        mysql_close(sqlConnection);
    }
}


// === Fonction qui execute une requete SQL ===
// instructionSQL = la requete a executer
void executerSQL(char *instructionSQL)
{
    if (mysql_query(sqlConnection, instructionSQL)) // instructionSQL = La requete SQL à executer 
    {
        fprintf(stderr, "%s\n", mysql_error(sqlConnection));
        mysql_close(sqlConnection);
        exit(EXIT_FAILURE);
    }   
}


// === Fonction permettant de rajouter un modèle à la base de données ===
// id = id du modèle
// name = nom qui correspondant
// nicaName = niceName qui correspondant
void ajouterModele(char* id, char* name, char* niceName)
{
    char *insertPhrase = "INSERT INTO modeles (id_modeles, name_modeles, niceName_modeles)\
     VALUE ('%s','%s', '%s')";
    
    char *insertSQL = (char *)malloc(strlen(id) + strlen(name) + strlen(niceName));
    sprintf(insertSQL, id, name, niceName);
    
    if (insertSQL != NULL)
    {
        if (mysql_query(sqlConnection, insertSQL))
        {
            fprintf(stderr, "%s\n", mysql_error(sqlConnection));
            mysql_close(sqlConnection);
            free(insertSQL);
            exit(EXIT_FAILURE);
        }
    }
    free(insertSQL);
}

// === Fonction qui execute une requete SQL et stock les resultats ===
// instructionSQL = requete a executer
int fetchDonnee(char *instructionSQL)
{
    if (mysql_query(sqlConnection, instructionSQL))
    {
        fprintf(stderr, "%s\n", mysql_error(sqlConnection));
        mysql_close(sqlConnection);
        exit(EXIT_FAILURE);
    }
    
    MYSQL_RES *sqlResult = mysql_store_result(sqlConnection);
    if (sqlResult == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(sqlConnection));
        mysql_close(sqlConnection);
        exit(EXIT_FAILURE);
    }

    MYSQL_ROW sqlRow = mysql_fetch_row(sqlResult);
    if (sqlRow == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(sqlConnection));
        mysql_close(sqlConnection);
        exit(EXIT_FAILURE);
    }
    
    return strcmp(sqlRow[0], "") != 0; //int retourne vrai si la requete retourne au moins une ligne

}

//Fonction permettant de trier une liste de MOTS en ordre alphabétique 

void trier (char *words[], int count)
{
    char *x;

    for (int i = 0; i<count; i++)
    {
        for (int j = i + 1; j<count; j++)
        {
            if (stcmp(words[i], words[j]) > 0)
            {
                x = words[j];
                words[j] = words[i];
                words[i] = x;
            }
        }
        
    }
}
//Fonction permetant de trier la listes des MODELES en ordre alphabétique

char **trierModeles(char *niceName){

    char *getNiceName = "SELECT NAME from modeles where niceName_modeles = '%s'";

    char *getSQL = (char *)malloc(strlen(niceName));

    sprintf(getSQL, niceName);

    if (mysql_query(sqlConnection, "SELECT * from "))
    {
        fprintf(stderr, "%s\n", mysql_error(sqlConnection));
        mysql_close(sqlConnection);
        exit(EXIT_FAILURE);
    }

    MYSQL_RES *sqlResult = mysql_store_result(sqlConnection);
    if (sqlResult == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(sqlConnection));
        mysql_close(sqlConnection);
        exit(EXIT_FAILURE);
    }

    MYSQL_ROW sqlRow = mysql_fetch_row(sqlResult);

    trier((char **) sqlRow, sqlResult->row_count);

    return (char **)sqlRow;
}