#include <string>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <functional>

namespace Blocks {
    typedef int32_t BlockId;

    namespace StickyPiston {
        namespace Properties {
            enum class Extended {
                TRUE,
                FALSE
            };
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
        }
        BlockId toProtocol(Properties::Extended extended, Properties::Facing facing);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

}
