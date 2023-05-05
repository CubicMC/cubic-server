#include <cstdint>
namespace Blocks {
    typedef int32_t BlockId;

    namespace SculkCatalyst {
        namespace Properties {
            enum class Bloom {
                TRUE,
                FALSE
            };
        }
        BlockId toProtocol(Properties::Bloom bloom);
    }

}
