#include "MovingPiston.hpp"
namespace Blocks {
    namespace MovingPiston {
        BlockId toProtocol(Properties::Type type, Properties::Facing facing) {
            switch (type) {
            case Properties::Type::NORMAL:
                switch (facing) {
                case Properties::Facing::NORTH:
                    return 2012;
                case Properties::Facing::EAST:
                    return 2014;
                case Properties::Facing::SOUTH:
                    return 2016;
                case Properties::Facing::WEST:
                    return 2018;
                case Properties::Facing::UP:
                    return 2020;
                case Properties::Facing::DOWN:
                    return 2022;
                default:
                    return 0;
                }
            case Properties::Type::STICKY:
                switch (facing) {
                case Properties::Facing::NORTH:
                    return 2013;
                case Properties::Facing::EAST:
                    return 2015;
                case Properties::Facing::SOUTH:
                    return 2017;
                case Properties::Facing::WEST:
                    return 2019;
                case Properties::Facing::UP:
                    return 2021;
                case Properties::Facing::DOWN:
                    return 2023;
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
