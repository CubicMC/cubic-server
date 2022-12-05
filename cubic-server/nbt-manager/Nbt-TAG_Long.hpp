#ifndef NBT_TAG_LONG_HPP
#define NBT_TAG_LONG_HPP

#include <cstdint>

#include "Nbt-base.hpp"

class Nbt_TAG_Long : public Nbt_base
{
private:
    int64_t _value;
public:
    Nbt_TAG_Long() : Nbt_base("", NbtType::Long) {};
    Nbt_TAG_Long(std::string name) : Nbt_base(name, NbtType::Long) {};
    Nbt_TAG_Long(std::string name, int64_t value) : Nbt_base(name, NbtType::Long), _value(value) {};
    ~Nbt_TAG_Long() {};
    int64_t get_value() const;
    void set_value(int64_t value);
};

// int64_t Nbt_TAG_Long::get_value() const
// {
//     return _value;
// }

// void Nbt_TAG_Long::set_value(int64_t value)
// {
//     _value = value;
// }

#endif //NBT_TAG_LONG_HPP