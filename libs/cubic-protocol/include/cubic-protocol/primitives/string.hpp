#ifndef CUBIC_PROTOCOL_PRIMITIVES_STRING_
#define CUBIC_PROTOCOL_PRIMITIVES_STRING_

#include <cstdint>
// TODO: Check if we want to use std::string for string parsing
#include <string>
#include <vector>

namespace cubic::protocol::primitives::string {

/**
 * Tries to serialize the given value to a byte buffer
 *
 * @param out Byte buffer where the data will be appended to
 * @param value Value to be serialized
 */
auto serialize(std::vector<uint8_t> &out, const std::string_view &value) -> void;

/**
 * Tries to parse a string
 *
 * If the parsing fails then the content of the given value is undefined
 *
 * @param data Raw incoming data from a client
 * @param available_bytes Number of bytes available in the incoming data
 * @param value Mapping that the function will try to fill
 * @return The number of bytes used to parse the primitive
 */
auto parse(const uint8_t *data, uint32_t available_bytes, std::string *value) -> uint32_t;

/**
 * Tries to parse a string with size bounds
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
auto parse(
    const uint8_t *data, uint32_t available_bytes, std::string *value, size_t min, size_t max
) -> uint32_t;

} // namespace cubic::protocol::primitives::string

#endif // CUBIC_PROTOCOL_PRIMITIVES_STRING_
