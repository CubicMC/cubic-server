#include "../LevelData.hpp"
#include <gtest/gtest.h>

world_storage::LevelData levelData;

TEST(LevelDataTest, setHardcore_and_getHardcore)
{
    levelData.setHardcore(1);
    EXPECT_EQ(1, levelData.getHardcore());
}

TEST(LevelDataTest, setMapFeatures_and_getMapFeatures)
{
    levelData.setMapFeatures(1);
    EXPECT_EQ(1, levelData.getMapFeatures());
}

TEST(LevelDataTest, setRaining_and_getRaining)
{
    levelData.setRaining(1);
    EXPECT_EQ(1, levelData.getRaining());
}

TEST(LevelDataTest, setThundering_and_getThundering)
{
    levelData.setThundering(1);
    EXPECT_EQ(1, levelData.getThundering());
}

TEST(LevelDataTest, setGameType_and_getGameType)
{
    levelData.setGameType(1);
    EXPECT_EQ(1, levelData.getGameType());
}

TEST(LevelDataTest, setGeneratorVersion_and_getGeneratorVersion)
{
    levelData.setGeneratorVersion(1);
    EXPECT_EQ(1, levelData.getGeneratorVersion());
}

TEST(LevelDataTest, setRainTime_and_getRainTime)
{
    levelData.setRainTime(1);
    EXPECT_EQ(1, levelData.getRainTime());
}

TEST(LevelDataTest, setSpawnX_and_getSpawnX)
{
    levelData.setSpawnX(1);
    EXPECT_EQ(1, levelData.getSpawnX());
}

TEST(LevelDataTest, setSpawnY_and_getSpawnY)
{
    levelData.setSpawnY(1);
    EXPECT_EQ(1, levelData.getSpawnY());
}

TEST(LevelDataTest, setSpawnZ_and_getSpawnZ)
{
    levelData.setSpawnZ(1);
    EXPECT_EQ(1, levelData.getSpawnZ());
}

TEST(LevelDataTest, setThunderTime_and_getThunderTime)
{
    levelData.setThunderTime(1);
    EXPECT_EQ(1, levelData.getThunderTime());
}

TEST(LevelDataTest, setVersion_and_getVersion)
{
    levelData.setVersion(1);
    EXPECT_EQ(1, levelData.getVersion());
}

TEST(LevelDataTest, setLastPlayed_and_getLastPlayed)
{
    levelData.setLastPlayed(1);
    EXPECT_EQ(1, levelData.getLastPlayed());
}

TEST(LevelDataTest, setSeed_and_getSeed)
{
    levelData.setSeed(1);
    EXPECT_EQ(1, levelData.getSeed());
}

TEST(LevelDataTest, setSizeOnDisk_and_getSizeOnDisk)
{
    levelData.setSizeOnDisk(1);
    EXPECT_EQ(1, levelData.getSizeOnDisk());
}

TEST(LevelDataTest, setTime_and_getTime)
{
    levelData.setTime(1);
    EXPECT_EQ(1, levelData.getTime());
}

TEST(LevelDataTest, setGeneratorName_and_getGeneratorName)
{
    levelData.setGeneratorName("generatorName");
    EXPECT_EQ("generatorName", levelData.getGeneratorName());
}

TEST(LevelDataTest, setLevelName_and_getLevelName)
{
    levelData.setLevelName("levelName");
    EXPECT_EQ("levelName", levelData.getLevelName());
}
