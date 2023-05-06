#include <cstdint>
namespace Blocks {
typedef int32_t BlockId;

namespace Target {
namespace Properties {
enum class Power {
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
BlockId toProtocol(Properties::Power power);
}

}
