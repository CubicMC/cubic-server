#include "BambooWallHangingSign.hpp"
namespace Blocks {
    namespace BambooWallHangingSign {
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 5454;
                case Properties::Waterlogged::FALSE:
                    return 5455;
                }
            case Properties::Facing::SOUTH:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 5456;
                case Properties::Waterlogged::FALSE:
                    return 5457;
                }
            case Properties::Facing::WEST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 5458;
                case Properties::Waterlogged::FALSE:
                    return 5459;
                }
            case Properties::Facing::EAST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 5460;
                case Properties::Waterlogged::FALSE:
                    return 5461;
                }
            }
            return 0;
        }
    }

}
