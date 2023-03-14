#include "SmoothRedSandstoneStairs.hpp"
#include <stdexcept>

namespace Blocks {
    namespace SmoothRedSandstoneStairs {
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (half) {
                case Properties::Half::TOP:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12414;
                        case Properties::Waterlogged::FALSE:
                            return 12415;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12416;
                        case Properties::Waterlogged::FALSE:
                            return 12417;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12418;
                        case Properties::Waterlogged::FALSE:
                            return 12419;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12420;
                        case Properties::Waterlogged::FALSE:
                            return 12421;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12422;
                        case Properties::Waterlogged::FALSE:
                            return 12423;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12424;
                        case Properties::Waterlogged::FALSE:
                            return 12425;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12426;
                        case Properties::Waterlogged::FALSE:
                            return 12427;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12428;
                        case Properties::Waterlogged::FALSE:
                            return 12429;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12430;
                        case Properties::Waterlogged::FALSE:
                            return 12431;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12432;
                        case Properties::Waterlogged::FALSE:
                            return 12433;
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
                            return 12434;
                        case Properties::Waterlogged::FALSE:
                            return 12435;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12436;
                        case Properties::Waterlogged::FALSE:
                            return 12437;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12438;
                        case Properties::Waterlogged::FALSE:
                            return 12439;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12440;
                        case Properties::Waterlogged::FALSE:
                            return 12441;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12442;
                        case Properties::Waterlogged::FALSE:
                            return 12443;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12444;
                        case Properties::Waterlogged::FALSE:
                            return 12445;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12446;
                        case Properties::Waterlogged::FALSE:
                            return 12447;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12448;
                        case Properties::Waterlogged::FALSE:
                            return 12449;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12450;
                        case Properties::Waterlogged::FALSE:
                            return 12451;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12452;
                        case Properties::Waterlogged::FALSE:
                            return 12453;
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
                            return 12454;
                        case Properties::Waterlogged::FALSE:
                            return 12455;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12456;
                        case Properties::Waterlogged::FALSE:
                            return 12457;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12458;
                        case Properties::Waterlogged::FALSE:
                            return 12459;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12460;
                        case Properties::Waterlogged::FALSE:
                            return 12461;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12462;
                        case Properties::Waterlogged::FALSE:
                            return 12463;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12464;
                        case Properties::Waterlogged::FALSE:
                            return 12465;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12466;
                        case Properties::Waterlogged::FALSE:
                            return 12467;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12468;
                        case Properties::Waterlogged::FALSE:
                            return 12469;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12470;
                        case Properties::Waterlogged::FALSE:
                            return 12471;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12472;
                        case Properties::Waterlogged::FALSE:
                            return 12473;
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
                            return 12474;
                        case Properties::Waterlogged::FALSE:
                            return 12475;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12476;
                        case Properties::Waterlogged::FALSE:
                            return 12477;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12478;
                        case Properties::Waterlogged::FALSE:
                            return 12479;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12480;
                        case Properties::Waterlogged::FALSE:
                            return 12481;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12482;
                        case Properties::Waterlogged::FALSE:
                            return 12483;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12484;
                        case Properties::Waterlogged::FALSE:
                            return 12485;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12486;
                        case Properties::Waterlogged::FALSE:
                            return 12487;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12488;
                        case Properties::Waterlogged::FALSE:
                            return 12489;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12490;
                        case Properties::Waterlogged::FALSE:
                            return 12491;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12492;
                        case Properties::Waterlogged::FALSE:
                            return 12493;
                        }
                    }
                }
            }
            return 0;
        }
    }

}
