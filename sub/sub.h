//
// Created by dingxiuzheng on 2022/9/2.
//

#ifndef TEST_SUB_H
#define TEST_SUB_H

#include <string>

namespace sub {
    class TestClass {
    public:
        TestClass(int index, std::string str);
        ~TestClass();
    public:
        void setIndex(int i);
        void setStr(std::string s);
        std::string toString();
    private:
        int index;
        std::string str;
    };
}

#endif //TEST_SUB_H
