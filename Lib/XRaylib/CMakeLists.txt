# CMakeLists.txt

# Always set the cmake min version.
CMAKE_MINIMUM_REQUIRED(VERSION 3.17)

# Set the project version 1.0 for example
SET(PROJECT_VERSION "1.0")

# Set the variable PROJ_NAME to whatever your library's name is, PROJECT_VERSION should be a version string like "0.1"
PROJECT(xray VERSION ${PROJECT_VERSION})

# Set g++ standard version
SET(CMAKE_CXX_STANDARD 17)

# Find globaly and recursively all source files required to compile the project
FILE(GLOB_RECURSE XRAY_SRCS CONFIGURE_DEPENDS
        "${PROJECT_SOURCE_DIR}/XRay/sources/*.cpp"
        )

# Make Raylib CMakeList meta-compile raylib-cpp library
# It will be linked with our XRay library project
ADD_SUBDIRECTORY(Raylib)

# Set Headers paths
SET(RAYLIB_HEADERS_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Raylib/")
SET(ENGINE_HEADERS_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../Engine/")
SET(XRAY_HEADERS_PATH "${CMAKE_CURRENT_SOURCE_DIR}/XRay/includes/")

# Create our static library target
ADD_LIBRARY(${PROJECT_NAME} STATIC ${XRAY_SRCS})

# Link raylib-cpp library to our raylib-cpp project
TARGET_LINK_LIBRARIES(${PROJECT_NAME} raylibCPP)

# Add headers path to our project
TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PRIVATE
        ${RAYLIB_HEADERS_PATH}
        ${ENGINE_HEADERS_PATH}
        ${XRAY_HEADERS_PATH}
        )

# Active in debug environment or hidden in release
#TARGET_COMPILE_OPTIONS(xray PRIVATE -g3 -lstdc++fs)
