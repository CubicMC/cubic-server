#include "PolishedDeepslateStairs.hpp"
#include <stdexcept>

namespace Blocks {
    namespace PolishedDeepslateStairs {
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (half) {
                case Properties::Half::TOP:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21977;
                        case Properties::Waterlogged::FALSE:
                            return 21978;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21979;
                        case Properties::Waterlogged::FALSE:
                            return 21980;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21981;
                        case Properties::Waterlogged::FALSE:
                            return 21982;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21983;
                        case Properties::Waterlogged::FALSE:
                            return 21984;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21985;
                        case Properties::Waterlogged::FALSE:
                            return 21986;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21987;
                        case Properties::Waterlogged::FALSE:
                            return 21988;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21989;
                        case Properties::Waterlogged::FALSE:
                            return 21990;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21991;
                        case Properties::Waterlogged::FALSE:
                            return 21992;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21993;
                        case Properties::Waterlogged::FALSE:
                            return 21994;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21995;
                        case Properties::Waterlogged::FALSE:
                            return 21996;
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
                            return 21997;
                        case Properties::Waterlogged::FALSE:
                            return 21998;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21999;
                        case Properties::Waterlogged::FALSE:
                            return 22000;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22001;
                        case Properties::Waterlogged::FALSE:
                            return 22002;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22003;
                        case Properties::Waterlogged::FALSE:
                            return 22004;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22005;
                        case Properties::Waterlogged::FALSE:
                            return 22006;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22007;
                        case Properties::Waterlogged::FALSE:
                            return 22008;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22009;
                        case Properties::Waterlogged::FALSE:
                            return 22010;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22011;
                        case Properties::Waterlogged::FALSE:
                            return 22012;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22013;
                        case Properties::Waterlogged::FALSE:
                            return 22014;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22015;
                        case Properties::Waterlogged::FALSE:
                            return 22016;
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
                            return 22017;
                        case Properties::Waterlogged::FALSE:
                            return 22018;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22019;
                        case Properties::Waterlogged::FALSE:
                            return 22020;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22021;
                        case Properties::Waterlogged::FALSE:
                            return 22022;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22023;
                        case Properties::Waterlogged::FALSE:
                            return 22024;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22025;
                        case Properties::Waterlogged::FALSE:
                            return 22026;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22027;
                        case Properties::Waterlogged::FALSE:
                            return 22028;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22029;
                        case Properties::Waterlogged::FALSE:
                            return 22030;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22031;
                        case Properties::Waterlogged::FALSE:
                            return 22032;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22033;
                        case Properties::Waterlogged::FALSE:
                            return 22034;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22035;
                        case Properties::Waterlogged::FALSE:
                            return 22036;
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
                            return 22037;
                        case Properties::Waterlogged::FALSE:
                            return 22038;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22039;
                        case Properties::Waterlogged::FALSE:
                            return 22040;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22041;
                        case Properties::Waterlogged::FALSE:
                            return 22042;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22043;
                        case Properties::Waterlogged::FALSE:
                            return 22044;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22045;
                        case Properties::Waterlogged::FALSE:
                            return 22046;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22047;
                        case Properties::Waterlogged::FALSE:
                            return 22048;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22049;
                        case Properties::Waterlogged::FALSE:
                            return 22050;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22051;
                        case Properties::Waterlogged::FALSE:
                            return 22052;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22053;
                        case Properties::Waterlogged::FALSE:
                            return 22054;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 22055;
                        case Properties::Waterlogged::FALSE:
                            return 22056;
                        }
                    }
                }
            }
            return 0;
        }
    }

}
