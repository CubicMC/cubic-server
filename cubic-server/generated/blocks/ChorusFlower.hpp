#include <string>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <functional>

namespace Blocks {
    typedef int32_t BlockId;

    namespace ChorusFlower {
        namespace Properties {
            enum class Age {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE
            };
        }
        BlockId toProtocol(Properties::Age age);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

}
