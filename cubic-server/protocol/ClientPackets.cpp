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
    finalize(*packet.get(), payload, (int32_t)ClientPacketID::ping);
    return packet;
}

std::shared_ptr<std::vector<uint8_t>> protocol::createStatusResponse(const StatusResponse &in)
{
    std::vector<uint8_t> payload;
    serialize(payload, in.payload, addString);
    auto packet = std::make_shared<std::vector<uint8_t>>();
    finalize(*packet.get(), payload, (int32_t)ClientPacketID::status);
    return packet;
}

std::shared_ptr<std::vector<uint8_t>> protocol::createPlayerChatMessage(const PlayerChatMessage &in)
{
    std::vector<uint8_t> payload;
    serialize(payload, in.signedContent, addString,
        in.hasUnsignedContent, addBoolean,
        in.unsignedContent, addString,
        in.type, addVarInt,
        in.senderUUID, addUUID,
        in.senderName, addString,
        in.hasTeamName, addBoolean,
        in.teamName, addString,
        in.timestamp, addLong,
        in.salt, addLong,
        in.signatureLength, addVarInt,
        in.signature, addByteArray);
    auto packet = std::make_shared<std::vector<uint8_t>>();
    finalize(*packet.get(), payload, (int32_t) ClientPacketID::PlayerChatMessage);
    return packet;
}

std::shared_ptr<std::vector<uint8_t>> protocol::createDisconnectPlayerReason(const DisconnectReason &in)
{
    std::vector<uint8_t> payload;
    serialize(payload, in.reason, addString);
    auto packet = std::make_shared<std::vector<uint8_t>>();
    finalize(*packet.get(), payload, (int32_t)ClientPacketID::disconnect);
    return packet;
}