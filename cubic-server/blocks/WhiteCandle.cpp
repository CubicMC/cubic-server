#include "WhiteCandle.hpp"
namespace Blocks {
    namespace WhiteCandle {
        BlockId toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged) {
            switch (candles) {
            case Properties::Candles::ONE:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20113;
                    case Properties::Waterlogged::FALSE:
                        return 20114;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20115;
                    case Properties::Waterlogged::FALSE:
                        return 20116;
                    }
                }
            case Properties::Candles::TWO:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20117;
                    case Properties::Waterlogged::FALSE:
                        return 20118;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20119;
                    case Properties::Waterlogged::FALSE:
                        return 20120;
                    }
                }
            case Properties::Candles::THREE:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20121;
                    case Properties::Waterlogged::FALSE:
                        return 20122;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20123;
                    case Properties::Waterlogged::FALSE:
                        return 20124;
                    }
                }
            case Properties::Candles::FOUR:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20125;
                    case Properties::Waterlogged::FALSE:
                        return 20126;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20127;
                    case Properties::Waterlogged::FALSE:
                        return 20128;
                    }
                }
            }
            return 0;
        }
    }

}
