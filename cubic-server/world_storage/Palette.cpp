#include "Palette.hpp"
#include "logging/Logger.hpp"
#include "world_storage/Section.hpp"

world_storage::BlockPalette::BlockPalette()
{
    // _nameToId.push_back(0);
    // _idCount.emplace(0, world_storage::SECTION_3D_SIZE);
}

world_storage::BiomePalette::BiomePalette()
{
    // _nameToId.push_back(0);
    // _idCount.emplace(0, world_storage::BIOME_SECTION_3D_SIZE);
}

void world_storage::Palette::add(int32_t globalId)
{
    if (std::find(_nameToId.begin(), _nameToId.end(), globalId) == _nameToId.end()) {
        // if (globalId == 0)
        //     _nameToId.insert(_nameToId.begin(), globalId);
        // else
        _nameToId.push_back(globalId);
        _idCount.emplace(globalId, 1);
        return;
    }

    if (!_idCount.contains(globalId))
        _idCount.emplace(globalId, 1);
    else
        _idCount.at(globalId) += 1;
}

void world_storage::Palette::setCount(int32_t globalId, uint32_t count)
{
    if (count == 0)
        return this->removeAll(globalId);
    _idCount.emplace(globalId, count);
}

uint32_t world_storage::Palette::getCount(int32_t globalId) const
{
    if (!_idCount.contains(globalId))
        return 0;
    return _idCount.at(globalId);
}

void world_storage::Palette::removeAll(int32_t globalId)
{
    if (!_idCount.contains(globalId))
        return;

    _idCount.erase(globalId);
    auto it = std::find(_nameToId.begin(), _nameToId.end(), globalId);
    if (it != _nameToId.end() && it == _nameToId.end() - 1)
        _nameToId.erase(it);
}

// TODO: Pas opti, but it's a pain
void world_storage::Palette::remove(int32_t globalId)
{
    if (!_idCount.contains(globalId))
        return;

    if (_idCount.at(globalId) != 0)
        _idCount.at(globalId) -= 1;

    if (_idCount.at(globalId) == 0) {
        _idCount.erase(globalId);
        auto it = std::find(_nameToId.begin(), _nameToId.end(), globalId);
        if (it != _nameToId.end() && it == _nameToId.end() - 1)
            _nameToId.erase(it);
    }
}

uint64_t world_storage::Palette::getTotalCount(bool countZero) const
{
    uint64_t count = 0;
    for (const auto &[key, idCount] : _idCount) {
        if (key == 0 && !countZero)
            continue;
        count += idCount;
    }

    return count;
}
