#include "cubic-protocol/c2s/status.hpp"
#include "cubic-protocol/primitives/slong.hpp"
#include "cubic-protocol/utils.hpp"

namespace cubic::protocol::c2s::status {

auto PingRequest::parse(const uint8_t *data, uint32_t available_bytes, PingRequest *value)
    -> uint32_t
{
    CUBIC_INIT_BASIC_PACKET_PARSER();

    CUBIC_PPARSE(slong, &value->payload);

    CUBIC_END_BASIC_PACKET_PARSER();
}

} // namespace cubic::protocol::c2s::status
