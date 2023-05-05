#include "JungleWallSign.hpp"
namespace Blocks {
    namespace JungleWallSign {
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4710;
                case Properties::Waterlogged::FALSE:
                    return 4711;
                }
            case Properties::Facing::SOUTH:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4712;
                case Properties::Waterlogged::FALSE:
                    return 4713;
                }
            case Properties::Facing::WEST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4714;
                case Properties::Waterlogged::FALSE:
                    return 4715;
                }
            case Properties::Facing::EAST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4716;
                case Properties::Waterlogged::FALSE:
                    return 4717;
                }
            }
            return 0;
        }
    }

}
