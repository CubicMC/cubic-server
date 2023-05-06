#include "AcaciaFenceGate.hpp"
namespace Blocks {
namespace AcaciaFenceGate {
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
                    return 10923;
                case Properties::Powered::FALSE:
                    return 10924;
                default:
                    return 0;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10925;
                case Properties::Powered::FALSE:
                    return 10926;
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
                    return 10927;
                case Properties::Powered::FALSE:
                    return 10928;
                default:
                    return 0;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10929;
                case Properties::Powered::FALSE:
                    return 10930;
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
                    return 10931;
                case Properties::Powered::FALSE:
                    return 10932;
                default:
                    return 0;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10933;
                case Properties::Powered::FALSE:
                    return 10934;
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
                    return 10935;
                case Properties::Powered::FALSE:
                    return 10936;
                default:
                    return 0;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10937;
                case Properties::Powered::FALSE:
                    return 10938;
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
                    return 10939;
                case Properties::Powered::FALSE:
                    return 10940;
                default:
                    return 0;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10941;
                case Properties::Powered::FALSE:
                    return 10942;
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
                    return 10943;
                case Properties::Powered::FALSE:
                    return 10944;
                default:
                    return 0;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10945;
                case Properties::Powered::FALSE:
                    return 10946;
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
                    return 10947;
                case Properties::Powered::FALSE:
                    return 10948;
                default:
                    return 0;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10949;
                case Properties::Powered::FALSE:
                    return 10950;
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
                    return 10951;
                case Properties::Powered::FALSE:
                    return 10952;
                default:
                    return 0;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10953;
                case Properties::Powered::FALSE:
                    return 10954;
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
