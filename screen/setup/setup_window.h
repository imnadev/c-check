#ifndef C_CHECK_SETUP_WINDOW_H
#define C_CHECK_SETUP_WINDOW_H

/*
 * Called from client(), just opens the setup client_window.
 * Writes server ip and port number on screen
 */
void setup_window_show();

/*
 * Called from glade when serve button clicked.
 * Inits server.h with user details
 * Opens client_window as server on success
 */
void setup_window_on_serve_clicked();

/*
 * Called from glade when connect button clicked.
 * Inits client.h with server details
 * Sends user details to server
 * Opens client_window as client on success
 */
void setup_window_on_connect_clicked();

#endif