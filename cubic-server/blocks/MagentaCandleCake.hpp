#include <cstdint>
namespace Blocks {
typedef int32_t BlockId;

namespace MagentaCandleCake {
namespace Properties {
enum class Lit {
    TRUE,
    FALSE
};
}
BlockId toProtocol(Properties::Lit lit);
}

}
