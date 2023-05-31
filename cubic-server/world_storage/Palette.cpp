#include "Palette.hpp"
#include "logging/logging.hpp"
#include "world_storage/Section.hpp"
#include <mutex>

world_storage::BlockPalette::BlockPalette()
{
    _nameToId.emplace_back(0);
    // _idCount.emplace(0, world_storage::SECTION_3D_SIZE);
}

world_storage::BiomePalette::BiomePalette()
{
    _nameToId.emplace_back(0);
    // _idCount.emplace(0, world_storage::BIOME_SECTION_3D_SIZE);
}

world_storage::Palette::Palette(world_storage::Palette &&palette):
    _lock(),
    _nameToId(palette._nameToId)
{
}

void world_storage::Palette::add(int32_t globalId)
{
    // auto it = std::find_if(_idCount.begin(), _idCount.end(), [globalId](const auto &p) {
    //     return p.first == globalId;
    // });
    std::lock_guard _(_lock);
    if (std::find(_nameToId.begin(), _nameToId.end(), globalId) == _nameToId.end()) {
        _nameToId.emplace_back(globalId);
        // if (it == _idCount.end())
        //     _idCount.emplace_back(std::make_pair(globalId, 1));
        // else
        //     it->second++;
        return;
    }

    // if (it == _idCount.end())
    //     _idCount.emplace_back(std::make_pair(globalId, 1));
    // else
    //     it->second += 1;
}

// void world_storage::Palette::setCount(int32_t globalId, uint32_t count)
// {
//     if (count == 0)
//         return this->removeAll(globalId);

//     auto it = std::find_if(_idCount.begin(), _idCount.end(), [globalId](const auto &p) {
//         return p.first == globalId;
//     });

//     if (it == _idCount.end())
//         _idCount.emplace_back(std::make_pair(globalId, count));
//     else
//         it->second = count;
// }

// uint32_t world_storage::Palette::getCount(int32_t globalId) const
// {
//     if (!_idCount.contains(globalId))
//         return 0;
//     return _idCount.at(globalId);
// }

void world_storage::Palette::removeAll(int32_t globalId)
{
    // if (!_idCount.contains(globalId))
    //     return;

    // _idCount.erase(globalId);
    std::lock_guard _(_lock);
    auto it = std::find(_nameToId.begin(), _nameToId.end(), globalId);
    if (it != _nameToId.end() && it == _nameToId.end() - 1)
        _nameToId.erase(it);
}

// TODO: Pas opti, but it's a pain
void world_storage::Palette::remove(int32_t globalId)
{
    // if (!_idCount.contains(globalId))
    //     return;

    // if (_idCount.at(globalId) != 0)
    //     _idCount.at(globalId) -= 1;

    // if (_idCount.at(globalId) == 0) {
    //     _idCount.erase(globalId);
    //     auto it = std::find(_nameToId.begin(), _nameToId.end(), globalId);
    //     if (it != _nameToId.end() && it == _nameToId.end() - 1)
    //         _nameToId.erase(it);
    // }
    std::lock_guard _(_lock);

    auto it = std::find(_nameToId.begin(), _nameToId.end(), globalId);
    while (it != _nameToId.end() && it == _nameToId.end() - 1) {
        _nameToId.erase(it);
        it = std::find(_nameToId.begin(), _nameToId.end(), globalId);
    }
}

// uint64_t world_storage::Palette::getTotalCount(bool countZero) const
// {
//     uint64_t count = 0;
//     for (const auto &[key, idCount] : _idCount) {
//         if (key == 0 && !countZero)
//             continue;
//         count += idCount;
//     }

//     return count;
// }
