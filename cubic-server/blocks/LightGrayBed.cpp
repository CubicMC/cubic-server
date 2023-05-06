#include "LightGrayBed.hpp"
namespace Blocks {
namespace LightGrayBed {
BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (occupied) {
        case Properties::Occupied::TRUE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1765;
            case Properties::Part::FOOT:
                return 1766;
            default:
                return 0;
            }
        case Properties::Occupied::FALSE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1767;
            case Properties::Part::FOOT:
                return 1768;
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
                return 1769;
            case Properties::Part::FOOT:
                return 1770;
            default:
                return 0;
            }
        case Properties::Occupied::FALSE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1771;
            case Properties::Part::FOOT:
                return 1772;
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
                return 1773;
            case Properties::Part::FOOT:
                return 1774;
            default:
                return 0;
            }
        case Properties::Occupied::FALSE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1775;
            case Properties::Part::FOOT:
                return 1776;
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
                return 1777;
            case Properties::Part::FOOT:
                return 1778;
            default:
                return 0;
            }
        case Properties::Occupied::FALSE:
            switch (part) {
            case Properties::Part::HEAD:
                return 1779;
            case Properties::Part::FOOT:
                return 1780;
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
