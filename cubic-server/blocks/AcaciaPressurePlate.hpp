#include <cstdint>
namespace Blocks {
typedef int32_t BlockId;

namespace AcaciaPressurePlate {
namespace Properties {
enum class Powered {
    TRUE,
    FALSE
};
}
BlockId toProtocol(Properties::Powered powered);
}

}
