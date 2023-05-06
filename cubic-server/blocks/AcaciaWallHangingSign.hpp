#include <cstdint>
namespace Blocks {
typedef int32_t BlockId;

namespace AcaciaWallHangingSign {
namespace Properties {
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
BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged);
}

}
