cmake_minimum_required(VERSION 3.17)
project(cmake_demo)

set(CMAKE_CXX_STANDARD 11)

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