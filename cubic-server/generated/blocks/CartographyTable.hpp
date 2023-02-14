#include <string>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <functional>

namespace Blocks {
    typedef int32_t BlockId;

    namespace CartographyTable {
        BlockId toProtocol();
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

}
