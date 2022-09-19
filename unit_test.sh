#!/bin/bash
cd /home/dingxiuzheng/cmake_demo
rm -rf ./CMakeGcovSupportCoverageReport
rm -rf ./CMakeGcovSupportInitialCoverage.info
rm -rf ./build
mkdir build && cd build
cmake3 -DENABLE_COVERAGE=ON ..
gmake all
cd ..
lcov -d build -z && lcov -d build -b . --no-external --initial -c -o CMakeGcovSupportInitialCoverage.info
cd build/bin
./unit_tests
cd ../../
lcov -d build -b . --no-external -c -o CMakeGcovSupportCoverage.info
genhtml -o CMakeGcovSupportCoverageReport --prefix='pwd' CMakeGcovSupportInitialCoverage.info CMakeGcovSupportCoverage.info
