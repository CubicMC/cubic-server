#include "AmethystCluster.hpp"
#include <stdexcept>

namespace Blocks {
namespace AmethystCluster {
BlockId toProtocol(Properties::Facing facing, Properties::Waterlogged waterlogged)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 20405;
        case Properties::Waterlogged::FALSE:
            return 20406;
        }
    case Properties::Facing::EAST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 20407;
        case Properties::Waterlogged::FALSE:
            return 20408;
        }
    case Properties::Facing::SOUTH:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 20409;
        case Properties::Waterlogged::FALSE:
            return 20410;
        }
    case Properties::Facing::WEST:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 20411;
        case Properties::Waterlogged::FALSE:
            return 20412;
        }
    case Properties::Facing::UP:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 20413;
        case Properties::Waterlogged::FALSE:
            return 20414;
        }
    case Properties::Facing::DOWN:
        switch (waterlogged) {
        case Properties::Waterlogged::TRUE:
            return 20415;
        case Properties::Waterlogged::FALSE:
            return 20416;
        }
    }
    return 0;
}
}

}
