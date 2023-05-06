#include <cstdint>
namespace Blocks {
typedef int32_t BlockId;

namespace StructureBlock {
namespace Properties {
enum class Mode {
    SAVE,
    LOAD,
    CORNER,
    DATA
};
}
BlockId toProtocol(Properties::Mode mode);
}

}
