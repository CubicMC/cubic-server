#include <string>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <functional>

namespace Blocks {
    typedef int32_t BlockId;

    namespace RespawnAnchor {
        namespace Properties {
            enum class Charges {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR
            };
        }
        BlockId toProtocol(Properties::Charges charges);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

}
