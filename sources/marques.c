#include "marques.h"

MYSQL *sqlConnection = NULL;

int main(int argc, char *argv[]) 
{
  setlocale(LC_ALL, "");

  FILE *monFichier = fopen("../textfiles/marques_modeles.txt", "r");

  char *ligne = (char *)malloc(2000);
  marque marque;
  char *erreur = (char *)malloc(50);
  marque.id = (char *)malloc(50);
  marque.name = (char *)malloc(50);
  marque.niceName = (char *)malloc(50);

  initialiserConnexion();
  executerSQL("DELETE FROM marque");

  while (fscanf(monFichier, "%[^\n] ", ligne) != EOF)
  {
      recupFichier(ligne, marque);
      recupMarque(marque, erreur);
      remplirSQL(marque);
  }

  cloturerConnexion();
  fclose(monFichier);
  free(erreur);
  free(ligne);

  return EXIT_SUCCESS;
}

void initialiserConnexion() 
{
  sqlConnection = mysql_init(NULL);
  if (sqlConnection == NULL)
  {
    fprintf(stderr, "%s\n", mysql_error(sqlConnection));
    exit(EXIT_FAILURE);
  }

  if (!mysql_real_connect(sqlConnection, "localhost", "root",
                          NULL, NULL, 3306, NULL, 0))
  {
    fprintf(stderr, "%s\n", mysql_error(sqlConnection));
    exit(EXIT_FAILURE);
  }
}

void executerSQL(char *instructionSQL) 
{
  if (mysql_query(sqlConnection, instructionSQL))
  {
    fprintf(stderr, "%s\n", mysql_error(sqlConnection));
    mysql_close(sqlConnection);
    exit(EXIT_FAILURE);
  }
}

int recupFichier(char *ligne, marque marque) 
{
  if (ligne != NULL) 
  {
  static char *virgule = ",";

  strcpy(marque.id, strtok(ligne, virgule));
  strcpy(marque.name, strtok(NULL, virgule));
  strcpy(marque.niceName, strtok(NULL, virgule));
  } else return 1;

  return 0;
}

int recupMarque(marque marque, char *erreur) 
{ 
  if (marque.id != NULL || marque.name != NULL || marque.niceName != NULL) 
  {
    jsonPrimitive(marque.id, "id", marque.id, 30, erreur);
    jsonPrimitive(marque.name, "name", marque.name, 30, erreur);
    jsonPrimitive(marque.niceName, "niceName", marque.niceName, 30, erreur);
  } else return 1;
  return 0
}

void remplirSQL(marque marque) 
{
  int id;
  id = atoi(marque.id);
  char *insert = (char *)malloc(1024);

  sprintf(insert, "INSERT INTO marque (id_marques, name_marques, niceName_marques) VALUES (%d, '%s', '%s')", id, marque.name, marque.niceName);
  executerSQL(insert);
}

void cloturerConnexion() 
{
  if (sqlConnection != NULL)
  {
    mysql_close(sqlConnection);
  }
}