#ifndef NBT_TAG_INT_ARRAY_HPP
#define NBT_TAG_INT_ARRAY_HPP

#include <cstdint>
#include <vector>

#include "Nbt-base.hpp"

class Nbt_TAG_Int_Array : public Nbt_base
{
private:
    std::vector<int32_t> _value;
public:
    Nbt_TAG_Int_Array() : Nbt_base("", NbtType::IntArray) {};
    Nbt_TAG_Int_Array(std::string name) : Nbt_base(name, NbtType::IntArray) {};
    Nbt_TAG_Int_Array(std::string name, std::vector<int32_t> value) : Nbt_base(name, NbtType::IntArray), _value(value) {};
    ~Nbt_TAG_Int_Array() {};
    const std::vector<int32_t> &get_values() const;
    const int32_t get_value(int index) const;
    void set_value(std::vector<int32_t> value);
    void add_value(int32_t value);
    void remove_value(int32_t value);
    void remove_value(size_t index);
};

// const std::vector<int32_t> &Nbt_TAG_Int_Array::get_values() const
// {
//     return _value;
// }

// const int32_t Nbt_TAG_Int_Array::get_value(int index) const
// {
//     return _value[index];
// }

// void Nbt_TAG_Int_Array::set_value(std::vector<int32_t> value)
// {
//     _value = value;
// }

// void Nbt_TAG_Int_Array::add_value(int32_t value)
// {
//     _value.push_back(value);
// }

// void Nbt_TAG_Int_Array::remove_value(int32_t value)
// {
//     for (size_t i = 0; i < _value.size(); i++)
//     {
//         if (_value[i] == value)
//         {
//             _value.erase(_value.begin() + i);
//             break;
//         }
//     }
// }

// void Nbt_TAG_Int_Array::remove_value(size_t index)
// {
//     _value.erase(_value.begin() + index);
// }

#endif // NBT_TAG_INT_ARRAY_HPP