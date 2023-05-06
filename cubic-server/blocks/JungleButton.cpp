#include "JungleButton.hpp"
namespace Blocks {
namespace JungleButton {
BlockId toProtocol(Properties::Face face, Properties::Facing facing, Properties::Powered powered) {
    switch (face) {
    case Properties::Face::FLOOR:
        switch (facing) {
        case Properties::Facing::NORTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8451;
            case Properties::Powered::FALSE:
                return 8452;
            default:
                return 0;
            }
        case Properties::Facing::SOUTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8453;
            case Properties::Powered::FALSE:
                return 8454;
            default:
                return 0;
            }
        case Properties::Facing::WEST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8455;
            case Properties::Powered::FALSE:
                return 8456;
            default:
                return 0;
            }
        case Properties::Facing::EAST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8457;
            case Properties::Powered::FALSE:
                return 8458;
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
                return 8459;
            case Properties::Powered::FALSE:
                return 8460;
            default:
                return 0;
            }
        case Properties::Facing::SOUTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8461;
            case Properties::Powered::FALSE:
                return 8462;
            default:
                return 0;
            }
        case Properties::Facing::WEST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8463;
            case Properties::Powered::FALSE:
                return 8464;
            default:
                return 0;
            }
        case Properties::Facing::EAST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8465;
            case Properties::Powered::FALSE:
                return 8466;
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
                return 8467;
            case Properties::Powered::FALSE:
                return 8468;
            default:
                return 0;
            }
        case Properties::Facing::SOUTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8469;
            case Properties::Powered::FALSE:
                return 8470;
            default:
                return 0;
            }
        case Properties::Facing::WEST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8471;
            case Properties::Powered::FALSE:
                return 8472;
            default:
                return 0;
            }
        case Properties::Facing::EAST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8473;
            case Properties::Powered::FALSE:
                return 8474;
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
