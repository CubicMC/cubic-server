#include <cstdint>
namespace Blocks {
typedef int32_t BlockId;

namespace NetherWart {
namespace Properties {
enum class Age {
    ZERO,
    ONE,
    TWO,
    THREE
};
}
BlockId toProtocol(Properties::Age age);
}

}
