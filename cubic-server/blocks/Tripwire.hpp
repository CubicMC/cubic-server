#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace Blocks {
typedef int32_t BlockId;

namespace Tripwire {
namespace Properties {
enum class Attached {
    TRUE,
    FALSE
};
enum class Disarmed {
    TRUE,
    FALSE
};
enum class East {
    TRUE,
    FALSE
};
enum class North {
    TRUE,
    FALSE
};
enum class Powered {
    TRUE,
    FALSE
};
enum class South {
    TRUE,
    FALSE
};
enum class West {
    TRUE,
    FALSE
};
}
BlockId toProtocol(
    Properties::Attached attached, Properties::Disarmed disarmed, Properties::East east, Properties::North north, Properties::Powered powered, Properties::South south,
    Properties::West west
);
}

}
