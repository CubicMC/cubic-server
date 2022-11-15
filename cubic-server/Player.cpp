#include "Player.hpp"
#include "Server.hpp"

Player::Player(Client *cli)
    : _cli(cli)
{
    _log = logging::Logger::get_instance();
}

void Player::tick()
{}

void Player::_onConfirmTeleportation(const std::shared_ptr<protocol::ConfirmTeleportation> &pck)
{
    _log->debug("Got a Confirm Teleportation");
}

void Player::_onQueryBlockEntityTag(const std::shared_ptr<protocol::QueryBlockEntityTag> &pck)
{
    _log->debug("Got a Query Block Entity Tag");
}

void Player::_onChangeDifficulty(const std::shared_ptr<protocol::ChangeDifficulty> &pck)
{
    _log->debug("Got a Change difficulty");
}

// Receive a chat message from the client, transmit it to the chat system.
void Player::_onChatMessage(const std::shared_ptr<protocol::ChatMessage> &pck)
{
    // TODO: verify that the message is valid (signature, etc.)
    // pck->message
    // const auto clients = Server::getInstance()->getClients();
    // auto message = nlohmann::json::parse(pck->message);
    // nlohmann::json response;
    // response["translate"] = "chat.type.text";
    // response["with"] = nlohmann::json::array();
    // response["with"].push_back({"text", "PlayerName"});
    // response["with"].push_back({"text", message["text"]});

    // for (const auto &cli : clients)
    //     cli->sendChatMessageResponse(
    //         "",
    //         true,
    //         response.dump(),
    //         (int32_t) MsgType::Chat,
    //         0, // sender.getUUID(),
    //         "{\"text\": \"PlayerName\"}", // display name
    //         false,
    //         "",
    //         std::time(nullptr),
    //         0,
    //         0,
    //         std::vector<uint8_t>()
    //     );

    _log->debug("Got a Chat Message");
}

void Player::_onClientCommand(const std::shared_ptr<protocol::ClientCommand> &pck)
{
    _log->debug("Got a Client Command");
}

void Player::_onClientInformation(const std::shared_ptr<protocol::ClientInformation> &pck)
{
    _log->debug("Got a Client Information");
}

void Player::_onCommandSuggestionRequest(const std::shared_ptr<protocol::CommandSuggestionRequest> &pck)
{
    _log->debug("Got a Command Suggestion Request");
}

void Player::_onClickContainerButton(const std::shared_ptr<protocol::ClickContainerButton> &pck)
{
    _log->debug("Got a Click Container Button");
}

void Player::_onCloseContainerRequest(const std::shared_ptr<protocol::CloseContainerRequest> &pck)
{
    _log->debug("Got a Close Container Request");
}

void Player::_onEditBook(const std::shared_ptr<protocol::EditBook> &pck)
{
    _log->debug("Got a Edit Book");
}

void Player::_onQueryEntityTag(const std::shared_ptr<protocol::QueryEntityTag> &pck)
{
    _log->debug("Got a Query Entity Tag");
}

void Player::_onInteract(const std::shared_ptr<protocol::Interact> &pck)
{
    _log->debug("Got a Interact");
}

void Player::_onJigsawGenerate(const std::shared_ptr<protocol::JigsawGenerate> &pck)
{
    _log->debug("Got a Jigsaw Generate");
}

void Player::_onKeepAliveResponse(const std::shared_ptr<protocol::KeepAliveResponse> &pck)
{
    _log->debug("Got a Keep Alive Response");
}

void Player::_onLockDifficulty(const std::shared_ptr<protocol::LockDifficulty> &pck)
{
    _log->debug("Got a Lock Difficulty");
}

void Player::_onSetPlayerPosition(const std::shared_ptr<protocol::SetPlayerPosition> &pck)
{
    _log->debug("Got a Set Player Position");
}

void Player::_onSetPlayerPositionAndRotation(const std::shared_ptr<protocol::SetPlayerPositionAndRotation> &pck)
{
    _log->debug("Got a Set Player Position And Rotation");
}

void Player::_onSetPlayerRotation(const std::shared_ptr<protocol::SetPlayerRotation> &pck)
{
    _log->debug("Got a Set Player Rotation");
}

void Player::_onSetPlayerOnGround(const std::shared_ptr<protocol::SetPlayerOnGround> &pck)
{
    _log->debug("Got a Set Player On Ground");
}

void Player::_onMoveVehicle(const std::shared_ptr<protocol::MoveVehicle> &pck)
{
    _log->debug("Got a Move Vehicle");
}

void Player::_onPaddleBoat(const std::shared_ptr<protocol::PaddleBoat> &pck)
{
    _log->debug("Got a Paddle Boat");
}

void Player::_onPickItem(const std::shared_ptr<protocol::PickItem> &pck)
{
    _log->debug("Got a Pick Item");
}

void Player::_onPlaceRecipe(const std::shared_ptr<protocol::PlaceRecipe> &pck)
{
    _log->debug("Got a Place Recipe");
}

void Player::_onPlayerAbilities(const std::shared_ptr<protocol::PlayerAbilities> &pck)
{
    _log->debug("Got a Player Abilities");
}

void Player::_onPlayerAction(const std::shared_ptr<protocol::PlayerAction> &pck)
{
    _log->debug("Got a Player Action");
}

void Player::_onPlayerCommand(const std::shared_ptr<protocol::PlayerCommand> &pck)
{
    _log->debug("Got a Player Command");
}

void Player::_onPlayerInput(const std::shared_ptr<protocol::PlayerInput> &pck)
{
    _log->debug("Got a Player Input");
}

void Player::_onPong(const std::shared_ptr<protocol::Pong> &pck)
{
    _log->debug("Got a Pong");
}

void Player::_onChangeRecipeBookSettings(const std::shared_ptr<protocol::ChangeRecipeBookSettings> &pck)
{
    _log->debug("Got a Change Recipe Book Settings");
}

void Player::_onSetSeenRecipe(const std::shared_ptr<protocol::SetSeenRecipe> &pck)
{
    _log->debug("Got a Set Seen Recipe");
}

void Player::_onRenameItem(const std::shared_ptr<protocol::RenameItem> &pck)
{
    _log->debug("Got a Rename Item");
}

void Player::_onResourcePack(const std::shared_ptr<protocol::ResourcePack> &pck)
{
    _log->debug("Got a Resource Pack");
}

void Player::_onSeenAdvancements(const std::shared_ptr<protocol::SeenAdvancements> &pck)
{
    _log->debug("Got a Seen Advancements");
}

void Player::_onSelectTrade(const std::shared_ptr<protocol::SelectTrade> &pck)
{
    _log->debug("Got a Select Trade");
}

void Player::_onSetBeaconEffect(const std::shared_ptr<protocol::SetBeaconEffect> &pck)
{
    _log->debug("Got a Set Beacon Effect");
}

void Player::_onSetHeldItem(const std::shared_ptr<protocol::SetHeldItem> &pck)
{
    _log->debug("Got a Set Held Item");
}

void Player::_onProgramCommandBlock(const std::shared_ptr<protocol::ProgramCommandBlock> &pck)
{
    _log->debug("Got a Program Command Block");
}

void Player::_onProgramCommandBlockMinecart(const std::shared_ptr<protocol::ProgramCommandBlockMinecart> &pck)
{
    _log->debug("Got a Program Command Block Minecart");
}

void Player::_onProgramJigsawBlock(const std::shared_ptr<protocol::ProgramJigsawBlock> &pck)
{
    _log->debug("Got a Program Jigsaw Block");
}

void Player::_onProgramStructureBlock(const std::shared_ptr<protocol::ProgramStructureBlock> &pck)
{
    _log->debug("Got a Program Structure Block");
}

void Player::_onUpdateSign(const std::shared_ptr<protocol::UpdateSign> &pck)
{
    _log->debug("Got a Update Sign");
}

void Player::_onSwingArm(const std::shared_ptr<protocol::SwingArm> &pck)
{
    _log->debug("Got a Swing Arm");
}

void Player::_onTeleportToEntity(const std::shared_ptr<protocol::TeleportToEntity> &pck)
{
    _log->debug("Got a Teleport To Entity");
}

void Player::_onUseItemOn(const std::shared_ptr<protocol::UseItemOn> &pck)
{
    _log->debug("Got a Use Item On");
}

void Player::_onUseItem(const std::shared_ptr<protocol::UseItem> &pck)
{
    _log->debug("Got a Use Item");
}
