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
    char *path_app;  //chemin d'acc�s d'une application qu'on veut identifier sa version
    char *name_exe; //nom de l'ex�cutable
    char *version_app; //contiendra la version d'une application

    MYSQL *connection = my_MySQL(); //appel de fonction pour se connecter � MySQL

    myGTK(argc, argv);   //appel de la fonction pour cr�er une fen�tre


    //chemin amenant l'appli
    path_app = "C:\\Riot Games\\League of Legends\\LeagueClient.exe";

    //fichier de l'ex�cutable
    name_exe = find_exe_app(path_app); //appel de la fonction pour rechercher le nom du fichier ex�cutable en fonction du chemin choisi
    if(strcmp(name_exe, "not_exec") == 0) return 1; //on v�rifie si c'est bien un fichier ex�cutable

    //version de l'appli
    version_app = find_version_app(path_app); //appel de la fonction pour trouver une version


    //nom de l'appli
    char name[100]; //L'utilisateur devra �crire le nom de son application
    printf("\nWhat is the name of your application?\nYour response:");
    fflush(stdin);
    fgets(name, 99, stdin);
    if(name[strlen(name) - 1] == '\n') name[strlen(name) - 1] = '\0'; //on enl�ve le retour � la ligne

    /* AJOUT D'UNE APPLICATION */
    if (version_app != NULL && path_app != NULL && name != NULL && name_exe != NULL && connection != NULL)
            add_app_MySQL(path_app, version_app, name, name_exe, connection); //appel de la fonction pour ajouter les infos de l'appli dans la base de donn�e

    free(version_app);
    free(name_exe);

    display_app_MySQL(connection); //appel de la fonction pour afficher toutes les applications choisies


    mysql_close(connection); //avant d'arr�ter le programme, on arr�te la connexion avec MySQL
    return EXIT_SUCCESS;
}
