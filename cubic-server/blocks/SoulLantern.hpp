#include <cstdint>
namespace Blocks {
typedef int32_t BlockId;

namespace SoulLantern {
namespace Properties {
enum class Hanging {
    TRUE,
    FALSE
};
enum class Waterlogged {
    TRUE,
    FALSE
};
}
BlockId toProtocol(Properties::Hanging hanging, Properties::Waterlogged waterlogged);
}

}
