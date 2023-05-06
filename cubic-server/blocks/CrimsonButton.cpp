#include "CrimsonButton.hpp"
namespace Blocks {
namespace CrimsonButton {
BlockId toProtocol(Properties::Face face, Properties::Facing facing, Properties::Powered powered) {
    switch (face) {
    case Properties::Face::FLOOR:
        switch (facing) {
        case Properties::Facing::NORTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 18472;
            case Properties::Powered::FALSE:
                return 18473;
            default:
                return 0;
            }
        case Properties::Facing::SOUTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 18474;
            case Properties::Powered::FALSE:
                return 18475;
            default:
                return 0;
            }
        case Properties::Facing::WEST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 18476;
            case Properties::Powered::FALSE:
                return 18477;
            default:
                return 0;
            }
        case Properties::Facing::EAST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 18478;
            case Properties::Powered::FALSE:
                return 18479;
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
                return 18480;
            case Properties::Powered::FALSE:
                return 18481;
            default:
                return 0;
            }
        case Properties::Facing::SOUTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 18482;
            case Properties::Powered::FALSE:
                return 18483;
            default:
                return 0;
            }
        case Properties::Facing::WEST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 18484;
            case Properties::Powered::FALSE:
                return 18485;
            default:
                return 0;
            }
        case Properties::Facing::EAST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 18486;
            case Properties::Powered::FALSE:
                return 18487;
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
                return 18488;
            case Properties::Powered::FALSE:
                return 18489;
            default:
                return 0;
            }
        case Properties::Facing::SOUTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 18490;
            case Properties::Powered::FALSE:
                return 18491;
            default:
                return 0;
            }
        case Properties::Facing::WEST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 18492;
            case Properties::Powered::FALSE:
                return 18493;
            default:
                return 0;
            }
        case Properties::Facing::EAST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 18494;
            case Properties::Powered::FALSE:
                return 18495;
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
