#include "WarpedDoor.hpp"
#include <stdexcept>

namespace Blocks {
    namespace WarpedDoor {
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Hinge hinge, Properties::Open open, Properties::Powered powered) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (half) {
                case Properties::Half::UPPER:
                    switch (hinge) {
                    case Properties::Hinge::LEFT:
                        switch (open) {
                        case Properties::Open::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 16800;
                            case Properties::Powered::FALSE:
                                return 16801;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 16802;
                            case Properties::Powered::FALSE:
                                return 16803;
                            }
                        }
                    case Properties::Hinge::RIGHT:
                        switch (open) {
                        case Properties::Open::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 16804;
                            case Properties::Powered::FALSE:
                                return 16805;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 16806;
                            case Properties::Powered::FALSE:
                                return 16807;
                            }
                        }
                    }
                case Properties::Half::LOWER:
                    switch (hinge) {
                    case Properties::Hinge::LEFT:
                        switch (open) {
                        case Properties::Open::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 16808;
                            case Properties::Powered::FALSE:
                                return 16809;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 16810;
                            case Properties::Powered::FALSE:
                                return 16811;
                            }
                        }
                    case Properties::Hinge::RIGHT:
                        switch (open) {
                        case Properties::Open::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 16812;
                            case Properties::Powered::FALSE:
                                return 16813;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 16814;
                            case Properties::Powered::FALSE:
                                return 16815;
                            }
                        }
                    }
                }
            case Properties::Facing::SOUTH:
                switch (half) {
                case Properties::Half::UPPER:
                    switch (hinge) {
                    case Properties::Hinge::LEFT:
                        switch (open) {
                        case Properties::Open::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 16816;
                            case Properties::Powered::FALSE:
                                return 16817;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 16818;
                            case Properties::Powered::FALSE:
                                return 16819;
                            }
                        }
                    case Properties::Hinge::RIGHT:
                        switch (open) {
                        case Properties::Open::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 16820;
                            case Properties::Powered::FALSE:
                                return 16821;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 16822;
                            case Properties::Powered::FALSE:
                                return 16823;
                            }
                        }
                    }
                case Properties::Half::LOWER:
                    switch (hinge) {
                    case Properties::Hinge::LEFT:
                        switch (open) {
                        case Properties::Open::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 16824;
                            case Properties::Powered::FALSE:
                                return 16825;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 16826;
                            case Properties::Powered::FALSE:
                                return 16827;
                            }
                        }
                    case Properties::Hinge::RIGHT:
                        switch (open) {
                        case Properties::Open::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 16828;
                            case Properties::Powered::FALSE:
                                return 16829;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 16830;
                            case Properties::Powered::FALSE:
                                return 16831;
                            }
                        }
                    }
                }
            case Properties::Facing::WEST:
                switch (half) {
                case Properties::Half::UPPER:
                    switch (hinge) {
                    case Properties::Hinge::LEFT:
                        switch (open) {
                        case Properties::Open::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 16832;
                            case Properties::Powered::FALSE:
                                return 16833;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 16834;
                            case Properties::Powered::FALSE:
                                return 16835;
                            }
                        }
                    case Properties::Hinge::RIGHT:
                        switch (open) {
                        case Properties::Open::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 16836;
                            case Properties::Powered::FALSE:
                                return 16837;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 16838;
                            case Properties::Powered::FALSE:
                                return 16839;
                            }
                        }
                    }
                case Properties::Half::LOWER:
                    switch (hinge) {
                    case Properties::Hinge::LEFT:
                        switch (open) {
                        case Properties::Open::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 16840;
                            case Properties::Powered::FALSE:
                                return 16841;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 16842;
                            case Properties::Powered::FALSE:
                                return 16843;
                            }
                        }
                    case Properties::Hinge::RIGHT:
                        switch (open) {
                        case Properties::Open::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 16844;
                            case Properties::Powered::FALSE:
                                return 16845;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 16846;
                            case Properties::Powered::FALSE:
                                return 16847;
                            }
                        }
                    }
                }
            case Properties::Facing::EAST:
                switch (half) {
                case Properties::Half::UPPER:
                    switch (hinge) {
                    case Properties::Hinge::LEFT:
                        switch (open) {
                        case Properties::Open::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 16848;
                            case Properties::Powered::FALSE:
                                return 16849;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 16850;
                            case Properties::Powered::FALSE:
                                return 16851;
                            }
                        }
                    case Properties::Hinge::RIGHT:
                        switch (open) {
                        case Properties::Open::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 16852;
                            case Properties::Powered::FALSE:
                                return 16853;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 16854;
                            case Properties::Powered::FALSE:
                                return 16855;
                            }
                        }
                    }
                case Properties::Half::LOWER:
                    switch (hinge) {
                    case Properties::Hinge::LEFT:
                        switch (open) {
                        case Properties::Open::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 16856;
                            case Properties::Powered::FALSE:
                                return 16857;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 16858;
                            case Properties::Powered::FALSE:
                                return 16859;
                            }
                        }
                    case Properties::Hinge::RIGHT:
                        switch (open) {
                        case Properties::Open::TRUE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 16860;
                            case Properties::Powered::FALSE:
                                return 16861;
                            }
                        case Properties::Open::FALSE:
                            switch (powered) {
                            case Properties::Powered::TRUE:
                                return 16862;
                            case Properties::Powered::FALSE:
                                return 16863;
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
            Properties::Facing facing;
            Properties::Half half;
            Properties::Hinge hinge;
            Properties::Open open;
            Properties::Powered powered;
            for (auto prop : properties) {
                if (prop.first == "facing") {
                    if (prop.second == "north") {
                        facing = Properties::Facing::NORTH;
                    } else if (prop.second == "south") {
                        facing = Properties::Facing::SOUTH;
                    } else if (prop.second == "west") {
                        facing = Properties::Facing::WEST;
                    } else if (prop.second == "east") {
                        facing = Properties::Facing::EAST;
                    } else {
                        throw std::runtime_error("Invalid property \"facing\" value");
                    }
                } else if (prop.first == "half") {
                    if (prop.second == "upper") {
                        half = Properties::Half::UPPER;
                    } else if (prop.second == "lower") {
                        half = Properties::Half::LOWER;
                    } else {
                        throw std::runtime_error("Invalid property \"half\" value");
                    }
                } else if (prop.first == "hinge") {
                    if (prop.second == "left") {
                        hinge = Properties::Hinge::LEFT;
                    } else if (prop.second == "right") {
                        hinge = Properties::Hinge::RIGHT;
                    } else {
                        throw std::runtime_error("Invalid property \"hinge\" value");
                    }
                } else if (prop.first == "open") {
                    if (prop.second == "true") {
                        open = Properties::Open::TRUE;
                    } else if (prop.second == "false") {
                        open = Properties::Open::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"open\" value");
                    }
                } else if (prop.first == "powered") {
                    if (prop.second == "true") {
                        powered = Properties::Powered::TRUE;
                    } else if (prop.second == "false") {
                        powered = Properties::Powered::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"powered\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(facing, half, hinge, open, powered);
        }
    }

}
