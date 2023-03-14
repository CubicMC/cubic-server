#include "MangroveWallHangingSign.hpp"
#include <stdexcept>

namespace Blocks {
    namespace MangroveWallHangingSign {
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 5430;
                case Properties::Waterlogged::FALSE:
                    return 5431;
                }
            case Properties::Facing::SOUTH:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 5432;
                case Properties::Waterlogged::FALSE:
                    return 5433;
                }
            case Properties::Facing::WEST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 5434;
                case Properties::Waterlogged::FALSE:
                    return 5435;
                }
            case Properties::Facing::EAST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 5436;
                case Properties::Waterlogged::FALSE:
                    return 5437;
                }
            }
            return 0;
        }
    }

}
