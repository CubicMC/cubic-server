#ifndef CUBICSERVER_WORLDSTORAGE_PALETTE_HPP
#define CUBICSERVER_WORLDSTORAGE_PALETTE_HPP

#include <algorithm>
#include <cstdint>
#include <mutex>
#include <numeric>
#include <unordered_map>
#include <vector>

namespace world_storage {

// https://stackoverflow.com/a/23784921
constexpr uint8_t bitsNeeded(int32_t n) { return n <= 1 ? 0 : 1 + bitsNeeded((n + 1) / 2); }

class Palette {
public:
    Palette() = default;
    Palette(Palette &&palette);
    virtual ~Palette() = default;

    constexpr uint64_t getId(int32_t globalId) const
    {
        auto it = std::find(_nameToId.begin(), _nameToId.end(), globalId);
        if (it == _nameToId.end())
            return 0;
        return std::distance(_nameToId.begin(), it);
    }

    constexpr int32_t getGlobalId(uint64_t localId) const
    {
        if (localId >= _nameToId.size())
            return -1;
        return _nameToId[localId];
    }

    void add(int32_t globalId);
    // void setCount(int32_t globalId, uint32_t count);
    // uint32_t getCount(int32_t globalId) const;
    void removeAll(int32_t globalId);
    void remove(int32_t globalId);
    // uint64_t getTotalCount(bool countZero = false) const;

    virtual uint8_t getBits() const = 0;

    constexpr uint64_t size() const { return _nameToId.size(); }
    constexpr std::vector<int32_t>::const_iterator begin() const { return _nameToId.begin(); }
    constexpr std::vector<int32_t>::const_iterator end() const { return _nameToId.end(); }
    constexpr const std::vector<int32_t> &data() const { return _nameToId; }
    constexpr int32_t operator[](uint64_t index) const { return _nameToId[index]; }
    constexpr void clear() { _nameToId.clear(); }

protected:
    mutable std::mutex _lock;
    std::vector<int32_t> _nameToId;
    // std::vector<std::pair<int32_t, uint32_t>> _idCount;
};

class BlockPalette : public Palette {
public:
    BlockPalette();
    BlockPalette(BlockPalette &&palette) = default;
    ~BlockPalette() = default;

    constexpr uint8_t getBits() const override
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
    BiomePalette();
    BiomePalette(BiomePalette &&palette) = default;
    ~BiomePalette() = default;

    constexpr uint8_t getBits() const override
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
