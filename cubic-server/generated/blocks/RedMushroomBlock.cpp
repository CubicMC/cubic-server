#include "RedMushroomBlock.hpp"
#include <stdexcept>

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
                                    return 4944;
                                case Properties::West::FALSE:
                                    return 4945;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 4946;
                                case Properties::West::FALSE:
                                    return 4947;
                                }
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 4948;
                                case Properties::West::FALSE:
                                    return 4949;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 4950;
                                case Properties::West::FALSE:
                                    return 4951;
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
                                    return 4952;
                                case Properties::West::FALSE:
                                    return 4953;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 4954;
                                case Properties::West::FALSE:
                                    return 4955;
                                }
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 4956;
                                case Properties::West::FALSE:
                                    return 4957;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 4958;
                                case Properties::West::FALSE:
                                    return 4959;
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
                                    return 4960;
                                case Properties::West::FALSE:
                                    return 4961;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 4962;
                                case Properties::West::FALSE:
                                    return 4963;
                                }
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 4964;
                                case Properties::West::FALSE:
                                    return 4965;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 4966;
                                case Properties::West::FALSE:
                                    return 4967;
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
                                    return 4968;
                                case Properties::West::FALSE:
                                    return 4969;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 4970;
                                case Properties::West::FALSE:
                                    return 4971;
                                }
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 4972;
                                case Properties::West::FALSE:
                                    return 4973;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 4974;
                                case Properties::West::FALSE:
                                    return 4975;
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
                                    return 4976;
                                case Properties::West::FALSE:
                                    return 4977;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 4978;
                                case Properties::West::FALSE:
                                    return 4979;
                                }
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 4980;
                                case Properties::West::FALSE:
                                    return 4981;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 4982;
                                case Properties::West::FALSE:
                                    return 4983;
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
                                    return 4984;
                                case Properties::West::FALSE:
                                    return 4985;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 4986;
                                case Properties::West::FALSE:
                                    return 4987;
                                }
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 4988;
                                case Properties::West::FALSE:
                                    return 4989;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 4990;
                                case Properties::West::FALSE:
                                    return 4991;
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
                                    return 4992;
                                case Properties::West::FALSE:
                                    return 4993;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 4994;
                                case Properties::West::FALSE:
                                    return 4995;
                                }
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 4996;
                                case Properties::West::FALSE:
                                    return 4997;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 4998;
                                case Properties::West::FALSE:
                                    return 4999;
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
                                    return 5000;
                                case Properties::West::FALSE:
                                    return 5001;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 5002;
                                case Properties::West::FALSE:
                                    return 5003;
                                }
                            }
                        case Properties::South::FALSE:
                            switch (up) {
                            case Properties::Up::TRUE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 5004;
                                case Properties::West::FALSE:
                                    return 5005;
                                }
                            case Properties::Up::FALSE:
                                switch (west) {
                                case Properties::West::TRUE:
                                    return 5006;
                                case Properties::West::FALSE:
                                    return 5007;
                                }
                            }
                        }
                    }
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 6)
            throw std::runtime_error("Invalid number of properties");
            Properties::Down down;
            Properties::East east;
            Properties::North north;
            Properties::South south;
            Properties::Up up;
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
            return toProtocol(down, east, north, south, up, west);
        }
    }

}
