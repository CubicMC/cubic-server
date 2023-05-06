#include "Barrel.hpp"
namespace Blocks {
    namespace Barrel {
        BlockId toProtocol(Properties::Facing facing, Properties::Open open) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (open) {
                case Properties::Open::TRUE:
                    return 17780;
                case Properties::Open::FALSE:
                    return 17781;
                default:
                    return 0;
                }
            case Properties::Facing::EAST:
                switch (open) {
                case Properties::Open::TRUE:
                    return 17782;
                case Properties::Open::FALSE:
                    return 17783;
                default:
                    return 0;
                }
            case Properties::Facing::SOUTH:
                switch (open) {
                case Properties::Open::TRUE:
                    return 17784;
                case Properties::Open::FALSE:
                    return 17785;
                default:
                    return 0;
                }
            case Properties::Facing::WEST:
                switch (open) {
                case Properties::Open::TRUE:
                    return 17786;
                case Properties::Open::FALSE:
                    return 17787;
                default:
                    return 0;
                }
            case Properties::Facing::UP:
                switch (open) {
                case Properties::Open::TRUE:
                    return 17788;
                case Properties::Open::FALSE:
                    return 17789;
                default:
                    return 0;
                }
            case Properties::Facing::DOWN:
                switch (open) {
                case Properties::Open::TRUE:
                    return 17790;
                case Properties::Open::FALSE:
                    return 17791;
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
