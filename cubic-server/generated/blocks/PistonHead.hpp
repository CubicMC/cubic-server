#include <string>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <functional>

namespace Blocks {
    typedef int32_t BlockId;

    namespace PistonHead {
        namespace Properties {
            enum class Type {
                NORMAL,
                STICKY
            };
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
            enum class Short_ {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Facing facing, Properties::Short_ short_);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

}
