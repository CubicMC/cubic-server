#ifndef AE79D862_ED99_4B26_9439_AB07465774BB
#define AE79D862_ED99_4B26_9439_AB07465774BB

#include <algorithm>
#include <array>
#include <string>

constexpr std::array<std::string, 3> SINGLE_SELECTOR = {"@r", "@s", "@p"};
constexpr std::array<std::string, 2> MULTIPLE_SELECTOR = {"@a", "@e"};

constexpr bool isMultipleSelector(const std::string &str)
{
    return std::find(MULTIPLE_SELECTOR.begin(), MULTIPLE_SELECTOR.end(), str) != MULTIPLE_SELECTOR.end();
}

constexpr bool isSingleSelector(const std::string &str)
{
    return std::find(SINGLE_SELECTOR.begin(), SINGLE_SELECTOR.end(), str) != SINGLE_SELECTOR.end();
}

constexpr bool isSelector(const std::string &str)
{
    return isMultipleSelector(str) || isSingleSelector(str);
}

#endif /* AE79D862_ED99_4B26_9439_AB07465774BB */
