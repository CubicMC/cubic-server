#include "Packet.hpp"
#include <stdexcept>

namespace Protocol
{

    Packet::Packet() : _packet_id(0)
    {
    }

    Packet::~Packet()
    {
    }

    void Packet::setPacketID(int32_t packet_id)
    {
        _packet_id = packet_id;
    }

    int32_t Packet::getPacketID(void) const
    {
        return _packet_id;
    }

    std::vector<uint8_t> Packet::serialize(void) const
    {
        std::vector<uint8_t> result;
        constexpr uint8_t CONTINUE_BIT = 0x80;
        constexpr uint8_t SEGMENT_BITS = 0x7f;
        uint32_t value = _payload.size() + 1; // TODO: Fix packet id length

        // TODO: Stop duplicating code ffs
        while (true)
        {
            if ((value & ~SEGMENT_BITS) == 0)
            {
                result.push_back(static_cast<uint8_t>(value));
                break;
            }

            result.push_back((value & SEGMENT_BITS) | CONTINUE_BIT);

            value >>= 7;
        }

        value = _packet_id;
        while (true)
        {
            if ((value & ~SEGMENT_BITS) == 0)
            {
                result.push_back(static_cast<uint8_t>(value));
                break;
            }

            result.push_back((value & SEGMENT_BITS) | CONTINUE_BIT);

            value >>= 7;
        }

        return std::vector<uint8_t>();
    }

    int32_t Packet::popVarInt(void)
    {
        uint32_t value = 0;
        int position = 0;
        uint8_t currentByte = 0;
        constexpr uint8_t CONTINUE_BIT = 0x80;
        constexpr uint8_t SEGMENT_BITS = 0x7f;

        while (true)
        {
            if (_payload.size() == 0)
                throw std::runtime_error("Not enough data to parse VarInt");
            currentByte = _payload.at(0);
            _payload.erase(_payload.begin());
            value |= (currentByte & SEGMENT_BITS) << position;

            if ((currentByte & CONTINUE_BIT) == 0)
                break;

            position += 7;

            if (position >= 32)
                throw std::runtime_error("VarInt is too big");
        }

        return value;
    }

    void Packet::addVarInt(int32_t data)
    {
        constexpr uint8_t CONTINUE_BIT = 0x80;
        constexpr uint8_t SEGMENT_BITS = 0x7f;
        uint32_t value = static_cast<uint32_t>(data);
        while (true)
        {
            if ((value & ~SEGMENT_BITS) == 0)
            {
                _payload.push_back(static_cast<uint8_t>(value));
                return;
            }

            _payload.push_back((value & SEGMENT_BITS) | CONTINUE_BIT);

            value >>= 7;
        }
    }

    std::string Packet::popString(void)
    {
        int32_t size = popVarInt();
        if (size > _payload.size())
            throw std::runtime_error("Not enough data to parse string");
        // This is so scuffed, no way it works
        std::string result = std::string(_payload.begin(), _payload.begin() + size);
        _payload.erase(_payload.begin(), _payload.begin() + size);
        return result;
    }

    void Packet::addVarString(const std::string &data)
    {
        addVarInt(data.size());
        _payload.insert(_payload.end(), data.begin(), data.end());
    }

    uint16_t Packet::popUnsignedShort(void)
    {
        uint16_t result = 0;

        if (_payload.size() < 2)
            throw std::runtime_error("Not enough data to parse unsigned short");

        result = _payload.at(1) | (_payload.at(0) << 8);
        _payload.erase(_payload.begin());
        _payload.erase(_payload.begin());
        return result;
    }

    void Packet::addUnsignedShort(uint16_t data)
    {
        _payload.push_back(data & 0xff);
        _payload.push_back(data >> 8);
    }
}
