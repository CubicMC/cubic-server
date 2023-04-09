#include "RedNetherBrickStairs.hpp"
#include <stdexcept>

namespace Blocks {
namespace RedNetherBrickStairs {
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
                    return 13214;
                case Properties::Waterlogged::FALSE:
                    return 13215;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13216;
                case Properties::Waterlogged::FALSE:
                    return 13217;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13218;
                case Properties::Waterlogged::FALSE:
                    return 13219;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13220;
                case Properties::Waterlogged::FALSE:
                    return 13221;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13222;
                case Properties::Waterlogged::FALSE:
                    return 13223;
                }
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13224;
                case Properties::Waterlogged::FALSE:
                    return 13225;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13226;
                case Properties::Waterlogged::FALSE:
                    return 13227;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13228;
                case Properties::Waterlogged::FALSE:
                    return 13229;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13230;
                case Properties::Waterlogged::FALSE:
                    return 13231;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13232;
                case Properties::Waterlogged::FALSE:
                    return 13233;
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
                    return 13234;
                case Properties::Waterlogged::FALSE:
                    return 13235;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13236;
                case Properties::Waterlogged::FALSE:
                    return 13237;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13238;
                case Properties::Waterlogged::FALSE:
                    return 13239;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13240;
                case Properties::Waterlogged::FALSE:
                    return 13241;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13242;
                case Properties::Waterlogged::FALSE:
                    return 13243;
                }
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13244;
                case Properties::Waterlogged::FALSE:
                    return 13245;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13246;
                case Properties::Waterlogged::FALSE:
                    return 13247;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13248;
                case Properties::Waterlogged::FALSE:
                    return 13249;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13250;
                case Properties::Waterlogged::FALSE:
                    return 13251;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13252;
                case Properties::Waterlogged::FALSE:
                    return 13253;
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
                    return 13254;
                case Properties::Waterlogged::FALSE:
                    return 13255;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13256;
                case Properties::Waterlogged::FALSE:
                    return 13257;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13258;
                case Properties::Waterlogged::FALSE:
                    return 13259;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13260;
                case Properties::Waterlogged::FALSE:
                    return 13261;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13262;
                case Properties::Waterlogged::FALSE:
                    return 13263;
                }
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13264;
                case Properties::Waterlogged::FALSE:
                    return 13265;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13266;
                case Properties::Waterlogged::FALSE:
                    return 13267;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13268;
                case Properties::Waterlogged::FALSE:
                    return 13269;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13270;
                case Properties::Waterlogged::FALSE:
                    return 13271;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13272;
                case Properties::Waterlogged::FALSE:
                    return 13273;
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
                    return 13274;
                case Properties::Waterlogged::FALSE:
                    return 13275;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13276;
                case Properties::Waterlogged::FALSE:
                    return 13277;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13278;
                case Properties::Waterlogged::FALSE:
                    return 13279;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13280;
                case Properties::Waterlogged::FALSE:
                    return 13281;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13282;
                case Properties::Waterlogged::FALSE:
                    return 13283;
                }
            }
        case Properties::Half::BOTTOM:
            switch (shape) {
            case Properties::Shape::STRAIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13284;
                case Properties::Waterlogged::FALSE:
                    return 13285;
                }
            case Properties::Shape::INNER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13286;
                case Properties::Waterlogged::FALSE:
                    return 13287;
                }
            case Properties::Shape::INNER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13288;
                case Properties::Waterlogged::FALSE:
                    return 13289;
                }
            case Properties::Shape::OUTER_LEFT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13290;
                case Properties::Waterlogged::FALSE:
                    return 13291;
                }
            case Properties::Shape::OUTER_RIGHT:
                switch (waterlogged) {
                case Properties::Waterlogged::TRUE:
                    return 13292;
                case Properties::Waterlogged::FALSE:
                    return 13293;
                }
            }
        }
    }
    return 0;
}
}

}
