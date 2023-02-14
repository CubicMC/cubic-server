#include "MossyStoneBrickWall.hpp"
#include <stdexcept>

namespace Blocks {
    namespace MossyStoneBrickWall {
        BlockId toProtocol(Properties::East east, Properties::North north, Properties::South south, Properties::Up up, Properties::Waterlogged waterlogged, Properties::West west) {
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
                                    return 12720;
                                case Properties::West::LOW:
                                    return 12721;
                                case Properties::West::TALL:
                                    return 12722;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12723;
                                case Properties::West::LOW:
                                    return 12724;
                                case Properties::West::TALL:
                                    return 12725;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12726;
                                case Properties::West::LOW:
                                    return 12727;
                                case Properties::West::TALL:
                                    return 12728;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12729;
                                case Properties::West::LOW:
                                    return 12730;
                                case Properties::West::TALL:
                                    return 12731;
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
                                    return 12732;
                                case Properties::West::LOW:
                                    return 12733;
                                case Properties::West::TALL:
                                    return 12734;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12735;
                                case Properties::West::LOW:
                                    return 12736;
                                case Properties::West::TALL:
                                    return 12737;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12738;
                                case Properties::West::LOW:
                                    return 12739;
                                case Properties::West::TALL:
                                    return 12740;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12741;
                                case Properties::West::LOW:
                                    return 12742;
                                case Properties::West::TALL:
                                    return 12743;
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
                                    return 12744;
                                case Properties::West::LOW:
                                    return 12745;
                                case Properties::West::TALL:
                                    return 12746;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12747;
                                case Properties::West::LOW:
                                    return 12748;
                                case Properties::West::TALL:
                                    return 12749;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12750;
                                case Properties::West::LOW:
                                    return 12751;
                                case Properties::West::TALL:
                                    return 12752;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12753;
                                case Properties::West::LOW:
                                    return 12754;
                                case Properties::West::TALL:
                                    return 12755;
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
                                    return 12756;
                                case Properties::West::LOW:
                                    return 12757;
                                case Properties::West::TALL:
                                    return 12758;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12759;
                                case Properties::West::LOW:
                                    return 12760;
                                case Properties::West::TALL:
                                    return 12761;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12762;
                                case Properties::West::LOW:
                                    return 12763;
                                case Properties::West::TALL:
                                    return 12764;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12765;
                                case Properties::West::LOW:
                                    return 12766;
                                case Properties::West::TALL:
                                    return 12767;
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
                                    return 12768;
                                case Properties::West::LOW:
                                    return 12769;
                                case Properties::West::TALL:
                                    return 12770;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12771;
                                case Properties::West::LOW:
                                    return 12772;
                                case Properties::West::TALL:
                                    return 12773;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12774;
                                case Properties::West::LOW:
                                    return 12775;
                                case Properties::West::TALL:
                                    return 12776;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12777;
                                case Properties::West::LOW:
                                    return 12778;
                                case Properties::West::TALL:
                                    return 12779;
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
                                    return 12780;
                                case Properties::West::LOW:
                                    return 12781;
                                case Properties::West::TALL:
                                    return 12782;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12783;
                                case Properties::West::LOW:
                                    return 12784;
                                case Properties::West::TALL:
                                    return 12785;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12786;
                                case Properties::West::LOW:
                                    return 12787;
                                case Properties::West::TALL:
                                    return 12788;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12789;
                                case Properties::West::LOW:
                                    return 12790;
                                case Properties::West::TALL:
                                    return 12791;
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
                                    return 12792;
                                case Properties::West::LOW:
                                    return 12793;
                                case Properties::West::TALL:
                                    return 12794;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12795;
                                case Properties::West::LOW:
                                    return 12796;
                                case Properties::West::TALL:
                                    return 12797;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12798;
                                case Properties::West::LOW:
                                    return 12799;
                                case Properties::West::TALL:
                                    return 12800;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12801;
                                case Properties::West::LOW:
                                    return 12802;
                                case Properties::West::TALL:
                                    return 12803;
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
                                    return 12804;
                                case Properties::West::LOW:
                                    return 12805;
                                case Properties::West::TALL:
                                    return 12806;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12807;
                                case Properties::West::LOW:
                                    return 12808;
                                case Properties::West::TALL:
                                    return 12809;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12810;
                                case Properties::West::LOW:
                                    return 12811;
                                case Properties::West::TALL:
                                    return 12812;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12813;
                                case Properties::West::LOW:
                                    return 12814;
                                case Properties::West::TALL:
                                    return 12815;
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
                                    return 12816;
                                case Properties::West::LOW:
                                    return 12817;
                                case Properties::West::TALL:
                                    return 12818;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12819;
                                case Properties::West::LOW:
                                    return 12820;
                                case Properties::West::TALL:
                                    return 12821;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12822;
                                case Properties::West::LOW:
                                    return 12823;
                                case Properties::West::TALL:
                                    return 12824;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12825;
                                case Properties::West::LOW:
                                    return 12826;
                                case Properties::West::TALL:
                                    return 12827;
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
                                    return 12828;
                                case Properties::West::LOW:
                                    return 12829;
                                case Properties::West::TALL:
                                    return 12830;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12831;
                                case Properties::West::LOW:
                                    return 12832;
                                case Properties::West::TALL:
                                    return 12833;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12834;
                                case Properties::West::LOW:
                                    return 12835;
                                case Properties::West::TALL:
                                    return 12836;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12837;
                                case Properties::West::LOW:
                                    return 12838;
                                case Properties::West::TALL:
                                    return 12839;
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
                                    return 12840;
                                case Properties::West::LOW:
                                    return 12841;
                                case Properties::West::TALL:
                                    return 12842;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12843;
                                case Properties::West::LOW:
                                    return 12844;
                                case Properties::West::TALL:
                                    return 12845;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12846;
                                case Properties::West::LOW:
                                    return 12847;
                                case Properties::West::TALL:
                                    return 12848;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12849;
                                case Properties::West::LOW:
                                    return 12850;
                                case Properties::West::TALL:
                                    return 12851;
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
                                    return 12852;
                                case Properties::West::LOW:
                                    return 12853;
                                case Properties::West::TALL:
                                    return 12854;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12855;
                                case Properties::West::LOW:
                                    return 12856;
                                case Properties::West::TALL:
                                    return 12857;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12858;
                                case Properties::West::LOW:
                                    return 12859;
                                case Properties::West::TALL:
                                    return 12860;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12861;
                                case Properties::West::LOW:
                                    return 12862;
                                case Properties::West::TALL:
                                    return 12863;
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
                                    return 12864;
                                case Properties::West::LOW:
                                    return 12865;
                                case Properties::West::TALL:
                                    return 12866;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12867;
                                case Properties::West::LOW:
                                    return 12868;
                                case Properties::West::TALL:
                                    return 12869;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12870;
                                case Properties::West::LOW:
                                    return 12871;
                                case Properties::West::TALL:
                                    return 12872;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12873;
                                case Properties::West::LOW:
                                    return 12874;
                                case Properties::West::TALL:
                                    return 12875;
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
                                    return 12876;
                                case Properties::West::LOW:
                                    return 12877;
                                case Properties::West::TALL:
                                    return 12878;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12879;
                                case Properties::West::LOW:
                                    return 12880;
                                case Properties::West::TALL:
                                    return 12881;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12882;
                                case Properties::West::LOW:
                                    return 12883;
                                case Properties::West::TALL:
                                    return 12884;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12885;
                                case Properties::West::LOW:
                                    return 12886;
                                case Properties::West::TALL:
                                    return 12887;
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
                                    return 12888;
                                case Properties::West::LOW:
                                    return 12889;
                                case Properties::West::TALL:
                                    return 12890;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12891;
                                case Properties::West::LOW:
                                    return 12892;
                                case Properties::West::TALL:
                                    return 12893;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12894;
                                case Properties::West::LOW:
                                    return 12895;
                                case Properties::West::TALL:
                                    return 12896;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12897;
                                case Properties::West::LOW:
                                    return 12898;
                                case Properties::West::TALL:
                                    return 12899;
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
                                    return 12900;
                                case Properties::West::LOW:
                                    return 12901;
                                case Properties::West::TALL:
                                    return 12902;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12903;
                                case Properties::West::LOW:
                                    return 12904;
                                case Properties::West::TALL:
                                    return 12905;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12906;
                                case Properties::West::LOW:
                                    return 12907;
                                case Properties::West::TALL:
                                    return 12908;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12909;
                                case Properties::West::LOW:
                                    return 12910;
                                case Properties::West::TALL:
                                    return 12911;
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
                                    return 12912;
                                case Properties::West::LOW:
                                    return 12913;
                                case Properties::West::TALL:
                                    return 12914;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12915;
                                case Properties::West::LOW:
                                    return 12916;
                                case Properties::West::TALL:
                                    return 12917;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12918;
                                case Properties::West::LOW:
                                    return 12919;
                                case Properties::West::TALL:
                                    return 12920;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12921;
                                case Properties::West::LOW:
                                    return 12922;
                                case Properties::West::TALL:
                                    return 12923;
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
                                    return 12924;
                                case Properties::West::LOW:
                                    return 12925;
                                case Properties::West::TALL:
                                    return 12926;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12927;
                                case Properties::West::LOW:
                                    return 12928;
                                case Properties::West::TALL:
                                    return 12929;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12930;
                                case Properties::West::LOW:
                                    return 12931;
                                case Properties::West::TALL:
                                    return 12932;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12933;
                                case Properties::West::LOW:
                                    return 12934;
                                case Properties::West::TALL:
                                    return 12935;
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
                                    return 12936;
                                case Properties::West::LOW:
                                    return 12937;
                                case Properties::West::TALL:
                                    return 12938;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12939;
                                case Properties::West::LOW:
                                    return 12940;
                                case Properties::West::TALL:
                                    return 12941;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12942;
                                case Properties::West::LOW:
                                    return 12943;
                                case Properties::West::TALL:
                                    return 12944;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12945;
                                case Properties::West::LOW:
                                    return 12946;
                                case Properties::West::TALL:
                                    return 12947;
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
                                    return 12948;
                                case Properties::West::LOW:
                                    return 12949;
                                case Properties::West::TALL:
                                    return 12950;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12951;
                                case Properties::West::LOW:
                                    return 12952;
                                case Properties::West::TALL:
                                    return 12953;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12954;
                                case Properties::West::LOW:
                                    return 12955;
                                case Properties::West::TALL:
                                    return 12956;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12957;
                                case Properties::West::LOW:
                                    return 12958;
                                case Properties::West::TALL:
                                    return 12959;
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
                                    return 12960;
                                case Properties::West::LOW:
                                    return 12961;
                                case Properties::West::TALL:
                                    return 12962;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12963;
                                case Properties::West::LOW:
                                    return 12964;
                                case Properties::West::TALL:
                                    return 12965;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12966;
                                case Properties::West::LOW:
                                    return 12967;
                                case Properties::West::TALL:
                                    return 12968;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12969;
                                case Properties::West::LOW:
                                    return 12970;
                                case Properties::West::TALL:
                                    return 12971;
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
                                    return 12972;
                                case Properties::West::LOW:
                                    return 12973;
                                case Properties::West::TALL:
                                    return 12974;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12975;
                                case Properties::West::LOW:
                                    return 12976;
                                case Properties::West::TALL:
                                    return 12977;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12978;
                                case Properties::West::LOW:
                                    return 12979;
                                case Properties::West::TALL:
                                    return 12980;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12981;
                                case Properties::West::LOW:
                                    return 12982;
                                case Properties::West::TALL:
                                    return 12983;
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
                                    return 12984;
                                case Properties::West::LOW:
                                    return 12985;
                                case Properties::West::TALL:
                                    return 12986;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12987;
                                case Properties::West::LOW:
                                    return 12988;
                                case Properties::West::TALL:
                                    return 12989;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12990;
                                case Properties::West::LOW:
                                    return 12991;
                                case Properties::West::TALL:
                                    return 12992;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12993;
                                case Properties::West::LOW:
                                    return 12994;
                                case Properties::West::TALL:
                                    return 12995;
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
                                    return 12996;
                                case Properties::West::LOW:
                                    return 12997;
                                case Properties::West::TALL:
                                    return 12998;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 12999;
                                case Properties::West::LOW:
                                    return 13000;
                                case Properties::West::TALL:
                                    return 13001;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13002;
                                case Properties::West::LOW:
                                    return 13003;
                                case Properties::West::TALL:
                                    return 13004;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13005;
                                case Properties::West::LOW:
                                    return 13006;
                                case Properties::West::TALL:
                                    return 13007;
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
                                    return 13008;
                                case Properties::West::LOW:
                                    return 13009;
                                case Properties::West::TALL:
                                    return 13010;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13011;
                                case Properties::West::LOW:
                                    return 13012;
                                case Properties::West::TALL:
                                    return 13013;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13014;
                                case Properties::West::LOW:
                                    return 13015;
                                case Properties::West::TALL:
                                    return 13016;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13017;
                                case Properties::West::LOW:
                                    return 13018;
                                case Properties::West::TALL:
                                    return 13019;
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
                                    return 13020;
                                case Properties::West::LOW:
                                    return 13021;
                                case Properties::West::TALL:
                                    return 13022;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13023;
                                case Properties::West::LOW:
                                    return 13024;
                                case Properties::West::TALL:
                                    return 13025;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13026;
                                case Properties::West::LOW:
                                    return 13027;
                                case Properties::West::TALL:
                                    return 13028;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13029;
                                case Properties::West::LOW:
                                    return 13030;
                                case Properties::West::TALL:
                                    return 13031;
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
                                    return 13032;
                                case Properties::West::LOW:
                                    return 13033;
                                case Properties::West::TALL:
                                    return 13034;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13035;
                                case Properties::West::LOW:
                                    return 13036;
                                case Properties::West::TALL:
                                    return 13037;
                                }
                            }
                        case Properties::Up::FALSE:
                            switch (waterlogged) {
                            case Properties::Waterlogged::TRUE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13038;
                                case Properties::West::LOW:
                                    return 13039;
                                case Properties::West::TALL:
                                    return 13040;
                                }
                            case Properties::Waterlogged::FALSE:
                                switch (west) {
                                case Properties::West::NONE:
                                    return 13041;
                                case Properties::West::LOW:
                                    return 13042;
                                case Properties::West::TALL:
                                    return 13043;
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
            Properties::East east;
            Properties::North north;
            Properties::South south;
            Properties::Up up;
            Properties::Waterlogged waterlogged;
            Properties::West west;
            for (auto prop : properties) {
                if (prop.first == "east") {
                    if (prop.second == "none") {
                        east = Properties::East::NONE;
                    } else if (prop.second == "low") {
                        east = Properties::East::LOW;
                    } else if (prop.second == "tall") {
                        east = Properties::East::TALL;
                    } else {
                        throw std::runtime_error("Invalid property \"east\" value");
                    }
                } else if (prop.first == "north") {
                    if (prop.second == "none") {
                        north = Properties::North::NONE;
                    } else if (prop.second == "low") {
                        north = Properties::North::LOW;
                    } else if (prop.second == "tall") {
                        north = Properties::North::TALL;
                    } else {
                        throw std::runtime_error("Invalid property \"north\" value");
                    }
                } else if (prop.first == "south") {
                    if (prop.second == "none") {
                        south = Properties::South::NONE;
                    } else if (prop.second == "low") {
                        south = Properties::South::LOW;
                    } else if (prop.second == "tall") {
                        south = Properties::South::TALL;
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
                } else if (prop.first == "waterlogged") {
                    if (prop.second == "true") {
                        waterlogged = Properties::Waterlogged::TRUE;
                    } else if (prop.second == "false") {
                        waterlogged = Properties::Waterlogged::FALSE;
                    } else {
                        throw std::runtime_error("Invalid property \"waterlogged\" value");
                    }
                } else if (prop.first == "west") {
                    if (prop.second == "none") {
                        west = Properties::West::NONE;
                    } else if (prop.second == "low") {
                        west = Properties::West::LOW;
                    } else if (prop.second == "tall") {
                        west = Properties::West::TALL;
                    } else {
                        throw std::runtime_error("Invalid property \"west\" value");
                    }
                } else {
                    throw std::runtime_error("Invalid property name");
                }
            }
            return toProtocol(east, north, south, up, waterlogged, west);
        }
    }

}
