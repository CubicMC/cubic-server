#include "Arrow.hpp"
#include "Dimension.hpp"
#include "protocol/ClientPackets.hpp"
#include "protocol/metadata.hpp"

void Arrow::tick() { Entity::tick(); }

void Arrow::appendMetadataPacket(std::vector<uint8_t> &data) const
{
    Entity::appendMetadataPacket(data);

    using namespace protocol::entity_metadata;

    addMByte(data, 8, 0x01); // Critical arrow
}
