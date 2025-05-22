#include "util/config.h"

KVFILE* CONFIG_load( const char* path )
{
    char* buf = IO_read_char( path );
    if ( buf == NULL )
    {
        return NULL;
    }

    KVFILE* config = KVFILE_read( buf );
    free( buf );

    if ( config == NULL )
    {
        return NULL;
    }

    return config;
}

void CONFIG_cleanup( KVFILE* config )
{
    KVFILE_free( config );
}