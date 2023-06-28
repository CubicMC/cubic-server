#include "LevelData.hpp"
#include "nbt.hpp"
#include "GZIP.hpp"
#include <cstdint>
#include <initializer_list>
#include <memory>
#include <iostream>

namespace world_storage {
    void LevelData::save(std::string const &folder) {
        nbt::Compound *data = new nbt::Compound("Data", {
            std::make_shared<nbt::Byte>("allowCommands", this->allowCommands),
            std::make_shared<nbt::Double>("BorderCenterX", this->borderCenterX),
            std::make_shared<nbt::Double>("BorderCenterZ", this->borderCenterZ),
            std::make_shared<nbt::Double>("BorderDamagePerBlock", this->borderDamagePerBlock),
            std::make_shared<nbt::Double>("BorderSize", this->borderSize),
            std::make_shared<nbt::Double>("BorderSafeZone", this->borderSafeZone),
            std::make_shared<nbt::Double>("BorderSizeLerpTarget", this->borderSizeLerpTarget),
            std::make_shared<nbt::Long>("BorderSizeLerpTime", this->borderSizeLerpTime),
            std::make_shared<nbt::Double>("BorderWarningBlocks", this->borderWarningBlocks),
            std::make_shared<nbt::Double>("BorderWarningTime", this->borderWarningTime),
            std::make_shared<nbt::Int>("ClearWeatherTime", this->clearWeatherTime),
            std::make_shared<nbt::Compound>("CustomBossEvents"),
            std::make_shared<nbt::Compound>("DataPacks"),
            std::make_shared<nbt::Int>("DataVersion", this->dataVersion),
            std::make_shared<nbt::Long>("DayTime", this->dayTime),
            std::make_shared<nbt::Byte>("Difficulty", this->difficulty),
            std::make_shared<nbt::Byte>("DifficultyLocked", this->difficultyLocked),
            std::make_shared<nbt::Compound>("DimensionData", std::initializer_list<std::shared_ptr<nbt::Base>>{
                std::make_shared<nbt::Compound>("1", std::initializer_list<std::shared_ptr<nbt::Base>>{
                    std::make_shared<nbt::Compound>("DragonFight", std::initializer_list<std::shared_ptr<nbt::Base>>{
                        std::make_shared<nbt::Compound>("ExitPortalLocation", std::initializer_list<std::shared_ptr<nbt::Base>>{
                            std::make_shared<nbt::Byte>("X", 0),
                            std::make_shared<nbt::Byte>("Y", 0),
                            std::make_shared<nbt::Byte>("Z", 0),
                        }),
                        std::make_shared<nbt::List>("Gateways"),
                        std::make_shared<nbt::Byte>("DragonKilled", 0),
                        std::make_shared<nbt::Long>("DragonUUIDLeast", 0),
                        std::make_shared<nbt::Long>("DragonUUIDMost", 0),
                        std::make_shared<nbt::Byte>("PreviouslyKilled", 0),
                    })
                })
            }),
            std::make_shared<nbt::Compound>("GameRules"),
            std::make_shared<nbt::Int>("GameType", this->gameType),
            std::make_shared<nbt::Byte>("hardcore", this->hardcore),
            std::make_shared<nbt::Byte>("initialized", this->initialized),
            std::make_shared<nbt::Long>("LastPlayed", this->lastPlayed),
            std::make_shared<nbt::String>("LevelName", "World"),
            std::make_shared<nbt::Byte>("MapFeatures", 1),
            std::make_shared<nbt::Compound>("Player"),
            std::make_shared<nbt::Byte>("raining", this->raining),
            std::make_shared<nbt::Int>("rainTime", this->rainTime),
            std::make_shared<nbt::Long>("RandomSeed", 0),
            std::make_shared<nbt::Long>("SizeOnDisk", 0),
            std::make_shared<nbt::Int>("SpawnX", this->spawnX),
            std::make_shared<nbt::Int>("SpawnY", this->spawnY),
            std::make_shared<nbt::Int>("SpawnZ", this->spawnZ),
            std::make_shared<nbt::Byte>("thundering", this->thundering),
            std::make_shared<nbt::Int>("thunderTime", this->thunderTime),
            std::make_shared<nbt::Long>("Time", this->time),
            std::make_shared<nbt::Int>("version", this->version ),
            std::make_shared<nbt::Compound>("Version", std::initializer_list<std::shared_ptr<nbt::Base>>{
                std::make_shared<nbt::Int>("Id", this->mcVersion.id), 
                std::make_shared<nbt::String>("Name", this->mcVersion.name),
                std::make_shared<nbt::String>("Series", this->mcVersion.series),
                std::make_shared<nbt::Byte>("Snapshot", this->mcVersion.snapshot)
            }),
            std::make_shared<nbt::IntArray>("WanderingTraderId", std::vector<int32_t>{0, 0, 0, 0}),
            std::make_shared<nbt::Int>("WanderingTraderSpawnChance", 10),
            std::make_shared<nbt::Int>("WanderingTraderSpawnDelay", 100000),
            std::make_shared<nbt::Byte>("WasModded", 0)
        });
        GZIP gzip;

        std::vector<uint8_t> buffer = data->serialize();

        gzip.compress(buffer, std::string(folder + "/level.dat").c_str());
    }
}