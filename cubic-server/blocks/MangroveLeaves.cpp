#include "MangroveLeaves.hpp"
namespace Blocks {
    namespace MangroveLeaves {
        BlockId toProtocol(Properties::Distance distance, Properties::Persistent persistent, Properties::Waterlogged waterlogged) {
            switch (distance) {
            case Properties::Distance::ONE:
                switch (persistent) {
                case Properties::Persistent::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 382;
                    case Properties::Waterlogged::FALSE:
                        return 383;
                    default:
                        return 0;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 384;
                    case Properties::Waterlogged::FALSE:
                        return 385;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Distance::TWO:
                switch (persistent) {
                case Properties::Persistent::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 386;
                    case Properties::Waterlogged::FALSE:
                        return 387;
                    default:
                        return 0;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 388;
                    case Properties::Waterlogged::FALSE:
                        return 389;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Distance::THREE:
                switch (persistent) {
                case Properties::Persistent::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 390;
                    case Properties::Waterlogged::FALSE:
                        return 391;
                    default:
                        return 0;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 392;
                    case Properties::Waterlogged::FALSE:
                        return 393;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Distance::FOUR:
                switch (persistent) {
                case Properties::Persistent::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 394;
                    case Properties::Waterlogged::FALSE:
                        return 395;
                    default:
                        return 0;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 396;
                    case Properties::Waterlogged::FALSE:
                        return 397;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Distance::FIVE:
                switch (persistent) {
                case Properties::Persistent::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 398;
                    case Properties::Waterlogged::FALSE:
                        return 399;
                    default:
                        return 0;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 400;
                    case Properties::Waterlogged::FALSE:
                        return 401;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Distance::SIX:
                switch (persistent) {
                case Properties::Persistent::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 402;
                    case Properties::Waterlogged::FALSE:
                        return 403;
                    default:
                        return 0;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 404;
                    case Properties::Waterlogged::FALSE:
                        return 405;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Distance::SEVEN:
                switch (persistent) {
                case Properties::Persistent::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 406;
                    case Properties::Waterlogged::FALSE:
                        return 407;
                    default:
                        return 0;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 408;
                    case Properties::Waterlogged::FALSE:
                        return 409;
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
