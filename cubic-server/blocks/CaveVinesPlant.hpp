#include <string>
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <functional>

namespace Blocks {
    typedef int32_t BlockId;

    namespace CaveVinesPlant {
        namespace Properties {
            enum class Berries {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Berries berries);
    }

}
