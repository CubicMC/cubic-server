#include "ChiseledBookshelf.hpp"
namespace Blocks {
    namespace ChiseledBookshelf {
        BlockId toProtocol(Properties::Facing facing, Properties::Slot_0_occupied slot_0_occupied, Properties::Slot_1_occupied slot_1_occupied, Properties::Slot_2_occupied slot_2_occupied, Properties::Slot_3_occupied slot_3_occupied, Properties::Slot_4_occupied slot_4_occupied, Properties::Slot_5_occupied slot_5_occupied) {
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
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2047;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2048;
                                    }
                                }
                            case Properties::Slot_3_occupied::FALSE:
                                switch (slot_4_occupied) {
                                case Properties::Slot_4_occupied::TRUE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2049;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2050;
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2051;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2052;
                                    }
                                }
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
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2055;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2056;
                                    }
                                }
                            case Properties::Slot_3_occupied::FALSE:
                                switch (slot_4_occupied) {
                                case Properties::Slot_4_occupied::TRUE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2057;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2058;
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2059;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2060;
                                    }
                                }
                            }
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
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2063;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2064;
                                    }
                                }
                            case Properties::Slot_3_occupied::FALSE:
                                switch (slot_4_occupied) {
                                case Properties::Slot_4_occupied::TRUE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2065;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2066;
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2067;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2068;
                                    }
                                }
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
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2071;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2072;
                                    }
                                }
                            case Properties::Slot_3_occupied::FALSE:
                                switch (slot_4_occupied) {
                                case Properties::Slot_4_occupied::TRUE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2073;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2074;
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2075;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2076;
                                    }
                                }
                            }
                        }
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
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2079;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2080;
                                    }
                                }
                            case Properties::Slot_3_occupied::FALSE:
                                switch (slot_4_occupied) {
                                case Properties::Slot_4_occupied::TRUE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2081;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2082;
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2083;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2084;
                                    }
                                }
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
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2087;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2088;
                                    }
                                }
                            case Properties::Slot_3_occupied::FALSE:
                                switch (slot_4_occupied) {
                                case Properties::Slot_4_occupied::TRUE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2089;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2090;
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2091;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2092;
                                    }
                                }
                            }
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
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2095;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2096;
                                    }
                                }
                            case Properties::Slot_3_occupied::FALSE:
                                switch (slot_4_occupied) {
                                case Properties::Slot_4_occupied::TRUE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2097;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2098;
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2099;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2100;
                                    }
                                }
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
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2103;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2104;
                                    }
                                }
                            case Properties::Slot_3_occupied::FALSE:
                                switch (slot_4_occupied) {
                                case Properties::Slot_4_occupied::TRUE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2105;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2106;
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2107;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2108;
                                    }
                                }
                            }
                        }
                    }
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
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2111;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2112;
                                    }
                                }
                            case Properties::Slot_3_occupied::FALSE:
                                switch (slot_4_occupied) {
                                case Properties::Slot_4_occupied::TRUE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2113;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2114;
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2115;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2116;
                                    }
                                }
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
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2119;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2120;
                                    }
                                }
                            case Properties::Slot_3_occupied::FALSE:
                                switch (slot_4_occupied) {
                                case Properties::Slot_4_occupied::TRUE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2121;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2122;
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2123;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2124;
                                    }
                                }
                            }
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
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2127;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2128;
                                    }
                                }
                            case Properties::Slot_3_occupied::FALSE:
                                switch (slot_4_occupied) {
                                case Properties::Slot_4_occupied::TRUE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2129;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2130;
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2131;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2132;
                                    }
                                }
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
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2135;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2136;
                                    }
                                }
                            case Properties::Slot_3_occupied::FALSE:
                                switch (slot_4_occupied) {
                                case Properties::Slot_4_occupied::TRUE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2137;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2138;
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2139;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2140;
                                    }
                                }
                            }
                        }
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
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2143;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2144;
                                    }
                                }
                            case Properties::Slot_3_occupied::FALSE:
                                switch (slot_4_occupied) {
                                case Properties::Slot_4_occupied::TRUE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2145;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2146;
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2147;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2148;
                                    }
                                }
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
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2151;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2152;
                                    }
                                }
                            case Properties::Slot_3_occupied::FALSE:
                                switch (slot_4_occupied) {
                                case Properties::Slot_4_occupied::TRUE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2153;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2154;
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2155;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2156;
                                    }
                                }
                            }
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
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2159;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2160;
                                    }
                                }
                            case Properties::Slot_3_occupied::FALSE:
                                switch (slot_4_occupied) {
                                case Properties::Slot_4_occupied::TRUE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2161;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2162;
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2163;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2164;
                                    }
                                }
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
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2167;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2168;
                                    }
                                }
                            case Properties::Slot_3_occupied::FALSE:
                                switch (slot_4_occupied) {
                                case Properties::Slot_4_occupied::TRUE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2169;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2170;
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2171;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2172;
                                    }
                                }
                            }
                        }
                    }
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
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2175;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2176;
                                    }
                                }
                            case Properties::Slot_3_occupied::FALSE:
                                switch (slot_4_occupied) {
                                case Properties::Slot_4_occupied::TRUE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2177;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2178;
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2179;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2180;
                                    }
                                }
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
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2183;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2184;
                                    }
                                }
                            case Properties::Slot_3_occupied::FALSE:
                                switch (slot_4_occupied) {
                                case Properties::Slot_4_occupied::TRUE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2185;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2186;
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2187;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2188;
                                    }
                                }
                            }
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
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2191;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2192;
                                    }
                                }
                            case Properties::Slot_3_occupied::FALSE:
                                switch (slot_4_occupied) {
                                case Properties::Slot_4_occupied::TRUE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2193;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2194;
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2195;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2196;
                                    }
                                }
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
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2199;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2200;
                                    }
                                }
                            case Properties::Slot_3_occupied::FALSE:
                                switch (slot_4_occupied) {
                                case Properties::Slot_4_occupied::TRUE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2201;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2202;
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2203;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2204;
                                    }
                                }
                            }
                        }
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
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2207;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2208;
                                    }
                                }
                            case Properties::Slot_3_occupied::FALSE:
                                switch (slot_4_occupied) {
                                case Properties::Slot_4_occupied::TRUE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2209;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2210;
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2211;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2212;
                                    }
                                }
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
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2215;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2216;
                                    }
                                }
                            case Properties::Slot_3_occupied::FALSE:
                                switch (slot_4_occupied) {
                                case Properties::Slot_4_occupied::TRUE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2217;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2218;
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2219;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2220;
                                    }
                                }
                            }
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
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2223;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2224;
                                    }
                                }
                            case Properties::Slot_3_occupied::FALSE:
                                switch (slot_4_occupied) {
                                case Properties::Slot_4_occupied::TRUE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2225;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2226;
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2227;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2228;
                                    }
                                }
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
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2231;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2232;
                                    }
                                }
                            case Properties::Slot_3_occupied::FALSE:
                                switch (slot_4_occupied) {
                                case Properties::Slot_4_occupied::TRUE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2233;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2234;
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2235;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2236;
                                    }
                                }
                            }
                        }
                    }
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
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2239;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2240;
                                    }
                                }
                            case Properties::Slot_3_occupied::FALSE:
                                switch (slot_4_occupied) {
                                case Properties::Slot_4_occupied::TRUE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2241;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2242;
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2243;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2244;
                                    }
                                }
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
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2247;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2248;
                                    }
                                }
                            case Properties::Slot_3_occupied::FALSE:
                                switch (slot_4_occupied) {
                                case Properties::Slot_4_occupied::TRUE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2249;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2250;
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2251;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2252;
                                    }
                                }
                            }
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
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2255;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2256;
                                    }
                                }
                            case Properties::Slot_3_occupied::FALSE:
                                switch (slot_4_occupied) {
                                case Properties::Slot_4_occupied::TRUE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2257;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2258;
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2259;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2260;
                                    }
                                }
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
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2263;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2264;
                                    }
                                }
                            case Properties::Slot_3_occupied::FALSE:
                                switch (slot_4_occupied) {
                                case Properties::Slot_4_occupied::TRUE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2265;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2266;
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2267;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2268;
                                    }
                                }
                            }
                        }
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
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2271;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2272;
                                    }
                                }
                            case Properties::Slot_3_occupied::FALSE:
                                switch (slot_4_occupied) {
                                case Properties::Slot_4_occupied::TRUE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2273;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2274;
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2275;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2276;
                                    }
                                }
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
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2279;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2280;
                                    }
                                }
                            case Properties::Slot_3_occupied::FALSE:
                                switch (slot_4_occupied) {
                                case Properties::Slot_4_occupied::TRUE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2281;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2282;
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2283;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2284;
                                    }
                                }
                            }
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
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2287;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2288;
                                    }
                                }
                            case Properties::Slot_3_occupied::FALSE:
                                switch (slot_4_occupied) {
                                case Properties::Slot_4_occupied::TRUE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2289;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2290;
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2291;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2292;
                                    }
                                }
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
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2295;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2296;
                                    }
                                }
                            case Properties::Slot_3_occupied::FALSE:
                                switch (slot_4_occupied) {
                                case Properties::Slot_4_occupied::TRUE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2297;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2298;
                                    }
                                case Properties::Slot_4_occupied::FALSE:
                                    switch (slot_5_occupied) {
                                    case Properties::Slot_5_occupied::TRUE:
                                        return 2299;
                                    case Properties::Slot_5_occupied::FALSE:
                                        return 2300;
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
