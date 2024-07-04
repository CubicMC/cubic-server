#ifndef CUBIC_PROTOCOL_PRIMITIVES_VARINT_
#define CUBIC_PROTOCOL_PRIMITIVES_VARINT_

#include <cstdint>
#include <vector>

namespace cubic::protocol::primitives::varint {

/**
 * Calculates the number of bytes used by a given value as a varint
 *
 * @param value The value to get the size of as a varint
 * @return The number of bytes used by the given value as a varint
 */
auto get_num_bytes(int32_t value) -> uint8_t;

/**
 * Tries to serialize the given value to a byte buffer
 *
 * @param out Byte buffer where the data will be appended to
 * @param value Value to be serialized
 */
auto serialize(std::vector<uint8_t> &out, int32_t value) -> void;

/**
 * Tries to serialize the given value to a byte buffer
 *
 * @param out Byte buffer where the data will be written to
 * @param value Value to be serialized
 */
auto serialize(uint8_t *out, int32_t value) -> void;

/**
 * Tries to parse a varint
 *
 * If the parsing fails then the content of the given value is undefined
 *
 * @param data Raw incoming data from a client
 * @param available_bytes Number of bytes available in the incoming data
 * @param value Mapping that the function will try to fill
 * @return The number of bytes used to parse the primitive
 */
auto parse(const uint8_t *data, uint32_t available_bytes, int32_t *value) -> uint32_t;

/**
 * Tries to parse a varint with bounds
 *
 * If the parsing fails then the content of the given value is undefined
 *
 * @param data Raw incoming data from a client
 * @param available_bytes Number of bytes available in the incoming data
 * @param value Mapping that the function will try to fill
 * @param min Minimum value that the parsing should accept from the value
 * @param mam Maximum value that the parsing should accept from the value
 * @return The number of bytes used to parse the primitive
 */
auto parse(const uint8_t *data, uint32_t available_bytes, int32_t *value, int32_t min, int32_t max)
    -> uint32_t;

} // namespace cubic::protocol::primitives::varint

#endif // CUBIC_PROTOCOL_PRIMITIVES_VARINT_
