#include <string>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <functional>

namespace Blocks {
    typedef int32_t BlockId;

    namespace MangroveDoor {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                UPPER,
                LOWER
            };
            enum class Hinge {
                LEFT,
                RIGHT
            };
            enum class Open {
                TRUE,
                FALSE
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Hinge hinge, Properties::Open open, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

}