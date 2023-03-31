#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace Blocks {
typedef int32_t BlockId;

namespace TripwireHook {
namespace Properties {
enum class Attached {
    TRUE,
    FALSE
};
enum class Facing {
    NORTH,
    SOUTH,
    WEST,
    EAST
};
enum class Powered {
    TRUE,
    FALSE
};
}
BlockId toProtocol(Properties::Attached attached, Properties::Facing facing, Properties::Powered powered);
}

}
