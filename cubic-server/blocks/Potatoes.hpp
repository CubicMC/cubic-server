#include <string>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <functional>

namespace Blocks {
    typedef int32_t BlockId;

    namespace Potatoes {
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
