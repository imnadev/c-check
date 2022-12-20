#include "setup_window.h"
#include <gtk/gtk.h>
#include "../../socket/server/server.h"
#include "../../socket/client/client.h"
#include "../server/server_window.h"
#include "../client/client_window.h"
#include "../../struct/constants.h"

GtkWidget *setup_window;
char ip[16] = "127.0.0.1";
char name[100] = "";
int port = 8877;

void setup_window_show() {
    GtkBuilder *builder = gtk_builder_new_from_file("../screen/setup/setup_window.glade");
    setup_window = GTK_WIDGET(gtk_builder_get_object(builder, "setup_window"));
    gtk_builder_connect_signals(builder, NULL);

    g_object_unref(builder);
    gtk_widget_show(setup_window);

    gtk_main();
}

void setup_window_on_serve_clicked() {
    if (server_init() == FAILURE) {
        //TODO show error client_window
        gtk_main_quit();
    } else {
        gtk_widget_hide(setup_window);
        server_window_show();
    }
}

void setup_window_on_connect_clicked() {
    if (client_init(ip, port) == FAILURE) {
        //TODO show error client_window
        gtk_main_quit();
    } else {
        gtk_widget_hide(setup_window);

        client_window_show(name);
    }
}

void get_text(GtkEntry *e) {
    sprintf(ip, "%s", gtk_entry_get_text(e));
}

void get_name(GtkEntry *e) {
    sprintf(name, "%s", gtk_entry_get_text(e));
}

void get_port(GtkEntry *e) {
    char portChar[6];
    sprintf(portChar, "%s", gtk_entry_get_text(e));
    port = atoi(portChar);
}

void on_window_setup_destroy() {
    gtk_main_quit();
}
