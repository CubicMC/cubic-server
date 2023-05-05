#include "RedMushroomBlock.hpp"
namespace Blocks {
    namespace RedMushroomBlock {
        BlockId toProtocol(Properties::Down down, Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::West west) {
            switch (down) {
            case Properties::Down::TRUE:
                switch (east) {
                case Properties::East::TRUE:
                    switch (north) {
                    case Properties::North::TRUE:
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6384;
                                case Properties::West::FALSE:
                                    return 6385;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6386;
                                case Properties::West::FALSE:
                                    return 6387;
                                }
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6388;
                                case Properties::West::FALSE:
                                    return 6389;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6390;
                                case Properties::West::FALSE:
                                    return 6391;
                                }
                            }
                        }
                    case Properties::North::FALSE:
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6392;
                                case Properties::West::FALSE:
                                    return 6393;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6394;
                                case Properties::West::FALSE:
                                    return 6395;
                                }
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6396;
                                case Properties::West::FALSE:
                                    return 6397;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6398;
                                case Properties::West::FALSE:
                                    return 6399;
                                }
                            }
                        }
                    }
                case Properties::East::FALSE:
                    switch (north) {
                    case Properties::North::TRUE:
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6400;
                                case Properties::West::FALSE:
                                    return 6401;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6402;
                                case Properties::West::FALSE:
                                    return 6403;
                                }
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6404;
                                case Properties::West::FALSE:
                                    return 6405;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6406;
                                case Properties::West::FALSE:
                                    return 6407;
                                }
                            }
                        }
                    case Properties::North::FALSE:
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6408;
                                case Properties::West::FALSE:
                                    return 6409;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6410;
                                case Properties::West::FALSE:
                                    return 6411;
                                }
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6412;
                                case Properties::West::FALSE:
                                    return 6413;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6414;
                                case Properties::West::FALSE:
                                    return 6415;
                                }
                            }
                        }
                    }
                }
            case Properties::Down::FALSE:
                switch (east) {
                case Properties::East::TRUE:
                    switch (north) {
                    case Properties::North::TRUE:
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6416;
                                case Properties::West::FALSE:
                                    return 6417;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6418;
                                case Properties::West::FALSE:
                                    return 6419;
                                }
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6420;
                                case Properties::West::FALSE:
                                    return 6421;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6422;
                                case Properties::West::FALSE:
                                    return 6423;
                                }
                            }
                        }
                    case Properties::North::FALSE:
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6424;
                                case Properties::West::FALSE:
                                    return 6425;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6426;
                                case Properties::West::FALSE:
                                    return 6427;
                                }
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6428;
                                case Properties::West::FALSE:
                                    return 6429;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6430;
                                case Properties::West::FALSE:
                                    return 6431;
                                }
                            }
                        }
                    }
                case Properties::East::FALSE:
                    switch (north) {
                    case Properties::North::TRUE:
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6432;
                                case Properties::West::FALSE:
                                    return 6433;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6434;
                                case Properties::West::FALSE:
                                    return 6435;
                                }
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6436;
                                case Properties::West::FALSE:
                                    return 6437;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6438;
                                case Properties::West::FALSE:
                                    return 6439;
                                }
                            }
                        }
                    case Properties::North::FALSE:
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6440;
                                case Properties::West::FALSE:
                                    return 6441;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6442;
                                case Properties::West::FALSE:
                                    return 6443;
                                }
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6444;
                                case Properties::West::FALSE:
                                    return 6445;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 6446;
                                case Properties::West::FALSE:
                                    return 6447;
                                }
                            }
                        }
                    }
                }
            }
            return 0;
        }
    }

}
