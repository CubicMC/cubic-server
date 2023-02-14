#include "Vine.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Vine {
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::West west) {
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
                                return 5167;
                            case Properties::West::FALSE:
                                return 5168;
                            }
                        case Properties::Up::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 5169;
                            case Properties::West::FALSE:
                                return 5170;
                            }
                        }
                    case Properties::South::FALSE:
                        switch (up) {
                        case Properties::Up::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 5171;
                            case Properties::West::FALSE:
                                return 5172;
                            }
                        case Properties::Up::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 5173;
                            case Properties::West::FALSE:
                                return 5174;
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
                                return 5175;
                            case Properties::West::FALSE:
                                return 5176;
                            }
                        case Properties::Up::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 5177;
                            case Properties::West::FALSE:
                                return 5178;
                            }
                        }
                    case Properties::South::FALSE:
                        switch (up) {
                        case Properties::Up::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 5179;
                            case Properties::West::FALSE:
                                return 5180;
                            }
                        case Properties::Up::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 5181;
                            case Properties::West::FALSE:
                                return 5182;
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
                                return 5183;
                            case Properties::West::FALSE:
                                return 5184;
                            }
                        case Properties::Up::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 5185;
                            case Properties::West::FALSE:
                                return 5186;
                            }
                        }
                    case Properties::South::FALSE:
                        switch (up) {
                        case Properties::Up::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 5187;
                            case Properties::West::FALSE:
                                return 5188;
                            }
                        case Properties::Up::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 5189;
                            case Properties::West::FALSE:
                                return 5190;
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
                                return 5191;
                            case Properties::West::FALSE:
                                return 5192;
                            }
                        case Properties::Up::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 5193;
                            case Properties::West::FALSE:
                                return 5194;
                            }
                        }
                    case Properties::South::FALSE:
                        switch (up) {
                        case Properties::Up::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 5195;
                            case Properties::West::FALSE:
                                return 5196;
                            }
                        case Properties::Up::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 5197;
                            case Properties::West::FALSE:
                                return 5198;
                            }
                        }
                    }
                }
            }
            return 0;
        }
        BlockId paletteToProtocol(std::vector<std::pair<std::string, std::string>> properties) {
            if (properties.size() != 5)
            throw std::runtime_error("Invalid number of properties");
            Properties::East east;
            Properties::North north;
            Properties::South south;
            Properties::Up up;
            Properties::West west;
            for (auto prop : properties) {
                if (prop.first == "east") {
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
            return toProtocol(east, north, south, up, west);
        }
    }

}
