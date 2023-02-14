#include <string>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <functional>

namespace Blocks {
    typedef int32_t BlockId;

    namespace Beehive {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Honey_level {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Honey_level honey_level);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

}
