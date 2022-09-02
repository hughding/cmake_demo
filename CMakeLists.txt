cmake_minimum_required(VERSION 3.17)
project(cmake_demo)

set(CMAKE_CXX_STANDARD 11)

include_directories(./sub)

add_subdirectory(sub)

add_executable(cmake_demo main.cpp)

target_link_libraries(cmake_demo sub)