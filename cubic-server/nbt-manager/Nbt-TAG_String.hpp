#ifndef NBT_TAG_STRING_HPP
#define NBT_TAG_STRING_HPP

#include "Nbt-base.hpp"

class Nbt_TAG_String : public Nbt_base
{
private:
    std::string _value;
public:
    Nbt_TAG_String() : Nbt_base("", NbtType::String) {};
    Nbt_TAG_String(std::string name) : Nbt_base(name, NbtType::String) {};
    Nbt_TAG_String(std::string name, std::string value) : Nbt_base(name, NbtType::String), _value(value) {};
    ~Nbt_TAG_String() {};
    const std::string &get_value() const;
    void set_value(std::string value);
};

// const std::string &Nbt_TAG_String::get_value() const
// {
//     return _value;
// }

// void Nbt_TAG_String::set_value(std::string value)
// {
//     _value = value;
// }

#endif //NBT_TAG_STRING_HPP