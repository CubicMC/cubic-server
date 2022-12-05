#ifndef NBT_TAG_INT_HPP
#define NBT_TAG_INT_HPP

#include <cstdint>

#include "Nbt-base.hpp"

class Nbt_TAG_Int : public Nbt_base
{
private:
    int32_t _value;
public:
    Nbt_TAG_Int() : Nbt_base("", NbtType::Int) {};
    Nbt_TAG_Int(std::string name) : Nbt_base(name, NbtType::Int) {};
    Nbt_TAG_Int(std::string name, int32_t value) : Nbt_base(name, NbtType::Int), _value(value) {};
    ~Nbt_TAG_Int() {};
    int32_t get_value() const;
    void set_value(int32_t value);
};

// int32_t Nbt_TAG_Int::get_value() const
// {
//     return _value;
// }

// void Nbt_TAG_Int::set_value(int32_t value)
// {
//     _value = value;
// }

#endif //NBT_TAG_INT_HPP