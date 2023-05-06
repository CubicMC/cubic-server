#include "ChiseledBookshelf.hpp"
namespace Blocks {
namespace ChiseledBookshelf {
BlockId toProtocol(Properties::Facing facing, Properties::Slot_0_occupied slot_0_occupied, Properties::Slot_1_occupied slot_1_occupied, Properties::Slot_2_occupied slot_2_occupied, Properties::Slot_3_occupied slot_3_occupied, Properties::Slot_4_occupied slot_4_occupied, Properties::Slot_5_occupied slot_5_occupied)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (slot_0_occupied) {
        case Properties::Slot_0_occupied::TRUE:
            switch (slot_1_occupied) {
            case Properties::Slot_1_occupied::TRUE:
                switch (slot_2_occupied) {
                case Properties::Slot_2_occupied::TRUE:
                    switch (slot_3_occupied) {
                    case Properties::Slot_3_occupied::TRUE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2045;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2046;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2047;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2048;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Slot_3_occupied::FALSE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2049;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2050;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2051;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2052;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                case Properties::Slot_2_occupied::FALSE:
                    switch (slot_3_occupied) {
                    case Properties::Slot_3_occupied::TRUE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2053;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2054;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2055;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2056;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Slot_3_occupied::FALSE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2057;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2058;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2059;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2060;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Slot_1_occupied::FALSE:
                switch (slot_2_occupied) {
                case Properties::Slot_2_occupied::TRUE:
                    switch (slot_3_occupied) {
                    case Properties::Slot_3_occupied::TRUE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2061;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2062;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2063;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2064;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Slot_3_occupied::FALSE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2065;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2066;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2067;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2068;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                case Properties::Slot_2_occupied::FALSE:
                    switch (slot_3_occupied) {
                    case Properties::Slot_3_occupied::TRUE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2069;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2070;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2071;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2072;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Slot_3_occupied::FALSE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2073;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2074;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2075;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2076;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            default:
                return 0;
            }
        case Properties::Slot_0_occupied::FALSE:
            switch (slot_1_occupied) {
            case Properties::Slot_1_occupied::TRUE:
                switch (slot_2_occupied) {
                case Properties::Slot_2_occupied::TRUE:
                    switch (slot_3_occupied) {
                    case Properties::Slot_3_occupied::TRUE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2077;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2078;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2079;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2080;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Slot_3_occupied::FALSE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2081;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2082;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2083;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2084;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                case Properties::Slot_2_occupied::FALSE:
                    switch (slot_3_occupied) {
                    case Properties::Slot_3_occupied::TRUE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2085;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2086;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2087;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2088;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Slot_3_occupied::FALSE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2089;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2090;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2091;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2092;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Slot_1_occupied::FALSE:
                switch (slot_2_occupied) {
                case Properties::Slot_2_occupied::TRUE:
                    switch (slot_3_occupied) {
                    case Properties::Slot_3_occupied::TRUE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2093;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2094;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2095;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2096;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Slot_3_occupied::FALSE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2097;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2098;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2099;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2100;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                case Properties::Slot_2_occupied::FALSE:
                    switch (slot_3_occupied) {
                    case Properties::Slot_3_occupied::TRUE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2101;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2102;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2103;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2104;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Slot_3_occupied::FALSE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2105;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2106;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2107;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2108;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Facing::SOUTH:
        switch (slot_0_occupied) {
        case Properties::Slot_0_occupied::TRUE:
            switch (slot_1_occupied) {
            case Properties::Slot_1_occupied::TRUE:
                switch (slot_2_occupied) {
                case Properties::Slot_2_occupied::TRUE:
                    switch (slot_3_occupied) {
                    case Properties::Slot_3_occupied::TRUE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2109;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2110;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2111;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2112;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Slot_3_occupied::FALSE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2113;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2114;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2115;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2116;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                case Properties::Slot_2_occupied::FALSE:
                    switch (slot_3_occupied) {
                    case Properties::Slot_3_occupied::TRUE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2117;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2118;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2119;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2120;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Slot_3_occupied::FALSE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2121;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2122;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2123;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2124;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Slot_1_occupied::FALSE:
                switch (slot_2_occupied) {
                case Properties::Slot_2_occupied::TRUE:
                    switch (slot_3_occupied) {
                    case Properties::Slot_3_occupied::TRUE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2125;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2126;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2127;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2128;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Slot_3_occupied::FALSE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2129;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2130;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2131;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2132;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                case Properties::Slot_2_occupied::FALSE:
                    switch (slot_3_occupied) {
                    case Properties::Slot_3_occupied::TRUE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2133;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2134;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2135;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2136;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Slot_3_occupied::FALSE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2137;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2138;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2139;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2140;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            default:
                return 0;
            }
        case Properties::Slot_0_occupied::FALSE:
            switch (slot_1_occupied) {
            case Properties::Slot_1_occupied::TRUE:
                switch (slot_2_occupied) {
                case Properties::Slot_2_occupied::TRUE:
                    switch (slot_3_occupied) {
                    case Properties::Slot_3_occupied::TRUE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2141;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2142;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2143;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2144;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Slot_3_occupied::FALSE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2145;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2146;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2147;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2148;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                case Properties::Slot_2_occupied::FALSE:
                    switch (slot_3_occupied) {
                    case Properties::Slot_3_occupied::TRUE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2149;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2150;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2151;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2152;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Slot_3_occupied::FALSE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2153;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2154;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2155;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2156;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Slot_1_occupied::FALSE:
                switch (slot_2_occupied) {
                case Properties::Slot_2_occupied::TRUE:
                    switch (slot_3_occupied) {
                    case Properties::Slot_3_occupied::TRUE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2157;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2158;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2159;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2160;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Slot_3_occupied::FALSE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2161;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2162;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2163;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2164;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                case Properties::Slot_2_occupied::FALSE:
                    switch (slot_3_occupied) {
                    case Properties::Slot_3_occupied::TRUE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2165;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2166;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2167;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2168;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Slot_3_occupied::FALSE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2169;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2170;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2171;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2172;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Facing::WEST:
        switch (slot_0_occupied) {
        case Properties::Slot_0_occupied::TRUE:
            switch (slot_1_occupied) {
            case Properties::Slot_1_occupied::TRUE:
                switch (slot_2_occupied) {
                case Properties::Slot_2_occupied::TRUE:
                    switch (slot_3_occupied) {
                    case Properties::Slot_3_occupied::TRUE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2173;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2174;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2175;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2176;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Slot_3_occupied::FALSE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2177;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2178;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2179;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2180;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                case Properties::Slot_2_occupied::FALSE:
                    switch (slot_3_occupied) {
                    case Properties::Slot_3_occupied::TRUE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2181;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2182;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2183;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2184;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Slot_3_occupied::FALSE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2185;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2186;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2187;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2188;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Slot_1_occupied::FALSE:
                switch (slot_2_occupied) {
                case Properties::Slot_2_occupied::TRUE:
                    switch (slot_3_occupied) {
                    case Properties::Slot_3_occupied::TRUE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2189;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2190;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2191;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2192;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Slot_3_occupied::FALSE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2193;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2194;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2195;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2196;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                case Properties::Slot_2_occupied::FALSE:
                    switch (slot_3_occupied) {
                    case Properties::Slot_3_occupied::TRUE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2197;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2198;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2199;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2200;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Slot_3_occupied::FALSE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2201;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2202;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2203;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2204;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            default:
                return 0;
            }
        case Properties::Slot_0_occupied::FALSE:
            switch (slot_1_occupied) {
            case Properties::Slot_1_occupied::TRUE:
                switch (slot_2_occupied) {
                case Properties::Slot_2_occupied::TRUE:
                    switch (slot_3_occupied) {
                    case Properties::Slot_3_occupied::TRUE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2205;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2206;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2207;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2208;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Slot_3_occupied::FALSE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2209;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2210;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2211;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2212;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                case Properties::Slot_2_occupied::FALSE:
                    switch (slot_3_occupied) {
                    case Properties::Slot_3_occupied::TRUE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2213;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2214;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2215;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2216;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Slot_3_occupied::FALSE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2217;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2218;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2219;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2220;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Slot_1_occupied::FALSE:
                switch (slot_2_occupied) {
                case Properties::Slot_2_occupied::TRUE:
                    switch (slot_3_occupied) {
                    case Properties::Slot_3_occupied::TRUE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2221;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2222;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2223;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2224;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Slot_3_occupied::FALSE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2225;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2226;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2227;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2228;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                case Properties::Slot_2_occupied::FALSE:
                    switch (slot_3_occupied) {
                    case Properties::Slot_3_occupied::TRUE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2229;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2230;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2231;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2232;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Slot_3_occupied::FALSE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2233;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2234;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2235;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2236;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            default:
                return 0;
            }
        default:
            return 0;
        }
    case Properties::Facing::EAST:
        switch (slot_0_occupied) {
        case Properties::Slot_0_occupied::TRUE:
            switch (slot_1_occupied) {
            case Properties::Slot_1_occupied::TRUE:
                switch (slot_2_occupied) {
                case Properties::Slot_2_occupied::TRUE:
                    switch (slot_3_occupied) {
                    case Properties::Slot_3_occupied::TRUE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2237;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2238;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2239;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2240;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Slot_3_occupied::FALSE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2241;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2242;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2243;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2244;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                case Properties::Slot_2_occupied::FALSE:
                    switch (slot_3_occupied) {
                    case Properties::Slot_3_occupied::TRUE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2245;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2246;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2247;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2248;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Slot_3_occupied::FALSE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2249;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2250;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2251;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2252;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Slot_1_occupied::FALSE:
                switch (slot_2_occupied) {
                case Properties::Slot_2_occupied::TRUE:
                    switch (slot_3_occupied) {
                    case Properties::Slot_3_occupied::TRUE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2253;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2254;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2255;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2256;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Slot_3_occupied::FALSE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2257;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2258;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2259;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2260;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                case Properties::Slot_2_occupied::FALSE:
                    switch (slot_3_occupied) {
                    case Properties::Slot_3_occupied::TRUE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2261;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2262;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2263;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2264;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Slot_3_occupied::FALSE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2265;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2266;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2267;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2268;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            default:
                return 0;
            }
        case Properties::Slot_0_occupied::FALSE:
            switch (slot_1_occupied) {
            case Properties::Slot_1_occupied::TRUE:
                switch (slot_2_occupied) {
                case Properties::Slot_2_occupied::TRUE:
                    switch (slot_3_occupied) {
                    case Properties::Slot_3_occupied::TRUE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2269;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2270;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2271;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2272;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Slot_3_occupied::FALSE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2273;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2274;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2275;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2276;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                case Properties::Slot_2_occupied::FALSE:
                    switch (slot_3_occupied) {
                    case Properties::Slot_3_occupied::TRUE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2277;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2278;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2279;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2280;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Slot_3_occupied::FALSE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2281;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2282;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2283;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2284;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            case Properties::Slot_1_occupied::FALSE:
                switch (slot_2_occupied) {
                case Properties::Slot_2_occupied::TRUE:
                    switch (slot_3_occupied) {
                    case Properties::Slot_3_occupied::TRUE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2285;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2286;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2287;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2288;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Slot_3_occupied::FALSE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2289;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2290;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2291;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2292;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                case Properties::Slot_2_occupied::FALSE:
                    switch (slot_3_occupied) {
                    case Properties::Slot_3_occupied::TRUE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2293;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2294;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2295;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2296;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    case Properties::Slot_3_occupied::FALSE:
                        switch (slot_4_occupied) {
                        case Properties::Slot_4_occupied::TRUE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2297;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2298;
                            default:
                                return 0;
                            }
                        case Properties::Slot_4_occupied::FALSE:
                            switch (slot_5_occupied) {
                            case Properties::Slot_5_occupied::TRUE:
                                return 2299;
                            case Properties::Slot_5_occupied::FALSE:
                                return 2300;
                            default:
                                return 0;
                            }
                        default:
                            return 0;
                        }
                    default:
                        return 0;
                    }
                default:
                    return 0;
                }
            default:
                return 0;
            }
        default:
            return 0;
        }
    default:
        return 0;
    }
    return 0;
}
}

}
