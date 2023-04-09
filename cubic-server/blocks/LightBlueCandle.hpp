#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace Blocks {
typedef int32_t BlockId;

namespace LightBlueCandle {
namespace Properties {
enum class Candles {
    ONE,
    TWO,
    THREE,
    FOUR
};
enum class Lit {
    TRUE,
    FALSE
};
enum class Waterlogged {
    TRUE,
    FALSE
};
}
BlockId toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged);
}

}
