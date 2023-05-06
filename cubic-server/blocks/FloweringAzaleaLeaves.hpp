#include <cstdint>
namespace Blocks {
typedef int32_t BlockId;

namespace FloweringAzaleaLeaves {
namespace Properties {
enum class Distance {
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN
};
enum class Persistent {
    TRUE,
    FALSE
};
enum class Waterlogged {
    TRUE,
    FALSE
};
}
BlockId toProtocol(Properties::Distance distance, Properties::Persistent persistent, Properties::Waterlogged waterlogged);
}

}
