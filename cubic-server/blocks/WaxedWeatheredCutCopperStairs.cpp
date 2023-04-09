#include "WaxedWeatheredCutCopperStairs.hpp"
#include <stdexcept>

namespace Blocks {
namespace WaxedWeatheredCutCopperStairs {
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
                    return 21134;
                case Properties::Waterlogged::FALSE:
                    return 21135;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21136;
                case Properties::Waterlogged::FALSE:
                    return 21137;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21138;
                case Properties::Waterlogged::FALSE:
                    return 21139;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21140;
                case Properties::Waterlogged::FALSE:
                    return 21141;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21142;
                case Properties::Waterlogged::FALSE:
                    return 21143;
                }
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21144;
                case Properties::Waterlogged::FALSE:
                    return 21145;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21146;
                case Properties::Waterlogged::FALSE:
                    return 21147;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21148;
                case Properties::Waterlogged::FALSE:
                    return 21149;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21150;
                case Properties::Waterlogged::FALSE:
                    return 21151;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21152;
                case Properties::Waterlogged::FALSE:
                    return 21153;
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
                    return 21154;
                case Properties::Waterlogged::FALSE:
                    return 21155;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21156;
                case Properties::Waterlogged::FALSE:
                    return 21157;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21158;
                case Properties::Waterlogged::FALSE:
                    return 21159;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21160;
                case Properties::Waterlogged::FALSE:
                    return 21161;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21162;
                case Properties::Waterlogged::FALSE:
                    return 21163;
                }
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21164;
                case Properties::Waterlogged::FALSE:
                    return 21165;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21166;
                case Properties::Waterlogged::FALSE:
                    return 21167;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21168;
                case Properties::Waterlogged::FALSE:
                    return 21169;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21170;
                case Properties::Waterlogged::FALSE:
                    return 21171;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21172;
                case Properties::Waterlogged::FALSE:
                    return 21173;
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
                    return 21174;
                case Properties::Waterlogged::FALSE:
                    return 21175;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21176;
                case Properties::Waterlogged::FALSE:
                    return 21177;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21178;
                case Properties::Waterlogged::FALSE:
                    return 21179;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21180;
                case Properties::Waterlogged::FALSE:
                    return 21181;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21182;
                case Properties::Waterlogged::FALSE:
                    return 21183;
                }
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21184;
                case Properties::Waterlogged::FALSE:
                    return 21185;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21186;
                case Properties::Waterlogged::FALSE:
                    return 21187;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21188;
                case Properties::Waterlogged::FALSE:
                    return 21189;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21190;
                case Properties::Waterlogged::FALSE:
                    return 21191;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21192;
                case Properties::Waterlogged::FALSE:
                    return 21193;
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
                    return 21194;
                case Properties::Waterlogged::FALSE:
                    return 21195;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21196;
                case Properties::Waterlogged::FALSE:
                    return 21197;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21198;
                case Properties::Waterlogged::FALSE:
                    return 21199;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21200;
                case Properties::Waterlogged::FALSE:
                    return 21201;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21202;
                case Properties::Waterlogged::FALSE:
                    return 21203;
                }
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21204;
                case Properties::Waterlogged::FALSE:
                    return 21205;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21206;
                case Properties::Waterlogged::FALSE:
                    return 21207;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21208;
                case Properties::Waterlogged::FALSE:
                    return 21209;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21210;
                case Properties::Waterlogged::FALSE:
                    return 21211;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 21212;
                case Properties::Waterlogged::FALSE:
                    return 21213;
                }
            }
        }
    }
    return 0;
}
}

}
