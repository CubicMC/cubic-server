#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace Blocks {
typedef int32_t BlockId;

namespace Jukebox {
namespace Properties {
enum class Has_record {
    TRUE,
    FALSE
};
}
BlockId toProtocol(Properties::Has_record has_record);
}

}
