#include "src/string_helper.h"
#include <gtest/gtest.h>

TEST(string_helper, test_to)
{
    std::string str;
    str = util::to<std::string>(123);
    EXPECT_STREQ(str.c_str(), "123");

    str = util::to<std::string>(1.23);
    EXPECT_STREQ(str.c_str(), "1.23");

    int i;
    i = util::to<int>("123");
    EXPECT_EQ(i, 123);
    EXPECT_THROW(util::to<int>(1.23), util::Exception);

    double d;
    d = util::to<double>("123");
    EXPECT_EQ(d, 123);

    d = util::to<double>(123);
    EXPECT_EQ(d, 123);
}
