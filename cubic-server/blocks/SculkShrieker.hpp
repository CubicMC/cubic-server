#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace Blocks {
typedef int32_t BlockId;

namespace SculkShrieker {
namespace Properties {
enum class Can_summon {
    TRUE,
    FALSE
};
enum class Shrieking {
    TRUE,
    FALSE
};
enum class Waterlogged {
    TRUE,
    FALSE
};
}
BlockId toProtocol(Properties::Can_summon can_summon, Properties::Shrieking shrieking, Properties::Waterlogged waterlogged);
}

}
