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

    // void addVarInt(int32_t data, std::vector<uint8_t> &buffer);

    constexpr std::string popString(uint8_t *&at, uint8_t *eof)
    {
        int32_t size = popVarInt(at, eof);

        if (size > eof - at + 1)
            throw PacketEOF("Not enough data in packet to parse a String");
        if (size == 0)
            throw ZeroLengthString("Zero length strings can't be parsed");
        std::string value(at, at + size - 1);
        at += size;
        return value;
    }
    // void addVarString(const std::string &data, std::vector<uint8_t> &buffer);

    constexpr uint16_t popUnsignedShort(uint8_t *&at, uint8_t *eof)
    {
        if (eof - at < 1)
            throw PacketEOF("Not enough data in packet to parse an unsigned short");

        uint16_t value = *(at + 1) | (*at << 8);
        at += 2;
        return value;
    }
    // void addUnsignedShort(uint16_t data, std::vector<uint8_t> &buffer);
}

#endif /* D7286F40_D05F_4DC1_9A04_28C9F7417C4E */
