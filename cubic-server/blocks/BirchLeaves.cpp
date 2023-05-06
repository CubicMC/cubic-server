#include "BirchLeaves.hpp"
namespace Blocks {
namespace BirchLeaves {
BlockId toProtocol(Properties::Distance distance, Properties::Persistent persistent, Properties::Waterlogged waterlogged)
{
    switch (distance) {
    case Properties::Distance::ONE:
        switch (persistent) {
        case Properties::Persistent::TRUE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 270;
            case Properties::Waterlogged::FALSE:
                return 271;
            default:
                return 0;
            }
        case Properties::Persistent::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 272;
            case Properties::Waterlogged::FALSE:
                return 273;
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
                return 274;
            case Properties::Waterlogged::FALSE:
                return 275;
            default:
                return 0;
            }
        case Properties::Persistent::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 276;
            case Properties::Waterlogged::FALSE:
                return 277;
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
                return 278;
            case Properties::Waterlogged::FALSE:
                return 279;
            default:
                return 0;
            }
        case Properties::Persistent::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 280;
            case Properties::Waterlogged::FALSE:
                return 281;
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
                return 282;
            case Properties::Waterlogged::FALSE:
                return 283;
            default:
                return 0;
            }
        case Properties::Persistent::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 284;
            case Properties::Waterlogged::FALSE:
                return 285;
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
                return 286;
            case Properties::Waterlogged::FALSE:
                return 287;
            default:
                return 0;
            }
        case Properties::Persistent::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 288;
            case Properties::Waterlogged::FALSE:
                return 289;
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
                return 290;
            case Properties::Waterlogged::FALSE:
                return 291;
            default:
                return 0;
            }
        case Properties::Persistent::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 292;
            case Properties::Waterlogged::FALSE:
                return 293;
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
                return 294;
            case Properties::Waterlogged::FALSE:
                return 295;
            default:
                return 0;
            }
        case Properties::Persistent::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 296;
            case Properties::Waterlogged::FALSE:
                return 297;
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
