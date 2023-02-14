#include <string>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <functional>

namespace Blocks {
    typedef int32_t BlockId;

    namespace OakSapling {
        namespace Properties {
            enum class Stage {
                ZERO,
                ONE
            };
        }
        BlockId toProtocol(Properties::Stage stage);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

}
