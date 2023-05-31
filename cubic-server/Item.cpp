#include "Item.hpp"
#include "Dimension.hpp"
#include "logging/logging.hpp"
#include "protocol/ClientPackets.hpp"

void Item::tick() { }

void Item::dropItem(const Vector3<double> &pos)
{
    LDEBUG("Item created at (x: {}, y: {}, z: {}) with id {}", pos.x, pos.y, pos.z, _id);
    this->setPosition(pos, true);
    _dim->addEntity(shared_from_this());
    _dim->spawnEntity(shared_from_this());
    _dim->addEntityMetadata({_id, {{8, protocol::SetEntityMetadata::EntityMetadata::Type::Slot, {true, _itemId, 1}}}});
}
