#include "LargeAmethystBud.hpp"
#include <stdexcept>

namespace Blocks {
    namespace LargeAmethystBud {
        BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20417;
                case Properties::Waterlogged::FALSE:
                    return 20418;
                }
            case Properties::Facing::EAST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20419;
                case Properties::Waterlogged::FALSE:
                    return 20420;
                }
            case Properties::Facing::SOUTH:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20421;
                case Properties::Waterlogged::FALSE:
                    return 20422;
                }
            case Properties::Facing::WEST:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20423;
                case Properties::Waterlogged::FALSE:
                    return 20424;
                }
            case Properties::Facing::UP:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20425;
                case Properties::Waterlogged::FALSE:
                    return 20426;
                }
            case Properties::Facing::DOWN:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20427;
                case Properties::Waterlogged::FALSE:
                    return 20428;
                }
            }
            return 0;
        }
    }

}
