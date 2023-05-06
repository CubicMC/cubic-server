#include "TrappedChest.hpp"
namespace Blocks {
namespace TrappedChest {
BlockId toProtocol(Properties::Type type, Properties::Facing facing, Properties::Waterlogged waterlogged) {
    switch (type) {
    case Properties::Type::SINGLE:
        switch (facing) {
        case Properties::Facing::NORTH:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 8723;
            case Properties::Waterlogged::FALSE:
                return 8724;
            default:
                return 0;
            }
        case Properties::Facing::SOUTH:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 8729;
            case Properties::Waterlogged::FALSE:
                return 8730;
            default:
                return 0;
            }
        case Properties::Facing::WEST:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 8735;
            case Properties::Waterlogged::FALSE:
                return 8736;
            default:
                return 0;
            }
        case Properties::Facing::EAST:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 8741;
            case Properties::Waterlogged::FALSE:
                return 8742;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Type::LEFT:
        switch (facing) {
        case Properties::Facing::NORTH:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 8725;
            case Properties::Waterlogged::FALSE:
                return 8726;
            default:
                return 0;
            }
        case Properties::Facing::SOUTH:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 8731;
            case Properties::Waterlogged::FALSE:
                return 8732;
            default:
                return 0;
            }
        case Properties::Facing::WEST:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 8737;
            case Properties::Waterlogged::FALSE:
                return 8738;
            default:
                return 0;
            }
        case Properties::Facing::EAST:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 8743;
            case Properties::Waterlogged::FALSE:
                return 8744;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Type::RIGHT:
        switch (facing) {
        case Properties::Facing::NORTH:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 8727;
            case Properties::Waterlogged::FALSE:
                return 8728;
            default:
                return 0;
            }
        case Properties::Facing::SOUTH:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 8733;
            case Properties::Waterlogged::FALSE:
                return 8734;
            default:
                return 0;
            }
        case Properties::Facing::WEST:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 8739;
            case Properties::Waterlogged::FALSE:
                return 8740;
            default:
                return 0;
            }
        case Properties::Facing::EAST:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 8745;
            case Properties::Waterlogged::FALSE:
                return 8746;
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
