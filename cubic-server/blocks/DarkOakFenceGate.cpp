#include "DarkOakFenceGate.hpp"
namespace Blocks {
    namespace DarkOakFenceGate {
        BlockId toProtocol(Properties::Facing facing, Properties::In_wall in_wall, Properties::Open open, Properties::Powered powered) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (in_wall) {
                case Properties::In_wall::TRUE:
                    switch (open) {
                    case Properties::Open::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 10955;
                        case Properties::Powered::FALSE:
                            return 10956;
                        default:
                            return 0;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 10957;
                        case Properties::Powered::FALSE:
                            return 10958;
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
                            return 10959;
                        case Properties::Powered::FALSE:
                            return 10960;
                        default:
                            return 0;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 10961;
                        case Properties::Powered::FALSE:
                            return 10962;
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
                            return 10963;
                        case Properties::Powered::FALSE:
                            return 10964;
                        default:
                            return 0;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 10965;
                        case Properties::Powered::FALSE:
                            return 10966;
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
                            return 10967;
                        case Properties::Powered::FALSE:
                            return 10968;
                        default:
                            return 0;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 10969;
                        case Properties::Powered::FALSE:
                            return 10970;
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
                            return 10971;
                        case Properties::Powered::FALSE:
                            return 10972;
                        default:
                            return 0;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 10973;
                        case Properties::Powered::FALSE:
                            return 10974;
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
                            return 10975;
                        case Properties::Powered::FALSE:
                            return 10976;
                        default:
                            return 0;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 10977;
                        case Properties::Powered::FALSE:
                            return 10978;
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
                            return 10979;
                        case Properties::Powered::FALSE:
                            return 10980;
                        default:
                            return 0;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 10981;
                        case Properties::Powered::FALSE:
                            return 10982;
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
                            return 10983;
                        case Properties::Powered::FALSE:
                            return 10984;
                        default:
                            return 0;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 10985;
                        case Properties::Powered::FALSE:
                            return 10986;
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
