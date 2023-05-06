#include "Campfire.hpp"
namespace Blocks {
namespace Campfire {
BlockId toProtocol(Properties::Facing facing, Properties::Lit lit, Properties::Signal_fire signal_fire, Properties::Waterlogged waterlogged) {
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (lit) {
        case Properties::Lit::TRUE:
            switch (signal_fire) {
            case Properties::Signal_fire::TRUE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 17883;
                case Properties::Waterlogged::FALSE:
                    return 17884;
                default:
                    return 0;
                }
            case Properties::Signal_fire::FALSE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 17885;
                case Properties::Waterlogged::FALSE:
                    return 17886;
                default:
                    return 0;
                }
            default:
                return 0;
            }
        case Properties::Lit::FALSE:
            switch (signal_fire) {
            case Properties::Signal_fire::TRUE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 17887;
                case Properties::Waterlogged::FALSE:
                    return 17888;
                default:
                    return 0;
                }
            case Properties::Signal_fire::FALSE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 17889;
                case Properties::Waterlogged::FALSE:
                    return 17890;
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
        switch (lit) {
        case Properties::Lit::TRUE:
            switch (signal_fire) {
            case Properties::Signal_fire::TRUE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 17891;
                case Properties::Waterlogged::FALSE:
                    return 17892;
                default:
                    return 0;
                }
            case Properties::Signal_fire::FALSE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 17893;
                case Properties::Waterlogged::FALSE:
                    return 17894;
                default:
                    return 0;
                }
            default:
                return 0;
            }
        case Properties::Lit::FALSE:
            switch (signal_fire) {
            case Properties::Signal_fire::TRUE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 17895;
                case Properties::Waterlogged::FALSE:
                    return 17896;
                default:
                    return 0;
                }
            case Properties::Signal_fire::FALSE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 17897;
                case Properties::Waterlogged::FALSE:
                    return 17898;
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
        switch (lit) {
        case Properties::Lit::TRUE:
            switch (signal_fire) {
            case Properties::Signal_fire::TRUE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 17899;
                case Properties::Waterlogged::FALSE:
                    return 17900;
                default:
                    return 0;
                }
            case Properties::Signal_fire::FALSE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 17901;
                case Properties::Waterlogged::FALSE:
                    return 17902;
                default:
                    return 0;
                }
            default:
                return 0;
            }
        case Properties::Lit::FALSE:
            switch (signal_fire) {
            case Properties::Signal_fire::TRUE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 17903;
                case Properties::Waterlogged::FALSE:
                    return 17904;
                default:
                    return 0;
                }
            case Properties::Signal_fire::FALSE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 17905;
                case Properties::Waterlogged::FALSE:
                    return 17906;
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
        switch (lit) {
        case Properties::Lit::TRUE:
            switch (signal_fire) {
            case Properties::Signal_fire::TRUE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 17907;
                case Properties::Waterlogged::FALSE:
                    return 17908;
                default:
                    return 0;
                }
            case Properties::Signal_fire::FALSE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 17909;
                case Properties::Waterlogged::FALSE:
                    return 17910;
                default:
                    return 0;
                }
            default:
                return 0;
            }
        case Properties::Lit::FALSE:
            switch (signal_fire) {
            case Properties::Signal_fire::TRUE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 17911;
                case Properties::Waterlogged::FALSE:
                    return 17912;
                default:
                    return 0;
                }
            case Properties::Signal_fire::FALSE:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 17913;
                case Properties::Waterlogged::FALSE:
                    return 17914;
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
