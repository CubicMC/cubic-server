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
    typedef bool (*onPlayerJoin)(PluginInterface *interface, Player *player);
    typedef bool (*onPlayerLeave)(PluginInterface *interface, Player *player);
    typedef bool (*onPlayerChat)(PluginInterface *interface, Player *player, Chat *chat, std::string message);
    typedef bool (*onEntitySpawn)(PluginInterface *interface, Entity *entity);
    typedef bool (*onEntityMove)(PluginInterface *interface, Entity *entity, Vector3<double> *from, Vector3<double> *to);
    typedef bool (*onEntityRotate)(PluginInterface *interface, Entity *entity, Vector3<uint8_t> *from, Vector3<uint8_t> *to);
    typedef bool (*onEntityInteractEntity)(PluginInterface *interface, Entity *source, Entity *target);
    typedef bool (*onEntityInteractBlock)(PluginInterface *interface, Entity *entity, Block *block);
    typedef bool (*onEntityDamage)(PluginInterface *interface, Entity *source, float amount);
    typedef bool (*onEntityUse)(PluginInterface *interface, Entity *entity, Item *item);
    typedef bool (*onBlockPlace)(PluginInterface *interface, Block *block, Vector3<int> *position);
    typedef bool (*onBlockDestroy)(PluginInterface *interface, Block *block, Vector3<int> *position);
    typedef bool (*onBlockInteract)(PluginInterface *interface, Block *block, Vector3<int> *position, Entity *entity);
    typedef bool (*onInventoryOpen)(PluginInterface *interface, Player *player, Inventory *inventory);
    typedef bool (*onInventoryClose)(PluginInterface *interface, Player *player, Inventory *inventory);
    typedef bool (*onInventoryChange)(PluginInterface *interface, Inventory *inventory);
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

        AllTypes(void *rawptr) : rawptr(rawptr) {};
        ~AllTypes() {};
    };
};

namespace EventKey {
    constexpr char initialize[] = "initialize";
    constexpr char destroy[] = "destroy";
    constexpr char onPlayerJoin[] = "onPlayerJoin";
    constexpr char onPlayerLeave[] = "onPlayerLeave";
    constexpr char onPlayerChat[] = "onPlayerChat";
    constexpr char onEntitySpawn[] = "onEntitySpawn";
    constexpr char onEntityMove[] = "onEntityMove";
    constexpr char onEntityRotate[] = "onEntityRotate";
    constexpr char onEntityInteractEntity[] = "onEntityInteractEntity";
    constexpr char onEntityInteractBlock[] = "onEntityInteractBlock";
    constexpr char onEntityDamage[] = "onEntityDamage";
    constexpr char onEntityUse[] = "onEntityUse";
    constexpr char onBlockPlace[] = "onBlockPlace";
    constexpr char onBlockDestroy[] = "onBlockDestroy";
    constexpr char onBlockInteract[] = "onBlockInteract";
    constexpr char onInventoryOpen[] = "onInventoryOpen";
    constexpr char onInventoryClose[] = "onInventoryClose";
    constexpr char onInventoryChange[] = "onInventoryChange";
    constexpr char onWorldLoad[] = "onWorldLoad";
    constexpr char onDimensionLoad[] = "onDimensionLoad";
    constexpr char onChunkLoad[] = "onChunkLoad";
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
