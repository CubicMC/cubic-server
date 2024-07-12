#include <cstring>
#include <limits>

#include "cubic-protocol/primitives/string.hpp"
#include "cubic-protocol/primitives/varint.hpp"

namespace cubic::protocol::primitives::string {

auto serialize(std::vector<uint8_t> &out, const std::string_view &value) -> void
{
    const uint32_t varint_size = varint::get_num_bytes((int32_t) value.size());
    const auto total_size = (uint32_t) (varint_size + value.size());
    const auto previous_size = out.size();
    out.resize(out.size() + total_size);
    varint::serialize(out.data() + previous_size, (int32_t) value.size());
    std::memcpy(out.data() + previous_size + varint_size, value.data(), value.size());
}

auto parse(const uint8_t *data, uint32_t available_bytes, std::string *value) -> uint32_t
{
    int32_t size;
    uint32_t parsed = varint::parse(
        data, available_bytes, &size, 0, std::numeric_limits<int32_t>::max()
    );

    if (parsed == 0)
        return 0;
    if (available_bytes - parsed < (uint32_t) size)
        return 0;
    value->insert(value->begin(), data + parsed, data + parsed + size);
    return parsed + (uint32_t) size;
}

auto parse(
    const uint8_t *data, uint32_t available_bytes, std::string *value, size_t min, size_t max
) -> uint32_t
{
    uint32_t parsed = parse(data, available_bytes, value);

    if (parsed == 0 || value->size() < min || value->size() > max)
        return 0;
    return parsed;
}

} // namespace cubic::protocol::primitives::string

#ifdef UNIT_TESTS
// GCOV_EXCL_START

#include <criterion/criterion.h>

TestSuite(primitives_string, .timeout = 1);

Test(primitives_string, parse_0)
{
    using namespace cubic::protocol::primitives::string;
    uint8_t data[] = { 0x00 };
    std::string value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 1);
    cr_assert_eq(value, "");
}

Test(primitives_string, ser_0)
{
    using namespace cubic::protocol::primitives::string;
    uint8_t expected[] = { 0x00 };
    size_t expected_size = sizeof expected / sizeof expected[0];
    std::string value;
    std::vector<uint8_t> out;
    serialize(out, value);
    cr_assert_eq(out.size(), expected_size);
    cr_assert_arr_eq(expected, out.data(), expected_size);
}

Test(primitives_string, parse_1)
{
    using namespace cubic::protocol::primitives::string;
    uint8_t data[] = { 0x01, 0x68 };
    std::string value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 2);
    cr_assert_eq(value, "h");
}

Test(primitives_string, ser_1)
{
    using namespace cubic::protocol::primitives::string;
    uint8_t expected[] = { 0x01, 0x68 };
    size_t expected_size = sizeof expected / sizeof expected[0];
    std::string value = "h";
    std::vector<uint8_t> out;
    serialize(out, value);
    cr_assert_eq(out.size(), expected_size);
    cr_assert_arr_eq(expected, out.data(), expected_size);
}

Test(primitives_string, parse_hello_world)
{
    using namespace cubic::protocol::primitives::string;
    uint8_t data[] = { 0x0d, 0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x2c,
                       0x20, 0x57, 0x6f, 0x72, 0x6c, 0x64, 0x21 };
    std::string value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 14);
    cr_assert_eq(value, "Hello, World!");
}

Test(primitives_string, ser_hello_world)
{
    using namespace cubic::protocol::primitives::string;
    uint8_t expected[] = { 0x0d, 0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x2c,
                           0x20, 0x57, 0x6f, 0x72, 0x6c, 0x64, 0x21 };
    size_t expected_size = sizeof expected / sizeof expected[0];
    std::string value = "Hello, World!";
    std::vector<uint8_t> out;
    serialize(out, value);
    cr_assert_eq(out.size(), expected_size);
    cr_assert_arr_eq(expected, out.data(), expected_size);
}

Test(primitives_string, ser_many_hello_world)
{
    using namespace cubic::protocol::primitives::string;
    uint8_t expected[] = {
        0x84, 0x02, 0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x2c, 0x20, 0x57, 0x6f, 0x72, 0x6c, 0x64, 0x21,
        0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x2c, 0x20, 0x57, 0x6f, 0x72, 0x6c, 0x64, 0x21, 0x48, 0x65,
        0x6c, 0x6c, 0x6f, 0x2c, 0x20, 0x57, 0x6f, 0x72, 0x6c, 0x64, 0x21, 0x48, 0x65, 0x6c, 0x6c,
        0x6f, 0x2c, 0x20, 0x57, 0x6f, 0x72, 0x6c, 0x64, 0x21, 0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x2c,
        0x20, 0x57, 0x6f, 0x72, 0x6c, 0x64, 0x21, 0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x2c, 0x20, 0x57,
        0x6f, 0x72, 0x6c, 0x64, 0x21, 0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x2c, 0x20, 0x57, 0x6f, 0x72,
        0x6c, 0x64, 0x21, 0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x2c, 0x20, 0x57, 0x6f, 0x72, 0x6c, 0x64,
        0x21, 0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x2c, 0x20, 0x57, 0x6f, 0x72, 0x6c, 0x64, 0x21, 0x48,
        0x65, 0x6c, 0x6c, 0x6f, 0x2c, 0x20, 0x57, 0x6f, 0x72, 0x6c, 0x64, 0x21, 0x48, 0x65, 0x6c,
        0x6c, 0x6f, 0x2c, 0x20, 0x57, 0x6f, 0x72, 0x6c, 0x64, 0x21, 0x48, 0x65, 0x6c, 0x6c, 0x6f,
        0x2c, 0x20, 0x57, 0x6f, 0x72, 0x6c, 0x64, 0x21, 0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x2c, 0x20,
        0x57, 0x6f, 0x72, 0x6c, 0x64, 0x21, 0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x2c, 0x20, 0x57, 0x6f,
        0x72, 0x6c, 0x64, 0x21, 0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x2c, 0x20, 0x57, 0x6f, 0x72, 0x6c,
        0x64, 0x21, 0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x2c, 0x20, 0x57, 0x6f, 0x72, 0x6c, 0x64, 0x21,
        0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x2c, 0x20, 0x57, 0x6f, 0x72, 0x6c, 0x64, 0x21, 0x48, 0x65,
        0x6c, 0x6c, 0x6f, 0x2c, 0x20, 0x57, 0x6f, 0x72, 0x6c, 0x64, 0x21, 0x48, 0x65, 0x6c, 0x6c,
        0x6f, 0x2c, 0x20, 0x57, 0x6f, 0x72, 0x6c, 0x64, 0x21, 0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x2c,
        0x20, 0x57, 0x6f, 0x72, 0x6c, 0x64, 0x21,
    };
    size_t expected_size = sizeof expected / sizeof expected[0];
    std::string value = "Hello, World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, "
                        "World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, "
                        "World!Hello, World!Hello, World!Hello, World!Hello, World!Hello, "
                        "World!Hello, World!Hello, World!Hello, World!Hello, World!";
    std::vector<uint8_t> out;
    serialize(out, value);
    cr_assert_eq(out.size(), expected_size);
    cr_assert_arr_eq(expected, out.data(), expected_size);
}

Test(primitives_string, parse_0_extra)
{
    using namespace cubic::protocol::primitives::string;
    uint8_t data[] = { 0x00, 0x68 };
    std::string value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 1);
    cr_assert_eq(value, "");
}

Test(primitives_string, parse_fail_1_almost)
{
    using namespace cubic::protocol::primitives::string;
    uint8_t data[] = { 0x01 };
    std::string value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 0);
}

Test(primitives_string, parse_fail_negative)
{
    using namespace cubic::protocol::primitives::string;
    uint8_t data[] = { 0xff, 0xff, 0xff, 0xff, 0x0f };
    std::string value;
    uint32_t bytes_parsed = parse(data, sizeof data, &value);
    cr_assert_eq(bytes_parsed, 0);
}

// GCOV_EXCL_STOP
#endif
