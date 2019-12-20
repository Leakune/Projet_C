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
    MYSQL *connection = my_MySQL(); //appel de fonction pour se conencter à MySQL

    myGTK(argc, argv);   //appel de la fonction pour créer une fenêtre

    mysql_close(connection); //avant d'arrêter le programme, on arrête la connexion avec MySQL

    return EXIT_SUCCESS;
}
