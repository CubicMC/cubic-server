#include "Math.hpp"

#include <stdexcept>

namespace Math_Testing {
long Math::factorial(int n)
{
    if (n < 0)
        throw std::invalid_argument("n must be >= 0"); // throw an exception if n is negative
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

long Math::fibonacci(int n)
{
    if (n < 0)
        throw std::invalid_argument("n must be >= 0"); // throw an exception if n is negative
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

bool Math::isPositive(int n) { return n >= 0; }

int Math::square(int n) { return n * n; }
}
