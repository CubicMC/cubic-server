#include "OakStairs.hpp"
#include <stdexcept>

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
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2824;
                        case Properties::Waterlogged::FALSE:
                            return 2825;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2826;
                        case Properties::Waterlogged::FALSE:
                            return 2827;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2828;
                        case Properties::Waterlogged::FALSE:
                            return 2829;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2830;
                        case Properties::Waterlogged::FALSE:
                            return 2831;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2832;
                        case Properties::Waterlogged::FALSE:
                            return 2833;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2834;
                        case Properties::Waterlogged::FALSE:
                            return 2835;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2836;
                        case Properties::Waterlogged::FALSE:
                            return 2837;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2838;
                        case Properties::Waterlogged::FALSE:
                            return 2839;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2840;
                        case Properties::Waterlogged::FALSE:
                            return 2841;
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
                            return 2842;
                        case Properties::Waterlogged::FALSE:
                            return 2843;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2844;
                        case Properties::Waterlogged::FALSE:
                            return 2845;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2846;
                        case Properties::Waterlogged::FALSE:
                            return 2847;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2848;
                        case Properties::Waterlogged::FALSE:
                            return 2849;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2850;
                        case Properties::Waterlogged::FALSE:
                            return 2851;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2852;
                        case Properties::Waterlogged::FALSE:
                            return 2853;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2854;
                        case Properties::Waterlogged::FALSE:
                            return 2855;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2856;
                        case Properties::Waterlogged::FALSE:
                            return 2857;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2858;
                        case Properties::Waterlogged::FALSE:
                            return 2859;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2860;
                        case Properties::Waterlogged::FALSE:
                            return 2861;
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
                            return 2862;
                        case Properties::Waterlogged::FALSE:
                            return 2863;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2864;
                        case Properties::Waterlogged::FALSE:
                            return 2865;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2866;
                        case Properties::Waterlogged::FALSE:
                            return 2867;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2868;
                        case Properties::Waterlogged::FALSE:
                            return 2869;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2870;
                        case Properties::Waterlogged::FALSE:
                            return 2871;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2872;
                        case Properties::Waterlogged::FALSE:
                            return 2873;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2874;
                        case Properties::Waterlogged::FALSE:
                            return 2875;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2876;
                        case Properties::Waterlogged::FALSE:
                            return 2877;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2878;
                        case Properties::Waterlogged::FALSE:
                            return 2879;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2880;
                        case Properties::Waterlogged::FALSE:
                            return 2881;
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
                            return 2882;
                        case Properties::Waterlogged::FALSE:
                            return 2883;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2884;
                        case Properties::Waterlogged::FALSE:
                            return 2885;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2886;
                        case Properties::Waterlogged::FALSE:
                            return 2887;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2888;
                        case Properties::Waterlogged::FALSE:
                            return 2889;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2890;
                        case Properties::Waterlogged::FALSE:
                            return 2891;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2892;
                        case Properties::Waterlogged::FALSE:
                            return 2893;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2894;
                        case Properties::Waterlogged::FALSE:
                            return 2895;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2896;
                        case Properties::Waterlogged::FALSE:
                            return 2897;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2898;
                        case Properties::Waterlogged::FALSE:
                            return 2899;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 2900;
                        case Properties::Waterlogged::FALSE:
                            return 2901;
                        }
                    }
                }
            }
            return 0;
        }
    }

}
