#include "LightGrayCandle.hpp"
namespace Blocks {
namespace LightGrayCandle {
BlockId toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged)
{
    switch (candles) {
    case Properties::Candles::ONE:
        switch (lit) {
        case Properties::Lit::TRUE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20241;
            case Properties::Waterlogged::FALSE:
                return 20242;
            default:
                return 0;
            }
        case Properties::Lit::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20243;
            case Properties::Waterlogged::FALSE:
                return 20244;
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
                return 20245;
            case Properties::Waterlogged::FALSE:
                return 20246;
            default:
                return 0;
            }
        case Properties::Lit::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20247;
            case Properties::Waterlogged::FALSE:
                return 20248;
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
                return 20249;
            case Properties::Waterlogged::FALSE:
                return 20250;
            default:
                return 0;
            }
        case Properties::Lit::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20251;
            case Properties::Waterlogged::FALSE:
                return 20252;
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
                return 20253;
            case Properties::Waterlogged::FALSE:
                return 20254;
            default:
                return 0;
            }
        case Properties::Lit::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20255;
            case Properties::Waterlogged::FALSE:
                return 20256;
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
