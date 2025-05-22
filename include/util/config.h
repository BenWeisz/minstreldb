#ifndef CONFIG_H
#define CONFIG_H

#include <stdlib.h>

#include "util/types.h"
#include "util/io.h"
#include "util/kvfile.h"

extern KVFILE* config;

KVFILE* CONFIG_load( const char* path );
void CONFIG_cleanup( KVFILE* config );

#endif // CONFIG_H