#include <string>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <functional>

namespace Blocks {
    typedef int32_t BlockId;

    namespace OakStairs {
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
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

}
