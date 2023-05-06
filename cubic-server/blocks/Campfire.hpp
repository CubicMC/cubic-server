#include <cstdint>
namespace Blocks {
typedef int32_t BlockId;

namespace Campfire {
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
enum class Signal_fire {
    TRUE,
    FALSE
};
enum class Waterlogged {
    TRUE,
    FALSE
};
}
BlockId toProtocol(Properties::Facing facing, Properties::Lit lit, Properties::Signal_fire signal_fire, Properties::Waterlogged waterlogged);
}

}
