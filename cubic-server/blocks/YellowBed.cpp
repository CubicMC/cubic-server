#include "YellowBed.hpp"
namespace Blocks {
namespace YellowBed {
BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part) {
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (occupied) {
        case Properties::Occupied::TRUE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1701;
            case Properties::Part::FOOT:
                return 1702;
            default:
                return 0;
            }
        case Properties::Occupied::FALSE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1703;
            case Properties::Part::FOOT:
                return 1704;
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
                return 1705;
            case Properties::Part::FOOT:
                return 1706;
            default:
                return 0;
            }
        case Properties::Occupied::FALSE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1707;
            case Properties::Part::FOOT:
                return 1708;
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
                return 1709;
            case Properties::Part::FOOT:
                return 1710;
            default:
                return 0;
            }
        case Properties::Occupied::FALSE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1711;
            case Properties::Part::FOOT:
                return 1712;
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
                return 1713;
            case Properties::Part::FOOT:
                return 1714;
            default:
                return 0;
            }
        case Properties::Occupied::FALSE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1715;
            case Properties::Part::FOOT:
                return 1716;
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
