#include <gtest/gtest.h>

#include "sub.h"
#include "include/sub2.h"

TEST(sub, toString) {
    sub::TestClass *tc;
    tc = new sub::TestClass(1, "hello world");
    std::cout << tc->toString() << std::endl;
    delete tc;
    ASSERT_EQ(1, 1);
}

TEST(sub2, print) {
    sub2::print("test");
    ASSERT_EQ(1, 1);
}
