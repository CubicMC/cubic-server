#include "Palette.hpp"
#include "ChunkColumn.hpp"
#include "globalPalette_TEMP.hpp"
#include "protocol/serialization/addPrimaryType.hpp"

void world_storage::Palette::addBlock(const Block &block)
{
    if (block.name == "minecraft:air")
        return;
    if (std::find(_nameToId.begin(), _nameToId.end(), block.toString()) == _nameToId.end())
        _nameToId.push_back(block.toString());
}

uint64_t world_storage::Palette::getBlockId(uint32_t globalId) const
{
    auto block = Block(world_storage::getBlockFromGlobalPaletteId(globalId));
    return this->getBlockId(block);
}

uint64_t world_storage::Palette::getBlockId(const std::string &name) const
{
    auto it = std::find(_nameToId.begin(), _nameToId.end(), name);
    if (it == _nameToId.end())
        return 0;
    return std::distance(_nameToId.begin(), it);
}

uint64_t world_storage::Palette::getBlockId(const Block &block) const
{
    return this->getBlockId(block.toString());
}

world_storage::Block world_storage::Palette::getBlock(uint64_t id) const
{
    return Block(_nameToId.at(id));
}

uint8_t world_storage::Palette::getBytePerBlock() const
{
    return _bytePerBlock;
}

void world_storage::Palette::serialize(std::vector<uint8_t> &out) const
{
    // Byte per block
    if (this->_bytePerBlock == 0)
        return;
    if (this->_bytePerBlock <= 4)
        out.push_back(4);
    else if (this->_bytePerBlock <= 8)
        out.push_back(this->_bytePerBlock);
    else
        out.push_back(15); // HARD CODED BECAUSE I DON'T WANT TO THINK ABOUT LOGARITHMS

    auto size = _nameToId.size();
    if (size != 1)
        protocol::addVarInt(out, _nameToId.size());

    for (auto &name : _nameToId)
        protocol::addVarInt(out, getGlobalPaletteIdFromBlock(name));
}
