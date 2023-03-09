#include "BubbleCoralWallFan.hpp"
#include <stdexcept>

namespace Blocks {
    namespace BubbleCoralWallFan {
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12281;
                case Properties::Waterlogged::FALSE:
                    return 12282;
                }
            case Properties::Facing::SOUTH:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12283;
                case Properties::Waterlogged::FALSE:
                    return 12284;
                }
            case Properties::Facing::WEST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12285;
                case Properties::Waterlogged::FALSE:
                    return 12286;
                }
            case Properties::Facing::EAST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12287;
                case Properties::Waterlogged::FALSE:
                    return 12288;
                }
            }
            return 0;
        }
    }

}
