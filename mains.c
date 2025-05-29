#include <stdio.h>
#include <stdlib.h>

#include "util/log.h"
#include "util/resource.h"
#include "util/types.h"
#include "util/config.h"
#include "server/server.h"

int main()
{
	// Load the config file
	KVFILE* config = CONFIG_load( RESOURCE( "config.txt" ) );
	if ( config == NULL )
	{
		LOG_ERROR( "CONFIG_load\n" );
		return 1;
	}

	const char* port = KVFILE_get( config, "PORT" );
    LOG_PRINT("Starting server...\n");
	LOG_PRINT( "PORT: %s\n", port );

	// Get the backlog size
	const char* backlog_str = KVFILE_get( config, "BACKLOG" );
	i32 backlog = 10;
	if ( backlog_str == NULL )
	{
		LOG_WARN( "No BACKLOG config variable found, defaulting to 10\n" );
	}
	else 
	{
		backlog = atoi( backlog_str );
	}

	// Start server
	i32 fd = SERVER_start( port, backlog );
	if ( fd == -1 )
	{
		LOG_ERROR( "SERVER_start\n" );
		LOG_PRINT( "Shutting down...\n" );
	
		// Clean up config file
		CONFIG_cleanup( config );
		return 1;
	}

	// Close server
	SERVER_close( fd );

	// Clean up config file
	CONFIG_cleanup( config );

	return 0;
}
