#ifndef WORLD_STORAGE_ITEM_HPP
#define WORLD_STORAGE_ITEM_HPP

#include <string>
#include <cstdint>

namespace world_storage {

class Item {
public:
    constexpr Item() = default;
    constexpr Item(const std::string &name, int32_t count = 1, int32_t damage = 0):
        name(name),
        count(count),
        damage(damage)
    {}

    constexpr const std::string &getName() const { return this->name; }
    constexpr int32_t getCount() const { return this->count; }
    constexpr int32_t getDamage() const { return this->damage; }

    constexpr void setName(const std::string &name) { this->name = name; }
    constexpr void setCount(int32_t count) { this->count = count; }
    constexpr void setDamage(int32_t damage) { this->damage = damage; }

private:
    std::string name;
    int32_t count;
    int32_t damage;
};

} // namespace world_storage

#endif // WORLD_STORAGE_ITEM_HPP
