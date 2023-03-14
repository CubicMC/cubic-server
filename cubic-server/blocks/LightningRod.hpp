#include <string>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <functional>

namespace Blocks {
    typedef int32_t BlockId;

    namespace LightningRod {
        namespace Properties {
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
            enum class Powered {
                TRUE,
                FALSE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Powered powered, Properties::Waterlogged waterlogged);
    }

}
