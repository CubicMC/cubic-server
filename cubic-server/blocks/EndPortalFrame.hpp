#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace Blocks {
typedef int32_t BlockId;

namespace EndPortalFrame {
namespace Properties {
enum class Eye {
    TRUE,
    FALSE
};
enum class Facing {
    NORTH,
    SOUTH,
    WEST,
    EAST
};
}
BlockId toProtocol(Properties::Eye eye, Properties::Facing facing);
}

}
