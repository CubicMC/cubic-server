#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace Blocks {
typedef int32_t BlockId;

namespace JungleFenceGate {
namespace Properties {
enum class Facing {
    NORTH,
    SOUTH,
    WEST,
    EAST
};
enum class In_wall {
    TRUE,
    FALSE
};
enum class Open {
    TRUE,
    FALSE
};
enum class Powered {
    TRUE,
    FALSE
};
}
BlockId toProtocol(Properties::Facing facing, Properties::In_wall in_wall, Properties::Open open, Properties::Powered powered);
}

}
