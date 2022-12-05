#ifndef NTB_TAG_DOUBLE_HPP
#define NTB_TAG_DOUBLE_HPP

#include "Nbt-base.hpp"

class Nbt_TAG_Double : public Nbt_base
{
private:
    double _value;
public:
    Nbt_TAG_Double() : Nbt_base("", NbtType::Double) {};
    Nbt_TAG_Double(std::string name) : Nbt_base(name, NbtType::Double) {};
    Nbt_TAG_Double(std::string name, double value) : Nbt_base(name, NbtType::Double), _value(value) {};
    ~Nbt_TAG_Double() {};
    double get_value() const;
    void set_value(double value);
};

// double Nbt_TAG_Double::get_value() const
// {
//     return _value;
// }

// void Nbt_TAG_Double::set_value(double value)
// {
//     _value = value;
// }

#endif //NTB_TAG_DOUBLE_HPP