#include <iostream>
#include "sub.h"

int main() {
    sub::TestClass testClass(1, "hello world");
    std::cout << testClass.toString() << std::endl;
}
