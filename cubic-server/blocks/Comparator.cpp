#include "Comparator.hpp"
namespace Blocks {
namespace Comparator {
BlockId toProtocol(Properties::Facing facing, Properties::Mode mode, Properties::Powered powered) {
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (mode) {
        case Properties::Mode::COMPARE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8779;
            case Properties::Powered::FALSE:
                return 8780;
            default:
                return 0;
            }
        case Properties::Mode::SUBTRACT:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8781;
            case Properties::Powered::FALSE:
                return 8782;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Facing::SOUTH:
        switch (mode) {
        case Properties::Mode::COMPARE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8783;
            case Properties::Powered::FALSE:
                return 8784;
            default:
                return 0;
            }
        case Properties::Mode::SUBTRACT:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8785;
            case Properties::Powered::FALSE:
                return 8786;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Facing::WEST:
        switch (mode) {
        case Properties::Mode::COMPARE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8787;
            case Properties::Powered::FALSE:
                return 8788;
            default:
                return 0;
            }
        case Properties::Mode::SUBTRACT:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8789;
            case Properties::Powered::FALSE:
                return 8790;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Facing::EAST:
        switch (mode) {
        case Properties::Mode::COMPARE:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8791;
            case Properties::Powered::FALSE:
                return 8792;
            default:
                return 0;
            }
        case Properties::Mode::SUBTRACT:
            switch (powered) {
            case Properties::Powered::TRUE:
                return 8793;
            case Properties::Powered::FALSE:
                return 8794;
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
