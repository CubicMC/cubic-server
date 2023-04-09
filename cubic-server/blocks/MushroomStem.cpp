#include "MushroomStem.hpp"
#include <stdexcept>

namespace Blocks {
namespace MushroomStem {
BlockId toProtocol(Properties::Down down, Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::West west)
{
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
                            return 6448;
                        case Properties::West::FALSE:
                            return 6449;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6450;
                        case Properties::West::FALSE:
                            return 6451;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6452;
                        case Properties::West::FALSE:
                            return 6453;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6454;
                        case Properties::West::FALSE:
                            return 6455;
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
                            return 6456;
                        case Properties::West::FALSE:
                            return 6457;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6458;
                        case Properties::West::FALSE:
                            return 6459;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6460;
                        case Properties::West::FALSE:
                            return 6461;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6462;
                        case Properties::West::FALSE:
                            return 6463;
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
                            return 6464;
                        case Properties::West::FALSE:
                            return 6465;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6466;
                        case Properties::West::FALSE:
                            return 6467;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6468;
                        case Properties::West::FALSE:
                            return 6469;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6470;
                        case Properties::West::FALSE:
                            return 6471;
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
                            return 6472;
                        case Properties::West::FALSE:
                            return 6473;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6474;
                        case Properties::West::FALSE:
                            return 6475;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6476;
                        case Properties::West::FALSE:
                            return 6477;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6478;
                        case Properties::West::FALSE:
                            return 6479;
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
                            return 6480;
                        case Properties::West::FALSE:
                            return 6481;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6482;
                        case Properties::West::FALSE:
                            return 6483;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6484;
                        case Properties::West::FALSE:
                            return 6485;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6486;
                        case Properties::West::FALSE:
                            return 6487;
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
                            return 6488;
                        case Properties::West::FALSE:
                            return 6489;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6490;
                        case Properties::West::FALSE:
                            return 6491;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6492;
                        case Properties::West::FALSE:
                            return 6493;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6494;
                        case Properties::West::FALSE:
                            return 6495;
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
                            return 6496;
                        case Properties::West::FALSE:
                            return 6497;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6498;
                        case Properties::West::FALSE:
                            return 6499;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6500;
                        case Properties::West::FALSE:
                            return 6501;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6502;
                        case Properties::West::FALSE:
                            return 6503;
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
                            return 6504;
                        case Properties::West::FALSE:
                            return 6505;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6506;
                        case Properties::West::FALSE:
                            return 6507;
                        }
                    }
                case Properties::South::FALSE:
                    switch (up) {
                    case Properties::Up::TRUE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6508;
                        case Properties::West::FALSE:
                            return 6509;
                        }
                    case Properties::Up::FALSE:
                        switch (west) {
                        case Properties::West::TRUE:
                            return 6510;
                        case Properties::West::FALSE:
                            return 6511;
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
