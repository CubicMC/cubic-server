#include <cstdint>
namespace Blocks {
    typedef int32_t BlockId;

    namespace YellowBed {
        namespace Properties {
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Occupied {
                TRUE,
                FALSE
            };
            enum class Part {
                HEAD,
                FOOT
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part);
    }

}
