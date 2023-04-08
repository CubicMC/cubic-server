#include "addPrimaryType.hpp"
#include "popPrimaryType.hpp"
#include <cstdint>
#include <gtest/gtest.h>
#include <rapidcheck/gtest.h>

namespace Serialization_Testing {
RC_GTEST_PROP(Serialization_Testing, ByteChecker, (uint8_t value))
{
    std::vector<uint8_t> out;
    addByte(out, value);
    auto at = out.data();
    auto parsed = popByte(at, at + out.size());
    RC_ASSERT(value == parsed);
}

RC_GTEST_PROP(Serialization_Testing, BooleanChecker, (bool value))
{
    std::vector<uint8_t> out;
    addBoolean(out, value);
    auto at = out.data();
    auto parsed = popBoolean(at, at + out.size());
    RC_ASSERT(value == parsed);
}

RC_GTEST_PROP(Serialization_Testing, ShortChecker, (int16_t value))
{
    std::vector<uint8_t> out;
    addShort(out, value);
    auto at = out.data();
    auto parsed = popShort(at, at + out.size());
    RC_ASSERT(value == parsed);
}

RC_GTEST_PROP(Serialization_Testing, UnsignedShortChecker, (uint16_t value))
{
    std::vector<uint8_t> out;
    addUShort(out, value);
    auto at = out.data();
    auto parsed = popUnsignedShort(at, at + out.size());
    RC_ASSERT(value == parsed);
}

RC_GTEST_PROP(Serialization_Testing, IntChecker, (int32_t value))
{
    std::vector<uint8_t> out;
    addInt(out, value);
    auto at = out.data();
    auto parsed = popInt(at, at + out.size());
    RC_ASSERT(value == parsed);
}

RC_GTEST_PROP(Serialization_Testing, VarIntChecker, (int32_t value))
{
    std::vector<uint8_t> out;
    addVarInt(out, value);
    auto at = out.data();
    auto parsed = popVarInt(at, at + out.size());
    RC_ASSERT(value == parsed);
}

RC_GTEST_PROP(Serialization_Testing, LongChecker, (int64_t value))
{
    std::vector<uint8_t> out;
    addLong(out, value);
    auto at = out.data();
    auto parsed = popLong(at, at + out.size());
    RC_ASSERT(value == parsed);
}

RC_GTEST_PROP(Serialization_Testing, UnsignedLongChecker, (uint64_t value))
{
    std::vector<uint8_t> out;
    addUnsignedLong(out, value);
    auto at = out.data();
    auto parsed = popUnsignedLong(at, at + out.size());
    RC_ASSERT(value == parsed);
}

RC_GTEST_PROP(Serialization_Testing, VarLongChecker, (int64_t value))
{
    std::vector<uint8_t> out;
    addVarLong(out, value);
    auto at = out.data();
    auto parsed = popVarLong(at, at + out.size());
    RC_ASSERT(value == parsed);
}

RC_GTEST_PROP(Serialization_Testing, FloatChecker, (float value))
{
    std::vector<uint8_t> out;
    addFloat(out, value);
    auto at = out.data();
    auto parsed = popFloat(at, at + out.size());
    RC_ASSERT(value == parsed);
}

RC_GTEST_PROP(Serialization_Testing, DoubleChecker, (double value))
{
    std::vector<uint8_t> out;
    addDouble(out, value);
    auto at = out.data();
    auto parsed = popDouble(at, at + out.size());
    RC_ASSERT(value == parsed);
}

RC_GTEST_PROP(Serialization_Testing, StringChecker, (std::string value))
{
    std::vector<uint8_t> out;
    if (value.size() > 32767) {
        RC_ASSERT_THROWS(addString(out, value));
    }
    addString(out, value) auto at = out.data();
    auto parsed = popString(at, at + out.size());
    RC_ASSERT(value == parsed);
}

RC_GTEST_PROP(Serialization_Testing, ChatChecker, (std::string value))
{
    std::vector<uint8_t> out;
    if (value.size() > 262144) {
        RC_ASSERT_THROWS(addChat(out, value));
    }
    addChat(out, value) auto at = out.data();
    auto parsed = popChat(at, at + out.size());
    RC_ASSERT(value == parsed);
}
}
