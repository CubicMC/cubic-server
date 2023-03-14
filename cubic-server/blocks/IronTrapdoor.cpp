#include "IronTrapdoor.hpp"
#include <stdexcept>

namespace Blocks {
    namespace IronTrapdoor {
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
                                return 9922;
                            case Properties::Waterlogged::FALSE:
                                return 9923;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 9924;
                            case Properties::Waterlogged::FALSE:
                                return 9925;
                            }
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 9926;
                            case Properties::Waterlogged::FALSE:
                                return 9927;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 9928;
                            case Properties::Waterlogged::FALSE:
                                return 9929;
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
                                return 9930;
                            case Properties::Waterlogged::FALSE:
                                return 9931;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 9932;
                            case Properties::Waterlogged::FALSE:
                                return 9933;
                            }
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 9934;
                            case Properties::Waterlogged::FALSE:
                                return 9935;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 9936;
                            case Properties::Waterlogged::FALSE:
                                return 9937;
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
                                return 9938;
                            case Properties::Waterlogged::FALSE:
                                return 9939;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 9940;
                            case Properties::Waterlogged::FALSE:
                                return 9941;
                            }
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 9942;
                            case Properties::Waterlogged::FALSE:
                                return 9943;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 9944;
                            case Properties::Waterlogged::FALSE:
                                return 9945;
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
                                return 9946;
                            case Properties::Waterlogged::FALSE:
                                return 9947;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 9948;
                            case Properties::Waterlogged::FALSE:
                                return 9949;
                            }
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 9950;
                            case Properties::Waterlogged::FALSE:
                                return 9951;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 9952;
                            case Properties::Waterlogged::FALSE:
                                return 9953;
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
                                return 9954;
                            case Properties::Waterlogged::FALSE:
                                return 9955;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 9956;
                            case Properties::Waterlogged::FALSE:
                                return 9957;
                            }
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 9958;
                            case Properties::Waterlogged::FALSE:
                                return 9959;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 9960;
                            case Properties::Waterlogged::FALSE:
                                return 9961;
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
                                return 9962;
                            case Properties::Waterlogged::FALSE:
                                return 9963;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 9964;
                            case Properties::Waterlogged::FALSE:
                                return 9965;
                            }
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 9966;
                            case Properties::Waterlogged::FALSE:
                                return 9967;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 9968;
                            case Properties::Waterlogged::FALSE:
                                return 9969;
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
                                return 9970;
                            case Properties::Waterlogged::FALSE:
                                return 9971;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 9972;
                            case Properties::Waterlogged::FALSE:
                                return 9973;
                            }
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 9974;
                            case Properties::Waterlogged::FALSE:
                                return 9975;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 9976;
                            case Properties::Waterlogged::FALSE:
                                return 9977;
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
                                return 9978;
                            case Properties::Waterlogged::FALSE:
                                return 9979;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 9980;
                            case Properties::Waterlogged::FALSE:
                                return 9981;
                            }
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 9982;
                            case Properties::Waterlogged::FALSE:
                                return 9983;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 9984;
                            case Properties::Waterlogged::FALSE:
                                return 9985;
                            }
                        }
                    }
                }
            }
            return 0;
        }
    }

}
