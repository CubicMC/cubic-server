#include "Item.hpp"
#include "Dimension.hpp"
#include "logging/logging.hpp"
#include "protocol/ClientPackets.hpp"

void Item::tick() { }

void Item::dropItem(const Vector3<double> &pos)
{
    LDEBUG("Item created at (x: {}, y: {}, z: {}) with entity id {} and item id {}", pos.x, pos.y, pos.z, _id, _slot.itemID);
    this->setPosition(pos, false);
    // _dim->addEntity(shared_from_this());
    _dim->spawnEntity(shared_from_this());
    _dim->addEntityMetadata({_id, {{8, protocol::SetEntityMetadata::EntityMetadata::Type::Slot, _slot}}});
}
