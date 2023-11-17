#ifndef CUBICSERVER_PLUGINMANAGER_EVENTS_HPP
#define CUBICSERVER_PLUGINMANAGER_EVENTS_HPP

#include <cstdint>
#include <string>

class PluginInterface;
class Entity;
class Player;
class Chat;
class Block;
class Item;
class Inventory;

class World;
class Dimension;
class Chunk;

template<typename T>
class Vector3;

namespace EventType {
using initialize = bool (*)(PluginInterface *);
using destroy = bool (*)(PluginInterface *);
using tick = bool (*)(PluginInterface *);
using onPlayerJoin = bool (*)(PluginInterface *, Player *);
using onPlayerLeave = bool (*)(PluginInterface *, Player *);
using onPlayerChat = bool (*)(PluginInterface *, Player *, Chat *, std::string); // TODO - Place event
using onEntitySpawn = bool (*)(PluginInterface *, Entity *); // TODO - Place event
using onEntityMove = bool (*)(PluginInterface *, Entity *, Vector3<double>, Vector3<double>);
using onEntityRotate = bool (*)(PluginInterface *, Entity *, Vector3<uint8_t>, Vector3<uint8_t>);
using onEntityInteractEntity = bool (*)(PluginInterface *, Entity *, Entity *);
using onEntityInteractBlock = bool (*)(PluginInterface *, Entity *, int32_t); // Todo - Place event
using onEntityDamage = bool (*)(PluginInterface *, Entity *, float);
using onEntityUse = bool (*)(PluginInterface *, Entity *, Item *); // Todo - Place event
using onBlockPlace = bool (*)(PluginInterface *, int32_t, Vector3<int>);
using onBlockDestroy = bool (*)(PluginInterface *, int32_t, Vector3<int>);
using onBlockInteract = bool (*)(PluginInterface *, int32_t, Vector3<int>, Entity *); // Todo - ?
using onInventoryOpen = bool (*)(PluginInterface *, Player *, Inventory *); // Todo - Place event
using onInventoryClose = bool (*)(PluginInterface *, Player *, Inventory *); // Todo - Place event
using onInventoryChange = bool (*)(PluginInterface *, Inventory *); // Todo - Place event
using onWorldLoad = bool (*)(PluginInterface *, World *);
using onDimensionLoad = bool (*)(PluginInterface *, Dimension *);
using onChunkLoad = bool (*)(PluginInterface *, Chunk *);

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
