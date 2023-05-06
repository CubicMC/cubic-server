#include "DeadFireCoralFan.hpp"
namespace Blocks {
    namespace DeadFireCoralFan {
        BlockId toProtocol(Properties::Waterlogged waterlogged) {
            switch (waterlogged) {
            case Properties::Waterlogged::TRUE:
                return 12211;
            case Properties::Waterlogged::FALSE:
                return 12212;
            default:
                return 0;
            }
            return 0;
        }
    }

}
