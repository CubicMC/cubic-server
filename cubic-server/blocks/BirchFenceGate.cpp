#include "BirchFenceGate.hpp"
namespace Blocks {
namespace BirchFenceGate {
BlockId toProtocol(Properties::Facing facing, Properties::In_wall in_wall, Properties::Open open, Properties::Powered powered)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (in_wall) {
        case Properties::In_wall::TRUE:
            switch (open) {
            case Properties::Open::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10859;
                case Properties::Powered::FALSE:
                    return 10860;
                default:
                    return 0;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10861;
                case Properties::Powered::FALSE:
                    return 10862;
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
                    return 10863;
                case Properties::Powered::FALSE:
                    return 10864;
                default:
                    return 0;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10865;
                case Properties::Powered::FALSE:
                    return 10866;
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
                    return 10867;
                case Properties::Powered::FALSE:
                    return 10868;
                default:
                    return 0;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10869;
                case Properties::Powered::FALSE:
                    return 10870;
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
                    return 10871;
                case Properties::Powered::FALSE:
                    return 10872;
                default:
                    return 0;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10873;
                case Properties::Powered::FALSE:
                    return 10874;
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
                    return 10875;
                case Properties::Powered::FALSE:
                    return 10876;
                default:
                    return 0;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10877;
                case Properties::Powered::FALSE:
                    return 10878;
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
                    return 10879;
                case Properties::Powered::FALSE:
                    return 10880;
                default:
                    return 0;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10881;
                case Properties::Powered::FALSE:
                    return 10882;
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
                    return 10883;
                case Properties::Powered::FALSE:
                    return 10884;
                default:
                    return 0;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10885;
                case Properties::Powered::FALSE:
                    return 10886;
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
                    return 10887;
                case Properties::Powered::FALSE:
                    return 10888;
                default:
                    return 0;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10889;
                case Properties::Powered::FALSE:
                    return 10890;
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
