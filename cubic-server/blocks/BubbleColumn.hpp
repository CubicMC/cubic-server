#include <cstdint>
namespace Blocks {
typedef int32_t BlockId;

namespace BubbleColumn {
namespace Properties {
enum class Drag {
    TRUE,
    FALSE
};
}
BlockId toProtocol(Properties::Drag drag);
}

}
