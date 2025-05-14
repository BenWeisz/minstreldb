# Wherever "Configure!" is marked, thats where you have to make changes
# Note: You'll have to create a /src and /include for your .c and .h files respectively
#       Don't worry, I've configured those folders below, but you still have to write your
#       .c files below and run cmake .. from your build dir each time you add a new source file.
cmake_minimum_required(VERSION 3.20)

# Configure! your server exe name
set(SERVER_NAME minstrel-dbs)

# Configure! your lib name
set(LIB_NAME minstrel-dbl)

# Configure! your client name
set(CLIENT_NAME minstrel-dbc)

# Configure! the minstreldb project name
set(MINSTREL_DB_PROJECT_NAME minstrel-db)

# Configure! this as the absolute path to your vendors folder, DO NOT USE RELATIVE PATHS!
set(VENDORS "/Users/bweisz/vendors")
# Configure! this if you want to build for the old intel based apple systems
# set(INTEL_APPLE 1)

# Setting up the project name
project(${MINSTREL_DB_PROJECT_NAME})

###################################
# Configure! the language standard
# Set C standard here (Used in App)
set(CMAKE_C_STANDARD 11)
# set(CMAKE_C_FLAGS "-Wall -fsanitize=address")

# Set C++ standard here (Used in cimgui lib)
set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_CXX_FLAGS "-Wall -fsanitize=address")

# Configuration for Intel based macs
if(APPLE)
    if(DEFINED INTEL_APPLE)
        set(CMAKE_OSX_ARCHITECTURES "x86_64")
    ENDIF()
ENDIF()

###################################

# Configure!
# Common sources go here
set(SERVER_SOURCE_FILES mains.c)
set(LIB_SOURCE_FILES 	mainl.c)
set(CLIENT_SOURCE_FILES mainc.c)

# Configure! Set up the platform dependent sources
if(WIN32)
    # list(APPEND SERVER_SOURCE_FILES src/win32_impl.c)
    # list(APPEND LIB_SOURCE_FILES src/win32_impl.c)
    # list(APPEND CLIENT_SOURCE_FILES src/win32_impl.c)
elseif(APPLE)
    list(APPEND SERVER_SOURCE_FILES src/server/platform/macos/server.c)
    #list(APPEND LIB_SOURCE_FILES 	src/lib/platform/macos/macos_impl.c)
    list(APPEND CLIENT_SOURCE_FILES src/client/platform/macos/client.c)
else() # Linux
    # list(APPEND SERVER_SOURCE_FILES src/linux_impl.c)
    # list(APPEND LIB_SOURCE_FILES src/linux_impl.c)
    # list(APPEND CLIENT_SOURCE_FILES src/linux_impl.c)
endif()

# Add the server executable
add_executable(${SERVER_NAME} ${SERVER_SOURCE_FILES})

# Add the include directory for headers for the server
target_include_directories(${SERVER_NAME} PUBLIC
	include)

# Add the client library
add_library(${LIB_NAME} ${LIB_SOURCE_FILES})

# Add the include directory for headers for the client lib
target_include_directories(${LIB_NAME} PUBLIC
	include)

# Add the client executable
add_executable(${CLIENT_NAME} ${CLIENT_SOURCE_FILES})

# Add the include directory for headers for the client
target_include_directories(${CLIENT_NAME} PUBLIC
	include)

# Add debug mode macro
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(__DEBUG__)
endif()
