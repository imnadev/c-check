#ifndef C_CHECK_SERVER_H
#define C_CHECK_SERVER_H

/*
 * Creates a new socket.
 * Starts a new thread to listen to connections.
 */
int server_init();

/*
 * Stops the server and listening to clients
 */
void server_stop();

#endif
