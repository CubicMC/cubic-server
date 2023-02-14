#include "Tripwire.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Tripwire {
        BlockId toProtocol(Properties::Attached attached, Properties::Disarmed disarmed, Properties::East east, Properties::North north, Properties::Powered powered, Properties::South south, Properties::West west) {
            switch (attached) {
            case Properties::Attached::TRUE:
                switch (disarmed) {
                case Properties::Disarmed::TRUE:
                    switch (east) {
                    case Properties::East::TRUE:
                        switch (north) {
                        case Properties::North::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5867;
                                    case Properties::West::FALSE:
                                        return 5868;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5869;
                                    case Properties::West::FALSE:
                                        return 5870;
                                    }
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5871;
                                    case Properties::West::FALSE:
                                        return 5872;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5873;
                                    case Properties::West::FALSE:
                                        return 5874;
                                    }
                                }
                            }
                        case Properties::North::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5875;
                                    case Properties::West::FALSE:
                                        return 5876;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5877;
                                    case Properties::West::FALSE:
                                        return 5878;
                                    }
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5879;
                                    case Properties::West::FALSE:
                                        return 5880;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5881;
                                    case Properties::West::FALSE:
                                        return 5882;
                                    }
                                }
                            }
                        }
                    case Properties::East::FALSE:
                        switch (north) {
                        case Properties::North::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5883;
                                    case Properties::West::FALSE:
                                        return 5884;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5885;
                                    case Properties::West::FALSE:
                                        return 5886;
                                    }
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5887;
                                    case Properties::West::FALSE:
                                        return 5888;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5889;
                                    case Properties::West::FALSE:
                                        return 5890;
                                    }
                                }
                            }
                        case Properties::North::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5891;
                                    case Properties::West::FALSE:
                                        return 5892;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5893;
                                    case Properties::West::FALSE:
                                        return 5894;
                                    }
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5895;
                                    case Properties::West::FALSE:
                                        return 5896;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5897;
                                    case Properties::West::FALSE:
                                        return 5898;
                                    }
                                }
                            }
                        }
                    }
                case Properties::Disarmed::FALSE:
                    switch (east) {
                    case Properties::East::TRUE:
                        switch (north) {
                        case Properties::North::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5899;
                                    case Properties::West::FALSE:
                                        return 5900;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5901;
                                    case Properties::West::FALSE:
                                        return 5902;
                                    }
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5903;
                                    case Properties::West::FALSE:
                                        return 5904;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5905;
                                    case Properties::West::FALSE:
                                        return 5906;
                                    }
                                }
                            }
                        case Properties::North::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5907;
                                    case Properties::West::FALSE:
                                        return 5908;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5909;
                                    case Properties::West::FALSE:
                                        return 5910;
                                    }
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5911;
                                    case Properties::West::FALSE:
                                        return 5912;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5913;
                                    case Properties::West::FALSE:
                                        return 5914;
                                    }
                                }
                            }
                        }
                    case Properties::East::FALSE:
                        switch (north) {
                        case Properties::North::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5915;
                                    case Properties::West::FALSE:
                                        return 5916;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5917;
                                    case Properties::West::FALSE:
                                        return 5918;
                                    }
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5919;
                                    case Properties::West::FALSE:
                                        return 5920;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5921;
                                    case Properties::West::FALSE:
                                        return 5922;
                                    }
                                }
                            }
                        case Properties::North::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5923;
                                    case Properties::West::FALSE:
                                        return 5924;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5925;
                                    case Properties::West::FALSE:
                                        return 5926;
                                    }
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5927;
                                    case Properties::West::FALSE:
                                        return 5928;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5929;
                                    case Properties::West::FALSE:
                                        return 5930;
                                    }
                                }
                            }
                        }
                    }
                }
            case Properties::Attached::FALSE:
                switch (disarmed) {
                case Properties::Disarmed::TRUE:
                    switch (east) {
                    case Properties::East::TRUE:
                        switch (north) {
                        case Properties::North::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5931;
                                    case Properties::West::FALSE:
                                        return 5932;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5933;
                                    case Properties::West::FALSE:
                                        return 5934;
                                    }
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5935;
                                    case Properties::West::FALSE:
                                        return 5936;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5937;
                                    case Properties::West::FALSE:
                                        return 5938;
                                    }
                                }
                            }
                        case Properties::North::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5939;
                                    case Properties::West::FALSE:
                                        return 5940;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5941;
                                    case Properties::West::FALSE:
                                        return 5942;
                                    }
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5943;
                                    case Properties::West::FALSE:
                                        return 5944;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5945;
                                    case Properties::West::FALSE:
                                        return 5946;
                                    }
                                }
                            }
                        }
                    case Properties::East::FALSE:
                        switch (north) {
                        case Properties::North::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5947;
                                    case Properties::West::FALSE:
                                        return 5948;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5949;
                                    case Properties::West::FALSE:
                                        return 5950;
                                    }
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5951;
                                    case Properties::West::FALSE:
                                        return 5952;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5953;
                                    case Properties::West::FALSE:
                                        return 5954;
                                    }
                                }
                            }
                        case Properties::North::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5955;
                                    case Properties::West::FALSE:
                                        return 5956;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5957;
                                    case Properties::West::FALSE:
                                        return 5958;
                                    }
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5959;
                                    case Properties::West::FALSE:
                                        return 5960;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5961;
                                    case Properties::West::FALSE:
                                        return 5962;
                                    }
                                }
                            }
                        }
                    }
                case Properties::Disarmed::FALSE:
                    switch (east) {
                    case Properties::East::TRUE:
                        switch (north) {
                        case Properties::North::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5963;
                                    case Properties::West::FALSE:
                                        return 5964;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5965;
                                    case Properties::West::FALSE:
                                        return 5966;
                                    }
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5967;
                                    case Properties::West::FALSE:
                                        return 5968;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5969;
                                    case Properties::West::FALSE:
                                        return 5970;
                                    }
                                }
                            }
                        case Properties::North::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5971;
                                    case Properties::West::FALSE:
                                        return 5972;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5973;
                                    case Properties::West::FALSE:
                                        return 5974;
                                    }
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5975;
                                    case Properties::West::FALSE:
                                        return 5976;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5977;
                                    case Properties::West::FALSE:
                                        return 5978;
                                    }
                                }
                            }
                        }
                    case Properties::East::FALSE:
                        switch (north) {
                        case Properties::North::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5979;
                                    case Properties::West::FALSE:
                                        return 5980;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5981;
                                    case Properties::West::FALSE:
                                        return 5982;
                                    }
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5983;
                                    case Properties::West::FALSE:
                                        return 5984;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5985;
                                    case Properties::West::FALSE:
                                        return 5986;
                                    }
                                }
                            }
                        case Properties::North::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5987;
                                    case Properties::West::FALSE:
                                        return 5988;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5989;
                                    case Properties::West::FALSE:
                                        return 5990;
                                    }
                                }
                            case Properties::Powered::FALSE:
                                switch (south) {
                                case Properties::South::TRUE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5991;
                                    case Properties::West::FALSE:
                                        return 5992;
                                    }
                                case Properties::South::FALSE:
                                    switch (west) {
                                    case Properties::West::TRUE:
                                        return 5993;
                                    case Properties::West::FALSE:
                                        return 5994;
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
            Properties::Attached attached;
            Properties::Disarmed disarmed;
            Properties::East east;
            Properties::North north;
            Properties::Powered powered;
            Properties::South south;
            Properties::West west;
            for (auto prop : properties) {
                if (prop.first == "attached") {
                    if (prop.second == "true") {
                        attached = Properties::Attached::TRUE;
                    } else if (prop.second == "false") {
                        attached = Properties::Attached::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"attached\" value");
                    }
                } else if (prop.first == "disarmed") {
                    if (prop.second == "true") {
                        disarmed = Properties::Disarmed::TRUE;
                    } else if (prop.second == "false") {
                        disarmed = Properties::Disarmed::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"disarmed\" value");
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
                } else if (prop.first == "powered") {
                    if (prop.second == "true") {
                        powered = Properties::Powered::TRUE;
                    } else if (prop.second == "false") {
                        powered = Properties::Powered::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"powered\" value");
                    }
                } else if (prop.first == "south") {
                    if (prop.second == "true") {
                        south = Properties::South::TRUE;
                    } else if (prop.second == "false") {
                        south = Properties::South::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"south\" value");
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
            return toProtocol(attached, disarmed, east, north, powered, south, west);
        }
    }

}
