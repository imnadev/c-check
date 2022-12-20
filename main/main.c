#include <gtk/gtk.h>
#include "../screen/setup/setup_window.h"

int main(int argc, char *argv[]) {

    //Init GTK3, a library to draw UI in C
    gtk_init(&argc, &argv);

    setup_window_show();
    return 0;
}
