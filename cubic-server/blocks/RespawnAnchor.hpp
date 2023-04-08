#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace Blocks {
typedef int32_t BlockId;

namespace RespawnAnchor {
namespace Properties {
enum class Charges {
    ZERO,
    ONE,
    TWO,
    THREE,
    FOUR
};
}
BlockId toProtocol(Properties::Charges charges);
}

}
