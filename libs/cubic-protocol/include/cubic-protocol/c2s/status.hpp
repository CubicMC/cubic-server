#ifndef CUBIC_PROTOCOL_C2S_STATUS_
#define CUBIC_PROTOCOL_C2S_STATUS_

#include <cstdint>

namespace cubic::protocol::c2s::status {

enum class packet_id : int32_t {
    StatusRequest = 0,
    PingRequest = 1,
};

struct StatusRequest {
    uint8_t dummy = 42;
};

struct PingRequest {
    int64_t payload;

    static auto parse(const uint8_t *data, uint32_t available_bytes, PingRequest *value)
        -> uint32_t;
};

} // namespace cubic::protocol::c2s::status

#endif // CUBIC_PROTOCOL_C2S_STATUS_
