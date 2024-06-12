#include <cassert>

#include "cubic-protocol/primitives/varint.hpp"

namespace cubic::protocol::primitives::varint {

// TODO: Add more stuff in there to support other platforms/compilers
#if defined __has_builtin
#if __has_builtin(__builtin_clz)
#define GET_LEADING_ZEROS(i) __builtin_clz(i)
#endif
#endif

auto get_num_bytes(int32_t value) -> uint8_t
{
    if (value == 0)
        return 1; // Special case to go around undefined gcc builtin behaviour
    if (value < 0)
        return 5; // Max varint size on negative numbers
    int num_leading_zeros = GET_LEADING_ZEROS((uint32_t) value);
    assert(num_leading_zeros != 0); // Can't happen except maybe on big endian machines (Not sure)
    int num_set_bits = 32 - num_leading_zeros;
    return (uint8_t) ((num_set_bits - 1) / 7 + 1);
}

auto parse(const uint8_t *data, uint32_t available_bytes, int32_t *value) -> uint32_t
{
    int position = 0;
    uint8_t current_byte = 0;
    constexpr uint8_t continue_bit = 0x80;
    constexpr uint8_t segment_bits = 0x7f;
    uint32_t byte_position = 0;
    *value = 0;

    while (true) {
        if (byte_position >= available_bytes)
            return 0;
        current_byte = data[byte_position++];
        *value |= (current_byte & segment_bits) << position;

        if ((current_byte & continue_bit) == 0)
            return byte_position;

        position += 7;

        if (position >= 32)
            return 0;
    }
}

auto parse(uint8_t **data, uint32_t *available_bytes) -> std::optional<int32_t>
{
    int32_t result;
    uint32_t parsed = parse(*data, *available_bytes, &result);

    if (parsed == 0)
        return std::nullopt;
    *data += parsed;
    *available_bytes -= parsed;
    return result;
}

auto parse(const uint8_t *data, uint32_t available_bytes, int32_t *value, int32_t min, int32_t max)
    -> uint32_t
{
    uint32_t parsed = parse(data, available_bytes, value);

    if (parsed == 0 || *value < min || *value > max)
        return 0;
    return parsed;
}

auto parse(uint8_t **data, uint32_t *available_bytes, int32_t min, int32_t max)
    -> std::optional<int32_t>
{
    int32_t result;
    uint32_t parsed = parse(*data, *available_bytes, &result);

    if (parsed == 0 || result < min || result > max)
        return std::nullopt;
    *data += parsed;
    *available_bytes -= parsed;
    return result;
}

} // namespace cubic::protocol::primitives::varint

#ifdef UNIT_TESTS

#include <criterion/criterion.h>

TestSuite(primitives_varint, .timeout = 1);

TestSuite(primitives_varint_size, .timeout = 1);

Test(primitives_varint, parse_0)
{
    using namespace cubic::protocol::primitives::varint;
    uint8_t data[] = { 0x00 };
    int32_t value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 1);
    cr_assert_eq(value, 0);
}

Test(primitives_varint_size, size_0)
{
    using namespace cubic::protocol::primitives::varint;
    int32_t value = 0;
    uint8_t counted = get_num_bytes(value);
    cr_assert_eq(counted, 1);
}

Test(primitives_varint, parse_1)
{
    using namespace cubic::protocol::primitives::varint;
    uint8_t data[] = { 0x01 };
    int32_t value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 1);
    cr_assert_eq(value, 1);
}

Test(primitives_varint_size, size_1)
{
    using namespace cubic::protocol::primitives::varint;
    int32_t value = 1;
    uint8_t counted = get_num_bytes(value);
    cr_assert_eq(counted, 1);
}

Test(primitives_varint, parse_127)
{
    using namespace cubic::protocol::primitives::varint;
    uint8_t data[] = { 0x7f };
    int32_t value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 1);
    cr_assert_eq(value, 127);
}

Test(primitives_varint_size, size_127)
{
    using namespace cubic::protocol::primitives::varint;
    int32_t value = 127;
    uint8_t counted = get_num_bytes(value);
    cr_assert_eq(counted, 1);
}

Test(primitives_varint_size, size_126)
{
    using namespace cubic::protocol::primitives::varint;
    int32_t value = 126;
    uint8_t counted = get_num_bytes(value);
    cr_assert_eq(counted, 1);
}

Test(primitives_varint, parse_128)
{
    using namespace cubic::protocol::primitives::varint;
    uint8_t data[] = { 0x80, 0x01 };
    int32_t value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 2);
    cr_assert_eq(value, 128);
}

Test(primitives_varint_size, size_128)
{
    using namespace cubic::protocol::primitives::varint;
    int32_t value = 128;
    uint8_t counted = get_num_bytes(value);
    cr_assert_eq(counted, 2);
}

Test(primitives_varint, parse_255)
{
    using namespace cubic::protocol::primitives::varint;
    uint8_t data[] = { 0xff, 0x01 };
    int32_t value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 2);
    cr_assert_eq(value, 255);
}

Test(primitives_varint_size, size_255)
{
    using namespace cubic::protocol::primitives::varint;
    int32_t value = 255;
    uint8_t counted = get_num_bytes(value);
    cr_assert_eq(counted, 2);
}

Test(primitives_varint, parse_25565)
{
    using namespace cubic::protocol::primitives::varint;
    uint8_t data[] = { 0xdd, 0xc7, 0x01 };
    int32_t value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 3);
    cr_assert_eq(value, 25565);
}

Test(primitives_varint_size, size_25565)
{
    using namespace cubic::protocol::primitives::varint;
    int32_t value = 25565;
    uint8_t counted = get_num_bytes(value);
    cr_assert_eq(counted, 3);
}

Test(primitives_varint, parse_2097151)
{
    using namespace cubic::protocol::primitives::varint;
    uint8_t data[] = { 0xff, 0xff, 0x7f };
    int32_t value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 3);
    cr_assert_eq(value, 2097151);
}

Test(primitives_varint_size, size_2097151)
{
    using namespace cubic::protocol::primitives::varint;
    int32_t value = 2097151;
    uint8_t counted = get_num_bytes(value);
    cr_assert_eq(counted, 3);
}

Test(primitives_varint, parse_2147483647)
{
    using namespace cubic::protocol::primitives::varint;
    uint8_t data[] = { 0xff, 0xff, 0xff, 0xff, 0x07 };
    int32_t value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 5);
    cr_assert_eq(value, 2147483647);
}

Test(primitives_varint_size, size_2147483647)
{
    using namespace cubic::protocol::primitives::varint;
    int32_t value = 2147483647;
    uint8_t counted = get_num_bytes(value);
    cr_assert_eq(counted, 5);
}

Test(primitives_varint, parse_m1)
{
    using namespace cubic::protocol::primitives::varint;
    uint8_t data[] = { 0xff, 0xff, 0xff, 0xff, 0x0f };
    int32_t value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 5);
    cr_assert_eq(value, -1);
}

Test(primitives_varint_size, size_m1)
{
    using namespace cubic::protocol::primitives::varint;
    int32_t value = -1;
    uint8_t counted = get_num_bytes(value);
    cr_assert_eq(counted, 5);
}

Test(primitives_varint, parse_m2147483648)
{
    using namespace cubic::protocol::primitives::varint;
    uint8_t data[] = { 0x80, 0x80, 0x80, 0x80, 0x08 };
    int32_t value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 5);
    cr_assert_eq(value, -2147483648);
}

Test(primitives_varint_size, size_m2147483648)
{
    using namespace cubic::protocol::primitives::varint;
    int32_t value = -2147483648;
    uint8_t counted = get_num_bytes(value);
    cr_assert_eq(counted, 5);
}

#endif
