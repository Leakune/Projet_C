/*
** Application : Daemon
** Ludovic & Gabriel
** 20/12/2012
*/

#include <stdlib.h>
#include <stdio.h>
#include "MySQL.h"
#include "GTK.h"

int main(int argc, char **argv)
{
    MYSQL *connection = my_MySQL(); //appel de fonction pour se conencter � MySQL

    myGTK(argc, argv);   //appel de la fonction pour cr�er une fen�tre

    mysql_close(connection); //avant d'arr�ter le programme, on arr�te la connexion avec MySQL

    return EXIT_SUCCESS;
}
