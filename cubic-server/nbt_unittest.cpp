#include "nbt.hpp"
#include <fstream>
#include <gtest/gtest.h>
#include <rapidcheck/gtest.h>

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

RC_GTEST_PROP(RapidCheckTest, NbtByteChecker, (int8_t value))
{
    auto toSerialize = nbt::Byte("test", value);
    auto serialized = toSerialize.serialize();
    auto at = serialized.data();
    auto parsed = nbt::parseByte(at, at + serialized.size() - 1);
    RC_ASSERT(value == parsed->getValue());
}

RC_GTEST_PROP(RapidCheckTest, NbtShortChecker, (int16_t value))
{
    auto toSerialize = nbt::Short("test", value);
    auto serialized = toSerialize.serialize();
    auto at = serialized.data();
    auto parsed = nbt::parseShort(at, at + serialized.size() - 1);
    RC_ASSERT(value == parsed->getValue());
}

RC_GTEST_PROP(RapidCheckTest, NbtIntChecker, (int32_t value))
{
    auto toSerialize = nbt::Int("test", value);
    auto serialized = toSerialize.serialize();
    auto at = serialized.data();
    auto parsed = nbt::parseInt(at, at + serialized.size() - 1);
    RC_ASSERT(value == parsed->getValue());
}

RC_GTEST_PROP(RapidCheckTest, NbtLongChecker, (int64_t value))
{
    auto toSerialize = nbt::Long("test", value);
    auto serialized = toSerialize.serialize();
    auto at = serialized.data();
    auto parsed = nbt::parseLong(at, at + serialized.size() - 1);
    RC_ASSERT(value == parsed->getValue());
}

RC_GTEST_PROP(RapidCheckTest, NbtFloatChecker, (float value))
{
    auto toSerialize = nbt::Float("test", value);
    auto serialized = toSerialize.serialize();
    auto at = serialized.data();
    auto parsed = nbt::parseFloat(at, at + serialized.size() - 1);
    RC_ASSERT(value == parsed->getValue());
}

RC_GTEST_PROP(RapidCheckTest, NbtDoubleChecker, (double value))
{
    auto toSerialize = nbt::Double("test", value);
    auto serialized = toSerialize.serialize();
    auto at = serialized.data();
    auto parsed = nbt::parseDouble(at, at + serialized.size() - 1);
    RC_ASSERT(value == parsed->getValue());
}

RC_GTEST_PROP(RapidCheckTest, NbtByteArrayChecker, (const std::vector<int8_t> value))
{
    auto toSerialize = nbt::ByteArray("test", value);
    auto serialized = toSerialize.serialize();
    auto at = serialized.data();
    auto parsed = nbt::parseByteArray(at, at + serialized.size() - 1);
    RC_ASSERT(value == parsed->getValues());
}

RC_GTEST_PROP(RapidCheckTest, NbtStringChecker, (const std::string value))
{
    auto toSerialize = nbt::String("test", value);
    auto serialized = toSerialize.serialize();
    auto at = serialized.data();
    auto parsed = nbt::parseString(at, at + serialized.size() - 1);
    RC_ASSERT(value == parsed->getValue());
}

RC_GTEST_PROP(RapidCheckTest, NbtIntArrayChecker, (const std::vector<int> value))
{
    auto toSerialize = nbt::IntArray("test", value);
    auto serialized = toSerialize.serialize();
    auto at = serialized.data();
    auto parsed = nbt::parseIntArray(at, at + serialized.size() - 1);
    RC_ASSERT(value == parsed->getValues());
}

RC_GTEST_PROP(RapidCheckTest, NbtLongArrayChecker, (const std::vector<int64_t> value))
{
    auto toSerialize = nbt::LongArray("test", value);
    auto serialized = toSerialize.serialize();
    auto at = serialized.data();
    auto parsed = nbt::parseLongArray(at, at + serialized.size() - 1);
    RC_ASSERT(value == parsed->getValues());
}

TEST(NbtTest, TestNbt)
{
    auto toserialize = nbt::Compound("hello world", {std::shared_ptr<nbt::String>(new nbt::String("name", "Bananrama"))});
    auto serialized = toserialize.serialize();

    std::vector<uint8_t> toGet({0x0a, 0x00, 0x0b, 0x68, 0x65, 0x6c, 0x6c, 0x6f, 0x20, 0x77, 0x6f, 0x72, 0x6c, 0x64, 0x08, 0x00, 0x04,
                                0x6e, 0x61, 0x6d, 0x65, 0x00, 0x09, 0x42, 0x61, 0x6e, 0x61, 0x6e, 0x72, 0x61, 0x6d, 0x61, 0x00});
    EXPECT_EQ(serialized.size(), toGet.size());
    EXPECT_EQ(serialized, toGet);
}

TEST(NbtTest, hello_world)
{
    std::ifstream file("hello_world.nbt", std::ios::binary);
    ASSERT_TRUE(testing::AssertionResult(file.is_open() ? testing::AssertionSuccess() : testing::AssertionFailure()) << "Failed to open file");
    std::vector<uint8_t> buffer(std::istreambuf_iterator<char>(file), {});
    auto at = buffer.data();
    auto content = nbt::parse(at, at + buffer.size() - 1);
    ASSERT_TRUE(testing::AssertionResult(content == nullptr ? testing::AssertionFailure() : testing::AssertionSuccess()) << "Failed to parse file");
    auto result = content->serialize();
    EXPECT_EQ(result.size(), buffer.size());
    EXPECT_EQ(result, buffer);
}

TEST(NbtTest, bigtest)
{
    std::ifstream file("bigtest.nbt", std::ios::binary);
    ASSERT_TRUE(testing::AssertionResult(file.is_open() ? testing::AssertionSuccess() : testing::AssertionFailure()) << "Failed to open file");
    std::vector<uint8_t> buffer(std::istreambuf_iterator<char>(file), {});
    auto at = buffer.data();
    auto content = nbt::parse(at, at + buffer.size() - 1);
    ASSERT_TRUE(testing::AssertionResult(content == nullptr ? testing::AssertionFailure() : testing::AssertionSuccess()) << "Failed to parse file");
    auto result = content->serialize();
    EXPECT_EQ(result.size(), buffer.size());
    EXPECT_EQ(result, buffer);
}
}
