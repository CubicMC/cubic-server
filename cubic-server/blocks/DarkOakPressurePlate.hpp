#include <cstdint>
namespace Blocks {
typedef int32_t BlockId;

namespace DarkOakPressurePlate {
namespace Properties {
enum class Powered {
    TRUE,
    FALSE
};
}
BlockId toProtocol(Properties::Powered powered);
}

}
