#include "PointedDripstone.hpp"
namespace Blocks {
namespace PointedDripstone {
BlockId toProtocol(Properties::Thickness thickness, Properties::Vertical_direction vertical_direction, Properties::Waterlogged waterlogged) {
    switch (thickness) {
    case Properties::Thickness::TIP_MERGE:
        switch (vertical_direction) {
        case Properties::Vertical_direction::UP:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 21422;
            case Properties::Waterlogged::FALSE:
                return 21423;
            default:
                return 0;
            }
        case Properties::Vertical_direction::DOWN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 21424;
            case Properties::Waterlogged::FALSE:
                return 21425;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Thickness::TIP:
        switch (vertical_direction) {
        case Properties::Vertical_direction::UP:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 21426;
            case Properties::Waterlogged::FALSE:
                return 21427;
            default:
                return 0;
            }
        case Properties::Vertical_direction::DOWN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 21428;
            case Properties::Waterlogged::FALSE:
                return 21429;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Thickness::FRUSTUM:
        switch (vertical_direction) {
        case Properties::Vertical_direction::UP:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 21430;
            case Properties::Waterlogged::FALSE:
                return 21431;
            default:
                return 0;
            }
        case Properties::Vertical_direction::DOWN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 21432;
            case Properties::Waterlogged::FALSE:
                return 21433;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Thickness::MIDDLE:
        switch (vertical_direction) {
        case Properties::Vertical_direction::UP:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 21434;
            case Properties::Waterlogged::FALSE:
                return 21435;
            default:
                return 0;
            }
        case Properties::Vertical_direction::DOWN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 21436;
            case Properties::Waterlogged::FALSE:
                return 21437;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Thickness::BASE:
        switch (vertical_direction) {
        case Properties::Vertical_direction::UP:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 21438;
            case Properties::Waterlogged::FALSE:
                return 21439;
            default:
                return 0;
            }
        case Properties::Vertical_direction::DOWN:
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 21440;
            case Properties::Waterlogged::FALSE:
                return 21441;
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
