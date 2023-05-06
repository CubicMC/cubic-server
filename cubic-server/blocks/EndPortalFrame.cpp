#include "EndPortalFrame.hpp"
namespace Blocks {
namespace EndPortalFrame {
BlockId toProtocol(Properties::Eye eye, Properties::Facing facing) {
    switch (eye) {
    case Properties::Eye::TRUE:
        switch (facing) {
        case Properties::Facing::NORTH:
            return 7177;
        case Properties::Facing::SOUTH:
            return 7178;
        case Properties::Facing::WEST:
            return 7179;
        case Properties::Facing::EAST:
            return 7180;
        default:
            return 0;
        }
    case Properties::Eye::FALSE:
        switch (facing) {
        case Properties::Facing::NORTH:
            return 7181;
        case Properties::Facing::SOUTH:
            return 7182;
        case Properties::Facing::WEST:
            return 7183;
        case Properties::Facing::EAST:
            return 7184;
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
