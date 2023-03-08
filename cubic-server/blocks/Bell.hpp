#include <string>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <functional>

namespace Blocks {
    typedef int32_t BlockId;

    namespace Bell {
        namespace Properties {
            enum class Attachment {
                FLOOR,
                CEILING,
                SINGLE_WALL,
                DOUBLE_WALL
            };
            enum class Facing {
                NORTH,
                SOUTH,
                WEST,
                EAST
            };
            enum class Powered {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Attachment attachment, Properties::Facing facing, Properties::Powered powered);
    }

}
