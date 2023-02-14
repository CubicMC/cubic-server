#include <string>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <functional>

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
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

}
