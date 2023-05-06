#include <cstdint>
namespace Blocks {
typedef int32_t BlockId;

namespace LargeAmethystBud {
namespace Properties {
enum class Facing {
    NORTH,
    EAST,
    SOUTH,
    WEST,
    UP,
    DOWN
};
enum class Waterlogged {
    TRUE,
    FALSE
};
}
BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged);
}

}
