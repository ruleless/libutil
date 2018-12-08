#include "util/string_helper.h"
#include <gtest/gtest.h>

using namespace util;

TEST(string_helper, test_to)
{
    std::string str;
    str = to<std::string>(123);
    EXPECT_STREQ(str.c_str(), "123");

    str = to<std::string>(1.23);
    EXPECT_STREQ(str.c_str(), "1.23");

    int i;
    i = to<int>("123");
    EXPECT_EQ(i, 123);
    EXPECT_THROW(to<int>(1.23), Exception);

    double d;
    d = to<double>("123");
    EXPECT_EQ(d, 123);

    d = to<double>(123);
    EXPECT_EQ(d, 123);
}

TEST(string_helper, trim)
{
    std::string str = "    ";
    EXPECT_STREQ(ltrim(str).c_str(), "");
    EXPECT_STREQ(rtrim(str).c_str(), "");
    EXPECT_STREQ(trim(str).c_str(), "");

    str = "  abcd  ";
    EXPECT_STREQ(ltrim(str).c_str(), "abcd  ");
    str = "  abcd  ";
    EXPECT_STREQ(rtrim(str).c_str(), "  abcd");
    str = "  abcd  ";
    EXPECT_STREQ(trim(str).c_str(), "abcd");

    str = "";
    EXPECT_STREQ(ltrim(str).c_str(), "");
    str = "";
    EXPECT_STREQ(rtrim(str).c_str(), "");
    str = "";
    EXPECT_STREQ(trim(str).c_str(), "");
}

TEST(string_helper, replace)
{
    std::string str = "abcdefg";
    EXPECT_EQ(replace(str, "abcd", ""), 1);
    EXPECT_STREQ(str.c_str(), "efg");

    str = "abcdefg";
    EXPECT_EQ(replace(str, "abcd", ""), 1);
    EXPECT_STREQ(str.c_str(), "efg");

    str = "xxxx    yyyy";
    EXPECT_EQ(replace(str, " ", ""), 4);
    EXPECT_STREQ(str.c_str(), "xxxxyyyy");

    str = "xxxx    yyyy";
    EXPECT_EQ(replace(str, "y", ""), 4);
    EXPECT_STREQ(str.c_str(), "xxxx    ");
}

TEST(string_helper, transCase)
{
    std::string str = "aAbBccdDd";
    EXPECT_STREQ(uppercase(str).c_str(), "AABBCCDDD");

    str = "aAbBccdDd";
    EXPECT_STREQ(lowercase(str).c_str(), "aabbccddd");
}

TEST(string_helper, split)
{
    std::vector<std::string> v;
    EXPECT_EQ(split(std::string("a;b"), ';', v), 2);
}
