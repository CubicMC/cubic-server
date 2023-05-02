#include "QuartzStairs.hpp"
#include <stdexcept>

namespace Blocks {
namespace QuartzStairs {
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
                    return 8844;
                case Properties::Waterlogged::FALSE:
                    return 8845;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8846;
                case Properties::Waterlogged::FALSE:
                    return 8847;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8848;
                case Properties::Waterlogged::FALSE:
                    return 8849;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8850;
                case Properties::Waterlogged::FALSE:
                    return 8851;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8852;
                case Properties::Waterlogged::FALSE:
                    return 8853;
                }
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8854;
                case Properties::Waterlogged::FALSE:
                    return 8855;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8856;
                case Properties::Waterlogged::FALSE:
                    return 8857;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8858;
                case Properties::Waterlogged::FALSE:
                    return 8859;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8860;
                case Properties::Waterlogged::FALSE:
                    return 8861;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8862;
                case Properties::Waterlogged::FALSE:
                    return 8863;
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
                    return 8864;
                case Properties::Waterlogged::FALSE:
                    return 8865;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8866;
                case Properties::Waterlogged::FALSE:
                    return 8867;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8868;
                case Properties::Waterlogged::FALSE:
                    return 8869;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8870;
                case Properties::Waterlogged::FALSE:
                    return 8871;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8872;
                case Properties::Waterlogged::FALSE:
                    return 8873;
                }
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8874;
                case Properties::Waterlogged::FALSE:
                    return 8875;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8876;
                case Properties::Waterlogged::FALSE:
                    return 8877;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8878;
                case Properties::Waterlogged::FALSE:
                    return 8879;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8880;
                case Properties::Waterlogged::FALSE:
                    return 8881;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8882;
                case Properties::Waterlogged::FALSE:
                    return 8883;
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
                    return 8884;
                case Properties::Waterlogged::FALSE:
                    return 8885;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8886;
                case Properties::Waterlogged::FALSE:
                    return 8887;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8888;
                case Properties::Waterlogged::FALSE:
                    return 8889;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8890;
                case Properties::Waterlogged::FALSE:
                    return 8891;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8892;
                case Properties::Waterlogged::FALSE:
                    return 8893;
                }
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8894;
                case Properties::Waterlogged::FALSE:
                    return 8895;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8896;
                case Properties::Waterlogged::FALSE:
                    return 8897;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8898;
                case Properties::Waterlogged::FALSE:
                    return 8899;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8900;
                case Properties::Waterlogged::FALSE:
                    return 8901;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8902;
                case Properties::Waterlogged::FALSE:
                    return 8903;
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
                    return 8904;
                case Properties::Waterlogged::FALSE:
                    return 8905;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8906;
                case Properties::Waterlogged::FALSE:
                    return 8907;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8908;
                case Properties::Waterlogged::FALSE:
                    return 8909;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8910;
                case Properties::Waterlogged::FALSE:
                    return 8911;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8912;
                case Properties::Waterlogged::FALSE:
                    return 8913;
                }
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8914;
                case Properties::Waterlogged::FALSE:
                    return 8915;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8916;
                case Properties::Waterlogged::FALSE:
                    return 8917;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8918;
                case Properties::Waterlogged::FALSE:
                    return 8919;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8920;
                case Properties::Waterlogged::FALSE:
                    return 8921;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 8922;
                case Properties::Waterlogged::FALSE:
                    return 8923;
                }
            }
        }
    }
    return 0;
}
}

}
