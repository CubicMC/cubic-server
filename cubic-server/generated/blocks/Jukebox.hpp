#include <string>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <functional>

namespace Blocks {
    typedef int32_t BlockId;

    namespace Jukebox {
        namespace Properties {
            enum class Has_record {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Has_record has_record);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

}
