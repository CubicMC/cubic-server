#include "RedstoneWire.hpp"
#include <stdexcept>

namespace Blocks {
namespace RedstoneWire {
BlockId toProtocol(Properties::East east, Properties::North north, Properties::Power power, Properties::South south, Properties::West west)
{
    switch (east) {
    case Properties::East::UP:
        switch (north) {
        case Properties::North::UP:
            switch (power) {
            case Properties::Power::ZERO:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 2926;
                    case Properties::West::SIDE:
                        return 2927;
                    case Properties::West::NONE:
                        return 2928;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 2929;
                    case Properties::West::SIDE:
                        return 2930;
                    case Properties::West::NONE:
                        return 2931;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 2932;
                    case Properties::West::SIDE:
                        return 2933;
                    case Properties::West::NONE:
                        return 2934;
                    }
                }
            case Properties::Power::ONE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 2935;
                    case Properties::West::SIDE:
                        return 2936;
                    case Properties::West::NONE:
                        return 2937;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 2938;
                    case Properties::West::SIDE:
                        return 2939;
                    case Properties::West::NONE:
                        return 2940;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 2941;
                    case Properties::West::SIDE:
                        return 2942;
                    case Properties::West::NONE:
                        return 2943;
                    }
                }
            case Properties::Power::TWO:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 2944;
                    case Properties::West::SIDE:
                        return 2945;
                    case Properties::West::NONE:
                        return 2946;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 2947;
                    case Properties::West::SIDE:
                        return 2948;
                    case Properties::West::NONE:
                        return 2949;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 2950;
                    case Properties::West::SIDE:
                        return 2951;
                    case Properties::West::NONE:
                        return 2952;
                    }
                }
            case Properties::Power::THREE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 2953;
                    case Properties::West::SIDE:
                        return 2954;
                    case Properties::West::NONE:
                        return 2955;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 2956;
                    case Properties::West::SIDE:
                        return 2957;
                    case Properties::West::NONE:
                        return 2958;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 2959;
                    case Properties::West::SIDE:
                        return 2960;
                    case Properties::West::NONE:
                        return 2961;
                    }
                }
            case Properties::Power::FOUR:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 2962;
                    case Properties::West::SIDE:
                        return 2963;
                    case Properties::West::NONE:
                        return 2964;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 2965;
                    case Properties::West::SIDE:
                        return 2966;
                    case Properties::West::NONE:
                        return 2967;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 2968;
                    case Properties::West::SIDE:
                        return 2969;
                    case Properties::West::NONE:
                        return 2970;
                    }
                }
            case Properties::Power::FIVE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 2971;
                    case Properties::West::SIDE:
                        return 2972;
                    case Properties::West::NONE:
                        return 2973;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 2974;
                    case Properties::West::SIDE:
                        return 2975;
                    case Properties::West::NONE:
                        return 2976;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 2977;
                    case Properties::West::SIDE:
                        return 2978;
                    case Properties::West::NONE:
                        return 2979;
                    }
                }
            case Properties::Power::SIX:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 2980;
                    case Properties::West::SIDE:
                        return 2981;
                    case Properties::West::NONE:
                        return 2982;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 2983;
                    case Properties::West::SIDE:
                        return 2984;
                    case Properties::West::NONE:
                        return 2985;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 2986;
                    case Properties::West::SIDE:
                        return 2987;
                    case Properties::West::NONE:
                        return 2988;
                    }
                }
            case Properties::Power::SEVEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 2989;
                    case Properties::West::SIDE:
                        return 2990;
                    case Properties::West::NONE:
                        return 2991;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 2992;
                    case Properties::West::SIDE:
                        return 2993;
                    case Properties::West::NONE:
                        return 2994;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 2995;
                    case Properties::West::SIDE:
                        return 2996;
                    case Properties::West::NONE:
                        return 2997;
                    }
                }
            case Properties::Power::EIGHT:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 2998;
                    case Properties::West::SIDE:
                        return 2999;
                    case Properties::West::NONE:
                        return 3000;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3001;
                    case Properties::West::SIDE:
                        return 3002;
                    case Properties::West::NONE:
                        return 3003;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3004;
                    case Properties::West::SIDE:
                        return 3005;
                    case Properties::West::NONE:
                        return 3006;
                    }
                }
            case Properties::Power::NINE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3007;
                    case Properties::West::SIDE:
                        return 3008;
                    case Properties::West::NONE:
                        return 3009;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3010;
                    case Properties::West::SIDE:
                        return 3011;
                    case Properties::West::NONE:
                        return 3012;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3013;
                    case Properties::West::SIDE:
                        return 3014;
                    case Properties::West::NONE:
                        return 3015;
                    }
                }
            case Properties::Power::TEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3016;
                    case Properties::West::SIDE:
                        return 3017;
                    case Properties::West::NONE:
                        return 3018;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3019;
                    case Properties::West::SIDE:
                        return 3020;
                    case Properties::West::NONE:
                        return 3021;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3022;
                    case Properties::West::SIDE:
                        return 3023;
                    case Properties::West::NONE:
                        return 3024;
                    }
                }
            case Properties::Power::ELEVEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3025;
                    case Properties::West::SIDE:
                        return 3026;
                    case Properties::West::NONE:
                        return 3027;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3028;
                    case Properties::West::SIDE:
                        return 3029;
                    case Properties::West::NONE:
                        return 3030;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3031;
                    case Properties::West::SIDE:
                        return 3032;
                    case Properties::West::NONE:
                        return 3033;
                    }
                }
            case Properties::Power::TWELVE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3034;
                    case Properties::West::SIDE:
                        return 3035;
                    case Properties::West::NONE:
                        return 3036;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3037;
                    case Properties::West::SIDE:
                        return 3038;
                    case Properties::West::NONE:
                        return 3039;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3040;
                    case Properties::West::SIDE:
                        return 3041;
                    case Properties::West::NONE:
                        return 3042;
                    }
                }
            case Properties::Power::THIRTEEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3043;
                    case Properties::West::SIDE:
                        return 3044;
                    case Properties::West::NONE:
                        return 3045;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3046;
                    case Properties::West::SIDE:
                        return 3047;
                    case Properties::West::NONE:
                        return 3048;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3049;
                    case Properties::West::SIDE:
                        return 3050;
                    case Properties::West::NONE:
                        return 3051;
                    }
                }
            case Properties::Power::FOURTEEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3052;
                    case Properties::West::SIDE:
                        return 3053;
                    case Properties::West::NONE:
                        return 3054;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3055;
                    case Properties::West::SIDE:
                        return 3056;
                    case Properties::West::NONE:
                        return 3057;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3058;
                    case Properties::West::SIDE:
                        return 3059;
                    case Properties::West::NONE:
                        return 3060;
                    }
                }
            case Properties::Power::FIFTEEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3061;
                    case Properties::West::SIDE:
                        return 3062;
                    case Properties::West::NONE:
                        return 3063;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3064;
                    case Properties::West::SIDE:
                        return 3065;
                    case Properties::West::NONE:
                        return 3066;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3067;
                    case Properties::West::SIDE:
                        return 3068;
                    case Properties::West::NONE:
                        return 3069;
                    }
                }
            }
        case Properties::North::SIDE:
            switch (power) {
            case Properties::Power::ZERO:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3070;
                    case Properties::West::SIDE:
                        return 3071;
                    case Properties::West::NONE:
                        return 3072;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3073;
                    case Properties::West::SIDE:
                        return 3074;
                    case Properties::West::NONE:
                        return 3075;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3076;
                    case Properties::West::SIDE:
                        return 3077;
                    case Properties::West::NONE:
                        return 3078;
                    }
                }
            case Properties::Power::ONE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3079;
                    case Properties::West::SIDE:
                        return 3080;
                    case Properties::West::NONE:
                        return 3081;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3082;
                    case Properties::West::SIDE:
                        return 3083;
                    case Properties::West::NONE:
                        return 3084;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3085;
                    case Properties::West::SIDE:
                        return 3086;
                    case Properties::West::NONE:
                        return 3087;
                    }
                }
            case Properties::Power::TWO:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3088;
                    case Properties::West::SIDE:
                        return 3089;
                    case Properties::West::NONE:
                        return 3090;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3091;
                    case Properties::West::SIDE:
                        return 3092;
                    case Properties::West::NONE:
                        return 3093;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3094;
                    case Properties::West::SIDE:
                        return 3095;
                    case Properties::West::NONE:
                        return 3096;
                    }
                }
            case Properties::Power::THREE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3097;
                    case Properties::West::SIDE:
                        return 3098;
                    case Properties::West::NONE:
                        return 3099;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3100;
                    case Properties::West::SIDE:
                        return 3101;
                    case Properties::West::NONE:
                        return 3102;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3103;
                    case Properties::West::SIDE:
                        return 3104;
                    case Properties::West::NONE:
                        return 3105;
                    }
                }
            case Properties::Power::FOUR:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3106;
                    case Properties::West::SIDE:
                        return 3107;
                    case Properties::West::NONE:
                        return 3108;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3109;
                    case Properties::West::SIDE:
                        return 3110;
                    case Properties::West::NONE:
                        return 3111;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3112;
                    case Properties::West::SIDE:
                        return 3113;
                    case Properties::West::NONE:
                        return 3114;
                    }
                }
            case Properties::Power::FIVE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3115;
                    case Properties::West::SIDE:
                        return 3116;
                    case Properties::West::NONE:
                        return 3117;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3118;
                    case Properties::West::SIDE:
                        return 3119;
                    case Properties::West::NONE:
                        return 3120;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3121;
                    case Properties::West::SIDE:
                        return 3122;
                    case Properties::West::NONE:
                        return 3123;
                    }
                }
            case Properties::Power::SIX:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3124;
                    case Properties::West::SIDE:
                        return 3125;
                    case Properties::West::NONE:
                        return 3126;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3127;
                    case Properties::West::SIDE:
                        return 3128;
                    case Properties::West::NONE:
                        return 3129;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3130;
                    case Properties::West::SIDE:
                        return 3131;
                    case Properties::West::NONE:
                        return 3132;
                    }
                }
            case Properties::Power::SEVEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3133;
                    case Properties::West::SIDE:
                        return 3134;
                    case Properties::West::NONE:
                        return 3135;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3136;
                    case Properties::West::SIDE:
                        return 3137;
                    case Properties::West::NONE:
                        return 3138;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3139;
                    case Properties::West::SIDE:
                        return 3140;
                    case Properties::West::NONE:
                        return 3141;
                    }
                }
            case Properties::Power::EIGHT:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3142;
                    case Properties::West::SIDE:
                        return 3143;
                    case Properties::West::NONE:
                        return 3144;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3145;
                    case Properties::West::SIDE:
                        return 3146;
                    case Properties::West::NONE:
                        return 3147;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3148;
                    case Properties::West::SIDE:
                        return 3149;
                    case Properties::West::NONE:
                        return 3150;
                    }
                }
            case Properties::Power::NINE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3151;
                    case Properties::West::SIDE:
                        return 3152;
                    case Properties::West::NONE:
                        return 3153;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3154;
                    case Properties::West::SIDE:
                        return 3155;
                    case Properties::West::NONE:
                        return 3156;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3157;
                    case Properties::West::SIDE:
                        return 3158;
                    case Properties::West::NONE:
                        return 3159;
                    }
                }
            case Properties::Power::TEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3160;
                    case Properties::West::SIDE:
                        return 3161;
                    case Properties::West::NONE:
                        return 3162;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3163;
                    case Properties::West::SIDE:
                        return 3164;
                    case Properties::West::NONE:
                        return 3165;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3166;
                    case Properties::West::SIDE:
                        return 3167;
                    case Properties::West::NONE:
                        return 3168;
                    }
                }
            case Properties::Power::ELEVEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3169;
                    case Properties::West::SIDE:
                        return 3170;
                    case Properties::West::NONE:
                        return 3171;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3172;
                    case Properties::West::SIDE:
                        return 3173;
                    case Properties::West::NONE:
                        return 3174;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3175;
                    case Properties::West::SIDE:
                        return 3176;
                    case Properties::West::NONE:
                        return 3177;
                    }
                }
            case Properties::Power::TWELVE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3178;
                    case Properties::West::SIDE:
                        return 3179;
                    case Properties::West::NONE:
                        return 3180;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3181;
                    case Properties::West::SIDE:
                        return 3182;
                    case Properties::West::NONE:
                        return 3183;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3184;
                    case Properties::West::SIDE:
                        return 3185;
                    case Properties::West::NONE:
                        return 3186;
                    }
                }
            case Properties::Power::THIRTEEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3187;
                    case Properties::West::SIDE:
                        return 3188;
                    case Properties::West::NONE:
                        return 3189;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3190;
                    case Properties::West::SIDE:
                        return 3191;
                    case Properties::West::NONE:
                        return 3192;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3193;
                    case Properties::West::SIDE:
                        return 3194;
                    case Properties::West::NONE:
                        return 3195;
                    }
                }
            case Properties::Power::FOURTEEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3196;
                    case Properties::West::SIDE:
                        return 3197;
                    case Properties::West::NONE:
                        return 3198;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3199;
                    case Properties::West::SIDE:
                        return 3200;
                    case Properties::West::NONE:
                        return 3201;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3202;
                    case Properties::West::SIDE:
                        return 3203;
                    case Properties::West::NONE:
                        return 3204;
                    }
                }
            case Properties::Power::FIFTEEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3205;
                    case Properties::West::SIDE:
                        return 3206;
                    case Properties::West::NONE:
                        return 3207;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3208;
                    case Properties::West::SIDE:
                        return 3209;
                    case Properties::West::NONE:
                        return 3210;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3211;
                    case Properties::West::SIDE:
                        return 3212;
                    case Properties::West::NONE:
                        return 3213;
                    }
                }
            }
        case Properties::North::NONE:
            switch (power) {
            case Properties::Power::ZERO:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3214;
                    case Properties::West::SIDE:
                        return 3215;
                    case Properties::West::NONE:
                        return 3216;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3217;
                    case Properties::West::SIDE:
                        return 3218;
                    case Properties::West::NONE:
                        return 3219;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3220;
                    case Properties::West::SIDE:
                        return 3221;
                    case Properties::West::NONE:
                        return 3222;
                    }
                }
            case Properties::Power::ONE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3223;
                    case Properties::West::SIDE:
                        return 3224;
                    case Properties::West::NONE:
                        return 3225;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3226;
                    case Properties::West::SIDE:
                        return 3227;
                    case Properties::West::NONE:
                        return 3228;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3229;
                    case Properties::West::SIDE:
                        return 3230;
                    case Properties::West::NONE:
                        return 3231;
                    }
                }
            case Properties::Power::TWO:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3232;
                    case Properties::West::SIDE:
                        return 3233;
                    case Properties::West::NONE:
                        return 3234;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3235;
                    case Properties::West::SIDE:
                        return 3236;
                    case Properties::West::NONE:
                        return 3237;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3238;
                    case Properties::West::SIDE:
                        return 3239;
                    case Properties::West::NONE:
                        return 3240;
                    }
                }
            case Properties::Power::THREE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3241;
                    case Properties::West::SIDE:
                        return 3242;
                    case Properties::West::NONE:
                        return 3243;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3244;
                    case Properties::West::SIDE:
                        return 3245;
                    case Properties::West::NONE:
                        return 3246;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3247;
                    case Properties::West::SIDE:
                        return 3248;
                    case Properties::West::NONE:
                        return 3249;
                    }
                }
            case Properties::Power::FOUR:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3250;
                    case Properties::West::SIDE:
                        return 3251;
                    case Properties::West::NONE:
                        return 3252;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3253;
                    case Properties::West::SIDE:
                        return 3254;
                    case Properties::West::NONE:
                        return 3255;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3256;
                    case Properties::West::SIDE:
                        return 3257;
                    case Properties::West::NONE:
                        return 3258;
                    }
                }
            case Properties::Power::FIVE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3259;
                    case Properties::West::SIDE:
                        return 3260;
                    case Properties::West::NONE:
                        return 3261;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3262;
                    case Properties::West::SIDE:
                        return 3263;
                    case Properties::West::NONE:
                        return 3264;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3265;
                    case Properties::West::SIDE:
                        return 3266;
                    case Properties::West::NONE:
                        return 3267;
                    }
                }
            case Properties::Power::SIX:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3268;
                    case Properties::West::SIDE:
                        return 3269;
                    case Properties::West::NONE:
                        return 3270;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3271;
                    case Properties::West::SIDE:
                        return 3272;
                    case Properties::West::NONE:
                        return 3273;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3274;
                    case Properties::West::SIDE:
                        return 3275;
                    case Properties::West::NONE:
                        return 3276;
                    }
                }
            case Properties::Power::SEVEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3277;
                    case Properties::West::SIDE:
                        return 3278;
                    case Properties::West::NONE:
                        return 3279;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3280;
                    case Properties::West::SIDE:
                        return 3281;
                    case Properties::West::NONE:
                        return 3282;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3283;
                    case Properties::West::SIDE:
                        return 3284;
                    case Properties::West::NONE:
                        return 3285;
                    }
                }
            case Properties::Power::EIGHT:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3286;
                    case Properties::West::SIDE:
                        return 3287;
                    case Properties::West::NONE:
                        return 3288;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3289;
                    case Properties::West::SIDE:
                        return 3290;
                    case Properties::West::NONE:
                        return 3291;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3292;
                    case Properties::West::SIDE:
                        return 3293;
                    case Properties::West::NONE:
                        return 3294;
                    }
                }
            case Properties::Power::NINE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3295;
                    case Properties::West::SIDE:
                        return 3296;
                    case Properties::West::NONE:
                        return 3297;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3298;
                    case Properties::West::SIDE:
                        return 3299;
                    case Properties::West::NONE:
                        return 3300;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3301;
                    case Properties::West::SIDE:
                        return 3302;
                    case Properties::West::NONE:
                        return 3303;
                    }
                }
            case Properties::Power::TEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3304;
                    case Properties::West::SIDE:
                        return 3305;
                    case Properties::West::NONE:
                        return 3306;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3307;
                    case Properties::West::SIDE:
                        return 3308;
                    case Properties::West::NONE:
                        return 3309;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3310;
                    case Properties::West::SIDE:
                        return 3311;
                    case Properties::West::NONE:
                        return 3312;
                    }
                }
            case Properties::Power::ELEVEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3313;
                    case Properties::West::SIDE:
                        return 3314;
                    case Properties::West::NONE:
                        return 3315;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3316;
                    case Properties::West::SIDE:
                        return 3317;
                    case Properties::West::NONE:
                        return 3318;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3319;
                    case Properties::West::SIDE:
                        return 3320;
                    case Properties::West::NONE:
                        return 3321;
                    }
                }
            case Properties::Power::TWELVE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3322;
                    case Properties::West::SIDE:
                        return 3323;
                    case Properties::West::NONE:
                        return 3324;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3325;
                    case Properties::West::SIDE:
                        return 3326;
                    case Properties::West::NONE:
                        return 3327;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3328;
                    case Properties::West::SIDE:
                        return 3329;
                    case Properties::West::NONE:
                        return 3330;
                    }
                }
            case Properties::Power::THIRTEEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3331;
                    case Properties::West::SIDE:
                        return 3332;
                    case Properties::West::NONE:
                        return 3333;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3334;
                    case Properties::West::SIDE:
                        return 3335;
                    case Properties::West::NONE:
                        return 3336;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3337;
                    case Properties::West::SIDE:
                        return 3338;
                    case Properties::West::NONE:
                        return 3339;
                    }
                }
            case Properties::Power::FOURTEEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3340;
                    case Properties::West::SIDE:
                        return 3341;
                    case Properties::West::NONE:
                        return 3342;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3343;
                    case Properties::West::SIDE:
                        return 3344;
                    case Properties::West::NONE:
                        return 3345;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3346;
                    case Properties::West::SIDE:
                        return 3347;
                    case Properties::West::NONE:
                        return 3348;
                    }
                }
            case Properties::Power::FIFTEEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3349;
                    case Properties::West::SIDE:
                        return 3350;
                    case Properties::West::NONE:
                        return 3351;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3352;
                    case Properties::West::SIDE:
                        return 3353;
                    case Properties::West::NONE:
                        return 3354;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3355;
                    case Properties::West::SIDE:
                        return 3356;
                    case Properties::West::NONE:
                        return 3357;
                    }
                }
            }
        }
    case Properties::East::SIDE:
        switch (north) {
        case Properties::North::UP:
            switch (power) {
            case Properties::Power::ZERO:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3358;
                    case Properties::West::SIDE:
                        return 3359;
                    case Properties::West::NONE:
                        return 3360;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3361;
                    case Properties::West::SIDE:
                        return 3362;
                    case Properties::West::NONE:
                        return 3363;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3364;
                    case Properties::West::SIDE:
                        return 3365;
                    case Properties::West::NONE:
                        return 3366;
                    }
                }
            case Properties::Power::ONE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3367;
                    case Properties::West::SIDE:
                        return 3368;
                    case Properties::West::NONE:
                        return 3369;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3370;
                    case Properties::West::SIDE:
                        return 3371;
                    case Properties::West::NONE:
                        return 3372;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3373;
                    case Properties::West::SIDE:
                        return 3374;
                    case Properties::West::NONE:
                        return 3375;
                    }
                }
            case Properties::Power::TWO:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3376;
                    case Properties::West::SIDE:
                        return 3377;
                    case Properties::West::NONE:
                        return 3378;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3379;
                    case Properties::West::SIDE:
                        return 3380;
                    case Properties::West::NONE:
                        return 3381;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3382;
                    case Properties::West::SIDE:
                        return 3383;
                    case Properties::West::NONE:
                        return 3384;
                    }
                }
            case Properties::Power::THREE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3385;
                    case Properties::West::SIDE:
                        return 3386;
                    case Properties::West::NONE:
                        return 3387;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3388;
                    case Properties::West::SIDE:
                        return 3389;
                    case Properties::West::NONE:
                        return 3390;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3391;
                    case Properties::West::SIDE:
                        return 3392;
                    case Properties::West::NONE:
                        return 3393;
                    }
                }
            case Properties::Power::FOUR:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3394;
                    case Properties::West::SIDE:
                        return 3395;
                    case Properties::West::NONE:
                        return 3396;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3397;
                    case Properties::West::SIDE:
                        return 3398;
                    case Properties::West::NONE:
                        return 3399;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3400;
                    case Properties::West::SIDE:
                        return 3401;
                    case Properties::West::NONE:
                        return 3402;
                    }
                }
            case Properties::Power::FIVE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3403;
                    case Properties::West::SIDE:
                        return 3404;
                    case Properties::West::NONE:
                        return 3405;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3406;
                    case Properties::West::SIDE:
                        return 3407;
                    case Properties::West::NONE:
                        return 3408;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3409;
                    case Properties::West::SIDE:
                        return 3410;
                    case Properties::West::NONE:
                        return 3411;
                    }
                }
            case Properties::Power::SIX:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3412;
                    case Properties::West::SIDE:
                        return 3413;
                    case Properties::West::NONE:
                        return 3414;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3415;
                    case Properties::West::SIDE:
                        return 3416;
                    case Properties::West::NONE:
                        return 3417;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3418;
                    case Properties::West::SIDE:
                        return 3419;
                    case Properties::West::NONE:
                        return 3420;
                    }
                }
            case Properties::Power::SEVEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3421;
                    case Properties::West::SIDE:
                        return 3422;
                    case Properties::West::NONE:
                        return 3423;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3424;
                    case Properties::West::SIDE:
                        return 3425;
                    case Properties::West::NONE:
                        return 3426;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3427;
                    case Properties::West::SIDE:
                        return 3428;
                    case Properties::West::NONE:
                        return 3429;
                    }
                }
            case Properties::Power::EIGHT:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3430;
                    case Properties::West::SIDE:
                        return 3431;
                    case Properties::West::NONE:
                        return 3432;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3433;
                    case Properties::West::SIDE:
                        return 3434;
                    case Properties::West::NONE:
                        return 3435;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3436;
                    case Properties::West::SIDE:
                        return 3437;
                    case Properties::West::NONE:
                        return 3438;
                    }
                }
            case Properties::Power::NINE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3439;
                    case Properties::West::SIDE:
                        return 3440;
                    case Properties::West::NONE:
                        return 3441;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3442;
                    case Properties::West::SIDE:
                        return 3443;
                    case Properties::West::NONE:
                        return 3444;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3445;
                    case Properties::West::SIDE:
                        return 3446;
                    case Properties::West::NONE:
                        return 3447;
                    }
                }
            case Properties::Power::TEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3448;
                    case Properties::West::SIDE:
                        return 3449;
                    case Properties::West::NONE:
                        return 3450;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3451;
                    case Properties::West::SIDE:
                        return 3452;
                    case Properties::West::NONE:
                        return 3453;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3454;
                    case Properties::West::SIDE:
                        return 3455;
                    case Properties::West::NONE:
                        return 3456;
                    }
                }
            case Properties::Power::ELEVEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3457;
                    case Properties::West::SIDE:
                        return 3458;
                    case Properties::West::NONE:
                        return 3459;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3460;
                    case Properties::West::SIDE:
                        return 3461;
                    case Properties::West::NONE:
                        return 3462;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3463;
                    case Properties::West::SIDE:
                        return 3464;
                    case Properties::West::NONE:
                        return 3465;
                    }
                }
            case Properties::Power::TWELVE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3466;
                    case Properties::West::SIDE:
                        return 3467;
                    case Properties::West::NONE:
                        return 3468;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3469;
                    case Properties::West::SIDE:
                        return 3470;
                    case Properties::West::NONE:
                        return 3471;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3472;
                    case Properties::West::SIDE:
                        return 3473;
                    case Properties::West::NONE:
                        return 3474;
                    }
                }
            case Properties::Power::THIRTEEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3475;
                    case Properties::West::SIDE:
                        return 3476;
                    case Properties::West::NONE:
                        return 3477;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3478;
                    case Properties::West::SIDE:
                        return 3479;
                    case Properties::West::NONE:
                        return 3480;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3481;
                    case Properties::West::SIDE:
                        return 3482;
                    case Properties::West::NONE:
                        return 3483;
                    }
                }
            case Properties::Power::FOURTEEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3484;
                    case Properties::West::SIDE:
                        return 3485;
                    case Properties::West::NONE:
                        return 3486;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3487;
                    case Properties::West::SIDE:
                        return 3488;
                    case Properties::West::NONE:
                        return 3489;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3490;
                    case Properties::West::SIDE:
                        return 3491;
                    case Properties::West::NONE:
                        return 3492;
                    }
                }
            case Properties::Power::FIFTEEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3493;
                    case Properties::West::SIDE:
                        return 3494;
                    case Properties::West::NONE:
                        return 3495;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3496;
                    case Properties::West::SIDE:
                        return 3497;
                    case Properties::West::NONE:
                        return 3498;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3499;
                    case Properties::West::SIDE:
                        return 3500;
                    case Properties::West::NONE:
                        return 3501;
                    }
                }
            }
        case Properties::North::SIDE:
            switch (power) {
            case Properties::Power::ZERO:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3502;
                    case Properties::West::SIDE:
                        return 3503;
                    case Properties::West::NONE:
                        return 3504;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3505;
                    case Properties::West::SIDE:
                        return 3506;
                    case Properties::West::NONE:
                        return 3507;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3508;
                    case Properties::West::SIDE:
                        return 3509;
                    case Properties::West::NONE:
                        return 3510;
                    }
                }
            case Properties::Power::ONE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3511;
                    case Properties::West::SIDE:
                        return 3512;
                    case Properties::West::NONE:
                        return 3513;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3514;
                    case Properties::West::SIDE:
                        return 3515;
                    case Properties::West::NONE:
                        return 3516;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3517;
                    case Properties::West::SIDE:
                        return 3518;
                    case Properties::West::NONE:
                        return 3519;
                    }
                }
            case Properties::Power::TWO:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3520;
                    case Properties::West::SIDE:
                        return 3521;
                    case Properties::West::NONE:
                        return 3522;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3523;
                    case Properties::West::SIDE:
                        return 3524;
                    case Properties::West::NONE:
                        return 3525;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3526;
                    case Properties::West::SIDE:
                        return 3527;
                    case Properties::West::NONE:
                        return 3528;
                    }
                }
            case Properties::Power::THREE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3529;
                    case Properties::West::SIDE:
                        return 3530;
                    case Properties::West::NONE:
                        return 3531;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3532;
                    case Properties::West::SIDE:
                        return 3533;
                    case Properties::West::NONE:
                        return 3534;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3535;
                    case Properties::West::SIDE:
                        return 3536;
                    case Properties::West::NONE:
                        return 3537;
                    }
                }
            case Properties::Power::FOUR:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3538;
                    case Properties::West::SIDE:
                        return 3539;
                    case Properties::West::NONE:
                        return 3540;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3541;
                    case Properties::West::SIDE:
                        return 3542;
                    case Properties::West::NONE:
                        return 3543;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3544;
                    case Properties::West::SIDE:
                        return 3545;
                    case Properties::West::NONE:
                        return 3546;
                    }
                }
            case Properties::Power::FIVE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3547;
                    case Properties::West::SIDE:
                        return 3548;
                    case Properties::West::NONE:
                        return 3549;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3550;
                    case Properties::West::SIDE:
                        return 3551;
                    case Properties::West::NONE:
                        return 3552;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3553;
                    case Properties::West::SIDE:
                        return 3554;
                    case Properties::West::NONE:
                        return 3555;
                    }
                }
            case Properties::Power::SIX:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3556;
                    case Properties::West::SIDE:
                        return 3557;
                    case Properties::West::NONE:
                        return 3558;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3559;
                    case Properties::West::SIDE:
                        return 3560;
                    case Properties::West::NONE:
                        return 3561;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3562;
                    case Properties::West::SIDE:
                        return 3563;
                    case Properties::West::NONE:
                        return 3564;
                    }
                }
            case Properties::Power::SEVEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3565;
                    case Properties::West::SIDE:
                        return 3566;
                    case Properties::West::NONE:
                        return 3567;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3568;
                    case Properties::West::SIDE:
                        return 3569;
                    case Properties::West::NONE:
                        return 3570;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3571;
                    case Properties::West::SIDE:
                        return 3572;
                    case Properties::West::NONE:
                        return 3573;
                    }
                }
            case Properties::Power::EIGHT:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3574;
                    case Properties::West::SIDE:
                        return 3575;
                    case Properties::West::NONE:
                        return 3576;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3577;
                    case Properties::West::SIDE:
                        return 3578;
                    case Properties::West::NONE:
                        return 3579;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3580;
                    case Properties::West::SIDE:
                        return 3581;
                    case Properties::West::NONE:
                        return 3582;
                    }
                }
            case Properties::Power::NINE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3583;
                    case Properties::West::SIDE:
                        return 3584;
                    case Properties::West::NONE:
                        return 3585;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3586;
                    case Properties::West::SIDE:
                        return 3587;
                    case Properties::West::NONE:
                        return 3588;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3589;
                    case Properties::West::SIDE:
                        return 3590;
                    case Properties::West::NONE:
                        return 3591;
                    }
                }
            case Properties::Power::TEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3592;
                    case Properties::West::SIDE:
                        return 3593;
                    case Properties::West::NONE:
                        return 3594;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3595;
                    case Properties::West::SIDE:
                        return 3596;
                    case Properties::West::NONE:
                        return 3597;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3598;
                    case Properties::West::SIDE:
                        return 3599;
                    case Properties::West::NONE:
                        return 3600;
                    }
                }
            case Properties::Power::ELEVEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3601;
                    case Properties::West::SIDE:
                        return 3602;
                    case Properties::West::NONE:
                        return 3603;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3604;
                    case Properties::West::SIDE:
                        return 3605;
                    case Properties::West::NONE:
                        return 3606;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3607;
                    case Properties::West::SIDE:
                        return 3608;
                    case Properties::West::NONE:
                        return 3609;
                    }
                }
            case Properties::Power::TWELVE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3610;
                    case Properties::West::SIDE:
                        return 3611;
                    case Properties::West::NONE:
                        return 3612;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3613;
                    case Properties::West::SIDE:
                        return 3614;
                    case Properties::West::NONE:
                        return 3615;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3616;
                    case Properties::West::SIDE:
                        return 3617;
                    case Properties::West::NONE:
                        return 3618;
                    }
                }
            case Properties::Power::THIRTEEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3619;
                    case Properties::West::SIDE:
                        return 3620;
                    case Properties::West::NONE:
                        return 3621;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3622;
                    case Properties::West::SIDE:
                        return 3623;
                    case Properties::West::NONE:
                        return 3624;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3625;
                    case Properties::West::SIDE:
                        return 3626;
                    case Properties::West::NONE:
                        return 3627;
                    }
                }
            case Properties::Power::FOURTEEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3628;
                    case Properties::West::SIDE:
                        return 3629;
                    case Properties::West::NONE:
                        return 3630;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3631;
                    case Properties::West::SIDE:
                        return 3632;
                    case Properties::West::NONE:
                        return 3633;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3634;
                    case Properties::West::SIDE:
                        return 3635;
                    case Properties::West::NONE:
                        return 3636;
                    }
                }
            case Properties::Power::FIFTEEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3637;
                    case Properties::West::SIDE:
                        return 3638;
                    case Properties::West::NONE:
                        return 3639;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3640;
                    case Properties::West::SIDE:
                        return 3641;
                    case Properties::West::NONE:
                        return 3642;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3643;
                    case Properties::West::SIDE:
                        return 3644;
                    case Properties::West::NONE:
                        return 3645;
                    }
                }
            }
        case Properties::North::NONE:
            switch (power) {
            case Properties::Power::ZERO:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3646;
                    case Properties::West::SIDE:
                        return 3647;
                    case Properties::West::NONE:
                        return 3648;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3649;
                    case Properties::West::SIDE:
                        return 3650;
                    case Properties::West::NONE:
                        return 3651;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3652;
                    case Properties::West::SIDE:
                        return 3653;
                    case Properties::West::NONE:
                        return 3654;
                    }
                }
            case Properties::Power::ONE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3655;
                    case Properties::West::SIDE:
                        return 3656;
                    case Properties::West::NONE:
                        return 3657;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3658;
                    case Properties::West::SIDE:
                        return 3659;
                    case Properties::West::NONE:
                        return 3660;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3661;
                    case Properties::West::SIDE:
                        return 3662;
                    case Properties::West::NONE:
                        return 3663;
                    }
                }
            case Properties::Power::TWO:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3664;
                    case Properties::West::SIDE:
                        return 3665;
                    case Properties::West::NONE:
                        return 3666;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3667;
                    case Properties::West::SIDE:
                        return 3668;
                    case Properties::West::NONE:
                        return 3669;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3670;
                    case Properties::West::SIDE:
                        return 3671;
                    case Properties::West::NONE:
                        return 3672;
                    }
                }
            case Properties::Power::THREE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3673;
                    case Properties::West::SIDE:
                        return 3674;
                    case Properties::West::NONE:
                        return 3675;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3676;
                    case Properties::West::SIDE:
                        return 3677;
                    case Properties::West::NONE:
                        return 3678;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3679;
                    case Properties::West::SIDE:
                        return 3680;
                    case Properties::West::NONE:
                        return 3681;
                    }
                }
            case Properties::Power::FOUR:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3682;
                    case Properties::West::SIDE:
                        return 3683;
                    case Properties::West::NONE:
                        return 3684;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3685;
                    case Properties::West::SIDE:
                        return 3686;
                    case Properties::West::NONE:
                        return 3687;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3688;
                    case Properties::West::SIDE:
                        return 3689;
                    case Properties::West::NONE:
                        return 3690;
                    }
                }
            case Properties::Power::FIVE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3691;
                    case Properties::West::SIDE:
                        return 3692;
                    case Properties::West::NONE:
                        return 3693;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3694;
                    case Properties::West::SIDE:
                        return 3695;
                    case Properties::West::NONE:
                        return 3696;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3697;
                    case Properties::West::SIDE:
                        return 3698;
                    case Properties::West::NONE:
                        return 3699;
                    }
                }
            case Properties::Power::SIX:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3700;
                    case Properties::West::SIDE:
                        return 3701;
                    case Properties::West::NONE:
                        return 3702;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3703;
                    case Properties::West::SIDE:
                        return 3704;
                    case Properties::West::NONE:
                        return 3705;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3706;
                    case Properties::West::SIDE:
                        return 3707;
                    case Properties::West::NONE:
                        return 3708;
                    }
                }
            case Properties::Power::SEVEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3709;
                    case Properties::West::SIDE:
                        return 3710;
                    case Properties::West::NONE:
                        return 3711;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3712;
                    case Properties::West::SIDE:
                        return 3713;
                    case Properties::West::NONE:
                        return 3714;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3715;
                    case Properties::West::SIDE:
                        return 3716;
                    case Properties::West::NONE:
                        return 3717;
                    }
                }
            case Properties::Power::EIGHT:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3718;
                    case Properties::West::SIDE:
                        return 3719;
                    case Properties::West::NONE:
                        return 3720;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3721;
                    case Properties::West::SIDE:
                        return 3722;
                    case Properties::West::NONE:
                        return 3723;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3724;
                    case Properties::West::SIDE:
                        return 3725;
                    case Properties::West::NONE:
                        return 3726;
                    }
                }
            case Properties::Power::NINE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3727;
                    case Properties::West::SIDE:
                        return 3728;
                    case Properties::West::NONE:
                        return 3729;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3730;
                    case Properties::West::SIDE:
                        return 3731;
                    case Properties::West::NONE:
                        return 3732;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3733;
                    case Properties::West::SIDE:
                        return 3734;
                    case Properties::West::NONE:
                        return 3735;
                    }
                }
            case Properties::Power::TEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3736;
                    case Properties::West::SIDE:
                        return 3737;
                    case Properties::West::NONE:
                        return 3738;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3739;
                    case Properties::West::SIDE:
                        return 3740;
                    case Properties::West::NONE:
                        return 3741;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3742;
                    case Properties::West::SIDE:
                        return 3743;
                    case Properties::West::NONE:
                        return 3744;
                    }
                }
            case Properties::Power::ELEVEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3745;
                    case Properties::West::SIDE:
                        return 3746;
                    case Properties::West::NONE:
                        return 3747;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3748;
                    case Properties::West::SIDE:
                        return 3749;
                    case Properties::West::NONE:
                        return 3750;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3751;
                    case Properties::West::SIDE:
                        return 3752;
                    case Properties::West::NONE:
                        return 3753;
                    }
                }
            case Properties::Power::TWELVE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3754;
                    case Properties::West::SIDE:
                        return 3755;
                    case Properties::West::NONE:
                        return 3756;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3757;
                    case Properties::West::SIDE:
                        return 3758;
                    case Properties::West::NONE:
                        return 3759;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3760;
                    case Properties::West::SIDE:
                        return 3761;
                    case Properties::West::NONE:
                        return 3762;
                    }
                }
            case Properties::Power::THIRTEEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3763;
                    case Properties::West::SIDE:
                        return 3764;
                    case Properties::West::NONE:
                        return 3765;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3766;
                    case Properties::West::SIDE:
                        return 3767;
                    case Properties::West::NONE:
                        return 3768;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3769;
                    case Properties::West::SIDE:
                        return 3770;
                    case Properties::West::NONE:
                        return 3771;
                    }
                }
            case Properties::Power::FOURTEEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3772;
                    case Properties::West::SIDE:
                        return 3773;
                    case Properties::West::NONE:
                        return 3774;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3775;
                    case Properties::West::SIDE:
                        return 3776;
                    case Properties::West::NONE:
                        return 3777;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3778;
                    case Properties::West::SIDE:
                        return 3779;
                    case Properties::West::NONE:
                        return 3780;
                    }
                }
            case Properties::Power::FIFTEEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3781;
                    case Properties::West::SIDE:
                        return 3782;
                    case Properties::West::NONE:
                        return 3783;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3784;
                    case Properties::West::SIDE:
                        return 3785;
                    case Properties::West::NONE:
                        return 3786;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3787;
                    case Properties::West::SIDE:
                        return 3788;
                    case Properties::West::NONE:
                        return 3789;
                    }
                }
            }
        }
    case Properties::East::NONE:
        switch (north) {
        case Properties::North::UP:
            switch (power) {
            case Properties::Power::ZERO:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3790;
                    case Properties::West::SIDE:
                        return 3791;
                    case Properties::West::NONE:
                        return 3792;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3793;
                    case Properties::West::SIDE:
                        return 3794;
                    case Properties::West::NONE:
                        return 3795;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3796;
                    case Properties::West::SIDE:
                        return 3797;
                    case Properties::West::NONE:
                        return 3798;
                    }
                }
            case Properties::Power::ONE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3799;
                    case Properties::West::SIDE:
                        return 3800;
                    case Properties::West::NONE:
                        return 3801;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3802;
                    case Properties::West::SIDE:
                        return 3803;
                    case Properties::West::NONE:
                        return 3804;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3805;
                    case Properties::West::SIDE:
                        return 3806;
                    case Properties::West::NONE:
                        return 3807;
                    }
                }
            case Properties::Power::TWO:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3808;
                    case Properties::West::SIDE:
                        return 3809;
                    case Properties::West::NONE:
                        return 3810;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3811;
                    case Properties::West::SIDE:
                        return 3812;
                    case Properties::West::NONE:
                        return 3813;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3814;
                    case Properties::West::SIDE:
                        return 3815;
                    case Properties::West::NONE:
                        return 3816;
                    }
                }
            case Properties::Power::THREE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3817;
                    case Properties::West::SIDE:
                        return 3818;
                    case Properties::West::NONE:
                        return 3819;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3820;
                    case Properties::West::SIDE:
                        return 3821;
                    case Properties::West::NONE:
                        return 3822;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3823;
                    case Properties::West::SIDE:
                        return 3824;
                    case Properties::West::NONE:
                        return 3825;
                    }
                }
            case Properties::Power::FOUR:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3826;
                    case Properties::West::SIDE:
                        return 3827;
                    case Properties::West::NONE:
                        return 3828;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3829;
                    case Properties::West::SIDE:
                        return 3830;
                    case Properties::West::NONE:
                        return 3831;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3832;
                    case Properties::West::SIDE:
                        return 3833;
                    case Properties::West::NONE:
                        return 3834;
                    }
                }
            case Properties::Power::FIVE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3835;
                    case Properties::West::SIDE:
                        return 3836;
                    case Properties::West::NONE:
                        return 3837;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3838;
                    case Properties::West::SIDE:
                        return 3839;
                    case Properties::West::NONE:
                        return 3840;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3841;
                    case Properties::West::SIDE:
                        return 3842;
                    case Properties::West::NONE:
                        return 3843;
                    }
                }
            case Properties::Power::SIX:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3844;
                    case Properties::West::SIDE:
                        return 3845;
                    case Properties::West::NONE:
                        return 3846;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3847;
                    case Properties::West::SIDE:
                        return 3848;
                    case Properties::West::NONE:
                        return 3849;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3850;
                    case Properties::West::SIDE:
                        return 3851;
                    case Properties::West::NONE:
                        return 3852;
                    }
                }
            case Properties::Power::SEVEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3853;
                    case Properties::West::SIDE:
                        return 3854;
                    case Properties::West::NONE:
                        return 3855;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3856;
                    case Properties::West::SIDE:
                        return 3857;
                    case Properties::West::NONE:
                        return 3858;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3859;
                    case Properties::West::SIDE:
                        return 3860;
                    case Properties::West::NONE:
                        return 3861;
                    }
                }
            case Properties::Power::EIGHT:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3862;
                    case Properties::West::SIDE:
                        return 3863;
                    case Properties::West::NONE:
                        return 3864;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3865;
                    case Properties::West::SIDE:
                        return 3866;
                    case Properties::West::NONE:
                        return 3867;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3868;
                    case Properties::West::SIDE:
                        return 3869;
                    case Properties::West::NONE:
                        return 3870;
                    }
                }
            case Properties::Power::NINE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3871;
                    case Properties::West::SIDE:
                        return 3872;
                    case Properties::West::NONE:
                        return 3873;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3874;
                    case Properties::West::SIDE:
                        return 3875;
                    case Properties::West::NONE:
                        return 3876;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3877;
                    case Properties::West::SIDE:
                        return 3878;
                    case Properties::West::NONE:
                        return 3879;
                    }
                }
            case Properties::Power::TEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3880;
                    case Properties::West::SIDE:
                        return 3881;
                    case Properties::West::NONE:
                        return 3882;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3883;
                    case Properties::West::SIDE:
                        return 3884;
                    case Properties::West::NONE:
                        return 3885;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3886;
                    case Properties::West::SIDE:
                        return 3887;
                    case Properties::West::NONE:
                        return 3888;
                    }
                }
            case Properties::Power::ELEVEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3889;
                    case Properties::West::SIDE:
                        return 3890;
                    case Properties::West::NONE:
                        return 3891;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3892;
                    case Properties::West::SIDE:
                        return 3893;
                    case Properties::West::NONE:
                        return 3894;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3895;
                    case Properties::West::SIDE:
                        return 3896;
                    case Properties::West::NONE:
                        return 3897;
                    }
                }
            case Properties::Power::TWELVE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3898;
                    case Properties::West::SIDE:
                        return 3899;
                    case Properties::West::NONE:
                        return 3900;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3901;
                    case Properties::West::SIDE:
                        return 3902;
                    case Properties::West::NONE:
                        return 3903;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3904;
                    case Properties::West::SIDE:
                        return 3905;
                    case Properties::West::NONE:
                        return 3906;
                    }
                }
            case Properties::Power::THIRTEEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3907;
                    case Properties::West::SIDE:
                        return 3908;
                    case Properties::West::NONE:
                        return 3909;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3910;
                    case Properties::West::SIDE:
                        return 3911;
                    case Properties::West::NONE:
                        return 3912;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3913;
                    case Properties::West::SIDE:
                        return 3914;
                    case Properties::West::NONE:
                        return 3915;
                    }
                }
            case Properties::Power::FOURTEEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3916;
                    case Properties::West::SIDE:
                        return 3917;
                    case Properties::West::NONE:
                        return 3918;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3919;
                    case Properties::West::SIDE:
                        return 3920;
                    case Properties::West::NONE:
                        return 3921;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3922;
                    case Properties::West::SIDE:
                        return 3923;
                    case Properties::West::NONE:
                        return 3924;
                    }
                }
            case Properties::Power::FIFTEEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3925;
                    case Properties::West::SIDE:
                        return 3926;
                    case Properties::West::NONE:
                        return 3927;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3928;
                    case Properties::West::SIDE:
                        return 3929;
                    case Properties::West::NONE:
                        return 3930;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3931;
                    case Properties::West::SIDE:
                        return 3932;
                    case Properties::West::NONE:
                        return 3933;
                    }
                }
            }
        case Properties::North::SIDE:
            switch (power) {
            case Properties::Power::ZERO:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3934;
                    case Properties::West::SIDE:
                        return 3935;
                    case Properties::West::NONE:
                        return 3936;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3937;
                    case Properties::West::SIDE:
                        return 3938;
                    case Properties::West::NONE:
                        return 3939;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3940;
                    case Properties::West::SIDE:
                        return 3941;
                    case Properties::West::NONE:
                        return 3942;
                    }
                }
            case Properties::Power::ONE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3943;
                    case Properties::West::SIDE:
                        return 3944;
                    case Properties::West::NONE:
                        return 3945;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3946;
                    case Properties::West::SIDE:
                        return 3947;
                    case Properties::West::NONE:
                        return 3948;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3949;
                    case Properties::West::SIDE:
                        return 3950;
                    case Properties::West::NONE:
                        return 3951;
                    }
                }
            case Properties::Power::TWO:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3952;
                    case Properties::West::SIDE:
                        return 3953;
                    case Properties::West::NONE:
                        return 3954;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3955;
                    case Properties::West::SIDE:
                        return 3956;
                    case Properties::West::NONE:
                        return 3957;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3958;
                    case Properties::West::SIDE:
                        return 3959;
                    case Properties::West::NONE:
                        return 3960;
                    }
                }
            case Properties::Power::THREE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3961;
                    case Properties::West::SIDE:
                        return 3962;
                    case Properties::West::NONE:
                        return 3963;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3964;
                    case Properties::West::SIDE:
                        return 3965;
                    case Properties::West::NONE:
                        return 3966;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3967;
                    case Properties::West::SIDE:
                        return 3968;
                    case Properties::West::NONE:
                        return 3969;
                    }
                }
            case Properties::Power::FOUR:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3970;
                    case Properties::West::SIDE:
                        return 3971;
                    case Properties::West::NONE:
                        return 3972;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3973;
                    case Properties::West::SIDE:
                        return 3974;
                    case Properties::West::NONE:
                        return 3975;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3976;
                    case Properties::West::SIDE:
                        return 3977;
                    case Properties::West::NONE:
                        return 3978;
                    }
                }
            case Properties::Power::FIVE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3979;
                    case Properties::West::SIDE:
                        return 3980;
                    case Properties::West::NONE:
                        return 3981;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3982;
                    case Properties::West::SIDE:
                        return 3983;
                    case Properties::West::NONE:
                        return 3984;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3985;
                    case Properties::West::SIDE:
                        return 3986;
                    case Properties::West::NONE:
                        return 3987;
                    }
                }
            case Properties::Power::SIX:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3988;
                    case Properties::West::SIDE:
                        return 3989;
                    case Properties::West::NONE:
                        return 3990;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3991;
                    case Properties::West::SIDE:
                        return 3992;
                    case Properties::West::NONE:
                        return 3993;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 3994;
                    case Properties::West::SIDE:
                        return 3995;
                    case Properties::West::NONE:
                        return 3996;
                    }
                }
            case Properties::Power::SEVEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 3997;
                    case Properties::West::SIDE:
                        return 3998;
                    case Properties::West::NONE:
                        return 3999;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4000;
                    case Properties::West::SIDE:
                        return 4001;
                    case Properties::West::NONE:
                        return 4002;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4003;
                    case Properties::West::SIDE:
                        return 4004;
                    case Properties::West::NONE:
                        return 4005;
                    }
                }
            case Properties::Power::EIGHT:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 4006;
                    case Properties::West::SIDE:
                        return 4007;
                    case Properties::West::NONE:
                        return 4008;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4009;
                    case Properties::West::SIDE:
                        return 4010;
                    case Properties::West::NONE:
                        return 4011;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4012;
                    case Properties::West::SIDE:
                        return 4013;
                    case Properties::West::NONE:
                        return 4014;
                    }
                }
            case Properties::Power::NINE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 4015;
                    case Properties::West::SIDE:
                        return 4016;
                    case Properties::West::NONE:
                        return 4017;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4018;
                    case Properties::West::SIDE:
                        return 4019;
                    case Properties::West::NONE:
                        return 4020;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4021;
                    case Properties::West::SIDE:
                        return 4022;
                    case Properties::West::NONE:
                        return 4023;
                    }
                }
            case Properties::Power::TEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 4024;
                    case Properties::West::SIDE:
                        return 4025;
                    case Properties::West::NONE:
                        return 4026;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4027;
                    case Properties::West::SIDE:
                        return 4028;
                    case Properties::West::NONE:
                        return 4029;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4030;
                    case Properties::West::SIDE:
                        return 4031;
                    case Properties::West::NONE:
                        return 4032;
                    }
                }
            case Properties::Power::ELEVEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 4033;
                    case Properties::West::SIDE:
                        return 4034;
                    case Properties::West::NONE:
                        return 4035;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4036;
                    case Properties::West::SIDE:
                        return 4037;
                    case Properties::West::NONE:
                        return 4038;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4039;
                    case Properties::West::SIDE:
                        return 4040;
                    case Properties::West::NONE:
                        return 4041;
                    }
                }
            case Properties::Power::TWELVE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 4042;
                    case Properties::West::SIDE:
                        return 4043;
                    case Properties::West::NONE:
                        return 4044;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4045;
                    case Properties::West::SIDE:
                        return 4046;
                    case Properties::West::NONE:
                        return 4047;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4048;
                    case Properties::West::SIDE:
                        return 4049;
                    case Properties::West::NONE:
                        return 4050;
                    }
                }
            case Properties::Power::THIRTEEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 4051;
                    case Properties::West::SIDE:
                        return 4052;
                    case Properties::West::NONE:
                        return 4053;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4054;
                    case Properties::West::SIDE:
                        return 4055;
                    case Properties::West::NONE:
                        return 4056;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4057;
                    case Properties::West::SIDE:
                        return 4058;
                    case Properties::West::NONE:
                        return 4059;
                    }
                }
            case Properties::Power::FOURTEEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 4060;
                    case Properties::West::SIDE:
                        return 4061;
                    case Properties::West::NONE:
                        return 4062;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4063;
                    case Properties::West::SIDE:
                        return 4064;
                    case Properties::West::NONE:
                        return 4065;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4066;
                    case Properties::West::SIDE:
                        return 4067;
                    case Properties::West::NONE:
                        return 4068;
                    }
                }
            case Properties::Power::FIFTEEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 4069;
                    case Properties::West::SIDE:
                        return 4070;
                    case Properties::West::NONE:
                        return 4071;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4072;
                    case Properties::West::SIDE:
                        return 4073;
                    case Properties::West::NONE:
                        return 4074;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4075;
                    case Properties::West::SIDE:
                        return 4076;
                    case Properties::West::NONE:
                        return 4077;
                    }
                }
            }
        case Properties::North::NONE:
            switch (power) {
            case Properties::Power::ZERO:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 4078;
                    case Properties::West::SIDE:
                        return 4079;
                    case Properties::West::NONE:
                        return 4080;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4081;
                    case Properties::West::SIDE:
                        return 4082;
                    case Properties::West::NONE:
                        return 4083;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4084;
                    case Properties::West::SIDE:
                        return 4085;
                    case Properties::West::NONE:
                        return 4086;
                    }
                }
            case Properties::Power::ONE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 4087;
                    case Properties::West::SIDE:
                        return 4088;
                    case Properties::West::NONE:
                        return 4089;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4090;
                    case Properties::West::SIDE:
                        return 4091;
                    case Properties::West::NONE:
                        return 4092;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4093;
                    case Properties::West::SIDE:
                        return 4094;
                    case Properties::West::NONE:
                        return 4095;
                    }
                }
            case Properties::Power::TWO:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 4096;
                    case Properties::West::SIDE:
                        return 4097;
                    case Properties::West::NONE:
                        return 4098;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4099;
                    case Properties::West::SIDE:
                        return 4100;
                    case Properties::West::NONE:
                        return 4101;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4102;
                    case Properties::West::SIDE:
                        return 4103;
                    case Properties::West::NONE:
                        return 4104;
                    }
                }
            case Properties::Power::THREE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 4105;
                    case Properties::West::SIDE:
                        return 4106;
                    case Properties::West::NONE:
                        return 4107;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4108;
                    case Properties::West::SIDE:
                        return 4109;
                    case Properties::West::NONE:
                        return 4110;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4111;
                    case Properties::West::SIDE:
                        return 4112;
                    case Properties::West::NONE:
                        return 4113;
                    }
                }
            case Properties::Power::FOUR:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 4114;
                    case Properties::West::SIDE:
                        return 4115;
                    case Properties::West::NONE:
                        return 4116;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4117;
                    case Properties::West::SIDE:
                        return 4118;
                    case Properties::West::NONE:
                        return 4119;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4120;
                    case Properties::West::SIDE:
                        return 4121;
                    case Properties::West::NONE:
                        return 4122;
                    }
                }
            case Properties::Power::FIVE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 4123;
                    case Properties::West::SIDE:
                        return 4124;
                    case Properties::West::NONE:
                        return 4125;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4126;
                    case Properties::West::SIDE:
                        return 4127;
                    case Properties::West::NONE:
                        return 4128;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4129;
                    case Properties::West::SIDE:
                        return 4130;
                    case Properties::West::NONE:
                        return 4131;
                    }
                }
            case Properties::Power::SIX:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 4132;
                    case Properties::West::SIDE:
                        return 4133;
                    case Properties::West::NONE:
                        return 4134;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4135;
                    case Properties::West::SIDE:
                        return 4136;
                    case Properties::West::NONE:
                        return 4137;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4138;
                    case Properties::West::SIDE:
                        return 4139;
                    case Properties::West::NONE:
                        return 4140;
                    }
                }
            case Properties::Power::SEVEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 4141;
                    case Properties::West::SIDE:
                        return 4142;
                    case Properties::West::NONE:
                        return 4143;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4144;
                    case Properties::West::SIDE:
                        return 4145;
                    case Properties::West::NONE:
                        return 4146;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4147;
                    case Properties::West::SIDE:
                        return 4148;
                    case Properties::West::NONE:
                        return 4149;
                    }
                }
            case Properties::Power::EIGHT:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 4150;
                    case Properties::West::SIDE:
                        return 4151;
                    case Properties::West::NONE:
                        return 4152;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4153;
                    case Properties::West::SIDE:
                        return 4154;
                    case Properties::West::NONE:
                        return 4155;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4156;
                    case Properties::West::SIDE:
                        return 4157;
                    case Properties::West::NONE:
                        return 4158;
                    }
                }
            case Properties::Power::NINE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 4159;
                    case Properties::West::SIDE:
                        return 4160;
                    case Properties::West::NONE:
                        return 4161;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4162;
                    case Properties::West::SIDE:
                        return 4163;
                    case Properties::West::NONE:
                        return 4164;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4165;
                    case Properties::West::SIDE:
                        return 4166;
                    case Properties::West::NONE:
                        return 4167;
                    }
                }
            case Properties::Power::TEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 4168;
                    case Properties::West::SIDE:
                        return 4169;
                    case Properties::West::NONE:
                        return 4170;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4171;
                    case Properties::West::SIDE:
                        return 4172;
                    case Properties::West::NONE:
                        return 4173;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4174;
                    case Properties::West::SIDE:
                        return 4175;
                    case Properties::West::NONE:
                        return 4176;
                    }
                }
            case Properties::Power::ELEVEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 4177;
                    case Properties::West::SIDE:
                        return 4178;
                    case Properties::West::NONE:
                        return 4179;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4180;
                    case Properties::West::SIDE:
                        return 4181;
                    case Properties::West::NONE:
                        return 4182;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4183;
                    case Properties::West::SIDE:
                        return 4184;
                    case Properties::West::NONE:
                        return 4185;
                    }
                }
            case Properties::Power::TWELVE:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 4186;
                    case Properties::West::SIDE:
                        return 4187;
                    case Properties::West::NONE:
                        return 4188;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4189;
                    case Properties::West::SIDE:
                        return 4190;
                    case Properties::West::NONE:
                        return 4191;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4192;
                    case Properties::West::SIDE:
                        return 4193;
                    case Properties::West::NONE:
                        return 4194;
                    }
                }
            case Properties::Power::THIRTEEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 4195;
                    case Properties::West::SIDE:
                        return 4196;
                    case Properties::West::NONE:
                        return 4197;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4198;
                    case Properties::West::SIDE:
                        return 4199;
                    case Properties::West::NONE:
                        return 4200;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4201;
                    case Properties::West::SIDE:
                        return 4202;
                    case Properties::West::NONE:
                        return 4203;
                    }
                }
            case Properties::Power::FOURTEEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 4204;
                    case Properties::West::SIDE:
                        return 4205;
                    case Properties::West::NONE:
                        return 4206;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4207;
                    case Properties::West::SIDE:
                        return 4208;
                    case Properties::West::NONE:
                        return 4209;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4210;
                    case Properties::West::SIDE:
                        return 4211;
                    case Properties::West::NONE:
                        return 4212;
                    }
                }
            case Properties::Power::FIFTEEN:
                switch (south) {
                case Properties::South::UP:
                    switch (west) {
                    case Properties::West::UP:
                        return 4213;
                    case Properties::West::SIDE:
                        return 4214;
                    case Properties::West::NONE:
                        return 4215;
                    }
                case Properties::South::SIDE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4216;
                    case Properties::West::SIDE:
                        return 4217;
                    case Properties::West::NONE:
                        return 4218;
                    }
                case Properties::South::NONE:
                    switch (west) {
                    case Properties::West::UP:
                        return 4219;
                    case Properties::West::SIDE:
                        return 4220;
                    case Properties::West::NONE:
                        return 4221;
                    }
                }
            }
        }
    }
    return 0;
}
}

}
