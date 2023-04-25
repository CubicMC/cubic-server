#ifndef CUBICSERVER_PLUGINMANAGER_HPP
#define CUBICSERVER_PLUGINMANAGER_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include <variant>
#include <memory>

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

namespace EventType {
    typedef void (*initialize)(PluginInterface *interface);
    typedef void (*destroy)(PluginInterface *interface);
    typedef void (*onPlayerJoin)(PluginInterface *interface, Player *player);
    typedef void (*onPlayerLeave)(PluginInterface *interface, Player *player);
    typedef void (*onPlayerChat)(PluginInterface *interface, Player *player, Chat *chat, std::string message);
    typedef void (*onEntitySpawn)(PluginInterface *interface, Entity *entity);
    typedef void (*onEntityMove)(PluginInterface *interface, Entity *entity, Vector3 *from, Vector3 *to);
    typedef void (*onEntityRotate)(PluginInterface *interface, Entity *entity, Vector3 *from, Vector3 *to);
    typedef void (*onEntityInteractEntity)(PluginInterface *interface, Entity *source, Entity *target);
    typedef void (*onEntityInteractBlock)(PluginInterface *interface, Entity *entity, Block *block);
    typedef void (*onEntityDamage)(PluginInterface *interface, Entity *source, float amount);
    typedef void (*onEntityUse)(PluginInterface *interface, Entity *entity, Item *item);
    typedef void (*onBlockPlace)(PluginInterface *interface, Block *block, Vector3 *position);
    typedef void (*onBlockDestroy)(PluginInterface *interface, Block *block, Vector3 *position);
    typedef void (*onBlockInteract)(PluginInterface *interface, Block *block, Vector3 *position, Entity *entity);
    typedef void (*onInventoryOpen)(PluginInterface *interface, Player *player, Inventory *inventory);
    typedef void (*onInventoryClose)(PluginInterface *interface, Player *player, Inventory *inventory);
    typedef void (*onInventoryChange)(PluginInterface *interface, Inventory *inventory);
    typedef void (*onWorldLoad)(PluginInterface *interface, World *world);
    typedef void (*onDimensionLoad)(PluginInterface *interface, Dimension *dimension);
    typedef void (*onChunkLoad)(PluginInterface *interface, Chunk *chunk);

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

        AllTypes(void *rawptr) : rawptr(rawptr) {};
        ~AllTypes() {};
    };
};

namespace EventKey {
    const char *initialize = "initialize";
    const char *destroy = "destroy";
    const char *onPlayerJoin = "onPlayerJoin";
    const char *onPlayerLeave = "onPlayerLeave";
    const char *onPlayerChat = "onPlayerChat";
    const char *onEntitySpawn = "onEntitySpawn";
    const char *onEntityMove = "onEntityMove";
    const char *onEntityRotate = "onEntityRotate";
    const char *onEntityInteractEntity = "onEntityInteractEntity";
    const char *onEntityInteractBlock = "onEntityInteractBlock";
    const char *onEntityDamage = "onEntityDamage";
    const char *onEntityUse = "onEntityUse";
    const char *onBlockPlace = "onBlockPlace";
    const char *onBlockDestroy = "onBlockDestroy";
    const char *onBlockInteract = "onBlockInteract";
    const char *onInventoryOpen = "onInventoryOpen";
    const char *onInventoryClose = "onInventoryClose";
    const char *onInventoryChange = "onInventoryChange";
    const char *onWorldLoad = "onWorldLoad";
    const char *onDimensionLoad = "onDimensionLoad";
    const char *onChunkLoad = "onChunkLoad";
}

#define onEvent(plugin_manager, key, x) for (const auto &event : plugin_manager._events[key]) { \
    event(x); \
}

class PluginManager {
public:
    PluginManager(std::string &folder);
    ~PluginManager() = default;

    void load(void);
    void reload(void);


    std::unordered_map<std::string, std::vector<EventType::AllTypes>> _events;

private:
    void loadPlugin(std::string filepath);

    std::string _folder;
    std::shared_ptr<PluginInterface> _interface;
};

#endif // CUBICSERVER_PLUGINMANAGER_HPP
