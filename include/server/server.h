#ifndef SERVER_H
#define SERVER_H

#include "util/types.h"
#include "util/config.h"
#include "util/log.h"

#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h> // macos?

/*
    Startup the server.
*/
i32 SERVER_start( const char* port, i32 backlog );

/*
    Close the server.
*/
void SERVER_close( i32 fd );

#endif // SERVER_H
