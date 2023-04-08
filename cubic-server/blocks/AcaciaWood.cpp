#include "AcaciaWood.hpp"
#include <stdexcept>

namespace Blocks {
namespace AcaciaWood {
BlockId toProtocol(Properties::Axis axis)
{
    switch (axis) {
    case Properties::Axis::X:
        return 184;
    case Properties::Axis::Y:
        return 185;
    case Properties::Axis::Z:
        return 186;
    }
    return 0;
}
}

}
