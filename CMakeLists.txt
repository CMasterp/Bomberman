CMAKE_MINIMUM_REQUIRED(VERSION 3.17) # FetchContent is available in 3.17+

# Set the project name and version
PROJECT(bomberman VERSION 1.0)

# Set g++ standard version
SET(CMAKE_CXX_STANDARD 17)

# We add this to ensure the CI/CDs don't fetch resources
IF (NOT DEFINED ENV{SKIP_RESOURCES_FETCHING})
    # Call the Findresources module
    INCLUDE(cmake/Findresources.cmake)
ELSE ()
    MESSAGE("Skipping resources fetching...")
ENDIF ()

# Make XRay CMakeList meta-compile XRay library that himself
# will make Raylib-cpp meta compile
# It will be linked with our Bomberman project
ADD_SUBDIRECTORY(Lib/XRaylib)

# Generate a list of files
FILE(GLOB_RECURSE SRCS CONFIGURE_DEPENDS
        "Engine/*.cpp"
        "Game/*.cpp"
        )

# Set Headers paths
SET(ENGINE_HEADERS_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Engine/")
SET(GAME_HEADERS_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Game/")
SET(XRAY_HEADERS_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Lib/XRaylib/XRay/includes/")
SET(RAYLIB_HEADERS_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Lib/XRaylib/Raylib/")
FIND_PACKAGE(Threads REQUIRED)

# This is the main part:
ADD_EXECUTABLE(${PROJECT_NAME} ${SRCS} ${HEADERS_FILES})
# This part downloads raylib and builds it if it's not installed on your system
TARGET_LINK_LIBRARIES(${PROJECT_NAME} xray) # Specify libraries or flags to use when linking a given target and/or its dependents
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT}) # Specify libraries or flags to use when linking a given target and/or its dependents

# Specify include directories to use when compiling a given target
# PRIVATE keyword ensure a complete compilation beetwin dependencies
TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PRIVATE
        ${ENGINE_HEADERS_PATH}
        ${GAME_HEADERS_PATH}
        ${XRAY_HEADERS_PATH}
        ${RAYLIB_HEADERS_PATH}
        )

# Active in debug environment or hidden in release
#TARGET_COMPILE_OPTIONS(bomberman PRIVATE -g3)

# That's it! You should have an bomberman executable that you can run. Have fun!
