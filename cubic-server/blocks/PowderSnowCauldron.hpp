#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace Blocks {
typedef int32_t BlockId;

namespace PowderSnowCauldron {
namespace Properties {
enum class Level {
    ONE,
    TWO,
    THREE
};
}
BlockId toProtocol(Properties::Level level);
}

}
