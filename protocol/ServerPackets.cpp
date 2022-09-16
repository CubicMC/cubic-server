#include <optional>

#include "ServerPackets.hpp"
#include "ParsePacket.hpp"
#include "utils.hpp"

using namespace protocol;

std::optional<std::shared_ptr<Handshake>> protocol::parseHandshake(std::vector<uint8_t> &buffer)
{
    static const auto h = ParsePacket<Handshake>()
                              .prop<int32_t>(popVarInt, offsetof(Handshake, prot_version))
                              .prop<std::string>(popString, offsetof(Handshake, addr))
                              .prop<uint16_t>(popUnsignedShort, offsetof(Handshake, port))
                              .prop<int32_t>(popVarInt, offsetof(Handshake, next_state));

    return h.parse(buffer);
}
