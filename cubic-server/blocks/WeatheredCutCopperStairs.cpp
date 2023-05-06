#include "WeatheredCutCopperStairs.hpp"
namespace Blocks {
    namespace WeatheredCutCopperStairs {
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (half) {
                case Properties::Half::TOP:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 20782;
                        case Properties::Waterlogged::FALSE:
                            return 20783;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 20784;
                        case Properties::Waterlogged::FALSE:
                            return 20785;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 20786;
                        case Properties::Waterlogged::FALSE:
                            return 20787;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 20788;
                        case Properties::Waterlogged::FALSE:
                            return 20789;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 20790;
                        case Properties::Waterlogged::FALSE:
                            return 20791;
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
                            return 20792;
                        case Properties::Waterlogged::FALSE:
                            return 20793;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 20794;
                        case Properties::Waterlogged::FALSE:
                            return 20795;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 20796;
                        case Properties::Waterlogged::FALSE:
                            return 20797;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 20798;
                        case Properties::Waterlogged::FALSE:
                            return 20799;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 20800;
                        case Properties::Waterlogged::FALSE:
                            return 20801;
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
                            return 20802;
                        case Properties::Waterlogged::FALSE:
                            return 20803;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 20804;
                        case Properties::Waterlogged::FALSE:
                            return 20805;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 20806;
                        case Properties::Waterlogged::FALSE:
                            return 20807;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 20808;
                        case Properties::Waterlogged::FALSE:
                            return 20809;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 20810;
                        case Properties::Waterlogged::FALSE:
                            return 20811;
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
                            return 20812;
                        case Properties::Waterlogged::FALSE:
                            return 20813;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 20814;
                        case Properties::Waterlogged::FALSE:
                            return 20815;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 20816;
                        case Properties::Waterlogged::FALSE:
                            return 20817;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 20818;
                        case Properties::Waterlogged::FALSE:
                            return 20819;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 20820;
                        case Properties::Waterlogged::FALSE:
                            return 20821;
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
                            return 20822;
                        case Properties::Waterlogged::FALSE:
                            return 20823;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 20824;
                        case Properties::Waterlogged::FALSE:
                            return 20825;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 20826;
                        case Properties::Waterlogged::FALSE:
                            return 20827;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 20828;
                        case Properties::Waterlogged::FALSE:
                            return 20829;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 20830;
                        case Properties::Waterlogged::FALSE:
                            return 20831;
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
                            return 20832;
                        case Properties::Waterlogged::FALSE:
                            return 20833;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 20834;
                        case Properties::Waterlogged::FALSE:
                            return 20835;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 20836;
                        case Properties::Waterlogged::FALSE:
                            return 20837;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 20838;
                        case Properties::Waterlogged::FALSE:
                            return 20839;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 20840;
                        case Properties::Waterlogged::FALSE:
                            return 20841;
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
                            return 20842;
                        case Properties::Waterlogged::FALSE:
                            return 20843;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 20844;
                        case Properties::Waterlogged::FALSE:
                            return 20845;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 20846;
                        case Properties::Waterlogged::FALSE:
                            return 20847;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 20848;
                        case Properties::Waterlogged::FALSE:
                            return 20849;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 20850;
                        case Properties::Waterlogged::FALSE:
                            return 20851;
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
                            return 20852;
                        case Properties::Waterlogged::FALSE:
                            return 20853;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 20854;
                        case Properties::Waterlogged::FALSE:
                            return 20855;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 20856;
                        case Properties::Waterlogged::FALSE:
                            return 20857;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 20858;
                        case Properties::Waterlogged::FALSE:
                            return 20859;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 20860;
                        case Properties::Waterlogged::FALSE:
                            return 20861;
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
