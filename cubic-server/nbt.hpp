#ifndef CUBICSERVER_NBT_HPP
#define CUBICSERVER_NBT_HPP

#include <array>
#include <algorithm>
#include <stdexcept>
#include <utility>
#include <vector>
#include <variant>

namespace nbt
{

// https://xuhuisun.com/post/c++-weekly-2-constexpr-map/
// This is used to have a constexpr map for TAG_Compound
template<typename Key, typename Value>
struct FastMap
{
    std::vector<std::pair<Key, Value>> data;

    [[nodiscard]] constexpr Value at(const Key &key) const
    {
        const auto itr =
                std::find_if(begin(data), end(data),
                             [&key](const auto &v) { return v.first == key; });
        if (itr != end(data)) {
            return itr->second;
        }
        else {
            throw std::range_error("Not Found");
        }
    }

    constexpr FastMap(FastMap<Key, Value> &&val) noexcept {
        data = std::move(val.data);
    }
};

// Some stuff here is from cpp-nbt (Only the types nothing else)
// https://github.com/SpockBotMC/cpp-nbt
enum class TagType {
    End,
    Byte,
    Short,
    Int,
    Long,
    Float,
    Double,
    ByteArray,
    String,
    List,
    Compound,
    IntArray,
    LongArray
};

class Base
{
protected:
    const std::string _name;
    const TagType _type;
public:
    Base(std::string name, TagType type) : _name(std::move(name)), _type(type) {};
    virtual ~Base() = default;

    [[nodiscard]] const std::string &get_name() const {
        return _name;
    };
};

class Int : public Base
{
private:
    int32_t _value;
public:
    explicit Int(const std::string &name, int32_t value = 0) : Base(name, TagType::Int), _value(value) {};
    ~Int() override = default;

    [[nodiscard]] constexpr int32_t get_value() const {
        return _value;
    }

    void set_value(int32_t value) {
        _value = value;
    }
};

class Byte : public Base
{
private:
    int8_t _value;
public:
    explicit Byte(std::string name, int8_t value = 0) : Base(std::move(name), TagType::Byte), _value(value) {};
    ~Byte() override = default;;

    [[nodiscard]] constexpr int8_t get_value() const {
        return _value;
    }

    void set_value(int8_t value) {
        _value = value;
    }
};

class ByteArray : public Base
{
private:
    std::vector<int8_t> _value;
public:
    explicit ByteArray(std::string name, std::vector<int8_t> value = std::vector<int8_t>())
        : Base(std::move(name), TagType::ByteArray), _value(std::move(value)) {};
    ~ByteArray() override = default;

    [[nodiscard]] constexpr std::vector<int8_t> &get_values() {
        return _value;
    }
};

class Compound : public Base
{
private:
    FastMap<std::string, Base> _value;
public:
    Compound(std::string name, FastMap<std::string, Base> value) : Base(std::move(name), TagType::Compound), _value(std::move(value)) {};
    ~Compound() override = default;

    constexpr FastMap<std::string, Base> &get_values() {
        return _value;
    }
};

class Double : public Base
{
private:
    double _value;
public:
    explicit Double(std::string name, int8_t value = 0) : Base(std::move(name), TagType::Double), _value(value) {};
    ~Double() override = default;;

    [[nodiscard]] constexpr double get_value() const {
        return _value;
    }

    void set_value(double value) {
        _value = value;
    }
};

class Float : public Base
{
private:
    float _value;
public:
    explicit Float(std::string name, int8_t value = 0) : Base(std::move(name), TagType::Float), _value(value) {};
    ~Float() override = default;;

    [[nodiscard]] constexpr float get_value() const {
        return _value;
    }

    void set_value(float value) {
        _value = value;
    }
};

}

#endif //CUBICSERVER_NBT_HPP
