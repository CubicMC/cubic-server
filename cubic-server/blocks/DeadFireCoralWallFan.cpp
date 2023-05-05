#include "DeadFireCoralWallFan.hpp"
namespace Blocks {
    namespace DeadFireCoralWallFan {
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12249;
                case Properties::Waterlogged::FALSE:
                    return 12250;
                }
            case Properties::Facing::SOUTH:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12251;
                case Properties::Waterlogged::FALSE:
                    return 12252;
                }
            case Properties::Facing::WEST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12253;
                case Properties::Waterlogged::FALSE:
                    return 12254;
                }
            case Properties::Facing::EAST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12255;
                case Properties::Waterlogged::FALSE:
                    return 12256;
                }
            }
            return 0;
        }
    }

}
