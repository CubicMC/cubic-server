#include "BrownCandle.hpp"
#include <stdexcept>

namespace Blocks {
    namespace BrownCandle {
        BlockId toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged) {
            switch (candles) {
            case Properties::Candles::ONE:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20305;
                    case Properties::Waterlogged::FALSE:
                        return 20306;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20307;
                    case Properties::Waterlogged::FALSE:
                        return 20308;
                    }
                }
            case Properties::Candles::TWO:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20309;
                    case Properties::Waterlogged::FALSE:
                        return 20310;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20311;
                    case Properties::Waterlogged::FALSE:
                        return 20312;
                    }
                }
            case Properties::Candles::THREE:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20313;
                    case Properties::Waterlogged::FALSE:
                        return 20314;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20315;
                    case Properties::Waterlogged::FALSE:
                        return 20316;
                    }
                }
            case Properties::Candles::FOUR:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20317;
                    case Properties::Waterlogged::FALSE:
                        return 20318;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20319;
                    case Properties::Waterlogged::FALSE:
                        return 20320;
                    }
                }
            }
            return 0;
        }
    }

}
