#ifndef AE9C1FA0_D3A2_4B7D_962E_4EAF72963603
#define AE9C1FA0_D3A2_4B7D_962E_4EAF72963603

#include <cstdint>
#include <string>
#include <memory>
#include <vector>
#include <optional>
#include <unordered_map>
#include <functional>
#include <map>

namespace protocol
{

    enum class ServerPacketsID : int32_t {
        Handshake = 0x00
    };

    struct BaseServerPacket {
        virtual ~BaseServerPacket() = default;
    };

    struct Handshake : BaseServerPacket
    {
        int32_t prot_version;
        std::string addr;
        uint16_t port;
        int32_t next_state; // TODO: Use an enum here instead of an int32_t
    };

    std::shared_ptr<Handshake> parseHandshake(std::vector<uint8_t> &buffer);

    static const std::unordered_map<ServerPacketsID, std::function<std::shared_ptr<BaseServerPacket>(std::vector<uint8_t> &)>> packetIDToParseInitial = {
            {ServerPacketsID::Handshake, parseHandshake}
    };

    static const std::unordered_map<ServerPacketsID, std::function<std::shared_ptr<BaseServerPacket>(std::vector<uint8_t> &)>> packetIDToParseStatus = {
    };

    static const std::unordered_map<ServerPacketsID, std::function<std::shared_ptr<BaseServerPacket>(std::vector<uint8_t> &)>> packetIDToParseLogin = {
    };

    static const std::unordered_map<ServerPacketsID, std::function<std::shared_ptr<BaseServerPacket>(std::vector<uint8_t> &)>> packetIDToParsePlay = {
    };
}

#endif /* AE9C1FA0_D3A2_4B7D_962E_4EAF72963603 */
