#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace Blocks {
typedef int32_t BlockId;

namespace Tnt {
namespace Properties {
enum class Unstable {
    TRUE,
    FALSE
};
}
BlockId toProtocol(Properties::Unstable unstable);
}

}
