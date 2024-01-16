#ifndef CUBICSERVER_PLAYER_HPP
#define CUBICSERVER_PLAYER_HPP

#include "Chat.hpp"
#include "PlayerAttributes.hpp"
#include "SoundList.hpp"
#include "TickClock.hpp"
#include "chat/Message.hpp"
#include "concept.hpp"
#include "entities/Entity.hpp"
#include "entities/LivingEntity.hpp"
#include "math/Vector3.hpp"
#include "protocol/ClientPackets.hpp"
#include "protocol/ServerPackets.hpp"
#include "protocol/common.hpp"
#include "protocol/container/Container.hpp"
#include "protocol/container/Inventory.hpp"
#include "types.hpp"
#include "world_storage/ChunkColumn.hpp"
#include <compare>
#include <cstdint>
#include <memory>
#include <sys/types.h>
#include <type_traits>

class Client;

class Player : public LivingEntity {
    friend class Client;

public:
    enum ChunkState {
        Unloaded,
        Loading,
        Loaded
    };

public:
    Player(std::weak_ptr<Client> cli, std::shared_ptr<Dimension> dim, u128 uuid, const std::string &username);
    ~Player() override;

    void tick() override;

    std::weak_ptr<Client> getClient() const;
    const std::string &getUsername() const;
    uint8_t getHeldItem() const;
    player_attributes::Gamemode getGamemode() const;
    const protocol::ClientInformation::ChatVisibility &getChatVisibility() const;
    long keepAliveId() const;
    uint8_t keepAliveIgnored() const;
    bool isOperator() const;
    NODISCARD const std::vector<protocol::PlayerProperty> &getProperties() const;
    std::shared_ptr<protocol::container::Inventory> getInventory() { return _inventory; };
    std::shared_ptr<const protocol::container::Inventory> getInventory() const { return _inventory; };

public:
    void setPosition(const Vector3<double> &pos, bool onGround) override;
    void setPosition(double x, double y, double z, bool onGround) override;
    void setGamemode(player_attributes::Gamemode gm);
    void teleport(const Vector3<double> &pos) override;
    void setKeepAliveIgnored(uint8_t ign);
    void setOperator(const bool isOp);
    void setKeepAliveId(long id);
    void updatePlayerInfo(const protocol::PlayerInfoUpdate &data);
    void playerPickupItem();
    void updateEquipment(bool mainHand, UNUSED bool offHand, UNUSED bool boots, UNUSED bool leggings, UNUSED bool chestplate, UNUSED bool helmet);

    template<isBaseOf<protocol::container::Container> Container, typename... Args>
    std::shared_ptr<Container> openContainer(Args &...);
    void closeContainer(uint8_t id);

    /**
     * @brief Sends the metadata of the given entity
     *
     * @param entity The entity to send the metadata of
     */
    void sendEntityMetadata(const Entity &entity);

    /**
     * @brief Checks if a given position is in the render distance
     *
     * @todo Returns only true, needs to be implemented
     * @param pos The position to check if in render distance
     * @return true The position is in the render distance
     * @return false The position is not in the render distance
     */
    bool isInRenderDistance(const Vector2<double> &pos) const;

    /**
     * @brief Adds serialized metadata to an output buffer
     *
     * @param data The output buffer
     */
    void appendMetadataPacket(std::vector<uint8_t> &data) const override;

    /**
     * @brief Get the Window Id of the next screen / window / inventory
     *
     * @return uint8_t The window id
     */
    uint8_t getWindowId() { return ++_windowId; }

    /**
     * @brief Get a container by its window id
     *
     * @param windowId The window id of the container
     */
    std::shared_ptr<protocol::container::Container> getContainer(uint8_t windowId);

public:
    /**
     * @brief Synchronize the player with the server
     */
    void synchronize();
    void disconnect(const chat::Message &reason = "Disconnected");
    void sendLoginPlay(const protocol::LoginPlay &packet);
    void sendPlayerInfoUpdate(const protocol::PlayerInfoUpdate &data);
    void sendPlayerInfoRemove(const protocol::PlayerInfoRemove &data);
    void sendSpawnEntity(const protocol::SpawnEntity &data);
    void sendSpawnEntity(const Entity &data);
    void sendSpawnPlayer(const protocol::SpawnPlayer &data);
    void sendEntityVelocity(const protocol::EntityVelocity &data);
    void sendSetEquipment(const protocol::SetEquipment &data);
    void sendHealth(void);
    void sendUpdateTime(const protocol::UpdateTime &data);
    void sendChatMessageResponse(const protocol::PlayerChatMessage &packet);
    void sendSystemChatMessage(const protocol::SystemChatMessage &packet);
    void sendWorldEvent(const protocol::WorldEvent &packet);
    void playSoundEffect(SoundsList sound, FloatingPosition position, SoundCategory category = SoundCategory::Master);
    void playSoundEffect(const protocol::SoundEffect &packet);
    void playSoundEffect(SoundsList sound, const Entity &entity, SoundCategory category = SoundCategory::Master);
    void playSoundEffect(const protocol::EntitySoundEffect &packet);
    void stopSound(uint8_t flags = 0, SoundCategory category = SoundCategory::Ambient, std::string sound = "");
    void sendKeepAlive(long id);
    void sendSynchronizePosition(const Vector3<double> &pos);
    void sendSynchronizePlayerPosition(const protocol::SynchronizePlayerPosition &data);
    void sendSynchronizePlayerPosition(void);
    void sendSwingArm(bool mainHand, int32_t swingerId);
    void sendTeleportEntity(int32_t id, const Vector3<double> &pos, const Vector2<uint8_t> &rot);
    void sendRemoveEntities(const std::vector<int32_t> &entities);
    void sendRespawn(const protocol::Respawn &data);
    void sendUpdateEntityPosition(const protocol::UpdateEntityPosition &data);
    void sendUpdateEntityPositionAndRotation(const protocol::UpdateEntityPositionRotation &data);
    void sendUpdateEntityRotation(const protocol::UpdateEntityRotation &data);
    void sendHeadRotation(const protocol::HeadRotation &data);
    void sendUpdateSectionBlock(const protocol::UpdateSectionBlock &data);
    void sendSetCenterChunk(const Position2D &pos);
    void sendChunkAndLightUpdate(const Position2D &pos);
    void sendChunkAndLightUpdate(int32_t x, int32_t z);
    void sendChunkAndLightUpdate(const world_storage::ChunkColumn &chunk);
    void sendUnloadChunk(int32_t x, int32_t z);
    void sendBlockUpdate(const protocol::BlockUpdate &packet);
    void sendBlockEntityData(const protocol::BlockEntityData &packet);
    void sendOpenScreen(const protocol::OpenScreen &packet);
    void sendPlayerAbilities(const protocol::PlayerAbilitiesClient &packet);
    void sendFeatureFlags(const protocol::FeatureFlags &packet);
    void sendServerData(const protocol::ServerData &packet);
    void sendGameEvent(const protocol::GameEvent &packet);
    void sendEntityAnimation(protocol::EntityAnimation::ID animId, int32_t entityID);
    void sendCloseContainer(uint8_t containerId);
    void sendSetContainerContent(const protocol::SetContainerContent &packet);
    void sendSetContainerProperty(const protocol::SetContainerProperty &packet);
    void sendSetContainerSlot(const protocol::SetContainerSlot &packet);
    void sendUpdateRecipes(const protocol::UpdateRecipes &packet);
    void sendUpdateTags(const protocol::UpdateTags &packet);
    void sendCommands(const protocol::Commands &packet);
    void sendChangeDifficulty(const protocol::ChangeDifficultyClient &packet);
    void sendSetHeldItem(const protocol::SetHeldItemClient &packet);
    void sendEntityEvent(const protocol::EntityEvent &packet);
    void sendUpdateRecipiesBook(const protocol::UpdateRecipesBook &packet);
    void sendInitializeWorldBorder(const protocol::InitializeWorldBorder &packet);
    void sendSetDefaultSpawnPosition(const protocol::SetDefaultSpawnPosition &packet);
    void sendUpdateAttributes(const protocol::UpdateAttributes &packet);
    void sendUpdateAdvancements(const protocol::UpdateAdvancements &packet);
    void sendSetExperience(const protocol::SetExperience &packet);
    void sendUpdateObjective(const protocol::UpdateObjectives &packet);
    void sendDisplayObjective(const protocol::DisplayObjective &packet);
    void sendUpdateScore(const protocol::UpdateScore &packet);
    void sendUpdateTeams(const protocol::UpdateTeams &packet);
    void sendPickupItem(const protocol::PickupItem &packet);
    void sendSubtitleText(const protocol::SetSubtitleText &data);
    void sendTitleText(const protocol::SetTitleText &data);
    void sendTitleAnimationTimes(const protocol::SetTitleAnimationTimes &data);

private:
    void _onConfirmTeleportation(protocol::ConfirmTeleportation &pck);
    void _onQueryBlockEntityTag(protocol::QueryBlockEntityTag &pck);
    void _onChangeDifficulty(protocol::ChangeDifficulty &pck);
    void _onChatMessage(protocol::ChatMessage &pck);
    void _onMessageAcknowledgement(protocol::MessageAcknowledgement &pck);
    void _onChatCommand(protocol::ChatCommand &pck);
    void _onClientCommand(protocol::ClientCommand &pck);
    void _onClientInformation(protocol::ClientInformation &pck);
    void _onCommandSuggestionRequest(protocol::CommandSuggestionRequest &pck);
    void _onClickContainerButton(protocol::ClickContainerButton &pck);
    void _onClickContainer(protocol::ClickContainer &pck);
    void _onCloseContainerRequest(protocol::CloseContainerRequest &pck);
    void _onPluginMessage(protocol::PluginMessage &pck);
    void _onEditBook(protocol::EditBook &pck);
    void _onQueryEntityTag(protocol::QueryEntityTag &pck);
    void _onInteract(protocol::Interact &pck);
    void _onJigsawGenerate(protocol::JigsawGenerate &pck);
    void _onKeepAliveResponse(protocol::KeepAliveResponse &pck);
    void _onLockDifficulty(protocol::LockDifficulty &pck);
    void _onSetPlayerPosition(protocol::SetPlayerPosition &pck);
    void _onSetPlayerPositionAndRotation(protocol::SetPlayerPositionAndRotation &pck);
    void _onSetPlayerRotation(protocol::SetPlayerRotation &pck);
    void _onSetPlayerOnGround(protocol::SetPlayerOnGround &pck);
    void _onMoveVehicle(protocol::MoveVehicle &pck);
    void _onPaddleBoat(protocol::PaddleBoat &pck);
    void _onPickItem(protocol::PickItem &pck);
    void _onPlaceRecipe(protocol::PlaceRecipe &pck);
    void _onPlayerAbilities(protocol::PlayerAbilities &pck);
    void _onPlayerAction(protocol::PlayerAction &pck);
    void _onPlayerCommand(protocol::PlayerCommand &pck);
    void _onPlayerInput(protocol::PlayerInput &pck);
    void _onPong(protocol::Pong &pck);
    void _onPlayerSession(protocol::PlayerSession &pck);
    void _onChangeRecipeBookSettings(protocol::ChangeRecipeBookSettings &pck);
    void _onSetSeenRecipe(protocol::SetSeenRecipe &pck);
    void _onRenameItem(protocol::RenameItem &pck);
    void _onResourcePack(protocol::ResourcePack &pck);
    void _onSeenAdvancements(protocol::SeenAdvancements &pck);
    void _onSelectTrade(protocol::SelectTrade &pck);
    void _onSetBeaconEffect(protocol::SetBeaconEffect &pck);
    void _onSetHeldItem(protocol::SetHeldItem &pck);
    void _onProgramCommandBlock(protocol::ProgramCommandBlock &pck);
    void _onProgramCommandBlockMinecart(protocol::ProgramCommandBlockMinecart &pck);
    void _onSetCreativeModeSlot(protocol::SetCreativeModeSlot &pck);
    void _onProgramJigsawBlock(protocol::ProgramJigsawBlock &pck);
    void _onProgramStructureBlock(protocol::ProgramStructureBlock &pck);
    void _onUpdateSign(protocol::UpdateSign &pck);
    void _onSwingArm(protocol::SwingArm &pck);
    void _onTeleportToEntity(protocol::TeleportToEntity &pck);
    void _onUseItemOn(protocol::UseItemOn &pck);
    void _onUseItem(protocol::UseItem &pck);

private:
    void _processKeepAlive();
    void _updateRenderedChunks(const Position2D &oldChunkPos, const Position2D &newChunkPos);
    void _continueLoginSequence();
    void _unloadChunk(int32_t x, int32_t z);
    void _foodTick();
    void _eat();
    void _respawn();
    void _shoot();

    std::weak_ptr<Client> _cli;
    std::string _username;
    long _keepAliveId;
    uint8_t _keepAliveIgnored;
    int8_t _heldItem;
    player_attributes::Gamemode _gamemode;
    TickClock _keepAliveClock;
    TickClock _synchronizeClock;
    std::unordered_map<Position2D, ChunkState> _chunks;
    mutable std::mutex _chunksMutex;

    // Inventory
    std::shared_ptr<protocol::container::Inventory> _inventory;
    std::vector<std::shared_ptr<protocol::container::Container>> _containers;

    // Food Mechanics
    int _foodLevel;
    float _foodSaturationLevel;
    int _foodTickTimer;
    float _foodExhaustionLevel;
    FloatingPosition _respawnPoint;

    // player status
    protocol::ClientInformation::ChatVisibility _chatVisibility;
    bool _isFlying;
    bool _isOperator;
    bool _isJumping;

    // metadata
    float _additionalHearts;
    int32_t _score;
    struct {
        bool capeEnabled;
        bool jacketEnabled;
        bool leftSleeveEnabled;
        bool rightSleeveEnabled;
        bool leftPantsEnabled;
        bool rightPantsEnabled;
        bool hatEnabled;
    } _skinParts;
    enum class MainHand : uint8_t {
        Left = 0,
        Right = 1,
    } _mainHand;
    int _nbTickBeforeNextAttack;
    uint8_t _windowId;
};

template<isBaseOf<protocol::container::Container> Container, typename... Args>
std::shared_ptr<Container> Player::openContainer(Args &...args)
{
    return _containers.emplace_back(std::make_shared<Container>(std::forward<Args>(args)...));
}

#endif // CUBICSERVER_PLAYER_HPP
