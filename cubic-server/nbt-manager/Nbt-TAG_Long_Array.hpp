#ifndef NBT_TAG_LONG_ARRAY_HPP
#define NBT_TAG_LONG_ARRAY_HPP

#include <cstdint>
#include <vector>

#include "Nbt-base.hpp"

class Nbt_TAG_Long_Array : public Nbt_base
{
private:
    std::vector<int64_t> _value;
public:
    Nbt_TAG_Long_Array() : Nbt_base("", NbtType::LongArray) {};
    Nbt_TAG_Long_Array(std::string name) : Nbt_base(name, NbtType::LongArray) {};
    Nbt_TAG_Long_Array(std::string name, std::vector<int64_t> value) : Nbt_base(name, NbtType::LongArray), _value(value) {};
    ~Nbt_TAG_Long_Array() {};
    const std::vector<int64_t> &get_values() const;
    const int64_t get_value(int index) const;
    void set_value(std::vector<int64_t> value);
    void add_value(int64_t value);
    void remove_value(int64_t value);
    void remove_value(size_t index);
};

// const std::vector<int64_t> &Nbt_TAG_Long_Array::get_values() const
// {
//     return _value;
// }

// const int64_t Nbt_TAG_Long_Array::get_value(int index) const
// {
//     return _value[index];
// }

// void Nbt_TAG_Long_Array::set_value(std::vector<int64_t> value)
// {
//     _value = value;
// }

// void Nbt_TAG_Long_Array::add_value(int64_t value)
// {
//     _value.push_back(value);
// }

// void Nbt_TAG_Long_Array::remove_value(int64_t value)
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

// void Nbt_TAG_Long_Array::remove_value(size_t index)
// {
//     _value.erase(_value.begin() + index);
// }

#endif // NBT_TAG_LONG_ARRAY_HPP