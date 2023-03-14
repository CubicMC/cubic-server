#include "Repeater.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Repeater {
        BlockId toProtocol(Properties::Delay delay, Properties::Facing facing, Properties::Locked locked, Properties::Powered powered) {
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
                        }
                    case Properties::Locked::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 5718;
                        case Properties::Powered::FALSE:
                            return 5719;
                        }
                    }
                case Properties::Facing::SOUTH:
                    switch (locked) {
                    case Properties::Locked::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 5720;
                        case Properties::Powered::FALSE:
                            return 5721;
                        }
                    case Properties::Locked::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 5722;
                        case Properties::Powered::FALSE:
                            return 5723;
                        }
                    }
                case Properties::Facing::WEST:
                    switch (locked) {
                    case Properties::Locked::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 5724;
                        case Properties::Powered::FALSE:
                            return 5725;
                        }
                    case Properties::Locked::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 5726;
                        case Properties::Powered::FALSE:
                            return 5727;
                        }
                    }
                case Properties::Facing::EAST:
                    switch (locked) {
                    case Properties::Locked::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 5728;
                        case Properties::Powered::FALSE:
                            return 5729;
                        }
                    case Properties::Locked::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 5730;
                        case Properties::Powered::FALSE:
                            return 5731;
                        }
                    }
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
                        }
                    case Properties::Locked::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 5734;
                        case Properties::Powered::FALSE:
                            return 5735;
                        }
                    }
                case Properties::Facing::SOUTH:
                    switch (locked) {
                    case Properties::Locked::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 5736;
                        case Properties::Powered::FALSE:
                            return 5737;
                        }
                    case Properties::Locked::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 5738;
                        case Properties::Powered::FALSE:
                            return 5739;
                        }
                    }
                case Properties::Facing::WEST:
                    switch (locked) {
                    case Properties::Locked::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 5740;
                        case Properties::Powered::FALSE:
                            return 5741;
                        }
                    case Properties::Locked::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 5742;
                        case Properties::Powered::FALSE:
                            return 5743;
                        }
                    }
                case Properties::Facing::EAST:
                    switch (locked) {
                    case Properties::Locked::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 5744;
                        case Properties::Powered::FALSE:
                            return 5745;
                        }
                    case Properties::Locked::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 5746;
                        case Properties::Powered::FALSE:
                            return 5747;
                        }
                    }
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
                        }
                    case Properties::Locked::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 5750;
                        case Properties::Powered::FALSE:
                            return 5751;
                        }
                    }
                case Properties::Facing::SOUTH:
                    switch (locked) {
                    case Properties::Locked::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 5752;
                        case Properties::Powered::FALSE:
                            return 5753;
                        }
                    case Properties::Locked::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 5754;
                        case Properties::Powered::FALSE:
                            return 5755;
                        }
                    }
                case Properties::Facing::WEST:
                    switch (locked) {
                    case Properties::Locked::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 5756;
                        case Properties::Powered::FALSE:
                            return 5757;
                        }
                    case Properties::Locked::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 5758;
                        case Properties::Powered::FALSE:
                            return 5759;
                        }
                    }
                case Properties::Facing::EAST:
                    switch (locked) {
                    case Properties::Locked::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 5760;
                        case Properties::Powered::FALSE:
                            return 5761;
                        }
                    case Properties::Locked::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 5762;
                        case Properties::Powered::FALSE:
                            return 5763;
                        }
                    }
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
                        }
                    case Properties::Locked::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 5766;
                        case Properties::Powered::FALSE:
                            return 5767;
                        }
                    }
                case Properties::Facing::SOUTH:
                    switch (locked) {
                    case Properties::Locked::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 5768;
                        case Properties::Powered::FALSE:
                            return 5769;
                        }
                    case Properties::Locked::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 5770;
                        case Properties::Powered::FALSE:
                            return 5771;
                        }
                    }
                case Properties::Facing::WEST:
                    switch (locked) {
                    case Properties::Locked::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 5772;
                        case Properties::Powered::FALSE:
                            return 5773;
                        }
                    case Properties::Locked::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 5774;
                        case Properties::Powered::FALSE:
                            return 5775;
                        }
                    }
                case Properties::Facing::EAST:
                    switch (locked) {
                    case Properties::Locked::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 5776;
                        case Properties::Powered::FALSE:
                            return 5777;
                        }
                    case Properties::Locked::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 5778;
                        case Properties::Powered::FALSE:
                            return 5779;
                        }
                    }
                }
            }
            return 0;
        }
    }

}
