#include <cstdint>
namespace Blocks {
typedef int32_t BlockId;

namespace SpruceSign {
namespace Properties {
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
BlockId toProtocol(Properties::Rotation rotation, Properties::Waterlogged waterlogged);
}

}
