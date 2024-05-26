#ifndef CUBIC_PROTOCOL_PRIMITIVES_
#define CUBIC_PROTOCOL_PRIMITIVES_

// TODO: Check if any of those can be forward declared
#include <cstdint>
#include <optional>

namespace cubic::protocol::primitives {

namespace varint {
auto parse(const uint8_t *data, uint32_t available_bytes, int32_t *value) -> uint32_t;
auto parse(uint8_t *const *data, uint32_t available_bytes) -> std::optional<int32_t>;
auto parse(const uint8_t *data, uint32_t available_bytes, int32_t *value, int32_t min, int32_t max)
    -> uint32_t;
auto parse(uint8_t *const *data, uint32_t available_bytes, int32_t min, int32_t max)
    -> std::optional<int32_t>;
} // namespace varint

} // namespace cubic::protocol::primitives

#endif // CUBIC_PROTOCOL_PRIMITIVES_
