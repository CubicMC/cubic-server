#include <string>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <functional>

namespace Blocks {
    typedef int32_t BlockId;

    namespace DaylightDetector {
        namespace Properties {
            enum class Inverted {
                TRUE,
                FALSE
            };
            enum class Power {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT,
                NINE,
                TEN,
                ELEVEN,
                TWELVE,
                THIRTEEN,
                FOURTEEN,
                FIFTEEN
            };
        }
        BlockId toProtocol(Properties::Inverted inverted, Properties::Power power);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

}
