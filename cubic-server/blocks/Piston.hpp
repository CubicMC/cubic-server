#include <cstdint>
namespace Blocks {
    typedef int32_t BlockId;

    namespace Piston {
        namespace Properties {
            enum class Extended {
                TRUE,
                FALSE
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
        BlockId toProtocol(Properties::Extended extended, Properties::Facing facing);
    }

}
