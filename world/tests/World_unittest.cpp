#include <gtest/gtest.h>
#include "../World.hpp"

World world;

TEST(WorldTest, addLevel_and_getLevelNames)
{
    std::string levelName = "overworld";
    world.addLevel(levelName);
    ASSERT_EQ(world.getLevelNames().size(), 1);
    ASSERT_EQ(world.getLevelNames()[0], levelName);
}

TEST(WorldTest, removeLevel)
{
    std::string levelName = "overworld";
    world.removeLevel(levelName);
    ASSERT_EQ(world.getLevelNames().size(), 0);
}