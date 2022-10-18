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

std::shared_ptr<LockDifficulty> protocol::parseLockDifficulty(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<LockDifficulty>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popBoolean, &LockDifficulty::locked);
    return h;
}

std::shared_ptr<SetPlayerPosition> protocol::parseSetPlayerPosition(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<SetPlayerPosition>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popDouble, &SetPlayerPosition::x,
          popDouble, &SetPlayerPosition::feet_y,
          popDouble, &SetPlayerPosition::z,
          popBoolean, &SetPlayerPosition::on_ground);
    return h;
}

std::shared_ptr<SetPlayerPositionAndRotation> protocol::parseSetPlayerPositionAndRotation(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<SetPlayerPositionAndRotation>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popDouble, &SetPlayerPositionAndRotation::x,
          popDouble, &SetPlayerPositionAndRotation::feet_y,
          popDouble, &SetPlayerPositionAndRotation::z,
          popFloat, &SetPlayerPositionAndRotation::yaw,
          popFloat, &SetPlayerPositionAndRotation::pitch,
          popBoolean, &SetPlayerPositionAndRotation::on_ground);
    return h;
}

std::shared_ptr<SetPlayerRotation> protocol::parseSetPlayerRotation(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<SetPlayerRotation>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popFloat, &SetPlayerRotation::yaw,
          popFloat, &SetPlayerRotation::pitch,
          popBoolean, &SetPlayerRotation::on_ground);
    return h;
}

std::shared_ptr<SetPlayerOnGround> protocol::parseSetPlayerOnGround(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<SetPlayerOnGround>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popBoolean, &SetPlayerOnGround::on_ground);
    return h;
}

std::shared_ptr<MoveVehicle> protocol::parseMoveVehicle(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<MoveVehicle>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popDouble, &MoveVehicle::x,
          popDouble, &MoveVehicle::y,
          popDouble, &MoveVehicle::z,
          popFloat, &MoveVehicle::yaw,
          popFloat, &MoveVehicle::pitch);
    return h;
}

std::shared_ptr<PaddleBoat> protocol::parsePaddleBoat(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<PaddleBoat>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popBoolean, &PaddleBoat::left_paddle_turning,
          popBoolean, &PaddleBoat::right_paddle_turning);
    return h;
}

std::shared_ptr<PickItem> protocol::parsePickItem(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<PickItem>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popVarInt, &PickItem::slot_to_use);
    return h;
}

std::shared_ptr<PlaceRecipe> protocol::parsePlaceRecipe(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<PlaceRecipe>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popByte, &PlaceRecipe::window_id,
          popString, &PlaceRecipe::recipe,
          popBoolean, &PlaceRecipe::make_all);
    return h;
}

std::shared_ptr<PlayerAbilities> protocol::parsePlayerAbilities(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<PlayerAbilities>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popByte, &PlayerAbilities::flags);
    return h;
}

std::shared_ptr<PlayerAction> protocol::parsePlayerAction(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<PlayerAction>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popVarInt, &PlayerAction::status,
          popPosition, &PlayerAction::location,
          popByte, &PlayerAction::face,
          popVarInt, &PlayerAction::sequence);
    return h;
}

std::shared_ptr<PlayerCommand> protocol::parsePlayerCommand(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<PlayerCommand>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popVarInt, &PlayerCommand::entity_id,
          popVarInt, &PlayerCommand::action_id,
          popVarInt, &PlayerCommand::jump_boost);
    return h;
}

std::shared_ptr<PlayerInput> protocol::parsePlayerInput(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<PlayerInput>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popFloat, &PlayerInput::sideways,
          popFloat, &PlayerInput::forward,
          popByte, &PlayerInput::flags);
    return h;
}

std::shared_ptr<Pong> protocol::parsePong(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<Pong>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popInt, &Pong::id);
    return h;
}

std::shared_ptr<ChangeRecipeBookSettings> protocol::parseChangeRecipeBookSettings(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<ChangeRecipeBookSettings>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popVarInt, &ChangeRecipeBookSettings::book_id,
          popBoolean, &ChangeRecipeBookSettings::book_open,
          popBoolean, &ChangeRecipeBookSettings::filter_active);
    return h;
}

std::shared_ptr<SetSeenRecipe> protocol::parseSetSeenRecipe(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<SetSeenRecipe>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popString, &SetSeenRecipe::recipe_id);
    return h;
}

std::shared_ptr<RenameItem> protocol::parseRenameItem(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<RenameItem>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popString, &RenameItem::item_name);
    return h;
}

std::shared_ptr<ResourcePack> protocol::parseResourcePack(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<ResourcePack>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popVarInt, &ResourcePack::result);
    return h;
}

std::shared_ptr<SeenAdvancements> protocol::parseSeenAdvancements(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<SeenAdvancements>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popVarInt, &SeenAdvancements::action);
    if (h->action == 0)
        parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
              popString, &SeenAdvancements::tab_id);
    return h;
}

std::shared_ptr<SelectTrade> protocol::parseSelectTrade(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<SelectTrade>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popVarInt, &SelectTrade::selected_slot);
    return h;
}

std::shared_ptr<SetBeaconEffect> protocol::parseSetBeaconEffect(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<SetBeaconEffect>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popBoolean, &SetBeaconEffect::primary_effect_present,
          popVarInt, &SetBeaconEffect::primary_effect,
          popBoolean, &SetBeaconEffect::secondary_effect_present,
          popVarInt, &SetBeaconEffect::secondary_effect);
    return h;
}

std::shared_ptr<SetHeldItem> protocol::parseSetHeldItem(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<SetHeldItem>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popUnsignedShort, &SetHeldItem::slot);
    return h;
}

std::shared_ptr<ProgramCommandBlock> protocol::parseProgramCommandBlock(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<ProgramCommandBlock>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popPosition, &ProgramCommandBlock::location,
          popString, &ProgramCommandBlock::command,
          popVarInt, &ProgramCommandBlock::mode,
          popByte, &ProgramCommandBlock::flags);
    return h;
}

std::shared_ptr<ProgramCommandBlockMinecart> protocol::parseProgramCommandBlockMinecart(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<ProgramCommandBlockMinecart>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popVarInt, &ProgramCommandBlockMinecart::entity_id,
          popString, &ProgramCommandBlockMinecart::command,
          popBoolean, &ProgramCommandBlockMinecart::track_output);
    return h;
}

std::shared_ptr<ProgramJigsawBlock> protocol::parseProgramJigsawBlock(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<ProgramJigsawBlock>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popPosition, &ProgramJigsawBlock::location,
          popString, &ProgramJigsawBlock::name,
          popString, &ProgramJigsawBlock::target,
          popString, &ProgramJigsawBlock::pool,
          popString, &ProgramJigsawBlock::final_state,
          popString, &ProgramJigsawBlock::joint_type);
    return h;
}

std::shared_ptr<ProgramStructureBlock> protocol::parseProgramStructureBlock(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<ProgramStructureBlock>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popPosition, &ProgramStructureBlock::location,
          popVarInt, &ProgramStructureBlock::action,
          popVarInt, &ProgramStructureBlock::mode,
          popByte, &ProgramStructureBlock::offset_x,
          popByte, &ProgramStructureBlock::offset_y,
          popByte, &ProgramStructureBlock::offset_z,
          popByte, &ProgramStructureBlock::size_x,
          popByte, &ProgramStructureBlock::size_y,
          popByte, &ProgramStructureBlock::size_z,
          popVarInt, &ProgramStructureBlock::mirror,
          popVarInt, &ProgramStructureBlock::rotation,
          popString, &ProgramStructureBlock::metadata,
          popFloat, &ProgramStructureBlock::integrity,
          popVarLong, &ProgramStructureBlock::seed,
          popByte, &ProgramStructureBlock::flags);
    return h;
}

std::shared_ptr<UpdateSign> protocol::parseUpdateSign(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<UpdateSign>();

    parse(buffer.data(), buffer.data() + buffer.size() - 1, *h,
          popPosition, &UpdateSign::location,
          popString, &UpdateSign::line_1,
          popString, &UpdateSign::line_2,
          popString, &UpdateSign::line_3,
          popString, &UpdateSign::line_4);
    return h;
}