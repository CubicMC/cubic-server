#include "OakStairs.hpp"
namespace Blocks {
    namespace OakStairs {
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (half) {
                case Properties::Half::TOP:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2822;
                        case Properties::Waterlogged::FALSE:
                            return 2823;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2824;
                        case Properties::Waterlogged::FALSE:
                            return 2825;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2826;
                        case Properties::Waterlogged::FALSE:
                            return 2827;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2828;
                        case Properties::Waterlogged::FALSE:
                            return 2829;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2830;
                        case Properties::Waterlogged::FALSE:
                            return 2831;
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
                            return 2832;
                        case Properties::Waterlogged::FALSE:
                            return 2833;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2834;
                        case Properties::Waterlogged::FALSE:
                            return 2835;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2836;
                        case Properties::Waterlogged::FALSE:
                            return 2837;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2838;
                        case Properties::Waterlogged::FALSE:
                            return 2839;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2840;
                        case Properties::Waterlogged::FALSE:
                            return 2841;
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
                            return 2842;
                        case Properties::Waterlogged::FALSE:
                            return 2843;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2844;
                        case Properties::Waterlogged::FALSE:
                            return 2845;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2846;
                        case Properties::Waterlogged::FALSE:
                            return 2847;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2848;
                        case Properties::Waterlogged::FALSE:
                            return 2849;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2850;
                        case Properties::Waterlogged::FALSE:
                            return 2851;
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
                            return 2852;
                        case Properties::Waterlogged::FALSE:
                            return 2853;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2854;
                        case Properties::Waterlogged::FALSE:
                            return 2855;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2856;
                        case Properties::Waterlogged::FALSE:
                            return 2857;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2858;
                        case Properties::Waterlogged::FALSE:
                            return 2859;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2860;
                        case Properties::Waterlogged::FALSE:
                            return 2861;
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
                            return 2862;
                        case Properties::Waterlogged::FALSE:
                            return 2863;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2864;
                        case Properties::Waterlogged::FALSE:
                            return 2865;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2866;
                        case Properties::Waterlogged::FALSE:
                            return 2867;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2868;
                        case Properties::Waterlogged::FALSE:
                            return 2869;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2870;
                        case Properties::Waterlogged::FALSE:
                            return 2871;
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
                            return 2872;
                        case Properties::Waterlogged::FALSE:
                            return 2873;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2874;
                        case Properties::Waterlogged::FALSE:
                            return 2875;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2876;
                        case Properties::Waterlogged::FALSE:
                            return 2877;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2878;
                        case Properties::Waterlogged::FALSE:
                            return 2879;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2880;
                        case Properties::Waterlogged::FALSE:
                            return 2881;
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
                            return 2882;
                        case Properties::Waterlogged::FALSE:
                            return 2883;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2884;
                        case Properties::Waterlogged::FALSE:
                            return 2885;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2886;
                        case Properties::Waterlogged::FALSE:
                            return 2887;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2888;
                        case Properties::Waterlogged::FALSE:
                            return 2889;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2890;
                        case Properties::Waterlogged::FALSE:
                            return 2891;
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
                            return 2892;
                        case Properties::Waterlogged::FALSE:
                            return 2893;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2894;
                        case Properties::Waterlogged::FALSE:
                            return 2895;
                        default:
                            return 0;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2896;
                        case Properties::Waterlogged::FALSE:
                            return 2897;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2898;
                        case Properties::Waterlogged::FALSE:
                            return 2899;
                        default:
                            return 0;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2900;
                        case Properties::Waterlogged::FALSE:
                            return 2901;
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
