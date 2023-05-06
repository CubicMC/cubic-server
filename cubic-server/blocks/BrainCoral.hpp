#include <cstdint>
namespace Blocks {
typedef int32_t BlockId;

namespace BrainCoral {
namespace Properties {
enum class Waterlogged {
    TRUE,
    FALSE
};
}
BlockId toProtocol(Properties::Waterlogged waterlogged);
}

}
