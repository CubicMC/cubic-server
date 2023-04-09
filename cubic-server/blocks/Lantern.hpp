#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace Blocks {
typedef int32_t BlockId;

namespace Lantern {
namespace Properties {
enum class Hanging {
    TRUE,
    FALSE
};
enum class Waterlogged {
    TRUE,
    FALSE
};
}
BlockId toProtocol(Properties::Hanging hanging, Properties::Waterlogged waterlogged);
}

}
