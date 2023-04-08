#include "OakFenceGate.hpp"
#include <stdexcept>

namespace Blocks {
namespace OakFenceGate {
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
                    return 6767;
                case Properties::Powered::FALSE:
                    return 6768;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 6769;
                case Properties::Powered::FALSE:
                    return 6770;
                }
            }
        case Properties::In_wall::FALSE:
            switch (open) {
            case Properties::Open::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 6771;
                case Properties::Powered::FALSE:
                    return 6772;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 6773;
                case Properties::Powered::FALSE:
                    return 6774;
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
                    return 6775;
                case Properties::Powered::FALSE:
                    return 6776;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 6777;
                case Properties::Powered::FALSE:
                    return 6778;
                }
            }
        case Properties::In_wall::FALSE:
            switch (open) {
            case Properties::Open::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 6779;
                case Properties::Powered::FALSE:
                    return 6780;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 6781;
                case Properties::Powered::FALSE:
                    return 6782;
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
                    return 6783;
                case Properties::Powered::FALSE:
                    return 6784;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 6785;
                case Properties::Powered::FALSE:
                    return 6786;
                }
            }
        case Properties::In_wall::FALSE:
            switch (open) {
            case Properties::Open::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 6787;
                case Properties::Powered::FALSE:
                    return 6788;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 6789;
                case Properties::Powered::FALSE:
                    return 6790;
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
                    return 6791;
                case Properties::Powered::FALSE:
                    return 6792;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 6793;
                case Properties::Powered::FALSE:
                    return 6794;
                }
            }
        case Properties::In_wall::FALSE:
            switch (open) {
            case Properties::Open::TRUE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 6795;
                case Properties::Powered::FALSE:
                    return 6796;
                }
            case Properties::Open::FALSE:
                switch (powered) {
                case Properties::Powered::TRUE:
                    return 6797;
                case Properties::Powered::FALSE:
                    return 6798;
                }
            }
        }
    }
    return 0;
}
}

}
