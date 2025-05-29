#include "server/server.h"

i32 SERVER_start( const char* port, i32 backlog )
{
	struct addrinfo setup_info;
	memset(&setup_info, 0, sizeof(struct addrinfo));

	setup_info.ai_family = PF_UNSPEC;
	setup_info.ai_socktype = SOCK_STREAM;
	setup_info.ai_flags = AI_PASSIVE;

	// Get the list of valid addrinfo structs
	struct addrinfo* infos = NULL;
	int status = getaddrinfo( NULL, port, &setup_info, &infos );
	if ( status != 0 || infos == NULL )
	{
		LOG_ERROR( "getaddrinfo: %s\n", gai_strerror( status ) );
		return -1;
	}

	// Pick a valid addrinfo struct
	struct addrinfo* info = &( infos[0] );
	while ( info != NULL )
	{
		if ( info->ai_socktype == SOCK_STREAM )
		{
			break;
		}
		info = info->ai_next;
	}

	// Open a socket with the chosen addrinfo
	i32 fd = socket( info->ai_family, info->ai_socktype, info->ai_protocol );
	if ( fd == - 1 )
	{
		LOG_ERROR( "socket\n" );
		perror( "socket error" );

		freeaddrinfo( infos );
		return -1;
	}

	// Bind the socket to port
	i32 r = bind( fd, info->ai_addr, info->ai_addrlen );
	if ( r == -1 )
	{
		LOG_ERROR( "bind\n" );
		perror( "bind error" );

		close( fd );
		freeaddrinfo( infos );
		return -1;
	}

	// Listen on the socket
	r = listen( fd, backlog );
	if ( r == -1 )
	{
		LOG_ERROR( "listen\n" );
		perror( "listen error" );
		
		close( fd );
		freeaddrinfo( infos );
		return -1;
	}
	
	freeaddrinfo( infos );

	return fd;
}

void SERVER_close( i32 fd )
{
	int r = close( fd );
	if ( r == -1 )
	{
		LOG_ERROR( "close\n" );
		perror( "close error" );
	}
}