#include <string>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <functional>

namespace Blocks {
    typedef int32_t BlockId;

    namespace SeaPickle {
        namespace Properties {
            enum class Pickles {
                ONE,
                TWO,
                THREE,
                FOUR
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Pickles pickles, Properties::Waterlogged waterlogged);
    }

}
