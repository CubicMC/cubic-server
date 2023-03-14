#include <string>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <functional>

namespace Blocks {
    typedef int32_t BlockId;

    namespace WarpedSlab {
        namespace Properties {
            enum class Type {
                TOP,
                BOTTOM,
                DOUBLE
            };
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Type type, Properties::Waterlogged waterlogged);
    }

}
