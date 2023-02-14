#include <string>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <functional>

namespace Blocks {
    typedef int32_t BlockId;

    namespace Comparator {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Mode {
                COMPARE,
                SUBTRACT
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Mode mode, Properties::Powered powered);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

}
