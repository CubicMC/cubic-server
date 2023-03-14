#include "BirchWallSign.hpp"
#include <stdexcept>

namespace Blocks {
    namespace BirchWallSign {
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4694;
                case Properties::Waterlogged::FALSE:
                    return 4695;
                }
            case Properties::Facing::SOUTH:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4696;
                case Properties::Waterlogged::FALSE:
                    return 4697;
                }
            case Properties::Facing::WEST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4698;
                case Properties::Waterlogged::FALSE:
                    return 4699;
                }
            case Properties::Facing::EAST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4700;
                case Properties::Waterlogged::FALSE:
                    return 4701;
                }
            }
            return 0;
        }
    }

}
