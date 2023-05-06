#include "MagentaBed.hpp"
namespace Blocks {
    namespace MagentaBed {
        BlockId toProtocol(Properties::Facing facing, Properties::Occupied occupied, Properties::Part part) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (occupied) {
                case Properties::Occupied::TRUE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1669;
                    case Properties::Part::FOOT:
                        return 1670;
                    default:
                        return 0;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1671;
                    case Properties::Part::FOOT:
                        return 1672;
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
                        return 1673;
                    case Properties::Part::FOOT:
                        return 1674;
                    default:
                        return 0;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1675;
                    case Properties::Part::FOOT:
                        return 1676;
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
                        return 1677;
                    case Properties::Part::FOOT:
                        return 1678;
                    default:
                        return 0;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1679;
                    case Properties::Part::FOOT:
                        return 1680;
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
                        return 1681;
                    case Properties::Part::FOOT:
                        return 1682;
                    default:
                        return 0;
                    }
                case Properties::Occupied::FALSE:
                    switch (part) {
                    case Properties::Part::HEAD:
                        return 1683;
                    case Properties::Part::FOOT:
                        return 1684;
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
