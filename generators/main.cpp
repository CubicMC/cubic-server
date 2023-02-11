#include <iostream>
#include "final.hpp"
// #include "generated.hpp"

int main(int argc, char** argv) {
    std::cout <<
        "Acacia button with Ceiling, south and powerred : " <<
        Blocks::fromNameToProtocolId("minecraft:acacia_button",
            {{"face", "ceiling"}, {"facing", "south"}, {"powered", "true"}}) <<
        std::endl;
    std::cout << Blocks::toName(Blocks::fromNameToProtocolId("minecraft:acacia_sapling", {{"stage", "0"}})) <<
        std::endl;
    return 0;
}
