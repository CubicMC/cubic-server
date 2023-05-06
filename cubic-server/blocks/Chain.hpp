#include <cstdint>
namespace Blocks {
typedef int32_t BlockId;

namespace Chain {
namespace Properties {
enum class Axis {
    X,
    Y,
    Z
};
enum class Waterlogged {
    TRUE,
    FALSE
};
}
BlockId toProtocol(Properties::Axis axis, Properties::Waterlogged waterlogged);
}

}
