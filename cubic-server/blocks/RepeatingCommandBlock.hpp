#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace Blocks {
typedef int32_t BlockId;

namespace RepeatingCommandBlock {
namespace Properties {
enum class Conditional {
    TRUE,
    FALSE
};
enum class Facing {
    NORTH,
    EAST,
    SOUTH,
    WEST,
    UP,
    DOWN
};
}
BlockId toProtocol(Properties::Conditional conditional, Properties::Facing facing);
}

}
