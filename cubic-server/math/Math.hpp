#ifndef MATH_HPP_
#define MATH_HPP_

namespace Math_Testing
{
    /**
     * @brief Math library just for show how to make test from a class
     */
    class Math
    {
        public:
            static long factorial(int n); // a factorial function
            static long fibonacci(int n); // a fibonacci function
            static bool isPositive(int n); // a function to check if a number is positive
            static int square(int n); // a function to square a number
    };
}

#endif /* !MATH_HPP_ */
