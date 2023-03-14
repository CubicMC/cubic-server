#include "MossyStoneBrickStairs.hpp"
#include <stdexcept>

namespace Blocks {
    namespace MossyStoneBrickStairs {
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (half) {
                case Properties::Half::TOP:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12494;
                        case Properties::Waterlogged::FALSE:
                            return 12495;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12496;
                        case Properties::Waterlogged::FALSE:
                            return 12497;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12498;
                        case Properties::Waterlogged::FALSE:
                            return 12499;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12500;
                        case Properties::Waterlogged::FALSE:
                            return 12501;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12502;
                        case Properties::Waterlogged::FALSE:
                            return 12503;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12504;
                        case Properties::Waterlogged::FALSE:
                            return 12505;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12506;
                        case Properties::Waterlogged::FALSE:
                            return 12507;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12508;
                        case Properties::Waterlogged::FALSE:
                            return 12509;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12510;
                        case Properties::Waterlogged::FALSE:
                            return 12511;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12512;
                        case Properties::Waterlogged::FALSE:
                            return 12513;
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
                            return 12514;
                        case Properties::Waterlogged::FALSE:
                            return 12515;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12516;
                        case Properties::Waterlogged::FALSE:
                            return 12517;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12518;
                        case Properties::Waterlogged::FALSE:
                            return 12519;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12520;
                        case Properties::Waterlogged::FALSE:
                            return 12521;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12522;
                        case Properties::Waterlogged::FALSE:
                            return 12523;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12524;
                        case Properties::Waterlogged::FALSE:
                            return 12525;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12526;
                        case Properties::Waterlogged::FALSE:
                            return 12527;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12528;
                        case Properties::Waterlogged::FALSE:
                            return 12529;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12530;
                        case Properties::Waterlogged::FALSE:
                            return 12531;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12532;
                        case Properties::Waterlogged::FALSE:
                            return 12533;
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
                            return 12534;
                        case Properties::Waterlogged::FALSE:
                            return 12535;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12536;
                        case Properties::Waterlogged::FALSE:
                            return 12537;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12538;
                        case Properties::Waterlogged::FALSE:
                            return 12539;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12540;
                        case Properties::Waterlogged::FALSE:
                            return 12541;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12542;
                        case Properties::Waterlogged::FALSE:
                            return 12543;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12544;
                        case Properties::Waterlogged::FALSE:
                            return 12545;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12546;
                        case Properties::Waterlogged::FALSE:
                            return 12547;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12548;
                        case Properties::Waterlogged::FALSE:
                            return 12549;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12550;
                        case Properties::Waterlogged::FALSE:
                            return 12551;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12552;
                        case Properties::Waterlogged::FALSE:
                            return 12553;
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
                            return 12554;
                        case Properties::Waterlogged::FALSE:
                            return 12555;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12556;
                        case Properties::Waterlogged::FALSE:
                            return 12557;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12558;
                        case Properties::Waterlogged::FALSE:
                            return 12559;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12560;
                        case Properties::Waterlogged::FALSE:
                            return 12561;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12562;
                        case Properties::Waterlogged::FALSE:
                            return 12563;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12564;
                        case Properties::Waterlogged::FALSE:
                            return 12565;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12566;
                        case Properties::Waterlogged::FALSE:
                            return 12567;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12568;
                        case Properties::Waterlogged::FALSE:
                            return 12569;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12570;
                        case Properties::Waterlogged::FALSE:
                            return 12571;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12572;
                        case Properties::Waterlogged::FALSE:
                            return 12573;
                        }
                    }
                }
            }
            return 0;
        }
    }

}
