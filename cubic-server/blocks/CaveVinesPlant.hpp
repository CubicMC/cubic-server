#include <cstdint>
namespace Blocks {
typedef int32_t BlockId;

namespace CaveVinesPlant {
namespace Properties {
enum class Berries {
    TRUE,
    FALSE
};
}
BlockId toProtocol(Properties::Berries berries);
}

}
