#ifndef C_CHECK_CLIENT_WINDOW_H
#define C_CHECK_CLIENT_WINDOW_H

/*
 * Called from setup_window with above SERVER_WINDOW and CLIENT_WINDOW values as type
 * Draws the client_window according to the type
 * Gets users list from server.h or client.h
 * Sets client_window text as 'Connected to'/'Serving at' 192.168.0.123:8080
 */
void client_window_show(char *name);

void client_window_on_a_clicked();
void client_window_on_b_clicked();
void client_window_on_c_clicked();
void client_window_on_d_clicked();

void next_question();

#endif
