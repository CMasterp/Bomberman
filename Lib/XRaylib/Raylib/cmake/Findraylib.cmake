# Usage:
# FIND_PACKAGE(raylib REQUIRED)
# [...]
# TARGET_LINK_LIBRARIES(target_name raylib)

CMAKE_MINIMUM_REQUIRED(VERSION 3.17) # FetchContent is available in 3.11+

if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    INCLUDE(FetchContent)

    FetchContent_Declare(
            raylib
            URL https://github.com/raysan5/raylib/archive/refs/tags/3.7.0.tar.gz
    )

    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        SET(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)

        SET(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples

        # build raylib
        ADD_SUBDIRECTORY(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
        SET(raylib_FOUND TRUE)

    endif ()

endif ()