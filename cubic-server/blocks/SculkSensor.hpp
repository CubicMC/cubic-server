#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace Blocks {
typedef int32_t BlockId;

namespace SculkSensor {
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
enum class Sculk_sensor_phase {
    INACTIVE,
    ACTIVE,
    COOLDOWN
};
enum class Waterlogged {
    TRUE,
    FALSE
};
}
BlockId toProtocol(Properties::Power power, Properties::Sculk_sensor_phase sculk_sensor_phase, Properties::Waterlogged waterlogged);
}

}
