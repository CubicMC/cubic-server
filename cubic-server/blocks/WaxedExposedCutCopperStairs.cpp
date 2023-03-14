#include "WaxedExposedCutCopperStairs.hpp"
#include <stdexcept>

namespace Blocks {
    namespace WaxedExposedCutCopperStairs {
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (half) {
                case Properties::Half::TOP:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21214;
                        case Properties::Waterlogged::FALSE:
                            return 21215;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21216;
                        case Properties::Waterlogged::FALSE:
                            return 21217;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21218;
                        case Properties::Waterlogged::FALSE:
                            return 21219;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21220;
                        case Properties::Waterlogged::FALSE:
                            return 21221;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21222;
                        case Properties::Waterlogged::FALSE:
                            return 21223;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21224;
                        case Properties::Waterlogged::FALSE:
                            return 21225;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21226;
                        case Properties::Waterlogged::FALSE:
                            return 21227;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21228;
                        case Properties::Waterlogged::FALSE:
                            return 21229;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21230;
                        case Properties::Waterlogged::FALSE:
                            return 21231;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21232;
                        case Properties::Waterlogged::FALSE:
                            return 21233;
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
                            return 21234;
                        case Properties::Waterlogged::FALSE:
                            return 21235;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21236;
                        case Properties::Waterlogged::FALSE:
                            return 21237;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21238;
                        case Properties::Waterlogged::FALSE:
                            return 21239;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21240;
                        case Properties::Waterlogged::FALSE:
                            return 21241;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21242;
                        case Properties::Waterlogged::FALSE:
                            return 21243;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21244;
                        case Properties::Waterlogged::FALSE:
                            return 21245;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21246;
                        case Properties::Waterlogged::FALSE:
                            return 21247;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21248;
                        case Properties::Waterlogged::FALSE:
                            return 21249;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21250;
                        case Properties::Waterlogged::FALSE:
                            return 21251;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21252;
                        case Properties::Waterlogged::FALSE:
                            return 21253;
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
                            return 21254;
                        case Properties::Waterlogged::FALSE:
                            return 21255;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21256;
                        case Properties::Waterlogged::FALSE:
                            return 21257;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21258;
                        case Properties::Waterlogged::FALSE:
                            return 21259;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21260;
                        case Properties::Waterlogged::FALSE:
                            return 21261;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21262;
                        case Properties::Waterlogged::FALSE:
                            return 21263;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21264;
                        case Properties::Waterlogged::FALSE:
                            return 21265;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21266;
                        case Properties::Waterlogged::FALSE:
                            return 21267;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21268;
                        case Properties::Waterlogged::FALSE:
                            return 21269;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21270;
                        case Properties::Waterlogged::FALSE:
                            return 21271;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21272;
                        case Properties::Waterlogged::FALSE:
                            return 21273;
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
                            return 21274;
                        case Properties::Waterlogged::FALSE:
                            return 21275;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21276;
                        case Properties::Waterlogged::FALSE:
                            return 21277;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21278;
                        case Properties::Waterlogged::FALSE:
                            return 21279;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21280;
                        case Properties::Waterlogged::FALSE:
                            return 21281;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21282;
                        case Properties::Waterlogged::FALSE:
                            return 21283;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21284;
                        case Properties::Waterlogged::FALSE:
                            return 21285;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21286;
                        case Properties::Waterlogged::FALSE:
                            return 21287;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21288;
                        case Properties::Waterlogged::FALSE:
                            return 21289;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21290;
                        case Properties::Waterlogged::FALSE:
                            return 21291;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 21292;
                        case Properties::Waterlogged::FALSE:
                            return 21293;
                        }
                    }
                }
            }
            return 0;
        }
    }

}
