#ifndef C_CHECK_CLIENT_H
#define C_CHECK_CLIENT_H

int client_init(
        char *ip,
        int port
);

void client_stop();

void client_send_result(char *name, int score, int total);

#endif
