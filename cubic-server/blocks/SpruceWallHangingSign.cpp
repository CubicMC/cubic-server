#include "SpruceWallHangingSign.hpp"
#include <stdexcept>

namespace Blocks {
namespace SpruceWallHangingSign {
BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 5390;
        case Properties::Waterlogged::FALSE:
            return 5391;
        }
    case Properties::Facing::SOUTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 5392;
        case Properties::Waterlogged::FALSE:
            return 5393;
        }
    case Properties::Facing::WEST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 5394;
        case Properties::Waterlogged::FALSE:
            return 5395;
        }
    case Properties::Facing::EAST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 5396;
        case Properties::Waterlogged::FALSE:
            return 5397;
        }
    }
    return 0;
}
}

}
