#include <string>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <functional>

namespace Blocks {
    typedef int32_t BlockId;

    namespace PinkCandle {
        namespace Properties {
            enum class Candles {
                ONE,
                TWO,
                THREE,
                FOUR
            };
            enum class Lit {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

}