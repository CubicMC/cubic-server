#include <string>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <functional>

namespace Blocks {
    typedef int32_t BlockId;

    namespace Composter {
        namespace Properties {
            enum class Level {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN,
                EIGHT
            };
        }
        BlockId toProtocol(Properties::Level level);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

}
