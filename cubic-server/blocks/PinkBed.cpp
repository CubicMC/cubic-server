#include "PinkBed.hpp"
namespace Blocks {
    namespace PinkBed {
        BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1733;
                    case Properties::Part::FOOT:
                        return 1734;
                    default:
                        return 0;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1735;
                    case Properties::Part::FOOT:
                        return 1736;
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
                        return 1737;
                    case Properties::Part::FOOT:
                        return 1738;
                    default:
                        return 0;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1739;
                    case Properties::Part::FOOT:
                        return 1740;
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
                        return 1741;
                    case Properties::Part::FOOT:
                        return 1742;
                    default:
                        return 0;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1743;
                    case Properties::Part::FOOT:
                        return 1744;
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
                        return 1745;
                    case Properties::Part::FOOT:
                        return 1746;
                    default:
                        return 0;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1747;
                    case Properties::Part::FOOT:
                        return 1748;
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
