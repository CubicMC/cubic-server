#ifndef CUBIC_PROTOCOL_PRIMITIVES_STRING_
#define CUBIC_PROTOCOL_PRIMITIVES_STRING_

// TODO: Check if any of those can be forward declared
#include <cstdint>
#include <optional>
// TODO: Check if we want to use std::string for string parsing
#include <string>

namespace cubic::protocol::primitives::string {

auto parse(const uint8_t *data, uint32_t available_bytes, std::string *value) -> uint32_t;
auto parse(uint8_t *const *data, uint32_t available_bytes) -> std::optional<std::string>;
auto parse(
    const uint8_t *data, uint32_t available_bytes, std::string *value, int32_t min, int32_t max
) -> uint32_t;
auto parse(uint8_t *const *data, uint32_t available_bytes, int32_t min, int32_t max)
    -> std::optional<std::string>;

} // namespace cubic::protocol::primitives::string

#endif // CUBIC_PROTOCOL_PRIMITIVES_STRING_
