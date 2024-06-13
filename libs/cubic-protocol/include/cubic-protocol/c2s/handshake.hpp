#ifndef CUBIC_PROTOCOL_C2S_HANDSHAKE_
#define CUBIC_PROTOCOL_C2S_HANDSHAKE_

#include <cstdint>
#include <string>

namespace cubic::protocol::c2s::handshake {

/**
 * Represents the packet ids used in the handshake state
 */
enum class packet_id : int32_t {
    Handshake = 0,
};

/**
 * Represents a 1:1 mapping of the Handshake packet
 *
 * https://wiki.vg/Protocol#Handshake
 */
struct Handshake {
    int32_t protocol_version;
    std::string server_address;
    uint16_t server_port;
    int32_t next_state;

    /**
     * Tries to parse an handshake packet
     *
     * If the parsing fails then the content of the given structure is undefined
     *
     * @param data Raw incoming data from a client
     * @param available_bytes Number of bytes available in the incoming data
     * @param value Mapping that this function will try to fill
     * @return The number of bytes used to parse the packet
     */
    static auto parse(const uint8_t *data, uint32_t available_bytes, Handshake *value) -> uint32_t;
};

} // namespace cubic::protocol::c2s::handshake

#endif // CUBIC_PROTOCOL_C2S_HANDSHAKE_
