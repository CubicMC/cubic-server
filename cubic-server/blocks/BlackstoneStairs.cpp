#include "BlackstoneStairs.hpp"
namespace Blocks {
    namespace BlackstoneStairs {
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (half) {
                case Properties::Half::TOP:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 18833;
                        case Properties::Waterlogged::FALSE:
                            return 18834;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 18835;
                        case Properties::Waterlogged::FALSE:
                            return 18836;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 18837;
                        case Properties::Waterlogged::FALSE:
                            return 18838;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 18839;
                        case Properties::Waterlogged::FALSE:
                            return 18840;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 18841;
                        case Properties::Waterlogged::FALSE:
                            return 18842;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 18843;
                        case Properties::Waterlogged::FALSE:
                            return 18844;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 18845;
                        case Properties::Waterlogged::FALSE:
                            return 18846;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 18847;
                        case Properties::Waterlogged::FALSE:
                            return 18848;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 18849;
                        case Properties::Waterlogged::FALSE:
                            return 18850;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 18851;
                        case Properties::Waterlogged::FALSE:
                            return 18852;
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
                            return 18853;
                        case Properties::Waterlogged::FALSE:
                            return 18854;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 18855;
                        case Properties::Waterlogged::FALSE:
                            return 18856;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 18857;
                        case Properties::Waterlogged::FALSE:
                            return 18858;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 18859;
                        case Properties::Waterlogged::FALSE:
                            return 18860;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 18861;
                        case Properties::Waterlogged::FALSE:
                            return 18862;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 18863;
                        case Properties::Waterlogged::FALSE:
                            return 18864;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 18865;
                        case Properties::Waterlogged::FALSE:
                            return 18866;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 18867;
                        case Properties::Waterlogged::FALSE:
                            return 18868;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 18869;
                        case Properties::Waterlogged::FALSE:
                            return 18870;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 18871;
                        case Properties::Waterlogged::FALSE:
                            return 18872;
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
                            return 18873;
                        case Properties::Waterlogged::FALSE:
                            return 18874;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 18875;
                        case Properties::Waterlogged::FALSE:
                            return 18876;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 18877;
                        case Properties::Waterlogged::FALSE:
                            return 18878;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 18879;
                        case Properties::Waterlogged::FALSE:
                            return 18880;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 18881;
                        case Properties::Waterlogged::FALSE:
                            return 18882;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 18883;
                        case Properties::Waterlogged::FALSE:
                            return 18884;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 18885;
                        case Properties::Waterlogged::FALSE:
                            return 18886;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 18887;
                        case Properties::Waterlogged::FALSE:
                            return 18888;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 18889;
                        case Properties::Waterlogged::FALSE:
                            return 18890;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 18891;
                        case Properties::Waterlogged::FALSE:
                            return 18892;
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
                            return 18893;
                        case Properties::Waterlogged::FALSE:
                            return 18894;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 18895;
                        case Properties::Waterlogged::FALSE:
                            return 18896;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 18897;
                        case Properties::Waterlogged::FALSE:
                            return 18898;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 18899;
                        case Properties::Waterlogged::FALSE:
                            return 18900;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 18901;
                        case Properties::Waterlogged::FALSE:
                            return 18902;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 18903;
                        case Properties::Waterlogged::FALSE:
                            return 18904;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 18905;
                        case Properties::Waterlogged::FALSE:
                            return 18906;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 18907;
                        case Properties::Waterlogged::FALSE:
                            return 18908;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 18909;
                        case Properties::Waterlogged::FALSE:
                            return 18910;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 18911;
                        case Properties::Waterlogged::FALSE:
                            return 18912;
                        }
                    }
                }
            }
            return 0;
        }
    }

}
