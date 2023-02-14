#include <string>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <functional>

namespace Blocks {
    typedef int32_t BlockId;

    namespace WaterCauldron {
        namespace Properties {
            enum class Level {
                ONE,
                TWO,
                THREE
            };
        }
        BlockId toProtocol(Properties::Level level);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

}
