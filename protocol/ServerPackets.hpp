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

#include "typeSerialization.hpp"

namespace protocol
{

    enum class ServerPacketsID : int32_t {
        Handshake = 0x00,
        StatusRequest = 0x00,
        ConfirmTeleportation = 0x00,
        PingRequest = 0x01,
        QueryBlockEntityTag = 0x01,
        ChangeDifficulty = 0x02,
        ClientCommand = 0x06,
    };

    struct BaseServerPacket {
        virtual ~BaseServerPacket() = default;
    };

    // Packets

    struct Handshake : BaseServerPacket
    {
        int32_t prot_version;
        std::string addr;
        uint16_t port;
        int32_t next_state; // TODO: Use an enum here instead of an int32_t
    };
    std::shared_ptr<Handshake> parseHandshake(std::vector<uint8_t> &buffer);

    struct StatusRequest : BaseServerPacket
    {};
    std::shared_ptr<StatusRequest> parseStatusRequest(std::vector<uint8_t> &buffer);

    struct PingRequest : BaseServerPacket
    {
        int64_t payload;
    };
    std::shared_ptr<PingRequest> parsePingRequest(std::vector<uint8_t> &buffer);

    struct ConfirmTeleportation : BaseServerPacket
    {
        int32_t teleport_id;
    };
    std::shared_ptr<ConfirmTeleportation> parseConfirmTeleportation(std::vector<uint8_t> &buffer);

    struct QueryBlockEntityTag : BaseServerPacket
    {
        int32_t transaction_id;
        Position location;
    };
    std::shared_ptr<QueryBlockEntityTag> parseQueryBlockEntityTag(std::vector<uint8_t> &buffer);

    struct ChangeDifficulty : BaseServerPacket
    {
        uint8_t new_difficulty;
    };
    std::shared_ptr<ChangeDifficulty> parseChangeDifficulty(std::vector<uint8_t> &buffer);

    struct ClientCommand : BaseServerPacket
    {
        ClientCommandActionID action_id;
    };
    std::shared_ptr<ClientCommand> parseClientCommand(std::vector<uint8_t> &buffer);

    // Maps

    static const std::unordered_map<ServerPacketsID, std::function<std::shared_ptr<BaseServerPacket>(std::vector<uint8_t> &)>> packetIDToParseInitial = {
            {ServerPacketsID::Handshake, parseHandshake},
    };

    static const std::unordered_map<ServerPacketsID, std::function<std::shared_ptr<BaseServerPacket>(std::vector<uint8_t> &)>> packetIDToParseStatus = {
            {ServerPacketsID::StatusRequest, &parseStatusRequest},
            {ServerPacketsID::PingRequest, &parsePingRequest},
    };

    static const std::unordered_map<ServerPacketsID, std::function<std::shared_ptr<BaseServerPacket>(std::vector<uint8_t> &)>> packetIDToParseLogin = {
    };

    static const std::unordered_map<ServerPacketsID, std::function<std::shared_ptr<BaseServerPacket>(std::vector<uint8_t> &)>> packetIDToParsePlay = {
            {ServerPacketsID::ConfirmTeleportation, &parseConfirmTeleportation},
            {ServerPacketsID::QueryBlockEntityTag, &parseQueryBlockEntityTag},
            {ServerPacketsID::ChangeDifficulty, &parseChangeDifficulty},
            {ServerPacketsID::ClientCommand, &parseClientCommand},
    };
}

#endif /* AE9C1FA0_D3A2_4B7D_962E_4EAF72963603 */
