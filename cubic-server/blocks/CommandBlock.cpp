#include "CommandBlock.hpp"
namespace Blocks {
    namespace CommandBlock {
        BlockId toProtocol(Properties::Conditional conditional, Properties::Facing facing) {
            switch (conditional) {
            case Properties::Conditional::TRUE:
                switch (facing) {
                case Properties::Facing::NORTH:
                    return 7676;
                case Properties::Facing::EAST:
                    return 7677;
                case Properties::Facing::SOUTH:
                    return 7678;
                case Properties::Facing::WEST:
                    return 7679;
                case Properties::Facing::UP:
                    return 7680;
                case Properties::Facing::DOWN:
                    return 7681;
                default:
                    return 0;
                }
            case Properties::Conditional::FALSE:
                switch (facing) {
                case Properties::Facing::NORTH:
                    return 7682;
                case Properties::Facing::EAST:
                    return 7683;
                case Properties::Facing::SOUTH:
                    return 7684;
                case Properties::Facing::WEST:
                    return 7685;
                case Properties::Facing::UP:
                    return 7686;
                case Properties::Facing::DOWN:
                    return 7687;
                default:
                    return 0;
                }
            default:
                return 0;
            }
            return 0;
        }
    }

}
