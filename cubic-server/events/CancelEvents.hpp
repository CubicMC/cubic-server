#ifndef CUBICSERVER_PLUGINMANAGER_CANCELEVENTS_HPP
#define CUBICSERVER_PLUGINMANAGER_CANCELEVENTS_HPP

#include "Events.hpp"

struct Position;

namespace Event {
void cancelPlayerChat(Player *player, Chat *chat, std::string message);
void cancelEntitySpawn(Player *player, Entity *entity);
void cancelEntityMove(Player *player, Entity *entity, Vector3<double> *from, Vector3<double> *to);
void cancelEntityRotate(Player *player, Entity *entity, Vector3<uint8_t> *from, Vector3<uint8_t> *to);
void cancelEntityInteractEntity(Player *player, Entity *source, Entity *target);
void cancelEntityInteractBlock(Player *player, Entity *entity, Block *block);
void cancelEntityDamage(Player *player, Entity *source, float amount);
void cancelEntityUse(Player *player, Entity *entity, Item *item);
void cancelBlockPlace(Player *player, int32_t block, Position position);
void cancelBlockDestroy(Player *player, int32_t block, Position position);
void cancelBlockInteract(Player *player, Block *block, Vector3<int> *position, Entity *entity);
void cancelInventoryOpen(Player *player, Inventory *inventory);
void cancelInventoryClose(Player *player, Inventory *inventory);
void cancelInventoryChange(Player *player, Inventory *inventory);
void cancelWorldLoad(Player *player, World *world);
void cancelDimensionLoad(Player *player, Dimension *dimension);
void cancelChunkLoad(Player *player, Chunk *chunk);
}

#endif // CUBICSERVER_PLUGINMANAGER_CANCELEVENTS_HPP
