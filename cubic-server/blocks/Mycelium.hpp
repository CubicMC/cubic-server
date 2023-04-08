#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace Blocks {
typedef int32_t BlockId;

namespace Mycelium {
namespace Properties {
enum class Snowy {
    TRUE,
    FALSE
};
}
BlockId toProtocol(Properties::Snowy snowy);
}

}
