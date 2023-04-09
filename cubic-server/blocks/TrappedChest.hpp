#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace Blocks {
typedef int32_t BlockId;

namespace TrappedChest {
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
}

}
