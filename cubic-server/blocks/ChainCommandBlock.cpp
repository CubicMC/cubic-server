#include "ChainCommandBlock.hpp"
namespace Blocks {
    namespace ChainCommandBlock {
        BlockId toProtocol(Properties::Conditional conditional, Properties::Facing facing) {
            switch (conditional) {
            case Properties::Conditional::TRUE:
                switch (facing) {
                case Properties::Facing::NORTH:
                    return 11902;
                case Properties::Facing::EAST:
                    return 11903;
                case Properties::Facing::SOUTH:
                    return 11904;
                case Properties::Facing::WEST:
                    return 11905;
                case Properties::Facing::UP:
                    return 11906;
                case Properties::Facing::DOWN:
                    return 11907;
                default:
                    return 0;
                }
            case Properties::Conditional::FALSE:
                switch (facing) {
                case Properties::Facing::NORTH:
                    return 11908;
                case Properties::Facing::EAST:
                    return 11909;
                case Properties::Facing::SOUTH:
                    return 11910;
                case Properties::Facing::WEST:
                    return 11911;
                case Properties::Facing::UP:
                    return 11912;
                case Properties::Facing::DOWN:
                    return 11913;
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
