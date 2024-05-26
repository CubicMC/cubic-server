#ifndef CUBIC_PROTOCOL_PRIMITIVES_VARINT_
#define CUBIC_PROTOCOL_PRIMITIVES_VARINT_

// TODO: Check if any of those can be forward declared
#include <cstdint>
#include <optional>

namespace cubic::protocol::primitives::varint {

auto parse(const uint8_t *data, uint32_t available_bytes, int32_t *value) -> uint32_t;
auto parse(uint8_t *const *data, uint32_t available_bytes) -> std::optional<int32_t>;
auto parse(const uint8_t *data, uint32_t available_bytes, int32_t *value, int32_t min, int32_t max)
    -> uint32_t;
auto parse(uint8_t *const *data, uint32_t available_bytes, int32_t min, int32_t max)
    -> std::optional<int32_t>;

} // namespace cubic::protocol::primitives::varint

#endif // CUBIC_PROTOCOL_PRIMITIVES_VARINT_
