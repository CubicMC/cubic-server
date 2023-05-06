#include "Bell.hpp"
namespace Blocks {
    namespace Bell {
        BlockId toProtocol(Properties::Attachment attachment, Properties::Facing facing, Properties::Powered powered) {
            switch (attachment) {
            case Properties::Attachment::FLOOR:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 17843;
                    case Properties::Powered::FALSE:
                        return 17844;
                    default:
                        return 0;
                    }
                case Properties::Facing::SOUTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 17845;
                    case Properties::Powered::FALSE:
                        return 17846;
                    default:
                        return 0;
                    }
                case Properties::Facing::WEST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 17847;
                    case Properties::Powered::FALSE:
                        return 17848;
                    default:
                        return 0;
                    }
                case Properties::Facing::EAST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 17849;
                    case Properties::Powered::FALSE:
                        return 17850;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Attachment::CEILING:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 17851;
                    case Properties::Powered::FALSE:
                        return 17852;
                    default:
                        return 0;
                    }
                case Properties::Facing::SOUTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 17853;
                    case Properties::Powered::FALSE:
                        return 17854;
                    default:
                        return 0;
                    }
                case Properties::Facing::WEST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 17855;
                    case Properties::Powered::FALSE:
                        return 17856;
                    default:
                        return 0;
                    }
                case Properties::Facing::EAST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 17857;
                    case Properties::Powered::FALSE:
                        return 17858;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Attachment::SINGLE_WALL:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 17859;
                    case Properties::Powered::FALSE:
                        return 17860;
                    default:
                        return 0;
                    }
                case Properties::Facing::SOUTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 17861;
                    case Properties::Powered::FALSE:
                        return 17862;
                    default:
                        return 0;
                    }
                case Properties::Facing::WEST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 17863;
                    case Properties::Powered::FALSE:
                        return 17864;
                    default:
                        return 0;
                    }
                case Properties::Facing::EAST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 17865;
                    case Properties::Powered::FALSE:
                        return 17866;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Attachment::DOUBLE_WALL:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 17867;
                    case Properties::Powered::FALSE:
                        return 17868;
                    default:
                        return 0;
                    }
                case Properties::Facing::SOUTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 17869;
                    case Properties::Powered::FALSE:
                        return 17870;
                    default:
                        return 0;
                    }
                case Properties::Facing::WEST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 17871;
                    case Properties::Powered::FALSE:
                        return 17872;
                    default:
                        return 0;
                    }
                case Properties::Facing::EAST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 17873;
                    case Properties::Powered::FALSE:
                        return 17874;
                    default:
                        return 0;
                    }
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
