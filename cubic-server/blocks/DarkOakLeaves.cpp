#include "DarkOakLeaves.hpp"
namespace Blocks {
    namespace DarkOakLeaves {
        BlockId toProtocol(Properties::Distance distance, Properties::Persistent persistent, Properties::Waterlogged waterlogged) {
            switch (distance) {
            case Properties::Distance::ONE:
                switch (persistent) {
                case Properties::Persistent::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 354;
                    case Properties::Waterlogged::FALSE:
                        return 355;
                    default:
                        return 0;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 356;
                    case Properties::Waterlogged::FALSE:
                        return 357;
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
                        return 358;
                    case Properties::Waterlogged::FALSE:
                        return 359;
                    default:
                        return 0;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 360;
                    case Properties::Waterlogged::FALSE:
                        return 361;
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
                        return 362;
                    case Properties::Waterlogged::FALSE:
                        return 363;
                    default:
                        return 0;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 364;
                    case Properties::Waterlogged::FALSE:
                        return 365;
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
                        return 366;
                    case Properties::Waterlogged::FALSE:
                        return 367;
                    default:
                        return 0;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 368;
                    case Properties::Waterlogged::FALSE:
                        return 369;
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
                        return 370;
                    case Properties::Waterlogged::FALSE:
                        return 371;
                    default:
                        return 0;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 372;
                    case Properties::Waterlogged::FALSE:
                        return 373;
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
                        return 374;
                    case Properties::Waterlogged::FALSE:
                        return 375;
                    default:
                        return 0;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 376;
                    case Properties::Waterlogged::FALSE:
                        return 377;
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
                        return 378;
                    case Properties::Waterlogged::FALSE:
                        return 379;
                    default:
                        return 0;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 380;
                    case Properties::Waterlogged::FALSE:
                        return 381;
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
