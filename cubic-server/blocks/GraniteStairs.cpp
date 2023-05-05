#include "GraniteStairs.hpp"
namespace Blocks {
    namespace GraniteStairs {
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (half) {
                case Properties::Half::TOP:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13054;
                        case Properties::Waterlogged::FALSE:
                            return 13055;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13056;
                        case Properties::Waterlogged::FALSE:
                            return 13057;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13058;
                        case Properties::Waterlogged::FALSE:
                            return 13059;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13060;
                        case Properties::Waterlogged::FALSE:
                            return 13061;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13062;
                        case Properties::Waterlogged::FALSE:
                            return 13063;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13064;
                        case Properties::Waterlogged::FALSE:
                            return 13065;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13066;
                        case Properties::Waterlogged::FALSE:
                            return 13067;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13068;
                        case Properties::Waterlogged::FALSE:
                            return 13069;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13070;
                        case Properties::Waterlogged::FALSE:
                            return 13071;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13072;
                        case Properties::Waterlogged::FALSE:
                            return 13073;
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
                            return 13074;
                        case Properties::Waterlogged::FALSE:
                            return 13075;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13076;
                        case Properties::Waterlogged::FALSE:
                            return 13077;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13078;
                        case Properties::Waterlogged::FALSE:
                            return 13079;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13080;
                        case Properties::Waterlogged::FALSE:
                            return 13081;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13082;
                        case Properties::Waterlogged::FALSE:
                            return 13083;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13084;
                        case Properties::Waterlogged::FALSE:
                            return 13085;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13086;
                        case Properties::Waterlogged::FALSE:
                            return 13087;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13088;
                        case Properties::Waterlogged::FALSE:
                            return 13089;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13090;
                        case Properties::Waterlogged::FALSE:
                            return 13091;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13092;
                        case Properties::Waterlogged::FALSE:
                            return 13093;
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
                            return 13094;
                        case Properties::Waterlogged::FALSE:
                            return 13095;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13096;
                        case Properties::Waterlogged::FALSE:
                            return 13097;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13098;
                        case Properties::Waterlogged::FALSE:
                            return 13099;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13100;
                        case Properties::Waterlogged::FALSE:
                            return 13101;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13102;
                        case Properties::Waterlogged::FALSE:
                            return 13103;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13104;
                        case Properties::Waterlogged::FALSE:
                            return 13105;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13106;
                        case Properties::Waterlogged::FALSE:
                            return 13107;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13108;
                        case Properties::Waterlogged::FALSE:
                            return 13109;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13110;
                        case Properties::Waterlogged::FALSE:
                            return 13111;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13112;
                        case Properties::Waterlogged::FALSE:
                            return 13113;
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
                            return 13114;
                        case Properties::Waterlogged::FALSE:
                            return 13115;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13116;
                        case Properties::Waterlogged::FALSE:
                            return 13117;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13118;
                        case Properties::Waterlogged::FALSE:
                            return 13119;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13120;
                        case Properties::Waterlogged::FALSE:
                            return 13121;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13122;
                        case Properties::Waterlogged::FALSE:
                            return 13123;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13124;
                        case Properties::Waterlogged::FALSE:
                            return 13125;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13126;
                        case Properties::Waterlogged::FALSE:
                            return 13127;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13128;
                        case Properties::Waterlogged::FALSE:
                            return 13129;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13130;
                        case Properties::Waterlogged::FALSE:
                            return 13131;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13132;
                        case Properties::Waterlogged::FALSE:
                            return 13133;
                        }
                    }
                }
            }
            return 0;
        }
    }

}
