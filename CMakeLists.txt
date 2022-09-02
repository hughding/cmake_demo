cmake_minimum_required(VERSION 3.17)
project(cmake_demo)

set(CMAKE_CXX_STANDARD 11)

include_directories(./sub)
include_directories(./sub2)

add_subdirectory(sub)
add_subdirectory(sub2)

add_executable(cmake_demo main.cpp)

target_link_libraries(cmake_demo sub sub2)