#include "cubic-protocol/primitives/ushort.hpp"

namespace cubic::protocol::primitives::ushort {

auto parse(const uint8_t *data, uint32_t available_bytes, uint16_t *value) -> uint32_t
{
    if (available_bytes < 2)
        return 0;
    *value = data[1] | (data[0] << 8);
    return 2;
}

auto parse(
    const uint8_t *data, uint32_t available_bytes, uint16_t *value, uint16_t min, uint16_t max
) -> uint32_t
{
    uint32_t parsed = parse(data, available_bytes, value);

    if (parsed == 0 || *value < min || *value > max)
        return 0;
    return parsed;
}

} // namespace cubic::protocol::primitives::ushort

#ifdef UNIT_TESTS

#include <criterion/criterion.h>

TestSuite(primitives_ushort, .timeout = 1);

Test(primitives_ushort, parse_0)
{
    using namespace cubic::protocol::primitives::ushort;
    uint8_t data[] = { 0x00, 0x00 };
    uint16_t value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 2);
    cr_assert_eq(value, 0);
}

Test(primitives_ushort, parse_1)
{
    using namespace cubic::protocol::primitives::ushort;
    uint8_t data[] = { 0x00, 0x01 };
    uint16_t value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 2);
    cr_assert_eq(value, 1);
}

Test(primitives_ushort, parse_255)
{
    using namespace cubic::protocol::primitives::ushort;
    uint8_t data[] = { 0x00, 0xff };
    uint16_t value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 2);
    cr_assert_eq(value, 255);
}

Test(primitives_ushort, parse_256)
{
    using namespace cubic::protocol::primitives::ushort;
    uint8_t data[] = { 0x01, 0x00 };
    uint16_t value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 2);
    cr_assert_eq(value, 256);
}

Test(primitives_ushort, parse_25565)
{
    using namespace cubic::protocol::primitives::ushort;
    uint8_t data[] = { 0x63, 0xdd };
    uint16_t value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 2);
    cr_assert_eq(value, 25565);
}

Test(primitives_ushort, parse_65535)
{
    using namespace cubic::protocol::primitives::ushort;
    uint8_t data[] = { 0xff, 0xff };
    uint16_t value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 2);
    cr_assert_eq(value, 65535);
}

Test(primitives_ushort, parse_fail_almost)
{
    using namespace cubic::protocol::primitives::ushort;
    uint8_t data[] = { 0x00 };
    uint16_t value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 0);
}

Test(primitives_ushort, parse_fail_nothing)
{
    using namespace cubic::protocol::primitives::ushort;
    uint8_t data[] = {};
    uint16_t value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 0);
}

#endif
