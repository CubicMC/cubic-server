#include "AcaciaTrapdoor.hpp"
#include <stdexcept>

namespace Blocks {
    namespace AcaciaTrapdoor {
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
                                return 4676;
                            case Properties::Waterlogged::FALSE:
                                return 4677;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 4678;
                            case Properties::Waterlogged::FALSE:
                                return 4679;
                            }
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 4680;
                            case Properties::Waterlogged::FALSE:
                                return 4681;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 4682;
                            case Properties::Waterlogged::FALSE:
                                return 4683;
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
                                return 4684;
                            case Properties::Waterlogged::FALSE:
                                return 4685;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 4686;
                            case Properties::Waterlogged::FALSE:
                                return 4687;
                            }
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 4688;
                            case Properties::Waterlogged::FALSE:
                                return 4689;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 4690;
                            case Properties::Waterlogged::FALSE:
                                return 4691;
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
                                return 4692;
                            case Properties::Waterlogged::FALSE:
                                return 4693;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 4694;
                            case Properties::Waterlogged::FALSE:
                                return 4695;
                            }
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 4696;
                            case Properties::Waterlogged::FALSE:
                                return 4697;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 4698;
                            case Properties::Waterlogged::FALSE:
                                return 4699;
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
                                return 4700;
                            case Properties::Waterlogged::FALSE:
                                return 4701;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 4702;
                            case Properties::Waterlogged::FALSE:
                                return 4703;
                            }
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 4704;
                            case Properties::Waterlogged::FALSE:
                                return 4705;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 4706;
                            case Properties::Waterlogged::FALSE:
                                return 4707;
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
                                return 4708;
                            case Properties::Waterlogged::FALSE:
                                return 4709;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 4710;
                            case Properties::Waterlogged::FALSE:
                                return 4711;
                            }
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 4712;
                            case Properties::Waterlogged::FALSE:
                                return 4713;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 4714;
                            case Properties::Waterlogged::FALSE:
                                return 4715;
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
                                return 4716;
                            case Properties::Waterlogged::FALSE:
                                return 4717;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 4718;
                            case Properties::Waterlogged::FALSE:
                                return 4719;
                            }
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 4720;
                            case Properties::Waterlogged::FALSE:
                                return 4721;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 4722;
                            case Properties::Waterlogged::FALSE:
                                return 4723;
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
                                return 4724;
                            case Properties::Waterlogged::FALSE:
                                return 4725;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 4726;
                            case Properties::Waterlogged::FALSE:
                                return 4727;
                            }
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 4728;
                            case Properties::Waterlogged::FALSE:
                                return 4729;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 4730;
                            case Properties::Waterlogged::FALSE:
                                return 4731;
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
                                return 4732;
                            case Properties::Waterlogged::FALSE:
                                return 4733;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 4734;
                            case Properties::Waterlogged::FALSE:
                                return 4735;
                            }
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 4736;
                            case Properties::Waterlogged::FALSE:
                                return 4737;
                            }
                        case Properties::Powered::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                return 4738;
                            case Properties::Waterlogged::FALSE:
                                return 4739;
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
            Properties::Open open;
            Properties::Powered powered;
            Properties::Waterlogged waterlogged;
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
                    if (prop.second == "top") {
                        half = Properties::Half::TOP;
                    } else if (prop.second == "bottom") {
                        half = Properties::Half::BOTTOM;
                    } else {
                        throw std::runtime_error("Invalid property \"half\" value");
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
                } else if (prop.first == "waterlogged") {
                    if (prop.second == "true") {
                        waterlogged = Properties::Waterlogged::TRUE;
                    } else if (prop.second == "false") {
                        waterlogged = Properties::Waterlogged::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"waterlogged\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(facing, half, open, powered, waterlogged);
        }
    }

}
