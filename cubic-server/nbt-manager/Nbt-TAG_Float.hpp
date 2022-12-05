#ifndef NBT_TAG_FLOAT_HPP
#define NBT_TAG_FLOAT_HPP

#include "Nbt-base.hpp"

class Nbt_TAG_Float : public Nbt_base
{
private:
    float _value;
public:
    Nbt_TAG_Float() : Nbt_base("", NbtType::Float) {};
    Nbt_TAG_Float(std::string name) : Nbt_base(name, NbtType::Float) {};
    Nbt_TAG_Float(std::string name, float value) : Nbt_base(name, NbtType::Float), _value(value) {};
    ~Nbt_TAG_Float() {};
    float get_value() const;
    void set_value(float value);
};

// float Nbt_TAG_Float::get_value() const
// {
//     return _value;
// }

// void Nbt_TAG_Float::set_value(float value)
// {
//     _value = value;
// }

#endif //NBT_TAG_FLOAT_HPP