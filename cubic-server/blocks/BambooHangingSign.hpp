#include <cstdint>
namespace Blocks {
typedef int32_t BlockId;

namespace BambooHangingSign {
namespace Properties {
enum class Attached {
    TRUE,
    FALSE
};
enum class Rotation {
    ZERO,
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    ELEVEN,
    TWELVE,
    THIRTEEN,
    FOURTEEN,
    FIFTEEN
};
enum class Waterlogged {
    TRUE,
    FALSE
};
}
BlockId toProtocol(Properties::Attached attached, Properties::Rotation rotation, Properties::Waterlogged waterlogged);
}

}
