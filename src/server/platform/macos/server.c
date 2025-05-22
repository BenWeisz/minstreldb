#include "server/server.h"

#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

i32 SERVER_start()
{
	struct addrinfo setup_info;
	memset(&setup_info, 0, sizeof(struct addrinfo));
	setup_info.ai_family = PF_UNSPEC;
	setup_info.ai_socktype = SOCK_STREAM;
	setup_info.ai_flags = AI_PASSIVE;

	struct addrinfo* connection_infos = NULL;
	int status = getaddrinfo(NULL, "3490", &setup_info, &connection_infos);
	if (status != 0)
	{
		printf("getaddrinfo error: %s\n", gai_strerror(status));
		return false;
	}

	freeaddrinfo(connection_infos);

	return true;
}
