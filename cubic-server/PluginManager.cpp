#include "PluginManager.hpp"
#include "PluginInterface.hpp"
#include "logging/Logger.hpp"
#include "Server.hpp"

#include <dlfcn.h>
#include <filesystem>
#include <array>

PluginManager::PluginManager(Server *server, const std::string &folder) : _folder(folder), _interface(std::make_shared<PluginInterface>())
{
    this->_interface->load(server);
    this->load();
}

PluginManager::~PluginManager()
{
    this->unload();
}

void PluginManager::loadPlugin(std::string filepath)
{
    const std::array<const char *, 21> EventKeyArray = {
        EventKey::initialize,
        EventKey::destroy,
        EventKey::onPlayerJoin,
        EventKey::onPlayerLeave,
        EventKey::onPlayerChat,
        EventKey::onEntitySpawn,
        EventKey::onEntityMove,
        EventKey::onEntityRotate,
        EventKey::onEntityInteractEntity,
        EventKey::onEntityInteractBlock,
        EventKey::onEntityDamage,
        EventKey::onEntityUse,
        EventKey::onBlockPlace,
        EventKey::onBlockDestroy,
        EventKey::onBlockInteract,
        EventKey::onInventoryOpen,
        EventKey::onInventoryClose,
        EventKey::onInventoryChange,
        EventKey::onWorldLoad,
        EventKey::onDimensionLoad,
        EventKey::onChunkLoad,
    };
    void *nhandle = nullptr;
    void *rawptr = nullptr;

    nhandle = dlopen(filepath.c_str(), RTLD_LAZY);
    if (!nhandle) {
        //SRO
        return;
    }

    LINFO("Adding ", filepath, " to plugin list");

    this->_plugins[filepath] = nhandle;

    LINFO("Loading ", filepath);

    for (const auto &key : EventKeyArray) {
        rawptr = dlsym(nhandle, key);
        if (rawptr) {
            LINFO("Loading event ", key);
            this->_events[key].push_back(rawptr);
        }
    }
}

void PluginManager::load(void)
{
    LINFO("Loading plugins from ", this->_folder, "...");
    if (!std::filesystem::is_directory(this->_folder))
        return;

    for (const auto &filepath : std::filesystem::directory_iterator(_folder)) {
        if (filepath.path().string().ends_with(".so")) {
            loadPlugin(filepath.path().string());
        }
    }
    LINFO("Loaded plugins");

    using namespace EventKey;
    onEvent(this, initialize, this->_interface.get());
}

void PluginManager::unload(void)
{
    LINFO("Unloading plugins...");
    for (const auto &plugin : this->_plugins)
        dlclose(plugin.second);
    this->_plugins.clear();
    LINFO("Unloaded plugins");
}

void PluginManager::reload(void)
{
    this->unload();
    this->_events.clear();
    this->load();
}
