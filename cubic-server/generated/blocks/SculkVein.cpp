#include "SculkVein.hpp"
#include <stdexcept>

namespace Blocks {
    namespace SculkVein {
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
                                        return 18770;
                                    case Properties::West::FALSE:
                                        return 18771;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18772;
                                    case Properties::West::FALSE:
                                        return 18773;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18774;
                                    case Properties::West::FALSE:
                                        return 18775;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18776;
                                    case Properties::West::FALSE:
                                        return 18777;
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
                                        return 18778;
                                    case Properties::West::FALSE:
                                        return 18779;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18780;
                                    case Properties::West::FALSE:
                                        return 18781;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18782;
                                    case Properties::West::FALSE:
                                        return 18783;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18784;
                                    case Properties::West::FALSE:
                                        return 18785;
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
                                        return 18786;
                                    case Properties::West::FALSE:
                                        return 18787;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18788;
                                    case Properties::West::FALSE:
                                        return 18789;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18790;
                                    case Properties::West::FALSE:
                                        return 18791;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18792;
                                    case Properties::West::FALSE:
                                        return 18793;
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
                                        return 18794;
                                    case Properties::West::FALSE:
                                        return 18795;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18796;
                                    case Properties::West::FALSE:
                                        return 18797;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18798;
                                    case Properties::West::FALSE:
                                        return 18799;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18800;
                                    case Properties::West::FALSE:
                                        return 18801;
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
                                        return 18802;
                                    case Properties::West::FALSE:
                                        return 18803;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18804;
                                    case Properties::West::FALSE:
                                        return 18805;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18806;
                                    case Properties::West::FALSE:
                                        return 18807;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18808;
                                    case Properties::West::FALSE:
                                        return 18809;
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
                                        return 18810;
                                    case Properties::West::FALSE:
                                        return 18811;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18812;
                                    case Properties::West::FALSE:
                                        return 18813;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18814;
                                    case Properties::West::FALSE:
                                        return 18815;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18816;
                                    case Properties::West::FALSE:
                                        return 18817;
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
                                        return 18818;
                                    case Properties::West::FALSE:
                                        return 18819;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18820;
                                    case Properties::West::FALSE:
                                        return 18821;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18822;
                                    case Properties::West::FALSE:
                                        return 18823;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18824;
                                    case Properties::West::FALSE:
                                        return 18825;
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
                                        return 18826;
                                    case Properties::West::FALSE:
                                        return 18827;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18828;
                                    case Properties::West::FALSE:
                                        return 18829;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18830;
                                    case Properties::West::FALSE:
                                        return 18831;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18832;
                                    case Properties::West::FALSE:
                                        return 18833;
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
                                        return 18834;
                                    case Properties::West::FALSE:
                                        return 18835;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18836;
                                    case Properties::West::FALSE:
                                        return 18837;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18838;
                                    case Properties::West::FALSE:
                                        return 18839;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18840;
                                    case Properties::West::FALSE:
                                        return 18841;
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
                                        return 18842;
                                    case Properties::West::FALSE:
                                        return 18843;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18844;
                                    case Properties::West::FALSE:
                                        return 18845;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18846;
                                    case Properties::West::FALSE:
                                        return 18847;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18848;
                                    case Properties::West::FALSE:
                                        return 18849;
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
                                        return 18850;
                                    case Properties::West::FALSE:
                                        return 18851;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18852;
                                    case Properties::West::FALSE:
                                        return 18853;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18854;
                                    case Properties::West::FALSE:
                                        return 18855;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18856;
                                    case Properties::West::FALSE:
                                        return 18857;
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
                                        return 18858;
                                    case Properties::West::FALSE:
                                        return 18859;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18860;
                                    case Properties::West::FALSE:
                                        return 18861;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18862;
                                    case Properties::West::FALSE:
                                        return 18863;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18864;
                                    case Properties::West::FALSE:
                                        return 18865;
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
                                        return 18866;
                                    case Properties::West::FALSE:
                                        return 18867;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18868;
                                    case Properties::West::FALSE:
                                        return 18869;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18870;
                                    case Properties::West::FALSE:
                                        return 18871;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18872;
                                    case Properties::West::FALSE:
                                        return 18873;
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
                                        return 18874;
                                    case Properties::West::FALSE:
                                        return 18875;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18876;
                                    case Properties::West::FALSE:
                                        return 18877;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18878;
                                    case Properties::West::FALSE:
                                        return 18879;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18880;
                                    case Properties::West::FALSE:
                                        return 18881;
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
                                        return 18882;
                                    case Properties::West::FALSE:
                                        return 18883;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18884;
                                    case Properties::West::FALSE:
                                        return 18885;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18886;
                                    case Properties::West::FALSE:
                                        return 18887;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18888;
                                    case Properties::West::FALSE:
                                        return 18889;
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
                                        return 18890;
                                    case Properties::West::FALSE:
                                        return 18891;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18892;
                                    case Properties::West::FALSE:
                                        return 18893;
                                    }
                                }
                            case Properties::Up::FALSE:
                                switch (waterlogged) {
                                case Properties::Waterlogged::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18894;
                                    case Properties::West::FALSE:
                                        return 18895;
                                    }
                                case Properties::Waterlogged::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 18896;
                                    case Properties::West::FALSE:
                                        return 18897;
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
