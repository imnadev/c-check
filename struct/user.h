#ifndef C_CHECK_USER_H
#define C_CHECK_USER_H

#include <stdbool.h>

typedef struct User User;

struct User {
    int id;

    char *name;

    char *password;

    char *address;

    int server_id;
};

#endif
