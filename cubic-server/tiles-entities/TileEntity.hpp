#ifndef CUBICSERVER_TILEENTITY_HPP
#define CUBICSERVER_TILEENTITY_HPP

#include "nbt.h"
#include "protocol/ClientPackets.hpp"
#include "protocol/Structures.hpp"
#include "types.hpp"
#include <cstdint>
#include <string>

class TileEntity {
public:
    TileEntity(const std::string &id, BlockId blockId, const Position &position, nbt_tag_t *nbt = nullptr):
        position(position),
        id(id),
        blockId(blockId),
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
    virtual void tick() {};

    /**
     * @brief Translate the tile entity to a block entity
     *
     * @return const protocol::BlockEntity
     */
    const protocol::BlockEntity toBlockEntity() const
    {
        return protocol::BlockEntity {
            .sectionCoordinate = int8_t(((position.x & 15) << 4) | (position.z & 15)),
            .height = int16_t(position.y),
            .type = blockId,
            .data = _nbt,
        };
    }

    /**
     * @brief Translate the tile entity to a block entity data
     *
     * @return const protocol::BlockEntityData
     */
    const protocol::BlockEntityData toBlockEntityData() const
    {
        return protocol::BlockEntityData {
            .location = position,
            .type = blockId,
            .nbtData = _nbt,
        };
    }

    const Position position;
    const std::string id;
    const BlockId blockId = 0;

protected:
    bool _keepPacked = false;
    nbt_tag_t *_nbt = nullptr;
};

#endif // CUBICSERVER_TILEENTITY_HPP
