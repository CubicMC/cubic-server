#include <cstdint>
namespace Blocks {
typedef int32_t BlockId;

namespace AcaciaDoor {
namespace Properties {
enum class Facing {
    NORTH,
    SOUTH,
    WEST,
    EAST
};
enum class Half {
    UPPER,
    LOWER
};
enum class Hinge {
    LEFT,
    RIGHT
};
enum class Open {
    TRUE,
    FALSE
};
enum class Powered {
    TRUE,
    FALSE
};
}
BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Hinge hinge, Properties::Open open, Properties::Powered powered);
}

}
