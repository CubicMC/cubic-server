#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace Blocks {
typedef int32_t BlockId;

namespace RedstoneWire {
namespace Properties {
enum class East {
    UP,
    SIDE,
    NONE
};
enum class North {
    UP,
    SIDE,
    NONE
};
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
enum class South {
    UP,
    SIDE,
    NONE
};
enum class West {
    UP,
    SIDE,
    NONE
};
}
BlockId toProtocol(Properties::East east, Properties::North north, Properties::Power power, Properties::South south, Properties::West west);
}

}
