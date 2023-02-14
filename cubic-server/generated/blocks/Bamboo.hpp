#include <string>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <functional>

namespace Blocks {
    typedef int32_t BlockId;

    namespace Bamboo {
        namespace Properties {
            enum class Age {
                ZERO,
                ONE
            };
            enum class Leaves {
                NONE,
                SMALL,
                LARGE
            };
            enum class Stage {
                ZERO,
                ONE
            };
        }
        BlockId toProtocol(Properties::Age age, Properties::Leaves leaves, Properties::Stage stage);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

}
