#ifndef D7286F40_D05F_4DC1_9A04_28C9F7417C4E
#define D7286F40_D05F_4DC1_9A04_28C9F7417C4E

#include <string>
#include <cstdint>
#include <iostream>

#include "ParseExceptions.hpp"

namespace protocol
{
    struct Position
    {
        int64_t x;
        int64_t z;
        int64_t y;
    };

    enum class ClientCommandActionID
    {
        perform_respawn = 0,
        request_stats = 1,
    };

    enum class ClientInformationChatMode
    {
        enabled = 0,
        commands_only = 1,
        hidden = 2,
    };

    enum class ClientInformationMainHand
    {
        left = 0,
        right = 1,
    };

    struct Instant
    {
        long seconds;
        int nanos;
    };

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

    constexpr void addInt(std::vector<uint8_t> &out, const int32_t &data)
    {
        for (int i = 0; i < 4; i++)
            out.push_back((data >> (i * 8)) & 0xFF);
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

    constexpr uint8_t popByte(uint8_t *&at, uint8_t *eof)
    {
        if (eof - at < 0 )
            throw PacketEOF("Not enough data in packet to parse a byte");

        uint8_t value = *at;
        at++;
        return value;
    }

    constexpr void addByte(std::vector<uint8_t> &out, const uint8_t &data)
    {
        out.push_back(data);
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
            throw PacketEOF("Not enough data in packet to parse a Long");

        int64_t value = 0;

        for (int i = 0; i < 8; i++)
            value = (value << 8) + *at++;

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

    constexpr Instant popInstantJavaObject(uint8_t *&at, uint8_t *eof)
    {
        Instant instant;
        // Java class thingy, don't ask...
        for (int i = 0; i < 36; i++)
            popByte(at, eof);
        uint8_t objectIdentifier = popByte(at, eof);
        if (objectIdentifier != 0x02)
            throw WrongObjectType("Wrong object identifier for Instant");
        instant.seconds = popVarLong(at, eof);
        instant.nanos = popVarInt(at, eof);
        return instant;
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

    constexpr void addPosition(std::vector<uint8_t> &out, const Position &data)
    {
        int64_t h = ((data.x & 0x3FFFFFF) << 38) | ((data.z & 0x3777777) << 12) | (data.y & 0xFFF);
        return addLong(out, h);
    }

    constexpr ClientCommandActionID popClientCommandActionID(uint8_t *&at, uint8_t *eof)
    {
        auto value = popVarInt(at, eof);

        if (value != 0 && value != 1)
            throw OutOfRangeEnum("Client Command Action ID is not within the range of the enum");
        return static_cast<ClientCommandActionID>(value);
    }

    constexpr void addClientCommandActionID(std::vector<uint8_t> &out, const ClientCommandActionID &data)
    {
        return addVarInt(out, static_cast<int32_t>(data));
    }

    constexpr ClientInformationChatMode popClientInformationChatMode(uint8_t *&at, uint8_t *eof)
    {
        auto value = popVarInt(at, eof);

        if (value != 0 && value != 1 && value != 2)
            throw OutOfRangeEnum("Client Information Chat Mode is not within the range of the enum");
        return static_cast<ClientInformationChatMode>(value);
    }

    constexpr void addClientInformationChatMode(std::vector<uint8_t> &out, const ClientInformationChatMode &data)
    {
        return addVarInt(out, static_cast<int32_t>(data));
    }

    constexpr ClientInformationMainHand popClientInformationMainHand(uint8_t *&at, uint8_t *eof)
    {
        auto value = popVarInt(at, eof);

        if (value != 0 && value != 1)
            throw OutOfRangeEnum("Client Information Main Hand is not within the range of the enum");
        return static_cast<ClientInformationMainHand>(value);
    }

    constexpr void addClientInformationMainHand(std::vector<uint8_t> &out, const ClientInformationMainHand &data)
    {
        return addVarInt(out, static_cast<int32_t>(data));
    }

    constexpr bool popBoolean(uint8_t *&at, uint8_t *eof)
    {
        auto value = popByte(at, eof);

        if (value != 0 && value != 1)
            throw OutOfRangeBoolean("Given boolean is not 0 or 1");
        return value == 1;
    }

    constexpr void addBoolean(std::vector<uint8_t> &out, const bool &data)
    {
        if (data)
            addByte(out, 1);
        else
            addByte(out, 0);
    }

    constexpr std::vector<std::string> popStringArray(const int32_t &count, uint8_t *&at, uint8_t *eof)
    {
        std::vector<std::string> value;

        for (auto i = 0; i < count; i++)
            value.push_back(popString(at, eof));
        return value;
    }

    constexpr std::vector<uint8_t> popByteArray(const int32_t &count, uint8_t *&at, uint8_t *eof)
    {
        std::vector<uint8_t> value;

        for (auto i = 0; i < count; i++)
            value.push_back(popByte(at, eof));
        return value;
    }

    constexpr void addByteArray(std::vector<uint8_t> &out, const std::vector<uint8_t> &data)
    {
        for (auto i : data)
            addByte(out, i);
    }

    constexpr __int128 popUUID(uint8_t *&at, uint8_t *eof)
    {
        auto a = (__int128) popLong(at, eof);
        auto b = (__int128) popLong(at, eof);

        return (a << 64) | b;
    }

    constexpr void addUUID(std::vector<uint8_t> &out, const __int128 &data)
    {
        addLong(out, data >> 64);
        addLong(out, data & 0xFFFFFFFFFFFFFFFF);
    }

    constexpr int32_t popInt(uint8_t *&at, uint8_t *eof)
    {
        if (eof - at < 3)
            throw PacketEOF("Not enough data in packet to parse an Int");

        int32_t value = 0;

        for (int i = 0; i < 4; i++)
            value = (value << 8) + *at++;

        return value;
    }

    constexpr float popFloat(uint8_t *&at, uint8_t *eof)
    {
        return (float) popInt(at, eof);
    }

    constexpr double popDouble(uint8_t *&at, uint8_t *eof)
    {
        return (double) popLong(at, eof);
    }
}

#endif /* D7286F40_D05F_4DC1_9A04_28C9F7417C4E */
