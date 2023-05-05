#include "WarpedTrapdoor.hpp"
namespace Blocks {
    namespace WarpedTrapdoor {
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Open open, Properties::Powered powered, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (half) {
                case Properties::Half::TOP:
                    switch (open) {
                    case Properties::Open::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18184;
                            case Properties::Waterlogged::FALSE:
                                return 18185;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18186;
                            case Properties::Waterlogged::FALSE:
                                return 18187;
                            }
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18188;
                            case Properties::Waterlogged::FALSE:
                                return 18189;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18190;
                            case Properties::Waterlogged::FALSE:
                                return 18191;
                            }
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (open) {
                    case Properties::Open::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18192;
                            case Properties::Waterlogged::FALSE:
                                return 18193;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18194;
                            case Properties::Waterlogged::FALSE:
                                return 18195;
                            }
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18196;
                            case Properties::Waterlogged::FALSE:
                                return 18197;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18198;
                            case Properties::Waterlogged::FALSE:
                                return 18199;
                            }
                        }
                    }
                }
            case Properties::Facing::SOUTH:
                switch (half) {
                case Properties::Half::TOP:
                    switch (open) {
                    case Properties::Open::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18200;
                            case Properties::Waterlogged::FALSE:
                                return 18201;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18202;
                            case Properties::Waterlogged::FALSE:
                                return 18203;
                            }
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18204;
                            case Properties::Waterlogged::FALSE:
                                return 18205;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18206;
                            case Properties::Waterlogged::FALSE:
                                return 18207;
                            }
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (open) {
                    case Properties::Open::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18208;
                            case Properties::Waterlogged::FALSE:
                                return 18209;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18210;
                            case Properties::Waterlogged::FALSE:
                                return 18211;
                            }
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18212;
                            case Properties::Waterlogged::FALSE:
                                return 18213;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18214;
                            case Properties::Waterlogged::FALSE:
                                return 18215;
                            }
                        }
                    }
                }
            case Properties::Facing::WEST:
                switch (half) {
                case Properties::Half::TOP:
                    switch (open) {
                    case Properties::Open::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18216;
                            case Properties::Waterlogged::FALSE:
                                return 18217;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18218;
                            case Properties::Waterlogged::FALSE:
                                return 18219;
                            }
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18220;
                            case Properties::Waterlogged::FALSE:
                                return 18221;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18222;
                            case Properties::Waterlogged::FALSE:
                                return 18223;
                            }
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (open) {
                    case Properties::Open::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18224;
                            case Properties::Waterlogged::FALSE:
                                return 18225;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18226;
                            case Properties::Waterlogged::FALSE:
                                return 18227;
                            }
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18228;
                            case Properties::Waterlogged::FALSE:
                                return 18229;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18230;
                            case Properties::Waterlogged::FALSE:
                                return 18231;
                            }
                        }
                    }
                }
            case Properties::Facing::EAST:
                switch (half) {
                case Properties::Half::TOP:
                    switch (open) {
                    case Properties::Open::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18232;
                            case Properties::Waterlogged::FALSE:
                                return 18233;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18234;
                            case Properties::Waterlogged::FALSE:
                                return 18235;
                            }
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18236;
                            case Properties::Waterlogged::FALSE:
                                return 18237;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18238;
                            case Properties::Waterlogged::FALSE:
                                return 18239;
                            }
                        }
                    }
                case Properties::Half::BOTTOM:
                    switch (open) {
                    case Properties::Open::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18240;
                            case Properties::Waterlogged::FALSE:
                                return 18241;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18242;
                            case Properties::Waterlogged::FALSE:
                                return 18243;
                            }
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18244;
                            case Properties::Waterlogged::FALSE:
                                return 18245;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 18246;
                            case Properties::Waterlogged::FALSE:
                                return 18247;
                            }
                        }
                    }
                }
            }
            return 0;
        }
    }

}
