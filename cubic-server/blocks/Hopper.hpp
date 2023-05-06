#include <cstdint>
namespace Blocks {
typedef int32_t BlockId;

namespace Hopper {
namespace Properties {
enum class Enabled {
    TRUE,
    FALSE
};
enum class Facing {
    DOWN,
    NORTH,
    SOUTH,
    WEST,
    EAST
};
}
BlockId toProtocol(Properties::Enabled enabled, Properties::Facing facing);
}

}
