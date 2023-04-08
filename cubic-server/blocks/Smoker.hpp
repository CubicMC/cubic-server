#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace Blocks {
typedef int32_t BlockId;

namespace Smoker {
namespace Properties {
enum class Facing {
    NORTH,
    SOUTH,
    WEST,
    EAST
};
enum class Lit {
    TRUE,
    FALSE
};
}
BlockId toProtocol(Properties::Facing facing, Properties::Lit lit);
}

}
