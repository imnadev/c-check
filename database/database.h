#ifndef C_CHECK_DATABASE_H
#define C_CHECK_DATABASE_H

/*
 * Inserts the entry to the end of database.
 * Called when a new score is received from a client.
 */
void database_insert(char *entry);

/*
 * Reads all data from the database and returns as one string.
 * Called when the server_window is opened or refreshed.
 */
char *database_read();

#endif