#include "JungleStairs.hpp"
namespace Blocks {
    namespace JungleStairs {
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (half) {
                case Properties::Half::TOP:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7596;
                        case Properties::Waterlogged::FALSE:
                            return 7597;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7598;
                        case Properties::Waterlogged::FALSE:
                            return 7599;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7600;
                        case Properties::Waterlogged::FALSE:
                            return 7601;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7602;
                        case Properties::Waterlogged::FALSE:
                            return 7603;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7604;
                        case Properties::Waterlogged::FALSE:
                            return 7605;
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7606;
                        case Properties::Waterlogged::FALSE:
                            return 7607;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7608;
                        case Properties::Waterlogged::FALSE:
                            return 7609;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7610;
                        case Properties::Waterlogged::FALSE:
                            return 7611;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7612;
                        case Properties::Waterlogged::FALSE:
                            return 7613;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7614;
                        case Properties::Waterlogged::FALSE:
                            return 7615;
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Facing::SOUTH:
                switch (half) {
                case Properties::Half::TOP:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7616;
                        case Properties::Waterlogged::FALSE:
                            return 7617;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7618;
                        case Properties::Waterlogged::FALSE:
                            return 7619;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7620;
                        case Properties::Waterlogged::FALSE:
                            return 7621;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7622;
                        case Properties::Waterlogged::FALSE:
                            return 7623;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7624;
                        case Properties::Waterlogged::FALSE:
                            return 7625;
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7626;
                        case Properties::Waterlogged::FALSE:
                            return 7627;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7628;
                        case Properties::Waterlogged::FALSE:
                            return 7629;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7630;
                        case Properties::Waterlogged::FALSE:
                            return 7631;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7632;
                        case Properties::Waterlogged::FALSE:
                            return 7633;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7634;
                        case Properties::Waterlogged::FALSE:
                            return 7635;
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Facing::WEST:
                switch (half) {
                case Properties::Half::TOP:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7636;
                        case Properties::Waterlogged::FALSE:
                            return 7637;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7638;
                        case Properties::Waterlogged::FALSE:
                            return 7639;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7640;
                        case Properties::Waterlogged::FALSE:
                            return 7641;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7642;
                        case Properties::Waterlogged::FALSE:
                            return 7643;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7644;
                        case Properties::Waterlogged::FALSE:
                            return 7645;
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7646;
                        case Properties::Waterlogged::FALSE:
                            return 7647;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7648;
                        case Properties::Waterlogged::FALSE:
                            return 7649;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7650;
                        case Properties::Waterlogged::FALSE:
                            return 7651;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7652;
                        case Properties::Waterlogged::FALSE:
                            return 7653;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7654;
                        case Properties::Waterlogged::FALSE:
                            return 7655;
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Facing::EAST:
                switch (half) {
                case Properties::Half::TOP:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7656;
                        case Properties::Waterlogged::FALSE:
                            return 7657;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7658;
                        case Properties::Waterlogged::FALSE:
                            return 7659;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7660;
                        case Properties::Waterlogged::FALSE:
                            return 7661;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7662;
                        case Properties::Waterlogged::FALSE:
                            return 7663;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7664;
                        case Properties::Waterlogged::FALSE:
                            return 7665;
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7666;
                        case Properties::Waterlogged::FALSE:
                            return 7667;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7668;
                        case Properties::Waterlogged::FALSE:
                            return 7669;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7670;
                        case Properties::Waterlogged::FALSE:
                            return 7671;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7672;
                        case Properties::Waterlogged::FALSE:
                            return 7673;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 7674;
                        case Properties::Waterlogged::FALSE:
                            return 7675;
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
