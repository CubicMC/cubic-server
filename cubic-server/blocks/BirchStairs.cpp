#include "BirchStairs.hpp"
#include <stdexcept>

namespace Blocks {
namespace BirchStairs {
BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (half) {
        case Properties::Half::TOP:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7516;
                case Properties::Waterlogged::FALSE:
                    return 7517;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7518;
                case Properties::Waterlogged::FALSE:
                    return 7519;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7520;
                case Properties::Waterlogged::FALSE:
                    return 7521;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7522;
                case Properties::Waterlogged::FALSE:
                    return 7523;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7524;
                case Properties::Waterlogged::FALSE:
                    return 7525;
                }
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7526;
                case Properties::Waterlogged::FALSE:
                    return 7527;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7528;
                case Properties::Waterlogged::FALSE:
                    return 7529;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7530;
                case Properties::Waterlogged::FALSE:
                    return 7531;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7532;
                case Properties::Waterlogged::FALSE:
                    return 7533;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7534;
                case Properties::Waterlogged::FALSE:
                    return 7535;
                }
            }
        }
    case Properties::Facing::SOUTH:
        switch (half) {
        case Properties::Half::TOP:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7536;
                case Properties::Waterlogged::FALSE:
                    return 7537;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7538;
                case Properties::Waterlogged::FALSE:
                    return 7539;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7540;
                case Properties::Waterlogged::FALSE:
                    return 7541;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7542;
                case Properties::Waterlogged::FALSE:
                    return 7543;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7544;
                case Properties::Waterlogged::FALSE:
                    return 7545;
                }
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7546;
                case Properties::Waterlogged::FALSE:
                    return 7547;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7548;
                case Properties::Waterlogged::FALSE:
                    return 7549;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7550;
                case Properties::Waterlogged::FALSE:
                    return 7551;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7552;
                case Properties::Waterlogged::FALSE:
                    return 7553;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7554;
                case Properties::Waterlogged::FALSE:
                    return 7555;
                }
            }
        }
    case Properties::Facing::WEST:
        switch (half) {
        case Properties::Half::TOP:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7556;
                case Properties::Waterlogged::FALSE:
                    return 7557;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7558;
                case Properties::Waterlogged::FALSE:
                    return 7559;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7560;
                case Properties::Waterlogged::FALSE:
                    return 7561;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7562;
                case Properties::Waterlogged::FALSE:
                    return 7563;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7564;
                case Properties::Waterlogged::FALSE:
                    return 7565;
                }
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7566;
                case Properties::Waterlogged::FALSE:
                    return 7567;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7568;
                case Properties::Waterlogged::FALSE:
                    return 7569;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7570;
                case Properties::Waterlogged::FALSE:
                    return 7571;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7572;
                case Properties::Waterlogged::FALSE:
                    return 7573;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7574;
                case Properties::Waterlogged::FALSE:
                    return 7575;
                }
            }
        }
    case Properties::Facing::EAST:
        switch (half) {
        case Properties::Half::TOP:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7576;
                case Properties::Waterlogged::FALSE:
                    return 7577;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7578;
                case Properties::Waterlogged::FALSE:
                    return 7579;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7580;
                case Properties::Waterlogged::FALSE:
                    return 7581;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7582;
                case Properties::Waterlogged::FALSE:
                    return 7583;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7584;
                case Properties::Waterlogged::FALSE:
                    return 7585;
                }
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7586;
                case Properties::Waterlogged::FALSE:
                    return 7587;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7588;
                case Properties::Waterlogged::FALSE:
                    return 7589;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7590;
                case Properties::Waterlogged::FALSE:
                    return 7591;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7592;
                case Properties::Waterlogged::FALSE:
                    return 7593;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 7594;
                case Properties::Waterlogged::FALSE:
                    return 7595;
                }
            }
        }
    }
    return 0;
}
}

}
