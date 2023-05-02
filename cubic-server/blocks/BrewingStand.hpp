#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace Blocks {
typedef int32_t BlockId;

namespace BrewingStand {
namespace Properties {
enum class Has_bottle_0 {
    TRUE,
    FALSE
};
enum class Has_bottle_1 {
    TRUE,
    FALSE
};
enum class Has_bottle_2 {
    TRUE,
    FALSE
};
}
BlockId toProtocol(Properties::Has_bottle_0 has_bottle_0, Properties::Has_bottle_1 has_bottle_1, Properties::Has_bottle_2 has_bottle_2);
}

}
