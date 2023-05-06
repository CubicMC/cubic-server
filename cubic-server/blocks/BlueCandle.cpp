#include "BlueCandle.hpp"
namespace Blocks {
namespace BlueCandle {
BlockId toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged)
{
    switch (candles) {
    case Properties::Candles::ONE:
        switch (lit) {
        case Properties::Lit::TRUE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20289;
            case Properties::Waterlogged::FALSE:
                return 20290;
            default:
                return 0;
            }
        case Properties::Lit::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20291;
            case Properties::Waterlogged::FALSE:
                return 20292;
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
                return 20293;
            case Properties::Waterlogged::FALSE:
                return 20294;
            default:
                return 0;
            }
        case Properties::Lit::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20295;
            case Properties::Waterlogged::FALSE:
                return 20296;
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
                return 20297;
            case Properties::Waterlogged::FALSE:
                return 20298;
            default:
                return 0;
            }
        case Properties::Lit::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20299;
            case Properties::Waterlogged::FALSE:
                return 20300;
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
                return 20301;
            case Properties::Waterlogged::FALSE:
                return 20302;
            default:
                return 0;
            }
        case Properties::Lit::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20303;
            case Properties::Waterlogged::FALSE:
                return 20304;
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
