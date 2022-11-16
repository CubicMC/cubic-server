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
    finalize(*packet.get(), payload, (int32_t)ClientPacketID::PING);
    return packet;
}

std::shared_ptr<std::vector<uint8_t>> protocol::createStatusResponse(const StatusResponse &in)
{
    std::vector<uint8_t> payload;
    serialize(payload, in.payload, addString);
    auto packet = std::make_shared<std::vector<uint8_t>>();
    finalize(*packet.get(), payload, (int32_t)ClientPacketID::STATUS);
    return packet;
}

std::shared_ptr<std::vector<uint8_t>> protocol::createPlayerChatMessage(const PlayerChatMessage &in)
{
    std::vector<uint8_t> payload;
    serialize(payload, in.signedContent, addString);
    serialize(payload, in.hasUnsignedContent, addBoolean);
    serialize(payload, in.unsignedContent, addString);
    serialize(payload, in.type, addVarInt);
    serialize(payload, in.senderUUID, addUUID);
    serialize(payload, in.senderName, addString);
    serialize(payload, in.hasTeamName, addBoolean);
    serialize(payload, in.teamName, addString);
    serialize(payload, in.timestamp, addLong);
    serialize(payload, in.salt, addLong);
    serialize(payload, in.signatureLength, addVarInt);
    serialize(payload, in.signature, addByteArray);
    auto packet = std::make_shared<std::vector<uint8_t>>();
    finalize(*packet.get(), payload, (int32_t) ClientPacketID::PlayerChatMessage);
    return packet;
}
