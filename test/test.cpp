#include <iostream>
#include "sub.h"
#include "sub2.h"

int main() {
    sub::TestClass* tc;
    tc = new sub::TestClass(1, "test hello world");
    std::cout << "test " + tc->toString() << std::endl;
    delete tc;
    sub2::print("test abc");
}
