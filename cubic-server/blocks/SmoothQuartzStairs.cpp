#include "SmoothQuartzStairs.hpp"
#include <stdexcept>

namespace Blocks {
    namespace SmoothQuartzStairs {
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (half) {
                case Properties::Half::TOP:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12974;
                        case Properties::Waterlogged::FALSE:
                            return 12975;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12976;
                        case Properties::Waterlogged::FALSE:
                            return 12977;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12978;
                        case Properties::Waterlogged::FALSE:
                            return 12979;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12980;
                        case Properties::Waterlogged::FALSE:
                            return 12981;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12982;
                        case Properties::Waterlogged::FALSE:
                            return 12983;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12984;
                        case Properties::Waterlogged::FALSE:
                            return 12985;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12986;
                        case Properties::Waterlogged::FALSE:
                            return 12987;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12988;
                        case Properties::Waterlogged::FALSE:
                            return 12989;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12990;
                        case Properties::Waterlogged::FALSE:
                            return 12991;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12992;
                        case Properties::Waterlogged::FALSE:
                            return 12993;
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
                            return 12994;
                        case Properties::Waterlogged::FALSE:
                            return 12995;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12996;
                        case Properties::Waterlogged::FALSE:
                            return 12997;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 12998;
                        case Properties::Waterlogged::FALSE:
                            return 12999;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13000;
                        case Properties::Waterlogged::FALSE:
                            return 13001;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13002;
                        case Properties::Waterlogged::FALSE:
                            return 13003;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13004;
                        case Properties::Waterlogged::FALSE:
                            return 13005;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13006;
                        case Properties::Waterlogged::FALSE:
                            return 13007;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13008;
                        case Properties::Waterlogged::FALSE:
                            return 13009;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13010;
                        case Properties::Waterlogged::FALSE:
                            return 13011;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13012;
                        case Properties::Waterlogged::FALSE:
                            return 13013;
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
                            return 13014;
                        case Properties::Waterlogged::FALSE:
                            return 13015;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13016;
                        case Properties::Waterlogged::FALSE:
                            return 13017;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13018;
                        case Properties::Waterlogged::FALSE:
                            return 13019;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13020;
                        case Properties::Waterlogged::FALSE:
                            return 13021;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13022;
                        case Properties::Waterlogged::FALSE:
                            return 13023;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13024;
                        case Properties::Waterlogged::FALSE:
                            return 13025;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13026;
                        case Properties::Waterlogged::FALSE:
                            return 13027;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13028;
                        case Properties::Waterlogged::FALSE:
                            return 13029;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13030;
                        case Properties::Waterlogged::FALSE:
                            return 13031;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13032;
                        case Properties::Waterlogged::FALSE:
                            return 13033;
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
                            return 13034;
                        case Properties::Waterlogged::FALSE:
                            return 13035;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13036;
                        case Properties::Waterlogged::FALSE:
                            return 13037;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13038;
                        case Properties::Waterlogged::FALSE:
                            return 13039;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13040;
                        case Properties::Waterlogged::FALSE:
                            return 13041;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13042;
                        case Properties::Waterlogged::FALSE:
                            return 13043;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13044;
                        case Properties::Waterlogged::FALSE:
                            return 13045;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13046;
                        case Properties::Waterlogged::FALSE:
                            return 13047;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13048;
                        case Properties::Waterlogged::FALSE:
                            return 13049;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13050;
                        case Properties::Waterlogged::FALSE:
                            return 13051;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13052;
                        case Properties::Waterlogged::FALSE:
                            return 13053;
                        }
                    }
                }
            }
            return 0;
        }
    }

}
