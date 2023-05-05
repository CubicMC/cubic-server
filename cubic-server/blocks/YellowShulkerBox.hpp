#include <cstdint>
namespace Blocks {
    typedef int32_t BlockId;

    namespace YellowShulkerBox {
        namespace Properties {
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
        }
        BlockId toProtocol(Properties::Facing facing);
    }

}
