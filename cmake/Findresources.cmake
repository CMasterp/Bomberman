# Specify the CMake version
CMAKE_MINIMUM_REQUIRED(VERSION 3.17)

MESSAGE("Searching for resources updates...")

# Download the last log from the resources' server
FILE(DOWNLOAD http://51.77.221.38:8080/last.log .last.log)

# Check for new updates by comparing the local timestamp and the server timestamp
EXECUTE_PROCESS( COMMAND ${CMAKE_COMMAND} -E compare_files
  "${CMAKE_CURRENT_SOURCE_DIR}/resources/.last.log"
  "${CMAKE_CURRENT_SOURCE_DIR}/build/.last.log"
                 RESULT_VARIABLE compare_result
)

# If the 2 timestamps are the same, so there's nothing to update
IF( compare_result EQUAL 0)
    MESSAGE("No update detected...")
    FILE(REMOVE ${CMAKE_CURRENT_SOURCE_DIR}/build/.last.log)
# Otherwise (if the timestamp are different are even the local timestamp doesn't exist yet),
# so we have to update
ELSE()
    MESSAGE("Need to be updated !")

    # Download the resources as a compressed tar.gz file
    FILE(DOWNLOAD http://51.77.221.38:8080/resources.tar.gz resources.tar.gz SHOW_PROGRESS)

    # Create build directory
    FILE(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/build)

    # Uncompress the resource.tar.gz
    EXECUTE_PROCESS(
      COMMAND ${CMAKE_COMMAND} -E tar xzvf resources.tar.gz
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build
    )

    # Remove the old resources, then replace by the new resources and set the new timestamp
    FILE(REMOVE_RECURSE ${CMAKE_CURRENT_SOURCE_DIR}/resources)
    FILE(RENAME ${CMAKE_CURRENT_SOURCE_DIR}/build/resources ${CMAKE_CURRENT_SOURCE_DIR}/resources)
    FILE(RENAME ${CMAKE_CURRENT_SOURCE_DIR}/build/.last.log ${CMAKE_CURRENT_SOURCE_DIR}/resources/.last.log)

ENDIF()