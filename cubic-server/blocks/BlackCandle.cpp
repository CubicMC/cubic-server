#include "BlackCandle.hpp"
#include <stdexcept>

namespace Blocks {
namespace BlackCandle {
BlockId toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged)
{
    switch (candles) {
    case Properties::Candles::ONE:
        switch (lit) {
        case Properties::Lit::TRUE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20353;
            case Properties::Waterlogged::FALSE:
                return 20354;
            }
        case Properties::Lit::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20355;
            case Properties::Waterlogged::FALSE:
                return 20356;
            }
        }
    case Properties::Candles::TWO:
        switch (lit) {
        case Properties::Lit::TRUE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20357;
            case Properties::Waterlogged::FALSE:
                return 20358;
            }
        case Properties::Lit::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20359;
            case Properties::Waterlogged::FALSE:
                return 20360;
            }
        }
    case Properties::Candles::THREE:
        switch (lit) {
        case Properties::Lit::TRUE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20361;
            case Properties::Waterlogged::FALSE:
                return 20362;
            }
        case Properties::Lit::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20363;
            case Properties::Waterlogged::FALSE:
                return 20364;
            }
        }
    case Properties::Candles::FOUR:
        switch (lit) {
        case Properties::Lit::TRUE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20365;
            case Properties::Waterlogged::FALSE:
                return 20366;
            }
        case Properties::Lit::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 20367;
            case Properties::Waterlogged::FALSE:
                return 20368;
            }
        }
    }
    return 0;
}
}

}
