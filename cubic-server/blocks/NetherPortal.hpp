#include <cstdint>
namespace Blocks {
typedef int32_t BlockId;

namespace NetherPortal {
namespace Properties {
enum class Axis {
    X,
    Z
};
}
BlockId toProtocol(Properties::Axis axis);
}

}
