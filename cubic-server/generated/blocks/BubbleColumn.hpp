#include <string>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <functional>

namespace Blocks {
    typedef int32_t BlockId;

    namespace BubbleColumn {
        namespace Properties {
            enum class Drag {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Drag drag);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

}
