#include "Candle.hpp"
#include <stdexcept>

namespace Blocks {
    namespace Candle {
        BlockId toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged) {
            switch (candles) {
            case Properties::Candles::ONE:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20097;
                    case Properties::Waterlogged::FALSE:
                        return 20098;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20099;
                    case Properties::Waterlogged::FALSE:
                        return 20100;
                    }
                }
            case Properties::Candles::TWO:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20101;
                    case Properties::Waterlogged::FALSE:
                        return 20102;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20103;
                    case Properties::Waterlogged::FALSE:
                        return 20104;
                    }
                }
            case Properties::Candles::THREE:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20105;
                    case Properties::Waterlogged::FALSE:
                        return 20106;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20107;
                    case Properties::Waterlogged::FALSE:
                        return 20108;
                    }
                }
            case Properties::Candles::FOUR:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20109;
                    case Properties::Waterlogged::FALSE:
                        return 20110;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20111;
                    case Properties::Waterlogged::FALSE:
                        return 20112;
                    }
                }
            }
            return 0;
        }
    }

}
