#include "BlueGlazedTerracotta.hpp"
#include <stdexcept>

namespace Blocks {
namespace BlueGlazedTerracotta {
BlockId toProtocol(Properties::Facing facing)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        return 12083;
    case Properties::Facing::SOUTH:
        return 12084;
    case Properties::Facing::WEST:
        return 12085;
    case Properties::Facing::EAST:
        return 12086;
    }
    return 0;
}
}

}
