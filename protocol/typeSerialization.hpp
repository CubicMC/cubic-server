#ifndef D7286F40_D05F_4DC1_9A04_28C9F7417C4E
#define D7286F40_D05F_4DC1_9A04_28C9F7417C4E

#include <string>
#include <stdint.h>
#include <ParseExceptions.hpp>
#include <iostream>

namespace protocol
{

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
    // void addVarString(const std::string &data, std::vector<uint8_t> &buffer);
    constexpr void addString(std::vector<uint8_t> &out, const std::string &data)
    {
        if (data.size() > 32767)
            throw MaxLengthString("String is too long");

        addVarInt(out, data.size());

        for (char c : data)
            out.push_back(c);
    }

    constexpr uint16_t popUnsignedShort(uint8_t *&at, uint8_t *eof)
    {
        if (eof - at < 1)
            throw PacketEOF("Not enough data in packet to parse an unsigned short");

        uint16_t value = *(at + 1) | (*at << 8);
        at += 2;
        return value;
    }

    // constexpr void addUnsignedShort(std::vector<uint8_t> &out, const uint16_t &data)
    // {

    // }

    constexpr int64_t popLong(uint8_t *&at, uint8_t *eof)
    {
        if (eof - at < 7)
            throw PacketEOF("Not enough data in packet to parse a long");

        int64_t value = *((int64_t *)(at));
        at += 8;
        return value;
    }

    constexpr void addLong(std::vector<uint8_t> &out, const int64_t &data)
    {
        out.push_back((data >> 56) & 0xFF);
        out.push_back((data >> 48) & 0xFF);
        out.push_back((data >> 40) & 0xFF);
        out.push_back((data >> 32) & 0xFF);
        out.push_back((data >> 24) & 0xFF);
        out.push_back((data >> 16) & 0xFF);
        out.push_back((data >> 8) & 0xFF);
        out.push_back(data & 0xFF);
    }
}

#endif /* D7286F40_D05F_4DC1_9A04_28C9F7417C4E */
