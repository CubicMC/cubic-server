#include <gtest/gtest.h>
#include "Math.hpp"

namespace Math_Testing
{
    /**
     * @brief Launch a new test environment
     *
     * @param TestSuiteName The name of the test suite (in that case MathTest) this allow to group different tests
     * @param TestName The name of the test (in this case Factorial) this allow to group test
     *
     * @note I choose to use EXPECT instead of ASSERT because I want to test all the cases and not to stop at the first error
     *
     */
    TEST(MathTest, Factorial)
    {
        EXPECT_ANY_THROW(Math::factorial(-1)); // Test if the function throw an exception when n is negative
        EXPECT_EQ(Math::factorial(0), 1); // Test an equality if the function return 1 when n is 0 
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