#include "LightBlueGlazedTerracotta.hpp"
#include <stdexcept>

namespace Blocks {
namespace LightBlueGlazedTerracotta {
BlockId toProtocol(Properties::Facing facing)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        return 12051;
    case Properties::Facing::SOUTH:
        return 12052;
    case Properties::Facing::WEST:
        return 12053;
    case Properties::Facing::EAST:
        return 12054;
    }
    return 0;
}
}

}
