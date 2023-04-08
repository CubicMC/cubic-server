#include "JungleFenceGate.hpp"
#include <stdexcept>

namespace Blocks {
namespace JungleFenceGate {
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
                    return 10891;
                case Properties::Powered::FALSE:
                    return 10892;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10893;
                case Properties::Powered::FALSE:
                    return 10894;
                }
            }
        case Properties::In_wall::FALSE:
            switch (open) {
            case Properties::Open::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10895;
                case Properties::Powered::FALSE:
                    return 10896;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10897;
                case Properties::Powered::FALSE:
                    return 10898;
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
                    return 10899;
                case Properties::Powered::FALSE:
                    return 10900;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10901;
                case Properties::Powered::FALSE:
                    return 10902;
                }
            }
        case Properties::In_wall::FALSE:
            switch (open) {
            case Properties::Open::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10903;
                case Properties::Powered::FALSE:
                    return 10904;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10905;
                case Properties::Powered::FALSE:
                    return 10906;
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
                    return 10907;
                case Properties::Powered::FALSE:
                    return 10908;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10909;
                case Properties::Powered::FALSE:
                    return 10910;
                }
            }
        case Properties::In_wall::FALSE:
            switch (open) {
            case Properties::Open::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10911;
                case Properties::Powered::FALSE:
                    return 10912;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10913;
                case Properties::Powered::FALSE:
                    return 10914;
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
                    return 10915;
                case Properties::Powered::FALSE:
                    return 10916;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10917;
                case Properties::Powered::FALSE:
                    return 10918;
                }
            }
        case Properties::In_wall::FALSE:
            switch (open) {
            case Properties::Open::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10919;
                case Properties::Powered::FALSE:
                    return 10920;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 10921;
                case Properties::Powered::FALSE:
                    return 10922;
                }
            }
        }
    }
    return 0;
}
}

}
