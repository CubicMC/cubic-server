#include <gtest/gtest.h>

// The purpose of these tests are just to make sure that gtest was properly installed.

TEST(SampleTest, SimpleAssertion)
{
    EXPECT_EQ(1, 1);
}

TEST(SampleTest, AnotherAssertion)
{
    EXPECT_TRUE(true);
}
