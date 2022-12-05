#ifndef NBT_TAG_COMPOUND_HPP
#define NBT_TAG_COMPOUND_HPP

#include <vector>

#include "Nbt-base.hpp"

class Nbt_TAG_Compound : public Nbt_base
{
private:
    std::vector<Nbt_base> _value;
public:
    Nbt_TAG_Compound() : Nbt_base("", NbtType::Compound) {};
    Nbt_TAG_Compound(std::string name) : Nbt_base(name, NbtType::Compound) {};
    Nbt_TAG_Compound(std::string name, std::vector<Nbt_base> value) : Nbt_base(name, NbtType::Compound), _value(value) {};
    ~Nbt_TAG_Compound() {};
    const std::vector<Nbt_base> &get_values() const;
    const Nbt_base get_value(size_t index) const;
    const Nbt_base get_value(const std::string name) const;
    void set_value(std::vector<Nbt_base> value);
    void add_value(Nbt_base value);
    void remove_value(std::string value);
    void remove_value(size_t index);
};

// const std::vector<Nbt_base> &Nbt_TAG_Compound::get_values() const
// {
//     return _value;
// }

// const Nbt_base Nbt_TAG_Compound::get_value(size_t index) const
// {
//     return _value.at(index);
// }

// const Nbt_base Nbt_TAG_Compound::get_value(const std::string name) const
// {
//     for (int i = 0; i < _value.size(); i++)
//     {
//         if (_value[i].get_name() == name)
//         {
//             return _value[i];
//         }
//     }
//     throw std::invalid_argument("No value with that name");
// }

// void Nbt_TAG_Compound::set_value(std::vector<Nbt_base> value)
// {
//     _value = value;
// }

// void Nbt_TAG_Compound::add_value(Nbt_base value)
// {
//     _value.push_back(value);
// }

// void Nbt_TAG_Compound::remove_value(std::string value)
// {
//     for (size_t i = 0; i < _value.size(); i++)
//     {
//         if (_value[i].get_name() == value)
//         {
//             _value.erase(_value.begin() + i);
//         }
//     }
// }

// void Nbt_TAG_Compound::remove_value(size_t index)
// {
//     _value.erase(_value.begin() + index);
// }

#endif //NBT_TAG_COMPOUND_HPP