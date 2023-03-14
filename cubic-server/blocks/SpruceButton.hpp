#include <string>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <functional>

namespace Blocks {
    typedef int32_t BlockId;

    namespace SpruceButton {
        namespace Properties {
            enum class Face {
                FLOOR,
                WALL,
                CEILING
            };
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Face face, Properties::Facing facing, Properties::Powered powered);
    }

}
