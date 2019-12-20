/*

Pack GTK+ v2.10.12

© Im@GinE - Tous droits réservés

Code Source du Programme du Pack

*/

#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

int main(int argc, char **argv)
{
    /* Variables */
    GtkWidget *pWindow;
    GtkWidget *pVBox;
	GtkWidget *pLabel;
	GtkWidget *pBouton;
	gchar* sUtf8;

    /* Initialisation de GTK+ */
    gtk_init(&argc, &argv);

    /* Création de la Fenêtre */
    pWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(pWindow), 210, 135);
    gtk_window_set_title(GTK_WINDOW(pWindow), "Pack GTK+ 2.10");
	gtk_window_set_position(GTK_WINDOW(pWindow), GTK_WIN_POS_CENTER);
    g_signal_connect(G_OBJECT(pWindow), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* VBox */
    pVBox = gtk_vbox_new(FALSE, 0);
    gtk_container_add(GTK_CONTAINER(pWindow), pVBox);

    /* Label */
	sUtf8 = g_locale_to_utf8("\n    Pack GTK+ 2.10 \n \n       by Im@GinE \n \nwww.siteduzero.com", -1, NULL, NULL, NULL);
    pLabel = gtk_label_new(sUtf8);
    g_free(sUtf8);
	gtk_container_add(GTK_CONTAINER(pVBox), pLabel);

	/* Bouton */
	pBouton = gtk_button_new_with_label("Merci JRG Soft !");
	gtk_box_pack_start(GTK_BOX(pVBox), pBouton, TRUE, FALSE, 0);
	g_signal_connect(G_OBJECT(pBouton), "clicked", G_CALLBACK(gtk_exit), NULL);
	gtk_container_set_border_width(GTK_CONTAINER(pBouton), 20);

	/* Affichage des Widgets */
    gtk_widget_show_all(pWindow);

	/* Quitte GTK+ */
    gtk_main();

    return EXIT_SUCCESS;
}
