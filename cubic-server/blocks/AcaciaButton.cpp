#include "AcaciaButton.hpp"
namespace Blocks {
namespace AcaciaButton {
BlockId toProtocol(Properties::Face face, Properties::Facing facing, Properties::Powered powered)
{
    switch (face) {
    case Properties::Face::FLOOR:
        switch (facing) {
        case Properties::Facing::NORTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8475;
            case Properties::Powered::FALSE:
                return 8476;
            default:
                return 0;
            }
        case Properties::Facing::SOUTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8477;
            case Properties::Powered::FALSE:
                return 8478;
            default:
                return 0;
            }
        case Properties::Facing::WEST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8479;
            case Properties::Powered::FALSE:
                return 8480;
            default:
                return 0;
            }
        case Properties::Facing::EAST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8481;
            case Properties::Powered::FALSE:
                return 8482;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Face::WALL:
        switch (facing) {
        case Properties::Facing::NORTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8483;
            case Properties::Powered::FALSE:
                return 8484;
            default:
                return 0;
            }
        case Properties::Facing::SOUTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8485;
            case Properties::Powered::FALSE:
                return 8486;
            default:
                return 0;
            }
        case Properties::Facing::WEST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8487;
            case Properties::Powered::FALSE:
                return 8488;
            default:
                return 0;
            }
        case Properties::Facing::EAST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8489;
            case Properties::Powered::FALSE:
                return 8490;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Face::CEILING:
        switch (facing) {
        case Properties::Facing::NORTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8491;
            case Properties::Powered::FALSE:
                return 8492;
            default:
                return 0;
            }
        case Properties::Facing::SOUTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8493;
            case Properties::Powered::FALSE:
                return 8494;
            default:
                return 0;
            }
        case Properties::Facing::WEST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8495;
            case Properties::Powered::FALSE:
                return 8496;
            default:
                return 0;
            }
        case Properties::Facing::EAST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8497;
            case Properties::Powered::FALSE:
                return 8498;
            default:
                return 0;
            }
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
