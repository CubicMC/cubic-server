#include "TripwireHook.hpp"
namespace Blocks {
    namespace TripwireHook {
        BlockId toProtocol(Properties::Attached attached, Properties::Facing facing, Properties::Powered powered) {
            switch (attached) {
            case Properties::Attached::TRUE:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7291;
                    case Properties::Powered::FALSE:
                        return 7292;
                    }
                case Properties::Facing::SOUTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7293;
                    case Properties::Powered::FALSE:
                        return 7294;
                    }
                case Properties::Facing::WEST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7295;
                    case Properties::Powered::FALSE:
                        return 7296;
                    }
                case Properties::Facing::EAST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7297;
                    case Properties::Powered::FALSE:
                        return 7298;
                    }
                }
            case Properties::Attached::FALSE:
                switch (facing) {
                case Properties::Facing::NORTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7299;
                    case Properties::Powered::FALSE:
                        return 7300;
                    }
                case Properties::Facing::SOUTH:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7301;
                    case Properties::Powered::FALSE:
                        return 7302;
                    }
                case Properties::Facing::WEST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7303;
                    case Properties::Powered::FALSE:
                        return 7304;
                    }
                case Properties::Facing::EAST:
                    switch (powered) {
                    case Properties::Powered::TRUE:
                        return 7305;
                    case Properties::Powered::FALSE:
                        return 7306;
                    }
                }
            }
            return 0;
        }
    }

}
