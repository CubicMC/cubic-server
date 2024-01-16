#include "ClientPackets.hpp"

#include "PacketUtils.hpp"
#include "entities/Entity.hpp"
#include "logging/logging.hpp"
#include "protocol/serialization/addPrimaryType.hpp"
#include "serialization/add.hpp"
#include "world_storage/ChunkColumn.hpp"
#include "world_storage/Section.hpp"
#include <memory>
#include <vector>

using namespace protocol;

std::unique_ptr<std::vector<uint8_t>> protocol::createLoginDisconnect(const Disconnect &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.reason, addString
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::DisconnectLogin);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createEncryptionRequest(const EncryptionRequest &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.serverID, addString,
        in.publicKey, addArray<uint8_t, addByte>,
        in.verifyToken, addArray<uint8_t, addByte>
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::EncryptionRequest);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createLoginSuccess(const LoginSuccess &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.uuid, addUUID,
        in.username, addString,
        in.properties.size(), addVarInt
    );

    // in.name, addString,
    // in.value, addString,
    // in.isSigned, addBoolean
    for (auto &property : in.properties) {
        serialize(payload,
            property.name, addString,
            property.value, addString,
            property.isSigned, addBoolean
        );
        if (property.isSigned) {
            serialize(payload,
                property.signature, addString
            );
        }
    }
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::LoginSuccess);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createSetCompression(int32_t compressionTreshold)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        compressionTreshold, addVarInt
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::SetCompression);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createStatusResponse(const StatusResponse &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.payload, addString
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::Status);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createPingResponse(const PingResponse &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.payload, addLong
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::Ping);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createSpawnEntity(const SpawnEntity &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.entityId, addVarInt,
        in.entityUuid, addUUID,
        in.type, addVarInt,
        in.x, addDouble,
        in.y, addDouble,
        in.z, addDouble,
        in.pitch, addByte,
        in.yaw, addByte,
        in.headYaw, addByte,
        in.data, addVarInt,
        in.velocityX, addShort,
        in.velocityY, addShort,
        in.velocityZ, addShort
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::SpawnEntity);

    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createSpawnPlayer(const SpawnPlayer &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.entityId, addVarInt,
        in.playerUuid, addUUID,
        in.x, addDouble,
        in.y, addDouble,
        in.z, addDouble,
        in.yaw, addByte,
        in.pitch, addByte
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::SpawnPlayer);

    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createEntityAnimation(EntityAnimation::ID animId, int32_t entityID)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        entityID, addVarInt,
        animId, addByte
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::EntityAnimation);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createBlockEntityData(const BlockEntityData &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.location, addPosition,
        in.type, addVarInt
    );
    addNBT((std::vector<uint8_t> &)payload, (nbt_tag_t *)in.nbtData);
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::BlockEntityData);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createBlockUpdate(const BlockUpdate &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.location, addPosition,
        in.blockId, addVarInt
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::BlockUpdate);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createChangeDifficultyClient(const ChangeDifficultyClient &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.difficulty, addByte,
        in.locked, addBoolean
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::ChangeDifficulty);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createCommands(const Commands &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.nodes, addArray<int, addVarInt>,
        in.rootIndex, addVarInt
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::Commands);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createCloseContainer(const CloseContainer &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.windowId, addByte
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::CloseContainer);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createSetContainerContent(const SetContainerContent &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.container->id(), addByte,
        in.container->state(), addVarInt,
        *in.container, addContainer,
        in.container->cariedItem(), addSlot
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::SetContainerContent);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createSetContainerProperty(const SetContainerProperty &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.windowId, addByte,
        in.property, addShort,
        in.value, addShort
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::SetContainerProperty);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createSetContainerSlot(const SetContainerSlot &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.containerId, addByte,
        in.container->state(), addVarInt,
        in.slot, addShort,
        in.container->at(in.slot), addSlot
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::SetContainerSlot);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createPluginMessageResponse(const PluginMessageResponse &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.channel, addIdentifier
    );
    // clang-format on
    // TODO: Just look at it
    for (auto i : in.data)
        payload.push_back(i);

    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::PluginMessage);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createPlayDisconnect(const Disconnect &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.reason, addString
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::DisconnectPlay);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createEntityEvent(const EntityEvent &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.entityId, addInt, // cringe
        in.eventStatus, addByte
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::EntityEvent);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createUnloadChunk(const Position2D &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.x, addInt,
        in.z, addInt
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::UnloadChunk);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createInitializeWorldBorder(const InitializeWorldBorder &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.x, addDouble,
        in.z, addDouble,
        in.oldDiameter, addDouble,
        in.newDiameter, addDouble,
        in.speed, addVarLong,
        in.portalTeleportBoundary, addVarInt,
        in.warningTime, addVarInt,
        in.warningBlocks, addVarInt
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::InitializeWorldBorder);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createGameEvent(const GameEvent &in)
{
    std::vector<uint8_t> payload;
    serialize(payload, (uint8_t) in.event, addByte, in.value, addFloat);
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::GameEvent);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createKeepAlive(long id)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        id, addLong
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::KeepAlive);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createChunkDataAndLightUpdate(const ChunkDataAndLightUpdate &in)
{
    std::vector<uint8_t> payload;

    // clang-format off
    serialize(payload,
        in.chunkX, addInt,
        in.chunkZ, addInt,
        // Obligated to do that here because addChunkColumn is constexpr
        // in.data.getHeightMap(), addNBT<nbt::Compound>,

        in.data, addChunkColumn
        // in.blockEntities, addBlockEntities,
        // in.trustEdges, addBoolean,
        // in.skyLightMask, addArray<int64_t, addLong>,
        // in.blockLightMask, addArray<int64_t, addLong>,
        // in.emptySkyLightMask, addArray<int64_t, addLong>,
        // in.emptyBlockLightMask, addArray<int64_t, addLong>,
        // in.skyLight, addLightArray,
        // in.blockLight, addLightArray
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::ChunkDataAndLightUpdate);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createWorldEvent(const WorldEvent &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.event, addInt,
        in.position, addPosition,
        in.data, addInt,
        in.disableRelativeVolume, addBoolean
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::WorldEvent);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createLoginPlay(const LoginPlay &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.entityID, addInt,
        in.isHardcore, addBoolean,
        in.gamemode, addByte,
        in.previousGamemode, addByte,
        in.dimensionNames, addArray<std::string, addString>,
        *in.registryCodec, addNBT<nbt::Compound>,
        in.dimensionType, addString,
        in.dimensionName, addString,
        in.hashedSeed, addLong,
        in.maxPlayers, addVarInt,
        in.viewDistance, addVarInt,
        in.simulationDistance, addVarInt,
        in.reducedDebugInfo, addBoolean,
        in.enableRespawnScreen, addBoolean,
        in.isDebug, addBoolean,
        in.isFlat, addBoolean,
        in.hasDeathLocation, addBoolean
    );
    if (in.hasDeathLocation) {
        serialize(payload,
            in.deathDimensionName, addString,
            in.deathLocation, addPosition
        );
    }
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::LoginPlay);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createUpdateEntityPosition(const UpdateEntityPosition &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.entityId, addVarInt,
        in.deltaX, addShort,
        in.deltaY, addShort,
        in.deltaZ, addShort,
        in.onGround, addBoolean
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::UpdateEntityPosition);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createUpdateEntityPositionRotation(const UpdateEntityPositionRotation &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.entityId, addVarInt,
        in.deltaX, addShort,
        in.deltaY, addShort,
        in.deltaZ, addShort,
        in.yaw, addByte,
        in.pitch, addByte,
        in.onGround, addBoolean
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::UpdateEntityPositionRotation);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createUpdateEntityRotation(const UpdateEntityRotation &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.entityId, addVarInt,
        in.yaw, addByte,
        in.pitch, addByte,
        in.onGround, addBoolean
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::UpdateEntityRotation);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createOpenScreen(const OpenScreen &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.id, addVarInt,
        in.type, addVarInt,
        in.title.serialize(), addChat
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::OpenScreen);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createPlayerAbilities(const PlayerAbilitiesClient &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.flags, addByte,
        in.flyingSpeed, addFloat,
        in.fieldOfViewModifier, addFloat
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::PlayerAbilities);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createPlayerChatMessage(const PlayerChatMessage &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.senderUUID, addUUID,
        in.index, addVarInt,
        in.hasSignature, addBoolean
    );
    if (in.hasSignature) {
        serialize(payload,
            in.signature, addArray<uint8_t, addByte>
        );
    }
    serialize(payload,
        in.message, addChat,
        in.timestamp, addLong,
        in.salt, addLong,
        in.previousMessages, addArray<std::pair<int32_t, std::vector<uint8_t>>, addRawMessage>,
        in.hasUnsignedContent, addBoolean
    );
    if (in.hasUnsignedContent) {
        serialize(payload,
            in.unsignedContent, addChat
        );
    }
    serialize(payload,
        in.filterType, addVarInt
    );
    // TODO: Chat filter
    // if ()
    //     serialize(payload, in.filterData, addArray<int64_t, addLong>);
    serialize(payload,
        in.chatType, addVarInt,
        in.networkName, addChat,
        in.hasNetworkTargetName, addBoolean
    );
    if (in.hasNetworkTargetName) {
        serialize(payload,
            in.networkTargetName, addChat
        );
    }
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::PlayerChatMessage);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createPlayerInfoRemove(const PlayerInfoRemove &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.uuids, addArray<u128, addUUID>
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::PlayerInfoRemove);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createPlayerInfoUpdate(const PlayerInfoUpdate &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.actions, addByte,
        in.actionSets.size(), addVarInt
    );
    for (auto &actionSet : in.actionSets) {
        serialize(payload,
            actionSet.uuid, addUUID
        );

        if (in.actions & (uint8_t) PlayerInfoUpdate::Actions::AddPlayer) { // Add Player
            serialize(payload,
                actionSet.addPlayer.name, addString,
                0, addVarInt // Number of properties -> To change to handle skins and stuff
            );
        }
        if (in.actions & (uint8_t) PlayerInfoUpdate::Actions::InitializeChat) { // Initialize chat
            serialize(payload,
                actionSet.initializeChat.hasSigData, addBoolean
            );
            // TODO(miki or huntears): Chat signature data
        }
        if (in.actions & (uint8_t) PlayerInfoUpdate::Actions::UpdateGamemode) { // Update gamemode
            serialize(payload,
                actionSet.updateGamemode.gamemode, addVarInt
            );
        }
        if (in.actions & (uint8_t) PlayerInfoUpdate::Actions::UpdateListed) { // Update listed
            serialize(payload,
                actionSet.updateListed.listed, addBoolean
            );
        }
        if (in.actions & (uint8_t) PlayerInfoUpdate::Actions::UpdateLatency) { // Update latency
            serialize(payload,
                actionSet.updateLatency.latency, addVarInt
            );
        }
        if (in.actions & (uint8_t) PlayerInfoUpdate::Actions::UpdateDisplayName) { // Update display name
            serialize(payload,
                actionSet.updateDisplayName.hasDisplayName, addBoolean
            );
            // TODO: Add a proper display name
        }
    }
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::PlayerInfoUpdate);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createSynchronizePlayerPosition(const SynchronizePlayerPosition &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.x, addDouble,
        in.y, addDouble,
        in.z, addDouble,
        in.yaw, addFloat,
        in.pitch, addFloat,
        in.flags, addByte,
        in.teleportId, addVarInt,
        in.dismountVehicle, addBoolean
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::SynchronizePlayerPosition);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createUpdateRecipesBook(const UpdateRecipesBook &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.action, addVarInt,
        in.craftingRecipeBookOpen, addBoolean,
        in.craftingRecipeBookFilterActive, addBoolean,
        in.smeltingRecipeBookOpen, addBoolean,
        in.smeltingRecipeBookFilterActive, addBoolean,
        in.blastFurnaceRecipeBookOpen, addBoolean,
        in.blastFurnaceRecipeBookFilterActive, addBoolean,
        in.smokerRecipeBookOpen, addBoolean,
        in.smokerRecipeBookFilterActive, addBoolean,
        in.recipesId, addArray<std::string, addIdentifier>
    );
    if (in.action == 0) {
        serialize(payload,
            in.recipiesIdForInit, addArray<std::string, addIdentifier>
        );
    }
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::UpdateRecipesBook);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createRemoveEntities(const RemoveEntities &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.entities, addArray<int32_t, addVarInt>
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::RemoveEntities);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createRespawn(const Respawn &in)
{
    std::vector<uint8_t> payload;

    // clang-format off
    serialize(payload,
        in.dimensionType, addIdentifier,
        in.dimensionName, addIdentifier,
        in.hashedSeed, addLong,
        in.gamemode, addByte,
        in.previousGamemode, addByte,
        in.isDebug, addBoolean,
        in.isFlat, addBoolean,
        in.copyMetadata, addBoolean,
        in.hasDeathLocation, addBoolean
    );
    // clang-format on
    if (in.hasDeathLocation) {
        // clang-format off
        serialize(payload,
            in.deathDimensionName, addIdentifier,
            in.deathLocation, addPosition
        );
        // clang-format on
    }
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::Respawn);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createHeadRotation(const HeadRotation &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.entityID, addVarInt,
        in.headYaw, addByte
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::HeadRotation);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createUpdateSectionBlock(const UpdateSectionBlock &in)
{
    std::vector<uint8_t> payload;
    int sectionY = world_storage::getSectionIndex(in.pos);
    long chunkSectionPosition = ((in.chunkData.getChunkPos().x & 0x3FFFFF) << 42) | (sectionY & 0xFFFFF) | ((in.chunkData.getChunkPos().z & 0x3FFFFF) << 20);
    std::vector<long> blocks;
    for (auto [block, id] : in.blocks) {
        blocks.push_back(id << 12 | (block.x << 8 | block.z << 4 | block.y));
    }
    // clang-format off
    serialize(payload,
        chunkSectionPosition, addLong,
        in.suppressLightUpdates, addBoolean,
        blocks, addArray<long, addVarLong>
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::UpdateSectionBlocks);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createServerData(const ServerData &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.hasMotd, addBoolean,
        in.hasIcon, addBoolean,
        in.enforceSecureChat, addBoolean
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::ServerData);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createSetHeldItemClient(const SetHeldItemClient &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.slot, addByte
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::SetHeldItem);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createCenterChunk(const Position2D &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.x, addVarInt,
        in.z, addVarInt
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::CenterChunk);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createSetDefaultSpawnPosition(const SetDefaultSpawnPosition &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.position, addPosition,
        in.angle, addFloat
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::SetDefaultSpawnPosition);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createDisplayObjective(const DisplayObjective &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.position, addByte,
        in.name, addString
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::DisplayObjective);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createSetEntityMetadata(const Entity &entity)
{
    std::vector<uint8_t> payload;
    serialize(payload, entity.getId(), addVarInt);
    entity.appendMetadataPacket(payload);
    payload.push_back(0xff);
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::SetEntityMetadata);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createUpdateTime(const UpdateTime &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.worldAge, addLong,
        in.timeOfDay, addLong
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::UpdateTime);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createSetTitleText(const SetTitleText &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.title, addChat
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::SetTitleText);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createSetTitleAnimationTimes(const SetTitleAnimationTimes &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.fadeIn, addInt,
        in.stay, addInt,
        in.fadeOut, addInt
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::SetTitleAnimationTimes);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createEntitySoundEffect(const EntitySoundEffect &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload, in.soundId, addVarInt);
    if (in.soundId == 0)
        serialize(payload,
            in.soundName, addIdentifier,
            in.hasFixedRange, addBoolean,
            in.range, addFloat
        );
    serialize(payload,
        in.category, addVarInt,
        in.entityId, addVarInt,
        in.volume, addFloat,
        in.pitch, addFloat,
        in.seed, addLong
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::EntitySoundEffect);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createSoundEffect(const SoundEffect &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload, in.soundId, addVarInt);
    if (in.soundId == 0)
        serialize(payload,
            in.soundName, addIdentifier,
            in.hasFixedRange, addBoolean,
            in.range, addFloat
        );
    serialize(payload,
        in.category, addVarInt,
        in.x, addInt,
        in.y, addInt,
        in.z, addInt,
        in.volume, addFloat,
        in.pitch, addFloat,
        in.seed, addLong
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::SoundEffect);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createStopSound(const StopSound &in)
{
    std::vector<uint8_t> payload;
    serialize(payload, in.flags, addByte);
    if (in.flags == 3 || in.flags == 1)
        serialize(payload, in.source, addVarInt);
    if (in.flags == 2 || in.flags == 3)
        serialize(payload, in.sound, addIdentifier);

    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::StopSound);
    return packet;
}
std::unique_ptr<std::vector<uint8_t>> protocol::createSystemChatMessage(const SystemChatMessage &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.JSONData, addChat,
        in.overlay, addBoolean
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::SystemChatMessage);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createPickupItem(const PickupItem &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.collectedEntityId, addVarInt,
        in.collectorEntityId, addVarInt,
        in.pickupItemCount, addVarInt
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::PickupItem);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createEntityVelocity(const EntityVelocity &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.entityId, addVarInt,
        in.velocityX, addShort,
        in.velocityY, addShort,
        in.velocityZ, addShort
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::EntityVelocity);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createSetEquipment(const SetEquipment &in)
{
    std::vector<uint8_t> payload;

    serialize(payload, in.entityId, addVarInt);
    for (const auto &it : in.equipment) {
        // clang-format off
        serialize(payload,
            it.first, addByte,
            it.second, addSlot
        );
        // clang-format on
    }
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::SetEquipment);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createSetExperience(const SetExperience &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.experienceBar, addFloat,
        in.level, addVarInt,
        in.totalExperience, addVarInt
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::SetExperience);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createHealth(const Health &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.health, addFloat,
        in.food, addVarInt,
        in.foodSaturation, addFloat
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::Health);

    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createUpdateObjectives(const UpdateObjectives &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.name, addString,
        in.mode, addByte
    );
    if (in.mode == 0 || in.mode == 2) {
        serialize(payload,
            in.value.serialize(), addChat,
            in.type, addVarInt
        );
    }
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::UpdateObjective);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createUpdateTeams(const UpdateTeams &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.name, addString,
        in.mode, addByte
    );
    if (in.mode == 0 || in.mode == 2) {
        serialize(payload,
            in.displayName.serialize(), addChat,
            in.friendlyFalgs, addByte,
            in.nameTagVisibility, addString,
            in.collisionRule, addString,
            in.color, addVarInt,
            in.prefix.serialize(), addChat,
            in.suffix.serialize(), addChat
        );
    }
    if (in.mode == 0 || in.mode == 3 || in.mode == 4) {
        serialize(payload,
            in.entities, addArray<std::string, addString>
        );
    }
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::UpdateTeam);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createUpdateScore(const UpdateScore &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.name, addString,
        in.action, addVarInt,
        in.objective, addString
    );
    if (in.action == 0) {
        serialize(payload,
            in.value, addVarInt
        );
    }
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::UpdateScore);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createSetSubtitleText(const SetSubtitleText &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.subtitle, addChat
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::SetSubtitleText);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createTeleportEntity(const TeleportEntity &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.entityID, addVarInt,
        in.x, addDouble,
        in.y, addDouble,
        in.z, addDouble,
        in.yaw, addByte,
        in.pitch, addByte,
        in.onGround, addBoolean
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::TeleportEntity);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createUpdateAdvancements(const UpdateAdvancements &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.resetOrClear, addBoolean,
        in.advancementMapping, addArray<protocol::UpdateAdvancements::AdvancementMapping, addAdvancementMapping>,
        in.identifiers, addArray<std::string, addIdentifier>,
        in.progressMapping, addArray<protocol::UpdateAdvancements::ProgressMapping, addAdvancementProgressMapping>
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::UpdateAdvancements);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createUpdateAttributes(const UpdateAttributes &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.entityId, addVarInt,
        in.attributes, addArray<protocol::UpdateAttributes::Property, addAttributesProperty>
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::UpdateAttributes);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createFeatureFlags(const FeatureFlags &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.flags, addArray<std::string, addString>
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::FeatureFlags);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createUpdateRecipes(const UpdateRecipes &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.recipes, addArray<int, addVarInt>
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::UpdateRecipes);
    return packet;
}

std::unique_ptr<std::vector<uint8_t>> protocol::createUpdateTags(const UpdateTags &in)
{
    std::vector<uint8_t> payload;
    // clang-format off
    serialize(payload,
        in.tags, addArray<int, addVarInt>
    );
    // clang-format on
    auto packet = std::make_unique<std::vector<uint8_t>>();
    finalize(*packet, payload, ClientPacketID::UpdateTags);
    return packet;
}
