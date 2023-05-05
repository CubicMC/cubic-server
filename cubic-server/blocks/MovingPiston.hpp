#include <cstdint>
namespace Blocks {
    typedef int32_t BlockId;

    namespace MovingPiston {
        namespace Properties {
            enum class Type {
                NORMAL,
                STICKY
            };
            enum class Facing {
                NORTH,
                EAST,
                SOUTH,
                WEST,
                UP,
                DOWN
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Facing facing);
    }

}
