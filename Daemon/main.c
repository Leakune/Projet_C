/*
** Application : Daemon
** Ludovic & Gabriel
** 20/12/2012
*/

#include <stdlib.h>
#include <stdio.h>
#include "MySQL.h"
#include "GTK.h"
#include "find_app.h"

int main(int argc, char **argv)
{
    char *path_app = "C:\\Riot Games\\League of Legends\\LeagueClient.exe";  //chemin d'acc�s d'une application qu'on veut identifier sa version
    char * version_app;

    MYSQL *connection = my_MySQL(); //appel de fonction pour se connecter � MySQL

    myGTK(argc, argv);   //appel de la fonction pour cr�er une fen�tre

    /* Application locale */
    printf("\nYour software: %s", path_app);
    version_app = find_app(path_app);
    if (version_app != NULL) {
            printf("\nYour version: %s", version_app);
            free(version_app);
    }


    mysql_close(connection); //avant d'arr�ter le programme, on arr�te la connexion avec MySQL
    return EXIT_SUCCESS;
}
