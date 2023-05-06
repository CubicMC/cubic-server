#include "Cocoa.hpp"
namespace Blocks {
    namespace Cocoa {
        BlockId toProtocol(Properties::Age age, Properties::Facing facing) {
            switch (age) {
            case Properties::Age::ZERO:
                switch (facing) {
                case Properties::Facing::NORTH:
                    return 7189;
                case Properties::Facing::SOUTH:
                    return 7190;
                case Properties::Facing::WEST:
                    return 7191;
                case Properties::Facing::EAST:
                    return 7192;
                default:
                    return 0;
                }
            case Properties::Age::ONE:
                switch (facing) {
                case Properties::Facing::NORTH:
                    return 7193;
                case Properties::Facing::SOUTH:
                    return 7194;
                case Properties::Facing::WEST:
                    return 7195;
                case Properties::Facing::EAST:
                    return 7196;
                default:
                    return 0;
                }
            case Properties::Age::TWO:
                switch (facing) {
                case Properties::Facing::NORTH:
                    return 7197;
                case Properties::Facing::SOUTH:
                    return 7198;
                case Properties::Facing::WEST:
                    return 7199;
                case Properties::Facing::EAST:
                    return 7200;
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
