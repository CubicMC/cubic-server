#include "PluginManager.hpp"
#include "PluginInterface.hpp"
#include "Server.hpp"
#include "library/LibraryManager.hpp"
#include "logging/logging.hpp"

#include <array>
#include <filesystem>

PluginManager::PluginManager(Server *server, const std::string &folder):
    _interface(std::make_shared<PluginInterface>()),
    _folder(folder)
{
    _interface->load(server);
}

PluginManager::~PluginManager() { this->unload(); }

void PluginManager::loadPlugin(const std::filesystem::path &filepath)
{
    static const std::array<const char *, 22> EventKeyArray = {
        EventKey::initialize,
        EventKey::destroy,
        EventKey::tick,
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

    auto handle = LibraryManager::load(filepath);
    if (!handle)
        return;

    LINFO("Adding {} to plugin list", filepath);

    this->_plugins[filepath.string()] = handle;

    LINFO("Loading ", filepath);

    for (const auto &key : EventKeyArray) {
        if (auto symbol = handle->getRawSymbol(key)) {
            LINFO("{} : Loading event {}", filepath, key);
            this->_events[key].push_back(symbol);
        }
    }
}

void PluginManager::load()
{
    LINFO("Loading plugins from {}...", this->_folder);
    if (!std::filesystem::is_directory(this->_folder))
        return;

    for (const auto &filepath : std::filesystem::directory_iterator(_folder)) {
        if (filepath.path().string().ends_with(LibraryManager::extension())) {
            loadPlugin(filepath.path());
        }
    }
    LINFO("Plugins loaded");

    using namespace EventKey;
    onEvent((*this), initialize);
}

void PluginManager::unload()
{
    this->_plugins.clear();
    this->_events.clear();
}

void PluginManager::reload()
{
    this->unload();
    this->load();
}
