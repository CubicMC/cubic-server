#ifndef UTILITY_PSEUDO_RANDOM_GENERATOR_HPP
#define UTILITY_PSEUDO_RANDOM_GENERATOR_HPP

#include "concept.hpp"
#include <mutex>
#include <numeric>
#include <random>
#include <type_traits>

namespace utility {
class PseudoRandomGenerator {
public:
    PseudoRandomGenerator();
    ~PseudoRandomGenerator();
    template<typename T>
    T generateNumber(T, T);
    static PseudoRandomGenerator *getInstance()
    {
        static PseudoRandomGenerator prg;
        return &prg;
    }

private:
    std::mutex _generator;
    std::random_device _seeder;
    std::mt19937 _engine;
};

template<typename T>
T PseudoRandomGenerator::generateNumber(T min, T max)
{
    static_assert(std::is_arithmetic<T>::value, "T must be an arithmetic type");
    std::lock_guard _(_generator);
    if constexpr (std::is_floating_point_v<T>) {
        std::uniform_real_distribution<T> dist(min, max);
        return (dist(_engine));
    } else {
        std::uniform_int_distribution<T> dist(min, max);
        return (dist(_engine));
    }
}

}

#endif // UTILITY_PSEUDO_RANDOM_GENERATOR_HPP
