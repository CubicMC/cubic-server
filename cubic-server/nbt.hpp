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

    constexpr FastMap(const std::initializer_list<std::pair<Key, Value>> &val) {
        data = std::vector<std::pair<Key, Value>>(val);
    }
};

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

    [[nodiscard]] virtual std::vector<uint8_t> serialize() {
        std::vector<uint8_t> data;
        serialize(data);
        return data;
    }

    virtual void serialize(std::vector<uint8_t> &data) {
        // Serialize the type
        data.push_back((uint8_t)_type);
        // Serialize the name length
        data.push_back(_name.length() >> 8);
        data.push_back(_name.length() & 0xFF);
        // Serialize the name
        for (const auto &i : _name)
            data.push_back(i);
    }
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

    [[nodiscard]] std::vector<uint8_t> serialize() override {
        std::vector<uint8_t> data;
        serialize(data);
        return data;
    }

    void serialize(std::vector<uint8_t> &data) override {
        Base::serialize(data);
        for (int i = 0; i < 4; i++)
            data.push_back((_value >> (24 - i * 8)) & 0xFF);
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

    [[nodiscard]] std::vector<uint8_t> serialize() override {
        std::vector<uint8_t> data;
        serialize(data);
        return data;
    }

    void serialize(std::vector<uint8_t> &data) override {
        Base::serialize(data);
        data.push_back(_value);
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
    Compound(std::string name, std::initializer_list<std::pair<std::string, Base>> value) : Base(std::move(name), TagType::Compound), _value(value) {};
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
    explicit Double(std::string name, double value = 0) : Base(std::move(name), TagType::Double), _value(value) {};
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
    explicit Float(std::string name, float value = 0) : Base(std::move(name), TagType::Float), _value(value) {};
    ~Float() override = default;;

    [[nodiscard]] constexpr float get_value() const {
        return _value;
    }

    void set_value(float value) {
        _value = value;
    }
};

class Long : public Base
{
private:
    int64_t _value;
public:
    explicit Long(std::string name, int64_t value = 0) : Base(std::move(name), TagType::Long), _value(value) {};
    ~Long() override = default;;

    [[nodiscard]] constexpr int64_t get_value() const {
        return _value;
    }

    void set_value(int64_t value) {
        _value = value;
    }
};

class Short : public Base
{
private:
    int16_t _value;
public:
    explicit Short(std::string name, int16_t value = 0) : Base(std::move(name), TagType::Short), _value(value) {};
    ~Short() override = default;

    [[nodiscard]] constexpr int16_t get_value() const {
        return _value;
    }

    void set_value(int16_t value) {
        _value = value;
    }
};

class String : public Base
{
private:
    std::string _value;
public:
    explicit String(std::string name, std::string value = "") : Base(std::move(name), TagType::String), _value(std::move(value)) {};
    ~String() override = default;;

    [[nodiscard]] constexpr const std::string &get_value() const {
        return _value;
    }

    void set_value(std::string value) {
        _value = value;
    }
};

class IntArray : public Base
{
private:
    std::vector<int32_t> _value;
public:
    explicit IntArray(std::string name, std::vector<int32_t> value = std::vector<int32_t>())
            : Base(std::move(name), TagType::IntArray), _value(std::move(value)) {};
    ~IntArray() override = default;

    [[nodiscard]] constexpr std::vector<int32_t> &get_values() {
        return _value;
    }
};

class LongArray : public Base
{
private:
    std::vector<int64_t> _value;
public:
    explicit LongArray(std::string name, std::vector<int64_t> value = std::vector<int64_t>())
            : Base(std::move(name), TagType::LongArray), _value(std::move(value)) {};
    ~LongArray() override = default;

    [[nodiscard]] constexpr std::vector<int64_t> &get_values() {
        return _value;
    }
};

class List : public Base
{
private:
    std::vector<Base> _value;
public:
    explicit List(std::string name, std::vector<Base> value = std::vector<Base>())
            : Base(std::move(name), TagType::List), _value(std::move(value)) {};
    ~List() override = default;

    [[nodiscard]] constexpr std::vector<Base> &get_values() {
        return _value;
    }
};

}

#endif //CUBICSERVER_NBT_HPP
