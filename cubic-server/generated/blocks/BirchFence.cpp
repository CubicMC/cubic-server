#include "BirchFence.hpp"
#include <stdexcept>

namespace Blocks {
    namespace BirchFence {
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Waterlogged waterlogged, Properties::West west) {
            switch (east) {
            case Properties::East::TRUE:
                switch (north) {
                case Properties::North::TRUE:
                    switch (south) {
                    case Properties::South::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9395;
                            case Properties::West::FALSE:
                                return 9396;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9397;
                            case Properties::West::FALSE:
                                return 9398;
                            }
                        }
                    case Properties::South::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9399;
                            case Properties::West::FALSE:
                                return 9400;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9401;
                            case Properties::West::FALSE:
                                return 9402;
                            }
                        }
                    }
                case Properties::North::FALSE:
                    switch (south) {
                    case Properties::South::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9403;
                            case Properties::West::FALSE:
                                return 9404;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9405;
                            case Properties::West::FALSE:
                                return 9406;
                            }
                        }
                    case Properties::South::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9407;
                            case Properties::West::FALSE:
                                return 9408;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9409;
                            case Properties::West::FALSE:
                                return 9410;
                            }
                        }
                    }
                }
            case Properties::East::FALSE:
                switch (north) {
                case Properties::North::TRUE:
                    switch (south) {
                    case Properties::South::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9411;
                            case Properties::West::FALSE:
                                return 9412;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9413;
                            case Properties::West::FALSE:
                                return 9414;
                            }
                        }
                    case Properties::South::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9415;
                            case Properties::West::FALSE:
                                return 9416;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9417;
                            case Properties::West::FALSE:
                                return 9418;
                            }
                        }
                    }
                case Properties::North::FALSE:
                    switch (south) {
                    case Properties::South::TRUE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9419;
                            case Properties::West::FALSE:
                                return 9420;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9421;
                            case Properties::West::FALSE:
                                return 9422;
                            }
                        }
                    case Properties::South::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9423;
                            case Properties::West::FALSE:
                                return 9424;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9425;
                            case Properties::West::FALSE:
                                return 9426;
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
            Properties::Waterlogged waterlogged;
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
            return toProtocol(east, north, south, waterlogged, west);
        }
    }

}
