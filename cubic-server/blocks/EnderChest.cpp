#include "EnderChest.hpp"
#include <stdexcept>

namespace Blocks {
    namespace EnderChest {
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7283;
                case Properties::Waterlogged::FALSE:
                    return 7284;
                }
            case Properties::Facing::SOUTH:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7285;
                case Properties::Waterlogged::FALSE:
                    return 7286;
                }
            case Properties::Facing::WEST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7287;
                case Properties::Waterlogged::FALSE:
                    return 7288;
                }
            case Properties::Facing::EAST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7289;
                case Properties::Waterlogged::FALSE:
                    return 7290;
                }
            }
            return 0;
        }
    }

}
