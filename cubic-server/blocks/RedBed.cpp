#include "RedBed.hpp"
namespace Blocks {
    namespace RedBed {
        BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1861;
                    case Properties::Part::FOOT:
                        return 1862;
                    default:
                        return 0;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1863;
                    case Properties::Part::FOOT:
                        return 1864;
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
                        return 1865;
                    case Properties::Part::FOOT:
                        return 1866;
                    default:
                        return 0;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1867;
                    case Properties::Part::FOOT:
                        return 1868;
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
                        return 1869;
                    case Properties::Part::FOOT:
                        return 1870;
                    default:
                        return 0;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1871;
                    case Properties::Part::FOOT:
                        return 1872;
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
                        return 1873;
                    case Properties::Part::FOOT:
                        return 1874;
                    default:
                        return 0;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1875;
                    case Properties::Part::FOOT:
                        return 1876;
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
