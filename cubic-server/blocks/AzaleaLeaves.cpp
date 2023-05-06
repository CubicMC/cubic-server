#include "AzaleaLeaves.hpp"
namespace Blocks {
namespace AzaleaLeaves {
BlockId toProtocol(Properties::Distance distance, Properties::Persistent persistent, Properties::Waterlogged waterlogged)
{
    switch (distance) {
    case Properties::Distance::ONE:
        switch (persistent) {
        case Properties::Persistent::TRUE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 410;
            case Properties::Waterlogged::FALSE:
                return 411;
            default:
                return 0;
            }
        case Properties::Persistent::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 412;
            case Properties::Waterlogged::FALSE:
                return 413;
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
                return 414;
            case Properties::Waterlogged::FALSE:
                return 415;
            default:
                return 0;
            }
        case Properties::Persistent::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 416;
            case Properties::Waterlogged::FALSE:
                return 417;
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
                return 418;
            case Properties::Waterlogged::FALSE:
                return 419;
            default:
                return 0;
            }
        case Properties::Persistent::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 420;
            case Properties::Waterlogged::FALSE:
                return 421;
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
                return 422;
            case Properties::Waterlogged::FALSE:
                return 423;
            default:
                return 0;
            }
        case Properties::Persistent::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 424;
            case Properties::Waterlogged::FALSE:
                return 425;
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
                return 426;
            case Properties::Waterlogged::FALSE:
                return 427;
            default:
                return 0;
            }
        case Properties::Persistent::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 428;
            case Properties::Waterlogged::FALSE:
                return 429;
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
                return 430;
            case Properties::Waterlogged::FALSE:
                return 431;
            default:
                return 0;
            }
        case Properties::Persistent::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 432;
            case Properties::Waterlogged::FALSE:
                return 433;
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
                return 434;
            case Properties::Waterlogged::FALSE:
                return 435;
            default:
                return 0;
            }
        case Properties::Persistent::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 436;
            case Properties::Waterlogged::FALSE:
                return 437;
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
