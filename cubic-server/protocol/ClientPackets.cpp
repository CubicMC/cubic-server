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

std::shared_ptr<std::vector<uint8_t>> protocol::createLoginSuccess(const LoginSuccess &in)
{
    std::vector<uint8_t> payload;
    serialize(payload, in.uuid, addUUID,
        in.username, addString,
        in.numberOfProperties, addVarInt,
        in.name, addString,
        in.value, addString,
        in.isSigned, addBoolean);
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
        in.entityID, addVarInt,
        in.isHardcore, addBoolean,
        in.gamemode, addByte,
        in.previousGamemode, addByte,
        in.dimensionCount, addVarInt,
        in.dimensionNames, addStringArray,
        // in.registryCodec, addNBTCompound,
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