#include <stdio.h>

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

	i32 r = SERVER_start( port );
	if ( r == -1 )
	{
		LOG_ERROR( "SERVER_start\n" );
		LOG_PRINT( "Shutting down...\n" );
	}

	// Clean up config file
	CONFIG_cleanup( config );

	return 0;
}
