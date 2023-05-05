#include <cstdint>
namespace Blocks {
    typedef int32_t BlockId;

    namespace Cocoa {
        namespace Properties {
            enum class Age {
                ZERO,
                ONE,
                TWO
            };
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
        }
        BlockId toProtocol(Properties::Age age, Properties::Facing facing);
    }

}
