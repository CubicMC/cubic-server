#include <cstdint>
namespace Blocks {
    typedef int32_t BlockId;

    namespace RedstoneWallTorch {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Lit {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Lit lit);
    }

}
