#include <cstdint>
namespace Blocks {
    typedef int32_t BlockId;

    namespace MangroveTrapdoor {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Half {
                TOP,
                BOTTOM
            };
            enum class Open {
                TRUE,
                FALSE
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
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Open open, Properties::Powered powered, Properties::Waterlogged waterlogged);
    }

}
