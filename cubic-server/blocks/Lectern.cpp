#include "Lectern.hpp"
namespace Blocks {
    namespace Lectern {
        BlockId toProtocol(Properties::Facing facing, Properties::Has_book has_book, Properties::Powered powered) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (has_book) {
                case Properties::Has_book::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 17822;
                    case Properties::Powered::FALSE:
                        return 17823;
                    default:
                        return 0;
                    }
                case Properties::Has_book::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 17824;
                    case Properties::Powered::FALSE:
                        return 17825;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Facing::SOUTH:
                switch (has_book) {
                case Properties::Has_book::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 17826;
                    case Properties::Powered::FALSE:
                        return 17827;
                    default:
                        return 0;
                    }
                case Properties::Has_book::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 17828;
                    case Properties::Powered::FALSE:
                        return 17829;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Facing::WEST:
                switch (has_book) {
                case Properties::Has_book::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 17830;
                    case Properties::Powered::FALSE:
                        return 17831;
                    default:
                        return 0;
                    }
                case Properties::Has_book::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 17832;
                    case Properties::Powered::FALSE:
                        return 17833;
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Facing::EAST:
                switch (has_book) {
                case Properties::Has_book::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 17834;
                    case Properties::Powered::FALSE:
                        return 17835;
                    default:
                        return 0;
                    }
                case Properties::Has_book::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 17836;
                    case Properties::Powered::FALSE:
                        return 17837;
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
