#include "GlowLichen.hpp"
#include <stdexcept>

namespace Blocks {
namespace GlowLichen {
BlockId toProtocol(
    Properties::Down down, Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west
)
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
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6639;
                            case Properties::West::FALSE:
                                return 6640;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6641;
                            case Properties::West::FALSE:
                                return 6642;
                            }
                        }
                    case Properties::Up::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6643;
                            case Properties::West::FALSE:
                                return 6644;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6645;
                            case Properties::West::FALSE:
                                return 6646;
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
                                return 6647;
                            case Properties::West::FALSE:
                                return 6648;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6649;
                            case Properties::West::FALSE:
                                return 6650;
                            }
                        }
                    case Properties::Up::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6651;
                            case Properties::West::FALSE:
                                return 6652;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6653;
                            case Properties::West::FALSE:
                                return 6654;
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
                                return 6655;
                            case Properties::West::FALSE:
                                return 6656;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6657;
                            case Properties::West::FALSE:
                                return 6658;
                            }
                        }
                    case Properties::Up::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6659;
                            case Properties::West::FALSE:
                                return 6660;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6661;
                            case Properties::West::FALSE:
                                return 6662;
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
                                return 6663;
                            case Properties::West::FALSE:
                                return 6664;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6665;
                            case Properties::West::FALSE:
                                return 6666;
                            }
                        }
                    case Properties::Up::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6667;
                            case Properties::West::FALSE:
                                return 6668;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6669;
                            case Properties::West::FALSE:
                                return 6670;
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
                                return 6671;
                            case Properties::West::FALSE:
                                return 6672;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6673;
                            case Properties::West::FALSE:
                                return 6674;
                            }
                        }
                    case Properties::Up::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6675;
                            case Properties::West::FALSE:
                                return 6676;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6677;
                            case Properties::West::FALSE:
                                return 6678;
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
                                return 6679;
                            case Properties::West::FALSE:
                                return 6680;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6681;
                            case Properties::West::FALSE:
                                return 6682;
                            }
                        }
                    case Properties::Up::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6683;
                            case Properties::West::FALSE:
                                return 6684;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6685;
                            case Properties::West::FALSE:
                                return 6686;
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
                                return 6687;
                            case Properties::West::FALSE:
                                return 6688;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6689;
                            case Properties::West::FALSE:
                                return 6690;
                            }
                        }
                    case Properties::Up::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6691;
                            case Properties::West::FALSE:
                                return 6692;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6693;
                            case Properties::West::FALSE:
                                return 6694;
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
                                return 6695;
                            case Properties::West::FALSE:
                                return 6696;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6697;
                            case Properties::West::FALSE:
                                return 6698;
                            }
                        }
                    case Properties::Up::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6699;
                            case Properties::West::FALSE:
                                return 6700;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6701;
                            case Properties::West::FALSE:
                                return 6702;
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
                                return 6703;
                            case Properties::West::FALSE:
                                return 6704;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6705;
                            case Properties::West::FALSE:
                                return 6706;
                            }
                        }
                    case Properties::Up::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6707;
                            case Properties::West::FALSE:
                                return 6708;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6709;
                            case Properties::West::FALSE:
                                return 6710;
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
                                return 6711;
                            case Properties::West::FALSE:
                                return 6712;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6713;
                            case Properties::West::FALSE:
                                return 6714;
                            }
                        }
                    case Properties::Up::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6715;
                            case Properties::West::FALSE:
                                return 6716;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6717;
                            case Properties::West::FALSE:
                                return 6718;
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
                                return 6719;
                            case Properties::West::FALSE:
                                return 6720;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6721;
                            case Properties::West::FALSE:
                                return 6722;
                            }
                        }
                    case Properties::Up::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6723;
                            case Properties::West::FALSE:
                                return 6724;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6725;
                            case Properties::West::FALSE:
                                return 6726;
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
                                return 6727;
                            case Properties::West::FALSE:
                                return 6728;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6729;
                            case Properties::West::FALSE:
                                return 6730;
                            }
                        }
                    case Properties::Up::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6731;
                            case Properties::West::FALSE:
                                return 6732;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6733;
                            case Properties::West::FALSE:
                                return 6734;
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
                                return 6735;
                            case Properties::West::FALSE:
                                return 6736;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6737;
                            case Properties::West::FALSE:
                                return 6738;
                            }
                        }
                    case Properties::Up::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6739;
                            case Properties::West::FALSE:
                                return 6740;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6741;
                            case Properties::West::FALSE:
                                return 6742;
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
                                return 6743;
                            case Properties::West::FALSE:
                                return 6744;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6745;
                            case Properties::West::FALSE:
                                return 6746;
                            }
                        }
                    case Properties::Up::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6747;
                            case Properties::West::FALSE:
                                return 6748;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6749;
                            case Properties::West::FALSE:
                                return 6750;
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
                                return 6751;
                            case Properties::West::FALSE:
                                return 6752;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6753;
                            case Properties::West::FALSE:
                                return 6754;
                            }
                        }
                    case Properties::Up::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6755;
                            case Properties::West::FALSE:
                                return 6756;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6757;
                            case Properties::West::FALSE:
                                return 6758;
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
                                return 6759;
                            case Properties::West::FALSE:
                                return 6760;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6761;
                            case Properties::West::FALSE:
                                return 6762;
                            }
                        }
                    case Properties::Up::FALSE:
                        switch (waterlogged) {
                        case Properties::Waterlogged::TRUE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6763;
                            case Properties::West::FALSE:
                                return 6764;
                            }
                        case Properties::Waterlogged::FALSE:
                            switch (west) {
                            case Properties::West::TRUE:
                                return 6765;
                            case Properties::West::FALSE:
                                return 6766;
                            }
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
