/*
** All add functions from the basic types specified in the protocol
** Some of them have a specific name in the protocol, but they are sent as a primitive type
** https://wiki.vg/index.php?title=Protocol&oldid=17753
*/

#ifndef CUBICSERVER_PROTOCOL_SERIALIZATION_ADDPRIMARYTYPE_HPP
#define CUBICSERVER_PROTOCOL_SERIALIZATION_ADDPRIMARYTYPE_HPP

#include <cstdint>
#include <string>
#include <vector>

#include "concept.hpp"
#include "nbt.h"
#include "protocol/ParseExceptions.hpp"
#include "protocol/Structures.hpp"
#include "types.hpp"
#include "world_storage/DynamicStorage.hpp"

namespace protocol {
constexpr void addByte(std::vector<uint8_t> &out, const uint8_t &data) { out.push_back(data); }

constexpr void addBoolean(std::vector<uint8_t> &out, const bool &data)
{
    if (data)
        addByte(out, 1);
    else
        addByte(out, 0);
}

constexpr void addShort(std::vector<uint8_t> &out, const int16_t &data)
{
    out.push_back(data >> 8);
    out.push_back(data & 0xFF);
}

constexpr void addUShort(std::vector<uint8_t> &out, const uint16_t &data)
{
    out.push_back(data >> 8);
    out.push_back(data & 0xFF);
}

constexpr void addInt(std::vector<uint8_t> &out, const int32_t &data)
{
    for (int i = 0; i < 4; i++)
        out.push_back((data >> (24 - i * 8)) & 0xFF);
}

// Variable length integer
constexpr void addVarInt(std::vector<uint8_t> &out, const int32_t &data)
{
    constexpr uint8_t CONTINUE_BIT = 0x80;
    constexpr uint8_t SEGMENT_BITS = 0x7f;
    int32_t value = data;

    while (true) {
        if ((value & ~SEGMENT_BITS) == 0) {
            out.push_back(value);
            return;
        }
        out.push_back((value & SEGMENT_BITS) | CONTINUE_BIT);
        // value >>= 7;
        value = *((uint32_t *) &value) >> 7;
    }
}

// Add long (int64_t)
constexpr void addLong(std::vector<uint8_t> &out, const int64_t &data)
{
    for (int i = 0; i < 8; i++)
        out.push_back((data >> (56 - i * 8)) & 0xFF);
}

constexpr void addUnsignedLong(std::vector<uint8_t> &out, const uint64_t &data)
{
    for (int i = 0; i < 8; i++)
        out.push_back((data >> (56 - i * 8)) & 0xFF);
}

// Variable length integer
constexpr void addVarLong(std::vector<uint8_t> &out, const int64_t &data)
{
    constexpr uint8_t CONTINUE_BIT = 0x80;
    constexpr uint8_t SEGMENT_BITS = 0x7f;
    int64_t value = data;

    while (true) {
        if ((value & ~SEGMENT_BITS) == 0) {
            out.push_back(value);
            return;
        }
        out.push_back((value & SEGMENT_BITS) | CONTINUE_BIT);
        // value >>= 7;
        value = *((uint64_t *) &value) >> 7;
    }
}

constexpr void addFloat(std::vector<uint8_t> &out, const float &data)
{
    union {
        float f;
        uint8_t u[4];
    } d;
    d.f = data;
    for (int i = 3; i >= 0; i--)
        out.push_back(d.u[i]);
}

constexpr void addDouble(std::vector<uint8_t> &out, const double &data)
{
    union {
        double f;
        uint8_t u[8];
    } d;
    d.f = data;
    for (int i = 7; i >= 0; i--)
        out.push_back(d.u[i]);
}

// Add string with a varint length
static constexpr void _addString(std::vector<uint8_t> &out, const std::string &data, std::size_t maxSize)
{
    if (data.size() > maxSize)
        throw MaxLengthString("String is too long");

    addVarInt(out, data.size());

    for (char c : data)
        out.push_back(c);
}

// Default addString with a max size of 32767
constexpr size_t MAX_STRING_SIZE = 32767;
constexpr size_t MAX_CHAT_SIZE = 262144;

constexpr void addString(std::vector<uint8_t> &out, const std::string &data) { _addString(out, data, MAX_STRING_SIZE); }

// Should use chat::Message, but can't because the JSON lib is not constexpr
constexpr void addChat(std::vector<uint8_t> &out, const std::string &data) { _addString(out, data, MAX_CHAT_SIZE); }

// TODO: gl :>
// constexpr void addEntityMetadata(std::vector<uint8_t>, const EntityMetadata &data)
// {
// }

inline size_t _nbtWriter(void *userData, uint8_t *data, size_t size)
{
    auto out = static_cast<std::vector<uint8_t> *>(userData);
    for (size_t i = 0; i < size; i++)
        out->push_back(data[i]);
    // out->insert(out->end(), data, data + size);
    return size;
}

inline void addNBT(std::vector<uint8_t> &out, nbt_tag_t *tag, nbt_write_flags_t writeFlag = NBT_WRITE_FLAG_USE_RAW)
{
    if (tag == nullptr) {
        addByte(out, 0);
        return;
    }
    nbt_writer_t writer {_nbtWriter, &out};
    nbt_write(writer, tag, writeFlag);
}

template<isBaseOf<nbt::Base> T>
constexpr void addNBT(std::vector<uint8_t> &out, const T &data)
{
    data.serialize(out);
}

constexpr void addSlot(std::vector<uint8_t> &out, const Slot &data)
{
    addBoolean(out, data.present);
    if (data.present) {
        addVarInt(out, data.itemID);
        addByte(out, data.itemCount);
        addNBT(out, data.nbt);
        // addByte(out, 0);
    }
}

constexpr void addIdentifier(std::vector<uint8_t> &out, const std::string &data) { addString(out, data); }

constexpr void addUUID(std::vector<uint8_t> &out, const u128 &data)
{
    // addLong(out, (data & AUGH) >> 64);
    addLong(out, data.most);
    addLong(out, data.least);
}

template<typename T, void (*add)(std::vector<uint8_t> &, const T &), uint64_t ArraySize>
constexpr void addArray(std::vector<uint8_t> &out, const world_storage::DynamicStorage<T, ArraySize> &data)
{
    addVarInt(out, data.data().size());

    for (const T &i : data.data())
        add(out, i);
}

template<typename T, void (*add)(std::vector<uint8_t> &, const T &)>
constexpr void addArray(std::vector<uint8_t> &out, const std::vector<T> &data)
{
    addVarInt(out, data.size());

    for (const T &i : data)
        add(out, i);
}

template<typename T, void (*add)(std::vector<uint8_t> &, const T &), uint64_t Size>
constexpr void addArray(std::vector<uint8_t> &out, const std::array<T, Size> &data)
{
    addVarInt(out, data.size());

    for (const T &i : data)
        add(out, i);
}

constexpr void addPosition(std::vector<uint8_t> &out, const Position &data) { addLong(out, ((data.x & 0x3FFFFFF) << 38) | ((data.z & 0x3FFFFFF) << 12) | (data.y & 0xFFF)); }
} // namespace protocol

#endif // CUBICSERVER_PROTOCOL_SERIALIZATION_ADDPRIMARYTYPE_HPP
