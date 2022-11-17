#include <gtest/gtest.h>
#include "../Level.hpp"

Level level;

TEST(LevelTest, addChunkColumn_and_getChunkColumn)
{
    _2d_pos pos;
    pos.x = 0;
    pos.z = 0;
    EXPECT_NO_THROW(level.addChunkColumn(pos));
    EXPECT_NO_THROW(level.getChunkColumn(pos));
}

TEST(LevelTest, addChunkColumn_and_removeChunkColumn)
{
    _2d_pos pos;
    pos.x = 0;
    pos.z = 0;
    EXPECT_NO_THROW(level.addChunkColumn(pos));
    EXPECT_NO_THROW(level.removeChunkColumn(pos));
}

TEST(LevelTest, addChunkColumn_and_getChunkColumn_with_raw_coordinate)
{
    _2d_pos pos;
    pos.x = 0;
    pos.z = 0;
    EXPECT_NO_THROW(level.addChunkColumn(pos));
    EXPECT_NO_THROW(level.getChunkColumn(0, 0));

    pos.x = 0;
    pos.z = 0;
    EXPECT_NO_THROW(level.addChunkColumn(pos));
    EXPECT_NO_THROW(level.getChunkColumn(15, 3));

    pos.x = 6;
    pos.z = 3;
    EXPECT_NO_THROW(level.addChunkColumn(pos));
    EXPECT_NO_THROW(level.getChunkColumn(110, 57));
}

TEST(LevelTest, addChunkColumn_and_removeChunkColumn_with_raw_negative_coordinate)
{
    _2d_pos pos;
    pos.x = -1;
    pos.z = 0;
    EXPECT_NO_THROW(level.addChunkColumn(pos));
    EXPECT_NO_THROW(level.getChunkColumn(-4, 4));

    pos.x = 0;
    pos.z = -1;
    EXPECT_NO_THROW(level.addChunkColumn(pos));
    EXPECT_NO_THROW(level.getChunkColumn(4, -4));

    pos.x = -1;
    pos.z = -1;
    EXPECT_NO_THROW(level.addChunkColumn(pos));
    EXPECT_NO_THROW(level.getChunkColumn(-4, -4));

    pos.x = -4;
    pos.z = -7;
    EXPECT_NO_THROW(level.addChunkColumn(pos));
    EXPECT_NO_THROW(level.getChunkColumn(-54, -105));
}