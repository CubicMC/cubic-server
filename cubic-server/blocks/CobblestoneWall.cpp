#include "CobblestoneWall.hpp"
#include <stdexcept>

namespace Blocks {
namespace CobblestoneWall {
BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west)
{
    switch (east) {
    case Properties::East::NONE:
        switch (north) {
        case Properties::North::NONE:
            switch (south) {
            case Properties::South::NONE:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7689;
                        case Properties::West::LOW:
                            return 7690;
                        case Properties::West::TALL:
                            return 7691;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7692;
                        case Properties::West::LOW:
                            return 7693;
                        case Properties::West::TALL:
                            return 7694;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7695;
                        case Properties::West::LOW:
                            return 7696;
                        case Properties::West::TALL:
                            return 7697;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7698;
                        case Properties::West::LOW:
                            return 7699;
                        case Properties::West::TALL:
                            return 7700;
                        }
                    }
                }
            case Properties::South::LOW:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7701;
                        case Properties::West::LOW:
                            return 7702;
                        case Properties::West::TALL:
                            return 7703;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7704;
                        case Properties::West::LOW:
                            return 7705;
                        case Properties::West::TALL:
                            return 7706;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7707;
                        case Properties::West::LOW:
                            return 7708;
                        case Properties::West::TALL:
                            return 7709;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7710;
                        case Properties::West::LOW:
                            return 7711;
                        case Properties::West::TALL:
                            return 7712;
                        }
                    }
                }
            case Properties::South::TALL:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7713;
                        case Properties::West::LOW:
                            return 7714;
                        case Properties::West::TALL:
                            return 7715;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7716;
                        case Properties::West::LOW:
                            return 7717;
                        case Properties::West::TALL:
                            return 7718;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7719;
                        case Properties::West::LOW:
                            return 7720;
                        case Properties::West::TALL:
                            return 7721;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7722;
                        case Properties::West::LOW:
                            return 7723;
                        case Properties::West::TALL:
                            return 7724;
                        }
                    }
                }
            }
        case Properties::North::LOW:
            switch (south) {
            case Properties::South::NONE:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7725;
                        case Properties::West::LOW:
                            return 7726;
                        case Properties::West::TALL:
                            return 7727;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7728;
                        case Properties::West::LOW:
                            return 7729;
                        case Properties::West::TALL:
                            return 7730;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7731;
                        case Properties::West::LOW:
                            return 7732;
                        case Properties::West::TALL:
                            return 7733;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7734;
                        case Properties::West::LOW:
                            return 7735;
                        case Properties::West::TALL:
                            return 7736;
                        }
                    }
                }
            case Properties::South::LOW:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7737;
                        case Properties::West::LOW:
                            return 7738;
                        case Properties::West::TALL:
                            return 7739;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7740;
                        case Properties::West::LOW:
                            return 7741;
                        case Properties::West::TALL:
                            return 7742;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7743;
                        case Properties::West::LOW:
                            return 7744;
                        case Properties::West::TALL:
                            return 7745;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7746;
                        case Properties::West::LOW:
                            return 7747;
                        case Properties::West::TALL:
                            return 7748;
                        }
                    }
                }
            case Properties::South::TALL:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7749;
                        case Properties::West::LOW:
                            return 7750;
                        case Properties::West::TALL:
                            return 7751;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7752;
                        case Properties::West::LOW:
                            return 7753;
                        case Properties::West::TALL:
                            return 7754;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7755;
                        case Properties::West::LOW:
                            return 7756;
                        case Properties::West::TALL:
                            return 7757;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7758;
                        case Properties::West::LOW:
                            return 7759;
                        case Properties::West::TALL:
                            return 7760;
                        }
                    }
                }
            }
        case Properties::North::TALL:
            switch (south) {
            case Properties::South::NONE:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7761;
                        case Properties::West::LOW:
                            return 7762;
                        case Properties::West::TALL:
                            return 7763;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7764;
                        case Properties::West::LOW:
                            return 7765;
                        case Properties::West::TALL:
                            return 7766;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7767;
                        case Properties::West::LOW:
                            return 7768;
                        case Properties::West::TALL:
                            return 7769;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7770;
                        case Properties::West::LOW:
                            return 7771;
                        case Properties::West::TALL:
                            return 7772;
                        }
                    }
                }
            case Properties::South::LOW:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7773;
                        case Properties::West::LOW:
                            return 7774;
                        case Properties::West::TALL:
                            return 7775;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7776;
                        case Properties::West::LOW:
                            return 7777;
                        case Properties::West::TALL:
                            return 7778;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7779;
                        case Properties::West::LOW:
                            return 7780;
                        case Properties::West::TALL:
                            return 7781;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7782;
                        case Properties::West::LOW:
                            return 7783;
                        case Properties::West::TALL:
                            return 7784;
                        }
                    }
                }
            case Properties::South::TALL:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7785;
                        case Properties::West::LOW:
                            return 7786;
                        case Properties::West::TALL:
                            return 7787;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7788;
                        case Properties::West::LOW:
                            return 7789;
                        case Properties::West::TALL:
                            return 7790;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7791;
                        case Properties::West::LOW:
                            return 7792;
                        case Properties::West::TALL:
                            return 7793;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7794;
                        case Properties::West::LOW:
                            return 7795;
                        case Properties::West::TALL:
                            return 7796;
                        }
                    }
                }
            }
        }
    case Properties::East::LOW:
        switch (north) {
        case Properties::North::NONE:
            switch (south) {
            case Properties::South::NONE:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7797;
                        case Properties::West::LOW:
                            return 7798;
                        case Properties::West::TALL:
                            return 7799;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7800;
                        case Properties::West::LOW:
                            return 7801;
                        case Properties::West::TALL:
                            return 7802;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7803;
                        case Properties::West::LOW:
                            return 7804;
                        case Properties::West::TALL:
                            return 7805;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7806;
                        case Properties::West::LOW:
                            return 7807;
                        case Properties::West::TALL:
                            return 7808;
                        }
                    }
                }
            case Properties::South::LOW:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7809;
                        case Properties::West::LOW:
                            return 7810;
                        case Properties::West::TALL:
                            return 7811;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7812;
                        case Properties::West::LOW:
                            return 7813;
                        case Properties::West::TALL:
                            return 7814;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7815;
                        case Properties::West::LOW:
                            return 7816;
                        case Properties::West::TALL:
                            return 7817;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7818;
                        case Properties::West::LOW:
                            return 7819;
                        case Properties::West::TALL:
                            return 7820;
                        }
                    }
                }
            case Properties::South::TALL:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7821;
                        case Properties::West::LOW:
                            return 7822;
                        case Properties::West::TALL:
                            return 7823;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7824;
                        case Properties::West::LOW:
                            return 7825;
                        case Properties::West::TALL:
                            return 7826;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7827;
                        case Properties::West::LOW:
                            return 7828;
                        case Properties::West::TALL:
                            return 7829;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7830;
                        case Properties::West::LOW:
                            return 7831;
                        case Properties::West::TALL:
                            return 7832;
                        }
                    }
                }
            }
        case Properties::North::LOW:
            switch (south) {
            case Properties::South::NONE:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7833;
                        case Properties::West::LOW:
                            return 7834;
                        case Properties::West::TALL:
                            return 7835;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7836;
                        case Properties::West::LOW:
                            return 7837;
                        case Properties::West::TALL:
                            return 7838;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7839;
                        case Properties::West::LOW:
                            return 7840;
                        case Properties::West::TALL:
                            return 7841;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7842;
                        case Properties::West::LOW:
                            return 7843;
                        case Properties::West::TALL:
                            return 7844;
                        }
                    }
                }
            case Properties::South::LOW:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7845;
                        case Properties::West::LOW:
                            return 7846;
                        case Properties::West::TALL:
                            return 7847;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7848;
                        case Properties::West::LOW:
                            return 7849;
                        case Properties::West::TALL:
                            return 7850;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7851;
                        case Properties::West::LOW:
                            return 7852;
                        case Properties::West::TALL:
                            return 7853;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7854;
                        case Properties::West::LOW:
                            return 7855;
                        case Properties::West::TALL:
                            return 7856;
                        }
                    }
                }
            case Properties::South::TALL:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7857;
                        case Properties::West::LOW:
                            return 7858;
                        case Properties::West::TALL:
                            return 7859;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7860;
                        case Properties::West::LOW:
                            return 7861;
                        case Properties::West::TALL:
                            return 7862;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7863;
                        case Properties::West::LOW:
                            return 7864;
                        case Properties::West::TALL:
                            return 7865;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7866;
                        case Properties::West::LOW:
                            return 7867;
                        case Properties::West::TALL:
                            return 7868;
                        }
                    }
                }
            }
        case Properties::North::TALL:
            switch (south) {
            case Properties::South::NONE:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7869;
                        case Properties::West::LOW:
                            return 7870;
                        case Properties::West::TALL:
                            return 7871;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7872;
                        case Properties::West::LOW:
                            return 7873;
                        case Properties::West::TALL:
                            return 7874;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7875;
                        case Properties::West::LOW:
                            return 7876;
                        case Properties::West::TALL:
                            return 7877;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7878;
                        case Properties::West::LOW:
                            return 7879;
                        case Properties::West::TALL:
                            return 7880;
                        }
                    }
                }
            case Properties::South::LOW:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7881;
                        case Properties::West::LOW:
                            return 7882;
                        case Properties::West::TALL:
                            return 7883;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7884;
                        case Properties::West::LOW:
                            return 7885;
                        case Properties::West::TALL:
                            return 7886;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7887;
                        case Properties::West::LOW:
                            return 7888;
                        case Properties::West::TALL:
                            return 7889;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7890;
                        case Properties::West::LOW:
                            return 7891;
                        case Properties::West::TALL:
                            return 7892;
                        }
                    }
                }
            case Properties::South::TALL:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7893;
                        case Properties::West::LOW:
                            return 7894;
                        case Properties::West::TALL:
                            return 7895;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7896;
                        case Properties::West::LOW:
                            return 7897;
                        case Properties::West::TALL:
                            return 7898;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7899;
                        case Properties::West::LOW:
                            return 7900;
                        case Properties::West::TALL:
                            return 7901;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7902;
                        case Properties::West::LOW:
                            return 7903;
                        case Properties::West::TALL:
                            return 7904;
                        }
                    }
                }
            }
        }
    case Properties::East::TALL:
        switch (north) {
        case Properties::North::NONE:
            switch (south) {
            case Properties::South::NONE:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7905;
                        case Properties::West::LOW:
                            return 7906;
                        case Properties::West::TALL:
                            return 7907;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7908;
                        case Properties::West::LOW:
                            return 7909;
                        case Properties::West::TALL:
                            return 7910;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7911;
                        case Properties::West::LOW:
                            return 7912;
                        case Properties::West::TALL:
                            return 7913;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7914;
                        case Properties::West::LOW:
                            return 7915;
                        case Properties::West::TALL:
                            return 7916;
                        }
                    }
                }
            case Properties::South::LOW:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7917;
                        case Properties::West::LOW:
                            return 7918;
                        case Properties::West::TALL:
                            return 7919;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7920;
                        case Properties::West::LOW:
                            return 7921;
                        case Properties::West::TALL:
                            return 7922;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7923;
                        case Properties::West::LOW:
                            return 7924;
                        case Properties::West::TALL:
                            return 7925;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7926;
                        case Properties::West::LOW:
                            return 7927;
                        case Properties::West::TALL:
                            return 7928;
                        }
                    }
                }
            case Properties::South::TALL:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7929;
                        case Properties::West::LOW:
                            return 7930;
                        case Properties::West::TALL:
                            return 7931;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7932;
                        case Properties::West::LOW:
                            return 7933;
                        case Properties::West::TALL:
                            return 7934;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7935;
                        case Properties::West::LOW:
                            return 7936;
                        case Properties::West::TALL:
                            return 7937;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7938;
                        case Properties::West::LOW:
                            return 7939;
                        case Properties::West::TALL:
                            return 7940;
                        }
                    }
                }
            }
        case Properties::North::LOW:
            switch (south) {
            case Properties::South::NONE:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7941;
                        case Properties::West::LOW:
                            return 7942;
                        case Properties::West::TALL:
                            return 7943;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7944;
                        case Properties::West::LOW:
                            return 7945;
                        case Properties::West::TALL:
                            return 7946;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7947;
                        case Properties::West::LOW:
                            return 7948;
                        case Properties::West::TALL:
                            return 7949;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7950;
                        case Properties::West::LOW:
                            return 7951;
                        case Properties::West::TALL:
                            return 7952;
                        }
                    }
                }
            case Properties::South::LOW:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7953;
                        case Properties::West::LOW:
                            return 7954;
                        case Properties::West::TALL:
                            return 7955;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7956;
                        case Properties::West::LOW:
                            return 7957;
                        case Properties::West::TALL:
                            return 7958;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7959;
                        case Properties::West::LOW:
                            return 7960;
                        case Properties::West::TALL:
                            return 7961;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7962;
                        case Properties::West::LOW:
                            return 7963;
                        case Properties::West::TALL:
                            return 7964;
                        }
                    }
                }
            case Properties::South::TALL:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7965;
                        case Properties::West::LOW:
                            return 7966;
                        case Properties::West::TALL:
                            return 7967;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7968;
                        case Properties::West::LOW:
                            return 7969;
                        case Properties::West::TALL:
                            return 7970;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7971;
                        case Properties::West::LOW:
                            return 7972;
                        case Properties::West::TALL:
                            return 7973;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7974;
                        case Properties::West::LOW:
                            return 7975;
                        case Properties::West::TALL:
                            return 7976;
                        }
                    }
                }
            }
        case Properties::North::TALL:
            switch (south) {
            case Properties::South::NONE:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7977;
                        case Properties::West::LOW:
                            return 7978;
                        case Properties::West::TALL:
                            return 7979;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7980;
                        case Properties::West::LOW:
                            return 7981;
                        case Properties::West::TALL:
                            return 7982;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7983;
                        case Properties::West::LOW:
                            return 7984;
                        case Properties::West::TALL:
                            return 7985;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7986;
                        case Properties::West::LOW:
                            return 7987;
                        case Properties::West::TALL:
                            return 7988;
                        }
                    }
                }
            case Properties::South::LOW:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7989;
                        case Properties::West::LOW:
                            return 7990;
                        case Properties::West::TALL:
                            return 7991;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7992;
                        case Properties::West::LOW:
                            return 7993;
                        case Properties::West::TALL:
                            return 7994;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7995;
                        case Properties::West::LOW:
                            return 7996;
                        case Properties::West::TALL:
                            return 7997;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 7998;
                        case Properties::West::LOW:
                            return 7999;
                        case Properties::West::TALL:
                            return 8000;
                        }
                    }
                }
            case Properties::South::TALL:
                switch (up) {
                case Properties::Up::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8001;
                        case Properties::West::LOW:
                            return 8002;
                        case Properties::West::TALL:
                            return 8003;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8004;
                        case Properties::West::LOW:
                            return 8005;
                        case Properties::West::TALL:
                            return 8006;
                        }
                    }
                case Properties::Up::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8007;
                        case Properties::West::LOW:
                            return 8008;
                        case Properties::West::TALL:
                            return 8009;
                        }
                    case Properties::Waterlogged::FALSE:
                        switch (west) {
                        case Properties::West::NONE:
                            return 8010;
                        case Properties::West::LOW:
                            return 8011;
                        case Properties::West::TALL:
                            return 8012;
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
