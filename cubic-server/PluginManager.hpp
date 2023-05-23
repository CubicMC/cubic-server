#ifndef CUBICSERVER_PLUGINMANAGER_HPP
#define CUBICSERVER_PLUGINMANAGER_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include <variant>
#include <memory>
#include <stdint.h>

class PluginInterface;
class Server;

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
    typedef void (*initialize)(PluginInterface *interface);
    typedef void (*destroy)(PluginInterface *interface);
    typedef void (*onPlayerJoin)(PluginInterface *interface, Player *player);
    typedef void (*onPlayerLeave)(PluginInterface *interface, Player *player);
    typedef void (*onPlayerChat)(PluginInterface *interface, Player *player, Chat *chat, std::string message);
    typedef void (*onEntitySpawn)(PluginInterface *interface, Entity *entity);
    typedef void (*onEntityMove)(PluginInterface *interface, Entity *entity, Vector3<double> *from, Vector3<double> *to);
    typedef void (*onEntityRotate)(PluginInterface *interface, Entity *entity, Vector3<uint8_t> *from, Vector3<uint8_t> *to);
    typedef void (*onEntityInteractEntity)(PluginInterface *interface, Entity *source, Entity *target);
    typedef void (*onEntityInteractBlock)(PluginInterface *interface, Entity *entity, Block *block);
    typedef void (*onEntityDamage)(PluginInterface *interface, Entity *source, float amount);
    typedef void (*onEntityUse)(PluginInterface *interface, Entity *entity, Item *item);
    typedef void (*onBlockPlace)(PluginInterface *interface, Block *block, Vector3<int> *position);
    typedef void (*onBlockDestroy)(PluginInterface *interface, Block *block, Vector3<int> *position);
    typedef void (*onBlockInteract)(PluginInterface *interface, Block *block, Vector3<int> *position, Entity *entity);
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
    static const char *initialize = "initialize";
    static const char *destroy = "destroy";
    static const char *onPlayerJoin = "onPlayerJoin";
    static const char *onPlayerLeave = "onPlayerLeave";
    static const char *onPlayerChat = "onPlayerChat";
    static const char *onEntitySpawn = "onEntitySpawn";
    static const char *onEntityMove = "onEntityMove";
    static const char *onEntityRotate = "onEntityRotate";
    static const char *onEntityInteractEntity = "onEntityInteractEntity";
    static const char *onEntityInteractBlock = "onEntityInteractBlock";
    static const char *onEntityDamage = "onEntityDamage";
    static const char *onEntityUse = "onEntityUse";
    static const char *onBlockPlace = "onBlockPlace";
    static const char *onBlockDestroy = "onBlockDestroy";
    static const char *onBlockInteract = "onBlockInteract";
    static const char *onInventoryOpen = "onInventoryOpen";
    static const char *onInventoryClose = "onInventoryClose";
    static const char *onInventoryChange = "onInventoryChange";
    static const char *onWorldLoad = "onWorldLoad";
    static const char *onDimensionLoad = "onDimensionLoad";
    static const char *onChunkLoad = "onChunkLoad";
}

#define onEvent(plugin_manager, key, ...) for (const auto &event : plugin_manager._events[EventKey::key]) { \
    ((EventType::key)event.rawptr)(plugin_manager.getInterface().get() __VA_OPT__(,) __VA_ARGS__); \
}

class PluginManager {
public:
    explicit PluginManager(Server *server, const std::string &folder = "./plugins");
    ~PluginManager();

    void load();
    void reload();
    void unload();

    std::shared_ptr<PluginInterface> getInterface() const;

    std::unordered_map<std::string, std::vector<EventType::AllTypes>> _events;
private:
    std::shared_ptr<PluginInterface> _interface;

    void loadPlugin(std::string filepath);
    std::string _folder;
    std::unordered_map<std::string, void *> _plugins;
};

#endif // CUBICSERVER_PLUGINMANAGER_HPP
