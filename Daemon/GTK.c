/*
** api pour cr�er une interface graphique avec GTK
** Ludovic & Gabriel
** 20/12/2019
*/

#include <stdlib.h>
#include <gtk/gtk.h>
#include "GTK.h"

void myGTK(int argc, char **argv)
{
    // Variables
    GtkWidget *MainWindow = NULL; //d�claration d'un pointeur sur GtkWidget, correspondra � notre fen�tre
    const gchar *title = "Daemon";           //d�claration d'une char en Glib, correspondra au titre de notre fen�tre
    gint width;             //d�claration de int en Glib, correspondra � la largeur de la fen�tre
    gint height;            //correspondra � la hauteur de la fen�tre
    gint x;         //correspondra � la position x de la fen�tre
    gint y;         //correspondra � la position y de la fen�tre


    // Initialisation de GTK+
    gtk_init(&argc, &argv);


    // Cr�ation de la fen�tre
    MainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL); //cr�er une fen�tre normale
    g_signal_connect(G_OBJECT(MainWindow), "delete-event", G_CALLBACK(gtk_main_quit), NULL); //quitter l'application apr�s clic sur la croix


    //Edition de la fen�tre
    gtk_window_set_title(GTK_WINDOW(MainWindow), title);                //on �crit le titre de la fen�tre
    gtk_window_set_default_size(GTK_WINDOW(MainWindow), 300, 350);      //on configure la taille de la fen�tre par d�faut
    gtk_window_set_position(GTK_WINDOW(MainWindow), GTK_WIN_POS_CENTER); //position au centre de l'�cran


    //R�cup�ration des informations de l'�dition de la fen�tre
    title = gtk_window_get_title(GTK_WINDOW(MainWindow));                   //on r�cup�re le titre de la fen�tre
    gtk_window_get_default_size(GTK_WINDOW(MainWindow), &width, &height); //on r�cup�re les tailles de la fen�tre
    gtk_window_get_position(GTK_WINDOW(MainWindow), &x, &y);              //r�cup�ration position



    // Affichage et boucle �v�nementielle
    gtk_widget_show(MainWindow); //affichage de la fen�tre
    gtk_main();


}
