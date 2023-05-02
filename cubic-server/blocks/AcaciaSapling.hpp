#include <cstdint>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

namespace Blocks {
typedef int32_t BlockId;

namespace AcaciaSapling {
namespace Properties {
enum class Stage {
    ZERO,
    ONE
};
}
BlockId toProtocol(Properties::Stage stage);
}

}
