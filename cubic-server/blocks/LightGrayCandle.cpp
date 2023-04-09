#include "LightGrayCandle.hpp"
#include <stdexcept>

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
            }
        case Properties::Lit::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20243;
            case Properties::Waterlogged::FALSE:
                return 20244;
            }
        }
    case Properties::Candles::TWO:
        switch (lit) {
        case Properties::Lit::TRUE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20245;
            case Properties::Waterlogged::FALSE:
                return 20246;
            }
        case Properties::Lit::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20247;
            case Properties::Waterlogged::FALSE:
                return 20248;
            }
        }
    case Properties::Candles::THREE:
        switch (lit) {
        case Properties::Lit::TRUE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20249;
            case Properties::Waterlogged::FALSE:
                return 20250;
            }
        case Properties::Lit::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20251;
            case Properties::Waterlogged::FALSE:
                return 20252;
            }
        }
    case Properties::Candles::FOUR:
        switch (lit) {
        case Properties::Lit::TRUE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20253;
            case Properties::Waterlogged::FALSE:
                return 20254;
            }
        case Properties::Lit::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20255;
            case Properties::Waterlogged::FALSE:
                return 20256;
            }
        }
    }
    return 0;
}
}

}
