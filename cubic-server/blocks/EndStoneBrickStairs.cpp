#include "EndStoneBrickStairs.hpp"
#include <stdexcept>

namespace Blocks {
namespace EndStoneBrickStairs {
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
                    return 12734;
                case Properties::Waterlogged::FALSE:
                    return 12735;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12736;
                case Properties::Waterlogged::FALSE:
                    return 12737;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12738;
                case Properties::Waterlogged::FALSE:
                    return 12739;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12740;
                case Properties::Waterlogged::FALSE:
                    return 12741;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12742;
                case Properties::Waterlogged::FALSE:
                    return 12743;
                }
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12744;
                case Properties::Waterlogged::FALSE:
                    return 12745;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12746;
                case Properties::Waterlogged::FALSE:
                    return 12747;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12748;
                case Properties::Waterlogged::FALSE:
                    return 12749;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12750;
                case Properties::Waterlogged::FALSE:
                    return 12751;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12752;
                case Properties::Waterlogged::FALSE:
                    return 12753;
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
                    return 12754;
                case Properties::Waterlogged::FALSE:
                    return 12755;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12756;
                case Properties::Waterlogged::FALSE:
                    return 12757;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12758;
                case Properties::Waterlogged::FALSE:
                    return 12759;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12760;
                case Properties::Waterlogged::FALSE:
                    return 12761;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12762;
                case Properties::Waterlogged::FALSE:
                    return 12763;
                }
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12764;
                case Properties::Waterlogged::FALSE:
                    return 12765;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12766;
                case Properties::Waterlogged::FALSE:
                    return 12767;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12768;
                case Properties::Waterlogged::FALSE:
                    return 12769;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12770;
                case Properties::Waterlogged::FALSE:
                    return 12771;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12772;
                case Properties::Waterlogged::FALSE:
                    return 12773;
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
                    return 12774;
                case Properties::Waterlogged::FALSE:
                    return 12775;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12776;
                case Properties::Waterlogged::FALSE:
                    return 12777;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12778;
                case Properties::Waterlogged::FALSE:
                    return 12779;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12780;
                case Properties::Waterlogged::FALSE:
                    return 12781;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12782;
                case Properties::Waterlogged::FALSE:
                    return 12783;
                }
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12784;
                case Properties::Waterlogged::FALSE:
                    return 12785;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12786;
                case Properties::Waterlogged::FALSE:
                    return 12787;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12788;
                case Properties::Waterlogged::FALSE:
                    return 12789;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12790;
                case Properties::Waterlogged::FALSE:
                    return 12791;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12792;
                case Properties::Waterlogged::FALSE:
                    return 12793;
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
                    return 12794;
                case Properties::Waterlogged::FALSE:
                    return 12795;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12796;
                case Properties::Waterlogged::FALSE:
                    return 12797;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12798;
                case Properties::Waterlogged::FALSE:
                    return 12799;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12800;
                case Properties::Waterlogged::FALSE:
                    return 12801;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12802;
                case Properties::Waterlogged::FALSE:
                    return 12803;
                }
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12804;
                case Properties::Waterlogged::FALSE:
                    return 12805;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12806;
                case Properties::Waterlogged::FALSE:
                    return 12807;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12808;
                case Properties::Waterlogged::FALSE:
                    return 12809;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12810;
                case Properties::Waterlogged::FALSE:
                    return 12811;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 12812;
                case Properties::Waterlogged::FALSE:
                    return 12813;
                }
            }
        }
    }
    return 0;
}
}

}
