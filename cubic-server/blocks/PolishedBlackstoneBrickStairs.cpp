#include "PolishedBlackstoneBrickStairs.hpp"
#include <stdexcept>

namespace Blocks {
    namespace PolishedBlackstoneBrickStairs {
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Shape shape, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (half) {
                case Properties::Half::TOP:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19253;
                        case Properties::Waterlogged::FALSE:
                            return 19254;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19255;
                        case Properties::Waterlogged::FALSE:
                            return 19256;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19257;
                        case Properties::Waterlogged::FALSE:
                            return 19258;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19259;
                        case Properties::Waterlogged::FALSE:
                            return 19260;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19261;
                        case Properties::Waterlogged::FALSE:
                            return 19262;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19263;
                        case Properties::Waterlogged::FALSE:
                            return 19264;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19265;
                        case Properties::Waterlogged::FALSE:
                            return 19266;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19267;
                        case Properties::Waterlogged::FALSE:
                            return 19268;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19269;
                        case Properties::Waterlogged::FALSE:
                            return 19270;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19271;
                        case Properties::Waterlogged::FALSE:
                            return 19272;
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
                            return 19273;
                        case Properties::Waterlogged::FALSE:
                            return 19274;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19275;
                        case Properties::Waterlogged::FALSE:
                            return 19276;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19277;
                        case Properties::Waterlogged::FALSE:
                            return 19278;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19279;
                        case Properties::Waterlogged::FALSE:
                            return 19280;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19281;
                        case Properties::Waterlogged::FALSE:
                            return 19282;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19283;
                        case Properties::Waterlogged::FALSE:
                            return 19284;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19285;
                        case Properties::Waterlogged::FALSE:
                            return 19286;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19287;
                        case Properties::Waterlogged::FALSE:
                            return 19288;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19289;
                        case Properties::Waterlogged::FALSE:
                            return 19290;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19291;
                        case Properties::Waterlogged::FALSE:
                            return 19292;
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
                            return 19293;
                        case Properties::Waterlogged::FALSE:
                            return 19294;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19295;
                        case Properties::Waterlogged::FALSE:
                            return 19296;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19297;
                        case Properties::Waterlogged::FALSE:
                            return 19298;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19299;
                        case Properties::Waterlogged::FALSE:
                            return 19300;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19301;
                        case Properties::Waterlogged::FALSE:
                            return 19302;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19303;
                        case Properties::Waterlogged::FALSE:
                            return 19304;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19305;
                        case Properties::Waterlogged::FALSE:
                            return 19306;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19307;
                        case Properties::Waterlogged::FALSE:
                            return 19308;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19309;
                        case Properties::Waterlogged::FALSE:
                            return 19310;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19311;
                        case Properties::Waterlogged::FALSE:
                            return 19312;
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
                            return 19313;
                        case Properties::Waterlogged::FALSE:
                            return 19314;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19315;
                        case Properties::Waterlogged::FALSE:
                            return 19316;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19317;
                        case Properties::Waterlogged::FALSE:
                            return 19318;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19319;
                        case Properties::Waterlogged::FALSE:
                            return 19320;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19321;
                        case Properties::Waterlogged::FALSE:
                            return 19322;
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (shape) {
                    case Properties::Shape::STRAIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19323;
                        case Properties::Waterlogged::FALSE:
                            return 19324;
                        }
                    case Properties::Shape::INNER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19325;
                        case Properties::Waterlogged::FALSE:
                            return 19326;
                        }
                    case Properties::Shape::INNER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19327;
                        case Properties::Waterlogged::FALSE:
                            return 19328;
                        }
                    case Properties::Shape::OUTER_LEFT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19329;
                        case Properties::Waterlogged::FALSE:
                            return 19330;
                        }
                    case Properties::Shape::OUTER_RIGHT:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            return 19331;
                        case Properties::Waterlogged::FALSE:
                            return 19332;
                        }
                    }
                }
            }
            return 0;
        }
    }

}
