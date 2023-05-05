#include "BambooFenceGate.hpp"
namespace Blocks {
    namespace BambooFenceGate {
        BlockId toProtocol(Properties::Facing facing, Properties::In_wall in_wall, Properties::Open open, Properties::Powered powered) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (in_wall) {
                case Properties::In_wall::TRUE:
                    switch (open) {
                    case Properties::Open::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 11019;
                        case Properties::Powered::FALSE:
                            return 11020;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 11021;
                        case Properties::Powered::FALSE:
                            return 11022;
                        }
                    }
                case Properties::In_wall::FALSE:
                    switch (open) {
                    case Properties::Open::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 11023;
                        case Properties::Powered::FALSE:
                            return 11024;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 11025;
                        case Properties::Powered::FALSE:
                            return 11026;
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
                            return 11027;
                        case Properties::Powered::FALSE:
                            return 11028;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 11029;
                        case Properties::Powered::FALSE:
                            return 11030;
                        }
                    }
                case Properties::In_wall::FALSE:
                    switch (open) {
                    case Properties::Open::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 11031;
                        case Properties::Powered::FALSE:
                            return 11032;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 11033;
                        case Properties::Powered::FALSE:
                            return 11034;
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
                            return 11035;
                        case Properties::Powered::FALSE:
                            return 11036;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 11037;
                        case Properties::Powered::FALSE:
                            return 11038;
                        }
                    }
                case Properties::In_wall::FALSE:
                    switch (open) {
                    case Properties::Open::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 11039;
                        case Properties::Powered::FALSE:
                            return 11040;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 11041;
                        case Properties::Powered::FALSE:
                            return 11042;
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
                            return 11043;
                        case Properties::Powered::FALSE:
                            return 11044;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 11045;
                        case Properties::Powered::FALSE:
                            return 11046;
                        }
                    }
                case Properties::In_wall::FALSE:
                    switch (open) {
                    case Properties::Open::TRUE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 11047;
                        case Properties::Powered::FALSE:
                            return 11048;
                        }
                    case Properties::Open::FALSE:
                        switch (powered) {
                        case Properties::Powered::TRUE:
                            return 11049;
                        case Properties::Powered::FALSE:
                            return 11050;
                        }
                    }
                }
            }
            return 0;
        }
    }

}
