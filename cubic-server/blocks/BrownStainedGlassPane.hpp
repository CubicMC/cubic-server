#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace Blocks {
typedef int32_t BlockId;

namespace BrownStainedGlassPane {
namespace Properties {
enum class East {
    TRUE,
    FALSE
};
enum class North {
    TRUE,
    FALSE
};
enum class South {
    TRUE,
    FALSE
};
enum class Waterlogged {
    TRUE,
    FALSE
};
enum class West {
    TRUE,
    FALSE
};
}
BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west);
}

}
