#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace Blocks {
typedef int32_t BlockId;

namespace AcaciaWood {
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
