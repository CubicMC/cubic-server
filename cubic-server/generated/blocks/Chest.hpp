#include <string>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <functional>

namespace Blocks {
    typedef int32_t BlockId;

    namespace Chest {
        namespace Properties {
            enum class Type {
                SINGLE,
                LEFT,
                RIGHT
            };
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Facing facing, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

}