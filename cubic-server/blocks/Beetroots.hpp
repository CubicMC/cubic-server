#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace Blocks {
typedef int32_t BlockId;

namespace Beetroots {
namespace Properties {
enum class Age {
    ZERO,
    ONE,
    TWO,
    THREE
};
}
BlockId toProtocol(Properties::Age age);
}

}
