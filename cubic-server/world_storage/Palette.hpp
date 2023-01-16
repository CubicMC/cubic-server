#ifndef WORLD_STORAGE_PALETTE_HPP
#define WORLD_STORAGE_PALETTE_HPP

#include <vector>
#include <cstdint>
#include <map>
#include <world_storage/Block.hpp>

namespace world_storage {

class Palette
{
public:
    Palette(uint8_t bytePerBlock = 4): _bytePerBlock(bytePerBlock) {}
    ~Palette() = default;

    void addBlock(const Block &block);

    uint64_t getBlockId(uint32_t globalId) const;
    uint64_t getBlockId(const std::string &name) const;
    uint64_t getBlockId(const Block &block) const;

    Block getBlock(uint64_t id) const;

    uint8_t getBytePerBlock() const;

    void serialize(std::vector<uint8_t> &out) const;

private:
    std::vector<std::string> _nameToId;
    const uint8_t _bytePerBlock;
};

} // namespace world_storage

#endif // WORLD_STORAGE_PALETTE_HPP
