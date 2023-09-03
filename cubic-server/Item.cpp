#include "Item.hpp"
#include "Dimension.hpp"
#include "logging/logging.hpp"
#include "protocol/ClientPackets.hpp"
#include "protocol/metadata.hpp"

void Item::tick() { }

void Item::dropItem(const Vector3<double> &pos)
{
    LDEBUG("Item created at (x: {}, y: {}, z: {}) with entity id {} and item id {}", pos.x, pos.y, pos.z, _id, _slot.itemID);
    this->setPosition(pos, false);
    // _dim->addEntity(shared_from_this());
    _dim->spawnEntity(shared_from_this());
}

void Item::appendMetadataPacket(std::vector<uint8_t> &data) const
{
    Entity::appendMetadataPacket(data);

    using namespace protocol::entity_metadata;

    addMSlot(data, 8, _slot);
}
