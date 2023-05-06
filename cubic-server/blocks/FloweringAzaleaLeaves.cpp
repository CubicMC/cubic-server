#include "FloweringAzaleaLeaves.hpp"
namespace Blocks {
namespace FloweringAzaleaLeaves {
BlockId toProtocol(Properties::Distance distance, Properties::Persistent persistent, Properties::Waterlogged waterlogged)
{
    switch (distance) {
    case Properties::Distance::ONE:
        switch (persistent) {
        case Properties::Persistent::TRUE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 438;
            case Properties::Waterlogged::FALSE:
                return 439;
            default:
                return 0;
            }
        case Properties::Persistent::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 440;
            case Properties::Waterlogged::FALSE:
                return 441;
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
                return 442;
            case Properties::Waterlogged::FALSE:
                return 443;
            default:
                return 0;
            }
        case Properties::Persistent::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 444;
            case Properties::Waterlogged::FALSE:
                return 445;
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
                return 446;
            case Properties::Waterlogged::FALSE:
                return 447;
            default:
                return 0;
            }
        case Properties::Persistent::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 448;
            case Properties::Waterlogged::FALSE:
                return 449;
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
                return 450;
            case Properties::Waterlogged::FALSE:
                return 451;
            default:
                return 0;
            }
        case Properties::Persistent::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 452;
            case Properties::Waterlogged::FALSE:
                return 453;
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
                return 454;
            case Properties::Waterlogged::FALSE:
                return 455;
            default:
                return 0;
            }
        case Properties::Persistent::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 456;
            case Properties::Waterlogged::FALSE:
                return 457;
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
                return 458;
            case Properties::Waterlogged::FALSE:
                return 459;
            default:
                return 0;
            }
        case Properties::Persistent::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 460;
            case Properties::Waterlogged::FALSE:
                return 461;
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
                return 462;
            case Properties::Waterlogged::FALSE:
                return 463;
            default:
                return 0;
            }
        case Properties::Persistent::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 464;
            case Properties::Waterlogged::FALSE:
                return 465;
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
