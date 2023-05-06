#include "MangroveButton.hpp"
namespace Blocks {
    namespace MangroveButton {
        BlockId toProtocol(Properties::Face face, Properties::Facing facing, Properties::Powered powered) {
            switch (face) {
            case Properties::Face::FLOOR:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 8523;
                    case Properties::Powered::FALSE:
                        return 8524;
                    default:
                        return 0;
                    }
                case Properties::Facing::SOUTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 8525;
                    case Properties::Powered::FALSE:
                        return 8526;
                    default:
                        return 0;
                    }
                case Properties::Facing::WEST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 8527;
                    case Properties::Powered::FALSE:
                        return 8528;
                    default:
                        return 0;
                    }
                case Properties::Facing::EAST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 8529;
                    case Properties::Powered::FALSE:
                        return 8530;
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
                        return 8531;
                    case Properties::Powered::FALSE:
                        return 8532;
                    default:
                        return 0;
                    }
                case Properties::Facing::SOUTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 8533;
                    case Properties::Powered::FALSE:
                        return 8534;
                    default:
                        return 0;
                    }
                case Properties::Facing::WEST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 8535;
                    case Properties::Powered::FALSE:
                        return 8536;
                    default:
                        return 0;
                    }
                case Properties::Facing::EAST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 8537;
                    case Properties::Powered::FALSE:
                        return 8538;
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
                        return 8539;
                    case Properties::Powered::FALSE:
                        return 8540;
                    default:
                        return 0;
                    }
                case Properties::Facing::SOUTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 8541;
                    case Properties::Powered::FALSE:
                        return 8542;
                    default:
                        return 0;
                    }
                case Properties::Facing::WEST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 8543;
                    case Properties::Powered::FALSE:
                        return 8544;
                    default:
                        return 0;
                    }
                case Properties::Facing::EAST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 8545;
                    case Properties::Powered::FALSE:
                        return 8546;
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
