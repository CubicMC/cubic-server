#include "AcaciaLeaves.hpp"
namespace Blocks {
    namespace AcaciaLeaves {
        BlockId toProtocol(Properties::Distance distance, Properties::Persistent persistent, Properties::Waterlogged waterlogged) {
            switch (distance) {
            case Properties::Distance::ONE:
                switch (persistent) {
                case Properties::Persistent::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 326;
                    case Properties::Waterlogged::FALSE:
                        return 327;
                    default:
                        return 0;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 328;
                    case Properties::Waterlogged::FALSE:
                        return 329;
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
                        return 330;
                    case Properties::Waterlogged::FALSE:
                        return 331;
                    default:
                        return 0;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 332;
                    case Properties::Waterlogged::FALSE:
                        return 333;
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
                        return 334;
                    case Properties::Waterlogged::FALSE:
                        return 335;
                    default:
                        return 0;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 336;
                    case Properties::Waterlogged::FALSE:
                        return 337;
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
                        return 338;
                    case Properties::Waterlogged::FALSE:
                        return 339;
                    default:
                        return 0;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 340;
                    case Properties::Waterlogged::FALSE:
                        return 341;
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
                        return 342;
                    case Properties::Waterlogged::FALSE:
                        return 343;
                    default:
                        return 0;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 344;
                    case Properties::Waterlogged::FALSE:
                        return 345;
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
                        return 346;
                    case Properties::Waterlogged::FALSE:
                        return 347;
                    default:
                        return 0;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 348;
                    case Properties::Waterlogged::FALSE:
                        return 349;
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
                        return 350;
                    case Properties::Waterlogged::FALSE:
                        return 351;
                    default:
                        return 0;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 352;
                    case Properties::Waterlogged::FALSE:
                        return 353;
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
