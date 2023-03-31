#include "OakWood.hpp"
#include <stdexcept>

namespace Blocks {
namespace OakWood {
BlockId toProtocol(Properties::Axis axis)
{
    switch (axis) {
    case Properties::Axis::X:
        return 172;
    case Properties::Axis::Y:
        return 173;
    case Properties::Axis::Z:
        return 174;
    }
    return 0;
}
}

}
