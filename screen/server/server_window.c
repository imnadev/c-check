#include <gtk/gtk.h>
#include "server_window.h"
#include "../../database/database.h"

GtkWindow *server_window;
GtkLabel *results_label;

void server_window_show() {
    GtkBuilder *builder = gtk_builder_new_from_file("../screen/server/server_window.glade");

    server_window = GTK_WIDGET(gtk_builder_get_object(builder, "server_window"));
    results_label = GTK_LABEL(gtk_builder_get_object(builder, "results_label"));

    gtk_builder_connect_signals(builder, NULL);

    g_object_unref(builder);
    gtk_widget_show((GtkWidget *) server_window);

    server_window_refresh();
}

void server_window_refresh() {
    char *results = database_read();
    gtk_label_set_text(results_label, results);
}