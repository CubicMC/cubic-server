#include "CrimsonFenceGate.hpp"
#include <stdexcept>

namespace Blocks {
namespace CrimsonFenceGate {
BlockId toProtocol(Properties::Facing facing, Properties::In_wall in_wall, Properties::Open open, Properties::Powered powered)
{
    switch (facing) {
    case Properties::Facing::NORTH:
        switch (in_wall) {
        case Properties::In_wall::TRUE:
            switch (open) {
            case Properties::Open::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 18248;
                case Properties::Powered::FALSE:
                    return 18249;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 18250;
                case Properties::Powered::FALSE:
                    return 18251;
                }
            }
        case Properties::In_wall::FALSE:
            switch (open) {
            case Properties::Open::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 18252;
                case Properties::Powered::FALSE:
                    return 18253;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 18254;
                case Properties::Powered::FALSE:
                    return 18255;
                }
            }
        }
    case Properties::Facing::SOUTH:
        switch (in_wall) {
        case Properties::In_wall::TRUE:
            switch (open) {
            case Properties::Open::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 18256;
                case Properties::Powered::FALSE:
                    return 18257;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 18258;
                case Properties::Powered::FALSE:
                    return 18259;
                }
            }
        case Properties::In_wall::FALSE:
            switch (open) {
            case Properties::Open::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 18260;
                case Properties::Powered::FALSE:
                    return 18261;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 18262;
                case Properties::Powered::FALSE:
                    return 18263;
                }
            }
        }
    case Properties::Facing::WEST:
        switch (in_wall) {
        case Properties::In_wall::TRUE:
            switch (open) {
            case Properties::Open::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 18264;
                case Properties::Powered::FALSE:
                    return 18265;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 18266;
                case Properties::Powered::FALSE:
                    return 18267;
                }
            }
        case Properties::In_wall::FALSE:
            switch (open) {
            case Properties::Open::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 18268;
                case Properties::Powered::FALSE:
                    return 18269;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 18270;
                case Properties::Powered::FALSE:
                    return 18271;
                }
            }
        }
    case Properties::Facing::EAST:
        switch (in_wall) {
        case Properties::In_wall::TRUE:
            switch (open) {
            case Properties::Open::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 18272;
                case Properties::Powered::FALSE:
                    return 18273;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 18274;
                case Properties::Powered::FALSE:
                    return 18275;
                }
            }
        case Properties::In_wall::FALSE:
            switch (open) {
            case Properties::Open::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 18276;
                case Properties::Powered::FALSE:
                    return 18277;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 18278;
                case Properties::Powered::FALSE:
                    return 18279;
                }
            }
        }
    }
    return 0;
}
}

}
