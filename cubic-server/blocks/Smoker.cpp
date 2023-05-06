#include "Smoker.hpp"
namespace Blocks {
namespace Smoker {
BlockId toProtocol(Properties::Facing facing, Properties::Lit lit) {
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (lit) {
        case Properties::Lit::TRUE:
            return 17792;
        case Properties::Lit::FALSE:
            return 17793;
        default:
            return 0;
        }
    case Properties::Facing::SOUTH:
        switch (lit) {
        case Properties::Lit::TRUE:
            return 17794;
        case Properties::Lit::FALSE:
            return 17795;
        default:
            return 0;
        }
    case Properties::Facing::WEST:
        switch (lit) {
        case Properties::Lit::TRUE:
            return 17796;
        case Properties::Lit::FALSE:
            return 17797;
        default:
            return 0;
        }
    case Properties::Facing::EAST:
        switch (lit) {
        case Properties::Lit::TRUE:
            return 17798;
        case Properties::Lit::FALSE:
            return 17799;
        default:
            return 0;
        }
    default:
        return 0;
    }
    return 0;
}
}

}
