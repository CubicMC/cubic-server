#include "BambooWallSign.hpp"
#include <stdexcept>

namespace Blocks {
namespace BambooWallSign {
BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4734;
        case Properties::Waterlogged::FALSE:
            return 4735;
        }
    case Properties::Facing::SOUTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4736;
        case Properties::Waterlogged::FALSE:
            return 4737;
        }
    case Properties::Facing::WEST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4738;
        case Properties::Waterlogged::FALSE:
            return 4739;
        }
    case Properties::Facing::EAST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4740;
        case Properties::Waterlogged::FALSE:
            return 4741;
        }
    }
    return 0;
}
}

}
