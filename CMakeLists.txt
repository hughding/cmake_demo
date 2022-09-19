cmake_minimum_required(VERSION 3.17)
project(cmake_demo)

set(CMAKE_CXX_STANDARD 11)

####################
# Set OUTPUT Path  #
####################
# By default, all dynamic and static libraries will be placed at ${CMAKE_BINARY_DIR}/lib, #
# while all executables at ${CMAKE_BINARY_DIR}/bin. #
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

OPTION (ENABLE_COVERAGE "Use gcov" OFF)
MESSAGE(STATUS ENABLE_COVERAGE=${ENABLE_COVERAGE})
IF(ENABLE_COVERAGE)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")
ENDIF()

include_directories(./sub)
include_directories(./sub2)
include_directories(./main)

#我们告诉cmake进入这些子目录，然后找到另一个CMakeLists.txt
#add_subdirectory(source_dir [binary_dir] [EXCLUDE_FROM_ALL])
add_subdirectory(./sub)
add_subdirectory(./sub2)
add_subdirectory(./main)

enable_testing()
add_subdirectory(test)