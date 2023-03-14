#include "PolishedAndesiteStairs.hpp"
#include <stdexcept>

namespace Blocks {
    namespace PolishedAndesiteStairs {
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (half) {
                case Properties::Half::TOP:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13294;
                        case Properties::Waterlogged::FALSE:
                            return 13295;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13296;
                        case Properties::Waterlogged::FALSE:
                            return 13297;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13298;
                        case Properties::Waterlogged::FALSE:
                            return 13299;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13300;
                        case Properties::Waterlogged::FALSE:
                            return 13301;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13302;
                        case Properties::Waterlogged::FALSE:
                            return 13303;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13304;
                        case Properties::Waterlogged::FALSE:
                            return 13305;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13306;
                        case Properties::Waterlogged::FALSE:
                            return 13307;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13308;
                        case Properties::Waterlogged::FALSE:
                            return 13309;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13310;
                        case Properties::Waterlogged::FALSE:
                            return 13311;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13312;
                        case Properties::Waterlogged::FALSE:
                            return 13313;
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
                            return 13314;
                        case Properties::Waterlogged::FALSE:
                            return 13315;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13316;
                        case Properties::Waterlogged::FALSE:
                            return 13317;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13318;
                        case Properties::Waterlogged::FALSE:
                            return 13319;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13320;
                        case Properties::Waterlogged::FALSE:
                            return 13321;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13322;
                        case Properties::Waterlogged::FALSE:
                            return 13323;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13324;
                        case Properties::Waterlogged::FALSE:
                            return 13325;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13326;
                        case Properties::Waterlogged::FALSE:
                            return 13327;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13328;
                        case Properties::Waterlogged::FALSE:
                            return 13329;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13330;
                        case Properties::Waterlogged::FALSE:
                            return 13331;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13332;
                        case Properties::Waterlogged::FALSE:
                            return 13333;
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
                            return 13334;
                        case Properties::Waterlogged::FALSE:
                            return 13335;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13336;
                        case Properties::Waterlogged::FALSE:
                            return 13337;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13338;
                        case Properties::Waterlogged::FALSE:
                            return 13339;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13340;
                        case Properties::Waterlogged::FALSE:
                            return 13341;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13342;
                        case Properties::Waterlogged::FALSE:
                            return 13343;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13344;
                        case Properties::Waterlogged::FALSE:
                            return 13345;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13346;
                        case Properties::Waterlogged::FALSE:
                            return 13347;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13348;
                        case Properties::Waterlogged::FALSE:
                            return 13349;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13350;
                        case Properties::Waterlogged::FALSE:
                            return 13351;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13352;
                        case Properties::Waterlogged::FALSE:
                            return 13353;
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
                            return 13354;
                        case Properties::Waterlogged::FALSE:
                            return 13355;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13356;
                        case Properties::Waterlogged::FALSE:
                            return 13357;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13358;
                        case Properties::Waterlogged::FALSE:
                            return 13359;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13360;
                        case Properties::Waterlogged::FALSE:
                            return 13361;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13362;
                        case Properties::Waterlogged::FALSE:
                            return 13363;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13364;
                        case Properties::Waterlogged::FALSE:
                            return 13365;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13366;
                        case Properties::Waterlogged::FALSE:
                            return 13367;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13368;
                        case Properties::Waterlogged::FALSE:
                            return 13369;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13370;
                        case Properties::Waterlogged::FALSE:
                            return 13371;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 13372;
                        case Properties::Waterlogged::FALSE:
                            return 13373;
                        }
                    }
                }
            }
            return 0;
        }
    }

}
