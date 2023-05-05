#include "Ladder.hpp"
namespace Blocks {
    namespace Ladder {
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4570;
                case Properties::Waterlogged::FALSE:
                    return 4571;
                }
            case Properties::Facing::SOUTH:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4572;
                case Properties::Waterlogged::FALSE:
                    return 4573;
                }
            case Properties::Facing::WEST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4574;
                case Properties::Waterlogged::FALSE:
                    return 4575;
                }
            case Properties::Facing::EAST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4576;
                case Properties::Waterlogged::FALSE:
                    return 4577;
                }
            }
            return 0;
        }
    }

}
