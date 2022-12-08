/*
** All add functions from the basic types specified in the protocol
** Some of them have a specific name in the protocol, but they are sent as a primitive type
** https://wiki.vg/index.php?title=Protocol&oldid=17753
*/

#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "ParseExceptions.hpp"
#include "common.hpp"
#include "Structures.hpp"

namespace protocol
{
    constexpr void addByte(std::vector<uint8_t> &out, const uint8_t &data)
    {
        out.push_back(data);
    }

    constexpr void addBoolean(std::vector<uint8_t> &out, const bool &data)
    {
        if (data)
            addByte(out, 1);
        else
            addByte(out, 0);
    }

    // add short (int16_t)
    constexpr void addShort(std::vector<uint8_t> &out, const uint16_t &data)
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
                out.push_back(value & 0xF);
                return;
            }
            out.push_back((value & SEGMENT_BITS) | CONTINUE_BIT);
            value >>= 7;
        }
    }

    // Add long (int64_t)
    constexpr void addLong(std::vector<uint8_t> &out, const int64_t &data)
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
                out.push_back(value & 0xF);
                return;
            }
            out.push_back((value & SEGMENT_BITS) | CONTINUE_BIT);
            value >>= 7;
        }
    }

    constexpr void addFloat(std::vector<uint8_t> &out, const float &data)
    {
        addInt(out, static_cast<int32_t>(data));
    }

    constexpr void addDouble(std::vector<uint8_t> &out, const double &data)
    {
        addLong(out, static_cast<int64_t>(data));
    }

    // Add string with a varint length
    static constexpr void _addString(std::vector<uint8_t> &out, const std::string &data, std::size_t maxSize)
    {
        if (data.size() > 32767)
            throw MaxLengthString("String is too long");

        addVarInt(out, data.size());

        for (char c : data)
            out.push_back(c);
    }

    // Default addString with a max size of 32767
    constexpr void addString(std::vector<uint8_t> &out, const std::string &data)
    {
        _addString(out, data, 32767);
    }

    constexpr void addChat(std::vector<uint8_t> &out, const std::string &data)
    {
        _addString(out, data, 262144);
    }

    // TODO: gl :>
    // constexpr void addEntityMetadata(std::vector<uint8_t>, const EntityMetadata &data)
    // {
    // }

    constexpr void addSlot(std::vector<uint8_t> &out, const Slot &data)
    {
        addBoolean(out, data.present);
        if (data.present) {
            addVarInt(out, data.itemID);
            addByte(out, data.itemCount);
            // addNBT(out, data.nbt);
        }
    }

    // TODO: NBT stuff
    // constexpr void addNBT(std::vector<uint8_t>, const NBT &data)
    // {
    // }

    constexpr void addIdentifier(std::vector<uint8_t> &out, const std::string &data)
    {
        addString(out, data);
    }

    constexpr void addUUID(std::vector<uint8_t> &out, const __int128 &data)
    {
        for (int i = 0; i < 16; i++)
            out.push_back((data >> (120 - i * 8)) & 0xFF);
    }

    template<typename T, void(*add)(std::vector<uint8_t> &, const T&)>
    constexpr void addArray(std::vector<uint8_t> &out, const std::vector<T> &data)
    {
        addVarInt(out, data.size());

        for (const T &i : data)
            add(out, i);
    }

    constexpr void addPosition(std::vector<uint8_t> &out, const Position &data)
    {
        addLong(out, ((data.x & 0x3FFFFFF) << 38) | ((data.z & 0x3777777) << 12) | (data.y & 0xFFF));
    }
} // namespace protocol
