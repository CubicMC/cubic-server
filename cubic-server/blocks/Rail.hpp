#include <string>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <functional>

namespace Blocks {
    typedef int32_t BlockId;

    namespace Rail {
        namespace Properties {
            enum class Shape {
                NORTH_SOUTH,
                EAST_WEST,
                ASCENDING_EAST,
                ASCENDING_WEST,
                ASCENDING_NORTH,
                ASCENDING_SOUTH,
                SOUTH_EAST,
                SOUTH_WEST,
                NORTH_WEST,
                NORTH_EAST
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Shape shape, Properties::Waterlogged waterlogged);
    }

}
