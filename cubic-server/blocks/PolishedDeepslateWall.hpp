#include <cstdint>
namespace Blocks {
typedef int32_t BlockId;

namespace PolishedDeepslateWall {
namespace Properties {
enum class East {
    NONE,
    LOW,
    TALL
};
enum class North {
    NONE,
    LOW,
    TALL
};
enum class South {
    NONE,
    LOW,
    TALL
};
enum class Up {
    TRUE,
    FALSE
};
enum class Waterlogged {
    TRUE,
    FALSE
};
enum class West {
    NONE,
    LOW,
    TALL
};
}
BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west);
}

}
