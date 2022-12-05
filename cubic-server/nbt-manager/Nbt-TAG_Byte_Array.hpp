#ifndef NBT_TAG_BYTE_ARRAY_HPP
#define NBT_TAG_BYTE_ARRAY_HPP

#include <vector>
#include <cstdint>

#include "Nbt-base.hpp"

class Nbt_TAG_Byte_Array : public Nbt_base
{
private:
    std::vector<int8_t> _value;
public:
    Nbt_TAG_Byte_Array() : Nbt_base("", NbtType::ByteArray) {};
    Nbt_TAG_Byte_Array(std::string name) : Nbt_base(name, NbtType::ByteArray) {};
    Nbt_TAG_Byte_Array(std::string name, std::vector<int8_t> value) : Nbt_base(name, NbtType::ByteArray), _value(value) {};
    ~Nbt_TAG_Byte_Array() {};
    const std::vector<int8_t> &get_values() const;
    const int8_t get_value(int index) const;
    void set_value(std::vector<int8_t> value);
    void add_value(int8_t value);
    void remove_value(int8_t value);
    void remove_value(size_t index);
};

// const std::vector<int8_t> &Nbt_TAG_Byte_Array::get_values() const
// {
//     return _value;
// }

// const int8_t Nbt_TAG_Byte_Array::get_value(int index) const
// {
//     return _value[index];
// }

// void Nbt_TAG_Byte_Array::set_value(std::vector<int8_t> value)
// {
//     _value = value;
// }

// void Nbt_TAG_Byte_Array::add_value(int8_t value)
// {
//     _value.push_back(value);
// }

// void Nbt_TAG_Byte_Array::remove_value(int8_t value)
// {
//     for (size_t i = 0; i < _value.size(); i++)
//     {
//         if (_value[i] == value)
//         {
//             _value.erase(_value.begin() + i);
//             return;
//         }
//     }
// }

// void Nbt_TAG_Byte_Array::remove_value(size_t index)
// {
//     _value.erase(_value.begin() + index);
// }

#endif //NBT_TAG_BYTE_ARRAY_HPP