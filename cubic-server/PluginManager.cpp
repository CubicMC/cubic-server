#include "PluginManager.hpp"

#include <dlfcn.h>
#include <fstream>
#include <filesystem>
#include <array>

PluginManager::PluginManager(std::string &folder) : _folder(folder)
{

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
    }
    for (const auto &key : EventKeyArray) {
        rawptr = dlsym(nhandle, key);
        if (rawptr) {
            this->_events[key].push_back(rawptr);
        }
    }
    dlclose(nhandle);
}

void PluginManager::load(void)
{
    if (!std::filesystem::is_directory(this->_folder))
        return;

    for (const auto &filepath : std::filesystem::directory_iterator(_folder)) {
        if (filepath.path().string().ends_with(".so")) {
            loadPlugin(filepath.path().string());
        }
    }
}

void PluginManager::reload(void)
{
    this->_events.clear();
    this->load();
}
