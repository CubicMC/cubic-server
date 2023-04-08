#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace Blocks {
typedef int32_t BlockId;

namespace Repeater {
namespace Properties {
enum class Delay {
    ONE,
    TWO,
    THREE,
    FOUR
};
enum class Facing {
    NORTH,
    SOUTH,
    WEST,
    EAST
};
enum class Locked {
    TRUE,
    FALSE
};
enum class Powered {
    TRUE,
    FALSE
};
}
BlockId toProtocol(Properties::Delay delay, Properties::Facing facing, Properties::Locked locked, Properties::Powered powered);
}

}
