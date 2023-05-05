#include <cstdint>
namespace Blocks {
    typedef int32_t BlockId;

    namespace Wheat {
        namespace Properties {
            enum class Age {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX,
                SEVEN
            };
        }
        BlockId toProtocol(Properties::Age age);
    }

}
