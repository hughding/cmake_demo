cmake_minimum_required(VERSION 3.17)
project(test)

set(CMAKE_CXX_STANDARD 11)

include_directories(../sub)
include_directories(../sub2)

#我们告诉cmake进入这些子目录，然后找到另一个CMakeLists.txt
#add_subdirectory(source_dir [binary_dir] [EXCLUDE_FROM_ALL])
add_subdirectory(../sub ./sub)
add_subdirectory(../sub2 ./sub2)

add_executable(test main.cpp)

target_link_libraries(test sub sub2)
enable_testing()