#include "CaveVines.hpp"
#include <stdexcept>

namespace Blocks {
namespace CaveVines {
BlockId toProtocol(Properties::Age age, Properties::Berries berries)
{
    switch (age) {
    case Properties::Age::ZERO:
        switch (berries) {
        case Properties::Berries::TRUE:
            return 21443;
        case Properties::Berries::FALSE:
            return 21444;
        }
    case Properties::Age::ONE:
        switch (berries) {
        case Properties::Berries::TRUE:
            return 21445;
        case Properties::Berries::FALSE:
            return 21446;
        }
    case Properties::Age::TWO:
        switch (berries) {
        case Properties::Berries::TRUE:
            return 21447;
        case Properties::Berries::FALSE:
            return 21448;
        }
    case Properties::Age::THREE:
        switch (berries) {
        case Properties::Berries::TRUE:
            return 21449;
        case Properties::Berries::FALSE:
            return 21450;
        }
    case Properties::Age::FOUR:
        switch (berries) {
        case Properties::Berries::TRUE:
            return 21451;
        case Properties::Berries::FALSE:
            return 21452;
        }
    case Properties::Age::FIVE:
        switch (berries) {
        case Properties::Berries::TRUE:
            return 21453;
        case Properties::Berries::FALSE:
            return 21454;
        }
    case Properties::Age::SIX:
        switch (berries) {
        case Properties::Berries::TRUE:
            return 21455;
        case Properties::Berries::FALSE:
            return 21456;
        }
    case Properties::Age::SEVEN:
        switch (berries) {
        case Properties::Berries::TRUE:
            return 21457;
        case Properties::Berries::FALSE:
            return 21458;
        }
    case Properties::Age::EIGHT:
        switch (berries) {
        case Properties::Berries::TRUE:
            return 21459;
        case Properties::Berries::FALSE:
            return 21460;
        }
    case Properties::Age::NINE:
        switch (berries) {
        case Properties::Berries::TRUE:
            return 21461;
        case Properties::Berries::FALSE:
            return 21462;
        }
    case Properties::Age::TEN:
        switch (berries) {
        case Properties::Berries::TRUE:
            return 21463;
        case Properties::Berries::FALSE:
            return 21464;
        }
    case Properties::Age::ELEVEN:
        switch (berries) {
        case Properties::Berries::TRUE:
            return 21465;
        case Properties::Berries::FALSE:
            return 21466;
        }
    case Properties::Age::TWELVE:
        switch (berries) {
        case Properties::Berries::TRUE:
            return 21467;
        case Properties::Berries::FALSE:
            return 21468;
        }
    case Properties::Age::THIRTEEN:
        switch (berries) {
        case Properties::Berries::TRUE:
            return 21469;
        case Properties::Berries::FALSE:
            return 21470;
        }
    case Properties::Age::FOURTEEN:
        switch (berries) {
        case Properties::Berries::TRUE:
            return 21471;
        case Properties::Berries::FALSE:
            return 21472;
        }
    case Properties::Age::FIFTEEN:
        switch (berries) {
        case Properties::Berries::TRUE:
            return 21473;
        case Properties::Berries::FALSE:
            return 21474;
        }
    case Properties::Age::SIXTEEN:
        switch (berries) {
        case Properties::Berries::TRUE:
            return 21475;
        case Properties::Berries::FALSE:
            return 21476;
        }
    case Properties::Age::SEVENTEEN:
        switch (berries) {
        case Properties::Berries::TRUE:
            return 21477;
        case Properties::Berries::FALSE:
            return 21478;
        }
    case Properties::Age::EIGHTEEN:
        switch (berries) {
        case Properties::Berries::TRUE:
            return 21479;
        case Properties::Berries::FALSE:
            return 21480;
        }
    case Properties::Age::NINETEEN:
        switch (berries) {
        case Properties::Berries::TRUE:
            return 21481;
        case Properties::Berries::FALSE:
            return 21482;
        }
    case Properties::Age::TWENTY:
        switch (berries) {
        case Properties::Berries::TRUE:
            return 21483;
        case Properties::Berries::FALSE:
            return 21484;
        }
    case Properties::Age::TWENTY_ONE:
        switch (berries) {
        case Properties::Berries::TRUE:
            return 21485;
        case Properties::Berries::FALSE:
            return 21486;
        }
    case Properties::Age::TWENTY_TWO:
        switch (berries) {
        case Properties::Berries::TRUE:
            return 21487;
        case Properties::Berries::FALSE:
            return 21488;
        }
    case Properties::Age::TWENTY_THREE:
        switch (berries) {
        case Properties::Berries::TRUE:
            return 21489;
        case Properties::Berries::FALSE:
            return 21490;
        }
    case Properties::Age::TWENTY_FOUR:
        switch (berries) {
        case Properties::Berries::TRUE:
            return 21491;
        case Properties::Berries::FALSE:
            return 21492;
        }
    case Properties::Age::TWENTY_FIVE:
        switch (berries) {
        case Properties::Berries::TRUE:
            return 21493;
        case Properties::Berries::FALSE:
            return 21494;
        }
    }
    return 0;
}
}

}
