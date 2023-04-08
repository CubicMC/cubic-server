#include "NetherPortal.hpp"
#include <stdexcept>

namespace Blocks {
namespace NetherPortal {
BlockId toProtocol(Properties::Axis axis)
{
    switch (axis) {
    case Properties::Axis::X:
        return 5699;
    case Properties::Axis::Z:
        return 5700;
    }
    return 0;
}
}

}
