/*
    All pop functions from the basic types specified in the protocol
    Some of them have a specific name in the protocol, but they are sent a primitive type
    https://wiki.vg/index.php?title=Protocol&oldid=17753
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
    constexpr uint8_t popByte(uint8_t *&at, uint8_t *eof)
    {
        if (eof - at < 0 )
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

        while (true)
        {
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

        while (true)
        {
            if (at > eof)
                throw PacketEOF("Not enough data in packet to parse a VarInt");
            currentByte = *at++;
            value |= (currentByte & SEGMENT_BITS) << position;

            if ((currentByte & CONTINUE_BIT) == 0)
                return value;

            position += 7;

            if (position >= 64)
                throw VarIntOverflow("VarInt exceeds max length");
        }
    }
    constexpr float popFloat(uint8_t *&at, uint8_t *eof)
    {
        return static_cast<float>(popInt(at, eof));
    }

    constexpr double popDouble(uint8_t *&at, uint8_t *eof)
    {
        return static_cast<double>(popLong(at, eof));
    }

    constexpr std::string popString(uint8_t *&at, uint8_t *eof)
    {
        int32_t size = popVarInt(at, eof);

        if (size > eof - at + 1)
            throw PacketEOF("Not enough data in packet to parse a String");
        if (size == 0)
            throw ZeroLengthString("Zero length strings can't be parsed");
        std::string value(at, at + size);
        at += size;
        return value;
    }

    constexpr std::string popChat(uint8_t *&at, uint8_t *eof)
    {
        return popString(at, eof);
    }

    constexpr __int128 popUUID(uint8_t *&at, uint8_t *eof)
    {
        if (eof - at < 15)
            throw PacketEOF("Not enough data in packet to parse a Long");

        int64_t value = 0;

        for (int i = 0; i < 16; i++)
            value = (value << 8) + *at++;

        return value;
    }

    constexpr std::vector<long> popBitSet(uint8_t *&at, uint8_t *eof)
    {
        std::vector<long> set;
        int32_t size = popVarInt(at, eof);

        for (int i = 0; i < size; i++)
            set.push_back(popLong(at, eof));

        return set;
    }

    template<typename T, T(*pop)(uint8_t *&begin, uint8_t *end)>
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
} // namespace protocol
