#include "LimeBed.hpp"
namespace Blocks {
namespace LimeBed {
BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (occupied) {
        case Properties::Occupied::TRUE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1717;
            case Properties::Part::FOOT:
                return 1718;
            default:
                return 0;
            }
        case Properties::Occupied::FALSE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1719;
            case Properties::Part::FOOT:
                return 1720;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Facing::SOUTH:
        switch (occupied) {
        case Properties::Occupied::TRUE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1721;
            case Properties::Part::FOOT:
                return 1722;
            default:
                return 0;
            }
        case Properties::Occupied::FALSE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1723;
            case Properties::Part::FOOT:
                return 1724;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Facing::WEST:
        switch (occupied) {
        case Properties::Occupied::TRUE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1725;
            case Properties::Part::FOOT:
                return 1726;
            default:
                return 0;
            }
        case Properties::Occupied::FALSE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1727;
            case Properties::Part::FOOT:
                return 1728;
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Facing::EAST:
        switch (occupied) {
        case Properties::Occupied::TRUE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1729;
            case Properties::Part::FOOT:
                return 1730;
            default:
                return 0;
            }
        case Properties::Occupied::FALSE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1731;
            case Properties::Part::FOOT:
                return 1732;
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
