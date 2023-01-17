#ifndef WORLD_STORAGE_PALETTE_HPP
#define WORLD_STORAGE_PALETTE_HPP

#include <vector>
#include <cstdint>
#include <algorithm>
#include <map>

#include "world_storage/Block.hpp"
#include "globalPalette_TEMP.hpp"
namespace world_storage {

class Palette
{
public:
    constexpr Palette(uint8_t bytePerBlock = 4): _bytePerBlock(bytePerBlock) {}
    constexpr ~Palette() = default;

    // Can't be constexpr because of Block
    void addBlock(const Block &block);
    uint64_t getBlockId(const Block &block) const;
    Block getBlock(uint64_t id) const;

    constexpr void addBlock(const std::string &name)
    {
        this->addBlock(getGlobalPaletteIdFromBlockName(name));
    }

    constexpr void addBlock(uint32_t globalId)
    {
        if (std::find(_nameToId.begin(), _nameToId.end(), globalId) == _nameToId.end())
            _nameToId.push_back(globalId);
    }

    constexpr uint64_t getBlockId(uint32_t globalId) const
    {
        auto it = std::find(_nameToId.begin(), _nameToId.end(), globalId);
        if (it == _nameToId.end())
            return 0;
        return std::distance(_nameToId.begin(), it);
    }

    constexpr uint64_t getBlockId(const std::string &name) const
    {
        return this->getBlockId(getGlobalPaletteIdFromBlockName(name));
    }

    constexpr uint8_t getBytePerBlock() const
    {
        return _bytePerBlock;
    }

    constexpr uint64_t size() const
    {
        return _nameToId.size();
    }

    constexpr std::vector<uint32_t>::const_iterator begin() const
    {
        return _nameToId.begin();
    }

    constexpr std::vector<uint32_t>::const_iterator end() const
    {
        return _nameToId.end();
    }

private:
    std::vector<uint32_t> _nameToId;
    const uint8_t _bytePerBlock;
};

} // namespace world_storage

#endif // WORLD_STORAGE_PALETTE_HPP
