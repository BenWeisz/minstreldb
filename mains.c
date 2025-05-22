#include <stdio.h>

#include "util/log.h"
#include "util/resource.h"
#include "util/types.h"
#include "util/config.h"
#include "server/server.h"

int main()
{
	// Load the config file
	u32 r = CONFIG_load( RESOURCE( "config.txt" ) );
	if ( r == 0 )
	{
		LOG_ERROR( "CONFIG_load\n" );
		return 1;
	}

    printf("Starting server...\n");

	SERVER_start();

	// Clean up config file
	CONFIG_cleanup();

	return 0;
}
