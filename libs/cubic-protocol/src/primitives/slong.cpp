#include "cubic-protocol/primitives/slong.hpp"

namespace cubic::protocol::primitives::slong {

auto parse(const uint8_t *data, uint32_t available_bytes, int64_t *value) -> uint32_t
{
    if (available_bytes < 8)
        return 0;

    *value = 0;
    for (int i = 0; i < 8; i++)
        *value = (*value << 8) + data[i];
    return 8;
}

auto parse(const uint8_t *data, uint32_t available_bytes, int64_t *value, int64_t min, int64_t max)
    -> uint32_t
{
    uint32_t parsed = parse(data, available_bytes, value);

    if (parsed == 0 || *value < min || *value > max)
        return 0;
    return parsed;
}

} // namespace cubic::protocol::primitives::slong

#ifdef UNIT_TESTS

#include <criterion/criterion.h>

TestSuite(primitives_slong, .timeout = 1);

Test(primitives_slong, parse_0)
{
    using namespace cubic::protocol::primitives::slong;
    uint8_t data[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
    int64_t value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 8);
    cr_assert_eq(value, 0);
}

Test(primitives_slong, parse_1)
{
    using namespace cubic::protocol::primitives::slong;
    uint8_t data[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01 };
    int64_t value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 8);
    cr_assert_eq(value, 1);
}

Test(primitives_slong, parse_255)
{
    using namespace cubic::protocol::primitives::slong;
    uint8_t data[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff };
    int64_t value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 8);
    cr_assert_eq(value, 255);
}

Test(primitives_slong, parse_256)
{
    using namespace cubic::protocol::primitives::slong;
    uint8_t data[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00 };
    int64_t value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 8);
    cr_assert_eq(value, 256);
}

Test(primitives_slong, parse_25565)
{
    using namespace cubic::protocol::primitives::slong;
    uint8_t data[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x63, 0xdd };
    int64_t value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 8);
    cr_assert_eq(value, 25565);
}

Test(primitives_slong, parse_65535)
{
    using namespace cubic::protocol::primitives::slong;
    uint8_t data[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff };
    int64_t value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 8);
    cr_assert_eq(value, 65535);
}

Test(primitives_slong, parse_fail_almost)
{
    using namespace cubic::protocol::primitives::slong;
    uint8_t data[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
    int64_t value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 0);
}

Test(primitives_slong, parse_fail_nothing)
{
    using namespace cubic::protocol::primitives::slong;
    uint8_t data[] = {};
    int64_t value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 0);
}

// TODO: Add more tests here cause it's just the unsigned short tests all over

#endif
