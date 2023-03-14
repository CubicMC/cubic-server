#include <string>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <functional>

namespace Blocks {
    typedef int32_t BlockId;

    namespace Tnt {
        namespace Properties {
            enum class Unstable {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Unstable unstable);
    }

}
