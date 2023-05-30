#include "CancelEvents.hpp"
#include "Player.hpp"

#include "protocol/ClientPackets.hpp"

void Event::cancelBlockPlace(Player *player, int32_t block, Position position)
{
    player->sendBlockUpdate(protocol::BlockUpdate{position, 0});
}

void Event::cancelBlockDestroy(Player *player, int32_t block, Position position)
{
    std::cout << "Cancel Block Destroy : " << position  << " id : " << block << std::endl;
    player->sendBlockUpdate({position, 2});
}
