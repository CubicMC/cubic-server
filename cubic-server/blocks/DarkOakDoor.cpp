#include "DarkOakDoor.hpp"
#include <stdexcept>

namespace Blocks {
namespace DarkOakDoor {
BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Hinge hinge, Properties::Open open, Properties::Powered powered)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (half) {
        case Properties::Half::UPPER:
            switch (hinge) {
            case Properties::Hinge::LEFT:
                switch (open) {
                case Properties::Open::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11531;
                    case Properties::Powered::FALSE:
                        return 11532;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11533;
                    case Properties::Powered::FALSE:
                        return 11534;
                    }
                }
            case Properties::Hinge::RIGHT:
                switch (open) {
                case Properties::Open::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11535;
                    case Properties::Powered::FALSE:
                        return 11536;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11537;
                    case Properties::Powered::FALSE:
                        return 11538;
                    }
                }
            }
        case Properties::Half::LOWER:
            switch (hinge) {
            case Properties::Hinge::LEFT:
                switch (open) {
                case Properties::Open::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11539;
                    case Properties::Powered::FALSE:
                        return 11540;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11541;
                    case Properties::Powered::FALSE:
                        return 11542;
                    }
                }
            case Properties::Hinge::RIGHT:
                switch (open) {
                case Properties::Open::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11543;
                    case Properties::Powered::FALSE:
                        return 11544;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11545;
                    case Properties::Powered::FALSE:
                        return 11546;
                    }
                }
            }
        }
    case Properties::Facing::SOUTH:
        switch (half) {
        case Properties::Half::UPPER:
            switch (hinge) {
            case Properties::Hinge::LEFT:
                switch (open) {
                case Properties::Open::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11547;
                    case Properties::Powered::FALSE:
                        return 11548;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11549;
                    case Properties::Powered::FALSE:
                        return 11550;
                    }
                }
            case Properties::Hinge::RIGHT:
                switch (open) {
                case Properties::Open::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11551;
                    case Properties::Powered::FALSE:
                        return 11552;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11553;
                    case Properties::Powered::FALSE:
                        return 11554;
                    }
                }
            }
        case Properties::Half::LOWER:
            switch (hinge) {
            case Properties::Hinge::LEFT:
                switch (open) {
                case Properties::Open::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11555;
                    case Properties::Powered::FALSE:
                        return 11556;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11557;
                    case Properties::Powered::FALSE:
                        return 11558;
                    }
                }
            case Properties::Hinge::RIGHT:
                switch (open) {
                case Properties::Open::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11559;
                    case Properties::Powered::FALSE:
                        return 11560;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11561;
                    case Properties::Powered::FALSE:
                        return 11562;
                    }
                }
            }
        }
    case Properties::Facing::WEST:
        switch (half) {
        case Properties::Half::UPPER:
            switch (hinge) {
            case Properties::Hinge::LEFT:
                switch (open) {
                case Properties::Open::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11563;
                    case Properties::Powered::FALSE:
                        return 11564;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11565;
                    case Properties::Powered::FALSE:
                        return 11566;
                    }
                }
            case Properties::Hinge::RIGHT:
                switch (open) {
                case Properties::Open::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11567;
                    case Properties::Powered::FALSE:
                        return 11568;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11569;
                    case Properties::Powered::FALSE:
                        return 11570;
                    }
                }
            }
        case Properties::Half::LOWER:
            switch (hinge) {
            case Properties::Hinge::LEFT:
                switch (open) {
                case Properties::Open::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11571;
                    case Properties::Powered::FALSE:
                        return 11572;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11573;
                    case Properties::Powered::FALSE:
                        return 11574;
                    }
                }
            case Properties::Hinge::RIGHT:
                switch (open) {
                case Properties::Open::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11575;
                    case Properties::Powered::FALSE:
                        return 11576;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11577;
                    case Properties::Powered::FALSE:
                        return 11578;
                    }
                }
            }
        }
    case Properties::Facing::EAST:
        switch (half) {
        case Properties::Half::UPPER:
            switch (hinge) {
            case Properties::Hinge::LEFT:
                switch (open) {
                case Properties::Open::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11579;
                    case Properties::Powered::FALSE:
                        return 11580;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11581;
                    case Properties::Powered::FALSE:
                        return 11582;
                    }
                }
            case Properties::Hinge::RIGHT:
                switch (open) {
                case Properties::Open::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11583;
                    case Properties::Powered::FALSE:
                        return 11584;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11585;
                    case Properties::Powered::FALSE:
                        return 11586;
                    }
                }
            }
        case Properties::Half::LOWER:
            switch (hinge) {
            case Properties::Hinge::LEFT:
                switch (open) {
                case Properties::Open::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11587;
                    case Properties::Powered::FALSE:
                        return 11588;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11589;
                    case Properties::Powered::FALSE:
                        return 11590;
                    }
                }
            case Properties::Hinge::RIGHT:
                switch (open) {
                case Properties::Open::TRUE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11591;
                    case Properties::Powered::FALSE:
                        return 11592;
                    }
                case Properties::Open::FALSE:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 11593;
                    case Properties::Powered::FALSE:
                        return 11594;
                    }
                }
            }
        }
    }
    return 0;
}
}

}
