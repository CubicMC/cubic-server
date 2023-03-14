#include "PurpleCandle.hpp"
#include <stdexcept>

namespace Blocks {
    namespace PurpleCandle {
        BlockId toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged) {
            switch (candles) {
            case Properties::Candles::ONE:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20273;
                    case Properties::Waterlogged::FALSE:
                        return 20274;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20275;
                    case Properties::Waterlogged::FALSE:
                        return 20276;
                    }
                }
            case Properties::Candles::TWO:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20277;
                    case Properties::Waterlogged::FALSE:
                        return 20278;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20279;
                    case Properties::Waterlogged::FALSE:
                        return 20280;
                    }
                }
            case Properties::Candles::THREE:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20281;
                    case Properties::Waterlogged::FALSE:
                        return 20282;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20283;
                    case Properties::Waterlogged::FALSE:
                        return 20284;
                    }
                }
            case Properties::Candles::FOUR:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20285;
                    case Properties::Waterlogged::FALSE:
                        return 20286;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20287;
                    case Properties::Waterlogged::FALSE:
                        return 20288;
                    }
                }
            }
            return 0;
        }
    }

}
