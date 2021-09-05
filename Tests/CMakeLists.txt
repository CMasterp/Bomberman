CMAKE_MINIMUM_REQUIRED(VERSION 3.17) # FetchContent is available in 3.17+

# Set the project name and version
PROJECT(test_bomberman VERSION 1.0)

SET(PROJET_DIRECTORY "../")

ENABLE_TESTING()

# Set g++ standard version
SET(CMAKE_CXX_STANDARD 17)

# Make XRay CMakeList meta-compile XRay library that himself
# will make Raylib-cpp meta compile
# It will be linked with our Bomberman project
FILE(COPY ${PROJET_DIRECTORY}/Lib DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})
FILE(COPY ${PROJET_DIRECTORY}/Engine DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})

ADD_SUBDIRECTORY(Lib/XRaylib)

# Generate a list of files
FILE(GLOB_RECURSE SRCS CONFIGURE_DEPENDS
        "${PROJET_DIRECTORY}Engine/Core/*.cpp"
        "${PROJET_DIRECTORY}Game/*.cpp"
        "sources/XRay/*.cpp"
        "sources/Raylib/*.cpp"
        #"sources/Game/*.cpp" Need to edit tests
        )

# Set Headers paths
SET(ENGINE_HEADERS_PATH "${PROJET_DIRECTORY}/Engine/")
SET(GAME_HEADERS_PATH "${PROJET_DIRECTORY}/Game/")
SET(XRAY_HEADERS_PATH "${PROJET_DIRECTORY}/Lib/XRaylib/XRay/includes/")
SET(RAYLIB_HEADERS_PATH "${PROJET_DIRECTORY}/Lib/XRaylib/Raylib/")

# We add this to ensure the CI/CDs don't fetch resources
IF (NOT DEFINED ENV{SKIP_RESOURCES_FETCHING})
    MESSAGE("-- Compile all tests")
ELSE ()
    LIST(REMOVE_ITEM lib_srcs "sources/Raylib/RaylibWindowTests.cpp")
    MESSAGE("-- Skipping windows tests for CI/CD...")
ENDIF ()

# This is the main part:
ADD_EXECUTABLE(${PROJECT_NAME} ${SRCS} ${HEADERS_FILES})

# This part downloads raylib and builds it if it's not installed on your system
TARGET_LINK_LIBRARIES(${PROJECT_NAME} xray) # Specify libraries or flags to use when linking a given target and/or its dependents

######################################################
#                     GOOGLETEST                     #
######################################################

INCLUDE(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
SET(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


# Specify include directories to use when compiling a given target
# PRIVATE keyword ensure a complete compilation beetwin dependencies
TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PRIVATE
        ${ENGINE_HEADERS_PATH}
        ${GAME_HEADERS_PATH}
        ${XRAY_HEADERS_PATH}
        ${RAYLIB_HEADERS_PATH}
        )

######################################################
#                    UNIT TESTS                      #
######################################################

target_link_libraries(
        ${PROJECT_NAME}
        gtest_main
)

include(GoogleTest)
