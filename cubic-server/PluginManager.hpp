#ifndef CUBICSERVER_PLUGINMANAGER_HPP
#define CUBICSERVER_PLUGINMANAGER_HPP

#include <cstdint>
#include <memory>
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

#include "events/Events.hpp"

class Server;

namespace EventKey {
constexpr char initialize[] = "initialize";
constexpr char destroy[] = "destroy";
constexpr char tick[] = "tick";
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

#define onEvent(plugin_manager, key, ...)                                                                \
    for (const auto &event : plugin_manager._events[EventKey::key]) {                                    \
        ((EventType::key) event.rawptr)(plugin_manager.getInterface().get() __VA_OPT__(, ) __VA_ARGS__); \
    }

#define onEventCancelable(plugin_manager, key, is_canceled, ...)                                                                      \
    for (const auto &event : plugin_manager._events[EventKey::key]) {                                                                 \
        is_canceled = is_canceled || ((EventType::key) event.rawptr)(plugin_manager.getInterface().get() __VA_OPT__(, ) __VA_ARGS__); \
    }

class PluginManager {
public:
    explicit PluginManager(Server *server, const std::string &folder = "./plugins");
    ~PluginManager();

    void load();
    void reload();
    void unload();

    std::shared_ptr<const PluginInterface> getInterface() const { return this->_interface; }
    std::shared_ptr<PluginInterface> getInterface() { return this->_interface; }

    std::unordered_map<std::string, std::vector<EventType::AllTypes>> _events;

private:
    std::shared_ptr<PluginInterface> _interface;

    void loadPlugin(std::string filepath);
    std::string _folder;
    std::unordered_map<std::string, void *> _plugins;
};

#endif // CUBICSERVER_PLUGINMANAGER_HPP
