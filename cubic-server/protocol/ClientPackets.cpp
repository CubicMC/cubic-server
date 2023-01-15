#include "PacketUtils.hpp"
#include "ClientPackets.hpp"
#include "protocol/serialization/addPrimaryType.hpp"
#include <cstdint>
#include <memory>
#include <vector>

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

std::shared_ptr<std::vector<uint8_t>> protocol::createLoginSuccess(const LoginSuccess &in)
{
    std::vector<uint8_t> payload;
    serialize(payload, in.uuid, addUUID,
        in.username, addString,
        in.numberOfProperties, addVarInt
    );

    // in.name, addString,
    // in.value, addString,
    // in.isSigned, addBoolean
    if (in.isSigned)
        serialize(payload, in.signature.value(), addString);
    auto packet = std::make_shared<std::vector<uint8_t>>();
    finalize(*packet.get(), payload, (int32_t)ClientPacketID::LoginSuccess);
    return packet;
}

std::shared_ptr<std::vector<uint8_t>> protocol::createLoginPlay(const LoginPlay &in)
{
    std::vector<uint8_t> payload;
    serialize(payload,
        in.entityID, addInt,
        in.isHardcore, addBoolean,
        in.gamemode, addByte,
        in.previousGamemode, addByte,
        in.dimensionNames, addArray<std::string, addString>,
        in.registryCodec, addNBT<nbt::Compound>,
        in.dimensionType, addString,
        in.dimensionName, addString,
        in.hashedSeed, addLong,
        in.maxPlayers, addVarInt,
        in.viewDistance, addVarInt,
        in.simulationDistance, addVarInt,
        in.reducedDebugInfo, addBoolean,
        in.enableRespawnScreen, addBoolean,
        in.isDebug, addBoolean,
        in.isFlat, addBoolean,
        in.hasDeathLocation, addBoolean);
    if (in.hasDeathLocation)
        serialize(payload,
            in.deathDimensionName.value(), addString,
            in.deathLocation.value(), addPosition);
    auto packet = std::make_shared<std::vector<uint8_t>>();
    finalize(*packet.get(), payload, (int32_t)ClientPacketID::LoginPlay);
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

std::shared_ptr<SynchronizePlayerPosition> protocol::parseSynchronizePlayerPosition(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<SynchronizePlayerPosition>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
        popDouble, &SynchronizePlayerPosition::x,
        popDouble, &SynchronizePlayerPosition::y,
        popDouble, &SynchronizePlayerPosition::z,
        popFloat, &SynchronizePlayerPosition::yaw,
        popFloat, &SynchronizePlayerPosition::pitch,
        popByte, &SynchronizePlayerPosition::flags,
        popVarInt, &SynchronizePlayerPosition::teleportId,
        popBoolean, &SynchronizePlayerPosition::dismountVehicle);
    return h;
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
        in.pitch, addFloat,
        in.seed, addLong
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

std::shared_ptr<std::vector<uint8_t>> protocol::createSpawnPlayer(const SpawnPlayer &in)
{
    std::vector<uint8_t> payload;

    serialize(payload,
              in.entity_id, addVarInt,
              in.player_uuid, addUUID,
              (long) in.x, addLong,
              (long) in.y, addLong,
              (long) in.z, addLong,
              in.yaw, addByte,
              in.pitch, addByte
    );

    auto packet = std::make_shared<std::vector<uint8_t>>();
    finalize(*packet.get(), payload, (int32_t)ClientPacketID::SpawnPlayer);

    return packet;
}

std::shared_ptr<std::vector<uint8_t>> protocol::createUpdateTime(const UpdateTime &in)
{
    std::vector<uint8_t> payload;

    serialize(payload,
              in.world_age, addLong,
              in.time_of_day, addLong
    );

    auto packet = std::make_shared<std::vector<uint8_t>>();
    finalize(*packet.get(), payload, (int32_t)ClientPacketID::UpdateTime);

    return packet;
}
std::shared_ptr<std::vector<uint8_t>> protocol::createKeepAlive(long id)
{
    std::vector<uint8_t> payload;
    serialize(payload, id, addLong);
    auto packet = std::make_shared<std::vector<uint8_t>>();
    finalize(*packet, payload, (int32_t) ClientPacketID::KeepAlive);
    return packet;
}

std::shared_ptr<std::vector<uint8_t>> protocol::createPluginMessageResponse(const PluginMessageResponse &in)
{
    std::vector<uint8_t> payload;
    serialize(payload, in.channel, addIdentifier);
    // TODO: Just look at it
    for (auto i : in.data)
        payload.push_back(i);
    
    auto packet = std::make_shared<std::vector<uint8_t>>();
    finalize(*packet, payload, (int32_t) ClientPacketID::PluginMessage);
    return packet;
}
