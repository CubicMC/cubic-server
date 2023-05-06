#include "PurpleCandle.hpp"
namespace Blocks {
namespace PurpleCandle {
BlockId toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged) {
    switch (candles) {
    case Properties::Candles::ONE:
        switch (lit) {
        case Properties::Lit::TRUE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20273;
            case Properties::Waterlogged::FALSE:
                return 20274;
            default:
                return 0;
            }
        case Properties::Lit::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20275;
            case Properties::Waterlogged::FALSE:
                return 20276;
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
                return 20277;
            case Properties::Waterlogged::FALSE:
                return 20278;
            default:
                return 0;
            }
        case Properties::Lit::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20279;
            case Properties::Waterlogged::FALSE:
                return 20280;
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
                return 20281;
            case Properties::Waterlogged::FALSE:
                return 20282;
            default:
                return 0;
            }
        case Properties::Lit::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20283;
            case Properties::Waterlogged::FALSE:
                return 20284;
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
                return 20285;
            case Properties::Waterlogged::FALSE:
                return 20286;
            default:
                return 0;
            }
        case Properties::Lit::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20287;
            case Properties::Waterlogged::FALSE:
                return 20288;
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
