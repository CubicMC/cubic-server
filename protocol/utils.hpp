#ifndef D7286F40_D05F_4DC1_9A04_28C9F7417C4E
#define D7286F40_D05F_4DC1_9A04_28C9F7417C4E

#include <string>
#include <stdint.h>
#include <vector>

namespace protocol
{
    bool popVarInt(std::vector<uint8_t> &buffer, int32_t &data);
    void addVarInt(int32_t data, std::vector<uint8_t> &buffer);

    bool popString(std::vector<uint8_t> &buffer, std::string &data);
    void addVarString(const std::string &data, std::vector<uint8_t> &buffer);

    bool popUnsignedShort(std::vector<uint8_t> &buffer, uint16_t &data);
    void addUnsignedShort(uint16_t data, std::vector<uint8_t> &buffer);
}

#endif /* D7286F40_D05F_4DC1_9A04_28C9F7417C4E */
