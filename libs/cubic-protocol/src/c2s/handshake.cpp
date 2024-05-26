#include "cubic-protocol/c2s/handshake.hpp"
#include "cubic-protocol/primitives/string.hpp"
#include "cubic-protocol/primitives/ushort.hpp"
#include "cubic-protocol/primitives/varint.hpp"
#include "cubic-protocol/utils.hpp"

namespace cubic::protocol::c2s::handshake {

auto Handshake::parse(const uint8_t *data, uint32_t available_bytes, Handshake *value) -> uint32_t
{
    CUBIC_INIT_BASIC_PACKET_PARSER();

    CUBIC_PPARSE(varint, &value->protocol_version);
    CUBIC_PPARSE_RANGE(string, &value->server_address, 0, 255);
    CUBIC_PPARSE(ushort, &value->server_port);
    CUBIC_PPARSE_RANGE(varint, &value->next_state, 0, 1);

    CUBIC_END_BASIC_PACKET_PARSER();
}

} // namespace cubic::protocol::c2s::handshake
