#ifndef CUBIC_PROTOCOL_C2S_HANDSHAKE_
#define CUBIC_PROTOCOL_C2S_HANDSHAKE_

#include <cstdint>
#include <string>

namespace cubic::protocol::c2s::handshake {

enum class packet_id : int32_t {
    Handshake = 0,
};

struct Handshake {
    int32_t protocol_version;
    std::string server_address;
    uint16_t server_port;
    int32_t next_state;

    static auto parse(const uint8_t *data, uint32_t available_bytes, Handshake *value) -> uint32_t;
};

} // namespace cubic::protocol::c2s::handshake

#endif // CUBIC_PROTOCOL_C2S_HANDSHAKE_
