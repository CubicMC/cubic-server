#include <cstdint>
namespace Blocks {
    typedef int32_t BlockId;

    namespace DeadBubbleCoral {
        namespace Properties {
            enum class Waterlogged {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Waterlogged waterlogged);
    }

}
