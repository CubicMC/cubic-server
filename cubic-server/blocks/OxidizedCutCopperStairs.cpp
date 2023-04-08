#include "OxidizedCutCopperStairs.hpp"
#include <stdexcept>

namespace Blocks {
namespace OxidizedCutCopperStairs {
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
                    return 20702;
                case Properties::Waterlogged::FALSE:
                    return 20703;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20704;
                case Properties::Waterlogged::FALSE:
                    return 20705;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20706;
                case Properties::Waterlogged::FALSE:
                    return 20707;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20708;
                case Properties::Waterlogged::FALSE:
                    return 20709;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20710;
                case Properties::Waterlogged::FALSE:
                    return 20711;
                }
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20712;
                case Properties::Waterlogged::FALSE:
                    return 20713;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20714;
                case Properties::Waterlogged::FALSE:
                    return 20715;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20716;
                case Properties::Waterlogged::FALSE:
                    return 20717;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20718;
                case Properties::Waterlogged::FALSE:
                    return 20719;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20720;
                case Properties::Waterlogged::FALSE:
                    return 20721;
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
                    return 20722;
                case Properties::Waterlogged::FALSE:
                    return 20723;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20724;
                case Properties::Waterlogged::FALSE:
                    return 20725;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20726;
                case Properties::Waterlogged::FALSE:
                    return 20727;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20728;
                case Properties::Waterlogged::FALSE:
                    return 20729;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20730;
                case Properties::Waterlogged::FALSE:
                    return 20731;
                }
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20732;
                case Properties::Waterlogged::FALSE:
                    return 20733;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20734;
                case Properties::Waterlogged::FALSE:
                    return 20735;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20736;
                case Properties::Waterlogged::FALSE:
                    return 20737;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20738;
                case Properties::Waterlogged::FALSE:
                    return 20739;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20740;
                case Properties::Waterlogged::FALSE:
                    return 20741;
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
                    return 20742;
                case Properties::Waterlogged::FALSE:
                    return 20743;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20744;
                case Properties::Waterlogged::FALSE:
                    return 20745;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20746;
                case Properties::Waterlogged::FALSE:
                    return 20747;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20748;
                case Properties::Waterlogged::FALSE:
                    return 20749;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20750;
                case Properties::Waterlogged::FALSE:
                    return 20751;
                }
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20752;
                case Properties::Waterlogged::FALSE:
                    return 20753;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20754;
                case Properties::Waterlogged::FALSE:
                    return 20755;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20756;
                case Properties::Waterlogged::FALSE:
                    return 20757;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20758;
                case Properties::Waterlogged::FALSE:
                    return 20759;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20760;
                case Properties::Waterlogged::FALSE:
                    return 20761;
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
                    return 20762;
                case Properties::Waterlogged::FALSE:
                    return 20763;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20764;
                case Properties::Waterlogged::FALSE:
                    return 20765;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20766;
                case Properties::Waterlogged::FALSE:
                    return 20767;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20768;
                case Properties::Waterlogged::FALSE:
                    return 20769;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20770;
                case Properties::Waterlogged::FALSE:
                    return 20771;
                }
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20772;
                case Properties::Waterlogged::FALSE:
                    return 20773;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20774;
                case Properties::Waterlogged::FALSE:
                    return 20775;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20776;
                case Properties::Waterlogged::FALSE:
                    return 20777;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20778;
                case Properties::Waterlogged::FALSE:
                    return 20779;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 20780;
                case Properties::Waterlogged::FALSE:
                    return 20781;
                }
            }
        }
    }
    return 0;
}
}

}
