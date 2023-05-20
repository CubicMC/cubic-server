#include "world_storage/DynamicStorage.hpp"
#include "types.hpp"
#include <cstdint>
#include <gtest/gtest.h>
#include "world_storage/Section.hpp"

namespace BlockStorage {

TEST(DynamicStorage, DynamicStorageTestSetAndGet)
{
    world_storage::DynamicStorage<uint64_t, world_storage::SECTION_3D_SIZE> storage(4);

    auto maxValue = 4;

    for (auto value = 0; value < 4; value++) {
        for (uint64_t i = 0; i < world_storage::SECTION_3D_SIZE; i++) {
            EXPECT_NO_THROW(storage.set(i, value));
        }

        for (uint64_t i = 0; i < world_storage::SECTION_3D_SIZE; i++) {
            EXPECT_EQ(storage.get(i), value);
        }

        for (uint64_t i = 0; i < world_storage::SECTION_3D_SIZE; i++) {
            EXPECT_NO_THROW(storage.set(i, i % maxValue));
            EXPECT_EQ(storage.get(i), i % maxValue);
        }
    }
}

TEST(DynamicStorage, DynamicStorageTestSetValueSize)
{

    world_storage::DynamicStorage<uint64_t, world_storage::SECTION_3D_SIZE> storage(4);

    auto maxValue = (1 << 4);
    auto valueSize = 4;

    for (auto value = 0; value < 4; value++) {
        for (uint64_t i = 0; i < world_storage::SECTION_3D_SIZE; i++) {
            EXPECT_NO_THROW(storage.set(i, value));
        }
        for (uint64_t i = 0; i < world_storage::SECTION_3D_SIZE; i++) {
            EXPECT_EQ(storage.get(i), value);
        }
        storage.setValueSize(++valueSize);
        for (uint64_t i = 0; i < world_storage::SECTION_3D_SIZE; i++) {
            EXPECT_EQ(storage.get(i), value);
        }
        for (uint64_t i = 0; i < world_storage::SECTION_3D_SIZE; i++) {
            EXPECT_NO_THROW(storage.set(i, i % maxValue));
            EXPECT_EQ(storage.get(i), i % maxValue);
        }
    }
}

} // namespace BlockStorage

namespace LightStorage {

TEST(DynamicStorage, DynamicStorageTestSetAndGet)
{
    world_storage::Section::LightStorage storage(4);

    auto maxValue = 4;

    for (auto value = 0; value < 4; value++) {
        for (uint64_t i = 0; i < world_storage::SECTION_3D_SIZE; i++) {
            EXPECT_NO_THROW(storage.set(i, value));
        }

        for (uint64_t i = 0; i < world_storage::SECTION_3D_SIZE; i++) {
            EXPECT_EQ(storage.get(i), value);
        }

        for (uint64_t i = 0; i < world_storage::SECTION_3D_SIZE; i++) {
            EXPECT_NO_THROW(storage.set(i, i % maxValue));
            EXPECT_EQ(storage.get(i), i % maxValue);
        }
    }
}

TEST(DynamicStorage, DynamicStorageTestSetValueSize)
{

    world_storage::Section::LightStorage storage(4);

    auto maxValue = (1 << 4);
    auto valueSize = 4;

    EXPECT_EQ(storage.data().size(), world_storage::SECTION_3D_SIZE / 2);
    for (auto value = 0; value < 4; value++) {
        for (uint64_t i = 0; i < world_storage::SECTION_3D_SIZE; i++) {
            EXPECT_NO_THROW(storage.set(i, value));
        }
        for (uint64_t i = 0; i < world_storage::SECTION_3D_SIZE; i++) {
            EXPECT_EQ(storage.get(i), value);
        }
        storage.setValueSize(++valueSize);
        for (uint64_t i = 0; i < world_storage::SECTION_3D_SIZE; i++) {
            EXPECT_EQ(storage.get(i), value);
        }
        for (uint64_t i = 0; i < world_storage::SECTION_3D_SIZE; i++) {
            EXPECT_NO_THROW(storage.set(i, i % maxValue));
            EXPECT_EQ(storage.get(i), i % maxValue);
        }
    }
}

} // namespace LightStorage
