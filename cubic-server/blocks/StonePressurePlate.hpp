#include <cstdint>
namespace Blocks {
typedef int32_t BlockId;

namespace StonePressurePlate {
namespace Properties {
enum class Powered {
    TRUE,
    FALSE
};
}
BlockId toProtocol(Properties::Powered powered);
}

}
