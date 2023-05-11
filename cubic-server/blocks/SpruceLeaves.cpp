#include "SpruceLeaves.hpp"
namespace Blocks {
namespace SpruceLeaves {
BlockId toProtocol(Properties::Distance distance, Properties::Persistent persistent, Properties::Waterlogged waterlogged)
{
    switch (distance) {
    case Properties::Distance::ONE:
        switch (persistent) {
        case Properties::Persistent::TRUE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 242;
            case Properties::Waterlogged::FALSE:
                return 243;
            default:
                return 0;
            }
        case Properties::Persistent::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 244;
            case Properties::Waterlogged::FALSE:
                return 245;
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
                return 246;
            case Properties::Waterlogged::FALSE:
                return 247;
            default:
                return 0;
            }
        case Properties::Persistent::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 248;
            case Properties::Waterlogged::FALSE:
                return 249;
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
                return 250;
            case Properties::Waterlogged::FALSE:
                return 251;
            default:
                return 0;
            }
        case Properties::Persistent::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 252;
            case Properties::Waterlogged::FALSE:
                return 253;
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
                return 254;
            case Properties::Waterlogged::FALSE:
                return 255;
            default:
                return 0;
            }
        case Properties::Persistent::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 256;
            case Properties::Waterlogged::FALSE:
                return 257;
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
                return 258;
            case Properties::Waterlogged::FALSE:
                return 259;
            default:
                return 0;
            }
        case Properties::Persistent::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 260;
            case Properties::Waterlogged::FALSE:
                return 261;
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
                return 262;
            case Properties::Waterlogged::FALSE:
                return 263;
            default:
                return 0;
            }
        case Properties::Persistent::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 264;
            case Properties::Waterlogged::FALSE:
                return 265;
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
                return 266;
            case Properties::Waterlogged::FALSE:
                return 267;
            default:
                return 0;
            }
        case Properties::Persistent::FALSE:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 268;
            case Properties::Waterlogged::FALSE:
                return 269;
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
