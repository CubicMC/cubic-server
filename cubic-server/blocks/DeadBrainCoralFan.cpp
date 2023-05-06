#include "DeadBrainCoralFan.hpp"
namespace Blocks {
    namespace DeadBrainCoralFan {
        BlockId toProtocol(Properties::Waterlogged waterlogged) {
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 12207;
            case Properties::Waterlogged::FALSE:
                return 12208;
            default:
                return 0;
            }
            return 0;
        }
    }

}
