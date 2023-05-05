#include <cstdint>
namespace Blocks {
    typedef int32_t BlockId;

    namespace CobbledDeepslateStairs {
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
            enum class Shape {
                STRAIGHT,
                INNER_LEFT,
                INNER_RIGHT,
                OUTER_LEFT,
                OUTER_RIGHT
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged);
    }

}
