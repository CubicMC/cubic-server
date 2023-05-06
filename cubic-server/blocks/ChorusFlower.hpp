#include <cstdint>
namespace Blocks {
typedef int32_t BlockId;

namespace ChorusFlower {
namespace Properties {
enum class Age {
    ZERO,
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE
};
}
BlockId toProtocol(Properties::Age age);
}

}
