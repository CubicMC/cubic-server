#include "WarpedFenceGate.hpp"
#include <stdexcept>

namespace Blocks {
namespace WarpedFenceGate {
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
                    return 18280;
                case Properties::Powered::FALSE:
                    return 18281;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 18282;
                case Properties::Powered::FALSE:
                    return 18283;
                }
            }
        case Properties::In_wall::FALSE:
            switch (open) {
            case Properties::Open::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 18284;
                case Properties::Powered::FALSE:
                    return 18285;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 18286;
                case Properties::Powered::FALSE:
                    return 18287;
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
                    return 18288;
                case Properties::Powered::FALSE:
                    return 18289;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 18290;
                case Properties::Powered::FALSE:
                    return 18291;
                }
            }
        case Properties::In_wall::FALSE:
            switch (open) {
            case Properties::Open::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 18292;
                case Properties::Powered::FALSE:
                    return 18293;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 18294;
                case Properties::Powered::FALSE:
                    return 18295;
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
                    return 18296;
                case Properties::Powered::FALSE:
                    return 18297;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 18298;
                case Properties::Powered::FALSE:
                    return 18299;
                }
            }
        case Properties::In_wall::FALSE:
            switch (open) {
            case Properties::Open::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 18300;
                case Properties::Powered::FALSE:
                    return 18301;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 18302;
                case Properties::Powered::FALSE:
                    return 18303;
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
                    return 18304;
                case Properties::Powered::FALSE:
                    return 18305;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 18306;
                case Properties::Powered::FALSE:
                    return 18307;
                }
            }
        case Properties::In_wall::FALSE:
            switch (open) {
            case Properties::Open::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 18308;
                case Properties::Powered::FALSE:
                    return 18309;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 18310;
                case Properties::Powered::FALSE:
                    return 18311;
                }
            }
        }
    }
    return 0;
}
}

}
