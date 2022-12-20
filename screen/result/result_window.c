#include "result_window.h"
#include <gtk/gtk.h>


GtkWidget *result_window;

void result_window_show(int score, int total) {

    GtkBuilder *builder = gtk_builder_new_from_file("../screen/result/result_window.glade");

    result_window = GTK_WIDGET(gtk_builder_get_object(builder, "result_window"));

    GtkLabel *label = GTK_LABEL(gtk_builder_get_object(builder, "scoreText"));
    char *message = (char *) malloc(100 * sizeof(char));
    sprintf(message, "Scored %d out of %d", score, total);
    gtk_label_set_text(label, message);

    gtk_builder_connect_signals(builder, NULL);

    g_object_unref(builder);
    gtk_widget_show(result_window);
}

void result_window_closed() {
    gtk_main_quit();
}