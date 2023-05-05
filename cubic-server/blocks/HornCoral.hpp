#include <cstdint>
namespace Blocks {
    typedef int32_t BlockId;

    namespace HornCoral {
        namespace Properties {
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Waterlogged waterlogged);
    }

}
