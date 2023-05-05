#include "RedCandle.hpp"
namespace Blocks {
    namespace RedCandle {
        BlockId toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged) {
            switch (candles) {
            case Properties::Candles::ONE:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20337;
                    case Properties::Waterlogged::FALSE:
                        return 20338;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20339;
                    case Properties::Waterlogged::FALSE:
                        return 20340;
                    }
                }
            case Properties::Candles::TWO:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20341;
                    case Properties::Waterlogged::FALSE:
                        return 20342;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20343;
                    case Properties::Waterlogged::FALSE:
                        return 20344;
                    }
                }
            case Properties::Candles::THREE:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20345;
                    case Properties::Waterlogged::FALSE:
                        return 20346;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20347;
                    case Properties::Waterlogged::FALSE:
                        return 20348;
                    }
                }
            case Properties::Candles::FOUR:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20349;
                    case Properties::Waterlogged::FALSE:
                        return 20350;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20351;
                    case Properties::Waterlogged::FALSE:
                        return 20352;
                    }
                }
            }
            return 0;
        }
    }

}
