#include "SpruceFence.hpp"
#include <stdexcept>

namespace Blocks {
    namespace SpruceFence {
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
                                return 9363;
                            case Properties::West::FALSE:
                                return 9364;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9365;
                            case Properties::West::FALSE:
                                return 9366;
                            }
                        }
                    case Properties::South::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9367;
                            case Properties::West::FALSE:
                                return 9368;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9369;
                            case Properties::West::FALSE:
                                return 9370;
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
                                return 9371;
                            case Properties::West::FALSE:
                                return 9372;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9373;
                            case Properties::West::FALSE:
                                return 9374;
                            }
                        }
                    case Properties::South::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9375;
                            case Properties::West::FALSE:
                                return 9376;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9377;
                            case Properties::West::FALSE:
                                return 9378;
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
                                return 9379;
                            case Properties::West::FALSE:
                                return 9380;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9381;
                            case Properties::West::FALSE:
                                return 9382;
                            }
                        }
                    case Properties::South::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9383;
                            case Properties::West::FALSE:
                                return 9384;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9385;
                            case Properties::West::FALSE:
                                return 9386;
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
                                return 9387;
                            case Properties::West::FALSE:
                                return 9388;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9389;
                            case Properties::West::FALSE:
                                return 9390;
                            }
                        }
                    case Properties::South::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9391;
                            case Properties::West::FALSE:
                                return 9392;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 9393;
                            case Properties::West::FALSE:
                                return 9394;
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
