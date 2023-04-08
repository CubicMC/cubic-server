#include "WarpedWallSign.hpp"
#include <stdexcept>

namespace Blocks {
namespace WarpedWallSign {
BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 18720;
        case Properties::Waterlogged::FALSE:
            return 18721;
        }
    case Properties::Facing::SOUTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 18722;
        case Properties::Waterlogged::FALSE:
            return 18723;
        }
    case Properties::Facing::WEST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 18724;
        case Properties::Waterlogged::FALSE:
            return 18725;
        }
    case Properties::Facing::EAST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 18726;
        case Properties::Waterlogged::FALSE:
            return 18727;
        }
    }
    return 0;
}
}

}
