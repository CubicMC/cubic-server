#include "MuddyMangroveRoots.hpp"
#include <stdexcept>

namespace Blocks {
namespace MuddyMangroveRoots {
BlockId toProtocol(Properties::Axis axis)
{
    switch (axis) {
    case Properties::Axis::X:
        return 142;
    case Properties::Axis::Y:
        return 143;
    case Properties::Axis::Z:
        return 144;
    }
    return 0;
}
}

}
