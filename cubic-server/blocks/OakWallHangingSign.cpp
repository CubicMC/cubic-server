#include "OakWallHangingSign.hpp"
#include <stdexcept>

namespace Blocks {
namespace OakWallHangingSign {
BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 5382;
        case Properties::Waterlogged::FALSE:
            return 5383;
        }
    case Properties::Facing::SOUTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 5384;
        case Properties::Waterlogged::FALSE:
            return 5385;
        }
    case Properties::Facing::WEST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 5386;
        case Properties::Waterlogged::FALSE:
            return 5387;
        }
    case Properties::Facing::EAST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 5388;
        case Properties::Waterlogged::FALSE:
            return 5389;
        }
    }
    return 0;
}
}

}
