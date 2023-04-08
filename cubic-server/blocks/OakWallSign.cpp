#include "OakWallSign.hpp"
#include <stdexcept>

namespace Blocks {
namespace OakWallSign {
BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4678;
        case Properties::Waterlogged::FALSE:
            return 4679;
        }
    case Properties::Facing::SOUTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4680;
        case Properties::Waterlogged::FALSE:
            return 4681;
        }
    case Properties::Facing::WEST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4682;
        case Properties::Waterlogged::FALSE:
            return 4683;
        }
    case Properties::Facing::EAST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 4684;
        case Properties::Waterlogged::FALSE:
            return 4685;
        }
    }
    return 0;
}
}

}
