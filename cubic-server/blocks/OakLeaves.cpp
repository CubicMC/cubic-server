#include "OakLeaves.hpp"
namespace Blocks {
namespace OakLeaves {
BlockId toProtocol(Properties::Distance distance, Properties::Persistent persistent, Properties::Waterlogged waterlogged)
{
    switch (distance) {
    case Properties::Distance::ONE:
        switch (persistent) {
        case Properties::Persistent::TRUE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 214;
            case Properties::Waterlogged::FALSE:
                return 215;
            default:
                return 0;
            }
        case Properties::Persistent::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 216;
            case Properties::Waterlogged::FALSE:
                return 217;
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
                return 218;
            case Properties::Waterlogged::FALSE:
                return 219;
            default:
                return 0;
            }
        case Properties::Persistent::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 220;
            case Properties::Waterlogged::FALSE:
                return 221;
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
                return 222;
            case Properties::Waterlogged::FALSE:
                return 223;
            default:
                return 0;
            }
        case Properties::Persistent::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 224;
            case Properties::Waterlogged::FALSE:
                return 225;
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
                return 226;
            case Properties::Waterlogged::FALSE:
                return 227;
            default:
                return 0;
            }
        case Properties::Persistent::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 228;
            case Properties::Waterlogged::FALSE:
                return 229;
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
                return 230;
            case Properties::Waterlogged::FALSE:
                return 231;
            default:
                return 0;
            }
        case Properties::Persistent::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 232;
            case Properties::Waterlogged::FALSE:
                return 233;
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
                return 234;
            case Properties::Waterlogged::FALSE:
                return 235;
            default:
                return 0;
            }
        case Properties::Persistent::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 236;
            case Properties::Waterlogged::FALSE:
                return 237;
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
                return 238;
            case Properties::Waterlogged::FALSE:
                return 239;
            default:
                return 0;
            }
        case Properties::Persistent::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 240;
            case Properties::Waterlogged::FALSE:
                return 241;
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
