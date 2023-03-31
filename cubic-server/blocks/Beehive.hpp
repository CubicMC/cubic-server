#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace Blocks {
typedef int32_t BlockId;

namespace Beehive {
namespace Properties {
enum class Facing {
    NORTH,
    SOUTH,
    WEST,
    EAST
};
enum class Honey_level {
    ZERO,
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE
};
}
BlockId toProtocol(Properties::Facing facing, Properties::Honey_level honey_level);
}

}
