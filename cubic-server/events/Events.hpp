#ifndef CUBICSERVER_PLUGINMANAGER_EVENTS_HPP
#define CUBICSERVER_PLUGINMANAGER_EVENTS_HPP

#include "protocol/container/Inventory.hpp"
#include <cstdint>
#include <string>

class PluginInterface;
class Entity;
class Player;
class Chat;
class Block;
class Item;
using Inventory = protocol::container::Inventory;

class World;
class Dimension;
class Chunk;

template<typename T>
class Vector3;

namespace EventType {
typedef bool (*initialize)(PluginInterface *interface);
typedef bool (*destroy)(PluginInterface *interface);
typedef bool (*tick)(PluginInterface *interface);
typedef bool (*onPlayerJoin)(PluginInterface *interface, Player *player);
typedef bool (*onPlayerLeave)(PluginInterface *interface, Player *player);
typedef bool (*onPlayerChat)(PluginInterface *interface, Player *player, Chat *chat, std::string message); // TODO - Place event
typedef bool (*onEntitySpawn)(PluginInterface *interface, Entity *entity); // TODO - Place event
typedef bool (*onEntityMove)(PluginInterface *interface, Entity *entity, Vector3<double> from, Vector3<double> to);
typedef bool (*onEntityRotate)(PluginInterface *interface, Entity *entity, Vector3<uint8_t> from, Vector3<uint8_t> to);
typedef bool (*onEntityInteractEntity)(PluginInterface *interface, Entity *source, Entity *target);
typedef bool (*onEntityInteractBlock)(PluginInterface *interface, Entity *entity, int32_t block_id); // Todo - Place event
typedef bool (*onEntityDamage)(PluginInterface *interface, Entity *source, float amount);
typedef bool (*onEntityUse)(PluginInterface *interface, Entity *entity, Item *item); // Todo - Place event
typedef bool (*onBlockPlace)(PluginInterface *interface, int32_t block_id, Vector3<int> position);
typedef bool (*onBlockDestroy)(PluginInterface *interface, int32_t block_id, Vector3<int> position);
typedef bool (*onBlockInteract)(PluginInterface *interface, int32_t block_id, Vector3<int> position, Entity *entity); // Todo - ?
typedef bool (*onInventoryOpen)(PluginInterface *interface, Player *player, Inventory *inventory); // Todo - Place event
typedef bool (*onInventoryClose)(PluginInterface *interface, Player *player, Inventory *inventory); // Todo - Place event
typedef bool (*onInventoryChange)(PluginInterface *interface, Inventory *inventory); // Todo - Place event
typedef bool (*onWorldLoad)(PluginInterface *interface, World *world);
typedef bool (*onDimensionLoad)(PluginInterface *interface, Dimension *dimension);
typedef bool (*onChunkLoad)(PluginInterface *interface, Chunk *chunk);

union AllTypes {
    void *rawptr;
    initialize initialize_type;
    destroy destroy_type;
    onPlayerJoin onPlayerJoin_type;
    onPlayerLeave onPlayerLeave_type;
    onPlayerChat onPlayerChat_type;
    onEntitySpawn onEntitySpawn_type;
    onEntityMove onEntityMove_type;
    onEntityRotate onEntityRotate_type;
    onEntityInteractEntity onEntityInteractEntity_type;
    onEntityInteractBlock onEntityInteractBlock_type;
    onEntityDamage onEntityDamage_type;
    onEntityUse onEntityUse_type;
    onBlockPlace onBlockPlace_type;
    onBlockDestroy onBlockDestroy_type;
    onBlockInteract onBlockInteract_type;
    onInventoryOpen onInventoryOpen_type;
    onInventoryClose onInventoryClose_type;
    onInventoryChange onInventoryChange_type;
    onWorldLoad onWorldLoad_type;
    onDimensionLoad onDimensionLoad_type;
    onChunkLoad onChunkLoad_type;

    AllTypes(void *rawptr):
        rawptr(rawptr) {};
    ~AllTypes() {};
};
};

#endif // CUBICSERVER_PLUGINMANAGER_EVENTS_HPP
