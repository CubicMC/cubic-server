#include "MagentaCandle.hpp"
#include <stdexcept>

namespace Blocks {
    namespace MagentaCandle {
        BlockId toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged) {
            switch (candles) {
            case Properties::Candles::ONE:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20145;
                    case Properties::Waterlogged::FALSE:
                        return 20146;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20147;
                    case Properties::Waterlogged::FALSE:
                        return 20148;
                    }
                }
            case Properties::Candles::TWO:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20149;
                    case Properties::Waterlogged::FALSE:
                        return 20150;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20151;
                    case Properties::Waterlogged::FALSE:
                        return 20152;
                    }
                }
            case Properties::Candles::THREE:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20153;
                    case Properties::Waterlogged::FALSE:
                        return 20154;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20155;
                    case Properties::Waterlogged::FALSE:
                        return 20156;
                    }
                }
            case Properties::Candles::FOUR:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20157;
                    case Properties::Waterlogged::FALSE:
                        return 20158;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20159;
                    case Properties::Waterlogged::FALSE:
                        return 20160;
                    }
                }
            }
            return 0;
        }
    }

}
