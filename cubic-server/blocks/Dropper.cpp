#include "Dropper.hpp"
namespace Blocks {
    namespace Dropper {
        BlockId toProtocol(Properties::Facing facing, Properties::Triggered triggered) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (triggered) {
                case Properties::Triggered::TRUE:
                    return 8948;
                case Properties::Triggered::FALSE:
                    return 8949;
                default:
                    return 0;
                }
            case Properties::Facing::EAST:
                switch (triggered) {
                case Properties::Triggered::TRUE:
                    return 8950;
                case Properties::Triggered::FALSE:
                    return 8951;
                default:
                    return 0;
                }
            case Properties::Facing::SOUTH:
                switch (triggered) {
                case Properties::Triggered::TRUE:
                    return 8952;
                case Properties::Triggered::FALSE:
                    return 8953;
                default:
                    return 0;
                }
            case Properties::Facing::WEST:
                switch (triggered) {
                case Properties::Triggered::TRUE:
                    return 8954;
                case Properties::Triggered::FALSE:
                    return 8955;
                default:
                    return 0;
                }
            case Properties::Facing::UP:
                switch (triggered) {
                case Properties::Triggered::TRUE:
                    return 8956;
                case Properties::Triggered::FALSE:
                    return 8957;
                default:
                    return 0;
                }
            case Properties::Facing::DOWN:
                switch (triggered) {
                case Properties::Triggered::TRUE:
                    return 8958;
                case Properties::Triggered::FALSE:
                    return 8959;
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
