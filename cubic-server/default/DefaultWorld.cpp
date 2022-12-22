#include "DefaultWorld.hpp"
#include <stdio.h>
#include <zlib.h>

#define CHUNK 0x4000

#include "Overworld.hpp"
#include "TheEnd.hpp"
#include "TheNether.hpp"
#include "world_storage/Persistence.hpp"
#include <memory>

DefaultWorld::DefaultWorld(std::shared_ptr<WorldGroup> worldGroup, world_storage::WorldType worldType, std::string folder):
    World(worldGroup, worldType, folder),
    persistence(folder)
{
}

void DefaultWorld::tick() { World::tick(); }

void DefaultWorld::initialize()
{
    this->_dimensions.emplace("end", std::make_shared<TheEnd>(std::dynamic_pointer_cast<DefaultWorld>(shared_from_this())));
    this->_dimensions.emplace("nether", std::make_shared<TheNether>(std::dynamic_pointer_cast<DefaultWorld>(shared_from_this())));
    this->_dimensions.emplace("overworld", std::make_shared<Overworld>(std::dynamic_pointer_cast<DefaultWorld>(shared_from_this())));

    World::initialize();
}

// TODO: When _data will be initialized don't forget to remove this phony data and put the function to const !
void DefaultWorld::save() {
    this->_data = std::make_shared<nbt::Compound>("Data", std::initializer_list<nbt::Base *>{
            new nbt::Byte("allowCommands", 0),
            new nbt::Double("BorderCenterX", 0),
            new nbt::Double("BorderCenterZ", 0),
            new nbt::Double("BorderCenterX", 0),
            new nbt::Double("BorderDamagePerBlock", 0.2),
            new nbt::Double("BorderSize", 60000000),
            new nbt::Double("BorderSafeZone", 5),
            new nbt::Double("BorderSizeLerpTarget", 60000000),
            new nbt::Long("BorderSizeLerpTime", 0),
            new nbt::Double("BorderWarningBlocks", 5),
            new nbt::Double("BorderWarningTime", 15),
            new nbt::Int("ClearWeatherTime", 0),
            new nbt::Compound("CustomBossEvents", std::initializer_list<nbt::Base *>{}),
            new nbt::Compound("DataPacks", std::initializer_list<nbt::Base *>{}),
            new nbt::Int("DataVersion", 3120),
            new nbt::Long("DayTime", 0),
            new nbt::Byte("Difficulty", 0),
            new nbt::Byte("DifficultyLocked", 0),
            new nbt::Compound("DimensionData", std::initializer_list<nbt::Base *>{
                    new nbt::Compound("1", std::initializer_list<nbt::Base *>{
                            new nbt::Compound("DragonFight", std::initializer_list<nbt::Base *>{
                                    new nbt::Compound("ExitPortalLocation", std::initializer_list<nbt::Base *>{
                                            new nbt::Byte("X", 0),
                                            new nbt::Byte("Y", 0),
                                            new nbt::Byte("Z", 0),
                                    }),
                                    new nbt::List("Gateways"),
                                    new nbt::Byte("DragonKilled", 0),
                                    new nbt::Long("DragonUUIDLeast", 0),
                                    new nbt::Long("DragonUUIDMost", 0),
                                    new nbt::Byte("PreviouslyKilled", 0),
                            })
                    })
            }),
            new nbt::Compound("GameRules", std::initializer_list<nbt::Base *>{}),
            new nbt::Int("GameType", 0),
            new nbt::Byte("hardcore", 0),
            new nbt::Byte("initialized", 0),
            new nbt::Long("LastPlayed", 0),
            new nbt::String("LevelName", "World"),
            new nbt::Byte("MapFeatures", 0),
            new nbt::Compound("Player", std::initializer_list<nbt::Base *>{}),
            new nbt::Byte("raining", 0),
            new nbt::Int("rainTime", 0),
            new nbt::Long("RandomSeed", 0),
            new nbt::Long("SizeOnDisk", 0),
            new nbt::Int("SpawnX", 0),
            new nbt::Int("SpawnY", 0),
            new nbt::Int("SpawnZ", 0),
            new nbt::Byte("thundering", 0),
            new nbt::Int("thunderTime", 0),
            new nbt::Long("Time", 0),
            new nbt::Int("Time", 19133 ),
            new nbt::Compound("Version", std::initializer_list<nbt::Base *>{
                    new nbt::Int("Id", 3120),
                    new nbt::String("Name", "1.19.2"),
                    new nbt::String("Series", "main"),
                    new nbt::Byte("Snapshot", 0)
            }),
            new nbt::IntArray("WanderingTraderId", {0, 0, 0, 0}),
            new nbt::Int("WanderingTraderSpawnChance", 10),
            new nbt::Int("WanderingTraderSpawnDelay", 100000),
            new nbt::Byte("WasModded", 0)
    });
    std::vector<uint8_t> buffer = _data->serialize();

    FILE *file_buf = fopen("level.dat", "w");
    unsigned char *in = buffer.data();
    unsigned char out[CHUNK];

    z_stream strm;

    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;

    deflateInit2(&strm, Z_DEFAULT_COMPRESSION, Z_DEFLATED, 15 | 16, 8, Z_DEFAULT_STRATEGY);

    strm.next_in = in;
    strm.avail_in = buffer.size();
    strm.next_out = out;
    strm.avail_out = CHUNK;

    deflate(&strm, Z_FINISH);
    fwrite(out, sizeof(char), CHUNK - strm.avail_out, file_buf);
    fclose(file_buf);
    deflateEnd(&strm);
}

void DefaultWorld::stop() { World::stop(); }
