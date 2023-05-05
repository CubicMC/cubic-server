#include <cstdint>
namespace Blocks {
    typedef int32_t BlockId;

    namespace Cake {
        namespace Properties {
            enum class Bites {
                ZERO,
                ONE,
                TWO,
                THREE,
                FOUR,
                FIVE,
                SIX
            };
        }
        BlockId toProtocol(Properties::Bites bites);
    }

}
