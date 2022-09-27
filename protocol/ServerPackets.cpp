#include <optional>

#include "ServerPackets.hpp"
#include "PacketUtils.hpp"
#include "typeSerialization.hpp"

using namespace protocol;

std::shared_ptr<Handshake> protocol::parseHandshake(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<Handshake>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popVarInt, &Handshake::prot_version,
          popString, &Handshake::addr,
          popUnsignedShort, &Handshake::port,
          popVarInt, &Handshake::next_state);
    return h;
}
