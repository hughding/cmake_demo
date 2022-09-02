#include <iostream>
#include "sub.h"
#include "sub2.h"

int main() {
    sub::TestClass* tc;
    tc = new sub::TestClass(1, "hello world");
    std::cout << tc->toString() << std::endl;
    delete tc;
    sub2::print("abc");
}
