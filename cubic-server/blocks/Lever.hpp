#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace Blocks {
typedef int32_t BlockId;

namespace Lever {
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
