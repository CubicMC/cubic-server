#include <string>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <functional>

namespace Blocks {
    typedef int32_t BlockId;

    namespace StructureBlock {
        namespace Properties {
            enum class Mode {
                SAVE,
                LOAD,
                CORNER,
                DATA
            };
        }
        BlockId toProtocol(Properties::Mode mode);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

}
