#ifndef CUBIC_PROTOCOL_C2S_STATUS_
#define CUBIC_PROTOCOL_C2S_STATUS_

#include <cstdint>

namespace cubic::protocol::c2s::status {

/**
 * Represents the packet ids used in the status state
 */
enum class packet_id : int32_t {
    StatusRequest = 0,
    PingRequest = 1,
};

/**
 * Dummy structure used for status requests
 *
 * We need that structure even though it doesn't do anything to avoid problems
 * with the parsing and callback dispatch that cubic-server does as that packet
 * is normally completely empty
 */
struct StatusRequest {
    uint8_t dummy = 42;
};

/**
 * Represents a 1:1 mapping of the PingRequest (status) packet
 *
 * https://wiki.vg/Protocol#Ping_Request_.28status.29
 */
struct PingRequest {
    int64_t payload;

    /**
     * Tries to parse an PingRequest packet
     *
     * If the parsing fails then the content of the given structure is undefined
     *
     * @param data Raw incoming data from a client
     * @param available_bytes Number of bytes available in the incoming data
     * @param value Mapping that this function will try to fill
     * @return The number of bytes used to parse the packet
     */
    static auto parse(const uint8_t *data, uint32_t available_bytes, PingRequest *value)
        -> uint32_t;
};

} // namespace cubic::protocol::c2s::status

#endif // CUBIC_PROTOCOL_C2S_STATUS_
