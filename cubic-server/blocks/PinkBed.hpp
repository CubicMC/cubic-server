#include <string>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <functional>

namespace Blocks {
    typedef int32_t BlockId;

    namespace PinkBed {
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
