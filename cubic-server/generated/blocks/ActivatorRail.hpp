#include <string>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <functional>

namespace Blocks {
    typedef int32_t BlockId;

    namespace ActivatorRail {
        namespace Properties {
            enum class Powered {
                TRUE,
                FALSE
            };
            enum class Shape {
                NORTH_SOUTH,
                EAST_WEST,
                ASCENDING_EAST,
                ASCENDING_WEST,
                ASCENDING_NORTH,
                ASCENDING_SOUTH
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Powered powered, Properties::Shape shape, Properties::Waterlogged waterlogged);
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties);
    }

}
