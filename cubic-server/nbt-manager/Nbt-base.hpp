#ifndef NBT_BASE_HPP
#define NBT_BASE_HPP

#include <string>

enum class NbtType
{
    End = 0,
    Byte = 1,
    Short = 2,
    Int = 3,
    Long = 4,
    Float = 5,
    Double = 6,
    ByteArray = 7,
    String = 8,
    List = 9,
    Compound = 10,
    IntArray = 11,
    LongArray = 12
};

class Nbt_base
{
protected:
    const std::string _name;
    const NbtType _type;
public:
    Nbt_base(std::string name, NbtType type) : _name(name), _type(type) {};
    virtual ~Nbt_base();
    const std::string &get_name() const { return _name; };
    Nbt_base &operator=(const Nbt_base &other);
};

#endif //NBT_BASE_HPP