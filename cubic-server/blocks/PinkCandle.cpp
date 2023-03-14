#include "PinkCandle.hpp"
#include <stdexcept>

namespace Blocks {
    namespace PinkCandle {
        BlockId toProtocol(Properties::Candles candles, Properties::Lit lit, Properties::Waterlogged waterlogged) {
            switch (candles) {
            case Properties::Candles::ONE:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20209;
                    case Properties::Waterlogged::FALSE:
                        return 20210;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20211;
                    case Properties::Waterlogged::FALSE:
                        return 20212;
                    }
                }
            case Properties::Candles::TWO:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20213;
                    case Properties::Waterlogged::FALSE:
                        return 20214;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20215;
                    case Properties::Waterlogged::FALSE:
                        return 20216;
                    }
                }
            case Properties::Candles::THREE:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20217;
                    case Properties::Waterlogged::FALSE:
                        return 20218;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20219;
                    case Properties::Waterlogged::FALSE:
                        return 20220;
                    }
                }
            case Properties::Candles::FOUR:
                switch (lit) {
                case Properties::Lit::TRUE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20221;
                    case Properties::Waterlogged::FALSE:
                        return 20222;
                    }
                case Properties::Lit::FALSE:
                    switch (waterlogged) {
                    case Properties::Waterlogged::TRUE:
                        return 20223;
                    case Properties::Waterlogged::FALSE:
                        return 20224;
                    }
                }
            }
            return 0;
        }
    }

}
