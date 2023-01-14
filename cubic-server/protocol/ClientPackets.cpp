#include "PacketUtils.hpp"
#include "ClientPackets.hpp"

using namespace protocol;

std::shared_ptr<std::vector<uint8_t>> protocol::createPingResponse(const PingResponse &in)
{
    std::vector<uint8_t> payload;
    serialize(payload, in.payload, addLong);
    auto packet = std::make_shared<std::vector<uint8_t>>();
    // TODO: Use an enum instead of hard-coding the packet ID
    // TODO: Undestand why I have to use a cast here
    finalize(*packet, payload, (int32_t)ClientPacketID::Ping);
    return packet;
}

std::shared_ptr<std::vector<uint8_t>> protocol::createStatusResponse(const StatusResponse &in)
{
    std::vector<uint8_t> payload;
    serialize(payload, in.payload, addString);
    auto packet = std::make_shared<std::vector<uint8_t>>();
    finalize(*packet, payload, (int32_t)ClientPacketID::Status);
    return packet;
}

std::shared_ptr<std::vector<uint8_t>> protocol::createPlayerChatMessage(const PlayerChatMessage &in)
{
    std::vector<uint8_t> payload;
    serialize(payload,
        in.signedContent, addString,
        in.hasUnsignedContent, addBoolean,
        in.unsignedContent, addString,
        in.type, addVarInt,
        in.senderUUID, addUUID,
        in.senderName, addString,
        in.hasTeamName, addBoolean,
        in.teamName, addString,
        in.timestamp, addLong,
        in.salt, addLong,
        in.signature, addArray<uint8_t, addByte>);
    auto packet = std::make_shared<std::vector<uint8_t>>();
    finalize(*packet, payload, (int32_t) ClientPacketID::PlayerChatMessage);
    return packet;
}

std::shared_ptr<std::vector<uint8_t>> protocol::createWorldEvent(const WorldEvent &in)
{
    std::vector<uint8_t> payload;
    serialize(payload,
        in.event, addInt,
        in.position, addPosition,
        in.data, addInt,
        in.disableRelativeVolume, addBoolean
    );
    auto packet = std::make_shared<std::vector<uint8_t>>();
    finalize(*packet.get(), payload, (int32_t) ClientPacketID::WorldEvent);
    return packet;
}

std::shared_ptr<std::vector<uint8_t>> protocol::createCustomSoundEffect(const CustomSoundEffect &in)
{
    std::vector<uint8_t> payload;
    serialize(payload,
        in.name, addIdentifier,
        in.category, addVarInt,
        in.x, addInt,
        in.y, addInt,
        in.z, addInt,
        in.volume, addFloat,
        in.pitch, addFloat,
        in.seed, addLong
    );
    auto packet = std::make_shared<std::vector<uint8_t>>();
    finalize(*packet, payload, (int32_t) ClientPacketID::CustomSoundEffect);
    return packet;
}

std::shared_ptr<std::vector<uint8_t>> protocol::createEntitySoundEffect(const EntitySoundEffect &in)
{
    std::vector<uint8_t> payload;
    serialize(payload,
        in.soundId, addVarInt,
        in.category, addVarInt,
        in.entityId, addVarInt,
        in.volume, addFloat,
        in.pitch, addFloat
    );
    auto packet = std::make_shared<std::vector<uint8_t>>();
    finalize(*packet, payload, (int32_t) ClientPacketID::EntitySoundEffect);
    return packet;
}

std::shared_ptr<std::vector<uint8_t>> protocol::createSoundEffect(const SoundEffect &in)
{
    std::vector<uint8_t> payload;
    serialize(payload,
        in.soundId, addVarInt,
        in.category, addVarInt,
        in.x, addInt,
        in.y, addInt,
        in.z, addInt,
        in.volume, addFloat,
        in.pitch, addFloat,
        in.seed, addLong
    );
    auto packet = std::make_shared<std::vector<uint8_t>>();
    finalize(*packet, payload, (int32_t) ClientPacketID::SoundEffect);
    return packet;
}

std::shared_ptr<std::vector<uint8_t>> protocol::createStopSound(const StopSound &in)
{
    std::vector<uint8_t> payload;
    serialize(payload, in.flags, addByte);
    if (in.flags == 3 || in.flags == 1)
        serialize(payload, in.source, addVarInt);
    if (in.flags == 2 || in.flags == 3)
        serialize(payload, in.sound, addIdentifier);

    auto packet = std::make_shared<std::vector<uint8_t>>();
    finalize(*packet, payload, (int32_t) ClientPacketID::StopSound);
    return packet;
}

std::shared_ptr<std::vector<uint8_t>> protocol::createLoginDisconnect(const Disconnect &in)
{
    std::vector<uint8_t> payload;
    serialize(payload, in.reason, addString);
    auto packet = std::make_shared<std::vector<uint8_t>>();
    finalize(*packet.get(), payload, (int32_t)ClientPacketID::DisconnectLogin);
    return packet;
}

std::shared_ptr<std::vector<uint8_t>> protocol::createPlayDisconnect(const Disconnect &in)
{
    std::vector<uint8_t> payload;
    serialize(payload, in.reason, addString);
    auto packet = std::make_shared<std::vector<uint8_t>>();
    finalize(*packet.get(), payload, (int32_t)ClientPacketID::DisconnectPlay);
    return packet;
}
