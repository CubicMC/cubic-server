#include <gtest/gtest.h>
#include "Math.hpp"

namespace Math_Testing
{
    TEST(MathTest, Factorial)
    {
        EXPECT_ANY_THROW(Math::factorial(-1));
        EXPECT_EQ(Math::factorial(0), 1);
        EXPECT_EQ(Math::factorial(1), 1);
        EXPECT_EQ(Math::factorial(2), 2);
        EXPECT_EQ(Math::factorial(3), 6);
        EXPECT_EQ(Math::factorial(10), 3628800);
    }

    TEST(MathTest, Fibonacci)
    {
        EXPECT_ANY_THROW(Math::fibonacci(-1));
        EXPECT_EQ(Math::fibonacci(0), 0);
        EXPECT_EQ(Math::fibonacci(1), 1);
        EXPECT_EQ(Math::fibonacci(2), 1);
        EXPECT_EQ(Math::fibonacci(3), 2);
        EXPECT_EQ(Math::fibonacci(4), 3);
        EXPECT_EQ(Math::fibonacci(5), 5);
        EXPECT_EQ(Math::fibonacci(6), 8);
    }
}