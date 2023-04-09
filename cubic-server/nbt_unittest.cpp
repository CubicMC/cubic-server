#include "nbt.hpp"
#include <gtest/gtest.h>

namespace Nbt_Testing {
/**
 * @brief Launch a new test environment
 *
 * @param TestSuiteName The name of the test suite (in that case MathTest) this allow to group different tests
 * @param TestName The name of the test (in this case Factorial) this allow to group test
 *
 * @note I choose to use EXPECT instead of ASSERT because I want to test all the cases and not to stop at the first error
 *
 */
TEST(NbtTest, TestNbt)
{
    auto to_serialize = nbt::Compound("hello world", {new nbt::String("name", "Bananrama")});
    auto serialized = to_serialize.serialize();

    std::vector<uint8_t> to_get({0x0a, 0x00, 0x0b, 0x68, 0x65, 0x6c, 0x6c, 0x6f, 0x20, 0x77, 0x6f, 0x72, 0x6c, 0x64, 0x08, 0x00, 0x04,
                                 0x6e, 0x61, 0x6d, 0x65, 0x00, 0x09, 0x42, 0x61, 0x6e, 0x61, 0x6e, 0x72, 0x61, 0x6d, 0x61, 0x00});
    EXPECT_EQ(serialized.size(), to_get.size());
    EXPECT_EQ(serialized, to_get);
}
}