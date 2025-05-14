#include "client/client.h"

#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

bool CLIENT_start()
{
    struct addrinfo setup_info;
    memset(&setup_info, 0, sizeof(struct addrinfo));
    setup_info.ai_family = PF_UNSPEC;
    setup_info.ai_socktype = SOCK_STREAM;

    struct addrinfo* connection_infos;
    int status = getaddrinfo("127.0.0.1", "3490", &setup_info, &connection_infos);
    if (status != 0)
    {
        printf("getaddrinfo error: %s\n", gai_strerror(status));
        return false;
    }

    freeaddrinfo(connection_infos);

    return true;
}