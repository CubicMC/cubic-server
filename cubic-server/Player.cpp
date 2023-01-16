#include "Player.hpp"
#include "Server.hpp"
#include "protocol/ClientPackets.hpp"
#include <cstdint>

Player::Player(
    Client *cli,
    std::shared_ptr<Dimension> dim,
    u128 uuid,
    const std::string &username)
    : _cli(cli), Entity(dim), _uuid(uuid), _username(username), _keepAliveId(0), _keepAliveIgnored(0)
{
    _log = logging::Logger::get_instance();
}

void Player::tick()
{
    // TODO: MOVE KEEP ALIVE HERE LOL
    bool updatePos = false;
    bool updateRot = false;

    if (_pos != _lastPos) {
        updatePos = true;
        _lastPos = _pos;
    }
    if (_rot != _lastRot) {
        updateRot = true;
        _lastRot = _rot;
    }
    if (updatePos && updateRot) {
        for (auto i : this->getDimension()->getPlayerList()) {
            if (i->getId() == this->getId())
                continue;
            i->sendUpdateEntityPositionAndRotation(protocol::createUpdateEntityPositionRotation({
                this->getId(),
                static_cast<int16_t>((this->_pos.x * 32.0 - this->_lastPos.x * 32) * 128),
                static_cast<int16_t>((this->_pos.y * 32.0 - this->_lastPos.y * 32) * 128),
                static_cast<int16_t>((this->_pos.z * 32.0 - this->_lastPos.z * 32) * 128),
                (uint8_t) (this->_rot.x),
                (uint8_t) (this->_rot.y),
                true
            }));
        }
    } else if (updatePos && !updateRot) {
        for (auto i : this->getDimension()->getPlayerList()) {
            if (i->getId() == this->getId())
                continue;
            i->sendUpdateEntityPosition(protocol::createUpdateEntityPosition({
                this->getId(),
                static_cast<int16_t>((this->_pos.x * 32.0 - this->_lastPos.x * 32) * 128),
                static_cast<int16_t>((this->_pos.y * 32.0 - this->_lastPos.y * 32) * 128),
                static_cast<int16_t>((this->_pos.z * 32.0 - this->_lastPos.z * 32) * 128),
                true
            }));
        }
    } else if (!updatePos && updateRot) {
        for (auto i : this->getDimension()->getPlayerList()) {
            if (i->getId() == this->getId())
                continue;
            i->sendUpdateEntityRotation(protocol::createUpdateEntityRotation({
                this->getId(),
                (uint8_t) (this->_rot.x),
                (uint8_t) (this->_rot.y),
                true
            }));
        }
    }
    static int tmp_mdr = 0;
    if (tmp_mdr++ >= 200) {
        sendSynchronizePosition();
        tmp_mdr = 180;
    }
}

Client *Player::getClient() const
{
    return _cli;
}

const std::string &Player::getUsername() const
{
    return _username;
}

const u128 &Player::getUuid() const
{
    return _uuid;
}

const int32_t Player::getGamemode() const
{
    return _gamemode;
}

void Player::disconnect(const chat::Message &reason)
{
    nlohmann::json json;

    // TODO: test this, cause I don't know if the translate key is the correct one
    json["translate"] = "chat.type.text";
    json["with"] = nlohmann::json::array({
        {"text", this->_username},
        {reason.toJson()}
    });

    auto pck = protocol::createPlayDisconnect({
        json.dump()
    });
    this->_cli->_sendData(*pck);
    this->_cli->_is_running = false;
    LDEBUG("Sent a disconnect play packet");
}

#pragma region ClientBound

long Player::keepAliveId() const
{
    return _keepAliveId;
}

void Player::setKeepAliveId(long id)
{
    _keepAliveId = id;
}

uint8_t Player::keepAliveIgnored() const
{
    return _keepAliveIgnored;
}

void Player::setKeepAliveIgnored(uint8_t ign)
{
    _keepAliveIgnored = ign;
}

void Player::playSoundEffect(SoundsList sound, protocol::FloatingPosition position, SoundCategory category)
{
    auto pck = protocol::createSoundEffect({
        (int32_t) sound,
        (int32_t) category,
        // https://wiki.vg/Data_types#Fixed-point_numbers
        static_cast<int32_t>(position.x * 32.0),
        static_cast<int32_t>(position.y * 32.0),
        static_cast<int32_t>(position.z * 32.0),
        0.5, // TODO: get the right volume
        1.0, // TODO: get the right pitch
        0 // TODO: get the right seed
    });
    this->_cli->_sendData(*pck);
    LDEBUG("Sent a sound effect packet");
}

void Player::playSoundEffect(SoundsList sound, const Entity *entity, SoundCategory category)
{
    auto pck = protocol::createEntitySoundEffect({
        (int32_t) sound,
        (int32_t) category,
        entity->getId(),
        0.5, // TODO: get the right volume
        1.0, // TODO: get the right pitch
        1 // TODO: get the right seed
    });
    this->_cli->_sendData(*pck);
    LDEBUG("Sent a sound effect packet");
}

void Player::playCustomSound(std::string sound, protocol::FloatingPosition position, SoundCategory category)
{
    auto pck = protocol::createCustomSoundEffect({
        sound,
        (int32_t) category,
        // https://wiki.vg/Data_types#Fixed-point_numbers
        static_cast<int32_t>(position.x * 32.0),
        static_cast<int32_t>(position.y * 32.0),
        static_cast<int32_t>(position.z * 32.0),
        0.5, // TODO: get the right volume
        1.0, // TODO: get the right pitch
        0 // TODO: get the right seed
    });
    this->_cli->_sendData(*pck);
    LDEBUG("Sent a custom sound effect packet");
}

void Player::stopSound(uint8_t flags, SoundCategory category, std::string sound)
{
    auto pck = protocol::createStopSound({
        flags,
        (int32_t) category,
        sound
    });
    this->_cli->_sendData(*pck);
    LDEBUG("Sent a stop sound packet");
}

void Player::sendKeepAlive(long id)
{
    auto pck = protocol::createKeepAlive(id);
    this->_cli->_sendData(*pck);
    LDEBUG("Sent a keep alive packet");
}

void Player::sendUpdateEntityPosition(std::shared_ptr<std::vector<uint8_t>> pck)
{
    this->_cli->_sendData(*pck);
    LDEBUG("Sent an entity position packet");
}

void Player::sendUpdateEntityPositionAndRotation(std::shared_ptr<std::vector<uint8_t>> pck)
{
    this->_cli->_sendData(*pck);
    LDEBUG("Sent an entity position and rotation packet");
}

void Player::sendUpdateEntityRotation(std::shared_ptr<std::vector<uint8_t>> pck)
{
    this->_cli->_sendData(*pck);
    LDEBUG("Sent an entity rotation packet");
}

void Player::sendSynchronizePosition()
{
    auto pck = protocol::createSynchronizePlayerPosition({
        0,
        0,
        0,
        0,
        0,
        0x08 | 0x10,
        0,
        true,
    });
    this->_cli->_sendData(*pck);
    LDEBUG("Synchronized player position");
}

#pragma endregion
#pragma region ServerBound

void Player::_onConfirmTeleportation(const std::shared_ptr<protocol::ConfirmTeleportation> &pck)
{
    LDEBUG("Got a Confirm Teleportation");
}

void Player::_onQueryBlockEntityTag(const std::shared_ptr<protocol::QueryBlockEntityTag> &pck)
{
    LDEBUG("Got a Query Block Entity Tag");
}

void Player::_onChangeDifficulty(const std::shared_ptr<protocol::ChangeDifficulty> &pck)
{
    LDEBUG("Got a Change difficulty");
}

// Receive a chat message from the client, transmit it to the chat system.
void Player::_onChatMessage(const std::shared_ptr<protocol::ChatMessage> &pck)
{
    // TODO: verify that the message is valid (signature, etc.)
    _dim->getWorld()->getChat()->sendPlayerMessage(pck->message, this);
    _log->debug("Got a Chat Message");
}

void Player::_onClientCommand(const std::shared_ptr<protocol::ClientCommand> &pck)
{
    LDEBUG("Got a Client Command");
}

void Player::_onClientInformation(const std::shared_ptr<protocol::ClientInformation> &pck)
{
    LDEBUG("Got a Client Information");
}

void Player::_onCommandSuggestionRequest(const std::shared_ptr<protocol::CommandSuggestionRequest> &pck)
{
    LDEBUG("Got a Command Suggestion Request");
}

void Player::_onClickContainerButton(const std::shared_ptr<protocol::ClickContainerButton> &pck)
{
    LDEBUG("Got a Click Container Button");
}

void Player::_onCloseContainerRequest(const std::shared_ptr<protocol::CloseContainerRequest> &pck)
{
    LDEBUG("Got a Close Container Request");
}

void Player::_onPluginMessage(const std::shared_ptr<protocol::PluginMessage> &pck)
{
    LDEBUG("Got a Plugin Message");
    if (pck->channel == "minecraft:brand") {
        LDEBUG("Got a branding request");
        auto pck = protocol::createPluginMessageResponse({
            "minecraft:brand",
            std::vector<uint8_t>({0x05, 0x43, 0x75, 0x62, 0x69, 0x63}) // 43 75 62 69 63 | "Cubic" in hex
        });
        _cli->_sendData(*pck);
        return;
    }
}

void Player::_onEditBook(const std::shared_ptr<protocol::EditBook> &pck)
{
    LDEBUG("Got a Edit Book");
}

void Player::_onQueryEntityTag(const std::shared_ptr<protocol::QueryEntityTag> &pck)
{
    LDEBUG("Got a Query Entity Tag");
}

void Player::_onInteract(const std::shared_ptr<protocol::Interact> &pck)
{
    LDEBUG("Got a Interact");
}

void Player::_onJigsawGenerate(const std::shared_ptr<protocol::JigsawGenerate> &pck)
{
    LDEBUG("Got a Jigsaw Generate");
}

void Player::_onKeepAliveResponse(const std::shared_ptr<protocol::KeepAliveResponse> &pck)
{
    if (pck->keep_alive_id != _keepAliveId) {
        LERROR("Got a Keep Alive Response with a wrong ID: " + std::to_string(pck->keep_alive_id) + " (expected " + std::to_string(_keepAliveId) + ")");
        this->disconnect("Wrong Keep Alive ID");
        return;
    }

    _keepAliveId = 0;
    LDEBUG("Got a Keep Alive Response");
}

void Player::_onLockDifficulty(const std::shared_ptr<protocol::LockDifficulty> &pck)
{
    LDEBUG("Got a Lock Difficulty");
}

void Player::_onSetPlayerPosition(const std::shared_ptr<protocol::SetPlayerPosition> &pck)
{
    //LDEBUG("Got a Set Player Position: " + std::to_string(pck->x) + ", " + std::to_string(pck->feet_y) + ", " + std::to_string(pck->z));
    this->setPosition(pck->x, pck->feet_y, pck->z);
}

void Player::_onSetPlayerPositionAndRotation(const std::shared_ptr<protocol::SetPlayerPositionAndRotation> &pck)
{
    LDEBUG("Got a Set Player Position And Rotation: x= " + std::to_string(pck->x) + "\ty= " + std::to_string(pck->feet_y) + "\tz= " + std::to_string(pck->z) + "\tyaw= " + std::to_string(pck->yaw) + "\tpitch= " + std::to_string(pck->pitch));
    this->setPosition(pck->x, pck->feet_y, pck->z);
    float yaw_tmp = pck->yaw;
    while (yaw_tmp < 0)
        yaw_tmp += 360;
    while (yaw_tmp > 360)
        yaw_tmp -= 360;
    this->setRotation(yaw_tmp, pck->pitch);
}

void Player::_onSetPlayerRotation(const std::shared_ptr<protocol::SetPlayerRotation> &pck)
{
    LDEBUG("Got a Set Player Rotation");
    this->setRotation(pck->yaw, pck->pitch);
}

void Player::_onSetPlayerOnGround(const std::shared_ptr<protocol::SetPlayerOnGround> &pck)
{
    LDEBUG("Got a Set Player On Ground");
}

void Player::_onMoveVehicle(const std::shared_ptr<protocol::MoveVehicle> &pck)
{
    LDEBUG("Got a Move Vehicle");
}

void Player::_onPaddleBoat(const std::shared_ptr<protocol::PaddleBoat> &pck)
{
    LDEBUG("Got a Paddle Boat");
}

void Player::_onPickItem(const std::shared_ptr<protocol::PickItem> &pck)
{
    LDEBUG("Got a Pick Item");
}

void Player::_onPlaceRecipe(const std::shared_ptr<protocol::PlaceRecipe> &pck)
{
    LDEBUG("Got a Place Recipe");
}

void Player::_onPlayerAbilities(const std::shared_ptr<protocol::PlayerAbilities> &pck)
{
    LDEBUG("Got a Player Abilities");
}

void Player::_onPlayerAction(const std::shared_ptr<protocol::PlayerAction> &pck)
{
    LDEBUG("Got a Player Action");
}

void Player::_onPlayerCommand(const std::shared_ptr<protocol::PlayerCommand> &pck)
{
    LDEBUG("Got a Player Command");
}

void Player::_onPlayerInput(const std::shared_ptr<protocol::PlayerInput> &pck)
{
    LDEBUG("Got a Player Input");
}

void Player::_onPong(const std::shared_ptr<protocol::Pong> &pck)
{
    LDEBUG("Got a Pong");
}

void Player::_onChangeRecipeBookSettings(const std::shared_ptr<protocol::ChangeRecipeBookSettings> &pck)
{
    LDEBUG("Got a Change Recipe Book Settings");
}

void Player::_onSetSeenRecipe(const std::shared_ptr<protocol::SetSeenRecipe> &pck)
{
    LDEBUG("Got a Set Seen Recipe");
}

void Player::_onRenameItem(const std::shared_ptr<protocol::RenameItem> &pck)
{
    LDEBUG("Got a Rename Item");
}

void Player::_onResourcePack(const std::shared_ptr<protocol::ResourcePack> &pck)
{
    LDEBUG("Got a Resource Pack");
}

void Player::_onSeenAdvancements(const std::shared_ptr<protocol::SeenAdvancements> &pck)
{
    LDEBUG("Got a Seen Advancements");
}

void Player::_onSelectTrade(const std::shared_ptr<protocol::SelectTrade> &pck)
{
    LDEBUG("Got a Select Trade");
}

void Player::_onSetBeaconEffect(const std::shared_ptr<protocol::SetBeaconEffect> &pck)
{
    LDEBUG("Got a Set Beacon Effect");
}

void Player::_onSetHeldItem(const std::shared_ptr<protocol::SetHeldItem> &pck)
{
    LDEBUG("Got a Set Held Item");
}

void Player::_onProgramCommandBlock(const std::shared_ptr<protocol::ProgramCommandBlock> &pck)
{
    LDEBUG("Got a Program Command Block");
}

void Player::_onProgramCommandBlockMinecart(const std::shared_ptr<protocol::ProgramCommandBlockMinecart> &pck)
{
    LDEBUG("Got a Program Command Block Minecart");
}

void Player::_onProgramJigsawBlock(const std::shared_ptr<protocol::ProgramJigsawBlock> &pck)
{
    LDEBUG("Got a Program Jigsaw Block");
}

void Player::_onProgramStructureBlock(const std::shared_ptr<protocol::ProgramStructureBlock> &pck)
{
    LDEBUG("Got a Program Structure Block");
}

void Player::_onUpdateSign(const std::shared_ptr<protocol::UpdateSign> &pck)
{
    LDEBUG("Got a Update Sign");
}

void Player::sendSwingArm(bool main_hand, int32_t swinger_id)
{
    auto pck = protocol::createEntityAnimationClient(
        main_hand ? protocol::EntityAnimationID::SwingMainArm : protocol::EntityAnimationID::SwingOffHand,
        swinger_id
    );
    _cli->_sendData(*pck);
}

void Player::_onSwingArm(const std::shared_ptr<protocol::SwingArm> &pck)
{
    LDEBUG("Got a Swing Arm");
    for (auto i : this->getDimension()->getPlayerList()) {
        if (i->getId() == this->getId())
            continue;
        i->sendSwingArm(pck->hand == 0, this->getId());
    }
}

void Player::_onTeleportToEntity(const std::shared_ptr<protocol::TeleportToEntity> &pck)
{
    LDEBUG("Got a Teleport To Entity");
}

void Player::_onUseItemOn(const std::shared_ptr<protocol::UseItemOn> &pck)
{
    LDEBUG("Got a Use Item On");
}

void Player::_onUseItem(const std::shared_ptr<protocol::UseItem> &pck)
{
    LDEBUG("Got a Use Item");
}

#pragma endregion Serverbound
