#ifndef C_CHECK_CLIENT_H
#define C_CHECK_CLIENT_H

#include "../../struct/user.h"
#include "../../struct/constants.h"

int client_init(
        char *ip,
        int port
);

void client_stop();

#endif
