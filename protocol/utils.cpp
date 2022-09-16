#include <stdexcept>

#include "utils.hpp"

using namespace protocol;

bool protocol::popVarInt(std::vector<uint8_t> &buffer, int32_t &data)
{
    data = 0;
    int position = 0;
    uint8_t currentByte = 0;
    constexpr uint8_t CONTINUE_BIT = 0x80;
    constexpr uint8_t SEGMENT_BITS = 0x7f;

    while (true)
    {
        if (buffer.size() == 0)
            return false;
        currentByte = buffer.at(0);
        buffer.erase(buffer.begin());
        data |= (currentByte & SEGMENT_BITS) << position;

        if ((currentByte & CONTINUE_BIT) == 0)
            break;

        position += 7;

        if (position >= 32)
            return false;
    }

    return true;
}

void protocol::addVarInt(int32_t data, std::vector<uint8_t> &buffer)
{
    constexpr uint8_t CONTINUE_BIT = 0x80;
    constexpr uint8_t SEGMENT_BITS = 0x7f;
    uint32_t value = static_cast<uint32_t>(data);
    while (true)
    {
        if ((value & ~SEGMENT_BITS) == 0)
        {
            buffer.push_back(static_cast<uint8_t>(value));
            return;
        }

        buffer.push_back((value & SEGMENT_BITS) | CONTINUE_BIT);

        value >>= 7;
    }
}

bool protocol::popString(std::vector<uint8_t> &buffer, std::string &data)
{
    int32_t size = 0;
    if (!popVarInt(buffer, size))
        return false; // TODO: Change that to a boolean
    if (size > buffer.size())
        return false;
    // This is so scuffed, no way it works
    data = std::string(buffer.begin(), buffer.begin() + size);
    buffer.erase(buffer.begin(), buffer.begin() + size);
    return true;
}

void protocol::addVarString(const std::string &data, std::vector<uint8_t> &buffer)
{
    addVarInt(data.size(), buffer);
    buffer.insert(buffer.end(), data.begin(), data.end());
}

bool protocol::popUnsignedShort(std::vector<uint8_t> &buffer, uint16_t &data)
{
    if (buffer.size() < 2)
        return false;

    data = buffer.at(1) | (buffer.at(0) << 8);
    buffer.erase(buffer.begin());
    buffer.erase(buffer.begin());
    return true;
}

void protocol::addUnsignedShort(uint16_t data, std::vector<uint8_t> &buffer)
{
    buffer.push_back(data & 0xff);
    buffer.push_back(data >> 8);
}
