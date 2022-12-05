#ifndef NBT_TAG_LIST_HPP
#define NBT_TAG_LIST_HPP

#include <vector>

#include "Nbt-base.hpp"

class Nbt_TAG_List : public Nbt_base
{
private:
    std::vector<Nbt_base> _value;
public:
    Nbt_TAG_List() : Nbt_base("", NbtType::List) {};
    Nbt_TAG_List(std::string name) : Nbt_base(name, NbtType::List) {};
    Nbt_TAG_List(std::string name, std::vector<Nbt_base> value) : Nbt_base(name, NbtType::List), _value(value) {};
    ~Nbt_TAG_List() {};
    const std::vector<Nbt_base> &get_values() const;
    const Nbt_base &get_value(size_t index) const;
    void set_value(std::vector<Nbt_base> value);
    void add_value(Nbt_base value);
    void remove_value(size_t index);
};

// const std::vector<Nbt_base> &Nbt_TAG_List::get_values() const
// {
//     return _value;
// }

// const Nbt_base &Nbt_TAG_List::get_value(size_t index) const
// {
//     return _value[index];
// }

// void Nbt_TAG_List::set_value(std::vector<Nbt_base> value)
// {
//     _value = value;
// }

// void Nbt_TAG_List::add_value(Nbt_base value)
// {
//     _value.push_back(value);
// }

// void Nbt_TAG_List::remove_value(size_t index)
// {
//     _value.erase(_value.begin() + index);
// }

#endif //NBT_TAG_LIST_HPP