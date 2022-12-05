#ifndef NBT_TAG_SHORT_HPP
#define NBT_TAG_SHORT_HPP

#include <cstdint>

#include "Nbt-base.hpp"

class Nbt_TAG_Short : public Nbt_base
{
private:
    int16_t _value;
public:
    Nbt_TAG_Short() : Nbt_base("", NbtType::Short) {};
    Nbt_TAG_Short(std::string name) : Nbt_base(name, NbtType::Short) {};
    Nbt_TAG_Short(std::string name, int16_t value) : Nbt_base(name, NbtType::Short), _value(value) {};
    ~Nbt_TAG_Short() {};
    int16_t get_value() const;
    void set_value(int16_t value);
};

// int16_t Nbt_TAG_Short::get_value() const
// {
//     return _value;
// }

// void Nbt_TAG_Short::set_value(int16_t value)
// {
//     _value = value;
// }

#endif //NBT_TAG_Short_HPP