/*
** api pour se connecter à MySQL
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

}
