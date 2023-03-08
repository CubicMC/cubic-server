#include "SmallDripleaf.hpp"
#include <stdexcept>

namespace Blocks {
    namespace SmallDripleaf {
        BlockId toProtocol(Properties::Facing facing, Properties::Half half, Properties::Waterlogged waterlogged) {
            switch (facing) {
            case Properties::Facing::NORTH:
                switch (half) {
                case Properties::Half::UPPER:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 21542;
                    case Properties::Waterlogged::FALSE:
                        return 21543;
                    }
                case Properties::Half::LOWER:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 21544;
                    case Properties::Waterlogged::FALSE:
                        return 21545;
                    }
                }
            case Properties::Facing::SOUTH:
                switch (half) {
                case Properties::Half::UPPER:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 21546;
                    case Properties::Waterlogged::FALSE:
                        return 21547;
                    }
                case Properties::Half::LOWER:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 21548;
                    case Properties::Waterlogged::FALSE:
                        return 21549;
                    }
                }
            case Properties::Facing::WEST:
                switch (half) {
                case Properties::Half::UPPER:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 21550;
                    case Properties::Waterlogged::FALSE:
                        return 21551;
                    }
                case Properties::Half::LOWER:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 21552;
                    case Properties::Waterlogged::FALSE:
                        return 21553;
                    }
                }
            case Properties::Facing::EAST:
                switch (half) {
                case Properties::Half::UPPER:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 21554;
                    case Properties::Waterlogged::FALSE:
                        return 21555;
                    }
                case Properties::Half::LOWER:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 21556;
                    case Properties::Waterlogged::FALSE:
                        return 21557;
                    }
                }
            }
            return 0;
        }
    }

}
