#include "addPrimaryType.hpp"
#include "popPrimaryType.hpp"
#include <cstdint>
#include <gtest/gtest.h>
#include <rapidcheck/gtest.h>

namespace Serialization_Testing {
RC_GTEST_PROP(Serialization_Testing, ByteChecker, (uint8_t value))
{
    std::vector<uint8_t> out;
    protocol::addByte(out, value);
    auto at = out.data();
    auto parsed = protocol::popByte(at, at + out.size());
    RC_ASSERT(value == parsed);
}

RC_GTEST_PROP(Serialization_Testing, BooleanChecker, (bool value))
{
    std::vector<uint8_t> out;
    protocol::addBoolean(out, value);
    auto at = out.data();
    auto parsed = protocol::popBoolean(at, at + out.size());
    RC_ASSERT(value == parsed);
}

// RC_GTEST_PROP(Serialization_Testing, ShortChecker, (int16_t value))
// {
//     std::vector<uint8_t> out;
//     protocol::addShort(out, value);
//     auto at = out.data();
//     auto parsed = protocol::popShort(at, at + out.size());
//     RC_ASSERT(value == parsed);
// }

RC_GTEST_PROP(Serialization_Testing, UnsignedShortChecker, (uint16_t value))
{
    std::vector<uint8_t> out;
    protocol::addUShort(out, value);
    auto at = out.data();
    auto parsed = protocol::popShort(at, at + out.size());
    RC_ASSERT(value == parsed);
}

RC_GTEST_PROP(Serialization_Testing, IntChecker, (int32_t value))
{
    std::vector<uint8_t> out;
    protocol::addInt(out, value);
    auto at = out.data();
    auto parsed = protocol::popInt(at, at + out.size());
    RC_ASSERT(value == parsed);
}

RC_GTEST_PROP(Serialization_Testing, VarIntChecker, (int32_t value))
{
    std::vector<uint8_t> out;
    protocol::addVarInt(out, value);
    auto at = out.data();
    auto parsed = protocol::popVarInt(at, at + out.size());
    RC_ASSERT(value == parsed);
}

RC_GTEST_PROP(Serialization_Testing, LongChecker, (int64_t value))
{
    std::vector<uint8_t> out;
    protocol::addLong(out, value);
    auto at = out.data();
    auto parsed = protocol::popLong(at, at + out.size());
    RC_ASSERT(value == parsed);
}

// RC_GTEST_PROP(Serialization_Testing, UnsignedLongChecker, (uint64_t value))
// {
//     std::vector<uint8_t> out;
//     protocol::addUnsignedLong(out, value);
//     auto at = out.data();
//     auto parsed = protocol::popUnsignedLong(at, at + out.size());
//     RC_ASSERT(value == parsed);
// }

RC_GTEST_PROP(Serialization_Testing, VarLongChecker, (int64_t value))
{
    std::vector<uint8_t> out;
    protocol::addVarLong(out, value);
    auto at = out.data();
    auto parsed = protocol::popVarLong(at, at + out.size());
    RC_ASSERT(value == parsed);
}

RC_GTEST_PROP(Serialization_Testing, FloatChecker, (float value))
{
    std::vector<uint8_t> out;
    protocol::addFloat(out, value);
    auto at = out.data();
    auto parsed = protocol::popFloat(at, at + out.size());
    RC_ASSERT(value == parsed);
}

RC_GTEST_PROP(Serialization_Testing, DoubleChecker, (double value))
{
    std::vector<uint8_t> out;
    protocol::addDouble(out, value);
    auto at = out.data();
    auto parsed = protocol::popDouble(at, at + out.size());
    RC_ASSERT(value == parsed);
}

RC_GTEST_PROP(Serialization_Testing, StringChecker, (std::string value))
{
    std::vector<uint8_t> out;
    if (value.size() > 32767) {
        RC_ASSERT_THROWS(protocol::addString(out, value));
    }
    protocol::addString(out, value);
    auto at = out.data();
    auto parsed = protocol::popString(at, at + out.size());
    RC_ASSERT(value == parsed);
}

RC_GTEST_PROP(Serialization_Testing, ChatChecker, (std::string value))
{
    std::vector<uint8_t> out;
    if (value.size() > 262144) {
        RC_ASSERT_THROWS(protocol::addChat(out, value));
    }
    protocol::addChat(out, value);
    auto at = out.data();
    auto parsed = protocol::popChat(at, at + out.size());
    RC_ASSERT(value == parsed);
}

TEST(Serialization_Testing, SlotChecker)
{
    protocol::Slot slot {true, 1, 32};
    std::vector<uint8_t> out;
    protocol::addSlot(out, slot);
    auto at = out.data();
    auto parsed = protocol::popSlot(at, at + out.size());
    ASSERT_EQ(slot.present, parsed.present);
    ASSERT_EQ(slot.itemCount, parsed.itemCount);
    ASSERT_EQ(slot.itemID, parsed.itemID);
}

RC_GTEST_PROP(Serialization_Testing, UUIDChecker, (uint64_t most, uint64_t least))
{
    u128 uuid {most, least};
    std::vector<uint8_t> out;
    protocol::addUUID(out, uuid);
    auto at = out.data();
    auto parsed = protocol::popUUID(at, at + out.size());
    ASSERT_EQ(uuid.most, parsed.most);
    ASSERT_EQ(uuid.least, parsed.least);
}
}
