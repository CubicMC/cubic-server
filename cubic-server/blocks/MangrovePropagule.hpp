#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace Blocks {
typedef int32_t BlockId;

namespace MangrovePropagule {
namespace Properties {
enum class Age {
    ZERO,
    ONE,
    TWO,
    THREE,
    FOUR
};
enum class Hanging {
    TRUE,
    FALSE
};
enum class Stage {
    ZERO,
    ONE
};
enum class Waterlogged {
    TRUE,
    FALSE
};
}
BlockId toProtocol(Properties::Age age, Properties::Hanging hanging, Properties::Stage stage, Properties::Waterlogged waterlogged);
}

}
