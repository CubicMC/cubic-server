#include "LightningRod.hpp"
namespace Blocks {
    namespace LightningRod {
        BlockId toProtocol(Properties::Facing facing, Properties::Powered powered, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (powered) {
                case Properties::Powered::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 21398;
                    case Properties::Waterlogged::FALSE:
                        return 21399;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 21400;
                    case Properties::Waterlogged::FALSE:
                        return 21401;
                    }
                }
            case Properties::Facing::EAST:
                switch (powered) {
                case Properties::Powered::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 21402;
                    case Properties::Waterlogged::FALSE:
                        return 21403;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 21404;
                    case Properties::Waterlogged::FALSE:
                        return 21405;
                    }
                }
            case Properties::Facing::SOUTH:
                switch (powered) {
                case Properties::Powered::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 21406;
                    case Properties::Waterlogged::FALSE:
                        return 21407;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 21408;
                    case Properties::Waterlogged::FALSE:
                        return 21409;
                    }
                }
            case Properties::Facing::WEST:
                switch (powered) {
                case Properties::Powered::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 21410;
                    case Properties::Waterlogged::FALSE:
                        return 21411;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 21412;
                    case Properties::Waterlogged::FALSE:
                        return 21413;
                    }
                }
            case Properties::Facing::UP:
                switch (powered) {
                case Properties::Powered::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 21414;
                    case Properties::Waterlogged::FALSE:
                        return 21415;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 21416;
                    case Properties::Waterlogged::FALSE:
                        return 21417;
                    }
                }
            case Properties::Facing::DOWN:
                switch (powered) {
                case Properties::Powered::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 21418;
                    case Properties::Waterlogged::FALSE:
                        return 21419;
                    }
                case Properties::Powered::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 21420;
                    case Properties::Waterlogged::FALSE:
                        return 21421;
                    }
                }
            }
            return 0;
        }
    }

}
