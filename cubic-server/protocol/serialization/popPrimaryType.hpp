/*
** All pop functions from the basic types specified in the protocol
** Some of them have a specific name in the protocol, but they are sent as a primitive type
** https://wiki.vg/index.php?title=Protocol&oldid=17753
*/

#ifndef CUBICSERVER_PROTOCOL_SERIALIZATION_POPPRIMARYTYPE_HPP
#define CUBICSERVER_PROTOCOL_SERIALIZATION_POPPRIMARYTYPE_HPP

#include <bitset>
#include <cstdint>
#include <cstring>
#include <string>
#include <vector>

#include "protocol/ParseExceptions.hpp"
#include "protocol/Structures.hpp"
#include "protocol/common.hpp"

namespace protocol {
constexpr uint8_t popByte(uint8_t *&at, uint8_t *eof)
{
    if (eof - at < 0)
        throw PacketEOF("Not enough data in packet to parse a byte");

    uint8_t value = *at;
    at++;
    return value;
}

constexpr bool popBoolean(uint8_t *&at, uint8_t *eof)
{
    auto value = popByte(at, eof);
    if (value != 0 && value != 1)
        throw OutOfRangeBoolean("Invalid boolean value");

    return value == 1;
}

constexpr uint16_t popShort(uint8_t *&at, uint8_t *eof)
{
    if (eof - at < 1)
        throw PacketEOF("Not enough data in packet to parse an short");

    uint16_t value = *(at + 1) | (*at << 8);
    at += 2;
    return value;
}

constexpr int32_t popInt(uint8_t *&at, uint8_t *eof)
{
    if (eof - at < 3)
        throw PacketEOF("Not enough data in packet to parse an int");

    int32_t value = 0;

    for (int i = 0; i < 4; i++)
        value = (value << 8) + *at++;
    return value;
}

// pop variable length integer (int32_t)
constexpr int32_t popVarInt(uint8_t *&at, uint8_t *eof)
{
    int32_t value = 0;
    int position = 0;
    uint8_t currentByte = 0;
    constexpr uint8_t CONTINUE_BIT = 0x80;
    constexpr uint8_t SEGMENT_BITS = 0x7f;

    while (true) {
        if (at > eof)
            throw PacketEOF("Not enough data in packet to parse a VarInt");
        currentByte = *at++;
        value |= (currentByte & SEGMENT_BITS) << position;

        if ((currentByte & CONTINUE_BIT) == 0)
            return value;

        position += 7;

        if (position >= 32)
            throw VarIntOverflow("VarInt exceeds max length");
    }
}

constexpr int64_t popLong(uint8_t *&at, uint8_t *eof)
{
    if (eof - at < 7)
        throw PacketEOF("Not enough data in packet to parse a Long");

    int64_t value = 0;

    for (int i = 0; i < 8; i++)
        value = (value << 8) + *at++;

    return value;
}

// pop variable length long (int64_t)
constexpr int64_t popVarLong(uint8_t *&at, uint8_t *eof)
{
    int64_t value = 0;
    int position = 0;
    uint8_t currentByte = 0;
    constexpr uint8_t CONTINUE_BIT = 0x80;
    constexpr uint8_t SEGMENT_BITS = 0x7f;

    while (true) {
        if (at > eof)
            throw PacketEOF("Not enough data in packet to parse a VarInt");
        currentByte = *at++;
        value |= ((uint64_t) (currentByte & SEGMENT_BITS)) << position;

        if ((currentByte & CONTINUE_BIT) == 0)
            return value;

        position += 7;

        if (position >= 64)
            throw VarIntOverflow("VarLong exceeds max length"); // TOOO(huntears): Change this to its proper exception
    }
}

constexpr uint32_t ntoh32(const uint32_t *input)
{
    uint32_t rval;
    uint8_t *data = (uint8_t *) &rval;

    data[0] = *input >> 24;
    data[1] = *input >> 16;
    data[2] = *input >> 8;
    data[3] = *input >> 0;

    return rval;
}

constexpr float popFloat(uint8_t *&at, uint8_t *eof)
{
    if (eof - at < 3)
        throw PacketEOF("Not enough data in packet to parse a Float");

    float result = 0;
    std::memcpy(&result, at, sizeof(float));
    at += sizeof(float);

    uint32_t *buf = (uint32_t *) &result;
    *buf = ntoh32(buf);

    return result;
}

constexpr uint64_t ntoh64(const uint64_t *input)
{
    uint64_t rval;
    uint8_t *data = (uint8_t *) &rval;

    data[0] = *input >> 56;
    data[1] = *input >> 48;
    data[2] = *input >> 40;
    data[3] = *input >> 32;
    data[4] = *input >> 24;
    data[5] = *input >> 16;
    data[6] = *input >> 8;
    data[7] = *input >> 0;

    return rval;
}

constexpr double popDouble(uint8_t *&at, uint8_t *eof)
{
    if (eof - at < 7)
        throw PacketEOF("Not enough data in packet to parse a Double");

    double result = 0;
    std::memcpy(&result, at, sizeof(double));
    at += sizeof(double);

    uint64_t *buf = (uint64_t *) &result;
    *buf = ntoh64(buf);

    return result;
}

constexpr std::string popString(uint8_t *&at, uint8_t *eof)
{
    int32_t size = popVarInt(at, eof);

    if (size > eof - at + 1)
        throw PacketEOF("Not enough data in packet to parse a String");
    std::string value(at, at + size);
    at += size;
    return value;
}

constexpr std::string popChat(uint8_t *&at, uint8_t *eof) { return popString(at, eof); }

// TODO: Fucking hell, this is a mess, why is this not an nbt ?
// constexpr EntityMetadata popEntityMetadata(uint8_t *&at, uint8_t *eof)
// {
// }

constexpr Slot popSlot(uint8_t *&at, uint8_t *eof)
{
    Slot slot;
    slot.present = popBoolean(at, eof);
    if (slot.present) {
        slot.itemID = popVarInt(at, eof);
        slot.itemCount = popByte(at, eof);
        // slot.nbt = popNbt(at, eof);
    }
    return slot;
}

// TODO: Nbt, nothing to see here. I could but why should I ?
// constexpr NBT popNBT(uint8_t *&at, uint8_t *eof)
// {
// }

constexpr u128 popUUID(uint8_t *&at, uint8_t *eof)
{
    if (eof - at < 15)
        throw PacketEOF("Not enough data in packet to parse a Long");

    u128 value;

    value.most = popLong(at, eof);
    value.least = popLong(at, eof);
    return value;
}

template<typename T, T (*pop)(uint8_t *&begin, uint8_t *end)>
constexpr std::vector<T> popArray(uint8_t *&at, uint8_t *eof)
{
    std::vector<T> array;
    auto length = popVarInt(at, eof);
    for (int i = 0; i < length; i++)
        array.push_back(pop(at, eof));
    return array;
}

constexpr Position popPosition(uint8_t *&at, uint8_t *eof)
{
    Position p;
    auto h = popLong(at, eof);

    p.x = h >> 38;
    p.z = h << 26 >> 38;
    p.y = h << 52 >> 52;
    return p;
}

/**
 * @brief Pop a bitset from the packet
 *
 * @tparam size The size of the bitset to pop
 * @param at The current position in the packet
 * @param eof The end of the packet
 * @return A bitset of size size
 */
template<uint64_t size>
constexpr std::bitset<size> popBitSet(uint8_t *&at, uint8_t *eof)
{
    std::bitset<size> result;

    for (uint32_t bit = 0; bit < size; bit += 8) {
        uint8_t byte = popByte(at, eof);
        for (uint8_t i = 0; i < 8 && bit + i < size; i++)
            result[bit + i] = byte & (1 >> i);
    }

    return result;
}
} // namespace protocol

#endif // CUBICSERVER_PROTOCOL_SERIALIZATION_POPPRIMARYTYPE_HPP
