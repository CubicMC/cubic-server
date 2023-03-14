#include "DeepslateTileStairs.hpp"
#include <stdexcept>

namespace Blocks {
    namespace DeepslateTileStairs {
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (half) {
                case Properties::Half::TOP:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22388;
                        case Properties::Waterlogged::FALSE:
                            return 22389;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22390;
                        case Properties::Waterlogged::FALSE:
                            return 22391;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22392;
                        case Properties::Waterlogged::FALSE:
                            return 22393;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22394;
                        case Properties::Waterlogged::FALSE:
                            return 22395;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22396;
                        case Properties::Waterlogged::FALSE:
                            return 22397;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22398;
                        case Properties::Waterlogged::FALSE:
                            return 22399;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22400;
                        case Properties::Waterlogged::FALSE:
                            return 22401;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22402;
                        case Properties::Waterlogged::FALSE:
                            return 22403;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22404;
                        case Properties::Waterlogged::FALSE:
                            return 22405;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22406;
                        case Properties::Waterlogged::FALSE:
                            return 22407;
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
                            return 22408;
                        case Properties::Waterlogged::FALSE:
                            return 22409;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22410;
                        case Properties::Waterlogged::FALSE:
                            return 22411;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22412;
                        case Properties::Waterlogged::FALSE:
                            return 22413;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22414;
                        case Properties::Waterlogged::FALSE:
                            return 22415;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22416;
                        case Properties::Waterlogged::FALSE:
                            return 22417;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22418;
                        case Properties::Waterlogged::FALSE:
                            return 22419;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22420;
                        case Properties::Waterlogged::FALSE:
                            return 22421;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22422;
                        case Properties::Waterlogged::FALSE:
                            return 22423;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22424;
                        case Properties::Waterlogged::FALSE:
                            return 22425;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22426;
                        case Properties::Waterlogged::FALSE:
                            return 22427;
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
                            return 22428;
                        case Properties::Waterlogged::FALSE:
                            return 22429;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22430;
                        case Properties::Waterlogged::FALSE:
                            return 22431;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22432;
                        case Properties::Waterlogged::FALSE:
                            return 22433;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22434;
                        case Properties::Waterlogged::FALSE:
                            return 22435;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22436;
                        case Properties::Waterlogged::FALSE:
                            return 22437;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22438;
                        case Properties::Waterlogged::FALSE:
                            return 22439;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22440;
                        case Properties::Waterlogged::FALSE:
                            return 22441;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22442;
                        case Properties::Waterlogged::FALSE:
                            return 22443;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22444;
                        case Properties::Waterlogged::FALSE:
                            return 22445;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22446;
                        case Properties::Waterlogged::FALSE:
                            return 22447;
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
                            return 22448;
                        case Properties::Waterlogged::FALSE:
                            return 22449;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22450;
                        case Properties::Waterlogged::FALSE:
                            return 22451;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22452;
                        case Properties::Waterlogged::FALSE:
                            return 22453;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22454;
                        case Properties::Waterlogged::FALSE:
                            return 22455;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22456;
                        case Properties::Waterlogged::FALSE:
                            return 22457;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22458;
                        case Properties::Waterlogged::FALSE:
                            return 22459;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22460;
                        case Properties::Waterlogged::FALSE:
                            return 22461;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22462;
                        case Properties::Waterlogged::FALSE:
                            return 22463;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22464;
                        case Properties::Waterlogged::FALSE:
                            return 22465;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22466;
                        case Properties::Waterlogged::FALSE:
                            return 22467;
                        }
                    }
                }
            }
            return 0;
        }
    }

}
