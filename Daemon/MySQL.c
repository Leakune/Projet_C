/*
** api lié à MySQL
** Fait par Ludovic & Gabriel
** 26/11/2019
*/

#include <stdio.h>
#include <stdlib.h>
#include "MySQL.h"



MYSQL * my_MySQL()
{
    const char *host = "127.0.0.1";
    const char *user = "root";
    const char *passwd = NULL;
    const char *dbname = "daemon";

    unsigned int port = 3308;
    const char *unix_socket = NULL;
    unsigned int flag = 0;


    MYSQL *connection, *res;            //créer un gestionnaire (ou autrement dit un objet) pour se connecter sur MySQL

    connection = mysql_init(NULL);  /*fonction qui allocalise, initialise et retourne un objet si on entre la valeur NULLE dans la fonction
                                    et qu'il y a eu assez de mémoire pour contenir l'objet
                                    Mais s'il n'y a pas assez d'espace mémoire, la fonction retourne NULLE*/

    mysql_options(connection,MYSQL_READ_DEFAULT_GROUP,"option");
    printf("MySQL client version: %s\n", mysql_get_client_info());

    res = mysql_real_connect(connection, host, user, passwd, dbname, port, unix_socket, flag); /*fonction qui retourne NULL si
                                                                                        on n'a pas réussi à se connecter sur la base,
                                                                                        Si ça marche elle retourne l'objet que nous avions
                                                                                        déjà employé pour se connecter sur MySQL (*connection)*/

    if (!res){      //S'il y a une erreur lié à la connexion, on affiche le message d'erreur puis son code d'erreur
        fprintf(stderr, "\n Error: %s [%d]\n",  mysql_error(connection), mysql_errno(connection));
        exit(1);
    }
    printf("Connection successful");
    return connection;
}

void display_app_MySQL(MYSQL *connection)
{
    mysql_query(connection, "SELECT nom, nom_exec, chemin, version_actuel FROM liste_application"); //on sélectionne toutes les application existantes dans la base de données
    MYSQL_RES *result = mysql_use_result(connection); //on enregistre les résultats de la précédente requette SQL dans un pointeur de structure
                                                      //de type MYSQL_RES

    int nb_columns = mysql_num_fields(result); //on stock le nombre de colonnes sélectionnées de la table liste_application d'après la requette
    MYSQL_ROW row; //contiendra une ligne de la table
    while((row = mysql_fetch_row(result)) != NULL) //on récupère les lignes trouvées tant que la requette en trouve
    {
        unsigned long *lengths = mysql_fetch_lengths(result); //on récupère la taille de la valeur d'une des colonnes pour une ligne trouvée
         for(int i = 0; i < nb_columns; i++){
            printf("[%.*s]", (int) lengths[i], row[i] ? row[i] : "NULL"); //on affiche les champs
         }
         printf("\n");
    }

    mysql_free_result(result); //on libère le jeu de résultat.
}

void add_app_MySQL (char *path_app, char *version_app, char *name, char *name_exe, MYSQL *connection)
{
    /*VERIFICATION SI APPLICATION DEJA CHOISIE*/
    mysql_query(connection, "SELECT nom, nom_exec FROM liste_application");
    MYSQL_RES *result = mysql_use_result(connection);

    int nb_columns = mysql_num_fields(result);
    MYSQL_ROW row;
    while((row = mysql_fetch_row(result)) != NULL)
    {
         for(int i = 0; i < nb_columns; i++){
            if(i == 0 && strcmp(name, row[i]) == 0){
                printf("\nError: this name is already used\n");
                return;
            }
            if(i == 1 && strcmp(name_exe, row[i]) == 0){
                printf("\nError: that software has been already chosen");
                return;
            }
         }
    }
    mysql_free_result(result); //on libère le jeu de résultat.

    /*INSERTION DES DONNEES*/
    char query[1000]; //tableau qui va contenir la requette
    char escaped_path_app[500];
    unsigned long ret = mysql_real_escape_string(connection, escaped_path_app, path_app, strlen(path_app));
    if (ret == (unsigned long)-1){
        printf("\nError: unable to escape path app");
        return;
    }
    sprintf(query, "INSERT INTO liste_application (nom, nom_exec, chemin, version_actuel) VALUES('%s', '%s', '%s', '%s')", name, name_exe, escaped_path_app, version_app);
    mysql_query(connection, query); //insertion de données dans la base
}
