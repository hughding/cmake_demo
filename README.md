# cmake_demo
环境配置
MinGW安装，bin加入到Path中，使用8.1.0版本
https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/

cmake安装，使用Clion中的cmake，bin加入到Path中

git submodule add -b v1.8.x https://github.com/google/googletest.git 3rdparty/gtest
git submodule update --init --recursive

git rm -r --cached 3rdparty/gtest

find_path 搜索指定头文件路径。
find_library 搜索指定动态文件路径。