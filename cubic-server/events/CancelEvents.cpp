#include "CancelEvents.hpp"
#include "Player.hpp"

#include "protocol/ClientPackets.hpp"

void Event::cancelBlockPlace(Player *player, int32_t block, Position position)
{
    player->sendBlockUpdate(protocol::BlockUpdate{position, block});
}

void Event::cancelBlockDestroy(Player *player, int32_t block, Position position)
{
    player->sendBlockUpdate(protocol::BlockUpdate{position, block});
}
