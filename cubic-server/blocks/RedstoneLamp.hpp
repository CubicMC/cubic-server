#include <string>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <functional>

namespace Blocks {
    typedef int32_t BlockId;

    namespace RedstoneLamp {
        namespace Properties {
            enum class Lit {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Lit lit);
    }

}
