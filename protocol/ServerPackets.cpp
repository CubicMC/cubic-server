#include <optional>

#include "ServerPackets.hpp"
#include "PacketUtils.hpp"
#include "typeSerialization.hpp"

using namespace protocol;

std::shared_ptr<Handshake> protocol::parseHandshake(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<Handshake>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popVarInt, &Handshake::prot_version,
          popString, &Handshake::addr,
          popUnsignedShort, &Handshake::port,
          popVarInt, &Handshake::next_state);
    return h;
}

std::shared_ptr<StatusRequest> protocol::parseStatusRequest(std::vector<uint8_t> &buffer)
{
    return {};
}

std::shared_ptr<LoginStart> protocol::parseLoginStart(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<LoginStart>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popString, &LoginStart::name,
          popBoolean, &LoginStart::has_sig_data);
    if (h->has_sig_data) {
        parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
              popLong, &LoginStart::timestamp,
              popVarInt, &LoginStart::public_key_length);
        parseExtra(buffer.data(), buffer.data() + buffer.size() - 1, *h,
                   popByteArray, &LoginStart::public_key, h->public_key_length);
        parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
              popVarInt, &LoginStart::signature_length);
        parseExtra(buffer.data(), buffer.data() + buffer.size() - 1, *h,
                   popByteArray, &LoginStart::signature, h->signature_length);
    }
    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popBoolean, &LoginStart::has_player_uuid);
    if (h->has_player_uuid)
        parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
              popUUID, &LoginStart::player_uuid);
    return h;
}

std::shared_ptr<PingRequest> protocol::parsePingRequest(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<PingRequest>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popLong, &PingRequest::payload);
    return h;
}

std::shared_ptr<ConfirmTeleportation> protocol::parseConfirmTeleportation(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<ConfirmTeleportation>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popVarInt, &ConfirmTeleportation::teleport_id);
    return h;
}

std::shared_ptr<EncryptionResponse> protocol::parseEncryptionResponse(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<EncryptionResponse>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popVarInt, &EncryptionResponse::shared_secret_length);
    parseExtra(buffer.data(), buffer.data() + buffer.size() - 1, *h,
               popByteArray, &EncryptionResponse::shared_secret, h->shared_secret_length);
    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popBoolean, &EncryptionResponse::has_verify_token);
    if (!h->has_verify_token)
        return h;
    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popVarInt, &EncryptionResponse::verify_token_length);
    parseExtra(buffer.data(), buffer.data() + buffer.size() - 1, *h,
               popByteArray, &EncryptionResponse::verify_token, h->verify_token_length);
    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popLong, &EncryptionResponse::salt,
          popVarInt, &EncryptionResponse::message_signature_length);
    parseExtra(buffer.data(), buffer.data() + buffer.size() - 1, *h,
               popByteArray, &EncryptionResponse::message_signature, h->message_signature_length);
    return h;
}

std::shared_ptr<QueryBlockEntityTag> protocol::parseQueryBlockEntityTag(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<QueryBlockEntityTag>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popVarInt, &QueryBlockEntityTag::transaction_id,
          popPosition, &QueryBlockEntityTag::location);
    return h;
}

std::shared_ptr<ChangeDifficulty> protocol::parseChangeDifficulty(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<ChangeDifficulty>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popByte, &ChangeDifficulty::new_difficulty);
    return h;
}

std::shared_ptr<ClientCommand> protocol::parseClientCommand(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<ClientCommand>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popClientCommandActionID, &ClientCommand::action_id);
    return h;
}

std::shared_ptr<ClientInformation> protocol::parseClientInformation(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<ClientInformation>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popString, &ClientInformation::locale,
          popByte, &ClientInformation::view_distance,
          popClientInformationChatMode, &ClientInformation::chat_mode,
          popBoolean, &ClientInformation::chat_colors,
          popByte, &ClientInformation::displayed_skin_parts,
          popClientInformationMainHand, &ClientInformation::main_hand,
          popBoolean, &ClientInformation::enable_text_filtering,
          popBoolean, &ClientInformation::allow_server_listings);
    return h;
}

std::shared_ptr<CommandSuggestionRequest> protocol::parseCommandSuggestionRequest(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<CommandSuggestionRequest>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popVarInt, &CommandSuggestionRequest::transaction_id,
          popString, &CommandSuggestionRequest::text);
    return h;
}

std::shared_ptr<ClickContainerButton> protocol::parseClickContainerButton(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<ClickContainerButton>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popByte, &ClickContainerButton::window_id,
          popByte, &ClickContainerButton::button_id);
    return h;
}

std::shared_ptr<CloseContainerRequest> protocol::parseCloseContainerRequest(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<CloseContainerRequest>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popByte, &CloseContainerRequest::window_id);
    return h;
}

std::shared_ptr<EditBook> protocol::parseEditBook(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<EditBook>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popVarInt, &EditBook::slot,
          popVarInt, &EditBook::count);
    parseExtra(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popStringArray, &EditBook::entries, h->count);
    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popBoolean, &EditBook::has_title);
    if (h->has_title)
        parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
              popString, &EditBook::title);
    return h;
}

std::shared_ptr<QueryEntityTag> protocol::parseQueryEntityTag(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<QueryEntityTag>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popVarInt, &QueryEntityTag::transaction_id,
          popVarInt, &QueryEntityTag::entity_id);
    return h;
}

std::shared_ptr<Interact> protocol::parseInteract(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<Interact>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popVarInt, &Interact::entity_id,
          popVarInt, &Interact::type);
    if (h->type == 2)
        parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
              popFloat, &Interact::target_x,
              popFloat, &Interact::target_y,
              popFloat, &Interact::target_z);
    if (h->type != 1)
        parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
              popVarInt, &Interact::hand);
    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popBoolean, &Interact::sneaking);
    return h;
}

std::shared_ptr<JigsawGenerate> protocol::parseJigsawGenerate(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<JigsawGenerate>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popPosition, &JigsawGenerate::location,
          popVarInt, &JigsawGenerate::levels,
          popBoolean, &JigsawGenerate::keep_jigsaws);
    return h;
}

std::shared_ptr<KeepAliveResponse> protocol::parseKeepAliveResponse(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<KeepAliveResponse>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popLong, &KeepAliveResponse::keep_alive_id);
    return h;
}