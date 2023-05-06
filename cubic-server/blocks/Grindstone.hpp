#include <cstdint>
namespace Blocks {
typedef int32_t BlockId;

namespace Grindstone {
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
}
BlockId toProtocol(Properties::Face face, Properties::Facing facing);
}

}
