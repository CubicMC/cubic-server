#include <string>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <functional>

namespace Blocks {
    typedef int32_t BlockId;

    namespace Farmland {
        namespace Properties {
            enum class Moisture {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN
            };
        }
        BlockId toProtocol(Properties::Moisture moisture);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

}
