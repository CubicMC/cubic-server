#ifndef NBT_TAG_BYTE_HPP
#define NBT_TAG_BYTE_HPP

#include <cstdint>

#include "Nbt-base.hpp"

class Nbt_TAG_Byte : public Nbt_base
{
private:
    int8_t _value;
public:
    Nbt_TAG_Byte() : Nbt_base("", NbtType::Byte) {};
    Nbt_TAG_Byte(std::string name) : Nbt_base(name, NbtType::Byte) {};
    Nbt_TAG_Byte(std::string name, int8_t value) : Nbt_base(name, NbtType::Byte), _value(value) {};
    ~Nbt_TAG_Byte() {};
    int8_t get_value() const;
    void set_value(int8_t value);
};

// int8_t Nbt_TAG_Byte::get_value() const
// {
//     return _value;
// }

// void Nbt_TAG_Byte::set_value(int8_t value)
// {
//     _value = value;
// }

#endif //NBT_TAG_BYTE_HPP