#include <cstdint>
namespace Blocks {
    typedef int32_t BlockId;

    namespace Lilac {
        namespace Properties {
            enum class Half {
                UPPER,
                LOWER
            };
        }
        BlockId toProtocol(Properties::Half half);
    }

}
