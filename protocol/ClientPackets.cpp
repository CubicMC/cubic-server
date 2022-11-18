#include "PacketUtils.hpp"
#include "ClientPackets.hpp"
#include "../cubic-server/Chat.hpp"

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

std::shared_ptr<std::vector<uint8_t>> protocol::disconnectPlayer(const DisconnectPlayer &in)
{
    std::vector<uint8_t> reason;
    //serialize(reason, in.reason, addString);
    auto packet = std::make_shared<std::vector<uint8_t>>();
    finalize(*packet.get(), reason, (int32_t)ClientPacketID::DISCONNECT);
    return packet;
}