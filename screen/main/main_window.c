#include "main_window.h"
#include <gtk/gtk.h>
#include "../../socket/server/server.h"
#include "../../socket/client/client.h"

#define SIZE 4

GtkWidget *main_window;
GtkLabel *label;

int window_type;

char questions[SIZE][1000] = {
        "1. First question\nA. Answer A\nB. Answer B\nC. Answer C\nD. Answer D",
        "2. Second question\nA. Answer A\nB. Answer B\nC. Answer C\nD. Answer D",
        "3. Third question\nA. Answer A\nB. Answer B\nC. Answer C\nD. Answer D",
        "4. Fourth question\nA. Answer A\nB. Answer B\nC. Answer C\nD. Answer D",
};

int answers[SIZE] = {0, 1, 4};

int score = 0;

int question = -1;

void main_window_show(int type) {

    window_type = type;

    GtkBuilder *builder = gtk_builder_new_from_file("../screen/main/main_window.glade");

    if (type == SERVER_WINDOW) {
        main_window = GTK_WIDGET(gtk_builder_get_object(builder, "server_window"));
    } else {
        main_window = GTK_WIDGET(gtk_builder_get_object(builder, "client_window"));
        label = (GtkLabel *) gtk_builder_get_object(builder, "question");
        next_question();
    }
    gtk_builder_connect_signals(builder, NULL);

    g_object_unref(builder);
    gtk_widget_show(main_window);
}

void client_window_on_a_clicked() {
    if (answers[question] == 0) {
        score++;
    }
    next_question();
}

void client_window_on_b_clicked() {
    if (answers[question] == 1) {
        score++;
    }
    next_question();
}

void client_window_on_c_clicked() {
    if (answers[question] == 2) {
        score++;
    }
    next_question();
}

void client_window_on_d_clicked() {
    if (answers[question] == 3) {
        score++;
    }
    next_question();
}

void next_question() {
    if (question >= SIZE) {
        return;
    }
    question++;
    gtk_label_set_text(label, questions[question]);
}

void on_window_main_destroy() {
    server_stop();
    client_stop();
    gtk_main_quit();
}