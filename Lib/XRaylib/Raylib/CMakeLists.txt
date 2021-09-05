# This CMakeLists.txt meta-compile our raylib-c encapsulation
# Export : libraylib-cpp.a

# Always set the cmake min version.
CMAKE_MINIMUM_REQUIRED(VERSION 3.17)

# Set the project version 1.0 for example
SET(PROJECT_VERSION "1.0")

# Set the variable PROJ_NAME to whatever your library's name is, PROJECT_VERSION should be a version string like "0.1"
PROJECT(raylibCPP VERSION ${PROJECT_VERSION})

# Set g++ standard version
SET(CMAKE_CXX_STANDARD 17)

# Add cmake modules folder to cmake path
LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
# Set this to the minimal version you want to support
FIND_PACKAGE(raylib 3.7) # Let CMake search for a raylib-config.cmake

# Find globaly and recursively all source files required to compile the project
FILE(GLOB_RECURSE RAYLIB_SRCS CONFIGURE_DEPENDS
        "${PROJECT_SOURCE_DIR}/*.cpp"
        )

# Set Raylib Headers path
SET(RAYLIB_HEADERS_PATH "${CMAKE_CURRENT_SOURCE_DIR}/")
SET(ENGINE_HEADERS_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../Engine/")

# Create our static library target
ADD_LIBRARY(${PROJECT_NAME} STATIC ${RAYLIB_SRCS})

# Link raylib-c library to our raylib-cpp project
TARGET_LINK_LIBRARIES(${PROJECT_NAME} raylib)

# Add Raylib headers path to our project
TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PRIVATE
        ${RAYLIB_HEADERS_PATH}
        ${ENGINE_HEADERS_PATH}
        )

# Active in debug environment or hidden in release
#TARGET_COMPILE_OPTIONS(raylibCPP PRIVATE -g3)