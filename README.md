# cmake_demo
## 环境配置
MinGW安装，bin加入到Path中，使用8.1.0版本，x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0.7z
https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/
cmake安装，使用Clion中的cmake，bin加入到Path中
linux中的make，在MinGW中为mingw32-make

## 开发工具
Clion配置远程开发(Full Remote Mode)
1.配置ToolChains，Remote（注意Cmake选择cmake3的bin）
2.配置Cmake使用Remote ToolChains
3.配置Deployment中Mappings的Deployment path
4.Cmake后，使用Deployment工具下载ESSD/src/proto文件夹（因为Cmake后,生成了proto的c++代码，需要下载下来供Clion使用）
5.Settings->Languages&Frameworks->Protocol Buffers

## git module
git submodule add -b v1.8.x https://github.com/google/googletest.git 3rdparty/gtest
git submodule update --init --recursive
[README.md](README.md)
git rm -r --cached 3rdparty/gtest

## CMakeLists.txt配置说明
引入第3方包，一般在/usr/include/,/usr/lib/,/usr/lib64/,/usr/local/include/,/usr/local/lib/,/usr/local/lib64/
find_path 搜索指定头文件路径。
find_library 搜索指定静态、动态链接库路径。

## 单元测试覆盖率(lcov)
```
UNITTEST_TARGET_LIST=(unittest-a unittest-b)
mkdir build && cd build
cmake3 -DENABLE_COVERAGE=ON ..
for target in ${UNITTEST_TARGET_LIST[@]}
do
    gmake ${target} -j4
done
cd ..
lcov -d build -z && lcov -d build -b . --no-external --initial -c -o CMakeGcovSupportInitialCoverage.info
lcov -r CMakeGcovSupportInitialCoverage.info "*/3rdparty/*" -o CMakeGcovSupportInitialCoverage.info
lcov -r CMakeGcovSupportInitialCoverage.info "*/include/*" -o CMakeGcovSupportInitialCoverage.info
lcov -r CMakeGcovSupportInitialCoverage.info "*/proto/*" -o CMakeGcovSupportInitialCoverage.info
lcov -r CMakeGcovSupportInitialCoverage.info "*/test/*" -o CMakeGcovSupportInitialCoverage.info

for target in ${UNITTEST_TARGET_LIST[@]}
do
    ./build/bin/${target}
done
lcov -d build -b . --no-external -c -o CMakeGcovSupportCoverage.info
lcov -r CMakeGcovSupportCoverage.info "*/3rdparty/*" -o CMakeGcovSupportCoverage.info
lcov -r CMakeGcovSupportCoverage.info "*/include/*" -o CMakeGcovSupportCoverage.info
lcov -r CMakeGcovSupportCoverage.info "*/proto/*" -o CMakeGcovSupportCoverage.info
lcov -r CMakeGcovSupportCoverage.info "*/test/*" -o CMakeGcovSupportCoverage.info
genhtml -o CMakeGcovSupportCoverageReport --prefix='pwd' CMakeGcovSupportInitialCoverage.info CMakeGcovSupportCoverage.info
#此时会生成CMakeGcovSupportCoverageReport文件夹，打开文件夹中的index.html，即可看到代码覆盖率
zip -q -r CMakeGcovSupportCoverageReport.zip CMakeGcovSupportCoverageReport
```

## 单元测试覆盖率(gcovr)
```
UNITTEST_TARGET_LIST=(unittest-a unittest-b)
mkdir build && cd build
cmake3 -DENABLE_COVERAGE=ON ..
make ${UNITTEST_TARGET_LIST[*]} -j9
#生成每个模块的覆盖率json
cd ..
for target in ${UNITTEST_TARGET_LIST[*]}
do
    ./build/bin/\\${target}
    gcovr -r . -e 'build/' -e 'src/3rdparty/' -e 'src/proto/' -e 'src/.*/test/' -e 'src/.*/unittest/' --json coverage-\\${target}.json
done
#合并生成覆盖率xml
gcovr -r . --add-tracefile 'coverage-*.json' --xml-pretty --output coverage.xml
#合并生成覆盖率html
mkdir CoverageGcovr
gcovr -r . --add-tracefile 'coverage-*.json' --html --html-details -o CoverageGcovr/index.html
```

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

## gdb调试
ulimit -c  如果结果为0，系统不能生成core dump文件
ulimit -c unlimited 开启core dump功能
cat /proc/sys/kernel/core_pattern  查看core dump文件位置
如果结果是|/usr/lib/systemd/systemd-coredump %P %u %g %s %t %c %h 需要重新设置，如下
echo "./core-%e-%p-%t" > /proc/sys/kernel/core_pattern  设置core dump文件位置在当前执行命令的文件夹内

使用gdb分析coredump文件
gdb ./bin/ipc_server   ipc_server.core   # 必须使用与core时一样的bin/lib文件
(gdb) set args zmq 6000   # 指定运行时的参数
(gdb) bt          # backtrace显示当前调用堆栈
(gdb) bt full     # backtrace显示完整的调用栈和局部变量等信息
(gdb) f 5         # 展示bt信息第5行的代码
(gdb) l 行号       # 展示行号上下10行的代码
(gdb) info args   # 展示函数参数值
(gdb) info locals # 展示当前函数的局部变量及其对应的值
(gdb) q           # 退出gdb

gdb断点调试
gdb --args /usr/local/essd/bin/essd-streamserver -flagfile=/usr/local/essd/etc/streamserver/gflags.conf
(gdb) b transfer_impl.cc:248
(gdb) info b 展示断点信息
(gdb) r 开始执行程序
(gdb) s 进入
(gdb) n 下一步
(gdb) p conn->addr_ 展示变量
(gdb) q 退出gdb

gdb调试已存在进程
(gdb) gdb attach 2880926
(gdb) info threads
(gdb) thread 10
(gdb) b extent_report.cc:418
(gdb) c
(gdb) detach
(gdb) q

gdb排查死锁
(gdb) gdb attach 2880926
(gdb) info threads
所有线程堆栈
(gdb) thread apply all bt
切换到单个线程
(gdb) thread 10
(gdb) bt
(gdb) p mutex变量
(gdb) detach
(gdb) q

分析内存
brpc框架，直接进入管理页面heap页面分析

#rpm
rpm -qa 查看已安装的包
rpm -qa --last 查看已安装的包，显示最后一次安装时间
rpm -e <软件包名>  卸载软件包
rpm -Uvh abc*.rpm --nodeps --force 更新安装包，输出信息，打印包hash值，不校验依赖，强制
rpm -ivh abc*.rpm 安装包，输出信息，打印hash marks（井号）
rpm -qpl <package.rpm> 查看安装包的目标目录

#动态链接库
已加载的动态库 
ldconfig -p
打印一个程序或共享库所依赖的动态链接库
ldd /path/to/your/executable

#perf工具
perf record -p <PID> -t <TID> -g -- sleep 60  生成perf.data
perf script > out.perf  生成out.perf
下载flamegraph
git clone https://github.com/brendangregg/FlameGraph.git
