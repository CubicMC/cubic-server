#include "Repeater.hpp"
namespace Blocks {
namespace Repeater {
BlockId toProtocol(Properties::Delay delay, Properties::Facing facing, Properties::Locked locked, Properties::Powered powered)
{
    switch (delay) {
    case Properties::Delay::ONE:
        switch (facing) {
        case Properties::Facing::NORTH:
            switch (locked) {
            case Properties::Locked::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 5716;
                case Properties::Powered::FALSE:
                    return 5717;
                default:
                    return 0;
                }
            case Properties::Locked::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 5718;
                case Properties::Powered::FALSE:
                    return 5719;
                default:
                    return 0;
                }
            default:
                return 0;
            }
        case Properties::Facing::SOUTH:
            switch (locked) {
            case Properties::Locked::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 5720;
                case Properties::Powered::FALSE:
                    return 5721;
                default:
                    return 0;
                }
            case Properties::Locked::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 5722;
                case Properties::Powered::FALSE:
                    return 5723;
                default:
                    return 0;
                }
            default:
                return 0;
            }
        case Properties::Facing::WEST:
            switch (locked) {
            case Properties::Locked::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 5724;
                case Properties::Powered::FALSE:
                    return 5725;
                default:
                    return 0;
                }
            case Properties::Locked::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 5726;
                case Properties::Powered::FALSE:
                    return 5727;
                default:
                    return 0;
                }
            default:
                return 0;
            }
        case Properties::Facing::EAST:
            switch (locked) {
            case Properties::Locked::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 5728;
                case Properties::Powered::FALSE:
                    return 5729;
                default:
                    return 0;
                }
            case Properties::Locked::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 5730;
                case Properties::Powered::FALSE:
                    return 5731;
                default:
                    return 0;
                }
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Delay::TWO:
        switch (facing) {
        case Properties::Facing::NORTH:
            switch (locked) {
            case Properties::Locked::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 5732;
                case Properties::Powered::FALSE:
                    return 5733;
                default:
                    return 0;
                }
            case Properties::Locked::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 5734;
                case Properties::Powered::FALSE:
                    return 5735;
                default:
                    return 0;
                }
            default:
                return 0;
            }
        case Properties::Facing::SOUTH:
            switch (locked) {
            case Properties::Locked::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 5736;
                case Properties::Powered::FALSE:
                    return 5737;
                default:
                    return 0;
                }
            case Properties::Locked::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 5738;
                case Properties::Powered::FALSE:
                    return 5739;
                default:
                    return 0;
                }
            default:
                return 0;
            }
        case Properties::Facing::WEST:
            switch (locked) {
            case Properties::Locked::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 5740;
                case Properties::Powered::FALSE:
                    return 5741;
                default:
                    return 0;
                }
            case Properties::Locked::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 5742;
                case Properties::Powered::FALSE:
                    return 5743;
                default:
                    return 0;
                }
            default:
                return 0;
            }
        case Properties::Facing::EAST:
            switch (locked) {
            case Properties::Locked::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 5744;
                case Properties::Powered::FALSE:
                    return 5745;
                default:
                    return 0;
                }
            case Properties::Locked::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 5746;
                case Properties::Powered::FALSE:
                    return 5747;
                default:
                    return 0;
                }
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Delay::THREE:
        switch (facing) {
        case Properties::Facing::NORTH:
            switch (locked) {
            case Properties::Locked::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 5748;
                case Properties::Powered::FALSE:
                    return 5749;
                default:
                    return 0;
                }
            case Properties::Locked::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 5750;
                case Properties::Powered::FALSE:
                    return 5751;
                default:
                    return 0;
                }
            default:
                return 0;
            }
        case Properties::Facing::SOUTH:
            switch (locked) {
            case Properties::Locked::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 5752;
                case Properties::Powered::FALSE:
                    return 5753;
                default:
                    return 0;
                }
            case Properties::Locked::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 5754;
                case Properties::Powered::FALSE:
                    return 5755;
                default:
                    return 0;
                }
            default:
                return 0;
            }
        case Properties::Facing::WEST:
            switch (locked) {
            case Properties::Locked::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 5756;
                case Properties::Powered::FALSE:
                    return 5757;
                default:
                    return 0;
                }
            case Properties::Locked::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 5758;
                case Properties::Powered::FALSE:
                    return 5759;
                default:
                    return 0;
                }
            default:
                return 0;
            }
        case Properties::Facing::EAST:
            switch (locked) {
            case Properties::Locked::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 5760;
                case Properties::Powered::FALSE:
                    return 5761;
                default:
                    return 0;
                }
            case Properties::Locked::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 5762;
                case Properties::Powered::FALSE:
                    return 5763;
                default:
                    return 0;
                }
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Delay::FOUR:
        switch (facing) {
        case Properties::Facing::NORTH:
            switch (locked) {
            case Properties::Locked::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 5764;
                case Properties::Powered::FALSE:
                    return 5765;
                default:
                    return 0;
                }
            case Properties::Locked::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 5766;
                case Properties::Powered::FALSE:
                    return 5767;
                default:
                    return 0;
                }
            default:
                return 0;
            }
        case Properties::Facing::SOUTH:
            switch (locked) {
            case Properties::Locked::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 5768;
                case Properties::Powered::FALSE:
                    return 5769;
                default:
                    return 0;
                }
            case Properties::Locked::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 5770;
                case Properties::Powered::FALSE:
                    return 5771;
                default:
                    return 0;
                }
            default:
                return 0;
            }
        case Properties::Facing::WEST:
            switch (locked) {
            case Properties::Locked::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 5772;
                case Properties::Powered::FALSE:
                    return 5773;
                default:
                    return 0;
                }
            case Properties::Locked::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 5774;
                case Properties::Powered::FALSE:
                    return 5775;
                default:
                    return 0;
                }
            default:
                return 0;
            }
        case Properties::Facing::EAST:
            switch (locked) {
            case Properties::Locked::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 5776;
                case Properties::Powered::FALSE:
                    return 5777;
                default:
                    return 0;
                }
            case Properties::Locked::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 5778;
                case Properties::Powered::FALSE:
                    return 5779;
                default:
                    return 0;
                }
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
