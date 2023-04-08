#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace Blocks {
typedef int32_t BlockId;

namespace PointedDripstone {
namespace Properties {
enum class Thickness {
    TIP_MERGE,
    TIP,
    FRUSTUM,
    MIDDLE,
    BASE
};
enum class Vertical_direction {
    UP,
    DOWN
};
enum class Waterlogged {
    TRUE,
    FALSE
};
}
BlockId toProtocol(Properties::Thickness thickness, Properties::Vertical_direction vertical_direction, Properties::Waterlogged waterlogged);
}

}
