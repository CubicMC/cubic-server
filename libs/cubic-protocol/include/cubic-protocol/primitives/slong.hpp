#ifndef CUBIC_PROTOCOL_PRIMITIVES_SLONG_
#define CUBIC_PROTOCOL_PRIMITIVES_SLONG_

#include <cstdint>

namespace cubic::protocol::primitives::slong {

auto parse(const uint8_t *data, uint32_t available_bytes, int64_t *value) -> uint32_t;
auto parse(const uint8_t *data, uint32_t available_bytes, int64_t *value, int64_t min, int64_t max)
    -> uint32_t;

} // namespace cubic::protocol::primitives::slong

#endif // CUBIC_PROTOCOL_PRIMITIVES_SLONG_
