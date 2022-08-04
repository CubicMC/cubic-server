#ifndef PACKETS_PACKET_HPP_
#define PACKETS_PACKET_HPP_

#include <stddef.h>
#include <stdint.h>
#include <vector>
#include <string>

namespace Protocol
{

    /**
     * @brief Handles packets serialization and deserialization
     *
     * Payload is in FIFO container
     */
    class Packet
    {
    public:
        Packet();
        ~Packet();

        void setPacketID(uint64_t packet_id);
        uint64_t getPacketID(void) const;
        std::vector<uint8_t> serialize(void) const;

        // Payload data
        int32_t popVarInt(void);
        void addVarInt(int32_t data);

        std::string popString(void);
        void addVarString(const std::string &data);

        uint16_t popUnsignedShort(void);
        void addUnsignedShort(uint16_t data);

    private:
        std::vector<uint8_t> _payload;
        uint64_t _packet_id;
    };

}
#endif /* !PACKETS_PACKET_HPP_ */
