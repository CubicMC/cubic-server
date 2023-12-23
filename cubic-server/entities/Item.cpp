#include "Item.hpp"
#include "Dimension.hpp"
#include "logging/logging.hpp"
#include "protocol/ClientPackets.hpp"
#include "protocol/metadata.hpp"

void Item::tick()
{
    Entity::tick();

    if (_nbTicksBeforePickable > 0)
        _nbTicksBeforePickable--;
}

void Item::dropItem(const Vector3<double> &pos, bool isDroppedWillinglyByEntity)
{
    LDEBUG("Item created at (x: {}, y: {}, z: {}) with entity id {} and item id {}", pos.x, pos.y, pos.z, _id, _slot.itemID);
    this->forceSetPosition(pos);
    this->_nbTicksBeforePickable = isDroppedWillinglyByEntity ? 40 : 10; // When dropped by player, dolphin or fox. Else it is 10 ticks
    // _dim->addEntity(shared_from_this());
    _dim->spawnEntity(shared_from_this());
}

void Item::appendMetadataPacket(std::vector<uint8_t> &data) const
{
    Entity::appendMetadataPacket(data);

    using namespace protocol::entity_metadata;

    addMSlot(data, 8, _slot);
}
