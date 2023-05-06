#include <cstdint>
namespace Blocks {
typedef int32_t BlockId;

namespace LightGrayShulkerBox {
namespace Properties {
enum class Facing {
    NORTH,
    EAST,
    SOUTH,
    WEST,
    UP,
    DOWN
};
}
BlockId toProtocol(Properties::Facing facing);
}

}
