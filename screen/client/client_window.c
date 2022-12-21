#include "client_window.h"
#include <gtk/gtk.h>
#include "../../socket/server/server.h"
#include "../../socket/client/client.h"
#include "../result/result_window.h"

#define SIZE 5

GtkWidget *client_window;
GtkWidget *label;

char questions[SIZE][1000] = {
        "1. Which of the following statement is correct?\nA. strcmp(s1, s2) returns a number less than 0 if s1>s2
 \nB. strcmp(s1, s2) returns a number greater than 0 if s1<s2
 \nC. strcmp(s1, s2) returns 0 if s1==s2
 \nD. strcmp(s1, s2) returns 1 if s1==s2",
        "2. Which of the following function sets first n characters of a string to a given character?\nA. strinit()
\nB. strnset()
\nC. strset()
\nD. strcset()",
        "3. #include<stdio.h>

int main()
{
    int a[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    printf("%u, %u, %u\n", a[0]+1, *(a[0]+1), *(*(a+0)+1));
    return 0;
}\nA. 448, 4, 4
\nB. 520, 2, 2
\nC. 1006, 2, 2
\nD. Error",
        "4. #include<stdio.h>

int main()
{
    struct value
    {
        int bit1:1;
        int bit3:4;
        int bit4:4;
    }bit;
    printf("%d\n", sizeof(bit));
    return 0;
}\nA. 1\nB. 2\nC. 4\nD. 9",
  "5.	
What will be the output of the program? \n#include<stdio.h>

int main()
{
    typedef int arr[5];
    arr iarr = {1, 2, 3, 4, 5};
    int i;
    for(i=0; i<4; i++)
        printf("%d,", iarr[i]);
    return 0;
}\nA. 1, 2, 3, 4
 \nB. 1, 2, 3, 4, 5
 \nC. No output
 \nD. Error: Cannot use typedef with an array"
};

int answers[SIZE] = {3, 2, 3, 2, 1};

int score = 0;

int question = -1;

char *username;

void client_window_show(char *name) {

    username = name;

    GtkBuilder *builder = gtk_builder_new_from_file("../screen/client/client_window.glade");

    client_window = GTK_WIDGET(gtk_builder_get_object(builder, "client_window"));
    label = GTK_WIDGET(gtk_builder_get_object(builder, "question"));

    next_question();

    gtk_builder_connect_signals(builder, NULL);

    g_object_unref(builder);
    gtk_widget_show((GtkWidget *) client_window);
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
    if (question + 1 >= SIZE) {
        gtk_widget_hide((GtkWidget *) client_window);
        result_window_show(score, SIZE);
        client_send_result(username, score, SIZE);
        return;
    }
    question++;
    gtk_label_set_text(GTK_LABEL(label), questions[question]);
}

void on_window_main_destroy() {
    server_stop();
    client_stop();
    gtk_main_quit();
}