#include "WarpedFenceGate.hpp"
namespace Blocks {
    namespace WarpedFenceGate {
        BlockId toProtocol(Properties::Facing facing, Properties::In_wall in_wall, Properties::Open open, Properties::Powered powered) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (in_wall) {
                case Properties::In_wall::TRUE:
                    switch (open) {
                    case Properties::Open::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 18280;
                        case Properties::Powered::FALSE:
                            return 18281;
                        default:
                            return 0;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 18282;
                        case Properties::Powered::FALSE:
                            return 18283;
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
                            return 18284;
                        case Properties::Powered::FALSE:
                            return 18285;
                        default:
                            return 0;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 18286;
                        case Properties::Powered::FALSE:
                            return 18287;
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
                            return 18288;
                        case Properties::Powered::FALSE:
                            return 18289;
                        default:
                            return 0;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 18290;
                        case Properties::Powered::FALSE:
                            return 18291;
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
                            return 18292;
                        case Properties::Powered::FALSE:
                            return 18293;
                        default:
                            return 0;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 18294;
                        case Properties::Powered::FALSE:
                            return 18295;
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
                            return 18296;
                        case Properties::Powered::FALSE:
                            return 18297;
                        default:
                            return 0;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 18298;
                        case Properties::Powered::FALSE:
                            return 18299;
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
                            return 18300;
                        case Properties::Powered::FALSE:
                            return 18301;
                        default:
                            return 0;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 18302;
                        case Properties::Powered::FALSE:
                            return 18303;
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
                            return 18304;
                        case Properties::Powered::FALSE:
                            return 18305;
                        default:
                            return 0;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 18306;
                        case Properties::Powered::FALSE:
                            return 18307;
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
                            return 18308;
                        case Properties::Powered::FALSE:
                            return 18309;
                        default:
                            return 0;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 18310;
                        case Properties::Powered::FALSE:
                            return 18311;
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
