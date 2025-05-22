#include "util/config.h"

KVFILE* config;

u32 CONFIG_load( const char* path )
{
    char* buf = IO_read_char( path );
    if ( buf == NULL )
    {
        return 0;
    }

    config = KVFILE_read( buf );
    free( buf );

    if ( config == NULL )
    {
        return 0;
    }

    return 1;
}

void CONFIG_cleanup()
{
    KVFILE_free( config );
    config = NULL;
}