#include "JungleWallHangingSign.hpp"
namespace Blocks {
    namespace JungleWallHangingSign {
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 5414;
                case Properties::Waterlogged::FALSE:
                    return 5415;
                }
            case Properties::Facing::SOUTH:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 5416;
                case Properties::Waterlogged::FALSE:
                    return 5417;
                }
            case Properties::Facing::WEST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 5418;
                case Properties::Waterlogged::FALSE:
                    return 5419;
                }
            case Properties::Facing::EAST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 5420;
                case Properties::Waterlogged::FALSE:
                    return 5421;
                }
            }
            return 0;
        }
    }

}
