/*
** api pour créer une interface graphique avec GTK
** Ludovic & Gabriel
** 20/12/2019
*/

#include <stdlib.h>
#include <gtk/gtk.h>
#include "GTK.h"

void myGTK(int argc, char **argv)
{
    // Variables
    GtkWidget *MainWindow = NULL; //déclaration d'un pointeur sur GtkWidget, correspondra à notre fenêtre
    const gchar *title = "Daemon";           //déclaration d'une char en Glib, correspondra au titre de notre fenêtre
    gint width;             //déclaration de int en Glib, correspondra à la largeur de la fenêtre
    gint height;            //correspondra à la hauteur de la fenêtre
    gint x;         //correspondra à la position x de la fenêtre
    gint y;         //correspondra à la position y de la fenêtre


    // Initialisation de GTK+
    gtk_init(&argc, &argv);


    // Création de la fenêtre
    MainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL); //créer une fenêtre normale
    g_signal_connect(G_OBJECT(MainWindow), "delete-event", G_CALLBACK(gtk_main_quit), NULL); //quitter l'application après clic sur la croix


    //Edition de la fenêtre
    gtk_window_set_title(GTK_WINDOW(MainWindow), title);                //on écrit le titre de la fenêtre
    gtk_window_set_default_size(GTK_WINDOW(MainWindow), 300, 350);      //on configure la taille de la fenêtre par défaut
    gtk_window_set_position(GTK_WINDOW(MainWindow), GTK_WIN_POS_CENTER); //position au centre de l'écran


    //Récupération des informations de l'édition de la fenêtre
    title = gtk_window_get_title(GTK_WINDOW(MainWindow));                   //on récupère le titre de la fenêtre
    gtk_window_get_default_size(GTK_WINDOW(MainWindow), &width, &height); //on récupère les tailles de la fenêtre
    gtk_window_get_position(GTK_WINDOW(MainWindow), &x, &y);              //récupération position



    // Affichage et boucle évènementielle
    gtk_widget_show(MainWindow); //affichage de la fenêtre
    gtk_main();


}
