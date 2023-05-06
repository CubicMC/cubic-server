#include <cstdint>
namespace Blocks {
typedef int32_t BlockId;

namespace Observer {
namespace Properties {
enum class Facing {
    NORTH,
    EAST,
    SOUTH,
    WEST,
    UP,
    DOWN
};
enum class Powered {
    TRUE,
    FALSE
};
}
BlockId toProtocol(Properties::Facing facing, Properties::Powered powered);
}

}
