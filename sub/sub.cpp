//
// Created by dingxiuzheng on 2022/9/2.
//

#include <iostream>
#include "sub.h"

namespace sub {
    TestClass::TestClass(int index, std::string str) : index(index), str(str) {
        std::cout << "sub TestClass Constructor" << std::endl;
    }

    TestClass::~TestClass() {
        std::cout << "sub TestClass Destructor" << std::endl;
    }

    void TestClass::setIndex(int i) {
        index = i;
    }

    void TestClass::setStr(std::string s) {
        str = s;
    }

    std::string TestClass::toString() {
        std::string s = "sub index:" + std::to_string(index) + " str:" + str;
        return s;
    }
}