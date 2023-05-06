#include "CyanCandle.hpp"
namespace Blocks {
    namespace CyanCandle {
        BlockId toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged) {
            switch (candles) {
            case Properties::Candles::ONE:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20257;
                    case Properties::Waterlogged::FALSE:
                        return 20258;
                    default:
                        return 0;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20259;
                    case Properties::Waterlogged::FALSE:
                        return 20260;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Candles::TWO:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20261;
                    case Properties::Waterlogged::FALSE:
                        return 20262;
                    default:
                        return 0;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20263;
                    case Properties::Waterlogged::FALSE:
                        return 20264;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Candles::THREE:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20265;
                    case Properties::Waterlogged::FALSE:
                        return 20266;
                    default:
                        return 0;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20267;
                    case Properties::Waterlogged::FALSE:
                        return 20268;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Candles::FOUR:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20269;
                    case Properties::Waterlogged::FALSE:
                        return 20270;
                    default:
                        return 0;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20271;
                    case Properties::Waterlogged::FALSE:
                        return 20272;
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
