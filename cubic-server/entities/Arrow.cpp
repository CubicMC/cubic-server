#include "Arrow.hpp"
#include "Dimension.hpp"
#include "Player.hpp"
#include "protocol/ClientPackets.hpp"
#include "protocol/metadata.hpp"

void Arrow::tick()
{
    constexpr double baseBlocksPerTicks = 1.0 / 8000.0;
    const Vector3<double> position = this->getPosition();
    const Vector3<double> velocity = this->getVelocity();

    const Vector3<double> newVelocity = {
        velocity.x * 0.99,
        velocity.y * 0.99 - (8000.0f / 20.0f),
        velocity.z * 0.99,
    };
    this->setVelocity(newVelocity);

    for (auto &player : _dim->getPlayers()) {
        player->sendEntityVelocity({
            _id,
            (int16_t) _velocity.x,
            (int16_t) _velocity.y,
            (int16_t) _velocity.z,
        });
    }

    const Vector3<double> movement = newVelocity * baseBlocksPerTicks;
    const Vector3<double> newPosition = movement + position;
    this->setPosition(newPosition, false);

    Entity::tick();
}

void Arrow::appendMetadataPacket(std::vector<uint8_t> &data) const
{
    Entity::appendMetadataPacket(data);

    using namespace protocol::entity_metadata;

    addMByte(data, 8, 0x01); // Critical arrow
}
