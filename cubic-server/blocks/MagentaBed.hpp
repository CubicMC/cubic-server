#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace Blocks {
typedef int32_t BlockId;

namespace MagentaBed {
namespace Properties {
enum class Facing {
    NORTH,
    SOUTH,
    WEST,
    EAST
};
enum class Occupied {
    TRUE,
    FALSE
};
enum class Part {
    HEAD,
    FOOT
};
}
BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part);
}

}
