#include "PrismarineBrickStairs.hpp"
#include <stdexcept>

namespace Blocks {
namespace PrismarineBrickStairs {
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
                    return 10069;
                case Properties::Waterlogged::FALSE:
                    return 10070;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10071;
                case Properties::Waterlogged::FALSE:
                    return 10072;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10073;
                case Properties::Waterlogged::FALSE:
                    return 10074;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10075;
                case Properties::Waterlogged::FALSE:
                    return 10076;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10077;
                case Properties::Waterlogged::FALSE:
                    return 10078;
                }
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10079;
                case Properties::Waterlogged::FALSE:
                    return 10080;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10081;
                case Properties::Waterlogged::FALSE:
                    return 10082;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10083;
                case Properties::Waterlogged::FALSE:
                    return 10084;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10085;
                case Properties::Waterlogged::FALSE:
                    return 10086;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10087;
                case Properties::Waterlogged::FALSE:
                    return 10088;
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
                    return 10089;
                case Properties::Waterlogged::FALSE:
                    return 10090;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10091;
                case Properties::Waterlogged::FALSE:
                    return 10092;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10093;
                case Properties::Waterlogged::FALSE:
                    return 10094;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10095;
                case Properties::Waterlogged::FALSE:
                    return 10096;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10097;
                case Properties::Waterlogged::FALSE:
                    return 10098;
                }
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10099;
                case Properties::Waterlogged::FALSE:
                    return 10100;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10101;
                case Properties::Waterlogged::FALSE:
                    return 10102;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10103;
                case Properties::Waterlogged::FALSE:
                    return 10104;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10105;
                case Properties::Waterlogged::FALSE:
                    return 10106;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10107;
                case Properties::Waterlogged::FALSE:
                    return 10108;
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
                    return 10109;
                case Properties::Waterlogged::FALSE:
                    return 10110;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10111;
                case Properties::Waterlogged::FALSE:
                    return 10112;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10113;
                case Properties::Waterlogged::FALSE:
                    return 10114;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10115;
                case Properties::Waterlogged::FALSE:
                    return 10116;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10117;
                case Properties::Waterlogged::FALSE:
                    return 10118;
                }
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10119;
                case Properties::Waterlogged::FALSE:
                    return 10120;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10121;
                case Properties::Waterlogged::FALSE:
                    return 10122;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10123;
                case Properties::Waterlogged::FALSE:
                    return 10124;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10125;
                case Properties::Waterlogged::FALSE:
                    return 10126;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10127;
                case Properties::Waterlogged::FALSE:
                    return 10128;
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
                    return 10129;
                case Properties::Waterlogged::FALSE:
                    return 10130;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10131;
                case Properties::Waterlogged::FALSE:
                    return 10132;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10133;
                case Properties::Waterlogged::FALSE:
                    return 10134;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10135;
                case Properties::Waterlogged::FALSE:
                    return 10136;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10137;
                case Properties::Waterlogged::FALSE:
                    return 10138;
                }
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10139;
                case Properties::Waterlogged::FALSE:
                    return 10140;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10141;
                case Properties::Waterlogged::FALSE:
                    return 10142;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10143;
                case Properties::Waterlogged::FALSE:
                    return 10144;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10145;
                case Properties::Waterlogged::FALSE:
                    return 10146;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 10147;
                case Properties::Waterlogged::FALSE:
                    return 10148;
                }
            }
        }
    }
    return 0;
}
}

}
