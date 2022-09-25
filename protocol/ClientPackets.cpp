#include "PacketUtils.hpp"
#include "ClientPackets.hpp"

using namespace protocol;

std::shared_ptr<std::vector<uint8_t>> createPingResponse(const PingResponse &in)
{
    std::vector<uint8_t> payload;
    serialize(payload, in.payload, addLong);
    auto packet = std::make_shared<std::vector<uint8_t>>();
    // TODO: Use an enum instead of hard-coding the packet ID
    finalize(*packet.get(), payload, 0x01);
    return packet;
}
