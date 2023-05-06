#include "BirchButton.hpp"
namespace Blocks {
    namespace BirchButton {
        BlockId toProtocol(Properties::Face face, Properties::Facing facing, Properties::Powered powered) {
            switch (face) {
            case Properties::Face::FLOOR:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 8427;
                    case Properties::Powered::FALSE:
                        return 8428;
                    default:
                        return 0;
                    }
                case Properties::Facing::SOUTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 8429;
                    case Properties::Powered::FALSE:
                        return 8430;
                    default:
                        return 0;
                    }
                case Properties::Facing::WEST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 8431;
                    case Properties::Powered::FALSE:
                        return 8432;
                    default:
                        return 0;
                    }
                case Properties::Facing::EAST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 8433;
                    case Properties::Powered::FALSE:
                        return 8434;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Face::WALL:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 8435;
                    case Properties::Powered::FALSE:
                        return 8436;
                    default:
                        return 0;
                    }
                case Properties::Facing::SOUTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 8437;
                    case Properties::Powered::FALSE:
                        return 8438;
                    default:
                        return 0;
                    }
                case Properties::Facing::WEST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 8439;
                    case Properties::Powered::FALSE:
                        return 8440;
                    default:
                        return 0;
                    }
                case Properties::Facing::EAST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 8441;
                    case Properties::Powered::FALSE:
                        return 8442;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Face::CEILING:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 8443;
                    case Properties::Powered::FALSE:
                        return 8444;
                    default:
                        return 0;
                    }
                case Properties::Facing::SOUTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 8445;
                    case Properties::Powered::FALSE:
                        return 8446;
                    default:
                        return 0;
                    }
                case Properties::Facing::WEST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 8447;
                    case Properties::Powered::FALSE:
                        return 8448;
                    default:
                        return 0;
                    }
                case Properties::Facing::EAST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 8449;
                    case Properties::Powered::FALSE:
                        return 8450;
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
