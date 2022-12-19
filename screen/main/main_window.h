#ifndef C_CHECK_CLIENT_WINDOW_H
#define C_CHECK_CLIENT_WINDOW_H


#define SERVER_WINDOW 0
#define CLIENT_WINDOW 1

/*
 * Called from setup_window with above SERVER_WINDOW and CLIENT_WINDOW values as type
 * Draws the main_window according to the type
 * Gets users list from server.h or client.h
 * Sets main_window text as 'Connected to'/'Serving at' 192.168.0.123:8080
 */
void main_window_show(int type);

void client_window_on_a_clicked();
void client_window_on_b_clicked();
void client_window_on_c_clicked();
void client_window_on_d_clicked();

void next_question();

#endif
