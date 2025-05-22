#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#define LOG_PRINT_INTERNAL( ... ) printf( __VA_ARGS__ )

#ifdef __DEBUG__
    #define LOG_PRINT( ... ) do { \
            LOG_PRINT_INTERNAL( "\e[1;32mLOG:\e[0m | [%s:%d] : ", __FILE__, __LINE__ ); \
            LOG_PRINT_INTERNAL( __VA_ARGS__ ); \
        } while( 0 )
    #define LOG_WARN( ... ) do { \
            LOG_PRINT_INTERNAL( "\e[1;33mWARN:\e[0m | [%s:%d] : ", __FILE__, __LINE__ ); \
            LOG_PRINT_INTERNAL( __VA_ARGS__ ); \
        } while( 0 )
    #define LOG_ERROR( ... ) do { \
            LOG_PRINT_INTERNAL( "\e[1;31mERROR\e[0m | [%s:%d] : ", __FILE__, __LINE__ ); \
            LOG_PRINT_INTERNAL( __VA_ARGS__ ); \
        } while( 0 )
#else
    #define LOG_PRINT( ... ) do { \
            LOG_PRINT_INTERNAL( "\e[1;32mLOG:\e[0m : " ); \
            LOG_PRINT_INTERNAL( __VA_ARGS__ ); \
        } while( 0 )
    #define LOG_WARN( ... )
    #define LOG_ERROR( ... ) do { \
            LOG_PRINT_INTERNAL( "\e[1;31mERROR\e[0m : " ); \
            LOG_PRINT_INTERNAL( __VA_ARGS__ ); \
        } while( 0 )
#endif

#endif // LOG_H
