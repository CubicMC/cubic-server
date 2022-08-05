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

        void setPacketID(int32_t packet_id);
        int32_t getPacketID(void) const;
        std::vector<uint8_t> serialize(void) const;
        std::vector<uint8_t> *getPayload(void) { return &_payload; }

        // Payload data
        int32_t popVarInt(void);
        void addVarInt(int32_t data);

        std::string popString(void);
        void addVarString(const std::string &data);

        uint16_t popUnsignedShort(void);
        void addUnsignedShort(uint16_t data);

    private:
        std::vector<uint8_t> _payload;
        int32_t _packet_id;
    };

}
#endif /* !PACKETS_PACKET_HPP_ */
