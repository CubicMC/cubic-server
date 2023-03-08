#include "BambooMosaicStairs.hpp"
#include <stdexcept>

namespace Blocks {
    namespace BambooMosaicStairs {
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (half) {
                case Properties::Half::TOP:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 9808;
                        case Properties::Waterlogged::FALSE:
                            return 9809;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 9810;
                        case Properties::Waterlogged::FALSE:
                            return 9811;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 9812;
                        case Properties::Waterlogged::FALSE:
                            return 9813;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 9814;
                        case Properties::Waterlogged::FALSE:
                            return 9815;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 9816;
                        case Properties::Waterlogged::FALSE:
                            return 9817;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 9818;
                        case Properties::Waterlogged::FALSE:
                            return 9819;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 9820;
                        case Properties::Waterlogged::FALSE:
                            return 9821;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 9822;
                        case Properties::Waterlogged::FALSE:
                            return 9823;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 9824;
                        case Properties::Waterlogged::FALSE:
                            return 9825;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 9826;
                        case Properties::Waterlogged::FALSE:
                            return 9827;
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
                            return 9828;
                        case Properties::Waterlogged::FALSE:
                            return 9829;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 9830;
                        case Properties::Waterlogged::FALSE:
                            return 9831;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 9832;
                        case Properties::Waterlogged::FALSE:
                            return 9833;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 9834;
                        case Properties::Waterlogged::FALSE:
                            return 9835;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 9836;
                        case Properties::Waterlogged::FALSE:
                            return 9837;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 9838;
                        case Properties::Waterlogged::FALSE:
                            return 9839;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 9840;
                        case Properties::Waterlogged::FALSE:
                            return 9841;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 9842;
                        case Properties::Waterlogged::FALSE:
                            return 9843;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 9844;
                        case Properties::Waterlogged::FALSE:
                            return 9845;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 9846;
                        case Properties::Waterlogged::FALSE:
                            return 9847;
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
                            return 9848;
                        case Properties::Waterlogged::FALSE:
                            return 9849;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 9850;
                        case Properties::Waterlogged::FALSE:
                            return 9851;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 9852;
                        case Properties::Waterlogged::FALSE:
                            return 9853;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 9854;
                        case Properties::Waterlogged::FALSE:
                            return 9855;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 9856;
                        case Properties::Waterlogged::FALSE:
                            return 9857;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 9858;
                        case Properties::Waterlogged::FALSE:
                            return 9859;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 9860;
                        case Properties::Waterlogged::FALSE:
                            return 9861;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 9862;
                        case Properties::Waterlogged::FALSE:
                            return 9863;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 9864;
                        case Properties::Waterlogged::FALSE:
                            return 9865;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 9866;
                        case Properties::Waterlogged::FALSE:
                            return 9867;
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
                            return 9868;
                        case Properties::Waterlogged::FALSE:
                            return 9869;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 9870;
                        case Properties::Waterlogged::FALSE:
                            return 9871;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 9872;
                        case Properties::Waterlogged::FALSE:
                            return 9873;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 9874;
                        case Properties::Waterlogged::FALSE:
                            return 9875;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 9876;
                        case Properties::Waterlogged::FALSE:
                            return 9877;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 9878;
                        case Properties::Waterlogged::FALSE:
                            return 9879;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 9880;
                        case Properties::Waterlogged::FALSE:
                            return 9881;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 9882;
                        case Properties::Waterlogged::FALSE:
                            return 9883;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 9884;
                        case Properties::Waterlogged::FALSE:
                            return 9885;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 9886;
                        case Properties::Waterlogged::FALSE:
                            return 9887;
                        }
                    }
                }
            }
            return 0;
        }
    }

}
