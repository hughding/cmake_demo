# cmake_demo
## 环境配置
MinGW安装，bin加入到Path中，使用8.1.0版本，x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0.7z
https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/
cmake安装，使用Clion中的cmake，bin加入到Path中
linux中的make，在MinGW中为mingw32-make

##开发工具
Clion配置远程开发(Full Remote Mode)
1.配置ToolChains，Remote（注意Cmake选择cmake3的bin）
2.配置Cmake使用Remote ToolChains
3.配置Deployment中Mappings的Deployment path
4.Cmkae后，使用Deployment工具下载ebs_essd/src/proto文件夹（因为Cmake后,生成了proto的c++代码，需要下载下来供Clion使用）
5.Settings->Languages&Frameworks->Protocol Buffers

## git module
git submodule add -b v1.8.x https://github.com/google/googletest.git 3rdparty/gtest
git submodule update --init --recursive

git rm -r --cached 3rdparty/gtest

## CMakeLists.txt配置说明
引入第3方包，一般在/usr/include/,/usr/lib/,/usr/lib64/,/usr/local/include/,/usr/local/lib/,/usr/local/lib64/
find_path 搜索指定头文件路径。
find_library 搜索指定静态、动态链接库路径。

## 单元测试覆盖率
mkdir build && cd build
cmake3 -DENABLE_COVERAGE=ON ..
gmake unittest-volumemanager -j9
cd .. && lcov -d build -z && lcov -d build -b . --no-external --initial -c -o CMakeGcovSupportInitialCoverage.info
./build/bin/unittest-volumemanager
lcov -d build -b . --no-external -c -o CMakeGcovSupportCoverage.info
genhtml -o CMakeGcovSupportCoverageReport --prefix='pwd' CMakeGcovSupportInitialCoverage.info CMakeGcovSupportCoverage.info
此时会生成CMakeGcovSupportCoverageReport文件夹，打开文件夹中的index.html，即可看到代码覆盖率
zip -r CMakeGcovSupportCoverageReport.zip CMakeGcovSupportCoverageReport

## protobuf 2.5.0库安装
https://github.com/protocolbuffers/protobuf/releases?page=11
protoc-2.5.0-win32.zip protoc.exe所在目录添加到Path中
protobuf-2.5.0.zip

## cmake


## 3rdparty介绍
### mockcpp
注释掉mockcpp.h中的static_assert定义，因为C++11已经引入，无需再次定义。
安装，直接执行make install，安装是静态链接库
安装动态链接库src/CMakeLists.txt中的ADD_LIBRARY(mockcpp STATIC ${MOCKCPP_SRCS}) STATIC改为SHARED，添加LIBRARY DESTINATION lib到install项。cmake后，make install
/usr/local/include/mockcpp/
/usr/local/lib/libmockcpp.a