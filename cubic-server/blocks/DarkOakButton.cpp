#include "DarkOakButton.hpp"
namespace Blocks {
namespace DarkOakButton {
BlockId toProtocol(Properties::Face face, Properties::Facing facing, Properties::Powered powered) {
    switch (face) {
    case Properties::Face::FLOOR:
        switch (facing) {
        case Properties::Facing::NORTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8499;
            case Properties::Powered::FALSE:
                return 8500;
            default:
                return 0;
            }
        case Properties::Facing::SOUTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8501;
            case Properties::Powered::FALSE:
                return 8502;
            default:
                return 0;
            }
        case Properties::Facing::WEST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8503;
            case Properties::Powered::FALSE:
                return 8504;
            default:
                return 0;
            }
        case Properties::Facing::EAST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8505;
            case Properties::Powered::FALSE:
                return 8506;
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
                return 8507;
            case Properties::Powered::FALSE:
                return 8508;
            default:
                return 0;
            }
        case Properties::Facing::SOUTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8509;
            case Properties::Powered::FALSE:
                return 8510;
            default:
                return 0;
            }
        case Properties::Facing::WEST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8511;
            case Properties::Powered::FALSE:
                return 8512;
            default:
                return 0;
            }
        case Properties::Facing::EAST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8513;
            case Properties::Powered::FALSE:
                return 8514;
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
                return 8515;
            case Properties::Powered::FALSE:
                return 8516;
            default:
                return 0;
            }
        case Properties::Facing::SOUTH:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8517;
            case Properties::Powered::FALSE:
                return 8518;
            default:
                return 0;
            }
        case Properties::Facing::WEST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8519;
            case Properties::Powered::FALSE:
                return 8520;
            default:
                return 0;
            }
        case Properties::Facing::EAST:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8521;
            case Properties::Powered::FALSE:
                return 8522;
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
