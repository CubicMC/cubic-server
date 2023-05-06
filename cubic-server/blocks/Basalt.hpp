#include <cstdint>
namespace Blocks {
typedef int32_t BlockId;

namespace Basalt {
namespace Properties {
enum class Axis {
    X,
    Y,
    Z
};
}
BlockId toProtocol(Properties::Axis axis);
}

}
