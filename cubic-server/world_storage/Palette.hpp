#ifndef CUBICSERVER_WORLDSTORAGE_PALETTE_HPP
#define CUBICSERVER_WORLDSTORAGE_PALETTE_HPP

#include <algorithm>
#include <cstdint>
#include <vector>

namespace world_storage {

// https://stackoverflow.com/a/23784921
constexpr uint8_t bitsNeeded(int32_t n) { return n <= 1 ? 0 : 1 + bitsNeeded((n + 1) / 2); }

class Palette {
public:
    constexpr Palette() = default;
    constexpr ~Palette() = default;

    constexpr void add(int32_t globalId)
    {
        if (std::find(_nameToId.begin(), _nameToId.end(), globalId) == _nameToId.end()) {
            if (globalId == 0)
                _nameToId.insert(_nameToId.begin(), globalId);
            else
                _nameToId.push_back(globalId);
        }
    }

    constexpr uint64_t getId(int32_t globalId) const
    {
        auto it = std::find(_nameToId.begin(), _nameToId.end(), globalId);
        if (it == _nameToId.end())
            return 0;
        return std::distance(_nameToId.begin(), it);
    }

    virtual uint8_t getBytePerEntry() const = 0;

    constexpr uint64_t size() const { return _nameToId.size(); }

    constexpr std::vector<int32_t>::const_iterator begin() const { return _nameToId.begin(); }

    constexpr std::vector<int32_t>::const_iterator end() const { return _nameToId.end(); }

    constexpr const std::vector<int32_t> &data() const { return _nameToId; }

protected:
    std::vector<int32_t> _nameToId;
};

class BlockPalette : public Palette {
public:
    constexpr BlockPalette() = default;
    constexpr ~BlockPalette() = default;

    constexpr uint8_t getBytePerEntry() const override
    {
        // No palette or single value palette
        if (_nameToId.size() <= 1)
            return 0;
        // Byte per block
        uint8_t bytePerBlock = world_storage::bitsNeeded(_nameToId.size());
        if (bytePerBlock <= 4)
            return 4;
        else if (bytePerBlock <= 8)
            return bytePerBlock;

        // Hard coded cause I don't know the total number of block
        // std::ceil(std::log2(blocks.size()));
        return 15;
    }
};

class BiomePalette : public Palette {
public:
    constexpr BiomePalette() = default;
    constexpr ~BiomePalette() = default;

    constexpr uint8_t getBytePerEntry() const override
    {
        if (_nameToId.size() <= 1)
            return 0;
        auto bytePerBlock = world_storage::bitsNeeded(_nameToId.size());
        if (bytePerBlock <= 3)
            return bytePerBlock;
        return 3;
    }
};

} // namespace world_storage

#endif // CUBICSERVER_WORLDSTORAGE_PALETTE_HPP
