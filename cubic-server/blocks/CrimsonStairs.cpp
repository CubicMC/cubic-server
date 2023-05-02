#include "CrimsonStairs.hpp"
#include <stdexcept>

namespace Blocks {
namespace CrimsonStairs {
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
                    return 18312;
                case Properties::Waterlogged::FALSE:
                    return 18313;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18314;
                case Properties::Waterlogged::FALSE:
                    return 18315;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18316;
                case Properties::Waterlogged::FALSE:
                    return 18317;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18318;
                case Properties::Waterlogged::FALSE:
                    return 18319;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18320;
                case Properties::Waterlogged::FALSE:
                    return 18321;
                }
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18322;
                case Properties::Waterlogged::FALSE:
                    return 18323;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18324;
                case Properties::Waterlogged::FALSE:
                    return 18325;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18326;
                case Properties::Waterlogged::FALSE:
                    return 18327;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18328;
                case Properties::Waterlogged::FALSE:
                    return 18329;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18330;
                case Properties::Waterlogged::FALSE:
                    return 18331;
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
                    return 18332;
                case Properties::Waterlogged::FALSE:
                    return 18333;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18334;
                case Properties::Waterlogged::FALSE:
                    return 18335;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18336;
                case Properties::Waterlogged::FALSE:
                    return 18337;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18338;
                case Properties::Waterlogged::FALSE:
                    return 18339;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18340;
                case Properties::Waterlogged::FALSE:
                    return 18341;
                }
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18342;
                case Properties::Waterlogged::FALSE:
                    return 18343;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18344;
                case Properties::Waterlogged::FALSE:
                    return 18345;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18346;
                case Properties::Waterlogged::FALSE:
                    return 18347;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18348;
                case Properties::Waterlogged::FALSE:
                    return 18349;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18350;
                case Properties::Waterlogged::FALSE:
                    return 18351;
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
                    return 18352;
                case Properties::Waterlogged::FALSE:
                    return 18353;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18354;
                case Properties::Waterlogged::FALSE:
                    return 18355;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18356;
                case Properties::Waterlogged::FALSE:
                    return 18357;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18358;
                case Properties::Waterlogged::FALSE:
                    return 18359;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18360;
                case Properties::Waterlogged::FALSE:
                    return 18361;
                }
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18362;
                case Properties::Waterlogged::FALSE:
                    return 18363;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18364;
                case Properties::Waterlogged::FALSE:
                    return 18365;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18366;
                case Properties::Waterlogged::FALSE:
                    return 18367;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18368;
                case Properties::Waterlogged::FALSE:
                    return 18369;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18370;
                case Properties::Waterlogged::FALSE:
                    return 18371;
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
                    return 18372;
                case Properties::Waterlogged::FALSE:
                    return 18373;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18374;
                case Properties::Waterlogged::FALSE:
                    return 18375;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18376;
                case Properties::Waterlogged::FALSE:
                    return 18377;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18378;
                case Properties::Waterlogged::FALSE:
                    return 18379;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18380;
                case Properties::Waterlogged::FALSE:
                    return 18381;
                }
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18382;
                case Properties::Waterlogged::FALSE:
                    return 18383;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18384;
                case Properties::Waterlogged::FALSE:
                    return 18385;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18386;
                case Properties::Waterlogged::FALSE:
                    return 18387;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18388;
                case Properties::Waterlogged::FALSE:
                    return 18389;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 18390;
                case Properties::Waterlogged::FALSE:
                    return 18391;
                }
            }
        }
    }
    return 0;
}
}

}
