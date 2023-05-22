#include "Chest.hpp"
namespace Blocks {
namespace Chest {
BlockId toProtocol(Properties::Type type, Properties::Facing facing, Properties::Waterlogged waterlogged)
{
    switch (type) {
    case Properties::Type::SINGLE:
        switch (facing) {
        case Properties::Facing::NORTH:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 2902;
            case Properties::Waterlogged::FALSE:
                return 2903;
            default:
                return 0;
            }
        case Properties::Facing::SOUTH:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 2908;
            case Properties::Waterlogged::FALSE:
                return 2909;
            default:
                return 0;
            }
        case Properties::Facing::WEST:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 2914;
            case Properties::Waterlogged::FALSE:
                return 2915;
            default:
                return 0;
            }
        case Properties::Facing::EAST:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 2920;
            case Properties::Waterlogged::FALSE:
                return 2921;
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
                return 2904;
            case Properties::Waterlogged::FALSE:
                return 2905;
            default:
                return 0;
            }
        case Properties::Facing::SOUTH:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 2910;
            case Properties::Waterlogged::FALSE:
                return 2911;
            default:
                return 0;
            }
        case Properties::Facing::WEST:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 2916;
            case Properties::Waterlogged::FALSE:
                return 2917;
            default:
                return 0;
            }
        case Properties::Facing::EAST:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 2922;
            case Properties::Waterlogged::FALSE:
                return 2923;
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
                return 2906;
            case Properties::Waterlogged::FALSE:
                return 2907;
            default:
                return 0;
            }
        case Properties::Facing::SOUTH:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 2912;
            case Properties::Waterlogged::FALSE:
                return 2913;
            default:
                return 0;
            }
        case Properties::Facing::WEST:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 2918;
            case Properties::Waterlogged::FALSE:
                return 2919;
            default:
                return 0;
            }
        case Properties::Facing::EAST:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 2924;
            case Properties::Waterlogged::FALSE:
                return 2925;
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
