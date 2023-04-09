#include "OrangeCandle.hpp"
#include <stdexcept>

namespace Blocks {
namespace OrangeCandle {
BlockId toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged)
{
    switch (candles) {
    case Properties::Candles::ONE:
        switch (lit) {
        case Properties::Lit::TRUE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20129;
            case Properties::Waterlogged::FALSE:
                return 20130;
            }
        case Properties::Lit::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20131;
            case Properties::Waterlogged::FALSE:
                return 20132;
            }
        }
    case Properties::Candles::TWO:
        switch (lit) {
        case Properties::Lit::TRUE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20133;
            case Properties::Waterlogged::FALSE:
                return 20134;
            }
        case Properties::Lit::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20135;
            case Properties::Waterlogged::FALSE:
                return 20136;
            }
        }
    case Properties::Candles::THREE:
        switch (lit) {
        case Properties::Lit::TRUE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20137;
            case Properties::Waterlogged::FALSE:
                return 20138;
            }
        case Properties::Lit::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20139;
            case Properties::Waterlogged::FALSE:
                return 20140;
            }
        }
    case Properties::Candles::FOUR:
        switch (lit) {
        case Properties::Lit::TRUE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20141;
            case Properties::Waterlogged::FALSE:
                return 20142;
            }
        case Properties::Lit::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20143;
            case Properties::Waterlogged::FALSE:
                return 20144;
            }
        }
    }
    return 0;
}
}

}
