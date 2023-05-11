#include "SpruceButton.hpp"
namespace Blocks {
namespace SpruceButton {
BlockId toProtocol(Properties::Face face, Properties::Facing facing, Properties::Powered powered)
{
    switch (face) {
    case Properties::Face::FLOOR:
        switch (facing) {
        case Properties::Facing::NORTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8403;
            case Properties::Powered::FALSE:
                return 8404;
            default:
                return 0;
            }
        case Properties::Facing::SOUTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8405;
            case Properties::Powered::FALSE:
                return 8406;
            default:
                return 0;
            }
        case Properties::Facing::WEST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8407;
            case Properties::Powered::FALSE:
                return 8408;
            default:
                return 0;
            }
        case Properties::Facing::EAST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8409;
            case Properties::Powered::FALSE:
                return 8410;
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
                return 8411;
            case Properties::Powered::FALSE:
                return 8412;
            default:
                return 0;
            }
        case Properties::Facing::SOUTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8413;
            case Properties::Powered::FALSE:
                return 8414;
            default:
                return 0;
            }
        case Properties::Facing::WEST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8415;
            case Properties::Powered::FALSE:
                return 8416;
            default:
                return 0;
            }
        case Properties::Facing::EAST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8417;
            case Properties::Powered::FALSE:
                return 8418;
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
                return 8419;
            case Properties::Powered::FALSE:
                return 8420;
            default:
                return 0;
            }
        case Properties::Facing::SOUTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8421;
            case Properties::Powered::FALSE:
                return 8422;
            default:
                return 0;
            }
        case Properties::Facing::WEST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8423;
            case Properties::Powered::FALSE:
                return 8424;
            default:
                return 0;
            }
        case Properties::Facing::EAST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8425;
            case Properties::Powered::FALSE:
                return 8426;
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
