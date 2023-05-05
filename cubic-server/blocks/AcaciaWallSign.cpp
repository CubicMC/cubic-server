#include "AcaciaWallSign.hpp"
namespace Blocks {
    namespace AcaciaWallSign {
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4702;
                case Properties::Waterlogged::FALSE:
                    return 4703;
                }
            case Properties::Facing::SOUTH:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4704;
                case Properties::Waterlogged::FALSE:
                    return 4705;
                }
            case Properties::Facing::WEST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4706;
                case Properties::Waterlogged::FALSE:
                    return 4707;
                }
            case Properties::Facing::EAST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 4708;
                case Properties::Waterlogged::FALSE:
                    return 4709;
                }
            }
            return 0;
        }
    }

}
