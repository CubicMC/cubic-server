#include "GlowLichen.hpp"
#include <stdexcept>

namespace Blocks {
    namespace GlowLichen {
        BlockId toProtocol(Properties::Down down, Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west) {
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
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5199;
                                    case Properties::West::FALSE:
                                        return 5200;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5201;
                                    case Properties::West::FALSE:
                                        return 5202;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5203;
                                    case Properties::West::FALSE:
                                        return 5204;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5205;
                                    case Properties::West::FALSE:
                                        return 5206;
                                    }
                                }
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5207;
                                    case Properties::West::FALSE:
                                        return 5208;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5209;
                                    case Properties::West::FALSE:
                                        return 5210;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5211;
                                    case Properties::West::FALSE:
                                        return 5212;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5213;
                                    case Properties::West::FALSE:
                                        return 5214;
                                    }
                                }
                            }
                        }
                    case Properties::North::FALSE:
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5215;
                                    case Properties::West::FALSE:
                                        return 5216;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5217;
                                    case Properties::West::FALSE:
                                        return 5218;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5219;
                                    case Properties::West::FALSE:
                                        return 5220;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5221;
                                    case Properties::West::FALSE:
                                        return 5222;
                                    }
                                }
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5223;
                                    case Properties::West::FALSE:
                                        return 5224;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5225;
                                    case Properties::West::FALSE:
                                        return 5226;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5227;
                                    case Properties::West::FALSE:
                                        return 5228;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5229;
                                    case Properties::West::FALSE:
                                        return 5230;
                                    }
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
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5231;
                                    case Properties::West::FALSE:
                                        return 5232;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5233;
                                    case Properties::West::FALSE:
                                        return 5234;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5235;
                                    case Properties::West::FALSE:
                                        return 5236;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5237;
                                    case Properties::West::FALSE:
                                        return 5238;
                                    }
                                }
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5239;
                                    case Properties::West::FALSE:
                                        return 5240;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5241;
                                    case Properties::West::FALSE:
                                        return 5242;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5243;
                                    case Properties::West::FALSE:
                                        return 5244;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5245;
                                    case Properties::West::FALSE:
                                        return 5246;
                                    }
                                }
                            }
                        }
                    case Properties::North::FALSE:
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5247;
                                    case Properties::West::FALSE:
                                        return 5248;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5249;
                                    case Properties::West::FALSE:
                                        return 5250;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5251;
                                    case Properties::West::FALSE:
                                        return 5252;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5253;
                                    case Properties::West::FALSE:
                                        return 5254;
                                    }
                                }
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5255;
                                    case Properties::West::FALSE:
                                        return 5256;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5257;
                                    case Properties::West::FALSE:
                                        return 5258;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5259;
                                    case Properties::West::FALSE:
                                        return 5260;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5261;
                                    case Properties::West::FALSE:
                                        return 5262;
                                    }
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
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5263;
                                    case Properties::West::FALSE:
                                        return 5264;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5265;
                                    case Properties::West::FALSE:
                                        return 5266;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5267;
                                    case Properties::West::FALSE:
                                        return 5268;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5269;
                                    case Properties::West::FALSE:
                                        return 5270;
                                    }
                                }
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5271;
                                    case Properties::West::FALSE:
                                        return 5272;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5273;
                                    case Properties::West::FALSE:
                                        return 5274;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5275;
                                    case Properties::West::FALSE:
                                        return 5276;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5277;
                                    case Properties::West::FALSE:
                                        return 5278;
                                    }
                                }
                            }
                        }
                    case Properties::North::FALSE:
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5279;
                                    case Properties::West::FALSE:
                                        return 5280;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5281;
                                    case Properties::West::FALSE:
                                        return 5282;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5283;
                                    case Properties::West::FALSE:
                                        return 5284;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5285;
                                    case Properties::West::FALSE:
                                        return 5286;
                                    }
                                }
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5287;
                                    case Properties::West::FALSE:
                                        return 5288;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5289;
                                    case Properties::West::FALSE:
                                        return 5290;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5291;
                                    case Properties::West::FALSE:
                                        return 5292;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5293;
                                    case Properties::West::FALSE:
                                        return 5294;
                                    }
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
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5295;
                                    case Properties::West::FALSE:
                                        return 5296;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5297;
                                    case Properties::West::FALSE:
                                        return 5298;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5299;
                                    case Properties::West::FALSE:
                                        return 5300;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5301;
                                    case Properties::West::FALSE:
                                        return 5302;
                                    }
                                }
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5303;
                                    case Properties::West::FALSE:
                                        return 5304;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5305;
                                    case Properties::West::FALSE:
                                        return 5306;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5307;
                                    case Properties::West::FALSE:
                                        return 5308;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5309;
                                    case Properties::West::FALSE:
                                        return 5310;
                                    }
                                }
                            }
                        }
                    case Properties::North::FALSE:
                        switch (south) {
                        case Properties::South::TRUE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5311;
                                    case Properties::West::FALSE:
                                        return 5312;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5313;
                                    case Properties::West::FALSE:
                                        return 5314;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5315;
                                    case Properties::West::FALSE:
                                        return 5316;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5317;
                                    case Properties::West::FALSE:
                                        return 5318;
                                    }
                                }
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5319;
                                    case Properties::West::FALSE:
                                        return 5320;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5321;
                                    case Properties::West::FALSE:
                                        return 5322;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5323;
                                    case Properties::West::FALSE:
                                        return 5324;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5325;
                                    case Properties::West::FALSE:
                                        return 5326;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 7)
            throw std::runtime_error("Invalid number of properties");
            Properties::Down down;
            Properties::East east;
            Properties::North north;
            Properties::South south;
            Properties::Up up;
            Properties::Waterlogged waterlogged;
            Properties::West west;
            for (auto prop : properties) {
                if (prop.first == "down") {
                    if (prop.second == "true") {
                        down = Properties::Down::TRUE;
                    } else if (prop.second == "false") {
                        down = Properties::Down::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"down\" value");
                    }
                } else if (prop.first == "east") {
                    if (prop.second == "true") {
                        east = Properties::East::TRUE;
                    } else if (prop.second == "false") {
                        east = Properties::East::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"east\" value");
                    }
                } else if (prop.first == "north") {
                    if (prop.second == "true") {
                        north = Properties::North::TRUE;
                    } else if (prop.second == "false") {
                        north = Properties::North::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"north\" value");
                    }
                } else if (prop.first == "south") {
                    if (prop.second == "true") {
                        south = Properties::South::TRUE;
                    } else if (prop.second == "false") {
                        south = Properties::South::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"south\" value");
                    }
                } else if (prop.first == "up") {
                    if (prop.second == "true") {
                        up = Properties::Up::TRUE;
                    } else if (prop.second == "false") {
                        up = Properties::Up::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"up\" value");
                    }
                } else if (prop.first == "waterlogged") {
                    if (prop.second == "true") {
                        waterlogged = Properties::Waterlogged::TRUE;
                    } else if (prop.second == "false") {
                        waterlogged = Properties::Waterlogged::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"waterlogged\" value");
                    }
                } else if (prop.first == "west") {
                    if (prop.second == "true") {
                        west = Properties::West::TRUE;
                    } else if (prop.second == "false") {
                        west = Properties::West::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"west\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(down, east, north, south, up, waterlogged, west);
        }
    }

}
