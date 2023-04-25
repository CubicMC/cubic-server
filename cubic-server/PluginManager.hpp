#ifndef CUBICSERVER_PLUGINMANAGER_HPP
#define CUBICSERVER_PLUGINMANAGER_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include <functional>
#include <variant>

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

class Vector3;

namespace PluginType {
    using initialize = std::function<void(PluginInterface *interface)>;
    using destroy = std::function<void(PluginInterface *interface)>;
    using onPlayerJoin = std::function<void(PluginInterface *interface, Player *player)>;
    using onPlayerLeave = std::function<void(PluginInterface *interface, Player *player)>;
    using onPlayerChat = std::function<void(PluginInterface *interface, Player *player, Chat *chat, std::string message)>;
    using onEntitySpawn = std::function<void(PluginInterface *interface, Entity *entity)>;
    using onEntityMove = std::function<void(PluginInterface *interface, Entity *entity, Vector3 *from, Vector3 *to)>;
    using onEntityRotate = std::function<void(PluginInterface *interface, Entity *entity, Vector3 *from, Vector3 *to)>;
    using onEntityInteractEntity = std::function<void(PluginInterface *interface, Entity *source, Entity *target)>;
    using onEntityInteractBlock = std::function<void(PluginInterface *interface, Entity *entity, Block *block)>;
    using onEntityDamage = std::function<void(PluginInterface *interface, Entity *source, float amount)>;
    using onEntityUse = std::function<void(PluginInterface *interface, Entity *entity, Item *item)>;
    using onBlockPlace = std::function<void(PluginInterface *interface, Block *block, Vector3 *position)>;
    using onBlockDestroy = std::function<void(PluginInterface *interface, Block *block, Vector3 *position)>;
    using onBlockInteract = std::function<void(PluginInterface *interface, Block *block, Vector3 *position, Entity *entity)>;
    using onInventoryOpen = std::function<void(PluginInterface *interface, Player *player, Inventory *inventory)>;
    using onInventoryClose = std::function<void(PluginInterface *interface, Player *player, Inventory *inventory)>;
    using onInventoryChange = std::function<void(PluginInterface *interface, Inventory *inventory)>;
    using onWorldLoad = std::function<void(PluginInterface *interface, World *world)>;
    using onDimensionLoad = std::function<void(PluginInterface *interface, Dimension *dimension)>;
    using onChunkLoad = std::function<void(PluginInterface *interface, Chunk *chunk)>;

    using EventTypeVariant = std::variant<
        initialize, 
        destroy, 
        onPlayerJoin, 
        onPlayerLeave, 
        onPlayerChat, 
        onEntitySpawn, 
        onEntityMove, 
        onEntityRotate, 
        onEntityInteractEntity, 
        onEntityInteractBlock, 
        onEntityDamage, 
        onEntityUse, 
        onBlockPlace, 
        onBlockDestroy, 
        onBlockInteract, 
        onInventoryOpen, 
        onInventoryClose, 
        onInventoryChange, 
        onWorldLoad, 
        onDimensionLoad, 
        onChunkLoad
    >;
};


class PluginManager {
public:
    PluginManager(std::string &folder);
    ~PluginManager();

    void getPluginInterface(PluginInterface *pluginInterface);

    void load(void);
    void reload(void);

private:
    std::string folder;
    std::unordered_map<std::string, std::vector<std::function<PluginType::EventTypeVariant>>> events;
};

#endif // CUBICSERVER_PLUGINMANAGER_HPP
