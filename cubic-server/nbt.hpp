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

    [[nodiscard]] constexpr const std::string &getName() const {
        return _name;
    };

    [[nodiscard]] constexpr TagType getType() const {
        return _type;
    }

    [[nodiscard]] constexpr virtual std::vector<uint8_t> serialize() const {
        std::vector<uint8_t> data;
        serialize(data);
        return data;
    }

    constexpr virtual void serialize(std::vector<uint8_t> &data, bool include_name = true) const = 0;

    constexpr virtual void pre_serialize(std::vector<uint8_t> &data, bool include_name) const {
        if (!include_name)
            return;
        // Serialize the type
        data.push_back((uint8_t)_type);
        // Serialize the name length
        data.push_back(_name.length() >> 8);
        data.push_back(_name.length() & 0xFF);
        // Serialize the name
        for (const auto &i : _name)
            data.push_back(i);
    }

    constexpr virtual void destroy() {};
};

constexpr void serialize(std::vector<uint8_t> &data, const Base *nbt, bool include_name = true);

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

    void setValue(int32_t value) {
        _value = value;
    }

    [[nodiscard]] constexpr std::vector<uint8_t> serialize() const override  {
        std::vector<uint8_t> data;
        serialize(data);
        return data;
    }

    constexpr void serialize(std::vector<uint8_t> &data, bool include_name = true) const override {
        Base::pre_serialize(data, include_name);
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
    ~Byte() override = default;

    [[nodiscard]] constexpr int8_t get_value() const {
        return _value;
    }

    void setValue(int8_t value) {
        _value = value;
    }

    [[nodiscard]] constexpr std::vector<uint8_t> serialize() const override {
        std::vector<uint8_t> data;
        serialize(data);
        return data;
    }

    constexpr void serialize(std::vector<uint8_t> &data, bool include_name = true) const override {
        Base::pre_serialize(data, include_name);
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

    [[nodiscard]] constexpr std::vector<int8_t> &getValues() {
        return _value;
    }

    [[nodiscard]] constexpr std::vector<uint8_t> serialize() const override {
        std::vector<uint8_t> data;
        serialize(data);
        return data;
    }

    constexpr void serialize(std::vector<uint8_t> &data, bool include_name = true) const override {
        Base::pre_serialize(data, include_name);
        // Serialize the length
        for (int i = 0; i < 4; i++)
            data.push_back((_value.size() >> (24 - i * 8)) & 0xFF);
        // Serialize the data
        for (auto i : _value)
            data.push_back(i);
    }
};

class Compound : public Base
{
private:
    std::vector<Base *> _value;
public:
    Compound(std::string name, std::vector<Base *> value) : Base(std::move(name), TagType::Compound), _value(std::move(value)) {};
    Compound(std::string name, std::initializer_list<Base *> value) : Base(std::move(name), TagType::Compound), _value(value) {};
    ~Compound() override = default;

    constexpr std::vector<Base *> &getValues() {
        return _value;
    }

    [[nodiscard]] constexpr std::vector<uint8_t> serialize() const override {
        std::vector<uint8_t> data;
        serialize(data);
        return data;
    }

    constexpr void serialize(std::vector<uint8_t> &data, bool include_name = true) const override {
        Base::pre_serialize(data, include_name);
        // if (!include_name) {
        //     // Serialize the length of the list in 4 bytes
        //     for (int i = 0; i < 4; i++)
        //         data.push_back(((_value.size() + 1) >> (24 - i * 8)) & 0xFF);
        // }
        for (const auto &i : _value) {
            // i->serialize(data);
            i->serialize(data);
        }
        // Ends the TAG_Compound with a TAG_End
        data.push_back(0);
    }

    constexpr void destroy() override {
        for (auto i : _value) {
            i->destroy();
            delete i;
        }
    }
};

class Double : public Base
{
private:
    double _value;
public:
    explicit Double(std::string name, double value = 0) : Base(std::move(name), TagType::Double), _value(value) {};
    ~Double() override = default;

    [[nodiscard]] constexpr double get_value() const {
        return _value;
    }

    void setValue(double value) {
        _value = value;
    }

    [[nodiscard]] constexpr std::vector<uint8_t> serialize() const override {
        std::vector<uint8_t> data;
        serialize(data);
        return data;
    }

    constexpr void serialize(std::vector<uint8_t> &data, bool include_name = true) const override {
        Base::pre_serialize(data, include_name);
        uint8_t const *p = reinterpret_cast<uint8_t const *>(&_value);
        for (int i = 7; i >= 0; i--)
            data.push_back(p[i]);
    }
};

class Float : public Base
{
private:
    float _value;
public:
    explicit Float(std::string name, float value = 0) : Base(std::move(name), TagType::Float), _value(value) {};
    ~Float() override = default;

    [[nodiscard]] constexpr float get_value() const {
        return _value;
    }

    void setValue(float value) {
        _value = value;
    }

    [[nodiscard]] constexpr std::vector<uint8_t> serialize() const override {
        std::vector<uint8_t> data;
        serialize(data);
        return data;
    }

    constexpr void serialize(std::vector<uint8_t> &data, bool include_name = true) const override {
        Base::pre_serialize(data, include_name);
        uint8_t const *p = reinterpret_cast<uint8_t const *>(&_value);
        for (int i = 3; i >= 0; i--)
            data.push_back(p[i]);
    }
};

class Long : public Base
{
private:
    int64_t _value;
public:
    explicit Long(std::string name, int64_t value = 0) : Base(std::move(name), TagType::Long), _value(value) {};
    ~Long() override = default;

    [[nodiscard]] constexpr int64_t get_value() const {
        return _value;
    }

    void setValue(int64_t value) {
        _value = value;
    }

    [[nodiscard]] constexpr std::vector<uint8_t> serialize() const override {
        std::vector<uint8_t> data;
        serialize(data);
        return data;
    }

    constexpr void serialize(std::vector<uint8_t> &data, bool include_name = true) const override {
        Base::pre_serialize(data, include_name);
        for (int i = 0; i < 8; i++)
            data.push_back((_value >> (56 - i * 8)) & 0xFF);
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

    void setValue(int16_t value) {
        _value = value;
    }

    [[nodiscard]] constexpr std::vector<uint8_t> serialize() const override {
        std::vector<uint8_t> data;
        serialize(data);
        return data;
    }

    constexpr void serialize(std::vector<uint8_t> &data, bool include_name = true) const override {
        Base::pre_serialize(data, include_name);
        data.push_back(_value >> 8);
        data.push_back(_value & 0xFF);
    }
};

class String : public Base
{
private:
    std::string _value;
public:
    explicit String(std::string name, std::string value = "") : Base(std::move(name), TagType::String), _value(std::move(value)) {};
    ~String() override = default;

    [[nodiscard]] constexpr const std::string &get_value() const {
        return _value;
    }

    void setValue(std::string value) {
        _value = std::move(value);
    }

    [[nodiscard]] constexpr std::vector<uint8_t> serialize() const override {
        std::vector<uint8_t> data;
        serialize(data);
        return data;
    }

    constexpr void serialize(std::vector<uint8_t> &data, bool include_name = true) const override {
        Base::pre_serialize(data, include_name);
        // Serialize the length of the string
        data.push_back(_value.length() >> 8);
        data.push_back(_value.length() & 0xFF);
        // Serialize the string
        for (auto i : _value) {
            data.push_back(i);
        }
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

    [[nodiscard]] constexpr std::vector<int32_t> &getValues() {
        return _value;
    }

    [[nodiscard]] constexpr std::vector<uint8_t> serialize() const override {
        std::vector<uint8_t> data;
        serialize(data);
        return data;
    }

    constexpr void serialize(std::vector<uint8_t> &data, bool include_name = true) const override {
        Base::pre_serialize(data, include_name);
        // Serialize the length of the data
        data.push_back(_value.size() >> 8);
        data.push_back(_value.size() & 0xFF);
        // Serialize the ints
        for (auto d : _value) {
            for (int i = 0; i < 4; i++)
                data.push_back((d >> (24 - i * 8)) & 0xFF);
        }
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

    [[nodiscard]] constexpr std::vector<int64_t> &getValues() {
        return _value;
    }

    [[nodiscard]] constexpr std::vector<uint8_t> serialize() const override {
        std::vector<uint8_t> data;
        serialize(data);
        return data;
    }

    constexpr void serialize(std::vector<uint8_t> &data, bool include_name = true) const override {
        Base::pre_serialize(data, include_name);
        // Serialize the length of the data
        data.push_back(_value.size() >> 8);
        data.push_back(_value.size() & 0xFF);
        // Serialize the longs
        for (auto d : _value) {
            for (int i = 0; i < 8; i++)
                data.push_back((d >> (56 - i * 8)) & 0xFF);
        }
    }
};

class List : public Base
{
private:
    std::vector<Base *> _value;
public:
    explicit List(std::string name, std::vector<Base *> value = std::vector<Base *>())
            : Base(std::move(name), TagType::List), _value(std::move(value)) {};
    ~List() override = default;

    [[nodiscard]] constexpr std::vector<Base *> &getValues() {
        return _value;
    }

    [[nodiscard]] constexpr std::vector<uint8_t> serialize() const override {
        std::vector<uint8_t> data;
        serialize(data);
        return data;
    }

    constexpr void serialize(std::vector<uint8_t> &data, bool include_name = true) const override {
        Base::pre_serialize(data, include_name);
        TagType current = TagType::End;
        // serialize the type of the first componant of the list
        data.push_back((uint8_t)_value[0]->getType());
        // Serialize the length of the data as int32
        for (int i = 0; i < 4; i++)
            data.push_back((_value.size() >> (24 - i * 8)) & 0xFF);
        // Serialize the nbt
        for (const auto &i : _value) {
            if (current == TagType::End)
                current = i->getType();
            if (current != i->getType())
                throw std::runtime_error("nbt::List contains more than one type");
            // i->serialize(data, false);
            i->serialize(data, false);
        }
    }

    constexpr void destroy() override {
        for (auto i : _value) {
            i->destroy();
            delete i;
        }
    }
};

}

#endif //CUBICSERVER_NBT_HPP
