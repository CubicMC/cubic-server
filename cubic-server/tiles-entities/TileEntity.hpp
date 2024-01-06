#ifndef CUBICSERVER_TILEENTITY_HPP
#define CUBICSERVER_TILEENTITY_HPP

#include "TileEntityList.hpp"
#include "nbt.h"
#include "protocol/ClientPackets.hpp"
#include "protocol/Structures.hpp"
#include "types.hpp"
#include <cstdint>
#include <string>

namespace tile_entity {
class TileEntity {
public:
    TileEntity(const std::string &id, const Position &position, nbt_tag_t *nbt = nullptr):
        position(position),
        id(id),
        blockEntityType(convertBlockNameToBlockEntityType(id)),
        _nbt(nbt)
    {
    }

    TileEntity(const TileEntity &) = default;

    virtual ~TileEntity()
    {
        if (_nbt)
            nbt_free_tag(_nbt);
    };

    /**
     * @brief Update the nbt tag of the tile entity with the current state of the tile entity
     *
     * @return TileEntity*
     */
    virtual TileEntity *updateNbt() { return this; };

    /**
     * @brief Get the nbt of the tile entity
     *
     * @return const nbt_tag_t*
     */
    const nbt_tag_t *getNbt() const { return _nbt; }

    /**
     * @brief Tick the tile entity
     */
    virtual void tick() = 0;

    /**
     * @brief Translate the tile entity to a block entity
     *
     * @return const protocol::BlockEntity
     */
    virtual const protocol::BlockEntity toBlockEntity() const final
    {
        return protocol::BlockEntity {
            .sectionCoordinate = int8_t(((position.x & 15) << 4) | (position.z & 15)),
            .height = int16_t(position.y),
            .type = static_cast<int>(blockEntityType),
            .data = _nbt,
        };
    }

    /**
     * @brief Translate the tile entity to a block entity data
     *
     * @return const protocol::BlockEntityData
     */
    virtual const protocol::BlockEntityData toBlockEntityData() const final
    {
        return protocol::BlockEntityData {
            .location = position,
            .type = static_cast<int>(blockEntityType),
            .nbtData = _nbt,
        };
    }

    /**
     * @brief Return a boolean that indicate if the blockId need to be updated and consume the boolean
     *
     * @return bool
     */
    virtual bool needBlockUpdate() final
    {
        if (_needBlockUpdate) {
            _needBlockUpdate = false;
            return true;
        }
        return false;
    }

    /**
     * @brief Get the block id of the tile entity
     *
     * @return BlockId
     */
    virtual BlockId getBlockId() const = 0;

    const Position position;
    const std::string id;
    const TileEntityType blockEntityType = TileEntityType::UnknownType;

protected:
    bool _keepPacked = false;
    nbt_tag_t *_nbt = nullptr;
    bool _needBlockUpdate = false;
};
}

#endif // CUBICSERVER_TILEENTITY_HPP
