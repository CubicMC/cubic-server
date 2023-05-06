#include <cstdint>
namespace Blocks {
typedef int32_t BlockId;

namespace SprucePressurePlate {
namespace Properties {
enum class Powered {
    TRUE,
    FALSE
};
}
BlockId toProtocol(Properties::Powered powered);
}

}
