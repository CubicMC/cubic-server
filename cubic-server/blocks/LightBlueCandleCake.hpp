#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace Blocks {
typedef int32_t BlockId;

namespace LightBlueCandleCake {
namespace Properties {
enum class Lit {
    TRUE,
    FALSE
};
}
BlockId toProtocol(Properties::Lit lit);
}

}
