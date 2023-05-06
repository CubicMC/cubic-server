#include "MangroveFenceGate.hpp"
namespace Blocks {
namespace MangroveFenceGate {
BlockId toProtocol(Properties::Facing facing, Properties::In_wall in_wall, Properties::Open open, Properties::Powered powered) {
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (in_wall) {
        case Properties::In_wall::TRUE:
            switch (open) {
            case Properties::Open::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10987;
                case Properties::Powered::FALSE:
                    return 10988;
                default:
                    return 0;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10989;
                case Properties::Powered::FALSE:
                    return 10990;
                default:
                    return 0;
                }
            default:
                return 0;
            }
        case Properties::In_wall::FALSE:
            switch (open) {
            case Properties::Open::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10991;
                case Properties::Powered::FALSE:
                    return 10992;
                default:
                    return 0;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10993;
                case Properties::Powered::FALSE:
                    return 10994;
                default:
                    return 0;
                }
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Facing::SOUTH:
        switch (in_wall) {
        case Properties::In_wall::TRUE:
            switch (open) {
            case Properties::Open::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10995;
                case Properties::Powered::FALSE:
                    return 10996;
                default:
                    return 0;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10997;
                case Properties::Powered::FALSE:
                    return 10998;
                default:
                    return 0;
                }
            default:
                return 0;
            }
        case Properties::In_wall::FALSE:
            switch (open) {
            case Properties::Open::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10999;
                case Properties::Powered::FALSE:
                    return 11000;
                default:
                    return 0;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 11001;
                case Properties::Powered::FALSE:
                    return 11002;
                default:
                    return 0;
                }
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Facing::WEST:
        switch (in_wall) {
        case Properties::In_wall::TRUE:
            switch (open) {
            case Properties::Open::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 11003;
                case Properties::Powered::FALSE:
                    return 11004;
                default:
                    return 0;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 11005;
                case Properties::Powered::FALSE:
                    return 11006;
                default:
                    return 0;
                }
            default:
                return 0;
            }
        case Properties::In_wall::FALSE:
            switch (open) {
            case Properties::Open::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 11007;
                case Properties::Powered::FALSE:
                    return 11008;
                default:
                    return 0;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 11009;
                case Properties::Powered::FALSE:
                    return 11010;
                default:
                    return 0;
                }
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Facing::EAST:
        switch (in_wall) {
        case Properties::In_wall::TRUE:
            switch (open) {
            case Properties::Open::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 11011;
                case Properties::Powered::FALSE:
                    return 11012;
                default:
                    return 0;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 11013;
                case Properties::Powered::FALSE:
                    return 11014;
                default:
                    return 0;
                }
            default:
                return 0;
            }
        case Properties::In_wall::FALSE:
            switch (open) {
            case Properties::Open::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 11015;
                case Properties::Powered::FALSE:
                    return 11016;
                default:
                    return 0;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 11017;
                case Properties::Powered::FALSE:
                    return 11018;
                default:
                    return 0;
                }
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
