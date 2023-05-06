#include <cstdint>
namespace Blocks {
typedef int32_t BlockId;

namespace Cactus {
namespace Properties {
enum class Age {
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
}
BlockId toProtocol(Properties::Age age);
}

}
