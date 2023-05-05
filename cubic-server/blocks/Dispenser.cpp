#include "Dispenser.hpp"
namespace Blocks {
    namespace Dispenser {
        BlockId toProtocol(Properties::Facing facing, Properties::Triggered triggered) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (triggered) {
                case Properties::Triggered::TRUE:
                    return 472;
                case Properties::Triggered::FALSE:
                    return 473;
                }
            case Properties::Facing::EAST:
                switch (triggered) {
                case Properties::Triggered::TRUE:
                    return 474;
                case Properties::Triggered::FALSE:
                    return 475;
                }
            case Properties::Facing::SOUTH:
                switch (triggered) {
                case Properties::Triggered::TRUE:
                    return 476;
                case Properties::Triggered::FALSE:
                    return 477;
                }
            case Properties::Facing::WEST:
                switch (triggered) {
                case Properties::Triggered::TRUE:
                    return 478;
                case Properties::Triggered::FALSE:
                    return 479;
                }
            case Properties::Facing::UP:
                switch (triggered) {
                case Properties::Triggered::TRUE:
                    return 480;
                case Properties::Triggered::FALSE:
                    return 481;
                }
            case Properties::Facing::DOWN:
                switch (triggered) {
                case Properties::Triggered::TRUE:
                    return 482;
                case Properties::Triggered::FALSE:
                    return 483;
                }
            }
            return 0;
        }
    }

}
