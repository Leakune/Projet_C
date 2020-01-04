/*
** Application : Daemon
** Ludovic & Gabriel
** 20/12/2019
*/

#include <stdlib.h>
#include <stdio.h>
#include "MySQL.h"
#include "GTK.h"
#include "find_app.h"

#define END 4
int main(int argc, char **argv)
{
    int choice;//Choix d'une option
    char *path_app;  //chemin d'accès d'une application qu'on veut identifier sa version
    char *name_exe; //nom de l'exécutable
    char exe_to_delete[50];
    char *version_app; //contiendra la version d'une application

    MYSQL *connection = my_MySQL(); //appel de fonction pour se connecter à MySQL

    myGTK(argc, argv);   //appel de la fonction pour créer une fenêtre

    printf("\n**************** Welcome! ****************\n");
    do{
        printf("\nWhat do you want? Tap a digit in order to do the corresponding instructions:\n"
               "1/ Add a software to know its current version.\n"
               "2/ Display the list of your chosen applications.\n"
               "3/ Remove a software from the list.\n"
               "4/ Quit the program.\n");

        scanf("%d", &choice);

        switch(choice){
            /* AJOUT D'UNE APPLICATION */
            case 1:
                //chemin amenant l'appli
                path_app = "C:\\Riot Games\\League of Legends\\LeagueClient.exe";

                //fichier de l'exécutable
                name_exe = find_exe_app(path_app); //appel de la fonction pour rechercher le nom du fichier exécutable en fonction du chemin choisi
                if(strcmp(name_exe, "not_exec") == 0) return 1; //on vérifie si c'est bien un fichier exécutable

                //version de l'appli
                version_app = find_version_app(path_app); //appel de la fonction pour trouver une version


                //nom de l'appli
                char name[100]; //L'utilisateur devra écrire le nom de son application
                printf("\nWhat is the name of your application?\nYour response:");
                fflush(stdin);
                fgets(name, 99, stdin);
                if(name[strlen(name) - 1] == '\n') name[strlen(name) - 1] = '\0'; //on enlève le retour à la ligne

                if (version_app != NULL && path_app != NULL && name != NULL && name_exe != NULL && connection != NULL)
                    add_app_MySQL(path_app, version_app, name, name_exe, connection); //appel de la fonction pour ajouter les infos de l'appli dans la base de donnée

                free(version_app);
                free(name_exe);
                break;

            /* AFFICHAGE DE LA LISTE DES APPLICATIONS */
            case 2:
                display_app_MySQL(connection); //appel de la fonction pour afficher toutes les applications choisies
                break;

            /* SUPPRESION D'UNE APPLICATION */

            case 3:
                printf("Select the software to delete:\n");
                fflush(stdin);
                fgets(exe_to_delete, 48, stdin);
                if(exe_to_delete[strlen(exe_to_delete) - 1] == '\n') exe_to_delete[strlen(exe_to_delete) - 1] = '\0';
                printf("%s", exe_to_delete);
                delete_app_MySQL(exe_to_delete, connection);
                break;

            /* FIN DE L'UTILISATION DU LOGICIEL DAEMON */
            case END:
                printf("You have chosen to quit. See you soon!\n");
                break;

            /* ERREUR LORS DU CHOIX */
            default:
                printf("Wrong answer, please choose a right one!\n");
                break;
        }

    }
    while(choice != END);

    mysql_close(connection); //avant d'arrêter le programme, on arrête la connexion avec MySQL
    return EXIT_SUCCESS;
}
