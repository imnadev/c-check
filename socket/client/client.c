#include "client.h"
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <stdlib.h>

int sock = 0;
struct sockaddr_in serv_addr;
char client_buffer[1024] = {0};

int client_listening = FALSE;


_Noreturn void *listen_to_server(void *a) {
    while (client_listening) {
        memset(client_buffer, 0, sizeof(client_buffer));

        read(sock, client_buffer, 1024);
    }
}

int client_init(char *ip, int port) {
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        return FAILURE;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, ip, &serv_addr.sin_addr) <= 0) {
        return FAILURE;
    }

    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        return FAILURE;
    }

    client_listening = TRUE;
    pthread_t my_thread;
    pthread_create(&my_thread, NULL, listen_to_server, NULL);

    return SUCCESS;
}

void client_get_question(int index) {

}

void client_stop() {
    if (client_listening == TRUE) {
        client_listening = FALSE;
    }
}