#include "JungleLeaves.hpp"
namespace Blocks {
    namespace JungleLeaves {
        BlockId toProtocol(Properties::Distance distance, Properties::Persistent persistent, Properties::Waterlogged waterlogged) {
            switch (distance) {
            case Properties::Distance::ONE:
                switch (persistent) {
                case Properties::Persistent::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 298;
                    case Properties::Waterlogged::FALSE:
                        return 299;
                    default:
                        return 0;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 300;
                    case Properties::Waterlogged::FALSE:
                        return 301;
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
                        return 302;
                    case Properties::Waterlogged::FALSE:
                        return 303;
                    default:
                        return 0;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 304;
                    case Properties::Waterlogged::FALSE:
                        return 305;
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
                        return 306;
                    case Properties::Waterlogged::FALSE:
                        return 307;
                    default:
                        return 0;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 308;
                    case Properties::Waterlogged::FALSE:
                        return 309;
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
                        return 310;
                    case Properties::Waterlogged::FALSE:
                        return 311;
                    default:
                        return 0;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 312;
                    case Properties::Waterlogged::FALSE:
                        return 313;
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
                        return 314;
                    case Properties::Waterlogged::FALSE:
                        return 315;
                    default:
                        return 0;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 316;
                    case Properties::Waterlogged::FALSE:
                        return 317;
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
                        return 318;
                    case Properties::Waterlogged::FALSE:
                        return 319;
                    default:
                        return 0;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 320;
                    case Properties::Waterlogged::FALSE:
                        return 321;
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
                        return 322;
                    case Properties::Waterlogged::FALSE:
                        return 323;
                    default:
                        return 0;
                    }
                case Properties::Persistent::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 324;
                    case Properties::Waterlogged::FALSE:
                        return 325;
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
