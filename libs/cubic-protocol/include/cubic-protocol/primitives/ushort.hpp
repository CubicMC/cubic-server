#ifndef CUBIC_PROTOCOL_PRIMITIVES_USHORT_
#define CUBIC_PROTOCOL_PRIMITIVES_USHORT_

// TODO: Check if any of those can be forward declared
#include <cstdint>
#include <optional>

namespace cubic::protocol::primitives::ushort {

auto parse(const uint8_t *data, uint32_t available_bytes, uint16_t *value) -> uint32_t;
auto parse(uint8_t **data, uint32_t available_bytes, uint16_t *value) -> std::optional<uint16_t>;
auto parse(
    const uint8_t *data, uint32_t available_bytes, uint16_t *value, uint16_t min, uint16_t max
) -> uint32_t;
auto parse(uint8_t **data, uint32_t available_bytes, uint16_t min, uint16_t max)
    -> std::optional<uint16_t>;

} // namespace cubic::protocol::primitives::ushort

#endif // CUBIC_PROTOCOL_PRIMITIVES_USHORT_
