# cmake_demo
## 环境配置
MinGW安装，bin加入到Path中，使用8.1.0版本
https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/
cmake安装，使用Clion中的cmake，bin加入到Path中

## git module
git submodule add -b v1.8.x https://github.com/google/googletest.git 3rdparty/gtest
git submodule update --init --recursive

git rm -r --cached 3rdparty/gtest

## CMakeLists.txt配置说明
find_path 搜索指定头文件路径。
find_library 搜索指定动态文件路径。

## 单元测试覆盖率
mkdir build
cd build
cmake3 -DENABLE_COVERAGE=ON ..
gmake all
cd ..
lcov -d build -z && lcov -d build -b . --no-external --initial -c -o CMakeGcovSupportInitialCoverage.info
cd build/bin
./unit_tests
cd ../../
lcov -d build -b . --no-external -c -o CMakeGcovSupportCoverage.info
genhtml -o CMakeGcovSupportCoverageReport --prefix='pwd' CMakeGcovSupportInitialCoverage.info CMakeGcovSupportCoverage.info